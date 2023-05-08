#include "Manager.h"

	void Manager::setConsoleSize(int x, int y)
	{
		HWND console = GetConsoleWindow();
		RECT r;
		GetWindowRect(console, &r);
		MoveWindow(console, r.left, r.top, x, y, TRUE);
	}

	void  Manager::getInput()
	{
		srand(time(NULL));

		while (true)
		{
			cout << "Enter frequency (1-30) : ";
			cin >> frequency;
			if (frequency > 0 && frequency < 31) break;
			cout << "ERROR: Invalid value" << "\n";
			cin.clear();
			cin.ignore(10000, '\n');
		}

		while (true)
		{
			cout << "Enter speed (1-30) : ";
			cin >> speed;
			if (speed > 0 && speed < 31) break;
			cout << "ERROR: Invalid value" << "\n";
			cin.clear();
			cin.ignore(10000, '\n');
		}

		while (true)
		{
			cout << "Enter length (1-30) : ";
			cin >> length;
			if (length > 0 && length < 31) break;
			cout << "ERROR: Invalid value" << "\n";
			cin.clear();
			cin.ignore(10000, '\n');
		}

		while (true)
		{
			cout << "Enable epilepsy Mode? ([Y]es/[N]o) : ";
			cin >> epilepsy;
			if (epilepsy == 'Y')
			{
				epilepsyMode = 1;
				break;
			}
			else if (epilepsy == 'N')
			{
				epilepsyMode = 0;
				break;
			}
			cout << "ERROR: Invalid value" << "\n";
			cin.clear();
			cin.ignore(10000, '\n');
		}

		while (true)
		{
			cout << "Enter minimal explosion radius (1-10): ";
			cin >> minExplosionRadius;
			if (minExplosionRadius > 0 && minExplosionRadius < 11) break;
			cout << "ERROR: Invalid value" << "\n";
			cin.clear();
			cin.ignore(10000, '\n');
		}

		while (true)
		{
			cout << "Enter maximal explosion radius (1-10): ";
			cin >> maxExplosionRadius;
			if (maxExplosionRadius > 0 && maxExplosionRadius < 11 && maxExplosionRadius > minExplosionRadius) break;
			cout << "ERROR: Invalid value" << "\n";
			cin.clear();
			cin.ignore(10000, '\n');
		}

		while (true)
		{
			cout << "Enter explosion chance (1-1000): ";
			cin >> explosionChance;
			if (explosionChance > 0 && explosionChance < 1001) break;
			cout << "ERROR: Invalid value" << "\n";
			cin.clear();
			cin.ignore(10000, '\n');
		}

		currentTimePoint = 0;

		delay = 1000 /getSpeed();
		currentLoopTime = 1000 / getFrequency();
	}

	int  Manager::getFrequency()
	{
		return frequency;
	}

	int  Manager::getSpeed()
	{
		return speed;
	}

	int  Manager::getLength()
	{
		return length;
	}

	int Manager::getMinExplosionRadius()
	{
		return minExplosionRadius;
	}

	int Manager::getMaxExplosionRadius()
	{
		return maxExplosionRadius;
	}

	int Manager::getExplosionChance()
	{
		return explosionChance;
	}

	bool Manager::getEpilepsyMode()
	{
		return epilepsyMode;
	}

	void Manager::setLastGenerationTimePoint(int time)
	{
		lastGenerationTime = time;
	}

	bool Manager::isNeedLineGeneration(int currentTime)
	{
		if (currentTime - lastGenerationTime > 1000)
		{
			return true;
		}
		return false;
	}

	int Manager::getWidth()
	{
		int width;
		CONSOLE_SCREEN_BUFFER_INFO csbi;

		HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
		GetConsoleScreenBufferInfo(hStdOut, &csbi);
		width = csbi.srWindow.Right - csbi.srWindow.Left;
		return width;
	};

	int Manager::getHeight() //
	{
		int height;
		CONSOLE_SCREEN_BUFFER_INFO csbi;

		HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
		GetConsoleScreenBufferInfo(hStdOut, &csbi);
		height = csbi.srWindow.Bottom - csbi.srWindow.Top;
		return height;
	};

	int Manager::getRandom(int min, int max) 
	{
		return rand() % max + min;
	}

	void Manager::hideCursor()
	{
		HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_CURSOR_INFO info;
		info.dwSize = 100;
		info.bVisible = FALSE;
		SetConsoleCursorInfo(consoleHandle, &info);
	}

	void Manager::move()
	{
		currentTimePoint = clock();

		if (isNeedLineGeneration(currentTimePoint))
		{
			for (int j = 0; j < getFrequency(); j++)
			{
				int lineTime = getRandom(0, 1000) + currentTimePoint;

				Line* line = new Line(getRandom(2, getHeight() - 2), getLength(), getEpilepsyMode(), lineTime, getExplosionChance(), delay);
				figureArray.push_back(line);
			}
			setLastGenerationTimePoint(clock());
		}

		for (int i = 0; i < figureArray.size(); i++)
		{
			if (figureArray[i]->isNeedToMove(currentTimePoint))
			{
				figureArray[i]->move(figureArray[i]->getCoordX(), figureArray[i]->getCoordY());
				figureArray[i]->addTime();

				if (figureArray[i]->checkExplosionFlag()) // TODO: move method must return NULL or explosion pointer;
				{
					Explosion* explosion = new Explosion(figureArray[i]->getCoordY(), figureArray[i]->getCoordX(), clock(), getRandom(getMinExplosionRadius(), getMaxExplosionRadius()));
					figureArray.push_back(explosion);
					figureArray[i]->resetExplosionFlag();
				}

				if (figureArray[i]->checkSelfTerminationFlag())
				{
					figureArray.erase(figureArray.begin() + i);
				}
			}
		}
	}





