/*
 * Licensed Materials - Property of IBM
 * (C) Copyright IBM Corp. 2006, 2013. All Rights Reserved.
 * US Government Users Restricted Rights - Use, duplication or
 * disclosure restricted by GSA ADP Schedule Contract with IBM Corp.
 */
//
//  IMFResourceRequest.h
//  IMFCore
//
//  Created by Vitaly Meytin on 9/2/14.
//  Copyright (c) 2014 IBM. All rights reserved.
//
#import <Foundation/Foundation.h>

enum {
    /**
     Internal request error
     */
    IMFResourseRequestErrorInternalError = 1,
    /**
     Resource request is not initialized. Call one of requestWithPath initializers first.
     */
    IMFResourseRequestErrorNotInitialized = 2,
    /**
     Request method is nil.
     */
    IMFResourseRequestErrorInvalidMethod = 3
};

@class IMFResponse;

@interface IMFResourceRequest : NSObject

/**
 * Returns an IMFResourceRequest object initialized with path. The path should not be nil, otherwise other methods will fail.
 * @param path Path to resource.
 * @return IMFResourceRequest initialized with path to resource.
 */
+(IMFResourceRequest*)requestWithPath:(NSString*)path;

/**
 * Returns an IMFResourceRequest object initialized with path and request method. The path should not be nil, otherwise other methods will fail.
 * @param path Path to resource.
 * @param method Request method. It can be any of allowed HTTP methods (for example "GET", "POST", "PUT", "DELETE", "HEAD").
 * @return IMFResourceRequest initialized with path to resource and request method.
 */
+(IMFResourceRequest*)requestWithPath:(NSString*)path method:(NSString*)method;

/**
 * Returns an IMFResourceRequest object initialized with path, request method and request parameters. The path should not be nil, otherwise other methods will fail.
 * @param path Path to resource
 * @param method Request method. It can be any of allowed HTTP methods (for example "GET", "POST", "PUT", "DELETE", "HEAD").
 * @param parameters Request parameters.
 * @return IMFResourceRequest initialized with path to resource, request method and request parameters.
 */
+(IMFResourceRequest*)requestWithPath:(NSString*)path method:(NSString*)method parameters:(NSDictionary*)parameters;

/**
 * Returns an IMFResourceRequest object initialized with path, request method and request parameters. The path should not be nil, otherwise other methods will fail.
 * @param path Path to resource
 * @param method Request method. It can be any of allowed HTTP methods (for example "GET", "POST", "PUT", "DELETE", "HEAD").
 * @param parameters Request parameters.
 * @param timeout Request timeout.
 * @return IMFResourceRequest initialized with path to resource, request method, request parameters and timeot.
 */
+(IMFResourceRequest*)requestWithPath:(NSString*)path method:(NSString*)method parameters:(NSDictionary*)parameters timeout:(NSTimeInterval)timeoutInterval;

/**
 * Sets request timeout
 * @param timeoutInterval Request timeout interval in seconds.
 */
-(void)setTimeoutInterval:(NSTimeInterval)timeoutInterval;

/**
 * Sets header value
 * @param value Value to set
 * @param forHTTPHeaderField Header field
 */
-(void)setValue:(NSString*)value forHTTPHeaderField:(NSString*)field;

/**
 * Sets request parameters
 * @param parameters Request parameters
 */
-(void)setParameters:(NSDictionary*)parameters;

/**
 * Sets HTTP body. Should be used for POST requests.
 * @param data The data to be set
 */
-(void)setHTTPBody:(NSData*)data;

/**
 * Sets request method.
 * @param method Request method. It can be any of allowed HTTP methods (for example "GET", "POST", "PUT", "DELETE", "HEAD").
 */
-(void)setHTTPMethod:(NSString*)method;

/**
 * Sends request to resource. The request must have been initialized with a valid path.
 * @discussion If the request is completed successfully, the <i>error</> parameter of completion block is nil and the <i>response</i> parameter 
 * contains server response. If the request fails, the <i>error</i> parameter is not nil and contains error description. The <i>response</i> parameter may contain
 * a response fro server, or may be nil.
 * @param completionHandler A block to be called when the request is completed.
 */
-(void)sendWithCompletionHandler:(void(^) (IMFResponse* response, NSError* error))completionHandler;

@end
