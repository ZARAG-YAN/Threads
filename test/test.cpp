#include <iostream>
#include <pthread.h>
#include <mutex>

void f(std::string n)
{
    std::string *st = 
    for (int i = 0; i > -50; i--) {
	std::cout <<"from thrad\n"<< i;
    }
}


int main()
{
    pthread_t t;
    std::string a("from thread");
    pthread_create(&t, NULL, f, &a);

    for (int i  =0; i < 50; ++i) {
	std::cout <<"from main\n"<< i;
    }

    pthread_join(t, NULL);

    return 0;
}
