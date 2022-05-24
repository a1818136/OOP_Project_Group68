#pragma once
#ifndef POTATO_H
#define POTATO_H
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
class Potato : public Crops {
public:
	//constructor for potato
	Potato(int sys_time, sf::Vector2f pos);

	//pure virtual growth function for potato case
	void growth();

};

#endif