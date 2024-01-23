﻿#pragma once

enum Scene { TITLE, STAGE, CLEAR };


class IScene
{
protected:
	// シーン番号を管理する変数
	static int SceneNo;

public:

	virtual void Init() = 0;

	virtual void Update() = 0;

	virtual void Draw() = 0;  

	virtual ~IScene();

	// シーン番号のゲッター
	int GetSceneNo();


};
