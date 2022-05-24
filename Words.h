#pragma once
#ifndef WORDS_H
#define WORDS_H
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
#include "Carrot.h"
#include "Pumpkin.h"
#include "tool.h"
using namespace std;
using namespace sf;

//to display information on the screen
class Words {
public:
	//text class for display
	sf::Text text;

	//constructor for basic display
	Words(sf::Font& font, float CharacterSize, float posx, float posy);

	//constructor for words display
	Words(sf::Font& font, float CharacterSize, float posx, float posy, const String& word);
};
#endif