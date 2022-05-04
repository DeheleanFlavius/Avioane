/*
 * logic.c
 *
 *  Created on: Apr 13, 2022
 *      Author: flavius.dehelean
 */
#include "logic.h"
#include "game.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

uint8_t GetRand(uint8_t min, uint8_t max) /* http://faq.cprogramming.com/cgi-bin/smartfaq.cgi?answer=1042005782&id=1043284385  */
{
	static uint8_t Init = 0;
	uint8_t rc;

	if (Init == 0)
	{
		srand(time(NULL));
		Init = 1;
	}
	rc = (rand() % (max - min + 1) + min);
	return (rc);
}
uint8_t logic()
{
	uint8_t coll, row, x1, y1, x2, y2, x3, y3, a1, a2, a3, generat2 = 0, generat3 = 0;

	for (uint8_t rowI = 0; rowI < 10; rowI++)
	{
		for (uint8_t colI = 0; colI < 10; colI++)
		{
			playerPtr->board[rowI][colI] = 0; //tabla goala
		}
	}
	//avionul 1
	//randomizare a1,x1, y1;
	a1 = GetRand(1, 4);		// directiile posibile ale varfului

	if (a1 == 1)			// a1 avionul 1 orientat in sus
	{
		x1 = GetRand(2, 7); // pzitionarea pilotului pe Axa x spre stanga
		y1 = GetRand(0, 6); // pozitionarea pilotului pe Axa y in jos
	}
	else if (a1 == 2)		// avionul 1 orientat spre dreapta
	{
		x1 = GetRand(3, 9); // pzitionarea pilotului pe Axa x spre stanga
		y1 = GetRand(2, 7); // pzitionarea pilotului pe Axa y in jos
	}
	else if (a1 == 3)		// avionul 1 Pilotul in jos
	{
		x1 = GetRand(2, 7); // pzitionarea pilotului pe Axa x spre stanga
		y1 = GetRand(3, 9); // pzitionarea pilotului pe Axa y in jos
	}
	else if (a1 == 4)		//avionul 1 Pilotul la stanga
	{
		x1 = GetRand(0, 6); //pzitionarea pilotului pe Axa x spre stanga
		y1 = GetRand(2, 7); //pzitionarea pilotului pe Axa y in jos
	}
	row = x1;
	coll = y1;

	if (a1 == 1)
	{
		//varful in sus
		playerPtr->board[row][coll] = 'A';
		playerPtr->board[row - 2][coll + 1] =
		playerPtr->board[row - 1][coll + 1] =
		playerPtr->board[row][coll + 1] =
		playerPtr->board[row + 1][coll + 1] =
		playerPtr->board[row + 2][coll + 1] =
		playerPtr->board[row][coll + 2] =
		playerPtr->board[row - 1][coll + 3] =
		playerPtr->board[row][coll + 3] =
		playerPtr->board[row + 1][coll + 3] = 'a';
	}
	else if (a1 == 2)
	{
		//varful spre dreapta
		playerPtr->board[row][coll] = 'A';
		playerPtr->board[row - 1][coll - 2] =
		playerPtr->board[row - 1][coll - 1] =
		playerPtr->board[row - 1][coll] =
		playerPtr->board[row - 1][coll + 1] =
		playerPtr->board[row - 1][coll + 2] =
		playerPtr->board[row - 2][coll] =
		playerPtr->board[row - 3][coll - 1] =
		playerPtr->board[row - 3][coll] =
		playerPtr->board[row - 3][coll + 1] = 'a';
	}
	else if (a1 == 3)
	{	//varful in jos
		playerPtr->board[row][coll] = 'A';
		playerPtr->board[row - 2][coll - 1] =
		playerPtr->board[row - 1][coll - 1] =
		playerPtr->board[row][coll - 1] =
		playerPtr->board[row + 1][coll - 1] =
		playerPtr->board[row + 2][coll - 1] =
		playerPtr->board[row][coll - 2] =
		playerPtr->board[row - 1][coll - 3] =
		playerPtr->board[row][coll - 3] =
		playerPtr->board[row+ 1][coll - 3] = 'a';
	}
	else if (a1 == 4)
	{	//varful spre stanga
		playerPtr->board[row][coll] = 'A';
		playerPtr->board[row + 1][coll - 2] =
		playerPtr->board[row + 1][coll - 1] =
		playerPtr->board[row + 1][coll] =
		playerPtr->board[row + 1][coll + 1] =
		playerPtr->board[row + 1][coll + 2] =
		playerPtr->board[row + 2][coll] =
		playerPtr->board[row + 3][coll - 1] =
		playerPtr->board[row + 3][coll] =
		playerPtr->board[row + 3][coll + 1] = 'a';
	}

	//avionul 2
	while (!generat2)
	{
		//randomizare a2, x2, y2;
		a2 = GetRand(1, 4);

	if (a2 == 1)
	{
		x2 = GetRand(2, 7); // pzitionarea pilotului pe Axa x spre stanga
		y2 = GetRand(0, 6); // pozitionarea pilotului pe Axa y in jos
	}
	else if (a2 == 2)		// avionul 1 orientat spre dreapta
	{
		x2 = GetRand(3, 9); // pzitionarea pilotului pe Axa x spre stanga
		y2 = GetRand(2, 7); // pzitionarea pilotului pe Axa y in jos
	}
	else if (a2 == 3)		// avionul 1 Pilotul in jos
	{
		x2 = GetRand(2, 7); // pzitionarea pilotului pe Axa x spre stanga
		y2 = GetRand(3, 9); // pzitionarea pilotului pe Axa y in jos
	}
	else if (a2 == 4)		//avionul 1 Pilotul la stanga
	{
		x2 = GetRand(0, 6); //pzitionarea pilotului pe Axa x spre stanga
		y2 = GetRand(2, 7); //pzitionarea pilotului pe Axa y in jos
	}
	row = x2;
	coll = y2;

	if (a2 == 1)//varful in sus
	{
		if ((playerPtr->board[row][coll]
		| playerPtr->board[row - 2][coll + 1]
		| playerPtr->board[row - 1][coll + 1]
		| playerPtr->board[row][coll + 1]
		| playerPtr->board[row + 1][coll + 1]
		| playerPtr->board[row + 2][coll + 1]
		| playerPtr->board[row][coll + 2]
		| playerPtr->board[row - 1][coll + 3]
		| playerPtr->board[row][coll + 3]
		| playerPtr->board[row + 1][coll + 3]) == 0x00)
		{
		playerPtr->board[row][coll] = 'B';
		playerPtr->board[row - 2][coll + 1] =
		playerPtr->board[row - 1][coll + 1] =
		playerPtr->board[row][coll + 1] =
		playerPtr->board[row + 1][coll + 1] =
		playerPtr->board[row + 2][coll + 1] =
		playerPtr->board[row][coll + 2] =
		playerPtr->board[row - 1][coll + 3] =
		playerPtr->board[row][coll + 3] =
		playerPtr->board[row + 1][coll + 3] = 'b';
		generat2 = 1;
		}
	}

	else if (a2 == 2)//varful la dreapta
	{
		if ((playerPtr->board[row][coll]
		| playerPtr->board[row - 1][coll - 2]
		| playerPtr->board[row - 1][coll - 1]
		| playerPtr->board[row - 1][coll]
		| playerPtr->board[row - 1][coll + 1]
		| playerPtr->board[row - 1][coll + 2]
		| playerPtr->board[row - 2][coll]
		| playerPtr->board[row - 3][coll - 1]
		| playerPtr->board[row - 3][coll]
		| playerPtr->board[row - 3][coll + 1]) == 0x00)
		{
		playerPtr->board[row][coll] = 'B';
		playerPtr->board[row - 1][coll - 2] =
		playerPtr->board[row - 1][coll - 1] =
		playerPtr->board[row - 1][coll] =
		playerPtr->board[row - 1][coll + 1] =
		playerPtr->board[row - 1][coll + 2] =
		playerPtr->board[row - 2][coll] =
		playerPtr->board[row - 3][coll - 1] =
		playerPtr->board[row - 3][coll] =
		playerPtr->board[row - 3][coll + 1] = 'b';
		generat2 = 1;
		}
	}

	else if (a2 == 3)//varful in jos
	{
		if ((playerPtr->board[row][coll]
		| playerPtr->board[row - 2][coll - 1]
		| playerPtr->board[row - 1][coll - 1]
		| playerPtr->board[row + 1][coll - 1]
		| playerPtr->board[row + 2][coll - 1]
		| playerPtr->board[row][coll - 2]
		| playerPtr->board[row - 1][coll - 3]
		| playerPtr->board[row][coll - 3]
		| playerPtr->board[row + 1][coll - 3]) == 0x00)
		{
		playerPtr->board[row][coll] = 'B';
		playerPtr->board[row - 2][coll - 1] =
		playerPtr->board[row - 1][coll - 1] =
		playerPtr->board[row][coll - 1] =
		playerPtr->board[row + 1][coll - 1] =
		playerPtr->board[row + 2][coll - 1] =
		playerPtr->board[row][coll - 2] =
		playerPtr->board[row - 1][coll - 3] =
		playerPtr->board[row][coll - 3] =
		playerPtr->board[row + 1][coll - 3] = 'b';
		generat2 = 1;
		}
	}

	else if (a2 == 4)//varful la stanga
	{
		if ((playerPtr->board[row][coll]
		| playerPtr->board[row + 1][coll - 2]
		| playerPtr->board[row + 1][coll - 1]
		| playerPtr->board[row + 1][coll]
		| playerPtr->board[row + 1][coll + 1]
		| playerPtr->board[row + 1][coll + 2]
		| playerPtr->board[row + 2][coll]
		| playerPtr->board[row + 3][coll - 1]
		| playerPtr->board[row + 3][coll]
		| playerPtr->board[row + 3][coll + 1]) ==0x00)
		{
		playerPtr->board[row][coll] = 'B';
		playerPtr->board[row + 1][coll - 2] =
		playerPtr->board[row + 1][coll - 1] =
		playerPtr->board[row + 1][coll] =
		playerPtr->board[row + 1][coll + 1] =
		playerPtr->board[row + 1][coll + 2] =
		playerPtr->board[row + 2][coll] =
		playerPtr->board[row + 3][coll - 1] =
		playerPtr->board[row + 3][coll] =
		playerPtr->board[row + 3][coll + 1] = 'b';
		generat2 = 1;
		}
	}
	else generat2 = 0;
}

	//avionul 3
	while (!generat3)
	{
		//randomizare a3, x3, y3;
		a3 = GetRand(1, 4);

	if (a3 == 1)
	{
		x3 = GetRand(2, 7); // pzitionarea pilotului pe Axa x spre stanga
		y3 = GetRand(0, 6); // pozitionarea pilotului pe Axa y in jos
	}
	else if (a3 == 2)		// avionul 1 orientat spre dreapta
	{
		x3 = GetRand(3, 9); // pzitionarea pilotului pe Axa x spre stanga
		y3 = GetRand(2, 7); // pzitionarea pilotului pe Axa y in jos
	}
	else if (a3 == 3)		// avionul 1 Pilotul in jos
	{
		x3 = GetRand(2, 7); // pzitionarea pilotului pe Axa x spre stanga
		y3 = GetRand(3, 9); // pzitionarea pilotului pe Axa y in jos
	}
	else if (a3 == 4)		//avionul 1 Pilotul la stanga
	{
		x3 = GetRand(0, 6); //pzitionarea pilotului pe Axa x spre stanga
		y3 = GetRand(2, 7); //pzitionarea pilotului pe Axa y in jos
	}
	row = x3;
	coll = y3;

		if (a3 == 1)//varful in sus
		{
		if ((playerPtr->board[row][coll]
		| playerPtr->board[row - 2][coll + 1]
		| playerPtr->board[row - 1][coll + 1]
		| playerPtr->board[row][coll + 1]
		| playerPtr->board[row + 1][coll + 1]
		| playerPtr->board[row + 2][coll + 1]
		| playerPtr->board[row][coll + 2]
		| playerPtr->board[row - 1][coll + 3]
		| playerPtr->board[row][coll + 3]
		| playerPtr->board[row + 1][coll + 3]) == 0x00)
		{
			//varful in sus
		playerPtr->board[row][coll] = 'C';
		playerPtr->board[row - 2][coll + 1] =
		playerPtr->board[row - 1][coll + 1] =
		playerPtr->board[row][coll + 1] =
		playerPtr->board[row + 1][coll + 1] =
		playerPtr->board[row + 2][coll + 1] =
		playerPtr->board[row][coll + 2] =
		playerPtr->board[row - 1][coll + 3] =
		playerPtr->board[row][coll + 3] =
		playerPtr->board[row + 1][coll + 3] = 'c';
		generat3 = 1;
		}
	}

	else if (a3 == 2)//varful la dreapta
	{
		if ((playerPtr->board[row][coll]
		| playerPtr->board[row - 1][coll - 2]
		| playerPtr->board[row - 1][coll - 1]
		| playerPtr->board[row - 1][coll]
		| playerPtr->board[row - 1][coll + 1]
		| playerPtr->board[row - 1][coll + 2]
		| playerPtr->board[row - 2][coll]
		| playerPtr->board[row - 3][coll - 1]
		| playerPtr->board[row - 3][coll]
		| playerPtr->board[row - 3][coll + 1]) == 0x00)
		{
		playerPtr->board[row][coll] = 'C';
		playerPtr->board[row - 1][coll - 2] =
		playerPtr->board[row - 1][coll - 1] =
		playerPtr->board[row - 1][coll] =
		playerPtr->board[row - 1][coll + 1] =
		playerPtr->board[row - 1][coll + 2] =
		playerPtr->board[row - 2][coll] =
		playerPtr->board[row - 3][coll - 1] =
		playerPtr->board[row - 3][coll] =
		playerPtr->board[row - 3][coll + 1] = 'c';
		generat3 = 1;
		}
	}

	else if (a3 == 3)//varful in jos
	{
		if ((playerPtr->board[row][coll]
		| playerPtr->board[row - 2][coll - 1]
		| playerPtr->board[row - 1][coll - 1]
		| playerPtr->board[row + 1][coll - 1]
		| playerPtr->board[row + 2][coll - 1]
		| playerPtr->board[row][coll - 2]
		| playerPtr->board[row - 1][coll - 3]
		| playerPtr->board[row][coll - 3]
		| playerPtr->board[row + 1][coll - 3]) == 0x00)
		{
		playerPtr->board[row][coll] = 'C';
		playerPtr->board[row - 2][coll - 1] =
		playerPtr->board[row - 1][coll - 1] =
		playerPtr->board[row][coll - 1] =
		playerPtr->board[row + 1][coll - 1] =
		playerPtr->board[row + 2][coll - 1] =
		playerPtr->board[row][coll - 2] =
		playerPtr->board[row - 1][coll - 3] =
		playerPtr->board[row][coll - 3] =
		playerPtr->board[row + 1][coll - 3] = 'c';
		generat3 = 1;
		}
	}

	else if (a3 == 4)//varful la stanga
	{
		if ((playerPtr->board[row][coll]
		| playerPtr->board[row + 1][coll - 2]
		| playerPtr->board[row + 1][coll - 1]
		| playerPtr->board[row + 1][coll]
		| playerPtr->board[row + 1][coll + 1]
		| playerPtr->board[row + 1][coll + 2]
		| playerPtr->board[row + 2][coll]
		| playerPtr->board[row + 3][coll - 1]
		| playerPtr->board[row + 3][coll]
		| playerPtr->board[row + 3][coll + 1]) ==0x00)
		{
		playerPtr->board[row][coll] = 'C';
		playerPtr->board[row + 1][coll - 2] =
		playerPtr->board[row + 1][coll - 1] =
		playerPtr->board[row + 1][coll] =
		playerPtr->board[row + 1][coll + 1] =
		playerPtr->board[row + 1][coll + 2] =
		playerPtr->board[row + 2][coll] =
		playerPtr->board[row + 3][coll - 1] =
		playerPtr->board[row + 3][coll] =
		playerPtr->board[row + 3][coll + 1] = 'c';
		generat3 = 1;
		}

	}
		else //incearca alte randomizari
		generat3 = 0;
	}
	return 0;
}
