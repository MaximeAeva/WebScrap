#include <iostream>
#include <com.hpp>
#include <useless.hpp>
#include <convert.hpp>
#include <nav.hpp>

int main(int, char**) 
{
    //Declaration part
    std::string adress = getAdress();//Just let you think you are in charge of something
    std::vector<bool> opt = options();

    //Do you know the way ??
    Com html(adress);//Scream until someone answer
    Conv xml(html.getContent());//Try to decode a shell sound
    MagicalWoodStick wand;
    Nav navigate(xml.getContent(), &wand, xml.getSize(), opt[1]);//Totally nervous breakdown caused by pointer's world
    
    //Please, be efficient and do not talk a lot
    //wand.skeleton();
    //wand.rawData();
    if(opt[2]) html.getContent();
    if(opt[0]) xml.getDiagnostic();//See it's not that bad (if you manage to get here)
    
    //Do not bother my conputer
    wand.~MagicalWoodStick();
    navigate.~Nav();
    xml.~Conv();
    html.~Com();//And now ?
    //Bye !
    
}


