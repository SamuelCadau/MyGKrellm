/*
** EPITECH PROJECT, 2021
** CPP_Pool
** File description:
** ram
*/

#include "ram.hpp"

std::string Ram::getAvailableRam()
{
    std::ifstream ram("/proc/meminfo");
    std::string line_ram;
    std::string availableRam;
    while (getline(ram, line_ram)) {
        checkCpu("MemAvailable", line_ram.c_str(), availableRam);
    }
    return (availableRam);
}

std::string Ram::getFreeRam()
{
    std::ifstream ram("/proc/meminfo");
    std::string line_ram;
    std::string availableRam;
    while (getline(ram, line_ram)) {
        checkCpu("MemFree", line_ram.c_str(), availableRam);
    }
    return (availableRam);
}

std::string Ram::getTotalRam()
{
    std::ifstream ram("/proc/meminfo");
    std::string line_ram;
    std::string availableRam;
    while (getline(ram, line_ram)) {
        checkCpu("MemTotal", line_ram.c_str(), availableRam);
    }
    return (availableRam);
}