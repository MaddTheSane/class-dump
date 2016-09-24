// -*- mode: ObjC -*-

//  This file is part of class-dump, a utility for examining the Objective-C segment of Mach-O files.
//  Copyright (C) 1997-1998, 2000-2001, 2004-2015 Steve Nygard.

#import "CDDataCursor.h"

@class CDMachOFile, CDSection;

@interface CDMachOFileDataCursor : CDDataCursor

- (instancetype)initWithFile:(CDMachOFile *)machOFile;
- (instancetype)initWithFile:(CDMachOFile *)machOFile offset:(NSUInteger)offset;
- (instancetype)initWithFile:(CDMachOFile *)machOFile address:(NSUInteger)address;

- (instancetype)initWithSection:(CDSection *)section;

@property (nonatomic, weak, readonly) CDMachOFile *machOFile;

- (void)setAddress:(NSUInteger)address;

// Read using the current byteOrder
- (uint16_t)readInt16;
- (uint32_t)readInt32;
- (uint64_t)readInt64;

- (uint32_t)peekInt32;

// Read using the current byteOrder and ptrSize (from the machOFile)
- (uint64_t)readPtr;

@end
