/*
 * Licensed Materials - Property of IBM
 * (C) Copyright IBM Corp. 2014, 2014. All Rights Reserved.
 * US Government Users Restricted Rights - Use, duplication or
 * disclosure restricted by GSA ADP Schedule Contract with IBM Corp.
 */

#import <Foundation/Foundation.h>
@protocol CDTObjectMapper;

@class CDTDatastore;
@class CDTQuery;

/**
 The CDTStore class is an abstract class for a class cluster.
 */
@interface CDTStore : NSObject

/** Specifies the CDTObjectMapper to use for mapping CDTDocumentRevision objects to objects and vice versa. */
@property id<CDTObjectMapper> mapper;

/**The CDTStore name*/
@property (readonly, atomic) NSString *name;

/**
 Creates a CDTStore that is local to the device.
 @param datastore Specifies the CDTDatastore from which to create the local CDTStore.
 @return The newly created CDTStore.
 */
+(CDTStore*) localStoreWithDatastore: (CDTDatastore*) datastore;


/**
 Creates a CDTStore that is local to the device.
 @param url Specifies the NSURL at which to create the remote CDTStore.
 @param completionHandler Specifies the completion handler to call when the remote datastore has been created.
 @return The newly created CDTStore.
 */
+(void) remoteStoreWithUrl:(NSURL *)url completionHandler:(void (^)(CDTStore* store, NSError *error))completionHandler;

/**
 Creates an index. If the CDTStore is local, a local CDTIndex is created on which you can perform queries.  If the CDTStore is remote only, a remote index is created on Cloudant.  If the CDTStore is a replicated store, only a local index is created.
 @param indexName Specifies the name of the new index.
 @param fields Specifies the field names to index.
 @param completionHandler Specifies the completionHandler to call upon completion. The creation of an index is an asynchronous event.  If the error is null, the operation was successful.
 */
-(void) createIndexWithName: (NSString*) indexName fields: (NSArray*) fields completionHandler: (void(^) (NSError *error)) completionHandler;

/**
 Deletes an index with a specific name. If the CDTStore is local, the local CDTIndex is deleted.  If the CDTStore is remote only, the remote index on Cloudant is deleted.   If the CDTStore is a replicated store, only the local index is deleted.
 @param indexName Specifies the name of the index to delete.
 @param completionHandler Specifies the completionHandler to call upon completion. The deletion of an index is an asynchronous event.  If the error is null, the operation was successful.
 */
-(void) deleteIndexWithName: (NSString*) indexName completionHandler: (void(^) (NSError *error)) completionHandler;

/**
 Creates an index with a data type. If the CDTStore is local, a local CDTIndex is created on which you can perform queries.  If the CDTStore is remote only, a remote index is created on Cloudant.  If the CDTStore is a replicated store, only a local index is created.
 @param dataType Specifies the class on which to create an index.
 @param fields Specifies the field names to index.
 @param completionHandler Specifies the completionHandler to call upon completion. The creation of an index is an asynchronous event.  If the error is null, the operation was successful.
 */
-(void) createIndexWithDataType: (NSString*) dataType fields: (NSArray*) fields completionHandler: (void(^) (NSError *error)) completionHandler;

/**
Deletes an index with a data type. If the CDTStore is local, the local CDTIndex is deleted.  If the CDTStore is remote only, the remote index is deleted on Cloudant.  If the CDTStore is a replicated store, only a local index is deleted.
 @param dataType Specifies the class on which to delete an index.
 @param completionHandler Specifies the completionHandler to call upon completion. The deletion of an index is an asynchronous event.  If the error is null, the operation was successful.
 */
-(void) deleteIndexWithDataType: (NSString*) dataType completionHandler: (void(^) (NSError *error)) completionHandler;

/**
 * Runs a query on the database. When the query is completed, the results are passed back in the array.
 * An error is set if an error occurs, otherwise the value of the error is nil. See CDTQueryOperation for more
 * information about running queries.
 * @param query Specifies the query to run
 * @param completionHandler Specifies the completionHandler to call when the query completes.
 */
- (void) performQuery:(CDTQuery *)query completionHandler:(void (^)(NSArray *results, NSError *error)) completionHandler;

/**
 Saves an object.
 @param objectToSave Specifies the object to save.
 @param completionHandler Specifies the completionHandler to call when the save is complete. Saving an object is an asynchronous event.  If error is null, the operation was successful.
 */
-(void) save: (id) objectToSave completionHandler: (void (^)(id savedObject, NSError *error))completionHandler;

/**
 Deletes an object.
 @param objectToDelete Specifies the object to delete.
 @param completionHandler Specifies the completionHandler to call when the deletion is complete. Deleting an object is an asynchronous event.  If error is null, the operation was successful.
 */
-(void) delete: (id) objectToDelete completionHandler: (void (^)(NSString* deletedObjectId, NSString *deletedRevisionId, NSError *error))completionHandler;

/**
 Fetches an object with the objectId.
 @param documentId Specifies the object to fetch.
 @param completionHandler Specifies the completionHandler to call when the fetch is complete. Fetching an object is an asynchronous event.  If error is null, the operation was successful.
 */
-(void) fetchById: (NSString*) documentId completionHandler: (void (^)(id object, NSError *error))completionHandler;

@end
