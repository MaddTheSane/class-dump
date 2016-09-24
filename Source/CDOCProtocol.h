// -*- mode: ObjC -*-

//  This file is part of class-dump, a utility for examining the Objective-C segment of Mach-O files.
//  Copyright (C) 1997-1998, 2000-2001, 2004-2015 Steve Nygard.

#import <Foundation/NSObject.h>

@class CDTypeController;
@class CDVisitor, CDVisitorPropertyState;
@class CDOCMethod, CDOCProperty;

@interface CDOCProtocol : NSObject

@property (strong) NSString *name;

@property (readonly) NSArray<CDOCProtocol *> *protocols;
- (void)addProtocol:(CDOCProtocol *)protocol;
- (void)removeProtocol:(CDOCProtocol *)protocol;
@property (nonatomic, readonly) NSArray *protocolNames;
@property (nonatomic, readonly) NSString *protocolsString;

@property (nonatomic, readonly) NSArray<CDOCMethod *> *classMethods; // TODO: NSArray vs. NSMutableArray
- (void)addClassMethod:(CDOCMethod *)method;

@property (nonatomic, readonly) NSArray<CDOCMethod *> *instanceMethods;
- (void)addInstanceMethod:(CDOCMethod *)method;

@property (nonatomic, readonly) NSArray<CDOCMethod *> *optionalClassMethods;
- (void)addOptionalClassMethod:(CDOCMethod *)method;

@property (nonatomic, readonly) NSArray<CDOCMethod *> *optionalInstanceMethods;
- (void)addOptionalInstanceMethod:(CDOCMethod *)method;

@property (nonatomic, readonly) NSArray<CDOCProperty *> *properties;
- (void)addProperty:(CDOCProperty *)property;

@property (nonatomic, readonly) BOOL hasMethods;

- (void)registerTypesWithObject:(CDTypeController *)typeController phase:(NSUInteger)phase;
- (void)registerTypesFromMethods:(NSArray<CDOCMethod *> *)methods withObject:(CDTypeController *)typeController phase:(NSUInteger)phase;

- (NSComparisonResult)ascendingCompareByName:(CDOCProtocol *)other;

@property (readonly, copy) NSString *methodSearchContext;
- (void)recursivelyVisit:(CDVisitor *)visitor;

- (void)visitMethods:(CDVisitor *)visitor propertyState:(CDVisitorPropertyState *)propertyState;

- (void)mergeMethodsFromProtocol:(CDOCProtocol *)other;
- (void)mergePropertiesFromProtocol:(CDOCProtocol *)other;

@end
