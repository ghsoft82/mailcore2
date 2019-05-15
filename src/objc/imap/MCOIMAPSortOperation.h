//
//  MCOIMAPSortOperation.h
//  mailcore2
//
//  Created by Ghaith Habash on 4/17/19.
//  Copyright (c) 2019. All rights reserved.
//

#ifndef MAILCORE_MCOSORTOPERATION_H

#define MAILCORE_MCOSORTOPERATION_H

/** This class runs an IMAP sort operation */

#import <MailCore/MCOIMAPBaseOperation.h>

@class MCOIndexSet;

NS_ASSUME_NONNULL_BEGIN
@interface MCOIMAPSortOperation : MCOIMAPBaseOperation

/** 
 Starts the asynchronous sort operation.

 @param completionBlock Called when the operation is finished.

 - On success `error` will be nil and `sortResults` will contain the UIDs of returned messages
 
 - On failure, `error` will be set with `MCOErrorDomain` as domain and an 
   error code available in MCOConstants.h, `sortResult` will be nil
*/

- (void) start:(void (^)(NSError * __nullable error, NSArray * __nullable sortResult))completionBlock;

@end
NS_ASSUME_NONNULL_END

#endif
