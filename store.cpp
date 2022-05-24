#include <iostream>
#include <time.h>
#include <stdio.h>
#include <string>
#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include <vector>
#include <fstream>
#include "store.h"
using namespace std;
using namespace sf;

//constructor
store::store(){};

//function for buying
void store::buy(int* inventory, int* money) {
		*inventory = *inventory + 1;
		*money = *money - 5;
	}