#pragma once
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
#include "crops.h"
using namespace std;
using namespace sf;

enum class Season {
	Spring,
	Summer,
	Autumn,
	Winter,
};

class Crops{
public:
	sf::Sprite sprite;
	sf::Texture texture;
	int cost;
	int purchasePrice;
	int timeGenerate;
	int timeLived;
	int lastSec;
	int growrate = 0;
	bool watered = false;
	bool grow = false;
	Season currentSeason;
	virtual void growth() = 0;
	//updates the time and season
	void states(Season _currentSeason) {
		time_t timep;
		int currentTime = time(&timep);
		lastSec = timeLived;
		timeLived = currentTime - timeGenerate;
		//check if the time increase
		if (lastSec < timeLived){
			grow = true;
		}
		currentSeason = _currentSeason;
	}
	//check for overlap
	bool intsec(Vector2i pos) {
		if (((sprite.getPosition().x < pos.x)
			&& ((sprite.getPosition().x + 48) > pos.x))
			&& ((sprite.getPosition().y < pos.y)
			&& ((sprite.getPosition().y + 48 > pos.y))))
			{
			return true;
		}
		return false;
	}
};

class Potato : public Crops {
public:
	Potato(int sys_time, sf::Vector2f pos) {
		timeGenerate = sys_time;
		//adjust the position of sprite
		pos.x = pos.x - 24;
		pos.y = pos.y - 35;
		sprite.setPosition(pos);
		cost = 5;
		purchasePrice = 10;
	}

	void growth() {
		//diffrent growth rate in different season
		if (grow && watered) {
			switch (currentSeason) {
			case Season::Spring:
				growrate += 2;
				break;
			case Season::Summer:
				growrate++;
				break;
			case Season::Autumn:
				growrate += 2;
				break;
			case Season::Winter:
				growrate++;
				break;
			}
			grow = false;
		}
		//change the textrue
		switch (growrate / 10) {
		case 0: texture.loadFromFile("potato/potato1.png"); sprite.setTexture(texture); break;
		case 1: texture.loadFromFile("potato/potato2.png"); sprite.setTexture(texture); break;
		case 2: texture.loadFromFile("potato/potato3.png"); sprite.setTexture(texture); break;
		case 3: texture.loadFromFile("potato/potato4.png"); sprite.setTexture(texture); break;
		case 4: texture.loadFromFile("potato/potato5.png"); sprite.setTexture(texture); break;
		case 5: texture.loadFromFile("potato/potato6.png"); sprite.setTexture(texture); break;
		}
	}

};

class Carrot : public Crops {
public:
	Carrot(int sys_time, sf::Vector2f pos) {
		timeGenerate = sys_time;
		//adjust the position of sprite
		pos.x = pos.x - 24;
		pos.y = pos.y - 35;
		sprite.setPosition(pos);
		cost = 5;
		purchasePrice = 10;
	}

	void growth() {
		//diffrent growth rate in different season
		if (grow && watered) {
			switch (currentSeason) {
			case Season::Spring:
				growrate++;
				break;
			case Season::Summer:
				growrate++;
				break;
			case Season::Autumn:
				growrate++;
				break;
			case Season::Winter:
				growrate++;
				break;
			}
			grow = false;
		}
		//change the textrue
		switch (growrate / 10) {
		case 0: texture.loadFromFile("carrot/carrot1.png"); sprite.setTexture(texture); break;
		case 1: texture.loadFromFile("carrot/carrot2.png"); sprite.setTexture(texture); break;
		case 2: texture.loadFromFile("carrot/carrot3.png"); sprite.setTexture(texture); break;
		case 3: texture.loadFromFile("carrot/carrot4.png"); sprite.setTexture(texture); break;
		case 4: texture.loadFromFile("carrot/carrot5.png"); sprite.setTexture(texture); break;
		}
	}

};

class Pumpkin : public Crops {
public:
	Pumpkin(int sys_time, sf::Vector2f pos) {
		timeGenerate = sys_time;
		//adjust the position of sprite
		pos.x = pos.x - 24;
		pos.y = pos.y - 35;
		sprite.setPosition(pos);
		cost = 5;
		purchasePrice = 10;
	}

