// Module:  Log4CPLUS
// File:    appenderattachable.h
// Created: 6/2001
// Author:  Tad E. Smith
//
//
// Copyright (C) The Apache Software Foundation. All rights reserved.
//
// This software is published under the terms of the Apache Software
// License version 1.1, a copy of which has been included with this
// distribution in the LICENSE.APL file.
//

/** @file */

#ifndef _LOG4CPLUS_SPI_APPENDER_ATTACHABLE_HEADER_
#define _LOG4CPLUS_SPI_APPENDER_ATTACHABLE_HEADER_

#include <log4cplus/config.h>
#include <log4cplus/helpers/pointer.h>
#include <string>
#include <vector>

namespace log4cplus {
    // Forward Declarations
    class Appender;
    typedef helpers::SharedObjectPtr<Appender> SharedAppenderPtr;
    typedef std::vector<log4cplus::SharedAppenderPtr> SharedAppenderPtrList;

    namespace spi {

        /**
         * This Interface is for attaching Appenders to objects.
         */
        class AppenderAttachable {
        public:
          // Methods
            /**
             * Add an appender.
             */
            virtual void addAppender(SharedAppenderPtr newAppender) = 0;

            /**
             * Get all previously added appenders as an Enumeration.  
             */
            virtual SharedAppenderPtrList getAllAppenders() = 0;

            /**
             * Get an appender by name.
             */
            virtual SharedAppenderPtr getAppender(const std::string& name) = 0;

            /**
             * Remove all previously added appenders.
             */
            virtual void removeAllAppenders() = 0;

            /**
             * Remove the appender passed as parameter from the list of appenders.
             */
            virtual void removeAppender(SharedAppenderPtr appender) = 0;

            /**
             * Remove the appender with the name passed as parameter from the
             * list of appenders.  
             */
            virtual void removeAppender(const std::string& name) = 0;

          // Dtor
            virtual ~AppenderAttachable(){}
        };

    }; // end namespace spi
}; // end namespace log4cplus

#endif // _LOG4CPLUS_SPI_APPENDER_ATTACHABLE_HEADER_
