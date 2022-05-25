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
using namespace std;
using namespace sf;


//updates the time and season
void Crops::states(Season _currentSeason) {
	//set time
	time_t timep;
	int currentTime = time(&timep);
	lastSec = timeLived;
	timeLived = currentTime - timeGenerate;
	//check if the time increase
	if (lastSec < timeLived) {
		grow = true;
	}
	currentSeason = _currentSeason;
	}

//check for overlap
bool Crops::intsec(Vector2i pos) {
	//if overlap
	if (((sprite.getPosition().x < pos.x)
		&& ((sprite.getPosition().x + 48) > pos.x))
		&& ((sprite.getPosition().y < pos.y)
		&& ((sprite.getPosition().y + 48 > pos.y))))
	{
		return true;
	}
	    return false;
	}