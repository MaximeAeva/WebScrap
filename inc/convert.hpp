#ifndef CONVERT_H
#define CONVERT_H

#include <iostream>
#include <string>
#include <cstdio>
#include <cerrno>

#include <tidy/tidy.h>
#include <tidy/tidybuffio.h>
#include <useless.hpp>

class Conv {
    /**
     * @brief       A class to convert pure HTML to XML 
     * 
     */
    public:
        Conv(const char *someHTMLString);
        ~Conv();
        char* getContent();
        void getDiagnostic();
        int getSize() {return this->output.size;};

    private:
        TidyBuffer output;
        TidyBuffer errbuf;
        TidyDoc tdoc;
        int rc;

};

#endif

