#pragma once
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#include "Figure.h"

class Line : public Figure
{
	char** fullLine;

	int positionCounterX;
	int startPositionY;
	int localLength;
	int localExplosionChance;
	bool localEpilepsy;

	Figure figure;

public:

	Line(int y, int lenght, bool epilepsy, int milliseconds, int explosionChance, int delay);


	int getTime();
	int getLength();

	int getCoordX() override;
	int getCoordY() override;

	void offsetLine(char* currentLine);

	void drawLine(char* currentLine, int x, int y); 

	void move(int x, int y) override;

	void resetExplosionFlag();

	void deleteLine();

	virtual bool checkSelfTerminationFlag() override;
};

