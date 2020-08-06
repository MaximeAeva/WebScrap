#include <useless.hpp>

std::string getAdress()
{
    std::string s;
    std::cout << "Adress : ";
    std::cin >> s;
    std::cout << std::endl;
    return s;
}

void choice(std::string name, std::vector<bool> &opt)
{
    char var;
    std::cout << name <<" ? (y/n) : ";
    std::cin >> var;
    switch(var)
    {
        case 'y':
            opt.push_back(1);
        break;
        case 'n':
            opt.push_back(0);
        break;
        default:
            opt.push_back(0);
        break;
    }
}

std::vector<bool> options()
{
    /**
     * @brief       Select options
     *      Diagnostic
     * 
     */
    std::vector<bool> opt;
    choice("Diagnostic", opt);
    choice("Verbose", opt);
    choice("HTML", opt);
    return opt;
}

