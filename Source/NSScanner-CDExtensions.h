// -*- mode: ObjC -*-

//  This file is part of class-dump, a utility for examining the Objective-C segment of Mach-O files.
//  Copyright (C) 1997-1998, 2000-2001, 2004-2015 Steve Nygard.

#import <Foundation/NSScanner.h>

@class NSCharacterSet;

@interface NSScanner (CDExtensions)

@property (class, readonly, retain) NSCharacterSet *cdOtherCharacterSet;
@property (class, readonly, retain) NSCharacterSet *cdIdentifierStartCharacterSet;
@property (class, readonly, retain) NSCharacterSet *cdIdentifierCharacterSet;
@property (class, readonly, retain) NSCharacterSet *cdTemplateTypeCharacterSet;

- (NSString *)peekCharacter;
- (unichar)peekChar;
- (BOOL)scanCharacter:(unichar *)value;
- (BOOL)scanCharacterFromSet:(NSCharacterSet *)set intoString:(NSString **)value;
- (BOOL)my_scanCharactersFromSet:(NSCharacterSet *)set intoString:(NSString **)value;

- (BOOL)scanIdentifierIntoString:(NSString **)stringPointer;

@end
