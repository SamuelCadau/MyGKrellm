/*
** EPITECH PROJECT, 2021
** CPP_Pool
** File description:
** infos
*/

#include "infos.hpp"

Infos::Infos()
{
    _display = true;
}

void Infos::theRelease()
{
    std::ifstream myRelease("/etc/os-release");
    std::string rel_line;
    std::vector<std::string> infos;
    while (getline(myRelease, rel_line))
    {
        infos.push_back(rel_line);
    }
    auto it = infos.begin();
    std::string name;
    std::string version;
    int p = 0;
    for (int i = 5; (*it)[i] != '\0'; i++) {
        name.push_back((*it)[i]);
    }
    this->_distribution = name;

    it++;
    for (int i = 8; (*it)[i] != '\0'; i++) {
        version.push_back((*it)[i]);
    }
    this->_version = version;
}

void Infos::setInfos()
{
    //SET KERNEL
    std::ifstream kernel("/proc/version");
    std::string kern_line;
    char c;
    while (kernel.get(c))
    {
        if (c == '(')
            break;
        kern_line.push_back(c);
    }
    _kernel = kern_line;

    //GET username && hostname
    char hostname[50];
    char username[50];
    gethostname(hostname, 50);
    getlogin_r(username, 50);
    _username = username;
    _hostname = hostname;
}