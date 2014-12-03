/*
 * Licensed Materials - Property of IBM
 * (C) Copyright IBM Corp. 2006, 2013. All Rights Reserved.
 * US Government Users Restricted Rights - Use, duplication or
 * disclosure restricted by GSA ADP Schedule Contract with IBM Corp.
 */

#import <Foundation/Foundation.h>

/** 
 Used to specify the desired log level.
 */
typedef NS_ENUM(NSInteger, IMFLogLevel) {
    
    /** Trace level. */
    IMFLogLevelTrace = 600,
    
    /** Debug level. */
    IMFLogLevelDebug = 500,
    
    /** Log level. */
    IMFLogLevelLog = 400,
    
    /** Info level. */
    IMFLogLevelInfo = 300,
    
    /** Warn level. */
    IMFLogLevelWarn = 200,
    
    /** Error level. */
    IMFLogLevelError = 100,
    
    /** Fatal level. */
    IMFLogLevelFatal = 50,
    
    /** Analytics level. */
    IMFLogLevelAnalytics = 25
};

/**
 IMFLogger is a drop-in replacement for nslog.  It is a feature-rich
 log class, with standard logger capabilities like levels, filters,
 and well-structured output formatting.  IMFLogger also has the ability
 to attach additional metadata (by passing an NSDictionary object) to
 log output.
 
 IMFLogger can also capture log output to local application storage
 within a storage size threshold with log rollover so that the captured
 logs can be sent to a server for debugging production-time problems
 occurring in the field.
 
 IMFLogger has built-in capability to capture uncaught exceptions, which
 appear to the end-user as a crashed application.  The presence of
 IMFLogger in an application is sufficient to enable this capture.
 
 Some parts of IMF framework code have already been instrumented with
 IMFLogger API calls.
 
 As a convenience, developers may use IMFLogger macros.  These macros
 automatically record the class name, file name, method, and line number
 of the IMFLogger function call in the metadata of the log record.
 
 The macros are as follows, where all parameters are of type NSString:
 
 - IMFLogTrace(message, ...)
 - IMFLogDebug(message, ...)
 - IMFLogInfo(message, ...)
 - IMFLogWarn(message, ...)
 - IMFLogError(message, ...)
 - IMFLogFatal(message, ...)
 - IMFLogAnalytics(message, ...)
 
 - IMFLogTraceWithName(name, message, ...)
 - IMFLogDebugWithName(name, message, ...)
 - IMFLogInfoWithName(name, message, ...)
 - IMFLogWarnWithName(name, message, ...)
 - IMFLogErrorWithName(name, message, ...)
 - IMFLogFatalWithName(name, message, ...)
 */
@interface IMFLogger : NSObject

#pragma mark Instance Methods

/** 
 This method logs a message at the trace level.
 @param message Message to be logged.
 @param ... Values to be replaced in the message parameter.
 */
-(void) logTraceWithMessages: (NSString*) message, ...;

/** 
 This method logs a message at the debug level.
 @param message Message to be logged.
 @param ... Values to be replaced in the message parameter.
 */
-(void) logDebugWithMessages: (NSString*) message, ...;

/** 
 This method logs a message at the info level.
 @param message Message to be logged.
 @param ... Values to be replaced in the message parameter.
 */
-(void) logInfoWithMessages: (NSString*) message, ...;

/** 
 This method logs a message at the warning level.
 @param message Message to be logged.
 @param ... Values to be replaced in the message parameter.
 */
-(void) logWarnWithMessages: (NSString*) message, ...;

/** 
 This method logs a message at the error level.
 @param message Message to be logged.
 @param ... Values to be replaced in the message parameter.
 */
-(void) logErrorWithMessages: (NSString*) message, ...;

/** 
 This method logs a message at the fatal level.
 @param message Message to be logged.
 @param ... Values to be replaced in the message parameter.
 */
-(void) logFatalWithMessages: (NSString*) message, ...;

/** 
 This method logs a message at the trace level.
 @param userInfo NSDictionary containing user info to append to the log output
 @param message Message to be logged.
 @param ... Values to be replaced in the message parameter.
 */
-(void) logTraceWithUserInfo:(NSDictionary*) userInfo andMessages: (NSString*) message, ...;

/** 
 This method logs a message at the debug level.
 @param userInfo NSDictionary containing user info to append to the log output.
 @param message Message to be logged.
 @param ... Values to be replaced in the message parameter.
 */
-(void) logDebugWithUserInfo:(NSDictionary*) userInfo andMessages: (NSString*) message, ...;

/** 
 This method logs a message at the info level.
 @param userInfo NSDictionary containing user info to append to the log output.
 @param message Message to be logged.
 @param ... Values to be replaced in the message parameter.
 */
