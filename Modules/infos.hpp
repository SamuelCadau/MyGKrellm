/*
** EPITECH PROJECT, 2021
** CPP_Pool
** File description:
** infos
*/

#ifndef INFOS_HPP_
#define INFOS_HPP_

#include "../Interfaces/IMonitorModule.hpp"
#include <string>
#include <fstream>
#include <unistd.h>
#include <iostream>
#include <vector>

class Infos : public IMonitorModule{
    public:
        Infos();
        virtual ~Infos() {}
        void setInfos();
        bool isDiplay() {return(_display);}
        std::string getUser() {return _username;}
        std::string getHost() {return _hostname;}
        std::string getKernel() {return _kernel;}
        std::string getVersion() {return _version;}
        std::string getDistribution() {return _distribution;}
        void theRelease();

    protected:
        std::string _version;
        std::string _distribution;
        std::string _kernel;
        std::string _username;
        std::string _hostname;
    private:
};

#endif /* !INFOS_HPP_ */