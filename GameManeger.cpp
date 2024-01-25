﻿#include "GameManeger.h"
#include "Novice.h"


GameManeger::GameManeger()
{
	//各シーンの配列
	sceneArr_[TITLE] = std::make_unique<TitleScene>();
	sceneArr_[STAGE] = std::make_unique<StageScene>();
	sceneArr_[CLEAR] = std::make_unique<ClearScene>();

	for (int i = 0; i < SCENEMAX; i++) {
		// ゲームマネージャーのキー全てのシーンに反映させる
		sceneArr_[i]->SetKeys(keys_, preKeys_);
	}

	//初期シーンの設定
	currentSceneNo_ = TITLE;

}

GameManeger::~GameManeger(){}

int GameManeger::Run() {

	while (Novice::ProcessMessage() == 0) {
		Novice::BeginFrame(); //フレームの開始

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
		if (preKeys_[DIK_ESCAPE] == 0 && keys_[DIK_ESCAPE] != 0) {
			break;
		}

	}
	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
