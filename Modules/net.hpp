/*
** EPITECH PROJECT, 2021
** CPP_Pool
** File description:
** net
*/

#ifndef NET_HPP_
#define NET_HPP_

#include "../Interfaces/IMonitorModule.hpp"
#include <string>
#include <fstream>
#include <iostream>

class Net : public IMonitorModule{
    public:
        Net() { _display = true;}
        virtual ~Net() {}
        void setNet();
        bool isDiplay() {return(_display);}
        std::string getIP() {return (_ipAdress);}
        std::string getType() {return (_typeNet);}
        std::string getRx_Bytes();
        std::string getTx_Bytes();


    protected:
        std::string _ipAdress;
        std::string _typeNet;
    private:
};
bool checkCpu(const char * a, const char *b, std::string &str);

#endif /* !NET_HPP_ */