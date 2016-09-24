// -*- mode: ObjC -*-

//  This file is part of class-dump, a utility for examining the Objective-C segment of Mach-O files.
//  Copyright (C) 1997-1998, 2000-2001, 2004-2015 Steve Nygard.

#import <Foundation/NSObject.h>

@class CDType, CDTypeLexer, CDMethodType;

extern NSString *CDExceptionName_SyntaxError;
extern NSString *CDErrorDomain_TypeParser;

extern NSString *CDErrorKey_Type;
extern NSString *CDErrorKey_RemainingString;
extern NSString *CDErrorKey_MethodOrVariable;
extern NSString *CDErrorKey_LocalizedLongDescription;

#define CDTypeParserCode_Default     0
#define CDTypeParserCode_SyntaxError 1

@interface CDTypeParser : NSObject

- (instancetype)initWithString:(NSString *)string;

@property (readonly) CDTypeLexer *lexer;

- (NSArray<CDMethodType*> *)parseMethodType:(NSError **)error;
- (CDType *)parseType:(NSError **)error;

@end
