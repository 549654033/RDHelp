// $Id: HTTP_ClientRequestHandler.h 90891 2010-06-28 09:55:39Z mcorino $

/**
 * @file HTTP_ClientRequestHandler.h
 *
 * @author Martin Corino <mcorino@remedy.nl>
 */

#ifndef ACE_HTTP_CLIENT_REQUEST_HANDLER_H
#define ACE_HTTP_CLIENT_REQUEST_HANDLER_H

#include /**/ "ace/pre.h"

#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Synch_Traits.h"
#include "ace/Thread_Mutex.h"
#include "ace/INet/INet_Export.h"
#include "ace/INet/IOS_util.h"
#include "ace/INet/StreamInterceptor.h"
#include "ace/INet/ClientRequestHandler.h"
#include "ace/INet/HTTP_Request.h"
#include "ace/INet/HTTP_Response.h"
#include "ace/INet/HTTP_Session.h"
#include "ace/INet/HTTP_URL.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

namespace ACE
  {
    namespace HTTP
      {
        /**
        * @class ACE_HTTP_ClientRequestHandler
        *
        * @brief This class implements clientside request handling
        *   for HTTP URLs.
        *
        * The class supports the HTTP protocol as specified in RFC 2616.
        */
        class ACE_INET_Export ClientRequestHandler
          : public ACE::INet::ClientINetRequestHandler,
            public ACE::IOS::StreamInterceptor
          {
            public:
              ClientRequestHandler ();
              virtual ~ClientRequestHandler ();

              virtual Request& request ();

              virtual const Request& request () const;

              virtual Response& response ();

              virtual const Response& response () const;

              std::ostream& request_stream ();

              virtual std::istream& response_stream ();

              virtual bool is_response_ok () const;

              virtual std::istream& handle_open_request (const ACE::INet::URL_Base& url);

              virtual std::istream& handle_get_request (const URL& url);
/*
              virtual std::istream& handle_post_request (const URL& url,
                                                         const PostData& post_data);

              virtual std::istream& handle_put_request (const URL& url,
                                                        std::istream* put_data = 0);
*/
            protected:
              virtual void on_eof ();

              class SessionHolder
                : public ACE::INet::ConnectionHolder
                {
                  public:
                    typedef Session_T<ACE_SYNCH> session_type;

                    SessionHolder ();
                    virtual ~SessionHolder();

                    session_type& operator *();
                    session_type* operator ->();

                  private:
                    session_type session_;
                };

              class SessionFactory
                : public ACE::INet::ConnectionFactory
                {
                  public:
                    SessionFactory ();
                    virtual ~SessionFactory ();

                    virtual ACE::INet::ConnectionHolder* create_connection (
                        const ACE::INet::ConnectionKey& key) const;
                };

              SessionHolder& session ();

              void session (SessionHolder* session);

              virtual bool initialize_connection (const ACE_CString& host,
                                                  u_short port);

              virtual void initialize_request (const URL& url, Request& request);

              virtual void handle_request_error (const URL& url);

              virtual void handle_connection_error (const URL& url);

              void release_connection ();

              void close_connection ();

            private:
              Request request_;
              Response response_;
              SessionHolder* session_;
          };

      }
  }

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/INet/HTTP_ClientRequestHandler.inl"
#endif

#include /**/ "ace/post.h"
#endif /* ACE_INET_CLIENT_REQUEST_HANDLER_H */
