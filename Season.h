#pragma once
#ifndef SEASON_H
#define SEASON_H
#include <iostream>
#include <time.h>
#include <stdio.h>
#include <string>
#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include <vector>
#include <fstream>
using namespace std;
using namespace sf;

enum class Season {
	Spring,
	Summer,
	Autumn,
	Winter,
};
#endif