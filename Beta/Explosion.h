#pragma once
#include "Figure.h"

class Explosion : public Figure
{
	int currentRadius = 0;
	int explosionRadius;

	int explosionPositionX;
	int explosionPositionY;

	Figure figure;

public:

	Explosion(int x, int y, int milliseconds, int radius);

	void drawExplosion(int x, int y, int radius);
	void clearExplosion(int x, int y, int radius);
	void move(int x, int y) override;

	int getCoordX() override;
	int getCoordY() override;

	virtual bool checkSelfTerminationFlag() override;

	int getExplosionRadius();
	int getCurrentExplosionRadius();
	int getTime(); //Add to figure
};

