#pragma once
#include <GameEngineCore/GameEngineLevel.h>

class MapToolLevel : public GameEngineLevel
{
public:
	MapToolLevel();
	~MapToolLevel();

	MapToolLevel(const MapToolLevel& _Other) = delete;
	MapToolLevel(MapToolLevel&& _Other) noexcept = delete;
	MapToolLevel& operator=(const MapToolLevel& _Other) = delete;
	MapToolLevel& operator=(MapToolLevel&& _Other) noexcept = delete;

protected:
	void Loading() override;
	void Update(float _DeltaTime) override;

	void LevelChangeStart(GameEngineLevel* _PrevLevel) {}
	void LevelChangeEnd(GameEngineLevel* _NextLevel) {}

private:

};