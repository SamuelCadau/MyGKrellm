/*
** EPITECH PROJECT, 2021
** CPP_Pool
** File description:
** cpu
*/

#ifndef CPU_HPP_
#define CPU_HPP_

#include "../Interfaces/IMonitorModule.hpp"
#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <sys/sysinfo.h>

class Cpu : public IMonitorModule{
    public:
        Cpu();
        virtual ~Cpu() {}
        void setCpuInfo();
        bool isDiplay() {return(_display);}
        std::vector<std::string> getCore();
        std::string getModel() {return _modelCpu;}
        std::string getCpuMhz() {return _cpuMhz;}
        std::string getCache() {return _cache;}
        float getActivity();

    protected:
        std::string _modelCpu;
        std::string _cpuMhz;
        std::string _cache;
    private:
};
bool checkCpu(const char * a, const char *b, std::string &str);

#endif /* !CPU_HPP_ */