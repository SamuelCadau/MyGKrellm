/*
** EPITECH PROJECT, 2021
** CPP_Pool
** File description:
** main
*/

#include "main.hpp"
#include "ncurse/ncurses.hpp"
#include <vector>
#include "stdlib.h"
#include "stdio.h"
#include <fstream>
#include <iostream>
#include <string>
#include <unistd.h>
#include <limits>
#include <cstring>
#include <sys/sysinfo.h>
#include "Modules/date.hpp"
#include "Modules/cpu.hpp"
#include "Modules/infos.hpp"
#include "Modules/net.hpp"
#include "Modules/ram.hpp"
#include "Interfaces/IMonitorModule.hpp"

int main(int ac, char **av)
{
    Datas datas;
    Date date;
    Cpu cpu;
    Infos infos;
    Net net;
    Ram ram;
    date.setDate();
    cpu.setCpuInfo();
    infos.setInfos();
    net.setNet();
    std::vector<std::string> e = cpu.getCore();
    infos.theRelease();
    datas.setCpu(&cpu);
    datas.setInfo(&infos);
    datas.setNet(&net);
    datas.setRam(&ram);
    datas.setDate(&date);

    if (ac == 1) {
        std::cout << date.getDate() << std::endl;
        std::cout << "Model CPU : "<<cpu.getModel()<< std::endl;
        std::cout << "Frequence de base : "<<cpu.getCpuMhz() << " MHz" << std::endl;
        std::cout << "Memoire cache : "<<cpu.getCache() << " KB" <<std::endl;
        std::cout << "Activity : " << cpu.getActivity() << " %"<< std::endl;
        std::cout << "User : "<< infos.getUser() << std::endl;
        std::cout << "Host : "<<infos.getHost() <<std::endl;
        std::cout << "Kernel : " << infos.getKernel() << std::endl;
        std::cout << "Ip Adress : "<< net.getIP() << std::endl;
        std::cout << "Net Type: "<< net.getType() <<std::endl;
        std::cout << "Rx_bytes : " <<net.getRx_Bytes() << " bits/s"<< std::endl;
        std::cout << "Tx_bytes : " <<net.getTx_Bytes() << " bits/s"<< std::endl;
        std::cout << "Ram Avail : " <<ram.getAvailableRam()<< std::endl;
        std::cout << "Ram Free : " <<ram.getFreeRam()<< std::endl;
        std::cout << "Ram Total : " <<ram.getTotalRam()<< std::endl;
        std::cout << "CPU ACTIVITY : " <<datas._cpu->getActivity()<< std::endl;
        std::cout << "DISTRIBUTION: " <<datas._infos->getDistribution()<< std::endl;
        std::cout << "VERSION : " <<datas._infos->getVersion()<< std::endl;
        for (std::string m : e)
            std::cout << m << std::endl;
        std::cout << "Usage:\n" << "./MyGKrellm [Interface]\n" << "[Interfaces]: -g (SFML)      -t (nCurses)" << std::endl;
        return 0;
    }
    if (av[1][0] == '-' && av[1][1] == 'g') {
        start_sfml(datas);
        return (0);
    } else if (av[1][0] == '-' && av[1][1] == 't') {
        prep_curses(datas);
        return 0;
    }

    // start_sfml(datas);
    // prep_curses(datas);
    return 0;
}