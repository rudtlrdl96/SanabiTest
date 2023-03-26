#include "ContentCore.h"
#include "MapToolLevel.h"

ContentCore::ContentCore()
{
}

ContentCore::~ContentCore()
{
}

void ContentCore::Start()
{
	CreateLevel<MapToolLevel>("MapToolLevel");
	ChangeLevel("MapToolLevel");
}

void ContentCore::Update()
{

}

void ContentCore::End()
{

}