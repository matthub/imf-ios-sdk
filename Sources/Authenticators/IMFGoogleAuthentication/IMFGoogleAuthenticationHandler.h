/*
 * Licensed Materials - Property of IBM
 * (C) Copyright IBM Corp. 2006, 2013. All Rights Reserved.
 * US Government Users Restricted Rights - Use, duplication or
 * disclosure restricted by GSA ADP Schedule Contract with IBM Corp.
 */

#import <Foundation/Foundation.h>
#import <IMFCore/IMFCore.h>
#import <GoogleOpenSource/GoogleOpenSource.h>
#import <GooglePlus/GooglePlus.h>
#import "IMFGoogleAuthenticationDelegate.h"

@protocol IMFGoogleAuthenticationDelegate;
/**
 *  This class provides functionalities to be able connect to IMF server with Google
 */
@interface IMFGoogleAuthenticationHandler : NSObject <IMFAuthenticationDelegate> {
    
}

/**
 *  Singletone for IMFGoogleAuthenticationHandler
 *
 *  @return the shared instance of IMFGoogleAuthenticationHandler
 */
+(IMFGoogleAuthenticationHandler*) sharedInstance;

/**
 *  Call this method before any request to a protected resource.  
 *  This function registers the default delegate which will do the Google authentication without writing additional code.
 */
-(void) registerWithDefaultDelegate;

/**
 *  Use this method in case needing to register custom Google delegate.
 *
 *  @param googleAuthenticationDelegate The custom google authentication delgate.
 */
-(void) registerWithDelegate:(id<IMFGoogleAuthenticationDelegate>) googleAuthenticationDelegate;

/**
 *  Call this method to pass back the googleId to the authorization server.
 *
 *  @param googleIdToken The Google id token received as result of the Google authentication.
 */
-(void) didFinishGoogleAuthenticationWithIdToken:(NSString*) googleIdToken;

/**
 *  Call this method if receiving a failure when trying to get the Google id token.
 *
 *  @param userInfo - error user info
 */
-(void) didFailGoogleAuthenticationWithUserInfo:(NSDictionary*) userInfo;

/**
 *  Add this method to your application delegate applicationDidBecomeActive
 *  This method will able to continue working with the application in case user start the login to Google but not finalize it.
 */
-(void) handleDidBecomeActive;

/**
 *  Add this method to your application delegate openURL
 *  This method allows to continue using the application in case the user starts the login to Google but does not finalize it.
 *
 *  @param isGoogleSigninInURL - is the URL scheme belong to Google
 */
- (void) handleOpenURL:(BOOL) isGoogleURL;

@end

@interface IMFGoogleAuthentication : NSObject

/**
 * Returns the current IMFGoogleAuthentication version
 */
+(NSString*) version;
@end
