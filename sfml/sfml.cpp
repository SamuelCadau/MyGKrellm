/*
** EPITECH PROJECT, 2021
** CPP_Pool
** File description:
** sfml
*/

#include "sfml.hpp"

void create_menu(GKrellm &gk)
{
    sf::Vector2f bouton_vector;
    gk.info_bouton_texture.loadFromFile("src/sprite/infos_bouton_activate.png");
    sf::Sprite info(gk.info_bouton_texture);
    gk.info_bouton = info;
    bouton_vector.x = 120;
    bouton_vector.y = 20;
    gk.info_bouton.setPosition(bouton_vector);

    gk.date_bouton_texture.loadFromFile("src/sprite/date_bouton_activate.png");
    sf::Sprite date(gk.date_bouton_texture);
    gk.date_bouton = date;
    bouton_vector.x = 120 + (278 * 1 + 12);
    gk.date_bouton.setPosition(bouton_vector);

    gk.kernel_bouton_texture.loadFromFile("src/sprite/ram_activatefe.png");
    sf::Sprite kernel(gk.kernel_bouton_texture);
    gk.kernel_bouton = kernel;
    bouton_vector.x = 120 + (278 * 2 + 17);
    gk.kernel_bouton.setPosition(bouton_vector);

    gk.network_bouton_texture.loadFromFile("src/sprite/network_d.png");
    sf::Sprite network(gk.network_bouton_texture);
    gk.network_bouton = network;
    bouton_vector.x = 120 + (278 * 3 + 33);
    gk.network_bouton.setPosition(bouton_vector);

    gk.cpu_bouton_texture.loadFromFile("src/sprite/cpu.png");
    sf::Sprite cpu(gk.cpu_bouton_texture);
    gk.cpu_bouton = cpu;
    bouton_vector.x = 120 + (278 * 4 + 40);
    gk.cpu_bouton.setPosition(bouton_vector);

    gk.ram_bouton_texture.loadFromFile("src/sprite/ram_activatefe.png");
    sf::Sprite ram(gk.ram_bouton_texture);
    gk.ram_bouton = ram;
    bouton_vector.x = 50;
    bouton_vector.x = 980;
    gk.ram_bouton.setPosition(bouton_vector);
}

void create_info(GKrellm &gk)
{
    sf::Vector2f bouton_vector2;
    gk.info_texture.loadFromFile("src/sprite/infos.png");
    sf::Sprite tmp_info(gk.info_texture);
    gk.info = tmp_info;
    bouton_vector2.x = 50;
    bouton_vector2.y = 950;
    gk.info.setPosition(bouton_vector2);
}

void create_network(GKrellm &gk)
{
    sf::Vector2f bouton_vector;
    gk.network_texture.loadFromFile("src/sprite/network.png");
    sf::Sprite tmp_network(gk.network_texture);
    gk.network = tmp_network;
    bouton_vector.x = 1140;
    bouton_vector.y = 450;
    gk.network.setPosition(bouton_vector);
}

void create_date(GKrellm &gk)
{
    sf::Vector2f bouton_vector;
    gk.date_texture.loadFromFile("src/sprite/date.png");
    sf::Sprite tmp_date(gk.date_texture);
    gk.date = tmp_date;
    bouton_vector.x = 1140;
    bouton_vector.y = 145;
    gk.date.setPosition(bouton_vector);
}

void create_kernel(GKrellm &gk)
{
    sf::Vector2f bouton_vector;
    gk.kernel_texture.loadFromFile("src/sprite/kernel.png");
    sf::Sprite tmpkernel(gk.kernel_texture);
    gk.kernel = tmpkernel;
    bouton_vector.x = 1140;
    bouton_vector.y = 740;
    gk.kernel.setPosition(bouton_vector);
}

void create_ram(GKrellm &gk)
{
    sf::Vector2f bouton_vector;
    gk.ram_texture.loadFromFile("src/sprite/ram.png");
    sf::Sprite tmp_ram(gk.ram_texture);
    gk.ram = tmp_ram;
    bouton_vector.x = 1140;
    bouton_vector.y = 240;
    gk.ram.setPosition(bouton_vector);
}
void create_core(GKrellm &gk)
{
    sf::Vector2f bouton_vector;
    gk.core_texture.loadFromFile("src/sprite/core.png");
    sf::Sprite tmp_core(gk.core_texture);
    gk.core = tmp_core;
    bouton_vector.x = 50;
    bouton_vector.y = 150;
    gk.core.setPosition(bouton_vector);
}
int createBackground(GKrellm &gk)
{
    if (!gk.background_texture.loadFromFile("src/sprite/background.png"))
        return EXIT_FAILURE;
    // gk.background(gk.background_texture);
    sf::Sprite sprite(gk.background_texture);
    gk.background = sprite;
}

