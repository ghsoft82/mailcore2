//
//  MCIMAPCloseFolderOperation.cpp
//  mailcore2
//
//  Created by Ghaith Habash on 8/27/19.
//  Copyright (c) 2019 MailCore. All rights reserved.
//

#include "MCIMAPCloseFolderOperation.h"

#include "MCIMAPSession.h"
#include "MCIMAPAsyncConnection.h"

using namespace mailcore;

IMAPCloseFolderOperation::IMAPCloseFolderOperation()
{
}

IMAPCloseFolderOperation::~IMAPCloseFolderOperation()
{
}

void IMAPCloseFolderOperation::main()
{
    ErrorCode error;
    session()->session()->closeFolder(&error);
    setError(error);
}
