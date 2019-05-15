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
