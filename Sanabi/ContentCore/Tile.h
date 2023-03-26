#pragma once
#include <GameEngineBase/GameEngineMath.h>

class TileActor;
class Tile
{
public:
	Tile();
	~Tile();

	Tile(const Tile& _Other) = delete;
	Tile(Tile&& _Other) noexcept;
	Tile& operator=(const Tile& _Other) = delete;
	Tile& operator=(Tile&& _Other) noexcept;

	void LinkTileActor(TileActor* _RenderActor);
	void ActiveRender(bool _Active);
	
	inline bool IsEmpty() const
	{
		return nullptr == RenderActor;
	}

protected:

private:
	TileActor* RenderActor = nullptr;

	int2 Index = int2(0, 0);
	size_t DataIndex = 0;
};