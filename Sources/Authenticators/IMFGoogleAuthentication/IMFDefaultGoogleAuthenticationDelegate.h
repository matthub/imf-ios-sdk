/*
 * Licensed Materials - Property of IBM
 * (C) Copyright IBM Corp. 2006, 2013. All Rights Reserved.
 * US Government Users Restricted Rights - Use, duplication or
 * disclosure restricted by GSA ADP Schedule Contract with IBM Corp.
 */

#import <Foundation/Foundation.h>
#import "IMFGoogleAuthenticationDelegate.h"
#import <GoogleOpenSource/GoogleOpenSource.h>
#import <GooglePlus/GooglePlus.h>

/**
 *  Deafault Google authentication. 
 *  To use the default Google delegate call to: [[IMFGoogleAuthenticationHandler sharedInstance] registerWithDefaultDelegate] before any call to a protected resource.
 */
@interface IMFDefaultGoogleAuthenticationDelegate : NSObject <IMFGoogleAuthenticationDelegate, GPPSignInDelegate>

@end
