///
/// Copyright (c) 2016 Dropbox, Inc. All rights reserved.
///

#import <Foundation/Foundation.h>

#import "DBCOMMONPathRoot.h"
#import "DBTransportBaseConfig.h"

NS_ASSUME_NONNULL_BEGIN

///
/// Configuration class for `DBTransportDefaultClient`.
///
@interface DBTransportDefaultConfig : DBTransportBaseConfig

/// A serial delegate queue used for executing blocks of code that touch state shared across threads (mainly the request
/// handlers storage).
@property (nonatomic, readonly, nullable) NSOperationQueue *delegateQueue;

/// If set to true, all network requests are made on foreground sessions (by default, most upload/download operations
/// are performed with a background session). This is appropriate for use cases where file upload / download operations
/// will be quick, and immediate response is preferable. Otherwise, for background sessions, uploads/downloads will
/// essentially never time out, if network connection is lost after the request has begun.
@property (nonatomic, readonly) BOOL forceForegroundSession;

/// The identifier for the shared container into which files in background URL sessions should be downloaded. This needs
/// to be set when downloading via an app extension.
@property (nonatomic, readonly, nullable) NSString *sharedContainerIdentifier;

/// The service name for the keychain. If it is nil, the default keychain service name is used, which consists of the main bundle id.
/// The keychain service name must be set manually if the keychain is to be shared (for example with an app extension).  
@property (nonatomic, readonly, nullable) NSString *keychainService;

///
/// Convenience constructor.
///
/// @param appKey The consumer app key associated with the app that is integrating with the Dropbox API. Here, app key
/// is used for querying endpoints that have "app auth" authentication type.
///
/// @return An initialized instance.
///
- (instancetype)initWithAppKey:(NSString *)appKey;

///
/// Convenience constructor.
///
/// Appropriate for apps that want to query endpoints with "app auth" authentication type.
///
/// @param appKey The consumer app key associated with the app that is integrating with the Dropbox API. Here, app key
/// is used for querying endpoints that have "app auth" authentication type.
/// @param appSecret The consumer app secret associated with the app that is integrating with the Dropbox API. Here, app
/// key is used for querying endpoints that have "app auth" authentication type.
///
/// @return An initialized instance.
///
- (instancetype)initWithAppKey:(NSString *)appKey appSecret:(NSString *)appSecret;

///
/// Convenience constructor.
///
/// Appropriate for apps that want to query endpoints with "app auth" authentication type.
///
/// @param appKey The consumer app key associated with the app that is integrating with the Dropbox API. Here, app key
/// is used for querying endpoints that have "app auth" authentication type.
/// @param appSecret The consumer app secret associated with the app that is integrating with the Dropbox API. Here, app
/// key is used for querying endpoints that have "app auth" authentication type.
/// @param delegateQueue A serial delegate queue used for executing blocks of code that touch state shared across
/// threads (mainly the request handlers storage).
///
/// @return An initialized instance.
///
- (instancetype)initWithAppKey:(NSString *)appKey
                     appSecret:(NSString *)appSecret
                 delegateQueue:(nullable NSOperationQueue *)delegateQueue;

///
/// Convenience constructor.
///
/// Appropriate for use cases where file upload / download operations will be quick, and immediate response is
/// preferable. Otherwise, for background sessions, uploads/downloads will essentially never time out, if network
/// connection is lost after the request has begun.
///
/// @param appKey The consumer app key associated with the app that is integrating with the Dropbox API. Here, app key
/// is used for querying endpoints that have "app auth" authentication type.
/// @param forceForegroundSession If set to true, all network requests are made on foreground sessions (by default, most
/// upload/download operations are performed with a background session).
///
/// @return An initialized instance.
///
- (instancetype)initWithAppKey:(NSString *)appKey forceForegroundSession:(BOOL)forceForegroundSession;

///
/// Convenience constructor.
///
/// @param appKey The consumer app key associated with the app that is integrating with the Dropbox API. Here, app key
/// is used for querying endpoints that have "app auth" authentication type.
/// @param appSecret The consumer app secret associated with the app that is integrating with the Dropbox API. Here, app
/// key is used for querying endpoints that have "app auth" authentication type.
/// @param userAgent The user agent associated with all networking requests. Used for server logging.
/// @param delegateQueue A serial delegate queue used for executing blocks of code that touch state shared across
/// threads (mainly the request handlers storage).
/// @param forceForegroundSession If set to true, all network requests are made on foreground sessions (by default, most
/// upload/download operations are performed with a background session).
///
/// @return An initialized instance.
///
- (instancetype)initWithAppKey:(NSString *)appKey
                     appSecret:(nullable NSString *)appSecret
                     userAgent:(nullable NSString *)userAgent
                 delegateQueue:(nullable NSOperationQueue *)delegateQueue
        forceForegroundSession:(BOOL)forceForegroundSession;

