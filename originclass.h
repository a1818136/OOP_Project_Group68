#pragma once
#include <iostream>
#include <time.h>
#include <stdio.h>
#include <string>
#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "vector"
#include <variant>
#include <fstream>
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
	int type;
	int cost;
	int purchasePrice;
	int timeGenerate;
	int timeLived;
	int lastSec;
	int growrate = 0;
	bool watered = false;
	bool grow = false;
	bool harvestable = false;
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
		type = 1;
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
		case 5: texture.loadFromFile("potato/potato6.png"); sprite.setTexture(texture); harvestable = true; break;
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
		type = 2;
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
		case 4: texture.loadFromFile("carrot/carrot5.png"); sprite.setTexture(texture); harvestable = true; break;
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
		type = 3;
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
		case 5: texture.loadFromFile("pumpkin/pumpkin6.png"); sprite.setTexture(texture); harvestable = true; break;
		}
	}

};

class tool {
public:
	std::vector<std::variant<Potato, Carrot, Pumpkin>> crops;
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

	void funnctions(int key, int count,int *money,int *inventory_fertilizer) {
		switch (key){
		//Spray bottle
		case 11:
			crops[count]._Storage()._Get().watered = true;
			break;
		//Hoe
		case 12:
			crops.erase(crops.begin() + count);
			break;
			
		//Sickle
		case 13:
			if (crops[count]._Storage()._Get().harvestable == true){
				crops.erase(crops.begin() + count);
				*money = *money + 10;
				break;
			}
			
		//Fertiliser
		case 14:
			if (crops[count]._Storage()._Get().harvestable == false && *inventory_fertilizer > 0) {
				crops[count]._Storage()._Get().growrate = crops[count]._Storage()._Get().growrate + 10;
				break;
			}
		}
		std::cout << "! Overlap !" << std::endl;
	}

	//Genarate crop
	void functionRake(int key, int currTime,sf::Vector2f pos, int* inventory_potato, int *inventory_carrot, int *inventory_pumpkin) {
		if (key==1 && *inventory_potato > 0){
			crops.push_back(Potato(currTime, pos));
			*inventory_potato = *inventory_potato - 1;
		}
		else if (key==2 && *inventory_carrot > 0){
			crops.push_back(Carrot(currTime, pos));
			*inventory_carrot = *inventory_carrot - 1;
		}
		else if (key == 3 && *inventory_pumpkin > 0) {
			crops.push_back(Pumpkin(currTime, pos));
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
	void functionLoad(int *money, int *inventory_potato, int *inventory_carrot, int *inventory_pumpkin, int *inventory_fertiliser) {
		cout << "Load" << endl;
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
		int sizeCrops;
		infile >> sizeCrops;
		float x;
		float y;
		int timeGenerate;
		int growthrate;
		int type;
		bool waterd;
		for (int i = 0; i < sizeCrops; i++){
			infile >> type;
			infile >> x;
			infile >> y;
			infile >> timeGenerate;
			infile >> growthrate;
			infile >> waterd;
			Vector2f pos = { x, y };
			switch (type){
			case 1:
				crops.push_back(Potato(timeGenerate, pos));
				crops[i]._Storage()._Get().growrate = growthrate;
				crops[i]._Storage()._Get().watered = waterd;
				break;
			case 2:
				crops.push_back(Carrot(timeGenerate, pos));
				crops[i]._Storage()._Get().growrate = growthrate;
				crops[i]._Storage()._Get().watered = waterd;
				break;
			case 3:
				crops.push_back(Pumpkin(timeGenerate, pos));
				crops[i]._Storage()._Get().growrate = growthrate;
				crops[i]._Storage()._Get().watered = waterd;
				break;
			}
			
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
