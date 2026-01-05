#include <stdio.h>
#include <vector>
#include <time.h>
#include <iostream>

#include "Terrain\MapGenerator.h"


int main()
{
	srand(time(NULL));

	printf("###################################\n");
	printf("#                                 #\n");
	printf("#                                 #\n");
	printf("#         WORLD GENERATOR         #\n");
	printf("#                                 #\n");
	printf("#                                 #\n");
	printf("#            by Marak             #\n");
	printf("#                                 #\n");
	printf("###################################\n");

	printf("\n\nMap Widith: ");
	int widith;
	std::cin >> widith;
	printf("\nMap Height: ");
	int height;
	std::cin >> height;

	printf("\nNumber of Islands: ");
	int nIslands;
	std::cin >> nIslands;

	printf("\nIntial spread value: ");
	int bagValue;
	std::cin >> bagValue;

	printf("\nUpdate rate: ");
	int updateRate;
	std::cin >> updateRate;


	CMapGenerator* mapGen = new CMapGenerator(widith, height);
	mapGen->GenerateTerrain(nIslands, bagValue, updateRate);

	printf("Press any key to continue . . . ");
	getchar();
}