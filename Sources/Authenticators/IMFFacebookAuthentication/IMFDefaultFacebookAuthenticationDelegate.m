/*
 * IBM Confidential OCO Source Materials
 * 
 * Copyright IBM Corp. 2006, 2013
 * 
 * The source code for this program is not published or otherwise
 * divested of its trade secrets, irrespective of what has
 * been deposited with the U.S. Copyright Office.
 * 
 */

#import <FacebookSDK/FacebookSDK.h>
#import "IMFDefaultFacebookAuthenticationDelegate.h"
#import "IMFFacebookAuthenticationHandler.h"

@implementation IMFDefaultFacebookAuthenticationDelegate

- (void) authenticationHandler:(IMFFacebookAuthenticationHandler *)authenticationHandler didReceiveAuthenticationRequestForAppId:(NSString *)appId {
    [FBSession openActiveSessionWithReadPermissions:@[@"public_profile"]
                                       allowLoginUI:YES
                                  completionHandler:
     ^(FBSession *session, FBSessionState state, NSError *error) {
         if (!error && state == FBSessionStateOpen){
             NSString *accessToken = [[session accessTokenData] accessToken];
             [authenticationHandler didFinishFacebookAuthenticationWithAccessToken: accessToken];
             return;
         }
         
         if (state == FBSessionStateClosed || state == FBSessionStateClosedLoginFailed){
             [FBSession.activeSession closeAndClearTokenInformation];
             NSLog(@"Could not get an access token from facebook: %@", [error userInfo]);
             
             [authenticationHandler didFailFacebookAuthenticationWithUserInfo: [error userInfo]];
         }
     }];
}

@end
