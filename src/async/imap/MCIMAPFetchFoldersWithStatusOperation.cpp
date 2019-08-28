//
//  MCIMAPFetchFoldersWithStatusOperation.cpp
//  mailcore2
//
//  Created by Ghaith Habash on 8/2/19.
//  Copyright (c) 2013 MailCore. All rights reserved.
//

#include "MCIMAPFetchFoldersWithStatusOperation.h"

#include <stdlib.h>

#include "MCIMAPSession.h"
#include "MCIMAPAsyncConnection.h"

using namespace mailcore;

IMAPFetchFoldersWithStatusOperation::IMAPFetchFoldersWithStatusOperation()
{
    mFolders = NULL;
}

IMAPFetchFoldersWithStatusOperation::~IMAPFetchFoldersWithStatusOperation()
{
    MC_SAFE_RELEASE(mFolders);
}

Array * IMAPFetchFoldersWithStatusOperation::folders()
{
    return mFolders;
}

void IMAPFetchFoldersWithStatusOperation::main()
{
    ErrorCode error;
    mFolders = session()->session()->fetchAllFoldersWithStatus(&error);

    MC_SAFE_RETAIN(mFolders);
    setError(error);
}
