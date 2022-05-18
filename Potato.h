#pragma once
#ifndef POTATO_H
#define POTATO_H
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
class Potato : public Crops {
public:
	Potato(int sys_time, sf::Vector2f pos);

	void growth();

};

#endif