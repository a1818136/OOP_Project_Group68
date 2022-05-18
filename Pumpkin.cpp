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
#include "Crops.h"
#include "Pumpkin.h"
using namespace std;
using namespace sf;

Pumpkin::Pumpkin(int sys_time, sf::Vector2f pos) {
		timeGenerate = sys_time;
		//adjust the position of sprite
		pos.x = pos.x - 24;
		pos.y = pos.y - 35;
		sprite.setPosition(pos);
		cost = 5;
		purchasePrice = 10;
	}

void Pumpkin::growth() {
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
		case 0: texture.loadFromFile("pumpkin/pumpkin1.png"); sprite.setTexture(texture); break;
		case 1: texture.loadFromFile("pumpkin/pumpkin2.png"); sprite.setTexture(texture); break;
		case 2: texture.loadFromFile("pumpkin/pumpkin3.png"); sprite.setTexture(texture); break;
		case 3: texture.loadFromFile("pumpkin/pumpkin4.png"); sprite.setTexture(texture); break;
		case 4: texture.loadFromFile("pumpkin/pumpkin5.png"); sprite.setTexture(texture); break;
		case 5: texture.loadFromFile("pumpkin/pumpkin6.png"); sprite.setTexture(texture); break;
		}
	}