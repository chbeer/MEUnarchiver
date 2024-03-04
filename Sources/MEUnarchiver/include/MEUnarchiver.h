//
// MEUnarchiver.h
//
// Created by Frank Illenberger on 13.03.15.
//
// Replacement for the NSUnarchiver which is only available as private API under iOS.
// We need it for importing documents of Merlin 2 which used NSArchiver for serializing values
// for durations, utilizations, budgets etc. For maximum compatibility, we should still prefer to
// to use the original NSArchiver under OS X.
// The implementation is loosely based on file format documented by the code found in typedstream.m inside objc-1.tar.gz of an old Darwin release
// http://ia700409.us.archive.org/zipview.php?zip=/12/items/ftp_nextstuff_info/nextstuff.info.2012.11.zip
// http://archive.org/download/ftp_nextstuff_info/nextstuff.info.2012.11.zip/nextstuff.info%2Fmirrors%2Fotto%2Fhtml%2Fpub%2FDarwin%2FPublicSource%2FDarwin%2Fobjc-1.tar.gz
 
#import <Foundation/Foundation.h>

@interface MEUnarchiver : NSCoder
 
- (id _Nullable)initForReadingWithData:(NSData * _Nonnull)data;
 
@property (nonatomic, readonly, copy)   NSData * _Nonnull data;
@property (nonatomic, readonly)         BOOL              isAtEnd;
 
// Uses NSArchiver under OS X and MEArchiver under iOS.
+ (id _Nullable) compatibilityUnarchiveObjectWithData:(NSData * _Nonnull)data
                                      decodeClassName:(NSString * _Nullable)archiveClassName
                                          asClassName:(NSString * _Nullable)className;

@end
