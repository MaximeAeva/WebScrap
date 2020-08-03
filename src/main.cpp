#include <iostream>
#include <com.hpp>


int main(int, char**) {
    std::string adress;
    std::cout << "Adress : ";
    std::cin >> adress;
    std::cout << std::endl;
    Com *test = new Com(adress);
    test->~Com();
}
