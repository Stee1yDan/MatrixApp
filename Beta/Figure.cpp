#include "Figure.h"
int Figure::getWidth()
{
	int width;
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hStdOut, &csbi);
	width = csbi.srWindow.Right - csbi.srWindow.Left;

	return width;
}

bool Figure::borderNotTouched(int x)
{
	if ((x > 0) && (x < getWidth())) return true;
	return false;
}

bool Figure::borderNotTouched(int x, int y)
{

	if ((x > 0) && (x < getWidth()) && (y > 0)) return true;
		
	return false;
}

void Figure::addTime()
{
	figureTime += figureDelay;
}

int Figure::getTime()
{
	return figureTime;
}

void Figure::move(int x, int y)
{
	currentSymbol.print(x, y, currentSymbol.getSymbol());
	currentSymbol.print(x + 1, y, ' ');
}

bool Figure::isNeedToMove(int deltaTime)
{
	if (deltaTime > figureTime) return true;
	return false;
}

bool Figure::checkExplosionFlag()
{
	return explosionFlag;
}

bool Figure::checkSelfTerminationFlag()
{
	return terminationFlag;
}

int Figure::getCoordX() // DO NOT REMOVE!!! LINK2001 ERROR
{
	return 0;
}

int Figure::getCoordY() // DO NOT REMOVE!!! LINK2001 ERROR
{
	return 0;
}

void Figure::resetExplosionFlag()
{
	explosionFlag = false;
}

int Figure::getRandom(int min, int max)
{
	return rand() % max + min;
}
