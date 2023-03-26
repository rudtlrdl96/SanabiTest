#include "Map.h"
#include <GameEngineBase/GameEngineDebug.h>
#include <GameEngineBase/GameEngineString.h>

Map::Map()
{
}

Map::~Map()
{
}

void Map::ChangeMainGrid(const std::string_view& _GridName)
{
	if (nullptr != MainGrid)
	{
		MainGrid->DisableGrid();
	}

	std::string UpperName = GameEngineString::ToUpper(_GridName);

	MainGrid = Grids[UpperName];

	if (nullptr == MainGrid)
	{
		MsgAssert("�ش� �׸���� �������� �ʴ� �׸��� �Դϴ�. [" + UpperName + "]");
		return;
	}

	MainGrid->ActiveGrid();
}

int2 Map::ToInt2(const float4& _WorldPos) const
{
	return int2();
}

bool Map::CanChain(const int2& _Index) const
{
	return false;
}

bool Map::IsGround(const int2& _Index) const
{
	return false;
}
