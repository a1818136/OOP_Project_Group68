#pragma once
#ifndef CARROT_H
#define CARROT_H
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

//child class derived from Crops
class Carrot : public Crops {
public:
	//constructor for carrot
	Carrot(int sys_time, sf::Vector2f pos);

	//growth function for carrot case
	void growth();
};

#endif