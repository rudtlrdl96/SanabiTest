#include "TileActor.h"
#include <GameEngineCore/GameEngineRender.h>
#include "ContentConst.h"

TileActor::TileActor()
{
}

TileActor::~TileActor()
{
}

void TileActor::Start()
{
	int TileSize = static_cast<int>(ContentConst::TileSize);

	TileRender = CreateRender();
	TileRender->SetScale(float4(TileSize, TileSize));
	TileRender->Off();
}