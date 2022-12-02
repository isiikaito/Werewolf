/*!
@file TitleStage.h
@brief 
*/

#pragma once
#include "stdafx.h"

namespace basecross {

	//--------------------------------------------------------------------------------------
	//	タイトルステージクラス
	//--------------------------------------------------------------------------------------
	class TitleStage : public Stage {
	private:
		//入力ハンドラー
		InputHandler<TitleStage> m_InputHandler;

	public:
		//ビューの作成
		void CreateViewLight();
		//スプライトの作成
		void CreateTitleSprite();

		shared_ptr<SoundItem>m_BGM;
		void CreatePlayBGM();//!BGM作成

		//構築と破棄
		TitleStage() :Stage() {}
		virtual ~TitleStage() {}
		//初期化
		virtual void OnCreate()override;
		//更新
		virtual void OnUpdate()override;

		virtual void OnDestroy() override;

		//Aボタン
		void OnPushA();
	};


}
//end basecross