///
/// Convenience constructor.
///
/// @param appKey The consumer app key associated with the app that is integrating with the Dropbox API. Here, app key
/// is used for querying endpoints that have "app auth" authentication type.
/// @param appSecret The consumer app secret associated with the app that is integrating with the Dropbox API. Here, app
/// key is used for querying endpoints that have "app auth" authentication type.
/// @param userAgent The user agent associated with all networking requests. Used for server logging.
/// @param delegateQueue A serial delegate queue used for executing blocks of code that touch state shared across
/// threads (mainly the request handlers storage).
/// @param forceForegroundSession If set to true, all network requests are made on foreground sessions (by default, most
/// upload/download operations are performed with a background session).
/// @param asMemberId An additional authentication header field used when a team app with the appropriate permissions
/// "performs" user API actions on behalf of a team member.
///
/// @return An initialized instance.
///
- (instancetype)initWithAppKey:(NSString *)appKey
                     appSecret:(nullable NSString *)appSecret
                     userAgent:(nullable NSString *)userAgent
                    asMemberId:(nullable NSString *)asMemberId
                 delegateQueue:(nullable NSOperationQueue *)delegateQueue
        forceForegroundSession:(BOOL)forceForegroundSession;

///
/// Convenience constructor.
///
/// @param appKey The consumer app key associated with the app that is integrating with the Dropbox API. Here, app key
/// is used for querying endpoints that have "app auth" authentication type.
/// @param appSecret The consumer app secret associated with the app that is integrating with the Dropbox API. Here, app
/// key is used for querying endpoints that have "app auth" authentication type.
/// @param userAgent The user agent associated with all networking requests. Used for server logging.
/// @param delegateQueue A serial delegate queue used for executing blocks of code that touch state shared across
/// threads (mainly the request handlers storage).
/// @param forceForegroundSession If set to true, all network requests are made on foreground sessions (by default, most
/// upload/download operations are performed with a background session).
/// @param asMemberId An additional authentication header field used when a team app with the appropriate permissions
/// "performs" user API actions on behalf of a team member.
/// @param sharedContainerIdentifier The identifier for the shared container into which files in background URL sessions
/// should be downloaded. This needs to be set when downloading via an app extension.
/// @param keychainService The service name for the keychain. Leave nil to use default
///
/// @return An initialized instance.
///
- (instancetype)initWithAppKey:(NSString *)appKey
                     appSecret:(nullable NSString *)appSecret
                     userAgent:(nullable NSString *)userAgent
                    asMemberId:(nullable NSString *)asMemberId
                 delegateQueue:(nullable NSOperationQueue *)delegateQueue
        forceForegroundSession:(BOOL)forceForegroundSession
     sharedContainerIdentifier:(nullable NSString *)sharedContainerIdentifier
			   keychainService:(nullable NSString *)keychainService;

///
/// Full constructor.
///
/// @param appKey The consumer app key associated with the app that is integrating with the Dropbox API. Here, app key
/// is used for querying endpoints that have "app auth" authentication type.
/// @param appSecret The consumer app secret associated with the app that is integrating with the Dropbox API. Here, app
/// key is used for querying endpoints that have "app auth" authentication type.
/// @param userAgent The user agent associated with all networking requests. Used for server logging.
/// @param delegateQueue A serial delegate queue used for executing blocks of code that touch state shared across
/// threads (mainly the request handlers storage).
/// @param forceForegroundSession If set to true, all network requests are made on foreground sessions (by default, most
/// upload/download operations are performed with a background session).
/// @param asMemberId An additional authentication header field used when a team app with the appropriate permissions
/// "performs" user API actions on behalf of a team member.
/// @param sharedContainerIdentifier The identifier for the shared container into which files in background URL sessions
/// should be downloaded. This needs to be set when downloading via an app extension.
/// @param additionalHeaders Additional HTTP headers to be injected into each client request.
/// @param keychainService The service name for the keychain. Leave nil to use default
///
/// @return An initialized instance.
///
- (instancetype)initWithAppKey:(NSString *)appKey
                     appSecret:(nullable NSString *)appSecret
                     userAgent:(nullable NSString *)userAgent
                    asMemberId:(nullable NSString *)asMemberId
             additionalHeaders:(nullable NSDictionary<NSString *, NSString *> *)additionalHeaders
                 delegateQueue:(nullable NSOperationQueue *)delegateQueue
        forceForegroundSession:(BOOL)forceForegroundSession
	 sharedContainerIdentifier:(nullable NSString *)sharedContainerIdentifier
			   keychainService:(nullable NSString *)keychainService;

