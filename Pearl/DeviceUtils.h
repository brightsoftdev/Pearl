//
//  DeviceUtils.h
//  Pearl
//
//  Created by Maarten Billemont on 05/11/09.
//  Copyright 2009, lhunath (Maarten Billemont). All rights reserved.
//

#import <Foundation/Foundation.h>


@interface DeviceUtils : NSObject {
    
}

/** Generates a string that very specifically identifies the exact platform.  This is a more detailed version of UIDevice-model. */
+ (NSString *)platform;

/** Generate a string of hexadecimal characters that represents given deviceToken (APNs registration device trust token) */
+ (NSString *)deviceTokenAsHex:(NSData *)deviceToken;

/** Generate a string of hexadecimal characters that represents the current deviceToken (APNs registration device trust token) */
+ (NSString *)currentDeviceTokenAsHex;

/** YES when invoked on an iPod touch device. */
+ (BOOL)isIPod;
/** YES when invoked on an iPad device. */
+ (BOOL)isIPad;
/** YES when invoked on an iPhone device. */
+ (BOOL)isIPhone;
/** YES when invoked on the iPhone simulator. */
+ (BOOL)isSimulator;

@end
