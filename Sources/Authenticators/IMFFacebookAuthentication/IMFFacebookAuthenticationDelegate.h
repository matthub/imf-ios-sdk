/*
 * Licensed Materials - Property of IBM
 * (C) Copyright IBM Corp. 2006, 2013. All Rights Reserved.
 * US Government Users Restricted Rights - Use, duplication or
 * disclosure restricted by GSA ADP Schedule Contract with IBM Corp.
 */

@class IMFFacebookAuthenticationHandler;

@protocol IMFFacebookAuthenticationDelegate

- (void)authenticationHandler:(IMFFacebookAuthenticationHandler*)authenticationHandler didReceiveAuthenticationRequestForAppId:(NSString*)appId;

@end
