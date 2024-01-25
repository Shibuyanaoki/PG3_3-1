#include "TitleScene.h"
#include "Novice.h"

void TitleScene::Init()
{
}

void TitleScene::Update()
{
	if (keys_[DIK_SPACE] == 0 && preKeys_[DIK_SPACE]) {
		SceneNo = STAGE;
	}
}

void TitleScene::Draw()
{
}
