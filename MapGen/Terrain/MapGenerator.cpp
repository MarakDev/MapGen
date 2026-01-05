#include "MapGenerator.h"

void CMapGenerator::GenerateTerrain(int _InitialIslandSpawns = 1, int _InitialBagValue = 10, int _UpdateRate = 10)
{
	//spawnea las islas necesarias
	for (; _InitialIslandSpawns > 0; --_InitialIslandSpawns)
	{
		CTile* initTile = m_oGrid->GetMiddleTileRange(m_oGrid->GetWidith() / 3, m_oGrid->GetHeight() / 3);

		initTile->SetupTileDirty(CTile::LAVA, _InitialBagValue, 10000);

		m_vOpenTiles.push_back(initTile);
	}

	int visualUpdate = 0;
	
	while (!m_vOpenTiles.empty())
	{
		CTile* parentTile = m_vOpenTiles.front();

		SelectRandomDirection(parentTile);

		m_vOpenTiles.erase(m_vOpenTiles.begin());

		visualUpdate++;

		if (visualUpdate % _UpdateRate == 0)
		{
			m_oGrid->UpdateMap();
		}
	}

	EnhancedGenerateTerrain();

	m_oGrid->UpdateMap();
}


void CMapGenerator::SelectRandomDirection(CTile* _parentTile)
{
	UPDATE_TILES_RANDOM_ORDER()
}

void CMapGenerator::UpdateTile(CTile* _parentTile, CTile* _thisTile)
{
	if (!_thisTile->GetIsModified())
	{
		int newBagValue = (_parentTile->GetBagValue() / ((rand() % 2) + 1));

		if (newBagValue <= 2)
			newBagValue = 0;
		
		_parentTile->SetBagValue(newBagValue);

		_thisTile->ChangeTileType(_parentTile->GetTileType(), _parentTile->GetBagValue());

		if (_thisTile->GetIsModified())
		{
			m_vOpenTiles.push_back(_thisTile);
		}
	}
}

void CMapGenerator::EnhancedGenerateTerrain()
{
	for (CTile* tile : m_oGrid->GetVectorTiles())
	{
		if (tile->GetTileType() == CTile::WATER)
		{
			int canConvertToSolid = 0;

			if (m_oGrid->GetUpTile(tile) != nullptr)
			{
				if (m_oGrid->GetUpTile(tile)->GetTileType() != CTile::WATER) { ++canConvertToSolid; }
			}
			if (m_oGrid->GetDownTile(tile) != nullptr)
			{
				if (m_oGrid->GetDownTile(tile)->GetTileType() != CTile::WATER) { ++canConvertToSolid; }
			}
			if (m_oGrid->GetLeftTile(tile) != nullptr)
			{
				if (m_oGrid->GetLeftTile(tile)->GetTileType() != CTile::WATER) { ++canConvertToSolid; }
			}
			if (m_oGrid->GetRightTile(tile) != nullptr)
			{
				if (m_oGrid->GetRightTile(tile)->GetTileType() != CTile::WATER) { ++canConvertToSolid; }
			}

			if (canConvertToSolid > 2)
			{
				if (m_oGrid->GetUpTile(tile) != nullptr)
				{
					tile->SetupTileDirty(m_oGrid->GetUpTile(tile)->GetTileType(), 10, 10);
					break;
				}
				if (m_oGrid->GetDownTile(tile) != nullptr)
				{
					tile->SetupTileDirty(m_oGrid->GetDownTile(tile)->GetTileType(), 10, 10);
					break;
				}
				if (m_oGrid->GetLeftTile(tile) != nullptr) 
				{
					tile->SetupTileDirty(m_oGrid->GetLeftTile(tile)->GetTileType(), 10, 10);
					break;
				}
				if (m_oGrid->GetRightTile(tile) != nullptr)
				{
					tile->SetupTileDirty(m_oGrid->GetRightTile(tile)->GetTileType(), 10, 10);
					break;
				}
			}
		}
	}
}
