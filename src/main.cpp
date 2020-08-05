#include <iostream>
#include <com.hpp>
#include <useless.hpp>
#include <convert.hpp>
#include <nav.hpp>

int main(int, char**) 
{
    std::string adress = getAdress();//Just let you think you are in charge of something
    std::vector<bool> opt = options();
    Com *html = new Com(adress);//Scream until someone answer
    Conv *xml = new Conv(html->getContent());//Try to decode a shell sound
    Nav *navigate = new Nav(xml->getContent(), opt[1]);//Totally nervous breakdown caused by pointer's world
    if(opt[0]) xml->getDiagnostic();//See it's not that bad (if you manage to get here)
    html->~Com();//And now ?
    xml->~Conv();//Bye !
}


