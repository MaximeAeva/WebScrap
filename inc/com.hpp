#ifndef COM_H
#define COM_H

#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>

#include <curl/curl.h>


struct MemoryStruct {
  char *memory;
  size_t size;
};

class Com{

    public:
        Com(std::string aStringName);
        ~Com();
        struct MemoryStruct file;

    private:
        CURL *curl;
        static size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, void *userp);
};

#endif