#include <nav.hpp>

Nav::Nav(char* someXMLfile)
{
    /**
     * @brief       Create a boat to sail this XML soup 
     * 
     */
    rapidxml::xml_document<> doc;
	rapidxml::xml_node<> * root_node;
    int i = 0;
    std::vector<char> buffer;
    std::cout << "Parsing";
    while((*(someXMLfile+i)) != '\0')
    {
        buffer.push_back(*(someXMLfile+i));// Here are the pointer's mermaids ...
        if (!(i%1000)) {std::cout << " .";}
        i++;
    }
    buffer.push_back('\0');
    //There... an iceberg
    //std::cout << &buffer[0];
    enum {
        PARSE_FLAGS = rapidxml::parse_non_destructive
    };
	doc.parse<PARSE_FLAGS>(const_cast<char*>(&buffer[0]));//Please, read https://fr.wikipedia.org/wiki/Titanic to know the end 

	root_node = doc.first_node(); 

    std::cout << std::endl << "node: " << root_node;

    walk(root_node, 0);
    
    std::cout << std::endl;
}

Nav::~Nav()
{

}

void Nav::walk(const rapidxml::xml_node<>* node, int indent)
{
    const std::string ind = std::string(indent * 4, ' ');
    std::cout << ind.c_str() << std::endl;

    const rapidxml::node_type t = node->type();
    switch(t) 
    {
        case rapidxml::node_element:
            {
                std::printf("<%.*s", node->name_size(), node->name());
                for(const rapidxml::xml_attribute<>* a = node->first_attribute()
                    ; a
                    ; a = a->next_attribute()
                ) {
                    std::printf(" %.*s", a->name_size(), a->name());
                    std::printf("='%.*s'", a->value_size(), a->value());
                }
                std::printf(">\n");

                for(const rapidxml::xml_node<>* n = node->first_node()
                    ; n
                    ; n = n->next_sibling()
                ) {
                    walk(n, indent+1);
                }
                std::printf("%s</%.*s>\n", ind.c_str(), node->name_size(), node->name());
            }
            break;

        case rapidxml::node_data:
            std::printf("DATA:[%.*s]\n", node->value_size(), node->value());
            break;

        default:
            std::printf("NODE-TYPE:%d\n", t);
            break;
    }
}