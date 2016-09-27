// -*- mode: ObjC -*-

//  This file is part of class-dump, a utility for examining the Objective-C segment of Mach-O files.
//  Copyright (C) 1997-1998, 2000-2001, 2004-2015 Steve Nygard.

#include <mach/machine.h> // For cpu_type_t, cpu_subtype_t
#import <Foundation/NSObject.h>

NS_ASSUME_NONNULL_BEGIN

typedef struct CDArch {
    cpu_type_t cputype;
    cpu_subtype_t cpusubtype;
} CDArch;

@class CDMachOFile, CDSearchPathState;

NSString *CDImportNameForPath(NSString *path);
NSString *CDNameForCPUType(cpu_type_t cputype, cpu_subtype_t cpusubtype);
CDArch CDArchFromName(NSString *name);
BOOL CDArchUses64BitABI(CDArch arch);
BOOL CDArchUses64BitLibraries(CDArch arch);

@interface CDFile : NSObject

//! Returns CDFatFile or CDMachOFile
+ (nullable CDFile*)fileWithContentsOfFile:(NSString *)filename searchPathState:(nullable CDSearchPathState *)searchPathState NS_SWIFT_NAME(file(contentsOf:searchPathState:));

- (nullable instancetype)initWithData:(NSData *)data filename:(NSString *)filename searchPathState:(nullable CDSearchPathState *)searchPathState;

@property (readonly, copy) NSString *filename;
@property (readonly, copy) NSData *data;
@property (readonly, nullable, retain) CDSearchPathState *searchPathState;

- (BOOL)bestMatchForLocalArch:(CDArch *)oArchPtr;
- (BOOL)bestMatchForArch:(CDArch *)ioArchPtr;
- (nullable CDMachOFile *)machOFileWithArch:(CDArch)arch;

@property (nonatomic, readonly, copy) NSString *architectureNameDescription;

@end

NS_ASSUME_NONNULL_END