void createVersion(GKrellm &gk)
{
    sf::Vector2f bouton_vector;
    gk.version_texture.loadFromFile("src/sprite/version.png");
    sf::Sprite tmp_core(gk.version_texture);
    gk.version = tmp_core;
    bouton_vector.x = 50;
    bouton_vector.y = 850;
    gk.version.setPosition(bouton_vector);
}

void info_text(GKrellm &gk, Datas &datas)
{

    //USERNAME
    sf::Text username(datas._infos->getUser(), gk.font, 25);
    sf::Vector2f username_vector(150, 970);
    username.setPosition(username_vector);
    gk.username = username;

    //HOSTNAME
    sf::Text hostname(datas._infos->getHost(), gk.font, 25);
    sf::Vector2f hostname_vector(330, 970);
    hostname.setPosition(hostname_vector);
    gk.hostname = hostname;

    //KERNEL
    sf::Text kernel(datas._infos->getKernel(), gk.font, 15);
    sf::Vector2f kernel_vector(20, 60);
    kernel.setPosition(kernel_vector);
    gk.kernel_text = kernel;

    //RAM TOT
    int rampp  = atoi((datas._ram->getTotalRam().c_str()));
    rampp = rampp / (1000*1000);
    sf::Text ramTotal(std::to_string(rampp), gk.font, 50);
    sf::Vector2f ramTotal_vector(1680, 290);
    ramTotal.setPosition(ramTotal_vector);
    gk.ramTotal = ramTotal;

    //ModelCPU
    sf::Text modelCPU(datas._cpu->getModel(), gk.font, 30);
    sf::Vector2f modelCPU_vector(1170, 840);
    modelCPU.setPosition(modelCPU_vector);
    gk.modelCPU = modelCPU;

    //CpuMhz
    sf::Text cpuMhz(datas._cpu->getCpuMhz(), gk.font, 30);
    sf::Vector2f cpuMhz_vector(1170, 910);
    cpuMhz.setPosition(cpuMhz_vector);
    gk.cpuMhz = cpuMhz;

    //Kernel
    sf::Text kernelaff(datas._infos->getKernel(), gk.font, 30);
    sf::Vector2f kernelaff_vector(1170, 770);
    kernelaff.setPosition(kernelaff_vector);
    gk.kernelaff = kernelaff;

    //CPU Cache
    sf::Text cpuCache(datas._cpu->getCache(), gk.font, 30);
    sf::Vector2f cpuCache_vector(1170, 970);
    cpuCache.setPosition(cpuCache_vector);
    gk.cpuCache = cpuCache;

    //IP
    sf::Text IP(datas._net->getIP(), gk.font, 30);
    sf::Vector2f IP_vector(1630, 600);
    IP.setPosition(IP_vector);
    gk.IP = IP;

    //NetType
    sf::Text NetType(datas._net->getType(), gk.font, 30);
    sf::Vector2f NetType_vector(1240, 600);
    NetType.setPosition(NetType_vector);
    gk.NetType = NetType;
}

