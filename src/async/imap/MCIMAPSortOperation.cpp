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
    mIsESort = false;
    mEsearchReturn = IMAPESearchReturnAll;
    mPartialLow = 0;
    mPartialHigh = 0;
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

void IMAPSortOperation::setIsESort(Boolean isESort)
{
    mIsESort = isESort;
}

Boolean IMAPSortOperation::isESort()
{
    return mIsESort;
}

void IMAPSortOperation::setEsearchReturn(IMAPESearchReturn esearchReturn)
{
    mEsearchReturn = esearchReturn;
}

IMAPESearchReturn IMAPSortOperation::esearchReturn()
{
    return mEsearchReturn;
}

void IMAPSortOperation::setPartialLow(int partialLow)
{
    mPartialLow = partialLow;
}

int IMAPSortOperation::partialLow()
{
    return mPartialLow;
}

void IMAPSortOperation::setPartialHigh(int partialHigh)
{
    mPartialHigh = partialHigh;
}

int IMAPSortOperation::partialHigh()
{
    return mPartialHigh;
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
    // DO ESORT
    if (mIsESort == true) {
        if (mSearchExpression != NULL)
        {
            mUids = session()->session()->esort(folder(), mEsearchReturn, mPartialLow, mPartialHigh, mSortKind, (int)mIsReverse, mSearchExpression, &error);
        }
        else
        {
            mUids = session()->session()->esort(folder(), mEsearchReturn, mPartialLow, mPartialHigh, mSortKind, (int)mIsReverse, mSearchKind, mSearchString, &error);
        }
    }
    else { // DO regular SORT
        if (mSearchExpression != NULL)
        {
            mUids = session()->session()->sort(folder(), mSortKind, (int)mIsReverse, mSearchExpression, &error);
        }
        else
        {
            mUids = session()->session()->sort(folder(), mSortKind, (int)mIsReverse, mSearchKind, mSearchString, &error);
        }
    }
    MC_SAFE_RETAIN(mUids);
    setError(error);
}

