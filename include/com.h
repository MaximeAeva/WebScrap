#ifndef COM_H
#define COM_H

#include <iostream>
#include <curl.h>
#include <string>

class Com{

    public:
        Com();
        ~Com();

};

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

#endif