#ifndef NAV_H
#define NAV_H

#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cerrno>

#include <rapidxml/rapidxml.hpp>

class MagicalWoodStick
{
    /**
     * @brief       Harry Potter's power to trap GoldenNuggets in a PokeBall with a name stamp on it.
     * 
     */
    public:
        MagicalWoodStick(int id, size_t i, char* const & n, std::vector<char*> const & a,
                        std::vector<char*> const & av, char* const & d):nodeSize_(i),
                                                        nodeName_(n),
                                                        nodeAttributes_(a),
                                                        nodeAttributesValues_(av){}
        size_t nodeSize() const{return nodeSize_;}
        std::string const & label() const{return nodeName_;}
    private:
        int id;
        size_t nodeSize_;
        char* nodeName_;
        std::vector<char*> nodeAttributes_;
        std::vector<char*> nodeAttributesValues_;
 
};

class Nav {
    /**
     * @brief       A class to navigate the soup
     * 
     */
    public:
        Nav(char* someXMLfile, bool mode = 0);
        ~Nav();

    private:
        void walk(const rapidxml::xml_node<>* node, int indent = 0, bool mode = 0);

};


#endif