#include "thread.hpp"
#include <iostream>
#include <cassert>

////////////////////thread class////////////////////

th::thread::th::thread() : m_thread()
{}

th::thread::~th::thread()
{}

void th::thread::create_thread()
{
    pthread_attr_t attr;
    int r = pthread_attr_init(&attr);
    assert(0 == r);
    r = pthread_create(&m_thread, &attr, entry_point, (void*)this);
    assert(0 == r);
    r = pthread_attr_destroy(&attr);
    assert(0 == r);
    (void)r;
}

void th::thread::join_thread()
{
    int r = pthread_join(m_thread, 0);
    assert(0 == r);
    (void)r;
}

void* th::thread::entry_point(void* p)
{
    assert(0 != p);
    th::thread* t = reinterpret_cast<th::thread*>(p);
    assert(0 != t);
    t->run();
    return 0;
}
