#include "Explosion.h"

Explosion::Explosion(int x, int y, int milliseconds,int radius) 
{
    explosionRadius = radius;
    figureTime = milliseconds;
    figureDelay = 500;
    explosionPositionX = x;
    explosionPositionY = y;
}

void Explosion::drawExplosion(int x, int y, int currentcurrentRadius)
{
    for (int i = 0; i <= currentRadius; i++)
    {
        if (borderNotTouched(x - i + currentRadius,y - i))
        {
            currentSymbol.setColor(figure.getRandom(1, 14), 0);
            currentSymbol.print(y - i, x - i + currentRadius, currentSymbol.getSymbol());
        }

        if (borderNotTouched(x + i - currentRadius, y - i))
        {
            currentSymbol.setColor(figure.getRandom(1, 14), 0);
            currentSymbol.print(y - i, x + i - currentRadius, currentSymbol.getSymbol());
        }

        if (borderNotTouched(x + i - currentRadius, y + i))
        {
            currentSymbol.setColor(figure.getRandom(1, 14), 0);
            currentSymbol.print(y + i, x + i - currentRadius, currentSymbol.getSymbol());
        }

        if (borderNotTouched(x - i + currentRadius, y + i))
        {
            currentSymbol.setColor(figure.getRandom(1, 14), 0);
            currentSymbol.print(y + i, x - i + currentRadius, currentSymbol.getSymbol());
        }     
    }
}

void Explosion::clearExplosion(int x, int y, int currentRadius)
{

    for (int i = 0; i <= currentRadius; i++)
    {
            if (borderNotTouched(x - i + currentRadius, y - i))
            {
                currentSymbol.print(y - i, x - i + currentRadius, ' ');
            }

            if (borderNotTouched(x + i - currentRadius, y - i))
            {
                currentSymbol.print(y - i, x + i - currentRadius, ' ');
            }

            if (borderNotTouched(x + i - currentRadius, y + i))
            {
                currentSymbol.print(y + i, x + i - currentRadius, ' ');
            }
            
            if (borderNotTouched(x - i + currentRadius, y + i))
            {
                currentSymbol.print(y + i, x - i + currentRadius, ' ');
            }
    }
}

void Explosion::move(int x, int y)
{
    drawExplosion(x, y, currentRadius);
    clearExplosion(x, y, currentRadius - 1);
    currentRadius++;
}

int Explosion::getExplosionRadius()
{
    return explosionRadius;
}

int Explosion::getCurrentExplosionRadius()
{
    return currentRadius;
}

int Explosion::getTime()
{
    return figureTime;
}

bool Explosion::checkSelfTerminationFlag() // 
{
    if (currentRadius > explosionRadius)
    {
        clearExplosion(explosionPositionX, explosionPositionY, currentRadius - 1);
        return true;
    }
    return false;
}

int Explosion::getCoordX()
{
    return explosionPositionX;
}

int Explosion::getCoordY()
{
    return explosionPositionY;
}



