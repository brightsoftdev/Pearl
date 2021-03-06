/*
 *   Copyright 2009, Maarten Billemont
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 */

//
//  MenuLayer.m
//  Pearl
//
//  Created by Maarten Billemont on 29/07/09.
//  Copyright 2009 lhunath (Maarten Billemont). All rights reserved.
//

#import "AbstractAppDelegate.h"
#import "MenuLayer.h"
#import "MenuItemSpacer.h"
#ifdef PEARL_MEDIA
#import "AudioController.h"
#endif


@interface ClickMenu : CCMenu

@end

@interface ClickMenu (Private)

-(CCMenuItem *) itemForTouch: (UITouch *) touch;

@end

@implementation ClickMenu

-(BOOL) ccTouchBegan:(UITouch *)touch withEvent:(UIEvent *)event {

    BOOL itemTouched = [super ccTouchBegan:touch withEvent:event];
#ifdef PEARL_MEDIA
    if (itemTouched && [self itemForTouch:touch].isEnabled)
        [[AudioController get] clickEffect];
#endif
    
    return itemTouched;
}

@end



@interface MenuLayer ()

- (void)doLoad;
- (void)doLayout;

@property (nonatomic, readwrite, retain) CCMenu                                         *menu;

@property (nonatomic, readwrite, assign) BOOL                                           layoutDirty;

@end

@implementation MenuLayer

@synthesize items = _items;
@synthesize menu = _menu;
@synthesize logo = _logo;
@synthesize offset = _offset;
@synthesize layout = _layout;
@synthesize layoutDirty = _layoutDirty;
@synthesize delegate = _delegate;
@synthesize itemCounts = _itemCounts;



+ (MenuLayer *)menuWithDelegate:(id<NSObject, MenuDelegate>)aDelegate logo:(CCMenuItem *)aLogo items:(CCMenuItem *)menuItem, ... {
    
    if (!menuItem)
        [NSException raise:NSInvalidArgumentException
                    format:@"No menu items passed."];
    
    va_list list;
    va_start(list, menuItem);
    CCMenuItem *item;
    NSMutableArray *menuItems = [[NSMutableArray alloc] initWithCapacity:5];
    [menuItems addObject:menuItem];
    
    while ((item = va_arg(list, CCMenuItem*)))
        [menuItems addObject:item];
    va_end(list);
    
    return [self menuWithDelegate:aDelegate logo:aLogo itemsFromArray:[menuItems autorelease]];
}


+ (MenuLayer *)menuWithDelegate:(id<NSObject, MenuDelegate>)aDelegate logo:(CCMenuItem *)aLogo itemsFromArray:(NSArray *)menuItems {
    
    return [[[self alloc] initWithDelegate:aDelegate logo:aLogo itemsFromArray:menuItems] autorelease];
}


- (id)initWithDelegate:(id<NSObject, MenuDelegate>)aDelegate logo:aLogo items:(CCMenuItem *)menuItem, ... {
    
    va_list list;
    va_start(list, menuItem);
    CCMenuItem *item;
    NSMutableArray *menuItems = [[NSMutableArray alloc] initWithCapacity:5];
    [menuItems addObject:menuItem];
    
    while ((item = va_arg(list, CCMenuItem*)))
        [menuItems addObject:item];
    va_end(list);
    
    return [self initWithDelegate:aDelegate logo:aLogo itemsFromArray:[menuItems autorelease]];
}


- (id)initWithDelegate:(id<NSObject, MenuDelegate>)aDelegate logo:aLogo itemsFromArray:(NSArray *)menuItems {
    
    if(!(self = [super init]))
        return nil;

    self.delegate           = aDelegate;
    self.logo               = aLogo;
    self.items              = menuItems;
    self.layout             = MenuLayoutVertical;
    
    return self;
}


- (void)setItems:(NSArray *)newItems {
    
    [_items release];
    _items = [newItems copy];
    
    [self reset];
}


- (void)setLogo:(CCMenuItem *)aLogo {

    [_logo release];
    _logo = [aLogo retain];
    
    [self reset];
}


- (void)setOffset:(CGPoint)newOffset {

    _offset = newOffset;
    self.menu.position = newOffset;
}


- (void)setLayout:(MenuLayout)newLayout {
    
    _layout = newLayout;
    
    [self reset];
}


