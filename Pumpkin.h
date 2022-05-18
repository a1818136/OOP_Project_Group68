#pragma once
#ifndef PUMPKIN_H
#define PUMPKIN_H
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
#include "Crops.h"
using namespace std;
using namespace sf;
class Pumpkin : public Crops {
public:
	Pumpkin(int sys_time, sf::Vector2f pos);

	void growth();

};
#endif