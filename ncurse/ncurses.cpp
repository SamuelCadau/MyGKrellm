/*
** EPITECH PROJECT, 2021
** CPoolTek2
** File description:
** ncurses
*/

#include "ncurses.hpp"

void init_pairs()
{
    init_pair(1, COLOR_RED, 0);
    init_pair(2, COLOR_YELLOW, 0);
    init_pair(3, COLOR_CYAN, 0);
    init_pair(4, COLOR_GREEN, 0);
    init_pair(5, COLOR_MAGENTA, 0);
}

void moduleProc(Datas &data)
{
    int w, h;
    init_pairs();
    WINDOW *boite_2;
    getmaxyx(stdscr, h, w);
    boite_2 = subwin(stdscr, h/2, w/2, 1,0);
    attron(A_STANDOUT | COLOR_PAIR(1));
    mvprintw(2,1, "CPU Board");
    attroff(A_STANDOUT);
    mvprintw(4,1,"CPU Usage: %0.2f %\n", data._cpu->getActivity());
    mvprintw(5,1,"CPU Model: %s\n", data._cpu->getModel().c_str());
    mvprintw(6,1,"CPU Frequency: %s Mhz\n", data._cpu->getCpuMhz().c_str());
    mvprintw(7,1,"CPU Cache: %s KB\n", data._cpu->getCache().c_str());
    attroff(COLOR_PAIR(1));
    wattron(boite_2,COLOR_PAIR(1));
    box(boite_2, 0, 0); // utiliser des bordures de boites prédéfinies
    wattroff(boite_2,COLOR_PAIR(1));
    //wborder(boite, '/','\\','-','-','x','x','x','x');
}

void moduleCores(Datas &data)
{
    int w, h, pos_x = 4, pos_y = 1,nb = 1;
    std::vector<std::string> cores = data._cpu->getCore();
    std::vector<std::string>::iterator its;
    init_pairs();
    WINDOW *boite_2;
    getmaxyx(stdscr, h, w);
    boite_2 = subwin(stdscr, h/2-1, w/2, h/2+1,0);
    attron(A_STANDOUT | COLOR_PAIR(3));
    mvprintw(h/2+2,1, "Cores status");
    attroff(A_STANDOUT);
    for (its = cores.begin(); its != cores.end(); ++its) {
        if (pos_x == h/2) {
            pos_x = 4;
            pos_y = (*its).size()+1;
        }
        mvprintw(h/2+pos_x,pos_y,"%s\n", (*its).c_str());
        nb++;
        pos_x++;
    }
    attroff(COLOR_PAIR(3));
    wattron(boite_2,COLOR_PAIR(3));
    box(boite_2, 0, 0); // utiliser des bordures de boites prédéfinies
    wattroff(boite_2,COLOR_PAIR(3));
}

void moduleRam(Datas &data)
{
    // Note: utiliser mvwprintw permet une meilleur adaptabilité mais moins de personnalisation (et empêche l'évolution)
    int w, h;
    init_pairs();
    WINDOW *boite;
    getmaxyx(stdscr, h, w);
    boite = subwin(stdscr, h/2, w/2, 1,w/2);
    attron(A_STANDOUT | COLOR_PAIR(2));
    mvprintw(2, w/2+1,"Random Access Memory");
    attroff(A_STANDOUT);
    mvprintw(4, w/2+1,"Available RAM: %s\n", data._ram->getAvailableRam().c_str());
    mvprintw(5, w/2+1,"Free RAM: %s\n", data._ram->getFreeRam().c_str());
    mvprintw(6, w/2+1,"Total RAM: %s\n", data._ram->getTotalRam().c_str());
    attroff(COLOR_PAIR(2));
    wattron(boite,COLOR_PAIR(2));
    box(boite, 0, 0); // utiliser des bordures de boites prédéfinies
    wattroff(boite,COLOR_PAIR(2));
}