- (void)onEnter {
    
    [self doLoad];
    
    if (self.layoutDirty) {
        if ([self.delegate respondsToSelector:@selector(didLayout:)])
            [self.delegate didLayout:self];
        self.layoutDirty = NO;
    }
    
    [super onEnter];

    if ([self.delegate respondsToSelector:@selector(didEnter:)])
        [self.delegate didEnter:self];
}


- (void)reset {
    
    if(self.menu) {
        [self.menu removeAllChildrenWithCleanup:YES];
        [self removeChild:self.menu cleanup:YES];
        self.menu = nil;
    }

    [self doLoad];
}


- (void)doLoad {
    
    if (self.menu)
        return;
    
    self.menu = [ClickMenu menuWithItems:nil];
    self.menu.isRelativeAnchorPoint = YES;
    self.menu.anchorPoint = ccp(-0.5f, -0.5f);
    self.menu.position = self.offset;
    
    if (self.logo)
        [self.menu addChild:self.logo];
    
    [self addChild:self.menu];
    [self doLayout];
    
    if ([self.delegate respondsToSelector:@selector(didLoad:)])
        [self.delegate didLoad:self];
    
    self.layoutDirty = YES;
}

- (void)doLayout {
    
    switch (self.layout) {
        case MenuLayoutVertical: {
            for (CCMenuItem *item in self.items)
                [self.menu addChild:item];

            [self.menu alignItemsVertically];
            break;
        }

        case MenuLayoutColumns: {
            NSNumber *rows[10] = { nil, nil, nil, nil, nil, nil, nil, nil, nil, nil };
            NSUInteger r = 0;

            if (self.logo)
                rows[r++] = [NSNumber numberWithUnsignedInt:1];
            
            NSUInteger itemsLeft = [self.items count], i = 0;
            if (itemsLeft % 2)
                [NSException raise:NSInternalInconsistencyException format:@"Item amount must be even for columns layout."];
            
            for (; r < 10 && itemsLeft; r += 2) {
                if (itemsLeft >= 4) {
                    rows[r + 0] = [NSNumber numberWithUnsignedInt:2];
                    rows[r + 1] = [NSNumber numberWithUnsignedInt:2];
                    [self.menu addChild:[self.items objectAtIndex:i + 0]];
                    [self.menu addChild:[self.items objectAtIndex:i + 2]];
                    [self.menu addChild:[self.items objectAtIndex:i + 1]];
                    [self.menu addChild:[self.items objectAtIndex:i + 3]];
                    itemsLeft   -= 4;
                    i           += 4;
                } else {
                    // itemsLeft == 2
                    rows[r + 0] = [NSNumber numberWithUnsignedInt:1];
                    rows[r + 1] = [NSNumber numberWithUnsignedInt:1];
                    [self.menu addChild:[self.items objectAtIndex:i + 0]];
                    [self.menu addChild:[self.items objectAtIndex:i + 1]];
                    itemsLeft   -= 2;
                    i           += 2;
                }
            }

            [self.menu alignItemsInColumns:
             rows[0], rows[1], rows[2], rows[3], rows[4],
             rows[5], rows[6], rows[7], rows[8], rows[9], nil];
            break;
        }
            
        case MenuLayoutCustomColumns: {
            NSNumber *cols[10] = { nil, nil, nil, nil, nil, nil, nil, nil, nil, nil };
            for (NSUInteger c = 0; c < self.itemCounts.count; ++c)
                cols[c] = [self.itemCounts objectAtIndex:c];

            for (CCNode *item in self.items)
                [self.menu addChild:item];
            [self.menu alignItemsInColumns:
             cols[0], cols[1], cols[2], cols[3], cols[4],
             cols[5], cols[6], cols[7], cols[8], cols[9], nil];
            break;
        }
        case MenuLayoutCustomRows: {
            NSNumber *rows[10] = { nil, nil, nil, nil, nil, nil, nil, nil, nil, nil };
            for (NSUInteger r = 0; r < self.itemCounts.count; ++r)
                rows[r] = [self.itemCounts objectAtIndex:r];

            [self.menu alignItemsInColumns:
             rows[0], rows[1], rows[2], rows[3], rows[4],
             rows[5], rows[6], rows[7], rows[8], rows[9], nil];
            break;
        }
        
        default:
            [NSException raise:NSInternalInconsistencyException format:@"Unsupported layout format."];
    }
}


- (void)dealloc {
    
    self.menu = nil;
    
    self.items = nil;
    self.logo = nil;
    self.delegate = nil;

    [super dealloc];
}

@end
