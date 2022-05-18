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
#include "Potato.h"
Potato::Potato(int sys_time, sf::Vector2f pos) {
		timeGenerate = sys_time;
		//adjust the position of sprite
		pos.x = pos.x - 24;
		pos.y = pos.y - 35;
		sprite.setPosition(pos);
		cost = 5;
		purchasePrice = 10;
	}

void Potato::growth() {
		//diffrent growth rate in different season
		if (grow && watered) {
			switch (currentSeason) {
			case Season::Spring:
				growrate += 2;
				break;
			case Season::Summer:
				growrate++;
				break;
			case Season::Autumn:
				growrate += 2;
				break;
			case Season::Winter:
				growrate++;
				break;
			}
			grow = false;
		}
		//change the textrue
		switch (growrate / 10) {
		case 0: texture.loadFromFile("potato/potato1.png"); sprite.setTexture(texture); break;
		case 1: texture.loadFromFile("potato/potato2.png"); sprite.setTexture(texture); break;
		case 2: texture.loadFromFile("potato/potato3.png"); sprite.setTexture(texture); break;
		case 3: texture.loadFromFile("potato/potato4.png"); sprite.setTexture(texture); break;
		case 4: texture.loadFromFile("potato/potato5.png"); sprite.setTexture(texture); break;
		case 5: texture.loadFromFile("potato/potato6.png"); sprite.setTexture(texture); break;
		}
	}
