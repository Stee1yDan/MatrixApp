#pragma once
#include <iostream>
#include <stdio.h>
#include <Windows.h>

class Symbol
{

public:

	char getSymbol();
	void setColor(int text, int background);
	void print(int x, int y, char charCode);
	int getRandom(int min, int max);
};

