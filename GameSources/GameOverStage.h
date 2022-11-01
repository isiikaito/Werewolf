/*!
@file GameOverStage.h
@brief ゲームオーバー
*/

#pragma once
#include "stdafx.h"

namespace basecross {
	//--------------------------------------------------------------------------------------
	//	ゲームオーバーステージクラス
	//--------------------------------------------------------------------------------------
	class GameOverStage : public Stage {
		//ビューの作成
		void CreateViewLight();
		//スプライトの作成
		void CreateGameOverSprite();


	public:
		//構築と破棄
		GameOverStage() :Stage() {}
		virtual ~GameOverStage() {}
		//初期化
		virtual void OnCreate()override;

	};




}
//end basecross