///
/// Full constructor, with debug hostname override.
///
/// @param appKey The consumer app key associated with the app that is integrating with the Dropbox API. Here, app key
/// is used for querying endpoints that have "app auth" authentication type.
/// @param appSecret The consumer app secret associated with the app that is integrating with the Dropbox API. Here, app
/// key is used for querying endpoints that have "app auth" authentication type.
/// @param hostnameConfig A custom hostname to use for networking requests. Only useful for debugging purposes.
/// @param userAgent The user agent associated with all networking requests. Used for server logging.
/// @param delegateQueue A serial delegate queue used for executing blocks of code that touch state shared across
/// threads (mainly the request handlers storage).
/// @param forceForegroundSession If set to true, all network requests are made on foreground sessions (by default, most
/// upload/download operations are performed with a background session).
/// @param asMemberId An additional authentication header field used when a team app with the appropriate permissions
/// "performs" user API actions on behalf of a team member.
/// @param sharedContainerIdentifier The identifier for the shared container into which files in background URL sessions
/// should be downloaded. This needs to be set when downloading via an app extension.
/// @param additionalHeaders Additional HTTP headers to be injected into each client request.
/// @param keychainService The service name for the keychain. Leave nil to use default
///
/// @return An initialized instance.
///
- (instancetype)initWithAppKey:(NSString *)appKey
                     appSecret:(nullable NSString *)appSecret
                hostnameConfig:(nullable DBTransportBaseHostnameConfig *)hostnameConfig
                     userAgent:(nullable NSString *)userAgent
                    asMemberId:(nullable NSString *)asMemberId
             additionalHeaders:(nullable NSDictionary<NSString *, NSString *> *)additionalHeaders
                 delegateQueue:(nullable NSOperationQueue *)delegateQueue
        forceForegroundSession:(BOOL)forceForegroundSession
     sharedContainerIdentifier:(nullable NSString *)sharedContainerIdentifier
			   keychainService:(nullable NSString *)keychainService;

///
/// Full constructor, with debug hostname and redirectURL override.
///
/// @param appKey The consumer app key associated with the app that is integrating with the Dropbox API. Here, app key
/// is used for querying endpoints that have "app auth" authentication type.
/// @param appSecret The consumer app secret associated with the app that is integrating with the Dropbox API. Here, app
/// key is used for querying endpoints that have "app auth" authentication type.
/// @param hostnameConfig A custom hostname to use for networking requests. Only useful for debugging purposes.
/// @param userAgent The user agent associated with all networking requests. Used for server logging.
/// @param delegateQueue A serial delegate queue used for executing blocks of code that touch state shared across
/// threads (mainly the request handlers storage).
/// @param forceForegroundSession If set to true, all network requests are made on foreground sessions (by default, most
/// upload/download operations are performed with a background session).
/// @param asMemberId An additional authentication header field used when a team app with the appropriate permissions
/// "performs" user API actions on behalf of a team member.
/// @param pathRoot The value of path root object which will be used as Dropbox-Api-Path-Root header.
/// @param sharedContainerIdentifier The identifier for the shared container into which files in background URL sessions
/// should be downloaded. This needs to be set when downloading via an app extension.
/// @param additionalHeaders Additional HTTP headers to be injected into each client request.
/// @param keychainService The service name for the keychain. Leave nil to use default
///
/// @return An initialized instance.
///
- (instancetype)initWithAppKey:(NSString *)appKey
                     appSecret:(nullable NSString *)appSecret
                hostnameConfig:(nullable DBTransportBaseHostnameConfig *)hostnameConfig
                   redirectURL:(nullable NSString *)redirectURL
                     userAgent:(nullable NSString *)userAgent
                    asMemberId:(nullable NSString *)asMemberId
                      pathRoot:(nullable DBCOMMONPathRoot *)pathRoot
             additionalHeaders:(nullable NSDictionary<NSString *, NSString *> *)additionalHeaders
                 delegateQueue:(nullable NSOperationQueue *)delegateQueue
        forceForegroundSession:(BOOL)forceForegroundSession
     sharedContainerIdentifier:(nullable NSString *)sharedContainerIdentifier
			   keychainService:(nullable NSString *)keychainService;

@end

NS_ASSUME_NONNULL_END
