#pragma once
class Terrain{
public:
    Terrain(void);
    ~Terrain(void);
    int getBarrier(int UnitType);
protected:
    int m_Type;
};
class Weather{
public:
    Weather();
    ~Weather();
private:
    int m_Type;
};
