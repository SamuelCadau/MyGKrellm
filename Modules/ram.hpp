/*
** EPITECH PROJECT, 2021
** CPP_Pool
** File description:
** ram
*/

#ifndef RAM_HPP_
#define RAM_HPP_

#include "../Interfaces/IMonitorModule.hpp"
#include <string>
#include <fstream>
#include <iostream>

class Ram : public IMonitorModule{
    public:
        Ram() { _display = true;}
        virtual ~Ram() {}
        bool isDiplay() {return(_display);}
        std::string getFreeRam();
        std::string getTotalRam();
        std::string getAvailableRam();


    protected:
        std::string freeRam;
        std::string totalRam;
        std::string availableRam;
    private:
};

bool checkCpu(const char * a, const char *b, std::string &str);

#endif /* !RAM_HPP_ */