/*
** EPITECH PROJECT, 2021
** CPP_Pool
** File description:
** sfml
*/

#ifndef SFML_HPP_
#define SFML_HPP_

#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <sstream>
#include "../main.hpp"

class GKrellm
{
public:
    sf::Font font;
    //BACKGROUND
    sf::Sprite background;
    sf::Texture background_texture;
    //BOUTONS
    sf::Sprite info_bouton;
    sf::Texture info_bouton_texture;
    sf::Sprite ram_bouton;
    sf::Texture ram_bouton_texture;
    sf::Sprite kernel_bouton;
    sf::Texture kernel_bouton_texture;
    sf::Sprite cpu_bouton;
    sf::Texture cpu_bouton_texture;
    sf::Sprite network_bouton;
    sf::Texture network_bouton_texture;
    sf::Sprite date_bouton;
    sf::Texture date_bouton_texture;
    sf::Sprite core_bouton;
    sf::Texture core_bouton_texture;
    //MODULE
    sf::Texture info_texture;
    sf::Sprite info;
    sf::Texture network_texture;
    sf::Sprite network;
    sf::Texture ram_texture;
    sf::Sprite ram;
    sf::Texture core_texture;
    sf::Sprite core;
    sf::Texture kernel_texture;
    sf::Sprite kernel;
    sf::Texture date_texture;
    sf::Sprite date;
    sf::Texture version_texture;
    sf::Sprite version;

    //MODULE TEXT
    sf::Text username;
    sf::Text hostname;
    sf::Text kernel_text;
    sf::Text ramTotal;
    sf::Text modelCPU;
    sf::Text cpuMhz;
    sf::Text kernelaff;
    sf::Text cpuCache;
    sf::Text IP;
    sf::Text NetType;


    //
};

#endif /* !SFML_HPP_ */