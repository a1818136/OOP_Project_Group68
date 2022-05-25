#include <iostream>
#include <sstream>
#include <string>
#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include <time.h>
#include <stdio.h>
#include <variant>
#include "Potato.h"
#include "Carrot.h"
#include "Pumpkin.h"
#include "Season.h"
#include "tool.h"
#include "store.h"
#include "Words.h"
//for test, use "origincalss.h"
//#include "originclass.h"
using namespace sf;
using namespace std;

int main(){
    //Display help message
    cout << "/-----------------------------------------------------------------------------------------------\\" << endl;
    cout << "|   Keypressed     Function                                                                     |" << endl;
    cout << "|   Num 1          To select potato                                                             |" << endl;
    cout << "|   Num 2          To select carrot                                                             |" << endl;
    cout << "|   Num 3          To select pumpkin                                                            |" << endl;
    cout << "|   B              Buy the seed of the current crop                                             |" << endl;
    cout << "|   Q              Spray bottle, crops must be watered or they won't growth                     |" << endl;
    cout << "|   W              Hoe, Hoe is used to remove the crops                                         |" << endl;
    cout << "|   E              Sickle, sickle is used to harvest the crops                                  |" << endl;
    cout << "|   R              Fertiliser, select fertiliser and press B can buy the fertiliser             |" << endl;
    cout << "|   S              To save the Game,L to load the game, you can load only once in same window   |" << endl;
    cout << "|   L              To load the game, you can load only once in same window                      |" << endl;
    cout << "\\-----------------------------------------------------------------------------------------------/" << endl;
    //initialise the window
    RenderWindow window(sf::VideoMode(1024, 800), "Farm");
    window.setFramerateLimit(60);        //limits fram

    //instantiating objects
    tool tools;
    store store;
    
    bool flag_not_overlap = true;       //to check if the mouse position is overlap with any crop
    int key = 1;                        //number that indecats the current tool/crop
    int type;                           //overlap check 

    //initialise the season module
    Season currentSeason = Season::Spring;  
    int season_idicate = 1;
    int season_frame_count = 0;

    //initialise the time variables
    time_t timep;
    int initalTime = time(&timep);
    int CD_count_time = 20;
    int game_time;
    int game_count_time = 0;

    //initialise the inventory and money
    int money = 50;
    int inventory_potato = 0;
    int inventory_carrot = 0;
    int inventory_pumpkin = 0;
    int inventory_fertilizer = 0;

    //initialise bool variable for loading module
    bool load = true;

    //initialise the GUI
    Font font;
    if (!font.loadFromFile("Poppins-SemiBold.ttf"))
        throw("error");
    Words seasonText(font, 22, 505, 5);
    Words dayText(font, 22, 255, 5, "Day ");
    Words timeText(font, 22, 305, 5);
    Words moneyText(font, 22, 5, 5, "Money ");
    Words moneyvalueText(font, 22, 90, 5);
    Words toolText(font, 22, 725, 5, "Item ");
    Words curToolText(font, 22, 800, 5, "potato");

    //main loop
    while (window.isOpen()) {
        //counting frames for season change and click detection
        CD_count_time++;
        season_frame_count++;
        //refuresh the overlap detection
        flag_not_overlap = true;

        //window close
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
        }


        //load from file
        if (Keyboard::isKeyPressed(Keyboard::L) && load){
            cout << "main load" << endl;
            tools.functionLoad(&money, &inventory_potato, &inventory_carrot, &inventory_pumpkin, &inventory_fertilizer);
            load = false;
        }

        //updating the game time and money
        time_t timep;
        int currTime = time(&timep);
        stringstream sstime;
        stringstream ssmoney;
        string str_time;
        string str_money;
        game_time = currTime - initalTime;
        sstime << game_time;
        sstime >> str_time;
        timeText.text.setString(str_time);
        ssmoney << money;
        ssmoney >> str_money;
        moneyvalueText.text.setString(str_money);

        //change season
        if (season_frame_count % 900 == 0) {
            season_idicate++;
            if (season_idicate >= 5) {
                season_idicate = 1;
            }
            season_frame_count = 0;
        }
        switch (season_idicate) {
        case 1: currentSeason = Season::Spring; break;
        case 2: currentSeason = Season::Summer; break;
        case 3: currentSeason = Season::Autumn; break;
        case 4: currentSeason = Season::Winter; break;
        }

        //change the season text
        switch (currentSeason) {
        case Season::Spring: seasonText.text.setString("Spring"); break;
        case Season::Summer: seasonText.text.setString("Summer"); break;
        case Season::Autumn: seasonText.text.setString("Autumn"); break;
        case Season::Winter: seasonText.text.setString("Winter"); break;
        }

        //adjust the postion of objects to keep step with mouse
        tools.toolsprite.setPosition(Mouse::getPosition(window).x, Mouse::getPosition(window).y);

        //tool selection with different key pressed
        if (Keyboard::isKeyPressed(Keyboard::Num1)) {
            key = 1;
            curToolText.text.setString("potato");
        }
        if (Keyboard::isKeyPressed(Keyboard::Num2)) {
            key = 2;
            curToolText.text.setString("carrot");
        }
        if (Keyboard::isKeyPressed(Keyboard::Num3)) {
            key = 3;
            curToolText.text.setString("pumpkin");
        }
        if (Keyboard::isKeyPressed(Keyboard::Q)) {
            key = 11;
            curToolText.text.setString("spray bottle");
        }
        if (Keyboard::isKeyPressed(Keyboard::W)) {
            key = 12;
            curToolText.text.setString("hoe");
        }
        if (Keyboard::isKeyPressed(Keyboard::E)) {
            key = 13;
            curToolText.text.setString("sickle");
        }
        if (Keyboard::isKeyPressed(Keyboard::R)) {
            key = 14;
            curToolText.text.setString("fertiliser");
        }

        //change the texture for different tool
        tools.states(key);

        //store buying function with different key pressed
        if (Keyboard::isKeyPressed(Keyboard::B)) {
            if (key == 1 && CD_count_time >= 20) {
                store.buy(&inventory_potato, &money);
                CD_count_time = 0;
            }
            else if (key == 2 && CD_count_time >= 20) {
                store.buy(&inventory_carrot, &money);
                CD_count_time = 0;
            }
            else if (key == 3 && CD_count_time >= 20) {
                store.buy(&inventory_pumpkin, &money);
                CD_count_time = 0;
            }
            else if (key == 14 && CD_count_time >= 20) {
                store.buy(&inventory_fertilizer, &money);
                CD_count_time = 0;
            }
        }

        //implement of functions of tool
        if (Mouse::isButtonPressed(Mouse::Left)) {
            for (size_t i = 0; i < tools.crops.size(); i++) {
                //overlap detection
                if (tools.crops[i]._Storage()._Get().intsec(Mouse::getPosition(window))) {
                    //tool functions
                    type = 1;
                    tools.funnctions( key, i, &money, &inventory_fertilizer);
                    flag_not_overlap = false;
                    break;
                }
            }
            
            //generate crop
            if (flag_not_overlap) {
                tools.functionRake(key,currTime, tools.toolsprite.getPosition(), &inventory_potato, &inventory_carrot, &inventory_pumpkin);
            }
        }

        //save the game
        if (Keyboard::isKeyPressed(Keyboard::S)) {
            tools.functionSave(money,inventory_potato,inventory_carrot,inventory_pumpkin,inventory_fertilizer);
        }

        //clear the window
        window.clear();

        //updates and draw the state of crops
        for (int i = 0; i < tools.crops.size(); i++) {
            tools.crops[i]._Storage()._Get().states(currentSeason);
            tools.crops[i]._Storage()._Get().growth();
            window.draw(tools.crops[i]._Storage()._Get().sprite);
        }

        //draw the tools
        if (key == 11 || key == 12 || key == 13 || key == 14){
            window.draw(tools.toolsprite);
        }
       
        //draw on the screen
        window.draw(seasonText.text);
        window.draw(dayText.text);
        window.draw(timeText.text);
        window.draw(moneyText.text);
        window.draw(moneyvalueText.text);
        window.draw(toolText.text);
        window.draw(curToolText.text);
        window.display();
    }

    return 0;
}