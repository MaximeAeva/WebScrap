#ifndef NAV_H
#define NAV_H

#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cerrno>

#include <rapidxml/rapidxml.hpp>

class Nav {

    public:
        Nav(char* someXMLfile);
        ~Nav();

};


#endif