#include "Manager.h"
#include "Symbol.h"

using namespace std;

int main()
{
	Manager manager;

	manager.setConsoleSize(800, 500);
	manager.getInput();
	manager.hideCursor();

	system("cls");

	manager.setLastGenerationTimePoint(0);

	while (true)
	{
		manager.move();
	}
}
