//
//  IMAPSortOperation.cc
//  mailcore2
//
//  Created by Ghaith Habash on 4/17/19.
//  Copyright (c) 2019. All rights reserved.
//

#include "MCIMAPSortOperation.h"

#include "MCIMAPSession.h"
#include "MCIMAPAsyncConnection.h"
#include "MCIMAPSearchExpression.h"

using namespace mailcore;

IMAPSortOperation::IMAPSortOperation()
{
    mSortKind = IMAPSortKindByArrival;
    mIsReverse = false;
    mSearchKind = IMAPSearchKindNone;
    mSearchString = NULL;
    mSearchExpression = NULL;
    mUids = NULL;
}

IMAPSortOperation::~IMAPSortOperation()
{
    MC_SAFE_RELEASE(mSearchString);
    MC_SAFE_RELEASE(mSearchExpression);
    MC_SAFE_RELEASE(mUids);
}

void IMAPSortOperation::setSortKind(IMAPSortKind sortKind)
{
    mSortKind = sortKind;
}

IMAPSortKind IMAPSortOperation::sortKind()
{
    return mSortKind;
}

void IMAPSortOperation::setIsReverse(Boolean isReverse)
{
    mIsReverse = isReverse;
}

Boolean IMAPSortOperation::isReverse()
{
    return mIsReverse;
}

void IMAPSortOperation::setSearchKind(IMAPSearchKind searchKind)
{
    mSearchKind = searchKind;
}

IMAPSearchKind IMAPSortOperation::searchKind()
{
    return mSearchKind;
}

void IMAPSortOperation::setSearchString(String * searchString)
{
    MC_SAFE_REPLACE_COPY(String, mSearchString, searchString);
}

String * IMAPSortOperation::searchString()
{
    return mSearchString;
}

void IMAPSortOperation::setSearchExpression(IMAPSearchExpression * searchExpression)
{
    MC_SAFE_REPLACE_RETAIN(IMAPSearchExpression, mSearchExpression, searchExpression);
}

IMAPSearchExpression * IMAPSortOperation::searchExpression()
{
    return mSearchExpression;
}

Array * IMAPSortOperation::uids()
{
    return mUids;
}

void IMAPSortOperation::main()
{
    ErrorCode error;
    if (mSearchExpression != NULL)
{
        mUids = session()->session()->sort(folder(), mSortKind, (int)mIsReverse, mSearchExpression, &error);
    }
    else
{
        mUids = session()->session()->sort(folder(), mSortKind, (int)mIsReverse, mSearchKind, mSearchString, &error);
    }
    MC_SAFE_RETAIN(mUids);
    setError(error);
}

