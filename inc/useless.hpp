#ifndef USELESS_H
#define USELESS_H

#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <unistd.h>

/**
 * @brief Get the Adress object
 * 
 * @return std::string 
 */
std::string getAdress();

/**
 * @brief  Select options (diagnostic, verbose, HTML, Communication, Skeleton, Content)
 * 
 * @return std::vector<bool> 
 */
std::vector<bool> options();

/**
 * @brief Progress bar are beautiful :D
 * 
 * @param percent 
 * @param wait 
 */
void progressBar(int percent, int wait = 100000);


#endif