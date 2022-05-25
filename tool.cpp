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
#include "tool.h"
using namespace std;
using namespace sf;

//constructor
tool::tool( ){ };

//change the texture for a specific tool
void tool::states(int key) {
	switch (key) {
		//Spray bottle
	case 11:
		texture.loadFromFile("water.png");
		toolsprite.setTexture(texture);
		break;
		//Shovel
	case 12:
		texture.loadFromFile("sholve.png");
		toolsprite.setTexture(texture);
		break;
		//Glove
	case 13:
		texture.loadFromFile("glove.png");
		toolsprite.setTexture(texture);
		break;
		//Fertiliser
	case 14:
		texture.loadFromFile("fert.png");
		toolsprite.setTexture(texture);
		break;
	}
}

//different functions corresponding to specific tools
void tool::funnctions(int key, int count, int* money, int* inventory_fertilizer) {
	switch (key) {
		//function for spray bottle,to change the water condition
	case 11:
		crops[count]._Storage()._Get().watered = true;
		break;
		//function for spray bottle,to delete the correspoding crop in the vector
	case 12:
		crops.erase(crops.begin() + count);
		break;

		//function for spray bottle,to delete the correspoding crop in the vector and increase money
	case 13:
		if (crops[count]._Storage()._Get().harvestable == true) {
			crops.erase(crops.begin() + count);
			*money = *money + 10;
			break;
		}

		//delete the correspoding crop in the vector, to change growrate of the correspoding crop
	case 14:
		if (crops[count]._Storage()._Get().harvestable == false && *inventory_fertilizer > 0) {
			crops[count]._Storage()._Get().growrate = crops[count]._Storage()._Get().growrate + 10;
			break;
		}
	}
	//indicating overlap in test
	//std::cout << "! Overlap !" << std::endl;
}

//to genarate crop
void tool::functionRake(int key, int currTime, sf::Vector2f pos, int* inventory_potato, int* inventory_carrot, int* inventory_pumpkin) {
	//to generate potato,carrot and pumpkin when pressing numberkey 1,2,3 respectively

	//add potato
	if (key == 1 && *inventory_potato > 0) {
		crops.push_back(Potato(currTime, pos));
		*inventory_potato = *inventory_potato - 1;
	}
	//add carrot
	else if (key == 2 && *inventory_carrot > 0) {
		crops.push_back(Carrot(currTime, pos));
		*inventory_carrot = *inventory_carrot - 1;
	}
	//add pumpkin
	else if (key == 3 && *inventory_pumpkin > 0) {
		crops.push_back(Pumpkin(currTime, pos));
		*inventory_pumpkin = *inventory_pumpkin - 1;
	}
}

//save all the values of the current game
void tool::functionSave(int money, int inventory_potato, int inventory_carrot, int inventory_pumpkin, int inventory_fertiliser) {
	ofstream file;

	//save basic player information
	file.open("file.dat");
	file << money << endl;
	file << inventory_potato << endl;
	file << inventory_carrot << endl;
	file << inventory_pumpkin << endl;
	file << inventory_fertiliser << endl;

	//loop to save the information of crops planted
	int sizeCrops = crops.size();
	file << sizeCrops << endl;
	for (size_t i = 0; i < crops.size(); i++) {
		file << crops[i]._Storage()._Get().type << endl;
		file << crops[i]._Storage()._Get().sprite.getPosition().x << endl;
		file << crops[i]._Storage()._Get().sprite.getPosition().y << endl;
		file << crops[i]._Storage()._Get().timeGenerate << endl;
		file << crops[i]._Storage()._Get().growrate << endl;
		file << crops[i]._Storage()._Get().watered << endl;
	}
}

//load from a saving file
void tool::functionLoad(int* money, int* inventory_potato, int* inventory_carrot, int* inventory_pumpkin, int* inventory_fertiliser) {
	cout << "Load" << endl;
	ifstream infile;
	infile.open("file.dat");

	//initialise the basic values to load
	int _money = 0;
	int potato = 0;
	int carrot = 0;
	int pumpkin = 0;
	int fertiliser = 0;

	//stream from the saving file to the values to load
	infile >> _money;
	infile >> potato;
	infile >> carrot;
	infile >> pumpkin;
	infile >> fertiliser;
	*money = _money;
	*inventory_potato = potato;
	*inventory_carrot = carrot;
	*inventory_pumpkin = pumpkin;
	*inventory_fertiliser = fertiliser;

	//initialise the related values of crops
	int sizeCrops;
	infile >> sizeCrops;
	float x;
	float y;
	int timeGenerate;
	int growthrate;
	int type;
	bool waterd;

	//loop to load different kinds of crops
	for (int i = 0; i < sizeCrops; i++) {
		//stream to target values
		infile >> type;
		infile >> x;
		infile >> y;
		infile >> timeGenerate;
		infile >> growthrate;
		infile >> waterd;
		Vector2f pos = { x, y };

		//set states of specific crops according to the load data
		switch (type) {
		//potato case
		case 1:
			crops.push_back(Potato(timeGenerate, pos));
			crops[i]._Storage()._Get().growrate = growthrate;
			crops[i]._Storage()._Get().watered = waterd;
			break;
		//carrot case
		case 2:
			crops.push_back(Carrot(timeGenerate, pos));
			crops[i]._Storage()._Get().growrate = growthrate;
			crops[i]._Storage()._Get().watered = waterd;
			break;
		//pumpkin case
		case 3:
			crops.push_back(Pumpkin(timeGenerate, pos));
			crops[i]._Storage()._Get().growrate = growthrate;
			crops[i]._Storage()._Get().watered = waterd;
			break;
		}

	}
}