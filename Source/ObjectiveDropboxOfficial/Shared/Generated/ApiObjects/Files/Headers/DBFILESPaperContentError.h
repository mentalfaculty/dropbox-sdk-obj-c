///
/// Copyright (c) 2016 Dropbox, Inc. All rights reserved.
///
/// Auto-generated by Stone, do not modify.
///

#import <Foundation/Foundation.h>

#import "DBSerializableProtocol.h"

@class DBFILESPaperContentError;

NS_ASSUME_NONNULL_BEGIN

#pragma mark - API Object

///
/// The `PaperContentError` union.
///
/// This class implements the `DBSerializable` protocol (serialize and
/// deserialize instance methods), which is required for all Obj-C SDK API route
/// objects.
///
@interface DBFILESPaperContentError : NSObject <DBSerializable, NSCopying>

#pragma mark - Instance fields

/// The `DBFILESPaperContentErrorTag` enum type represents the possible tag
/// states with which the `DBFILESPaperContentError` union can exist.
typedef NS_CLOSED_ENUM(NSInteger, DBFILESPaperContentErrorTag){
    /// Your account does not have permissions to edit Paper docs.
    DBFILESPaperContentErrorInsufficientPermissions,

    /// The provided content was malformed and cannot be imported to Paper.
    DBFILESPaperContentErrorContentMalformed,

    /// The Paper doc would be too large, split the content into multiple docs.
    DBFILESPaperContentErrorDocLengthExceeded,

    /// The imported document contains an image that is too large. The current
    /// limit is 1MB. This only applies to HTML with data URI.
    DBFILESPaperContentErrorImageSizeExceeded,

    /// (no description).
    DBFILESPaperContentErrorOther,

};

/// Represents the union's current tag state.
@property (nonatomic, readonly) DBFILESPaperContentErrorTag tag;

#pragma mark - Constructors

///
/// Initializes union class with tag state of "insufficient_permissions".
///
/// Description of the "insufficient_permissions" tag state: Your account does
/// not have permissions to edit Paper docs.
///
/// @return An initialized instance.
///
- (instancetype)initWithInsufficientPermissions;

///
/// Initializes union class with tag state of "content_malformed".
///
/// Description of the "content_malformed" tag state: The provided content was
/// malformed and cannot be imported to Paper.
///
/// @return An initialized instance.
///
- (instancetype)initWithContentMalformed;

///
/// Initializes union class with tag state of "doc_length_exceeded".
///
/// Description of the "doc_length_exceeded" tag state: The Paper doc would be
/// too large, split the content into multiple docs.
///
/// @return An initialized instance.
///
- (instancetype)initWithDocLengthExceeded;

///
/// Initializes union class with tag state of "image_size_exceeded".
///
/// Description of the "image_size_exceeded" tag state: The imported document
/// contains an image that is too large. The current limit is 1MB. This only
/// applies to HTML with data URI.
///
/// @return An initialized instance.
///
- (instancetype)initWithImageSizeExceeded;

///
/// Initializes union class with tag state of "other".
///
/// @return An initialized instance.
///
- (instancetype)initWithOther;

- (instancetype)init NS_UNAVAILABLE;

#pragma mark - Tag state methods

///
/// Retrieves whether the union's current tag state has value
/// "insufficient_permissions".
///
/// @return Whether the union's current tag state has value
/// "insufficient_permissions".
///
- (BOOL)isInsufficientPermissions;

///
/// Retrieves whether the union's current tag state has value
/// "content_malformed".
///
/// @return Whether the union's current tag state has value "content_malformed".
///
- (BOOL)isContentMalformed;

///
/// Retrieves whether the union's current tag state has value
/// "doc_length_exceeded".
///
/// @return Whether the union's current tag state has value
/// "doc_length_exceeded".
///
- (BOOL)isDocLengthExceeded;

///
/// Retrieves whether the union's current tag state has value
/// "image_size_exceeded".
///
/// @return Whether the union's current tag state has value
/// "image_size_exceeded".
///
- (BOOL)isImageSizeExceeded;

///
/// Retrieves whether the union's current tag state has value "other".
///
/// @return Whether the union's current tag state has value "other".
///
- (BOOL)isOther;

///
/// Retrieves string value of union's current tag state.
///
/// @return A human-readable string representing the union's current tag state.
///
- (NSString *)tagName;

@end

#pragma mark - Serializer Object

///
/// The serialization class for the `DBFILESPaperContentError` union.
///
@interface DBFILESPaperContentErrorSerializer : NSObject

///
/// Serializes `DBFILESPaperContentError` instances.
///
/// @param instance An instance of the `DBFILESPaperContentError` API object.
///
/// @return A json-compatible dictionary representation of the
/// `DBFILESPaperContentError` API object.
///
+ (nullable NSDictionary<NSString *, id> *)serialize:(DBFILESPaperContentError *)instance;

///
/// Deserializes `DBFILESPaperContentError` instances.
///
/// @param dict A json-compatible dictionary representation of the
/// `DBFILESPaperContentError` API object.
///
/// @return An instantiation of the `DBFILESPaperContentError` object.
///
+ (DBFILESPaperContentError *)deserialize:(NSDictionary<NSString *, id> *)dict;

@end

NS_ASSUME_NONNULL_END