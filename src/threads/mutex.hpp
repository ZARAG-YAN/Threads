#ifndef THREADS_MUTEX_HPP
#define THREADS_MUTEX_HPP

#include <pthread.h>

/**
 * @file mutex.hpp
 * @brief Contains threads::mutex class declaration
 */

/// TODO
namespace threads
{
        /**
          @class mutex
          @brief abstract class incapsulating POSIX mutex functionality
          */
        class mutex;
}

class threads::mutex
{
public:
        /**
         * @brief Constructor
         */
        mutex();
        /**
         * @brief Destructor
         */
        virtual ~mutex();
private:
        pthread_mutex_t m_mutex;
};

#endif // THREADS_MUTEX_HPP
