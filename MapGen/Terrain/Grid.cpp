#include "Grid.h"

//--------------PUBLIC--------------

void CGrid::UpdateMap()
{
	system("cls");

	printf("+");

	for (unsigned int i = 0; i < m_uWidith; ++i)
	{
		printf("-");
	}

	printf("+\n");

	for (unsigned int i = 0; i < m_uHeight; ++i)
	{
		printf("|");

		for (unsigned int j = 0; j < m_uWidith; ++j)
		{
			printf("%s", m_vTiles[Position1D(j, i)]->DrawTile());
		}

		printf("\033[0m|\n");
	}

	printf("+");

	for (unsigned int i = 0; i < m_uWidith; ++i)
	{
		printf("-");
	}

	printf("+\n");

}

CTile* CGrid::GetMiddleTileRange(int _RangeValX, int _RangeValY)
{
	int randomValue = _RangeValX - (rand() % (_RangeValX * 2));
	unsigned int xPos = static_cast<unsigned int>((static_cast<float>(m_uWidith) * 0.5f) + static_cast<float>(randomValue));

	randomValue = _RangeValY - (rand() % (_RangeValY * 2));
	unsigned int yPos = static_cast<unsigned int>((static_cast<float>(m_uHeight) * 0.5f) + static_cast<float>(randomValue));

	return m_vTiles[Position1D(xPos, yPos)];
}

CTile* CGrid::GetUpTile(const CTile* _ThisTile)
{
	int yPos = (_ThisTile->GetPosY() - 1);
	if (yPos < 0) { return nullptr; }

	unsigned int pos = Position1D(_ThisTile->GetPosX(), yPos);
	CTile* Tile = m_vTiles[pos];

	if (Tile == nullptr)
	{
		return nullptr;
	}
	else
	{
		return Tile;
	}
}

CTile* CGrid::GetDownTile(const CTile* _ThisTile)
{
	int yPos = (_ThisTile->GetPosY() + 1);
	if (yPos >= static_cast<int>(m_uHeight)) { return nullptr; }

	unsigned int pos = Position1D(_ThisTile->GetPosX(), yPos);
	CTile* Tile = m_vTiles[pos];

	if (Tile == nullptr)
	{
		return nullptr;
	}
	else
	{
		return Tile;
	}
}

CTile* CGrid::GetLeftTile(const CTile* _ThisTile)
{
	int xPos = (_ThisTile->GetPosX() - 1);
	if (xPos < 0) { return nullptr; }

	unsigned int pos = Position1D(xPos, _ThisTile->GetPosY());
	CTile* Tile = m_vTiles[pos];

	if (Tile == nullptr)
	{
		return nullptr;
	}
	else
	{
		return Tile;
	}
}

CTile* CGrid::GetRightTile(const CTile* _ThisTile)
{
	int xPos = (_ThisTile->GetPosX() + 1);
	if (xPos >= static_cast<int>(m_uWidith)) { return nullptr; }

	unsigned int pos = Position1D(xPos, _ThisTile->GetPosY());
	CTile* Tile = m_vTiles[pos];

	if (Tile == nullptr)
	{
		return nullptr;
	}
	else
	{
		return Tile;
	}
}


//--------------PRIVATE--------------

unsigned int CGrid::Position1D(unsigned int _x, unsigned int _y)
{
	return _x + (_y * m_uWidith);
}

void CGrid::GenerateMap()
{
	for (unsigned int i = 0; i < m_uHeight; ++i)
	{
		for (unsigned int j = 0; j < m_uWidith; ++j)
		{
			m_vTiles.push_back(new CTile(j, i, ETileType::WATER));

			printf("%s", m_vTiles[Position1D(j, i)]->DrawTile());
		}

		printf("\n");
	}

	printf("\033[0m");
}



