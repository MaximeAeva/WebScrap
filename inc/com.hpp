#ifndef COM_H
#define COM_H

#include <iostream>
#include <string>

extern "C" {
#include <curl/curl.h>
}

class Com{

    public:
        Com();
        ~Com();
    
};

#endif