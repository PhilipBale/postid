//
//  PostidManager.h
//  Postid
//
//  Created by Philip Bale on 8/22/15.
//  Copyright (c) 2015 Philip Bale. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Realm/RLMRealm.h>
#import "User.h"
#import "Post.h"
#import "Notification.h"

@interface PostidManager : NSObject

typedef NS_ENUM(NSInteger, FriendGroup) {
    FriendGroupRequest,
    FriendGroupPending,
    FriendGroupFriends,
    FriendGroupPhone,
    FriendGroupUnknown
};

@property (nonatomic) NSInteger currentUserId;
@property (nonatomic, strong) NSData *lastImageData;

+ (PostidManager *)sharedManager;

- (void)logout;
- (void)saveTokenToKeychain:(NSString *)token;
- (NSString *)loadTokenFromKeychain;
- (void)saveMaxPostIdToKeychain:(NSNumber *)maxPostId;
- (NSNumber *)loadMaxPostIdFromKeychain;
- (RLMObject *)expressDefaultRealmWrite:(RLMObject *)object;

- (void)setCurrentUser:(User *)currentUser;
- (User *)currentUser;
- (User *)userFromCacheWithId:(NSInteger)userId;
- (void)cacheFriendsData:(NSDictionary *)dictionary;
- (void)uploadProfilePhoto:(NSData *)imageData completion:(void (^)(BOOL success, NSString *imageName))completion;

//- (Post *)postFromCacheWithId:(NSNumber *)postId;
//- (Post *)postFromCacheWithIntegerId:(NSInteger)postId;
//- (void)cachePosts:(NSArray *)posts;
- (void)makePostForUsers:(NSArray *)userIds withImageData:(NSData *)imageData completion:(void (^)(BOOL success))completion;

- (void)saveMaxNotificationIdToKeychain:(NSNumber *)maxNotificationId;
- (NSNumber *)loadMaxNotificationIdFromKeychain;
//- (void)cacheNotifications:(NSArray *)notifications;

- (void)downloadAndAddUser:(NSNumber *)userId toFriendGroup:(FriendGroup)group ofCurrentUser:(User *)currentUser;

@end
