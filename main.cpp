#include <iostream>
#include <conio.h>
#include <Windows.h>

bool gameOver;
bool fire;
bool fireLastState;
bool enemyB;
const int width = 20;
const int height = 10;
int x, y, fX, fY, eX, eY, score;
char enemyC = 'V';
unsigned long clock = 0;

void setup()
{
	gameOver = false;
    // Starting position
	x = width / 2;
	y = height - 1;
    // Enemy starting position
	eX = rand() % width;
	eY = 0;
}

void draw()
{
    // Clear the terminal
	system("cls");
    // Top "border"
	for (int i = 0; i < width; i++)
	{
		std::cout << "#";
	}

    // Print new line
	std::cout << '\n';

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width + 3; j++)
		{
            // Left border
			if (j == 0)
				std::cout << "#";

			if (j > 0 && j < width - 1)
			{
                // Prints player
				if (i == y && j == x)
					std::cout << "A";
                // Prints enemy
				else if (i == eY && j == eX && enemyB == true)
					std::cout << enemyC;
                // Prints the "bullet"
				else if (i == fY && j == fX)
					std::cout << ".";
				else
					std::cout << " ";
			}
            // Right border
			if (j == width + 2)
				std::cout << "#";
		}
		std::cout << "\n";
	}
	for (int i = 0; i < width; i++)
	{
		std::cout << "#";
	}
	std::cout << "\n\nScore: " << score << "\n";
}

void input()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			if (x > 1)
			{
				x -= 1;
			}
			break;
		case 'd':
			if (x < width - 2)
			{
				x += 1;
			}
			break;
		case 'j':
		{
			{
				fire = true;
			}
			break;
		}
		case 'o':
			gameOver = true;
			break;
		}
	}
}

void logic()
{
	// missles:
	if (fire == true)
	{
		fX = x;
		fY = height - 2;
		fire = false;
	}
	fY -= 1;
	if (fY == eY && fX == eX)
	{
		score += 10;
		enemyB = false;
		enemyC = 'v';
	}

	//enemy
	if (clock % 5 == 0)
		eY++;
	if (clock % 40 == 0 && enemyB == false)
	{
		enemyB = true;
		eX = rand() % (width - 3);
		eY = 0;
	}
	if (enemyB == true && eY == height)
	{
		gameOver = true;
		std::cout << "You have won the game. Congratulations!";
	}
}

int main()
{
	setup();
	while (!gameOver)
	{
		draw();
		input();
		logic();
		Sleep(10);
		clock++;
	}
}