void moduleNet(Datas &data)
{
    int w, h;
    init_pairs();
    WINDOW *boite;
    getmaxyx(stdscr, h, w);
    boite = subwin(stdscr, h/2-1, w/2, h/2+1,w/2);
    attron(A_STANDOUT | COLOR_PAIR(4));
    mvprintw(h/2+2, w/2+1,"Network status");
    attroff(A_STANDOUT);
    mvprintw(h/2+4, w/2+1,"IP Address: %s\n", data._net->getIP().c_str());
    mvprintw(h/2+5, w/2+1,"Connection Type: %s\n", data._net->getType().c_str());
    mvprintw(h/2+7, w/2+1,"Rx & Tx Bytes:");
    mvprintw(h/2+8, w/2+16,"%s bytes/s\n", data._net->getRx_Bytes().c_str());
    mvprintw(h/2+9, w/2+16,"%s bytes/s\n", data._net->getTx_Bytes().c_str());
    attroff(COLOR_PAIR(4));
    wattron(boite,COLOR_PAIR(4));
    box(boite, 0, 0); // utiliser des bordures de boites prédéfinies
    wattroff(boite,COLOR_PAIR(4));
}

// void displates()
// {
//     init_pairs();
//     int width, height, size, i;
//     std::vector<int> b;
//     const char characters[] = {' ', '+', '#', '£'};
//     getmaxyx(stdscr, height, width);
//     size = width*height;
//     clear();
//     srand(time(NULL));

// }

void help()
{
    int w, h, key;
    initscr();
    noecho();
    start_color();
    curs_set(FALSE);
    while (1) {
        init_pairs();
        halfdelay(1);
        clear();
        WINDOW *boite;
        getmaxyx(stdscr, h, w);
        boite = subwin(stdscr, h/2+4, w/2, h/4,w/4);
        attron(A_STANDOUT | COLOR_PAIR(5));
        mvprintw(h/4+1, w/4+1,"Help");
        attroff(A_STANDOUT);
        mvprintw(h/4+3, w/4+1,"P : enable / disable CPU-related pannels.\n");
        mvprintw(h/4+5, w/4+1,"R : enable / disable RAM-related pannels.\n");
        mvprintw(h/4+7, w/4+1,"N : enable / disable Network-related pannels.\n");
        mvprintw(h/4+9, w/4+1,"W : exits the program.\n");
        mvprintw(h/4+12, w/4+1,"Press , again to exit.\n");
        // mvprintw(h/4+8, w/4+16,"%s bytes/s\n");
        // mvprintw(h/4+9, w/4+16,"%s bytes/s\n");
        attroff(COLOR_PAIR(5));
        wattron(boite,COLOR_PAIR(5));
        box(boite, 0, 0); // utiliser des bordures de boites prédéfinies
        wattroff(boite,COLOR_PAIR(5));
        key = getch();
        //key = getch();
        if (key == ',')
            break;
        if (key != 410) refresh();
        usleep(1000);
    }
}

void curses1(Datas &data)
{
    int key, h, w;
    initscr();
    noecho();
    start_color();
    curs_set(FALSE);
    while (1) {
        halfdelay(1);
        clear();
        getmaxyx(stdscr, h, w);
        data._date->setDate();
        attron(A_UNDERLINE | A_STANDOUT);
        mvprintw(0, w-(data._date->getDate().size()-1), data._date->getDate().c_str());
        attroff(A_UNDERLINE);
        mvprintw(0, 0, "Host: %s, User: ", data._infos->getHost().c_str());
        mvprintw(0, data._infos->getHost().size()+14, data._infos->getUser().c_str());
        mvprintw(0, data._infos->getHost().size()+14+data._infos->getUser().size(), " -- %s %s", data._infos->getDistribution().c_str(),data._infos->getVersion().c_str());
        mvprintw(0, w/2 - data._infos->getKernel().size()/2-10, "%s-- Press , for help", data._infos->getKernel().c_str());
        attroff(A_STANDOUT);
        if (data._cpu->isDiplay() == true) { moduleProc(data); }
        if (data._cpu->isDiplay() == true) { moduleCores(data); }
        if (data._ram->isDiplay() == true) { moduleRam(data); }
        if (data._net->isDiplay() == true) { moduleNet(data); }
        if (key == ',') help();
        if (key == 'p') { if(data._cpu->isDiplay() == true) { data._cpu->_display = false; } else { data._cpu->_display = true; } }
        if (key == 'r') { if(data._ram->isDiplay() == true) { data._ram->_display = false; } else { data._ram->_display = true; } }
        if (key == 'n') { if(data._net->isDiplay() == true) { data._net->_display = false; } else { data._net->_display = true; } }
        if (key == 'w')
            break;
        key = getch();
        //key = getch();
        if (key != 410) refresh();
        usleep(1000);
    }
    endwin();
}

void prep_curses(Datas &our_data)
{
    curses1(our_data);
}