	void growth() {
		//diffrent growth rate in different season
		if (grow && watered) {
			switch (currentSeason) {
			case Season::Spring:
				growrate += 2;
				break;
			case Season::Summer:
				growrate++;
				break;
			case Season::Autumn:
				growrate++;
				break;
			case Season::Winter:
				growrate++;
				break;
			}
			grow = false;
		}
		//change the textrue
		switch (growrate / 10) {
		case 0: texture.loadFromFile("pumpkin/pumpkin1.png"); sprite.setTexture(texture); break;
		case 1: texture.loadFromFile("pumpkin/pumpkin2.png"); sprite.setTexture(texture); break;
		case 2: texture.loadFromFile("pumpkin/pumpkin3.png"); sprite.setTexture(texture); break;
		case 3: texture.loadFromFile("pumpkin/pumpkin4.png"); sprite.setTexture(texture); break;
		case 4: texture.loadFromFile("pumpkin/pumpkin5.png"); sprite.setTexture(texture); break;
		case 5: texture.loadFromFile("pumpkin/pumpkin6.png"); sprite.setTexture(texture); break;
		}
	}

};

class tool {
public:
	vector<Potato> potatoes;
	vector<Carrot> carrots;
	vector<Pumpkin> pumpkins;
	int costFert = 5;
	int key;
	Texture texture;
	Sprite toolsprite;
	tool(){};

