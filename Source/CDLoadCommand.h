// -*- mode: ObjC -*-

//  This file is part of class-dump, a utility for examining the Objective-C segment of Mach-O files.
//  Copyright (C) 1997-1998, 2000-2001, 2004-2015 Steve Nygard.

// Importing these here saves us from importing them in the implementation of every load command.
#include <mach-o/loader.h>
#import "CDMachOFileDataCursor.h"

@class CDMachOFile;

@interface CDLoadCommand : NSObject

+ (CDLoadCommand*)loadCommandWithDataCursor:(CDMachOFileDataCursor *)cursor NS_SWIFT_NAME(loadCommand(with:));

- (instancetype)initWithDataCursor:(CDMachOFileDataCursor *)cursor;

@property (readonly, copy) NSString *extraDescription;

@property (weak, readonly) CDMachOFile *machOFile;
@property (readonly) NSUInteger commandOffset;

@property (nonatomic, readonly) uint32_t cmd;
@property (nonatomic, readonly) uint32_t cmdsize;
@property (nonatomic, readonly) BOOL mustUnderstandToExecute;

@property (nonatomic, readonly, copy) NSString *commandName;

- (void)appendToString:(NSMutableString *)resultString verbose:(BOOL)isVerbose;

- (void)machOFileDidReadLoadCommands:(CDMachOFile *)machOFile;

@end
