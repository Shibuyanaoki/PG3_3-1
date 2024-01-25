#include "StageScene.h"
#include "Novice.h" 

void StageScene::Init()
{
}

void StageScene::Update()
{

	if (keys_[DIK_SPACE] && preKeys_[DIK_SPACE]) {
		SceneNo = CLEAR;
	}

}

void StageScene::Draw()
{

}
