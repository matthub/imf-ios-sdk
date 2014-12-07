/*
 * Licensed Materials - Property of IBM
 * (C) Copyright IBM Corp. 2006, 2013. All Rights Reserved.
 * US Government Users Restricted Rights - Use, duplication or
 * disclosure restricted by GSA ADP Schedule Contract with IBM Corp.
 */


#import <Foundation/Foundation.h>
#import <IMFCore/IMFCore.h>
#import "IMFFacebookAuthenticationDelegate.h"

/**
 * Interface for handling Facebook authentication challenges from the IMF Server.
 */
@interface IMFFacebookAuthenticationHandler : NSObject <IMFAuthenticationDelegate>

/**
 * Singleton for IMFFacebookAuthenticationHandler.
 *
 * @return The shared intance of IMFFacebookAuthenticationHandler.
 */
+ (IMFFacebookAuthenticationHandler*) sharedInstance;

/**
 * Registers this handler to respond to Facebook authentication challenges using the default delegate.
 */
- (void) registerWithDefaultDelegate;

/**
 * Registers this handler to respond to Facebook authentication challenges using a custom delegate.
 *
 * @param facebookAuthenticationDelegate The custom authentication delegate.
 */
- (void) registerWithDelegate:(id<IMFFacebookAuthenticationDelegate>)facebookAuthenticationDelegate;

/**
 * Passes the Facebook access token back to the IMF authorization server
 *
 * @param facebookAccessToken The Facebook access token.
 */
- (void) didFinishFacebookAuthenticationWithAccessToken:(NSString*) facebookAccessToken;

/**
 * Called whenever there was a problem receiving the Facebook id token
 *
 * @param userInfo The Error user info.
 */
- (void) didFailFacebookAuthenticationWithUserInfo:(NSDictionary*) userInfo;

@end

@interface IMFFacebookAuthentication : NSObject

/**
 * Returns the current IMFFacebookAuthentication version
 */
+(NSString*) version;
@end




