#include "StageScene.h"
#include "Novice.h" 
#include "Vector2.h"

void StageScene::Init()
{
	player = { 640,320 };

	enemy = { 0,0 };

	bullet;

	moveE = { 3,3 };

	moveP = { 3,3 };

}

void StageScene::Update()
{

	enemy.x += moveE.x;

	if (enemy.x <= 0) {
		moveE.x += 3;
	}

	if (enemy.x >= 1280) {
		moveE.x-=3;
	}


	if (keys_[DIK_SPACE] && preKeys_[DIK_SPACE] == 0) {
		SceneNo = CLEAR;
	}

}

void StageScene::Draw()
{
	Novice::DrawEllipse((int)enemy.x, (int)enemy.y, (int)radius, (int)radius, 0.0f, RED, kFillModeSolid);
}
