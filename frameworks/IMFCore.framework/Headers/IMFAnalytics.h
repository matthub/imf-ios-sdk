/*
 * Licensed Materials - Property of IBM
 * (C) Copyright IBM Corp. 2006, 2013. All Rights Reserved.
 * US Government Users Restricted Rights - Use, duplication or
 * disclosure restricted by GSA ADP Schedule Contract with IBM Corp.
 */
 
#import <Foundation/Foundation.h>

/**
 IMFAnalytics is an extension to IMFLogger and has the ability to persistently store Analytics log data.
 Use this class to store Analytics data which can later be visualized on the Analytics console.
 */
@interface IMFAnalytics : NSObject

/**
 Provides an instance of the Analytics object.
 @return self
 */
+ (IMFAnalytics *) sharedInstance;

/**
 This method must be called in order for application lifecycle events (app startup time, session events) to be automatically recorded. This method is typically called in the didFinishLaunchingWithOptions method.
 */
- (void) startRecordingApplicationLifecycleEvents;

/**
 This method must be called in order to stop automatic recording of application lifecycle events.
 */
- (void) stopRecordingApplicationLifecycleEvents;

/**
 This method logs a message at the analytics level.
 @param eventName name of the event being logged
 */
- (void) logEvent:(NSString*)eventName;

/**
 This method logs a message at the analytics level.
 @param eventName Name of the event being logged
 @param metadata Dictionary containing metadata to append to the log output
 */
- (void) logEvent:(NSString*)eventName withMetadata:(NSDictionary*)metadata;

/**
 This method sends the analytics log file when the log store exists and is not empty. If the send fails, the local store is preserved. If the send succeeds, the local store is deleted.
 */
- (void) sendPersistedLogs;

/**
 This method sends the analytics log on a specified interval in seconds. By default, the logs will not be sent on interval.
 @param Interval in seconds defining how often analytics logs will be automatically sent.
 */
- (void)startSendingPersistedLogsWithInterval: (NSTimeInterval) intervalInSeconds;

/**
 This method will stop the automatic sending of analytics data on an interval.
 */
- (void)stopSendingPersistedLogsOnInterval;

/**
 This method turns the global setting for persisting of the analytics data.
 @param enabled Boolean used to indicate whether the log data must be saved persistently.
 */
- (void) setEnabled: (BOOL) enabled;

/**
 This method gets the current setting for determining if log data should be saved persistently.
 @return Boolean indicating whether the log data must be saved persistently.
 */
- (BOOL) isEnabled;

@end