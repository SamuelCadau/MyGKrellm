/*
** EPITECH PROJECT, 2021
** CPP_Pool
** File description:
** cpu
*/

#include "cpu.hpp"

Cpu::Cpu()
{
    _display = true;
}

bool checkCpu(const char * a, const char *b, std::string &str)
{
    int i = 0;
    std::string tmp;
    for (; b[i] != '\0'; i ++) {
        if (a[i] != b[i])
            break;
        else
            tmp.push_back(a[i]);
    }
    // std::cout << tmp << std::endl;
    std::string value;
    if (tmp == a) {
        for (; b[i] != ':'; i++);
        for (; b[i] != ' '; i++);
        for (; b[i] == ' '; i++);
        for (; b[i] != '\0'; i ++) {
            value.push_back(b[i]);
        }
        str = value;
        return (true);
    }
    else {
        return (false);
    }
}

void Cpu::setCpuInfo()
{
    //GET INFO CPU
    std::ifstream cpuinfo("/proc/cpuinfo");
    std::string line_2;
    std::string model_cpu;
    std::string cpuMhz;
    std::string cache;
    while (getline(cpuinfo, line_2))
    {
        checkCpu("model name", line_2.c_str(), model_cpu);
        checkCpu("cpu MHz", line_2.c_str(), cpuMhz);
        checkCpu("cache size", line_2.c_str(), cache);
    }
    _cache = cache;
    _cpuMhz = cpuMhz;
    _modelCpu = model_cpu;

}

std::vector<std::string> Cpu::getCore()
{
    std::vector<std::string> our_cpus;
    std::vector<std::string> results;

    std::ifstream stat("/proc/stat");
    std::string line;
    while (getline(stat, line))
    {
        if (line[0] == 'c' && line[1] == 'p' && line[2] == 'u')
            our_cpus.push_back(line);
    }
    for (std::string it : our_cpus) {
        std::vector<std::string> total;
        std::string temp;
        int i = 0, y = 0, w = 0;
        for (; it[i] != '\0'; i++, w++) {
            if (it[i] == ' ') {
                total.push_back(temp);
                temp = "";
                w = 0;
                continue;
            }
            temp.push_back(it[i]);
            if (it[i+1] == '\0') {
                total.push_back(temp);
            }
        }
        float t_total = atof(total[1].c_str()) + atof(total[2].c_str()) + atof(total[3].c_str()) + atof(total[4].c_str()) + atof(total[5].c_str()) + atof(total[6].c_str()) + atof(total[7].c_str()) + atof(total[8].c_str());
        float t_idle = atof(total[4].c_str()) + atof(total[5].c_str());
        float t_usage = t_total - t_idle;
        float cpu_prct = (t_usage/t_total) * 100;
        std::string cpu_value;
        cpu_value.append(total[0]);
        cpu_value.append(" ");
        cpu_value.append(std::to_string(cpu_prct));
        cpu_value.append(" %");
        results.push_back(cpu_value);
        //std::cout << t_total << " : " << t_idle << " : " << t_usage << " : " << cpu_prct << std::endl;
    }
    return (results);
}

float Cpu::getActivity()
{
    std::ifstream cpuactivity("/proc/loadavg");
    std::string line_act;
    float activity;
    getline(cpuactivity, line_act);
    std::string tmp;
    for (int i = 0; line_act[i] != ' '; i++) {
        tmp.push_back(line_act[i]);
    }
    activity = (100*(stof(tmp))/get_nprocs_conf());
    return (activity);

}