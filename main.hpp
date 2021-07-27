/*
** EPITECH PROJECT, 2021
** CPoolTek2
** File description:
** main
*/


#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <limits.h>
#include <vector>
#include <ctime>
#include "Modules/date.hpp"
#include "Modules/cpu.hpp"
#include "Modules/infos.hpp"
#include "Modules/net.hpp"
#include "Modules/ram.hpp"
#include "Interfaces/IMonitorModule.hpp"

#ifndef MAIN_HPP_
#define MAIN_HPP_


class Datas {
    public:
        Datas() {};
        ~Datas() {};
        void setDate(Date *date) {_date = date;}
        void setCpu(Cpu *cpu) {_cpu = cpu;}
        void setInfo(Infos *infos) {_infos = infos;}
        void setNet(Net *net) {_net = net;}
        void setRam(Ram *ram) {_ram = ram;}
        Date *_date;
        Cpu *_cpu;
        Infos *_infos;
        Net *_net;
        Ram *_ram;

    protected:
        

};



int start_sfml(Datas &our_datas);

#endif /* !MAIN_HPP_ */
