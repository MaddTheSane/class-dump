// -*- mode: ObjC -*-

//  This file is part of class-dump, a utility for examining the Objective-C segment of Mach-O files.
//  Copyright (C) 1997-1998, 2000-2001, 2004-2015 Steve Nygard.

#import <Foundation/NSString.h>

@interface NSString (CDExtensions)

+ (NSString *)stringWithFileSystemRepresentation:(const char *)str;
+ (NSString *)spacesIndentedToLevel:(NSUInteger)level;
+ (NSString *)spacesIndentedToLevel:(NSUInteger)level spacesPerLevel:(NSUInteger)spacesPerLevel;
+ (NSString *)stringWithUnichar:(unichar)character;

@property (readonly, getter=isFirstLetterUppercase) BOOL firstLetterUppercase;
- (BOOL)isFirstLetterUppercase;

- (void)print;

@property (readonly, copy) NSString *executablePathForFilename;

- (NSString *)SHA1DigestString;

@property (readonly) BOOL hasUnderscoreCapitalPrefix;
@property (readonly, copy) NSString *capitalizeFirstCharacter;

@end

@interface NSMutableString (CDExtensions)

- (void)appendSpacesIndentedToLevel:(NSUInteger)level;
- (void)appendSpacesIndentedToLevel:(NSUInteger)level spacesPerLevel:(NSUInteger)spacesPerLevel;

@end
