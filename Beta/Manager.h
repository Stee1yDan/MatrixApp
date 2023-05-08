#pragma once
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <WinUser.h>
#include <ctime>
#include <chrono>
#include <thread>
#include <random>
#include <vector>
#include <string>

#include "Figure.h"
#include "Line.h"
#include "Explosion.h"

using namespace std;

class Manager
{
	public:
		vector<Figure*> figureArray;

		int frequency;
		int speed;
		int length;
		int minExplosionRadius = 1;
		int maxExplosionRadius = 10;
		int explosionChance = 100;

		int lastGenerationTime = 0;
		char epilepsy;
		bool epilepsyMode = 0;

		int currentTimePoint;

		int delay;
		int currentLoopTime;

		void getInput();

		int getFrequency();
		int getSpeed();
		int getLength();
		int getMinExplosionRadius();
		int getMaxExplosionRadius();
		int getExplosionChance();

		bool getEpilepsyMode();

		void setLastGenerationTimePoint(int time);

		bool isNeedLineGeneration(int currentTime);

		int getWidth();
		int getHeight();
		void hideCursor();
		void setConsoleSize(int x, int y);

		int getRandom(int min, int max);

		void move();

};

