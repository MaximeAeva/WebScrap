#ifndef COM_H
#define COM_H

#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <windows.h>

#include <curl/curl.h>
#include <useless.hpp>


struct MemoryStruct {
  char *memory;
  size_t size;
};

class Com{
  /**
   * @brief     Establish a communication with the desired adress and get HTML
   * 
   */
    public:
        Com(std::string aStringName, std::vector<bool> opt);
        ~Com();
        int getSize();
        char* getContent();

    private:
        struct MemoryStruct file;
        CURL *curl;
        static size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, void *userp);
        static int trace(CURL *handle, curl_infotype type,
             char *data, size_t size,
             void *userp);
        static void dump(const char *text,
          FILE *stream, unsigned char *ptr, size_t size, bool data = 0);

};

#endif