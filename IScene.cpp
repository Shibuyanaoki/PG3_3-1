#include "IScene.h"

//タイトルシーンで初期化
int IScene::SceneNo = TITLE;

IScene::~IScene()
{
}

int IScene::GetSceneNo()
{
	return SceneNo;
}
