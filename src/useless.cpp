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
    if(var=='y') opt.push_back(1);
    else opt.push_back(0);
}

std::vector<bool> options()
{
    std::vector<bool> opt;
    choice("Diagnostic", opt);
    choice("Verbose", opt);
    choice("Display HTML version", opt);
    choice("Communication", opt);
    choice("Skeleton", opt);
    choice("Content", opt);
    return opt;
}

void progressBar(int percent, int wait)
{
    const char parts[] = {'[', ']', '=', '>'};
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 11);
    std::cout << percent << "%";
    SetConsoleTextAttribute(hConsole, 15);
    std::cout << "  " << parts[0];
    int i = 0;
    while(i<(percent))
    {
        std::cout << parts[2];
        i++;
    }
    i = 0;
    std::cout << parts[3];
    while(i<(100-percent-1))
    {
        std::cout << " ";
        i++;
    }
    std::cout << parts[1];
    if(percent-100)
    {
        std::cout << "\r";
        std::cout.flush();
    }
    else std::cout << std::endl;
    usleep(wait);
}