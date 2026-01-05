#pragma once

#define CB_WATER "\033[48;5;33m "
#define CB_LAVA "\033[48;5;196m "
#define CB_OBSIDIAN "\033[48;5;16m "
#define CB_ROCK "\033[48;5;94m "
#define CB_SNOW "\033[48;5;230m "
#define CB_ICE "\033[48;5;194m "
#define CB_SAND "\033[48;5;228m "
#define CB_GRASS "\033[48;5;40m "
#define CB_FOREST "\033[48;5;22m "


class CTile
{
public:
    enum ETileType
    {
        WATER,
        LAVA,
        OBSIDIAN,
        ROCK,
        SNOW,
        ICE,
        SAND,
        GRASS,
        FOREST,
    };

public:

    CTile() :
        m_vPos{ 0, 0 },
        m_eTileType(WATER),
        m_iBagValue(0),
        m_fTemperature(10)
    {
    };

    CTile(unsigned int _x, unsigned int _y, ETileType _eTileType) :
        m_vPos{ _x, _y },
        m_eTileType(_eTileType),
        m_iBagValue(0),
        m_fTemperature(10)
    {
    };

    ~CTile()
    {
    };

    void SetupTileDirty(ETileType _eNextTileType, int _BagValue, float _Temp);

    void SetupTile(ETileType _eNextTileType, float _Temp);

    void ChangeTileType(ETileType _eNextTileType, int _newBagValue);

    const char* DrawTile();

    //get y sets
    unsigned int GetPosX() const { return m_vPos[0]; }
    unsigned int GetPosY() const { return m_vPos[1]; }
    ETileType GetTileType() const { return m_eTileType; }
    int GetBagValue() const { return m_iBagValue; }
    void SetBagValue(int _newBagValue) { m_iBagValue = _newBagValue; }
    float GetTemperature() const { return m_fTemperature; }
    bool GetIsModified() const { return m_bIsModified; }

private:

    unsigned int m_vPos[2] = {0u, 0u};
    //Bag Value is the replication value of the tiles 0-100
    int m_iBagValue = 0;
    bool m_bIsModified = false;

    ETileType m_eTileType;
    //Temperature goes from -20 to 1000
    float m_fTemperature = 0.f;
};