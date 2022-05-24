#pragma once
#ifndef PUMPKIN_H
#define PUMPKIN_H
#include <iostream>
#include <time.h>
#include <stdio.h>
#include <string>
#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include <vector>
#include <fstream>
#include "Crops.h"
using namespace std;
using namespace sf;

//child class derived from Crops
class Pumpkin : public Crops {
public:
	//constructor for pumpkin
	Pumpkin(int sys_time, sf::Vector2f pos);

	//pure virtual growth function for pumpkin case
	void growth();

};
#endif