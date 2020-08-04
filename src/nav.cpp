#include <nav.hpp>

Nav::Nav(char* someXMLfile)
{
    rapidxml::xml_document<> doc;
	rapidxml::xml_node<> * root_node;
    std::vector<char> buffer(*someXMLfile);
    std::cout << someXMLfile << std::endl;
    buffer.push_back('\0');
	doc.parse<0>(&buffer[0]);

	root_node = doc.first_node("pre"); 

    for (rapidxml::xml_node<> * a_node = root_node->first_node("span"); a_node; a_node = a_node->next_sibling())
	{
	    std::cout << a_node->value() << std::endl;
	}
}

Nav::~Nav()
{

}