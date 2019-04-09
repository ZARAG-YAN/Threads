#include "mutex.hpp"

#include <cassert>

threads::mutex::mutex()
        : m_mutex(PTHREAD_MUTEX_INITIALIZER)
{
         int r = pthread_mutex_init(&m_mutex, NULL);
         assert(0 == r);
         (void)r;
}

threads::mutex::~mutex()
{
        int r = pthread_mutex_destroy(&m_mutex);
        assert(0 == r);
        (void)r;
}

