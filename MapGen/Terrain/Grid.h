#pragma once

#include <vector>
#include "Tile.h"

class CGrid
{
public:
	typedef CTile::ETileType ETileType;

	CGrid()
	{
		GenerateMap();
	}

	CGrid(unsigned int _Widith, unsigned int _Height) :
		m_uWidith(_Widith),
		m_uHeight(_Height)
	{
		GenerateMap();
	}

	~CGrid()
	{
	}


	void UpdateMap();

	CTile* GetMiddleTileRange(int _RangeValX, int _RangeValY);

	CTile* GetUpTile(const CTile* _ThisTile);
	CTile* GetDownTile(const CTile* _ThisTile);
	CTile* GetLeftTile(const CTile* _ThisTile);
	CTile* GetRightTile(const CTile* _ThisTile);

	std::vector<CTile*> GetVectorTiles() { return m_vTiles; }

	unsigned int GetWidith() const { return m_uWidith; }
	unsigned int GetHeight() const { return m_uHeight; }

private:
	unsigned int Position1D(unsigned int _x, unsigned int _y);

	void GenerateMap();

private:
	unsigned int m_uWidith = 100;
	unsigned int m_uHeight = 26;

	std::vector<CTile*> m_vTiles;
};