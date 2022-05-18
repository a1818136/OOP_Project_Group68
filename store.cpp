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
#include "store.h"

store::store(){};

void store::buy(int* inventory, int* money) {
		*inventory = *inventory + 1;
		*money = *money - 5;
	}