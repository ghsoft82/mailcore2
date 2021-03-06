//
//  IMAPSortOperation.h
//  mailcore2
//
//  Created by Ghaith Habash on 4/17/19.
//  Copyright (c) 2019. All rights reserved.
//

#ifndef MAILCORE_MCIMAPSORTOPERATION_H

#define MAILCORE_MCIMAPSORTOPERATION_H

#include <MailCore/MCIMAPOperation.h>
#include <MailCore/MCMessageConstants.h>

#ifdef __cplusplus

namespace mailcore
{

    class IMAPSearchExpression;

    class MAILCORE_EXPORT IMAPSortOperation : public IMAPOperation
{
    public:
        IMAPSortOperation();
        virtual ~IMAPSortOperation();

        virtual void setIsESort(Boolean isESort);
        virtual Boolean isESort();

        virtual void setEsearchReturn(IMAPESearchReturn esearchReturn);
        virtual IMAPESearchReturn esearchReturn();

        virtual void setPartialLow(int partialLow);
        virtual int partialLow();

        virtual void setPartialHigh(int partialHigh);
        virtual int partialHigh();

        virtual void setSortKind(IMAPSortKind sortKind);
        virtual IMAPSortKind sortKind();

        virtual void setIsReverse(Boolean isReverse);
        virtual Boolean isReverse();

        virtual void setSearchKind(IMAPSearchKind searchKind);
        virtual IMAPSearchKind searchKind();

        virtual void setSearchString(String * searchString);
        virtual String * searchString();

        virtual void setSearchExpression(IMAPSearchExpression * searchExpression);
        virtual IMAPSearchExpression * searchExpression();

        // Result.
        virtual Array * uids();

    public: // subclass behavior
        virtual void main();

    private:
        Boolean mIsESort;
        IMAPESearchReturn mEsearchReturn;
        int mPartialLow;
        int mPartialHigh;
        IMAPSortKind mSortKind;
        Boolean mIsReverse;
        IMAPSearchKind mSearchKind;
        String * mSearchString;
        IMAPSearchExpression * mSearchExpression;
        Array * mUids;

    };
    
}

#endif

#endif
