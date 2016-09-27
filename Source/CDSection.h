// -*- mode: ObjC -*-

//  This file is part of class-dump, a utility for examining the Objective-C segment of Mach-O files.
//  Copyright (C) 1997-1998, 2000-2001, 2004-2015 Steve Nygard.

@class CDMachOFileDataCursor;
@class CDLCSegment;

@interface CDSection : NSObject

- (id)initWithDataCursor:(CDMachOFileDataCursor *)cursor segment:(CDLCSegment *)segment;

@property (weak, readonly) CDLCSegment *segment;

@property (nonatomic, readonly, copy) NSData *data;

@property (nonatomic, readonly, copy) NSString *segmentName;
@property (nonatomic, readonly, copy) NSString *sectionName;

@property (nonatomic, readonly) NSUInteger addr;
@property (nonatomic, readonly) NSUInteger size;

- (BOOL)containsAddress:(NSUInteger)address;
- (NSUInteger)fileOffsetForAddress:(NSUInteger)address;

@end
