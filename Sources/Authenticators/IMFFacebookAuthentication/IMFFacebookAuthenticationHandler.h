/*
 * Licensed Materials - Property of IBM
 * (C) Copyright IBM Corp. 2006, 2013. All Rights Reserved.
 * US Government Users Restricted Rights - Use, duplication or
 * disclosure restricted by GSA ADP Schedule Contract with IBM Corp.
 */


#import <Foundation/Foundation.h>
#import <IMFCore/IMFCore.h>
#import "IMFFacebookAuthenticationDelegate.h"

@interface IMFFacebookAuthenticationHandler : NSObject <IMFAuthenticationDelegate>

+ (IMFFacebookAuthenticationHandler*) sharedInstance;

- (void) registerWithDefaultDelegate;

- (void) registerWithDelegate:(id<IMFFacebookAuthenticationDelegate>)facebookAuthenticationDelegate;

- (void) didFinishFacebookAuthenticationWithAccessToken:(NSString*) facebookAccessToken;

- (void) didFailFacebookAuthenticationWithUserInfo:(NSDictionary*) userInfo;

@end

@interface IMFFacebookAuthentication : NSObject
/**
 * Returns the current IMFFacebookAuthentication version
 */
+(NSString*) version;
@end




