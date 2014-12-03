/*
 * Licensed Materials - Property of IBM
 * (C) Copyright IBM Corp. 2014, 2014. All Rights Reserved.
 * US Government Users Restricted Rights - Use, duplication or
 * disclosure restricted by GSA ADP Schedule Contract with IBM Corp.
 */

#import <Foundation/Foundation.h>
/**
 The CDTDataObjectMetadata class defines metadata that is required to manage the CDTDataObject object.
 */
@interface CDTDataObjectMetadata : NSObject

/** Specifies a string that uniquely identifies this object. (read-only) */
@property (nonatomic, readonly) NSString	*documentId;

/** Specifies a string that identifies the revision for this object. (read-only) */
@property (nonatomic, readonly) NSString    *revisionId;

/** Indicates if this revision has been deleted. */
@property (nonatomic, readonly) BOOL        deleted;

@end
