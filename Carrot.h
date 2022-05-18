#pragma once
#ifndef CARROT_H
#define CARROT_H
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
using namespace std;
using namespace sf;
class Carrot : public Crops {
public:
	Carrot(int sys_time, sf::Vector2f pos);

	void growth();
};

#endif