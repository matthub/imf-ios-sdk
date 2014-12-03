/*
 * Licensed Materials - Property of IBM
 * (C) Copyright IBM Corp. 2006, 2013. All Rights Reserved.
 * US Government Users Restricted Rights - Use, duplication or
 * disclosure restricted by GSA ADP Schedule Contract with IBM Corp.
 */

#import <Foundation/Foundation.h>

@class      IMFChallengeHandler;
@protocol   IMFAuthenticationDelegate;

/**
 *  the IMFClient error domain
 */
extern NSString * const IMFClientErrorDomain;

enum {
	IMFClientErrorInternalError = 1,
	IMFClientErrorUnresponsiveHost = 2,
	IMFClientErrorRequestTimeout = 3,
	IMFClientErrorServerError = 4,
    IMFClientErrorAuthenticationFailure = 5
};

/**
 *  The entery point to worklight
 */
@interface IMFClient : NSObject

/**
 * Specifies base backend URL
 */
@property (readonly) NSString* backendRoute;

/**
 * Specifies backend application id.
 */
@property (readonly) NSString* backendGUID;

/**
 * Specifies default request time out.
 */
@property (readwrite) NSTimeInterval defaultRequestTimeoutInterval;

/**
 *
 */
+ (IMFClient*)sharedInstance;

/**
 * Sets the base URL for the authorization server.
 * This method should be called before you send the first request that requires authorization.
 * @param url Specifies the base URL for the authorization server.
 * @param backendGUID Specifies the GUID of application
 */
-(void) initializeWithBackendRoute: (NSString*)backendRoute backendGUID:(NSString*)backendGUID;

/**
 * You use this method to add a global header, which is sent on each request.
 * Each IMFRequest instance will use this header as an HTTP header
 *
 * @param headerName The header name/key.
 * @param value The header value.
 */
-(void) addGlobalHeader: (NSString *) headerName headerValue:(NSString *)value;

/**
 * Removes a global header from the list of global headers to be added to all requests.
 * @param headerName The name of header to remove.
 */
- (void) removeGlobalHeader:(NSString*)headerName;

/**
 * Registers a delegate that will handle authentication for the specified realm.
 * @param authenticationDelegate A delegate that will handle authentication challeneges.
 * @param realm The name of realm.
 */
- (void) registerAuthenticationDelegate:(id<IMFAuthenticationDelegate>)authenticationDelegate forRealm:(NSString*)realm;

/**
 * Unregisters an authentication delegate for the specified realm.
 * @param realm The name of realm.
 */
- (void) unregisterAuthenticationDelegateForRealm:(NSString*)realm;

@end

@interface IMFCore : NSObject

/**
 * Returns the current IMFCore version
 */
+(NSString*) version;

@end
