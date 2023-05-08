#include "Line.h"

	Line::Line(int y, int length, bool epilepsy, int milliseconds, int explosionChance, int delay) {

		localLength = length;
		localEpilepsy = epilepsy;
		localExplosionChance = explosionChance;
		figureTime = milliseconds;
		figureDelay = delay;

		fullLine = new char* [localLength * sizeof(char) * 3];

		fullLine[0] = new char[localLength * sizeof(char)];
		fullLine[1] = new char[localLength * sizeof(char)];
		fullLine[2] = new char[localLength * sizeof(char)];

		positionCounterX = figure.getWidth() - 1;
		startPositionY = y;

		for (int i = 0; i <= localLength; i++)
		{

			if (i % 2 == 0)
			{
				fullLine[0][i] = ' ';
				fullLine[1][i] = currentSymbol.getSymbol();
				fullLine[2][i] = ' ';
			}
			else
			{
				fullLine[0][i] = currentSymbol.getSymbol();
				fullLine[1][i] = ' ';
				fullLine[2][i] = currentSymbol.getSymbol();
			}
		}

	if (rand() % 2 == 1)
		{
			offsetLine(fullLine[0]);
			offsetLine(fullLine[1]);
			offsetLine(fullLine[2]);
		} 

	} 

	int Line::getTime()
	{
		return figureTime;
	}

	int Line::getLength()
	{
		return localLength;
	}


	int Line::getCoordX()
	{
		return positionCounterX;
	}

	int Line::getCoordY()
	{
		return startPositionY;
	}

	void Line::offsetLine(char* currentLine)
	{

		for (int i = 0; i < localLength; i++) {

			currentLine[i] = currentLine[i + 1];

		}

		if (currentLine[localLength] == ' ')
		{
			currentLine[localLength] = currentSymbol.getSymbol();
		}
		else
		{
			currentLine[localLength] = ' ';
		}

	}

	void Line::drawLine(char* currentLine, int x, int y)
	{

		int counter = figure.getWidth() - x - 1;
		int randomColor = figure.getRandom(1, 14);

		currentSymbol.setColor(15, 0);

		if (x > figure.getWidth() - localLength + 1)
		{
			currentSymbol.print(x, y, currentLine[counter]);

			if (localEpilepsy) currentSymbol.setColor(randomColor, 0);
			else currentSymbol.setColor(2, 0);

			if (counter != 0)
			{
				currentSymbol.print(x + 1, y, currentLine[counter - 1]);
			}

		}
		else if (!borderNotTouched(x))
		{
			currentSymbol.print(x + localLength, y, ' ');
		}
		else
		{
			currentSymbol.print(x, y, currentLine[localLength]);

			if (localEpilepsy) currentSymbol.setColor(randomColor,0);
			else currentSymbol.setColor(2, 0);;

			currentSymbol.print(x + 1, y, currentLine[localLength - 1]);

			offsetLine(currentLine);

			currentSymbol.print(x + localLength, y, ' ');
		}


	}

	void Line::move(int x, int y)
	{
		drawLine(fullLine[0], x, y + 1);
		drawLine(fullLine[1], x, y);
		drawLine(fullLine[2], x, y - 1);

		if (figure.getRandom(0, 1000) < localExplosionChance && fullLine[1][1] != ' ')
		{
			explosionFlag = true;
			localLength--;

			currentSymbol.print(x + localLength, y, ' ');
			currentSymbol.print(x + localLength, y + 1, ' ');
			currentSymbol.print(x + localLength, y - 1, ' ');

			offsetLine(fullLine[0]);
			offsetLine(fullLine[1]);
			offsetLine(fullLine[2]);

		}

		positionCounterX--;

	}

	void Line::resetExplosionFlag()
	{
		explosionFlag = false;
	}


	void Line::deleteLine() {
		delete[] fullLine;
	}

	bool Line::checkSelfTerminationFlag() //////////////
	{
		if (getCoordX() < -localLength || getLength() < 1)
		{
			return true;
		}

		return false;
	}