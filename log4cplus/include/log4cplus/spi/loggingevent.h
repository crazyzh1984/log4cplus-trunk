// Module:  Log4CPLUS
// File:    loggingevent.h
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

#ifndef _LOG4CPLUS_SPI_INTERNAL_LOGGING_EVENT_HEADER_
#define _LOG4CPLUS_SPI_INTERNAL_LOGGING_EVENT_HEADER_

#include <log4cplus/config.h>
#include <log4cplus/category.h>
#include <log4cplus/ndc.h>
#include <string>
#include <time.h>

namespace log4cplus {
    namespace spi {
        /**
         * The internal representation of logging events. When an affirmative
         * decision is made to log then a <code>InternalLoggingEvent</code> 
         * instance is created. This instance is passed around to the 
         * different log4cplus components.
         *
         * <p>This class is of concern to those wishing to extend log4cplus. 
         */
        struct InternalLoggingEvent {
          // Ctors
             /**
              * Instantiate a LoggingEvent from the supplied parameters.
              *           
              * <p>Except {@link #timeStamp} all the other fields of
              * <code>LoggingEvent</code> are filled when actually needed.
              * <p>
              * @param category The category of this event.
              * @param priority The priority of this event.
              * @param message  The message of this event.
              */
             InternalLoggingEvent(const std::string& category,
                                  const Priority& priority,
                                  const std::string& message,
                                  const char* file,
                                  int line)
              : categoryName(category),
                priority(priority),
                ndc(log4cplus::getNDC().get()),
                message(message),
                thread( LOG4CPLUS_GET_CURRENT_THREAD ),
                timestamp(time(NULL)),
                clock_ticks(clock()),
                file(file),
                line(line)
             {
             }


          // Data
            /** The category of the logging event. It is set by 
             * the LoggingEvent constructor. */
            const std::string categoryName;

            /** Priority of logging event. */
            const Priority priority;

            /** The nested diagnostic context (NDC) of logging event. */
            const std::string ndc;

            /** The application supplied message of logging event. */
            const std::string message;

            /** The name of thread in which this logging event was generated. */
            const LOG4CPLUS_THREAD_KEY_TYPE thread;

            /** The number of milliseconds elapsed from 1/1/1970 until logging event
             *  was created. */
            const time_t timestamp;

            /** The number of clock ticks since the program started running. */
            const clock_t clock_ticks;

            /** The is the file where this log statement was written */
            const char* file;

            /** The is the line where this log statement was written */
            int line;
        };

    }; // end namespace spi
}; // end namespace log4cplus

#endif // _LOG4CPLUS_SPI_INTERNAL_LOGGING_EVENT_HEADER_
