#ifndef CROPS_H
#define CROPS_H
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
using namespace std;
using namespace sf;

class Crops {
public:
	sf::Sprite sprite;
	sf::Texture texture;
	int cost;
	int purchasePrice;
	int timeGenerate;
	int timeLived;
	int lastSec;
	int growrate = 0;
	bool watered = false;
	bool grow = false;
	Season currentSeason;
	virtual void growth() = 0;

	//updates the time and season
	void states(Season _currentSeason);

	//check for overlap
	bool intsec(Vector2i pos);
};
#endif