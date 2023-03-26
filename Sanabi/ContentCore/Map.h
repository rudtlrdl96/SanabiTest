#pragma once
#include <map>
#include "Grid.h"

class Map
{
public:
	Map();
	~Map();

	Map(const Map& _Other) = delete;
	Map(Map&& _Other) noexcept = delete;
	Map& operator=(const Map& _Other) = delete;
	Map& operator=(Map&& _Other) noexcept = delete;

	bool CanChain(const int2& _Index) const;
	bool CanChain(const float4& _Pos) const
	{
		return CanChain(ToInt2(_Pos));
	}

	bool IsGround(const int2& _Index) const;
	bool IsGround(const float4& _Pos) const
	{
		return IsGround(ToInt2(_Pos));
	}

	void ChangeMainGrid(const std::string_view& _GridName);

	int2 ToInt2(const float4& _WorldPos) const;

protected:

private:
	std::map<std::string, Grid*> Grids;

	Grid* MainGrid = nullptr;
};