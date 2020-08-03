#ifndef COM_H
#define COM_H

#include <iostream>
#include <string>

#include <curl/curl.h>


class Com{

    public:
        Com(std::string aStringName);
        ~Com();

    private:
        CURL *curl;
};

#endif