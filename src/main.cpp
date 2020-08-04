#include <iostream>
#include <com.hpp>
#include <useless.hpp>
#include <convert.hpp>
#include <nav.hpp>

int main(int, char**) 
{
    std::string adress = getAdress();//Just let you think you are in charge of something
    Com *html = new Com(adress);//Scream until someone answer
    Conv *xml = new Conv(html->getContent());//Try to decode a shell sound
    Nav *navigate = new Nav(xml->getContent());//Totally nervous breakdown caused by pointer's world
    xml->getDiagnostic();//See it's not that bad (if you manage to be here)
    html->~Com();//And now ?
    xml->~Conv();//Bye !
}


