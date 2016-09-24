// -*- mode: ObjC -*-

//  This file is part of class-dump, a utility for examining the Objective-C segment of Mach-O files.
//  Copyright (C) 1997-1998, 2000-2001, 2004-2015 Steve Nygard.

#import <Foundation/NSObject.h>

@class CDOCProperty;

@interface CDVisitorPropertyState : NSObject

- (instancetype)initWithProperties:(NSArray<CDOCProperty*> *)properties;

- (CDOCProperty *)propertyForAccessor:(NSString *)str;

- (BOOL)hasUsedProperty:(CDOCProperty *)property;
- (void)useProperty:(CDOCProperty *)property;

@property (nonatomic, readonly) NSArray<CDOCProperty*> *remainingProperties;

@end
