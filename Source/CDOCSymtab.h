// -*- mode: ObjC -*-

//  This file is part of class-dump, a utility for examining the Objective-C segment of Mach-O files.
//  Copyright (C) 1997-1998, 2000-2001, 2004-2015 Steve Nygard.

#import <Foundation/NSObject.h>

@class CDOCCategory, CDOCClass;

@interface CDOCSymtab : NSObject

@property (readonly) NSMutableArray<CDOCClass *> *classes;
- (void)addClass:(CDOCClass *)aClass;

@property (readonly) NSMutableArray<CDOCCategory *> *categories;
- (void)addCategory:(CDOCCategory *)category;

@end
