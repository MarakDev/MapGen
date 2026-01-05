#include <vector>
#include <time.h>
#include <iostream>
#include <cstdio>

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

	printf("\n\nMap Widith (20-200): ");
	int widith;
	std::cin >> widith;
	printf("\nMap Height (10-100): ");
	int height;
	std::cin >> height;

	printf("\nNumber of Islands (2-50): ");
	int nIslands;
	std::cin >> nIslands;

	printf("\nIntial spread value (2-50): ");
	int bagValue;
	std::cin >> bagValue;

	printf("\nUpdate rate (2-100): ");
	int updateRate;
	std::cin >> updateRate;


	CMapGenerator* mapGen = new CMapGenerator(widith, height);
	mapGen->GenerateTerrain(nIslands, bagValue, updateRate);

	printf("Press any key to continue . . .");
	std::getchar();
	std::getchar();

}