int start_sfml(Datas &datas)
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(1980, 1080), "MyGKrellm");
    // Load a sprite to display
    // Create a graphical text to display
    GKrellm gk;
    // sf::Font font;
    createBackground(gk);
    create_menu(gk);
    create_core(gk);
    create_ram(gk);
    create_kernel(gk);
    create_date(gk);
    create_network(gk);
    create_info(gk);
    createVersion(gk);
    if (!gk.font.loadFromFile("src/arial.ttf"))
        return EXIT_FAILURE;

    info_text(gk, datas);


    std::ostringstream oss;
    oss << datas._cpu->getActivity();
    std::string result = oss.str();

    sf::Text activity(result, gk.font, 30);
    sf::Vector2f activity_vector(20, 100);
    activity.setPosition(activity_vector);

    sf::Text iPadress(datas._net->getIP(), gk.font, 30);
    sf::Vector2f iPadress_vector(20, 700);
    iPadress.setPosition(iPadress_vector);

    sf::Text NetType(datas._net->getType(), gk.font, 30);
    sf::Vector2f NetType_vector(600, 700);
    NetType.setPosition(NetType_vector);

    while (window.isOpen())
    {

        sf::Text rx_bits(datas._net->getRx_Bytes().append(" bits/s"), gk.font, 40);
        sf::Vector2f rx_bits_vector(1300, 500);
        rx_bits.setPosition(rx_bits_vector);

        sf::Text tx_bits(datas._net->getTx_Bytes().append(" bits/s"), gk.font, 40);
        sf::Vector2f tx_bits_vector(1630, 500);
        tx_bits.setPosition(tx_bits_vector);

        sf::Text ramFree(datas._ram->getFreeRam().append(" : MemFree"), gk.font, 20);
        sf::Vector2f ramFree_vector(1200, 340);
        ramFree.setPosition(ramFree_vector);

        sf::Text ramAvailable(datas._ram->getAvailableRam().append(" : MemAvailable"), gk.font, 20);
        sf::Vector2f ramAvailable_vector(1200, 300);
        ramAvailable.setPosition(ramAvailable_vector);

        sf::Text versionText(datas._infos->getVersion(), gk.font, 20);
        sf::Vector2f versionText_vector(500, 875);
        versionText.setPosition(versionText_vector);

        sf::Text distributionText(datas._infos->getDistribution(), gk.font, 20);
        sf::Vector2f distributionText_vector(150, 875);
        distributionText.setPosition(distributionText_vector);

        std::vector<std::string> d = datas._cpu->getCore();
        int i = 0;

        datas._date->setDate();
        sf::Text date(datas._date->getDate(), gk.font, 40);
        sf::Vector2f date_vector(1260, 155);
        date.setPosition(date_vector);

        sf::Event event;
        while (window.pollEvent(event))

        {
            // Close window: exit
            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))
                window.close();
            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::E))
            {
                datas._date->_display = !datas._date->_display;
            }
            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::R))
            {
                datas._infos->_display = !datas._infos->_display;
            }
            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::T))
            {
                datas._cpu->_display = !datas._cpu->_display;
            }
            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Y))
            {
                datas._net->_display = !datas._net->_display;
            }
            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::U))
            {
                datas._ram->_display = !datas._ram->_display;
            }
        }
        // Clear screen
        window.clear();
        window.draw(gk.background);
        window.draw(gk.ram_bouton);
        window.draw(gk.network_bouton);
        window.draw(gk.cpu_bouton);
        window.draw(gk.kernel_bouton);
        window.draw(gk.date_bouton);
        window.draw(gk.info_bouton);
        // Draw the string
        if (datas._date->isDiplay() == true)
        {
            window.draw(gk.date);
            window.draw(date);
        }
        if (datas._infos->isDiplay() == true)
        {
            window.draw(gk.info);
            window.draw(gk.kernel);
            window.draw(gk.username);
            window.draw(gk.hostname);
            window.draw(gk.kernel);
            window.draw(gk.modelCPU);
            window.draw(gk.cpuMhz);
            window.draw(gk.kernelaff);
            window.draw(gk.cpuCache);
            window.draw(gk.version);
            window.draw(versionText);
            window.draw(distributionText);
        }
        if (datas._cpu->isDiplay() == true)
        {
            int i = 0;
            for (std::string s : d) {
                if (i == d.size() / 2)
                    break;
                sf::Vector2f bouton_vector;
                sf::Text Aff(s, gk.font, 40);
                bouton_vector.x = 50;
                bouton_vector.y = 150 + (i*100);
                gk.core.setPosition(bouton_vector);
                Aff.setPosition(bouton_vector);
                window.draw(gk.core);
                i = i + 1;
            }
            i = 0;
            int r = 0;
            int o = 0;
            for (std::string s : d) {
                if (i == 0) {
                    i = i + 1;
                    continue;
                }
                sf::Vector2f bouton_vector;
                sf::Text Aff(s, gk.font, 40);
                if (i <= d.size() / 2) {
                    bouton_vector.x = 60;
                    bouton_vector.y = 160 + (o*100);
                    o ++;
                }
                else {
                    bouton_vector.x = 580;
                    bouton_vector.y = 160 + (r*100);
                    r = r + 1;
                }
                Aff.setPosition(bouton_vector);
                window.draw(Aff);
                i = i + 1;
            }

                // std::cout << s << std::endl;
        }
        if (datas._net->isDiplay() == true)
        {
            window.draw(gk.network);
            window.draw(rx_bits);
            window.draw(tx_bits);
            window.draw(gk.IP);
            window.draw(gk.NetType);
        }
        if (datas._ram->isDiplay() == true)
        {
            window.draw(gk.ram);
            window.draw(gk.ramTotal);
            window.draw(ramFree);
            window.draw(ramAvailable);

        }

        // window.draw(username);
        // window.draw(hostname);
        // window.draw(distribution);
        // window.draw(version);
        // window.draw(core);
        // Update the window
        window.display();
    }
    return EXIT_SUCCESS;
}
