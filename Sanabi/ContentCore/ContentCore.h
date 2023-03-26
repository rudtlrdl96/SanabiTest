#pragma once
#include <GameEngineCore/GameEngineCore.h>

class ContentCore : public GameEngineCore
{
public:
	static ContentCore& GetInst()
	{
		static ContentCore Core;
		return Core;
	}
public:
	ContentCore();
	~ContentCore();

	ContentCore(const ContentCore& _Other) = delete;
	ContentCore(ContentCore&& _Other) noexcept = delete;
	ContentCore& operator=(const ContentCore& _Other) = delete;
	ContentCore& operator=(ContentCore&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update() override;
	void End() override;
private:

};

