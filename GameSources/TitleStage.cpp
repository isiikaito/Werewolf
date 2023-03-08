/*!
@file TitleStage.cpp
@brief 
*@author isii kaito
*/


#include "stdafx.h"
#include "Project.h"

namespace basecross {
	
	constexpr int randomspeed = 22;
	constexpr int randomNumber = 3;
	//--------------------------------------------------------------------------------------
	//	タイトルステージクラス
	//--------------------------------------------------------------------------------------
	void TitleStage::CreateViewLight()
	{
		auto PtrView = CreateView<SingleView>();
		//ビューのカメラの設定
		auto PtrCamera = ObjectFactory::Create<Camera>();
		PtrView->SetCamera(PtrCamera);
		PtrCamera->SetEye(Vec3(0.0f, 2.0f, -3.0f));
		PtrCamera->SetAt(Vec3(0.0f, 0.0f, 0.0f));
		//マルチライトの作成
		auto PtrMultiLight = CreateLight<MultiLight>();
		//デフォルトのライティングを指定
		PtrMultiLight->SetDefaultLighting();
	}

	//!スプライトの作成
	void TitleStage::CreateTitleSprite() {
		AddGameObject<TitleSprite>(L"MESSAGE_TX", false,
			Vec2(1300.0f, 800.0f), Vec2(0.0f, 0.0f));

	}

	//!初期化
	void TitleStage::OnCreate() {
		CreateViewLight();
		//スプライトの作成
		CreateTitleSprite();
		CreatePlayBGM();//!BGMの作成
		auto scene = App::GetApp()->GetScene<Scene>();
		scene->SetGameOver(false);
	}

	//!更新
	void TitleStage::OnUpdate() {
		auto& app = App::GetApp();//!アプリの取得
		auto scene = app->GetScene<Scene>();//!シーンの取得
		
		auto deltaTime = app->GetElapsedTime();//!デルタタイムの取得
		m_keyTime += deltaTime * randomspeed;
		srand(std::time(0));
		m_keyNumber = rand() % randomNumber;
		scene->SetKeyNamber(m_keyNumber);


		//!コントローラチェックして入力があればコマンド呼び出し
		m_InputHandler.PushHandle(GetThis<TitleStage>());
	}

	//!BGMの再生
	void TitleStage::CreatePlayBGM()
	{
		auto XAPtr = App::GetApp()->GetXAudio2Manager();
		m_BGM = XAPtr->Start(L"TitleBGM", XAUDIO2_LOOP_INFINITE, 0.5f);
	}

	//! BGMのストップ
	void TitleStage::OnDestroy()
	{
		auto XAPtr = App::GetApp()->GetXAudio2Manager();
		XAPtr->Stop(m_BGM);
	}

	//!Aボタン
	void TitleStage::OnPushA() {
		//!サウンド再生
		auto ptrXA = App::GetApp()->GetXAudio2Manager();
		ptrXA->Start(L"decision", 0, 1.0f);
		PostEvent(0.0f, GetThis<ObjectInterface>(), App::GetApp()->GetScene<Scene>(), L"ToDescriptionStage");
	}


}
//end basecross
