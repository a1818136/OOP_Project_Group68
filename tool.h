#pragma once
#ifndef TOOL_H
#define TOOL_H
#include <iostream>
#include <time.h>
#include <stdio.h>
#include <string>
#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include <vector>
#include <variant>
#include <fstream>
#include "Season.h"
#include "Crops.h"
#include "Potato.h"
#include "Carrot.h"
#include "Pumpkin.h"
using namespace std;
using namespace sf;

//define a class
class tool {
public:
	//contain vector of specific crops
	std::vector<std::variant<Potato, Carrot, Pumpkin>> crops;

	//set attributes
	int costFert = 5;
	int key;

	//to load texture
	Texture texture;
	Sprite toolsprite;

	tool();

	//change the texture for a specific tool
	void states(int key);

	//different functions corresponding to specific tools
	void funnctions(int key, int count, int* money, int* inventory_fertilizer);

	//to genarate crop
	void functionRake(int key, int currTime, sf::Vector2f pos, int* inventory_potato, int* inventory_carrot, int* inventory_pumpkin);

	//save all the values of the current game
	void functionSave(int money, int inventory_potato, int inventory_carrot, int inventory_pumpkin, int inventory_fertiliser);

	//load from a saving file
	void functionLoad(int* money, int* inventory_potato, int* inventory_carrot, int* inventory_pumpkin, int* inventory_fertiliser);
};
#endif