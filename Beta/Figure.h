#pragma once
#include <Windows.h>
#include <chrono>
#include <thread>

#include "Symbol.h"

class Figure
{

public:
	virtual void addTime();
	virtual void move(int x, int y); 

	virtual int getTime();

	virtual int getCoordX();
	virtual int getCoordY();

	bool borderNotTouched(int x);
	bool borderNotTouched(int x, int y);

	bool isNeedToMove(int currentTime);
	bool checkExplosionFlag();

	virtual bool checkSelfTerminationFlag();
	void resetExplosionFlag();

	int getRandom(int min, int max);
	int getWidth();

protected:
	Symbol currentSymbol;

	int figureTime = 0;
	int figureDelay = 0;
	bool explosionFlag = false;
	bool terminationFlag = false;
};

