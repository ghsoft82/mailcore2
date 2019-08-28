//
//  MCOIMAPCloseFolderOperation.h
//  mailcore2
//
//  Created by Ghaith Habash on 8/27/19.
//  Copyright (c) 2019 MailCore. All rights reserved.
//

#ifndef MAILCORE_MCOIMAPCLOSEFOLDEROPERATION_H

#define MAILCORE_MCOIMAPCLOSEFOLDEROPERATION_H

#import <MailCore/MCOIMAPBaseOperation.h>

NS_ASSUME_NONNULL_BEGIN
/* The class is used to perform a No-Op operation. */
@interface MCOIMAPCloseFolderOperation : MCOIMAPBaseOperation

/**
 Starts the asynchronous operation.
 
 @param completionBlock Called when the operation is finished.
 
 - On success `error` will be nil
 
 - On failure, `error` will be set
 */

- (void) start:(void (^)(NSError * __nullable error))completionBlock;

@end
NS_ASSUME_NONNULL_END

#endif
