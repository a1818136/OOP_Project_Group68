#include <iostream>
#include <sstream>
#include <string>
#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include <time.h>
#include <variant>
#include <stdio.h>
#include "Season.h"
using namespace sf;
using namespace std;
int main() {
	{
		Season SeasonTest = Season::Spring;
		if (SeasonTest == Season::Spring) {
			cout << "Test 1 passed" << endl;
		}
		else {
			cout << "Test 1 failed" << endl;
		}
	}
	{
		Season SeasonTest = Season::Summer;
		if (SeasonTest == Season::Summer) {
			cout << "Test 2 passed" << endl;
		}
		else {
			cout << "Test 2 failed" << endl;
		}
	}
	{
		Season SeasonTest = Season::Autumn;
		if (SeasonTest == Season::Autumn) {
			cout << "Test 3 passed" << endl;
		}
		else {
			cout << "Test 3 failed" << endl;
		}
	}
	{
		Season SeasonTest = Season::Winter;
		if (SeasonTest == Season::Winter) {
			cout << "Test 4 passed" << endl;
		}
		else {
			cout << "Test 4 failed" << endl;
		}
	}
	return 0;
}