	//change the texture
	void states(int key) {
		switch (key){
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

	void funnctions(int type, int key, int count,int *money,int *inventory_fertilizer) {
		switch (key){
		//Spray bottle
		case 11:
			if (type==1){
				potatoes[count].watered = true;
				break;
			}
			else if(type==2) {
				carrots[count].watered = true;
				break;
			}
			else if (type == 3) {
				pumpkins[count].watered = true;
				break;
			}
		//Hoe
		case 12:
			if (type == 1) {
				potatoes.erase(potatoes.begin() + count);
				break;
			}
			else if (type == 2) {
				carrots.erase(carrots.begin() + count);
				break;
			}
			else if (type == 3) {
				pumpkins.erase(pumpkins.begin() + count);
				break;
			}
			
		//Sickle
		case 13:
			if (type == 1 && potatoes[count].growrate >= 50) {
				potatoes.erase(potatoes.begin() + count);
				*money = *money + 10;
			}
			else if (type == 2 && carrots[count].growrate >= 40) {
				carrots.erase(carrots.begin() + count);
				*money = *money + 15;
			}
			else if (type == 3 && pumpkins[count].growrate >=50) {
				pumpkins.erase(pumpkins.begin() + count);
				*money = *money + 20;
				break;
			}
		//Fertiliser
		case 14:
			if (type == 1 && *inventory_fertilizer > 0) {
				potatoes[count].growrate = potatoes[count].growrate + 10;
				*inventory_fertilizer = *inventory_fertilizer - 1;
			}
			else if (type == 2 && *inventory_fertilizer > 0) {
				carrots[count].growrate = carrots[count].growrate + 8;
				*inventory_fertilizer = *inventory_fertilizer - 1;
			}
			else if (type == 3 && *inventory_fertilizer > 0) {
				pumpkins[count].growrate = pumpkins[count].growrate + 10;
				*inventory_fertilizer = *inventory_fertilizer - 1;
				break;
			}
		}
		std::cout << "! Overlap !" << std::endl;
	}

	//Genarate crop
	void functionRake(int key, int currTime,sf::Vector2f pos, int* inventory_potato, int *inventory_carrot, int *inventory_pumpkin) {
		if (key==1 && *inventory_potato > 0){
			potatoes.push_back(Potato(currTime, pos));
			*inventory_potato = *inventory_potato - 1;
		}
		else if (key==2 && *inventory_carrot > 0){
			carrots.push_back(Carrot(currTime, pos));
			*inventory_carrot = *inventory_carrot - 1;
		}
		else if (key == 3 && *inventory_pumpkin > 0) {
			pumpkins.push_back(Pumpkin(currTime, pos));
			*inventory_pumpkin = *inventory_pumpkin - 1;
		}
	}
	//save all the values of 
	void functionSave(int money,int inventory_potato, int inventory_carrot, int inventory_pumpkin, int inventory_fertiliser) {
		ofstream file;
		file.open("file.dat");
		file << money << endl;
		file << inventory_potato << endl;
		file << inventory_carrot << endl;
		file << inventory_pumpkin << endl;
		file << inventory_fertiliser << endl;
		int sizePotato = potatoes.size();
		int sizeCarrot = carrots.size();
		int sizePumpkin = pumpkins.size();
		file << sizePotato << endl;
		file << sizeCarrot << endl;
		file << sizePumpkin << endl;
		for (size_t i = 0; i < potatoes.size(); i++) {
			file << potatoes[i].sprite.getPosition().x << endl;
			file << potatoes[i].sprite.getPosition().y << endl;
			file << potatoes[i].timeGenerate << endl;
			file << potatoes[i].growrate << endl;
		}
		for (size_t j = 0; j < carrots.size(); j++) {
			file << carrots[j].sprite.getPosition().x << endl;
			file << carrots[j].sprite.getPosition().y << endl;
			file << carrots[j].timeGenerate << endl;
			file << carrots[j].growrate << endl;
		}
		for (size_t k = 0; k < pumpkins.size(); k++) {
			file << pumpkins[k].sprite.getPosition().x << endl;
			file << pumpkins[k].sprite.getPosition().y << endl;
			file << pumpkins[k].timeGenerate << endl;
			file << pumpkins[k].growrate << endl;
		}
	}
	void functionLoad(int *money, int *inventory_potato, int *inventory_carrot, int *inventory_pumpkin, int *inventory_fertiliser) {
		cout << ".h load" << endl;
		ifstream infile;
		infile.open("file.dat");
		int _money=0;
		int potato=0;
		int carrot=0;
		int pumpkin=0;
		int fertiliser=0;
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
		int sizePotato;
		int sizeCarrot;
		int sizePumpkin;
		infile >> sizePotato;
		infile >> sizeCarrot;
		infile >> sizePumpkin;
		float x;
		float y;
		int timeGenerate;
		int growthrate;
		for (int i = 0; i < sizePotato; i++){
			infile >> x;
			infile >> y;
			infile >> timeGenerate;
			infile >> growthrate;
			Vector2f pos = { x, y };
			potatoes.push_back(Potato(timeGenerate, pos));
			potatoes[i].growrate = growthrate;
		}
		for (int j = 0; j < sizeCarrot; j++) {
			infile >> x;
			infile >> y;
			infile >> timeGenerate;
			infile >> growthrate;
			Vector2f pos = { x, y };
			carrots.push_back(Carrot(timeGenerate, pos));
			carrots[j].growrate = growthrate;
		}
		for (int k = 0; k < sizePumpkin; k++) {
			infile >> x;
			infile >> y;
			infile >> timeGenerate;
			infile >> growthrate;
			Vector2f pos = { x, y };
			pumpkins.push_back(Pumpkin(timeGenerate, pos));
			pumpkins[k].growrate = growthrate;
		}
	}
};

class Words{
public:
	sf::Text text;
	Words(Font &font, float CharacterSize, float posx, float posy) {
		text.setFont(font);
		text.setCharacterSize(CharacterSize);
		text.setPosition(posx, posy);
		text.setOutlineColor(Color::Black);
		text.setFillColor(Color::White);
	}
	Words(Font &font, float CharacterSize, float posx, float posy, const String &word) {
		text.setFont(font);
		text.setCharacterSize(CharacterSize);
		text.setPosition(posx, posy);
		text.setOutlineColor(Color::Black);
		text.setFillColor(Color::White);
		text.setString(word);
	}
};

class store{
public:
	store(){};
	void buy(int *inventory,int *money) {
		*inventory = *inventory + 1;
		*money = *money - 5;
	}
};
