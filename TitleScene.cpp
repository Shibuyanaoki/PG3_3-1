#include "TitleScene.h"
#include "Novice.h"

void TitleScene::Init()
{
}

void TitleScene::Update()
{

	// キー入力を受け取る
	memcpy(preKeys, keys, 256);
	Novice::GetHitKeyStateAll(keys);

	if (preKeys[DIK_SPACE] == 0 && keys[DIK_SPACE]) {
		SceneNo = STAGE;
	}
}

void TitleScene::Draw()
{
}
