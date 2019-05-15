//
//  MCOIMAPSortOperation.m
//  mailcore2
//
//  Created by Ghaith Habash on 4/17/19.
//  Copyright (c) 2019. All rights reserved.
//

#import "MCOIMAPSortOperation.h"

#include "MCAsyncIMAP.h"

#import "MCOOperation+Private.h"
#import "MCOUtils.h"
#import "MCOIndexSet.h"

typedef void (^CompletionType)(NSError *error, MCOIndexSet * sortResult);

@implementation MCOIMAPSortOperation
{
    CompletionType _completionBlock;
}

#define nativeType mailcore::IMAPSortOperation

+ (void) load
{
    MCORegisterClass(self, &typeid(nativeType));
}

+ (NSObject *) mco_objectWithMCObject:(mailcore::Object *)object
{
    nativeType * op = (nativeType *) object;
    return [[[self alloc] initWithMCOperation:op] autorelease];
}

- (void) deallocx
{
    [_completionBlock release];
    [super dealloc];
}

- (void) start:(void (^)(NSError *error, NSArray * sortResult))completionBlock
{
    _completionBlock = [completionBlock copy];
    [self start];
}

- (void) cancel
{
    [_completionBlock release];
    _completionBlock = nil;
    [super cancel];
}

- (void) operationCompleted
{
    if (_completionBlock == NULL)
        return;
    
    nativeType *op = MCO_NATIVE_INSTANCE;
    if (op->error() == mailcore::ErrorNone)
{
        _completionBlock(nil, MCO_TO_OBJC(op->uids()));
    } else
{
        _completionBlock([NSError mco_errorWithErrorCode:op->error()], nil);
    }
    [_completionBlock release];
    _completionBlock = nil;
}

@end
