#include <iostream>
#include <time.h>
#include <process.h>
#include <stdio.h>
#include <string>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <vector>
#include <fstream>
#include "Season.h"
#include "Crops.h"
#include "Carrot.h"
using namespace std;
using namespace sf;
Carrot::Carrot(int sys_time, sf::Vector2f pos) {
		timeGenerate = sys_time;
		//adjust the position of sprite
		pos.x = pos.x - 24;
		pos.y = pos.y - 35;
		sprite.setPosition(pos);
		cost = 5;
		purchasePrice = 10;
	}

void Carrot::growth() {
		//diffrent growth rate in different season
		if (grow && watered) {
			switch (currentSeason) {
			case Season::Spring:
				growrate++;
				break;
			case Season::Summer:
				growrate++;
				break;
			case Season::Autumn:
				growrate++;
				break;
			case Season::Winter:
				growrate++;
				break;
			}
			grow = false;
		}

		//change the textrue
		switch (growrate / 10) {
		case 0: texture.loadFromFile("carrot/carrot1.png"); sprite.setTexture(texture); break;
		case 1: texture.loadFromFile("carrot/carrot2.png"); sprite.setTexture(texture); break;
		case 2: texture.loadFromFile("carrot/carrot3.png"); sprite.setTexture(texture); break;
		case 3: texture.loadFromFile("carrot/carrot4.png"); sprite.setTexture(texture); break;
		case 4: texture.loadFromFile("carrot/carrot5.png"); sprite.setTexture(texture); break;
		}
	}