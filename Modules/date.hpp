/*
** EPITECH PROJECT, 2021
** CPP_Pool
** File description:
** date
*/

#ifndef DATE_HPP_
#define DATE_HPP_

#include "../Interfaces/IMonitorModule.hpp"
#include <string>

class Date : public IMonitorModule{
    public:
        Date();
        virtual ~Date() {};
        void setDate();
        bool isDiplay() {return(_display);}
        std::string getDate() {return _date;}
    protected:
        std::string _date;
    private:
};

#endif /* !DATE_HPP_ */
