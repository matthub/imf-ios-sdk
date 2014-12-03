/*
 * Licensed Materials - Property of IBM
 * (C) Copyright IBM Corp. 2006, 2013. All Rights Reserved.
 * US Government Users Restricted Rights - Use, duplication or
 * disclosure restricted by GSA ADP Schedule Contract with IBM Corp.
 */

#import <Foundation/Foundation.h>
#import "IMFGoogleAuthenticationHandler.h"

@class IMFGoogleAuthenticationHandler;

/**
 *  To implement custom Google authentication you need to implememnt this protocol
 */
@protocol IMFGoogleAuthenticationDelegate <NSObject>

/**
 *  Use this method to call the Google sign-in.
 *
 *  @param authenticationHandler The Google autentication handler.  This handler will receive the id token when sign-in is complete.
 *  @param clientId Client id receiveed from the dashboard.
 */

- (void)authenticationHandler: (IMFGoogleAuthenticationHandler *) authenticationHandler didReceiveAuthenticationRequestForClientId:(NSString*)clientId;

@end
