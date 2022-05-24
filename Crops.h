#ifndef CROPS_H
#define CROPS_H
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
using namespace std;
using namespace sf;

//a basic class for crops
class Crops {
public:
	//display the testure
	sf::Sprite sprite;
	sf::Texture texture;

	//basic attributes for crops
	int type;
	int cost;
	int purchasePrice;
	int timeGenerate;
	int timeLived;
	int lastSec;
	int growrate = 0;
	bool watered = false;
	bool grow = false;
	bool harvestable = false;
	Season currentSeason;

	//pure vritual grow situations for different kindscrops
	virtual void growth() = 0;

	//updates the time and season
	void states(Season _currentSeason);

	//check for overlap
	bool intsec(Vector2i pos);
};
#endif