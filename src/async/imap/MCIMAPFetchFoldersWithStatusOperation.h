//
//  MCIMAPFetchFoldersWithStatusOperation.h
//  mailcore2
//
//  Created by Ghaith Habash on 8/2/19.
//  Copyright (c) 2013 MailCore. All rights reserved.
//

#ifndef MAILCORE_MCIMAPFETCHFOLDERSWITHSTATUSOPERATION_H

#define MAILCORE_MCIMAPFETCHFOLDERSWITHSTATUSOPERATION_H

#include <MailCore/MCBaseTypes.h>
#include <MailCore/MCIMAPOperation.h>

#ifdef __cplusplus

namespace mailcore {
    
    class MAILCORE_EXPORT IMAPFetchFoldersWithStatusOperation : public IMAPOperation {
    public:
        IMAPFetchFoldersWithStatusOperation();
        virtual ~IMAPFetchFoldersWithStatusOperation();
        
        // Result.
        virtual Array * /* IMAPFolderWithStatus */ folders();
        
    public: // subclass behavior
        virtual void main();
        
    private:
        Array * mFolders;
        
    };
    
}

#endif

#endif
