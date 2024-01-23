﻿#include "GameManeger.h"
#include "Novice.h"


GameManeger::GameManeger()
{
	//各シーンの配列
	sceneArr_[TITLE] = std::make_unique<TitleScene>();
	sceneArr_[STAGE] = std::make_unique<StageScene>();
	sceneArr_[CLEAR] = std::make_unique<ClearScene>();

	//初期シーンの設定

	currentSceneNo_ = TITLE;

}

GameManeger::~GameManeger(){}

int GameManeger::Run() {

	while (Novice::ProcessMessage() == 0) {
		Novice::BeginFrame(); //フレームの開始


		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		//シーンチェック
		precSceneNo_ = currentSceneNo_;
		currentSceneNo_ = sceneArr_[currentSceneNo_]->GetSceneNo();

		//シーン変更チェック
		if (precSceneNo_ != currentSceneNo_) {
			sceneArr_[currentSceneNo_]->Init();
		}

		// 更新処理
		sceneArr_[currentSceneNo_]->Update(); //シーンごとの更新処理

		// 描画処理
		sceneArr_[currentSceneNo_]->Draw();

		Novice::EndFrame();	//フレームの終了

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}

	}
}
