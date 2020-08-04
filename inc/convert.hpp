#ifndef CONVERT_H
#define CONVERT_H

#include <iostream>
#include <string>
#include <cstdio>
#include <cerrno>

#include <tidy/tidy.h>
#include <tidy/tidybuffio.h>

class Conv {

    public:
        Conv(const char *someHTMLString);
        ~Conv();
        char* getContent();
        void getDiagnostic();

    private:
        TidyBuffer output;
        TidyBuffer errbuf;
        TidyDoc tdoc;
        int rc;

};

#endif

