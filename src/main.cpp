#include <iostream>
#include <com.hpp>
#include <useless.hpp>
#include <convert.hpp>

int main(int, char**) 
{
    std::string adress = getAdress();
    Com *test = new Com(adress);
    std::cout << test->file.size << std::endl;
    html2xml(test->file.memory);
    test->~Com();
}


