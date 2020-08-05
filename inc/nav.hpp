#ifndef NAV_H
#define NAV_H

#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cerrno>

#include <rapidxml/rapidxml.hpp>

class Nav {
    /**
     * @brief       A class to navigate the soup
     * 
     */
    public:
        Nav(char* someXMLfile);
        ~Nav();

    private:
        void walk(const rapidxml::xml_node<>* node, int indent = 0);

};


#endif