#pragma once
#ifndef STORE_H
#define STORE_H
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
class store {
public:
	store();
	void buy(int* inventory, int* money);
};
#endif