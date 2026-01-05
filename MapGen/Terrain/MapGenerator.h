#pragma once
#include <vector>
#include "Tile.h"
#include "Grid.h"



//MACROS

#define UPDATE_TILE(direction) if (CTile* direction = m_oGrid->Get##direction(_parentTile)) \
	{ \
		UpdateTile(_parentTile, direction); \
	}

/*
	if (CTile* upTile = m_oGrid->GetUpTile(_parentTile))
	{
		UpdateTile(_parentTile, upTile);
	}
*/

#define UPDATE_TILES_RANDOM_ORDER() 	int randomDirection = rand() % 3; \
switch (randomDirection) \
{ \
	case 0: \
		UPDATE_TILE(UpTile); \
		UPDATE_TILE(DownTile); \
		UPDATE_TILE(RightTile); \
		UPDATE_TILE(LeftTile); \
		break; \
	case 1: \
		UPDATE_TILE(DownTile); \
		UPDATE_TILE(UpTile); \
		UPDATE_TILE(LeftTile); \
		UPDATE_TILE(RightTile); \
		break; \
	case 2: \
		UPDATE_TILE(RightTile); \
		UPDATE_TILE(UpTile); \
		UPDATE_TILE(DownTile); \
		UPDATE_TILE(LeftTile); \
		break; \
	case 3: \
		UPDATE_TILE(LeftTile); \
		UPDATE_TILE(UpTile); \
		UPDATE_TILE(DownTile); \
		UPDATE_TILE(RightTile); \
		break; \
	default: \
		break; \
	}

//


class CMapGenerator
{
public:
	CMapGenerator()
	{
		m_oGrid = new CGrid();

	}

	CMapGenerator(unsigned int _Widith, unsigned int _Height)
	{
		m_oGrid = new CGrid(_Widith, _Height);
	}

	~CMapGenerator()
	{
	}

	//
	void GenerateTerrain(int _InitialIslandSpawns, int _InitialBagValue, int _UpdateRate);

private:

	void SelectRandomDirection(CTile* _parentTile);

	void UpdateTile(CTile* _parentTile, CTile* _thisTile);

	void EnhancedGenerateTerrain();
	//Formula para calcular el bag value de cada tile

//variables ------------------>

private:
	CGrid* m_oGrid;
	
	std::vector<CTile*> m_vOpenTiles;
};