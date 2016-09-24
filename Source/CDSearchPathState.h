// -*- mode: ObjC -*-

//  This file is part of class-dump, a utility for examining the Objective-C segment of Mach-O files.
//  Copyright (C) 1997-1998, 2000-2001, 2004-2015 Steve Nygard.

#import <Foundation/NSObject.h>

@interface CDSearchPathState : NSObject

@property (nonatomic, copy) NSString *executablePath;

- (void)pushSearchPaths:(NSArray<NSString*> *)searchPaths;
- (void)popSearchPaths;

- (NSArray<NSString*> *)searchPaths;

@end
