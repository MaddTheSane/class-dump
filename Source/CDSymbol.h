// -*- mode: ObjC -*-

//  This file is part of class-dump, a utility for examining the Objective-C segment of Mach-O files.
//  Copyright (C) 1997-1998, 2000-2001, 2004-2015 Steve Nygard.

#include <mach-o/nlist.h>

extern NSString *const ObjCClassSymbolPrefix;

@class CDMachOFile, CDSection, CDLCDylib;

@interface CDSymbol : NSObject

- (instancetype)initWithName:(NSString *)name machOFile:(CDMachOFile *)machOFile nlist32:(struct nlist)nlist32;
- (instancetype)initWithName:(NSString *)name machOFile:(CDMachOFile *)machOFile nlist64:(struct nlist_64)nlist64;

@property (nonatomic, readonly) uint64_t value;
@property (readonly) NSString *name;
@property (nonatomic, readonly) CDSection *section;
@property (nonatomic, readonly) CDLCDylib *dylibLoadCommand;

@property (nonatomic, readonly, getter=isExternal) BOOL external;
@property (nonatomic, readonly, getter=isPrivateExternal) BOOL privateExternal;
@property (nonatomic, readonly) NSUInteger stab;
@property (nonatomic, readonly) NSUInteger type;
@property (nonatomic, readonly, getter=isDefined) BOOL defined;
@property (nonatomic, readonly, getter=isAbsolute) BOOL absolute;
@property (nonatomic, readonly, getter=isInSection) BOOL inSection;
@property (nonatomic, readonly, getter=isPrebound) BOOL prebound;
@property (nonatomic, readonly, getter=isIndirect) BOOL indirect;
@property (nonatomic, readonly, getter=isCommon) BOOL common;
@property (nonatomic, readonly, getter=isInTextSection) BOOL inTextSection;
@property (nonatomic, readonly, getter=isInDataSection) BOOL inDataSection;
@property (nonatomic, readonly, getter=isInBssSection) BOOL inBssSection;
@property (nonatomic, readonly) NSUInteger referenceType;
@property (nonatomic, readonly) NSString *referenceTypeName;
@property (nonatomic, readonly) NSString *shortTypeDescription;
@property (nonatomic, readonly) NSString *longTypeDescription;

- (NSComparisonResult)compare:(CDSymbol *)other;
- (NSComparisonResult)compareByName:(CDSymbol *)other;

+ (NSString *)classNameFromSymbolName:(NSString *)symbolName;

@end
