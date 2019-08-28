//
//  MCOIMAPFetchFoldersWithStatusOperation.h
//  mailcore2
//
//  Created by Ghaith Habash on 8/2/19.
//  Copyright (c) 2013 MailCore. All rights reserved.
//

#ifndef MAILCORE_MCOIMAPFETCHFOLDERSWITHSTATUSOPERATION_H

#define MAILCORE_MCOIMAPFETCHFOLDERSWITHSTATUSOPERATION_H

/** This class implements an operation to fetch a list of folders with status. */

#import <MailCore/MCOIMAPBaseOperation.h>

@class MCOIMAPFolder;

NS_ASSUME_NONNULL_BEGIN
@interface MCOIMAPFetchFoldersWithStatusOperation : MCOIMAPBaseOperation

/** 
 Starts the asynchronous fetch operation.

 @param completionBlock Called when the operation is finished.

 - On success `error` will be nil and `folders` will contain an array of MCOIMAPFolder with Status
 
 - On failure, `error` will be set with `MCOErrorDomain` as domain and an 
   error code available in `MCOConstants.h`, `folders` will be nil
*/
- (void) start:(void (^)(NSError * __nullable error, NSArray<MCOIMAPFolder *> * __nullable folders))completionBlock;

@end
NS_ASSUME_NONNULL_END

#endif
