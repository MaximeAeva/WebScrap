#include <iostream>
#include <com.hpp>

std::string uselessFunction()
{
    std::string s;
    std::cout << "Adress : ";
    std::cin >> s;
    std::cout << std::endl;
    return s;
}

int main(int, char**) 
{
    std::string adress = uselessFunction();
    Com *test = new Com(adress);
    std::cout << test->file.memory << std::endl;
    test->~Com();
}


