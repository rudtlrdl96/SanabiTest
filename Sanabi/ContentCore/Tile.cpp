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
		MsgAssert("nullptr TileActor�� ����Ϸ� �߽��ϴ�");
	}

	if (nullptr != RenderActor)
	{
		MsgAssert("�̹� TileActor�� ��ϵ� Ÿ�Ͽ� TileActor�� ����Ϸ� �߽��ϴ�.");
	}

	RenderActor = _RenderActor;
}

void Tile::ActiveRender(bool _Active)
{
	if (nullptr == RenderActor)
	{
		MsgAssert("Ÿ�� ������ ���͸� �������� �ʰ� �����Ϸ� �߽��ϴ�");
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
