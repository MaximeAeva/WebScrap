#include <iostream>
#include <com.hpp>
#include <useless.hpp>
#include <convert.hpp>
#include <nav.hpp>

int main(int, char**) 
{
    std::string adress = getAdress();
    Com *html = new Com(adress);
    Conv *xml = new Conv(html->getContent());
    Nav *navigate = new Nav(xml->getContent());
    xml->getDiagnostic();
    html->~Com();
    xml->~Conv();
}


