/*
** EPITECH PROJECT, 2021
** CPP_Pool
** File description:
** net
*/

#include "net.hpp"
#include <chrono>
#include <ctime>

time_t getTime()
{
    auto start = std::chrono::system_clock::now();
    auto end =  std::chrono::system_clock::now();

    std::chrono::duration<double> elapsed_seconds = end-start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
    return (end_time);
}

std::string checkIp(std::string s)
{
    std::string adress;
    for (int i = 0; s[i] != ' '; i ++) {
        adress.push_back(s[i]);
    }
    return (adress);
}

std::string checkNetType(std::string s)
{
    std::string NetType;
    int i = 0;
    for (; s[i] != ' '; i ++) {}
    for (; s[i] == ' '; i ++) {}
    for (; s[i] != ' '; i ++) {}
    for (; s[i] == ' '; i ++) {}
    for (; s[i] != ' '; i ++) {}
    for (; s[i] == ' '; i ++) {}
    for (; s[i] != ' '; i ++) {}
    for (; s[i] == ' '; i ++) {}
    for (; s[i] != ' '; i ++) {}
    for (; s[i] == ' '; i ++) {}
    for (; s[i] != '\0'; i++) {
        NetType.push_back(s[i]);
    }
    return (NetType);
}

void Net::setNet()
{
    std::ifstream net("/proc/net/arp");
    std::string line_net;
    std::string ipAdress;
    std::string NetAdress;
    while (getline(net, line_net)) {
        ipAdress = checkIp(line_net);
        NetAdress = checkNetType(line_net);
    }
    _ipAdress = ipAdress;
    _typeNet = NetAdress;
}

std::string Net::getRx_Bytes()
{
    static time_t turn = 0;
    static std::string line;
    static int res = 0;
    std::string line2;
    if (turn == 0) {
        std::ifstream finfo("/sys/class/net/" + _typeNet + "/statistics/rx_bytes");
        getline(finfo, line);
        turn = getTime();
    } else if (getTime() > turn + 1) {
        std::ifstream finfo2("/sys/class/net/" + _typeNet + "/statistics/rx_bytes");
        getline(finfo2,line2);
        turn = 0;
        res = (atoi(line2.c_str()) - atoi(line.c_str()));
    }
    // printf("RX BYTE : %i\n", res);
    return std::to_string(res);
}

std::string Net::getTx_Bytes()
{
    static time_t turn = 0;
    static std::string line;
    static int res = 0;
    std::string line2;
    if (turn == 0) {
        std::ifstream finfo("/sys/class/net/" + _typeNet + "/statistics/tx_bytes");
        getline(finfo, line);
        turn = getTime();
    } else if (getTime() > turn + 1) {
        std::ifstream finfo2("/sys/class/net/" + _typeNet + "/statistics/tx_bytes");
        getline(finfo2,line2);
        turn = 0;
        res = (atoi(line2.c_str()) - atoi(line.c_str()));
    }
    // printf("TX BYTE : %i\n", res);
    return std::to_string(res);
}