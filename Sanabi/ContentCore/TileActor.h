#pragma once
#include <GameEngineCore/GameEngineActor.h>

class GameEngineRender;
class TileActor : public GameEngineActor
{
public:
	TileActor();
	~TileActor();

	TileActor(const TileActor& _Other) = delete;
	TileActor(TileActor&& _Other) noexcept = delete;
	TileActor& operator=(const TileActor& _Other) = delete;
	TileActor& operator=(TileActor&& _Other) noexcept = delete;

protected:
	void Start() override;

private:
	GameEngineRender* TileRender = nullptr;
};