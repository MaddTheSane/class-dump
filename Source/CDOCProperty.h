// -*- mode: ObjC -*-

//  This file is part of class-dump, a utility for examining the Objective-C segment of Mach-O files.
//  Copyright (C) 1997-1998, 2000-2001, 2004-2015 Steve Nygard.

@class CDType;

@interface CDOCProperty : NSObject

- (instancetype)initWithName:(NSString *)name attributes:(NSString *)attributes;

@property (readonly, copy) NSString *name;
@property (readonly, copy) NSString *attributeString;
@property (readonly, copy) CDType *type;
@property (readonly, copy) NSArray *attributes;

@property (copy) NSString *attributeStringAfterType;

@property (nonatomic, readonly, copy) NSString *defaultGetter;
@property (nonatomic, readonly, copy) NSString *defaultSetter;

@property (copy) NSString *customGetter;
@property (copy) NSString *customSetter;

@property (nonatomic, readonly, copy) NSString *getter;
@property (nonatomic, readonly, copy) NSString *setter;

@property (readonly, getter=isReadOnly) BOOL readOnly;
@property (readonly, getter=isDynamic) BOOL dynamic;

- (NSComparisonResult)ascendingCompareByName:(CDOCProperty *)other;

@end
