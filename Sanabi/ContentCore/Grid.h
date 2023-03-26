#pragma once
#include <vector>
#include <string>
#include "Tile.h"

class GameEngineLevel;
class Grid
{
public:
	Grid();
	~Grid();

	Grid(const Grid& _Other) = delete;
	Grid(Grid&& _Other) noexcept = delete;
	Grid& operator=(const Grid& _Other) = delete;
	Grid& operator=(Grid&& _Other) noexcept = delete;

	inline void SetLevel(GameEngineLevel* _Level)
	{
		GridLevel = _Level;
	}

	void ActiveGrid();
	void DisableGrid();

	void SetUpGrid(Grid* const _Grid);
	void SetDownGrid(Grid* const _Grid);
	void SetLeftGrid(Grid* const _Grid);
	void SetRightGrid(Grid* const _Grid);

	void Resize(const int2& _Size);

	float4 GetTilePos(const int2& _Index);
	int2 GetTileIndex(const float4& _Pos);

protected:

private:
	std::string GridName;
	std::vector<std::vector<Tile>> Tiles;

	GameEngineLevel* GridLevel = nullptr;
	float4 GridStartPos = float4::Zero;

	bool IsActive = false;

	Grid* UpGrid = nullptr;
	Grid* DownGrid = nullptr;
	Grid* LeftGrid = nullptr;
	Grid* RightGrid = nullptr;

	void UpdateTileActive();
	void UpdateTileDisable();
};