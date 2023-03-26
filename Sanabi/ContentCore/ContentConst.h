#pragma once


class ContentConst
{
public:
	static const size_t TileSize;
protected:

private:
	ContentConst();
	~ContentConst();

	ContentConst(const ContentConst& _Other) = delete;
	ContentConst(ContentConst&& _Other) noexcept = delete;
	ContentConst& operator=(const ContentConst& _Other) = delete;
	ContentConst& operator=(ContentConst&& _Other) noexcept = delete;
};