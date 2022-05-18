#pragma once
#ifndef TOOL_H
#define TOOL_H
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
using namespace std;
using namespace sf;
class tool {
public:
	vector<Potato> potatoes;
	vector<Carrot> carrots;
	vector<Pumpkin> pumpkins;
	int costFert = 5;
	int key;
	Texture texture;
	Sprite toolsprite;

	tool();

	//change the texture
	void states(int key);

	void funnctions(int type, int key, int count, int* money, int* inventory_fertilizer);

	//Genarate crop
	void functionRake(int key, int currTime, sf::Vector2f pos, int* inventory_potato, int* inventory_carrot, int* inventory_pumpkin);

	//save all the values of 
	void functionSave(int money, int inventory_potato, int inventory_carrot, int inventory_pumpkin, int inventory_fertiliser);

	void functionLoad(int* money, int* inventory_potato, int* inventory_carrot, int* inventory_pumpkin, int* inventory_fertiliser);
};
#endif