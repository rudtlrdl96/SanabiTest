#include "Grid.h"
#include <GameEngineBase/GameEngineDebug.h>
#include <GameEngineCore/GameEngineLevel.h>
#include "ContentConst.h"
#include "TileActor.h"

Grid::Grid()
{
}

Grid::~Grid()
{
}

void Grid::ActiveGrid()
{
	UpdateTileActive();

	if (nullptr != UpGrid)
	{
		UpGrid->UpdateTileActive();
	}
	if (nullptr != DownGrid)
	{
		DownGrid->UpdateTileActive();
	}	
	if (nullptr != LeftGrid)
	{
		LeftGrid->UpdateTileActive();
	}	
	if (nullptr != RightGrid)
	{
		RightGrid->UpdateTileActive();
	}
}

void Grid::DisableGrid()
{
	UpdateTileDisable();

	if (nullptr != UpGrid)
	{
		UpGrid->UpdateTileDisable();
	}
	if (nullptr != DownGrid)
	{
		DownGrid->UpdateTileDisable();
	}
	if (nullptr != LeftGrid)
	{
		LeftGrid->UpdateTileDisable();
	}
	if (nullptr != RightGrid)
	{
		RightGrid->UpdateTileDisable();
	}
}

void Grid::SetUpGrid(Grid* const _Grid)
{
	if (nullptr != UpGrid)
	{
		MsgAssert("Up Grid를 중복으로 설정하려 했습니다");
		return;
	}

	UpGrid = _Grid;
}

void Grid::SetDownGrid(Grid* const _Grid)
{
	if (nullptr != DownGrid)
	{
		MsgAssert("Up Grid를 중복으로 설정하려 했습니다");
		return;
	}

	DownGrid = _Grid;
}

void Grid::SetLeftGrid(Grid* const _Grid)
{
	if (nullptr != LeftGrid)
	{
		MsgAssert("Up Grid를 중복으로 설정하려 했습니다");
		return;
	}

	LeftGrid = _Grid;
}

void Grid::SetRightGrid(Grid* const _Grid)
{
	if (nullptr != RightGrid)
	{
		MsgAssert("Up Grid를 중복으로 설정하려 했습니다");
		return;
	}

	RightGrid = _Grid;
}

void Grid::Resize(const int2& _Size)
{
	if (_Size.x == 0 || _Size.y == 0)
	{
		MsgAssert("그리드 사이즈는 0으로 리사이즈 할 수 없습니다.");
		return;
	}

	// 모든 랜더링 오프
	for (size_t y = 0; y < Tiles.size(); y++)
	{
		for (size_t x = 0; x < Tiles[y].size(); x++)
		{
			Tiles[y][x].ActiveRender(false);
		}
	}

	// 만약 부족하다면 리사이즈
	if (Tiles.size() < _Size.y)
	{
		Tiles.resize(_Size.y);
	}

	if (Tiles[0].size() < _Size.x)
	{
		for (size_t y = 0; y < Tiles.size(); y++)
		{
			Tiles[y].resize(_Size.x);
		}
	}

	for (int y = 0; y < Tiles.size(); y++)
	{
		for (int x = 0; x < Tiles[y].size(); x++)
		{
			if (true == Tiles[y][x].IsEmpty())
			{
				TileActor* NewRender = GridLevel->CreateActor<TileActor>();

				NewRender->SetPos(GetTilePos(int2(x, y)));
				Tiles[y][x].LinkTileActor(NewRender);
			}
		}
	}

}

float4 Grid::GetTilePos(const int2& _Index)
{
	float4 ResultPos = GridStartPos;

	float TileSize = static_cast<float>(ContentConst::TileSize);

	ResultPos.x += _Index.x * TileSize;
	ResultPos.y += _Index.y * TileSize;

	return ResultPos;
}

int2 Grid::GetTileIndex(const float4& _Pos)
{
	int2 ResultIndex = { 0, 0 };

	float PosX = _Pos.x - GridStartPos.x;
	float PosY = _Pos.y - GridStartPos.y;

	float TileSize = static_cast<float>(ContentConst::TileSize);
	
	if (PosX < 0)
	{
		float DiffX = (PosX - static_cast<int>(PosX));

		if (DiffX != 0.0f)
		{
			PosX -= TileSize - DiffX;
		}
	}

	if (PosY < 0)
	{
		float DiffY = (PosY - static_cast<int>(PosY));

		if (DiffY != 0.0f)
		{
			PosY -= TileSize - DiffY;
		}
	}

	float CountX = PosX / TileSize;
	float CountY = PosY / TileSize;

	ResultIndex.x = static_cast<int>(CountX);
	ResultIndex.y = static_cast<int>(CountY);

	return ResultIndex;
}

void Grid::UpdateTileActive()
{
	if (false == IsActive)
	{
		for (size_t y = 0; y < Tiles.size(); y++)
		{
			for (size_t x = 0; x < Tiles[y].size(); x++)
			{
				Tiles[y][x].ActiveRender(true);
			}
		}
	}

	IsActive = true;
}

void Grid::UpdateTileDisable()
{
	if (true == IsActive)
	{
		for (size_t y = 0; y < Tiles.size(); y++)
		{
			for (size_t x = 0; x < Tiles[y].size(); x++)
			{
				Tiles[y][x].ActiveRender(false);
			}
		}
	}

	IsActive = false;
}
