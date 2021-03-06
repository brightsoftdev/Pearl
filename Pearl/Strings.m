//
//  Created by lhunath on 11/07/11.
//
//  To change this template use File | Settings | File Templates.
//


#import "Strings.h"


@implementation Strings

@synthesize tableName = _tableName;

- (id)initWithTable:(NSString *)tableName {
    
    if (!( self = [super init] ))
        return nil;
    
    self.tableName = tableName;
    
    return self;
}

- (NSMethodSignature *)methodSignatureForSelector:(SEL)aSelector {
    
    return [NSMethodSignature signatureWithObjCTypes:"@@:"];
}


- (void)forwardInvocation:(NSInvocation *)anInvocation {
    
    static NSBundle *mainBundle = nil;
    if (!mainBundle)
        mainBundle = [NSBundle mainBundle];
    static NSRegularExpression *newWord = nil, *endAcronym = nil;
    if (!newWord)
        newWord = [[NSRegularExpression alloc] initWithPattern:@"(\\p{Ll})(?=\\p{Lu})" options:0 error:nil];
    if (!endAcronym)
        endAcronym = [[NSRegularExpression alloc] initWithPattern:@"(\\p{Lu}\\p{Lu})(?=\\p{Lu}\\p{Ll})" options:0 error:nil];
    
    NSString *selector  = NSStringFromSelector(anInvocation.selector);
    NSString *key       = [newWord stringByReplacingMatchesInString:selector options:0 range:NSMakeRange(0, [selector length])
                                                       withTemplate:@"$1."];
    key                 = [endAcronym stringByReplacingMatchesInString:key options:0 range:NSMakeRange(0, [key length])
                                                          withTemplate:@"$1."];
    key                 = [key lowercaseString];
    id value = [mainBundle localizedStringForKey:key
                                           value:[mainBundle localizedStringForKey:key value:nil table:self.tableName]
                                           table:nil];
    [anInvocation setReturnValue:&value];
}

- (void)dealloc {
    
    self.tableName = nil;
    
    [super dealloc];
}

@end
