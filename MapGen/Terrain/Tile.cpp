#include "Tile.h"
#include <stdlib.h>
#include <cmath>

void CTile::SetupTileDirty(ETileType _eNextTileType, int _BagValue, float _Temp)
{
	m_bIsModified = true;
	m_eTileType = _eNextTileType;
	m_iBagValue = _BagValue;
	m_fTemperature = _Temp;
}

void CTile::SetupTile(ETileType _eNextTileType, float _Temp)
{
	m_eTileType = _eNextTileType;
	m_fTemperature = _Temp;
}

void CTile::ChangeTileType(ETileType _eNextTileType, int _newBagValue)
{
	m_iBagValue = _newBagValue - 1;

	if (m_eTileType != _eNextTileType)
	{
		m_bIsModified = true;
	}

	switch (_eNextTileType)
	{
	case LAVA:
		if (m_iBagValue <= 100)
		{
			m_iBagValue *= 2;
			SetupTile(ROCK, 0);
		}
		else
		{
			SetupTile(LAVA, 1000);
		}
		break;
	case ROCK:
		if (m_iBagValue <= 10)
		{
			m_iBagValue *= 3;
			SetupTile(FOREST, 0);
		}
		else
		{
			SetupTile(ROCK, 1000);
		}
		break;
	case FOREST:
		if (m_iBagValue <= 10)
		{
			m_iBagValue *= 2;
			SetupTile(GRASS, 0);
		}
		else
		{
			SetupTile(FOREST, 1000);
		}
		break;
	case GRASS:
		if (m_iBagValue <= 5)
		{
			SetupTile(SAND, 0);
		}
		else
		{
			SetupTile(GRASS, 1000);
		}
		break;
	case SAND:
		if (m_iBagValue <= 0)
		{
			SetupTile(WATER, 0);
		}
		else
		{
			SetupTile(SAND, 1000);
		}
		break;
	case WATER:
		SetupTile(WATER, 0);
		break;
	default:
		break;
	}

	DrawTile();
}

const char* CTile::DrawTile()
{
	switch (m_eTileType)
	{
	case WATER:
		return CB_WATER;
		break;
	case LAVA:
		return CB_LAVA;
		break;
	case OBSIDIAN:
		return CB_OBSIDIAN;
		break;
	case ROCK:
		return CB_ROCK;
		break;
	case SNOW:
		return CB_SNOW;
		break;
	case ICE:
		return CB_ICE;
		break;
	case SAND:
		return CB_SAND;
		break;
	case GRASS:
		return CB_GRASS;
		break;
	case FOREST:
		return CB_FOREST;
		break;
	}
}
