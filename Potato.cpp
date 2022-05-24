#include <iostream>
#include <time.h>
#include <stdio.h>
#include <string>
#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include <vector>
#include <fstream>
#include "Season.h"
#include "Crops.h"
#include "Potato.h"

//constructor for potato
Potato::Potato(int sys_time, sf::Vector2f pos) {
	//set time information
	timeGenerate = sys_time;

	//adjust the position of sprite
	pos.x = pos.x - 24;
	pos.y = pos.y - 35;
	sprite.setPosition(pos);

	//set attributes values for potato
	cost = 5;
	purchasePrice = 10;
	type = 1;
	}

//growth function for potato case
void Potato::growth() {
	//growth rate in different seasons, for potato

	//only grow if watered
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
	//change the textrue for specific stages
	switch (growrate / 10) {
	case 0: texture.loadFromFile("potato/potato1.png"); sprite.setTexture(texture); break;
	case 1: texture.loadFromFile("potato/potato2.png"); sprite.setTexture(texture); break;
	case 2: texture.loadFromFile("potato/potato3.png"); sprite.setTexture(texture); break;
	case 3: texture.loadFromFile("potato/potato4.png"); sprite.setTexture(texture); break;
	case 4: texture.loadFromFile("potato/potato5.png"); sprite.setTexture(texture); break;
	case 5: texture.loadFromFile("potato/potato6.png"); sprite.setTexture(texture); harvestable = true; break;
	}
}
