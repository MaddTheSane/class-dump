// -*- mode: ObjC -*-

//  This file is part of class-dump, a utility for examining the Objective-C segment of Mach-O files.
//  Copyright (C) 1997-1998, 2000-2001, 2004-2015 Steve Nygard.

#import "CDFile.h"

#include <mach/machine.h> // For cpu_type_t, cpu_subtype_t
#include <mach-o/loader.h>

typedef NS_ENUM(NSUInteger, CDByteOrder) {
    CDByteOrder_LittleEndian = 0,
    CDByteOrder_BigEndian = 1,
};

@class CDLCSegment;
@class CDLCDyldInfo, CDLCDylib, CDMachOFile, CDLCSymbolTable, CDLCDynamicSymbolTable, CDLCVersionMinimum, CDLCSourceVersion, CDLoadCommand, CDLCRunPath, CDLCDylinker;

@interface CDMachOFile : CDFile

@property (readonly) CDByteOrder byteOrder;

@property (readonly) uint32_t magic;
@property (assign) cpu_type_t cputype;
@property (assign) cpu_subtype_t cpusubtype;
@property (readonly) uint32_t filetype;
@property (readonly) uint32_t flags;

@property (nonatomic, readonly) cpu_type_t maskedCPUType;
@property (nonatomic, readonly) cpu_subtype_t maskedCPUSubtype;

@property (readonly, copy) NSArray<__kindof CDLoadCommand *> *loadCommands;
@property (readonly, copy) NSArray<CDLCDylib*> *dylibLoadCommands;
@property (readonly, copy) NSArray<CDLCSegment*> *segments;
@property (readonly, copy) NSArray<NSString*> *runPaths;
@property (readonly, copy) NSArray<CDLCRunPath*> *runPathCommands;
@property (readonly, copy) NSArray<CDLCDylinker*> *dyldEnvironment;
@property (readonly, copy) NSArray<CDLoadCommand*> *reExportedDylibs;

@property (strong) CDLCSymbolTable *symbolTable;
@property (strong) CDLCDynamicSymbolTable *dynamicSymbolTable;
@property (strong) CDLCDyldInfo *dyldInfo;
@property (strong) CDLCDylib *dylibIdentifier;
@property (strong) CDLCVersionMinimum *minVersionMacOSX;
@property (strong) CDLCVersionMinimum *minVersionIOS;
@property (strong) CDLCSourceVersion *sourceVersion;

@property (readonly) BOOL uses64BitABI;
@property (readonly) NSUInteger ptrSize;

@property (readonly, copy/*, nullable*/) NSString *filetypeDescription;
@property (readonly, copy/*, nonnull*/) NSString *flagDescription;

- (CDLCSegment *)dataConstSegment;
- (CDLCSegment *)segmentWithName:(NSString *)segmentName;
- (CDLCSegment *)segmentContainingAddress:(NSUInteger)address;
- (NSString *)stringAtAddress:(NSUInteger)address;

- (NSUInteger)dataOffsetForAddress:(NSUInteger)address;

@property (readonly) const void* bytes NS_RETURNS_INNER_POINTER;
- (const void *)bytesAtOffset:(NSUInteger)offset NS_RETURNS_INNER_POINTER;

@property (nonatomic, readonly, copy) NSString *importBaseName;

@property (nonatomic, readonly, getter=isEncrypted) BOOL encrypted;
@property (nonatomic, readonly) BOOL hasProtectedSegments;
@property (nonatomic, readonly) BOOL canDecryptAllSegments;

- (NSString *)loadCommandString:(BOOL)isVerbose;
- (NSString *)headerString:(BOOL)isVerbose;

@property (nonatomic, readonly, copy) NSUUID *UUID;
@property (nonatomic, readonly, copy) NSString *archName;

- (Class)processorClass;
- (void)logInfoForAddress:(NSUInteger)address;

- (NSString *)externalClassNameForAddress:(NSUInteger)address;
- (BOOL)hasRelocationEntryForAddress:(NSUInteger)address;

// Checks compressed dyld info on 10.6 or later.
- (BOOL)hasRelocationEntryForAddress2:(NSUInteger)address;
- (NSString *)externalClassNameForAddress2:(NSUInteger)address;

- (CDLCDylib *)dylibLoadCommandForLibraryOrdinal:(NSUInteger)ordinal;

@property (nonatomic, readonly) BOOL hasObjectiveC1Data;
@property (nonatomic, readonly) BOOL hasObjectiveC2Data;
@property (nonatomic, readonly) Class processorClass;

@end