-(void) logInfoWithUserInfo:(NSDictionary*) userInfo andMessages: (NSString*) message, ...;

/** 
 This method logs a message at the warn level.
 @param userInfo NSDictionary containing user info to append to the log output.
 @param message Message to be logged.
 @param ... Values to be replaced in the message parameter.
 */
-(void) logWarnWithUserInfo:(NSDictionary*) userInfo andMessages: (NSString*) message, ...;

/** 
 This method logs a message at the error level.
 @param userInfo NSDictionary containing user info to append to the log output.
 @param message Message to be logged.
 @param ... Values to be replaced in the message parameter.
 */
-(void) logErrorWithUserInfo:(NSDictionary*) userInfo andMessages: (NSString*) message, ...;

/** 
 This method logs a message at the fatal level.
 @param userInfo NSDictionary containing user info to append to the log output.
 @param message Message to be logged.
 @param ... Values to be replaced in the message parameter.
 */
-(void) logFatalWithUserInfo:(NSDictionary*) userInfo andMessages: (NSString*) message, ...;

/** 
 This method logs a message at the analytics level.
 @param userInfo NSDictionary containing user info to append to the log output.
 @param message Message to be logged.
 @param ... Values to be replaced in the message parameter.
 */
-(void) logAnalyticsWithUserInfo:(NSDictionary*) userInfo andMessages: (NSString*) message, ...;

#pragma mark Getters and Setters

/** 
 Sets the name for the IMFLogger instance.
 @param name Name of the IMFLogger instance.
 */
-(void) setName:(NSString*) name;

/** 
 Getter for the name of the IMFLogger instance.
 @return name of the IMFLogger instance.
 */
-(NSString*) name;

#pragma mark Static methods

/** 
 This method gets or creates an instance of this logger. If an instance exists for the name parameter, that instance is returned.
 @param name String denoting name that must be printed with log messages. The value is passed through to NSLog and recorded when log capture is enabled.
 @return IMFLogger instance used to invoke log calls.
 */
+(IMFLogger*) loggerForName: (NSString*) name;

/** 
 This method sends the log file when the log store exists and is not empty.  If the send fails, the local store is preserved.  If the send succeeds, the local store is deleted.
 */
+(void) send;

/** 
 This method gets the current setting for determining if log data should be saved persistently.
 @return Boolean flag indicating whether the log data must be saved persistently.
 */
+(BOOL) getCapture;

/** 
 Global setting: turn persisting of the log data that is passed to the log methods of this class, on or off.
 @param flag Boolean used to indicate whether the log data must be saved persistently.
 */
+(void) setCapture: (BOOL) flag;

/** 
 This method will retrieve the filters that are used to determine which log messages are persisted.
 @return Dictionary defining the logging filters.
 */
+(NSDictionary*) getFilters;

/** 
 This method sets the filters that are used to determine which log messages are persisted. Each key defines a name and each value defines a logging level.
 @param filters Dictionary containing the name and logging level key value pairs that are used to filter persisted logs.
*/
+(void) setFilters: (NSDictionary*) filters;

/** 
 This method gets the current setting for the maximum storage size threshold.
 @return Integer indicating the maximum storage size threshold.
 */
+(int) getMaxStoreSize;

/** 
 This method sets the maximum size of the local persistent storage for queueing log data. When the maximum storage size is reached, no more data is queued. This content of the storage is sent to a server.
 @param bytes Integer defining the maximum size of the store in bytes, the minimum is 10,000 bytes.
 */
+(void) setMaxStoreSize: (int) bytes;

/** 
 This method gets the currently configured IMFLogLevel and returns IMFLogLevel.
 @return IMFLogLevel for the current log level.
 */
+(IMFLogLevel) getLogLevel;

/** 
 This method sets the level from which log messages must be saved and printed. For example, passing IMFLogLevel.IMFLogger_INFO logs INFO, WARN, and ERROR.
 @param level IMFLogLevel The valid values of this input parameter are IMFLogger_TRACE, IMFLogger_DEBUG, IMFLogger_LOG, IMFLogger_INFO, IMFLogger_WARN, and IMFLogger_ERROR.
 */
+(void) setLogLevel: (IMFLogLevel) level;

/** 
 This method indicates that an uncaught exception was detected. The indicator is cleared on successful send.
 @return Boolean that indicates an uncaught exception was detected (true) or not (false).
 */
+(BOOL) uncaughtExceptionDetected;

/**
 This method will enable IMFLogger to capture uncaught exceptions.
 */
+(void) captureUncaughtExceptions;

@end
