/**
 * @file thread.hpp
 * @brief Contains prototype for thread class
 */
#ifndef THREAD_H
#define THREAD_H
//#include <pthread.h>

namespace th
{
    class thread;
}
/**
  @class thread
  @brief abstract class
 */
class th::thread
{
public:
        /**
         * @fn thread
         * @brief Constructor
         */
        thread();
        /**
         * @fn ~thread
         * @brief Destructor
         */
        virtual ~thread();
        /**
         * @fn run
         *@brief pure virtual function
         */
        virtual void run() = 0;
        /**
         * @fn create_thread
         * @brief creating thread
         */
        void create_thread();
        /** 
         * @fn join_thread
         * @brief joining thread
         */
        void join_thread();
private:
        /**
         * @fn entry_point
         * @brief for thread
         * @param obj
         * @brief connecting function to thread
         * */
        static void* entry_point(void* obj);
        pthread_t m_thread;
};

#endif
