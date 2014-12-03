/*
 * Licensed Materials - Property of IBM
 * (C) Copyright IBM Corp. 2014, 2014. All Rights Reserved.
 * US Government Users Restricted Rights - Use, duplication or
 * disclosure restricted by GSA ADP Schedule Contract with IBM Corp.
 */

#import <Foundation/Foundation.h>
#import <CloudantSync.h>
#import <IMFCore/IMFCore.h>
@class CDTStore;
@protocol CDTObjectMapper;

@class IMFDataManager;

/**
 The IMFDataManager is the central point for interacting with the Cloudant NoSQL database.
 */
@interface IMFDataManager : NSObject

/**
 Specifies the object mapper. This CDTObjectMapper is automatically set when a CDTStore is created.  By default, this value is set to the IMFDataObjectMapper class.
 */
@property (nonatomic, strong) id<CDTObjectMapper> defaultMapper;

/**
Specifies the CDTDatastoreManager for this class.
 */
@property (readonly, atomic) CDTDatastoreManager *datastoreManager;

/**
 Specifies the CDTReplicatorFactory for the manager.
 */
@property (readonly, atomic) CDTReplicatorFactory *replicatorFactory;


/**
 @return The sharedInstance of the IMFDataManager.
 */
+(instancetype) sharedInstance;

/**
 Creates a local data store.
 @param name Specifies the name of the store.
 @param error Specifies any errors, if an error was encountered.
 */
-(CDTStore*) localStore: (NSString*) name error: (NSError**) error;

/**
 Creates a remote data store.
 @param name Specifies the name of the data store.
 @param completionHandler Specifies the completion handler that gets invoked when the operation is completed.
 */
-(void) remoteStore: (NSString*) name completionHandler: (void(^) (CDTStore *store, NSError *error)) completionHandler;

/**
 Generates a CDTPullReplication.
 @param name Specifies the name of the data store to replicate from remote to local.
 */
-(CDTPullReplication*) pullReplicationForStore: (NSString*) name;

/**
 Generates a CDTPushReplication.
 @param name Specifies the name of the data store to replicate from local to remote.
 */
-(CDTPushReplication*) pushReplicationForStore: (NSString*) name;


/**
 Sets user permissions on a remote Cloudant database.
 @param access Specifies the access group to which to add the user.  Valid values are admins or members.
 @param storeName Specifies the name of the data store on which to set permissions.
 @param completionHandler Specifies the completion handler that gets invoked when the operation is completed.
 */
-(void) setCurrentUserPermissions:(NSString*)access forStoreName:(NSString*)storeName completionHander: (void(^) (BOOL success, NSError *error)) completionHandler;

@end

/**
 IMFData provides the current version of the IMFData framework.
 */
@interface IMFData : NSObject

/**
 @return The version of the IMFData framework.
 */
+(NSString*) version;

@end
