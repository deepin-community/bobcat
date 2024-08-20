inline bool Milter::start()
{
    return smfi_main() == MI_SUCCESS;
}

inline void Milter::stop()
{
    smfi_stop();
}

inline std::string const &Milter::name()
{
    return s_name;
}

// protected:

inline bool Milter::addHeader(std::string const &hdrName,
                std::string const &hdrValue)
{
    return smfi_addheader(d_ctx,
                    const_cast<char *>(hdrName.c_str()),
                    const_cast<char *>(hdrValue.c_str()))
            == SUCCESS;
}
                            // from eom() only
                            // hdr-name: without :
                            // hdr-value: \n and \t ok.
inline bool Milter::addRecipient(std::string const &rcptName)
{
    return smfi_addrcpt(d_ctx,
            const_cast<char *>(rcptName.c_str())) == SUCCESS;
}

inline bool Milter::changeHeader(std::string const &hdrName,
                unsigned headerNr, std::string const &hdrValue)
{
    return smfi_chgheader(d_ctx,
                const_cast<char *>(hdrName.c_str()),
                headerNr,
                hdrValue.length() ?
                    const_cast<char *>(hdrValue.c_str())
                :
                    0
            ) == SUCCESS;
}

inline bool Milter::deleteRecipient(std::string const &rcptName)
{
    return smfi_delrcpt(d_ctx,
            const_cast<char *>(rcptName.c_str())) == SUCCESS;
}

inline SMFICTX *Milter::id() const
{
    return d_ctx;
}

inline bool Milter::insertHeader(size_t hdrIdx, std::string const &hdrName,
                  std::string const &hdrValue)
{
    return smfi_insheader(d_ctx, hdrIdx,
            const_cast<char *>(hdrName.c_str()),
            const_cast<char *>(hdrValue.c_str()));
}
inline bool Milter::openSocket(bool removeIfTrue)
{
    return smfi_opensocket(removeIfTrue) == SUCCESS;
}

inline bool Milter::quarantine(std::string const &reason)
{
    return  smfi_quarantine(d_ctx,
            const_cast<char *>(reason.c_str())) == SUCCESS;
}

inline bool Milter::replaceBody(std::string const &body)
{
    return smfi_replacebody(d_ctx,
                reinterpret_cast<unsigned char *>
                (
                    const_cast<char *>(body.c_str())
                ),
                body.length()) == SUCCESS;
}

inline bool Milter::setBacklog(size_t backlog)
{
    return smfi_setbacklog(backlog) == SUCCESS;
}

inline void Milter::setConnection(std::string const &socketName)
{
    smfi_setconn(const_cast<char *>(socketName.c_str()));
}

inline bool Milter::setReply(std::string const &rcode, 
                std::string const &xcode, std::string const &msg)
{
    return smfi_setreply(d_ctx,
                const_cast<char *>(rcode.c_str()),
                xcode.length() ?
                    const_cast<char *>(xcode.c_str())
                :
                    0,
                const_cast<char *>(msg.c_str()));

        // rcode: The three-digit (RFC 821/2821) SMTP reply code, as a
        // null-terminated string. rcode cannot be NULL, and must be a
        // valid 4XX or 5XX reply code.

        // xxcode The extended (RFC 1893/2034) reply code. If xcode is
        // NULL, no extended code is used. Otherwise, xcode must
        // conform to RFC 1893/2034.



        // * Values passed to smfi_setreply are not checked for
        // standards compliance.

        // * The message parameter should contain only printable
        // characters, other characters may lead to undefined
        // behavior. For example, CR or LF will cause the call to
        // fail, single '%' characters will cause the text to be
        // ignored (if there really should be a '%' in the string, use
        // '%%' just like for printf(3)).

        // * If the reply code (rcode) given is a '4XX' code but
        // SMFI_REJECT is used for the message, the custom reply is
        // not used.

        // * Similarly, if the reply code (rcode) given is a '5XX'
        // code but SMFI_TEMPFAIL is used for the message, the custom
        // reply is not used.

        // Note: in neither of the last two cases an error is returned
        // to the milter, libmilter silently ignores the reply code.

        // * If the milter returns SMFI_TEMPFAIL and sets the reply
        // code to '421', then the SMTP server will terminate the SMTP
        // session with a 421 error code.
}
// can't do smfi_setmlreply(ctx, ...)
// since there is no smfi_Vsetmlreply(ctx, ...)
inline void Milter::setTimeout(size_t seconds)
{
    smfi_settimeout(seconds);
}

inline char const *Milter::symval(std::string const &name) const
{
    return smfi_getsymval(d_ctx,
            const_cast<char *>(name.c_str()));
}

inline bool Milter::wait()                           // from eom() only
{
    return smfi_progress(d_ctx) == SUCCESS;
}
