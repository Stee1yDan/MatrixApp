#include "Symbol.h"

char Symbol::getSymbol()
{
	return rand() % 93 + 33;
}

void Symbol::print(int x, int y, char charCode)
{
	printf("\033[%d;%dH%c", y, x, charCode);
}

void Symbol::setColor(int text, int background)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut,
		(WORD)((background << 4) | text));
}
