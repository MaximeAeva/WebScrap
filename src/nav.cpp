#include <nav.hpp>

std::string catchThis(size_t s, char *name)
{
    std::string buff;
    for(int i = 0; i<s; i++)
    {
        buff=buff+(name[i]);
    }
    return buff;
}

Node::Node(std::string id, std::string name, int parent = -1)
{
    /**
     * @brief       Lets split this page
     *                      _ _ _ _      
     *              _ - - '   //    ' - - _ 
     *          , '          //            ' ,
     *        /             //               |
     *                     //
     *                    //
     *                   // 
     *                  //
     *                 //  
     */
    this->id = id;
    this->name = name;
    this->attr = {};
    this->val = {};
    this->data = "";
    this->parent = parent;
}

void Node::appendAttr(std::string attr, std::string val)
{
    this->attr.push_back(attr);
    this->val.push_back(val);
}

void Node::appendData(std::string data)
{
    this->data = data;
}

Node::~Node()
{

}

MagicalWoodStick::MagicalWoodStick()
{
    this->content = {};
    this->depList = {};
}

void MagicalWoodStick::appendNode(std::string id, std::string name)
{
    if(this->depList.empty()) 
    {
        Node n(id, name);
        this->content.push_back(n);
        this->depList.push_back(-1);
        
    }
    else 
    {
        Node n(id, name, this->depList.back());
        this->content.push_back(n);
        this->depList.push_back(this->content.size()-1);
    }
}

int MagicalWoodStick::getLast()
{
    return this->depList.back();
}

void MagicalWoodStick::closeNode()
 {
     this->depList.pop_back();
 }

void MagicalWoodStick::skeleton()
{
    int end = this->content.size();
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    for(int i = 0; i < end; i++)
    {
        int color = 1;
        int father = this->content[i].getParent();
        while(father >= 0)
        {
            std::cout << "      ";
            father = this->content[father].getParent();
            color++;
        }
        SetConsoleTextAttribute(hConsole, color);
        std::cout << this->content[i].getName();
        std::cout << std::endl;
    }
    SetConsoleTextAttribute(hConsole, 15);
}

MagicalWoodStick::~MagicalWoodStick()
{
    for(int i = this->content.size(); i >=0 ; i--)
    {
        this->content[i].~Node();
        this->content.pop_back();
    }
}

Nav::Nav(char* someXMLfile, MagicalWoodStick *wand, int weight, bool mode)
{
    /**
     * @brief       Create a boat to sail this XML soup 
     * 
     */
    rapidxml::xml_document<> doc;
    int i = 0;
    std::vector<char> buffer;
    std::cout << "Parsing" << std::endl;
    progressBar(0, 0);
    while((*(someXMLfile+i)) != '\0')
    {
        buffer.push_back(*(someXMLfile+i));// Here are the pointer's mermaids ...
        i++;
        if(i/weight) progressBar(100*i/weight, 0);
    }
    buffer.push_back('\0');
    //There... an iceberg
    enum {
        PARSE_FLAGS = rapidxml::parse_non_destructive
    };
	doc.parse<PARSE_FLAGS>(const_cast<char*>(&buffer[0]));//Please, read https://fr.wikipedia.org/wiki/Titanic to know the end 

	root_node = doc.first_node(); 

    if(mode) std::cout << std::endl << "node: " << root_node;
    //But look ... If you die, you can't die again ;) !

    walk(root_node, wand, 0, mode);
    
    std::cout << std::endl;
}

Nav::~Nav()
{
    delete this->root_node;
    this->root_node = NULL;
}

void Nav::walk(const rapidxml::xml_node<>* node, MagicalWoodStick *wand, int indent, bool mode)
{
    const std::string ind = std::string(indent * 4, ' ');
    if(mode) std::cout << ind.c_str() << std::endl;

    const rapidxml::node_type t = node->type();
    switch(t) 
    {
        case rapidxml::node_element:
            {
                wand->appendNode(ind, catchThis(node->name_size(), node->name()));
                if(mode) std::cout << "Append " << wand->content[wand->getLast()].getName();
                if(mode) std::printf("<%.*s", node->name_size(), node->name());
                for(const rapidxml::xml_attribute<>* a = node->first_attribute()
                    ; a
                    ; a = a->next_attribute()
                ) {
                    //wand->content[wand->getLast()].appendAttr(catchThis(a->name_size(), a->name()), catchThis(a->value_size(), a->value()));
                    if(mode) std::printf(" %.*s", a->name_size(), a->name());
                    if(mode) std::printf("='%.*s'", a->value_size(), a->value());
                }
                if(mode) std::printf(">\n");

                for(const rapidxml::xml_node<>* n = node->first_node()
                    ; n
                    ; n = n->next_sibling()
                ) {
                    walk(n, wand, indent+1, mode);
                }
                if(mode) std::cout << "Close " << wand->content[wand->getLast()].getName();
                wand->closeNode();
                if(mode) std::printf("%s</%.*s>\n", ind.c_str(), node->name_size(), node->name());
            }
            break;

        case rapidxml::node_data:
            wand->content[wand->getLast()].appendData(catchThis(node->value_size(), node->value()));
            if(mode) std::printf("DATA:[%.*s]\n", node->value_size(), node->value());
            break;

        default:
            if(mode) std::printf("NODE-TYPE:%d\n", t);
            break;
    }
}



