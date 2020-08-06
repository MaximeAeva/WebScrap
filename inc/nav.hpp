#ifndef NAV_H
#define NAV_H

#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cerrno>

#include <rapidxml/rapidxml.hpp>

class Node {
    
    public:
        Node(std::string id, std::string name, Node *parent);
        ~Node();
        void appendAttr(std::string attr, std::string val);//add an attribute
        void appendData(std::string data);//add data
        std::string getId() {return this->id;};
        std::string getName() {return this->name;};
        std::vector<std::string> getAttr() {return this->attr;};
        std::vector<std::string> getVal() {return this->val;};

    private:
        std::string id; 
        std::string name; 
        std::vector<std::string> attr; 
        std::vector<std::string> val; 
        std::string data;
        Node *parent;
};

class MagicalWoodStick
{
    /**
     * @brief       Harry Potter's power to trap GoldenNuggets in a PokeBall with a name stamp on it.
     * 
     */
    public:
        MagicalWoodStick();
        ~MagicalWoodStick();
        void appendNode(std::string id, std::string name);//add a node to the list
        void closeNode();//close a node (this node can't be parent anymore)
        void skeleton();//What a bones amount
        Node* getLast();//Return the current opened Node
    private:
        std::vector<Node> content;
        std::vector<Node*> depList;
};

class Nav {
    /**
     * @brief       A class to navigate the soup
     * 
     */
    public:
        Nav(char* someXMLfile, MagicalWoodStick *wand, bool mode = 0);
        ~Nav();

    private:
        rapidxml::xml_node<> * root_node;
        void walk(const rapidxml::xml_node<>* node, MagicalWoodStick *wand, int indent = 0, bool mode = 0);

};


#endif