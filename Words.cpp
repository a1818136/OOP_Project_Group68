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
#include "Carrot.h"
#include "Pumpkin.h"
#include "tool.h"
#include "Words.h"

Words::Words(sf::Font& font, float CharacterSize, float posx, float posy) {
		text.setFont(font);
		text.setCharacterSize(CharacterSize);
		text.setPosition(posx, posy);
		text.setOutlineColor(Color::Black);
		text.setFillColor(Color::White);
	}
Words::Words(sf::Font& font, float CharacterSize, float posx, float posy, const String& word) {
		text.setFont(font);
		text.setCharacterSize(CharacterSize);
		text.setPosition(posx, posy);
		text.setOutlineColor(Color::Black);
		text.setFillColor(Color::White);
		text.setString(word);
	}