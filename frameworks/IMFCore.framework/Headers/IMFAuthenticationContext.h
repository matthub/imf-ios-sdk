/*
 * Licensed Materials - Property of IBM
 * (C) Copyright IBM Corp. 2006, 2013. All Rights Reserved.
 * US Government Users Restricted Rights - Use, duplication or
 * disclosure restricted by GSA ADP Schedule Contract with IBM Corp.
 */

//
//  IMFAuthenticationContext.h
//  IMFCore
//
//  Created by Vitaly Meytin on 9/3/14.
//  Copyright (c) 2014 IBM. All rights reserved.
//

@protocol IMFAuthenticationContext <NSObject>

/**
 * Submits authentication challenge answer.
 @param answer Dicitionary with challenge answers.
 */
-(void) submitAuthenticationChallengeAnswer:(NSDictionary*) answer;

/**
 * Informs about authentication success.
 */
-(void) submitAuthenticationSuccess;

/**
 * Informs about authentication failure.
 @param userInfo Dictionary with extended information about failure.
 */
-(void) submitAuthenticationFailure:(NSDictionary*) userInfo;

@end
