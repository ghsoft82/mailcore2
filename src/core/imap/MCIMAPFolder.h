#ifndef MAILCORE_MCIMAPFOLDER_H

#define MAILCORE_MCIMAPFOLDER_H

#include <MailCore/MCBaseTypes.h>
#include <MailCore/MCMessageConstants.h>

#ifdef __cplusplus

namespace mailcore {

    class IMAPFolderStatus;
    
    class MAILCORE_EXPORT IMAPFolder : public Object {
    public:
        IMAPFolder();
        virtual ~IMAPFolder();
        
        virtual void setPath(String * path);
        virtual String * path();
        
        virtual void setDelimiter(char delimiter);
        virtual char delimiter();
        
        virtual void setFlags(IMAPFolderFlag flags);
        virtual IMAPFolderFlag flags();

        virtual void setStatus(IMAPFolderStatus * status);
        virtual IMAPFolderStatus * status();
        
    public: // subclass behavior
        IMAPFolder(IMAPFolder * other);
        virtual Object * copy();
        virtual String * description();
        
    private:
        String * mPath;
        char mDelimiter;
        IMAPFolderFlag mFlags;
        IMAPFolderStatus * mStatus;
        void init();
    };
    
}

#endif

#endif
