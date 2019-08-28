//
//  MCIMAPCloseFolderOperation.h
//  mailcore2
//
//  Created by Ghaith Habash on 8/27/19.
//  Copyright (c) 2019 MailCore. All rights reserved.
//

#ifndef MAILCORE_MCIMAPCLOSEFOLDEROPERATION_H

#define MAILCORE_MCIMAPCLOSEFOLDEROPERATION_H

#include <MailCore/MCIMAPOperation.h>

#ifdef __cplusplus

namespace mailcore {
    
    class MAILCORE_EXPORT IMAPCloseFolderOperation : public IMAPOperation {
    public:
        IMAPCloseFolderOperation();
        virtual ~IMAPCloseFolderOperation();
        
    public: // subclass behavior
        virtual void main();
    };
    
}

#endif

#endif
