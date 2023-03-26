#include "Tile.h"
#include <GameEngineBase/GameEngineDebug.h>
#include "TileActor.h"

Tile::Tile()
{
}

Tile::~Tile()
{
	if (nullptr != RenderActor)
	{
		RenderActor->Death();
	}
}

Tile::Tile(Tile&& _Other) noexcept
{
	RenderActor = _Other.RenderActor;
	_Other.RenderActor = nullptr;
}

Tile& Tile::operator=(Tile&& _Other) noexcept
{
	RenderActor = _Other.RenderActor;
	_Other.RenderActor = nullptr;

	return *this;
}

void Tile::LinkTileActor(TileActor* _RenderActor)
{
	if (nullptr == _RenderActor)
	{
		MsgAssert("nullptr TileActor를 등록하려 했습니다");
	}

	if (nullptr != RenderActor)
	{
		MsgAssert("이미 TileActor가 등록된 타일에 TileActor를 등록하려 했습니다.");
	}

	RenderActor = _RenderActor;
}

void Tile::ActiveRender(bool _Active)
{
	if (nullptr == RenderActor)
	{
		MsgAssert("타일 랜더링 액터를 설정하지 않고 참조하려 했습니다");
		return;
	}

	if (true == _Active)
	{
		RenderActor->On();
	}
	else
	{
		RenderActor->Off();
	}
}
