/*
 * Licensed Materials - Property of IBM
 * (C) Copyright IBM Corp. 2006, 2013. All Rights Reserved.
 * US Government Users Restricted Rights - Use, duplication or
 * disclosure restricted by GSA ADP Schedule Contract with IBM Corp.
 */


#import <Foundation/Foundation.h>
#import "IMFResponse.h"

/**
 * This class manage all OAuth flow, from client registration to token generation.
 */
 
typedef NS_ENUM(NSInteger, IMFAuthorizationPerisistencePolicy) {
    IMFAuthorizationPerisistencePolicyAlways = 0,
    IMFAuthorizationPerisistencePolicyWithTouchBiometrics = 1,
    IMFAuthorizationPerisistencePolicyNever = 2
};

@interface IMFAuthorizationManager : NSObject

/**
 *  Get the cached authorization header from keychain.
 */
@property (nonatomic, readonly) NSString *cachedAuthorizationHeader;

@property (nonatomic, readonly) NSDictionary *userIdentity;

@property (nonatomic, readonly) NSDictionary *deviceIdentity;

@property (nonatomic, readonly) NSDictionary *appIdentity;

/**
 *  Get the IMFAuthorizationManager shared instance
 *
 *  @return IMFAuthorizationManager shared instance
 */
+ (IMFAuthorizationManager *) sharedInstance;
 
/**
 *  Explicit call to obtains the access token.
 *
 *  @param completionHandler The completion handler with response contains the authorization header value.
 */
- (void) obtainAuthorizationHeaderWithCompletionHandler:(void(^) (IMFResponse* response, NSError* error))completionHandler;

/**
 *  Add the authorization header value to any NSURLRequest request
 *
 *  @param request The request to add the authorization header
 */
- (void) addCachedAuthorizationHeaderToRequest:(NSMutableURLRequest*)request;

/**
 *  Set the authorization policy that defines way the application handles storing of authorization access token.
 *
 *  @param policy The persistence policy
 *  The policy can be one of the following:
 *	<ul>
 *  <li>__IMFAuthorizationPerisistencePolicyAlways__:
 *  Always store access token on the device (least secure option).
 *	The access tokens are persisted, regardless of whether Touch ID is present, supported, or enabled. Touch ID and device passcode authentication are never required.</li>
 *  <li>__IMFAuthorizationPerisistencePolicyWithTouchBiometrics__
 *  Use the Touch ID interface to fetch the access token from the key-chain (partially secure option).
 *	The access tokens are persisted, only if Touch ID is present, supported, and enabled.
 *	Touch ID or device passcode authentication are required to access the token once per client session.</li>
 *  <li>__IMFAuthorizationPerisistencePolicyNever__
 *  Never store access token on the device (most secure option).
 *	The access tokens are never persisted, meaning that an access token is valid for a single app session only.</li>
 *  </ul>
 *  The default policy is __IMFAuthorizationPerisistencePolicyAlways__.
 *
 *  Examples of use:
 *
 *  Set __IMFAuthorizationPerisistencePolicyAlways__ policy:<br />
 *          <pre><code>IMFAuthorizationManager* manager = [IMFAuthorizationManager sharedInstance];
 *          [manager setAuthorizationPersistencePolicy: IMFAuthorizationPerisistencePolicyAlways];</code></pre>
 *
 *  Set __IMFAuthorizationPerisistencePolicyWithTouchBiometrics__ policy:<br />
 *          <pre><code>IMFAuthorizationManager* manager = [IMFAuthorizationManager sharedInstance];
 *          [manager setAuthorizationPersistencePolicy: IMFAuthorizationPerisistencePolicyWithTouchBiometrics];</code></pre>
 *  
 *  Set __IMFAuthorizationPerisistencePolicyNever__ policy:<br />
 *          <pre><code>IMFAuthorizationManager* manager = [IMFAuthorizationManager sharedInstance];
 *          [manager setAuthorizationPersistencePolicy: IMFAuthorizationPerisistencePolicyNever];</code></pre>
 */
- (void) setAuthorizationPersistencePolicy: (IMFAuthorizationPerisistencePolicy) policy;


@end
