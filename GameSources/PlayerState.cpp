#include "stdafx.h"
#include "Project.h"
#include "Utility.h"
#include "PlayerState.h"
#include "Meat.h"

namespace basecross
{
	namespace kaito
	{
		constexpr float m_maxHumanChangeTime = 31.0f;
		constexpr float m_maxWolfChangeTime = 61.0f;
		constexpr int randomNumber = 2;
		constexpr float m_MeatTimeSpeed = 22.0f;
		constexpr float m_notEatSpeed = 10.0f;
		constexpr float m_firstEat = 15.0f;
		constexpr float m_secondEat = 20.0f;
		constexpr float m_thirdEat = 23.0f;



		//!人間状態の時----------------------------------------------------------
		//!インスタンスの生成(実体の作成)
		HumanState* HumanState::Instance()
		{
			static HumanState instance;
			return &instance;
		}

		void HumanState::ReadCsv(const wstring& FileNume)
		{
			wstring DataDir;
			App::GetApp()->GetDataDirectory(DataDir);
			auto scene = App::GetApp()->GetScene<Scene>();

			//!シーンの取得
			m_MeatNumber = scene->GetMeatNamber();

			// フォルダの指定
			auto csvDirectory = DataDir + L"csvFolder\\";
			//!MetaPositonファイルの読み込み
			m_MeatPositon.SetFileName(csvDirectory + FileNume + Util::IntToWStr(m_MeatNumber) + L".csv");
			m_MeatPositon.ReadCsv();

			m_HumanChangeTime = 0.0f;

		}

		void HumanState::CreateMeat()
		{

			ReadCsv(L"MeatPosition");

			//!肉の削除
			auto& app = App::GetApp();//!アプリの取得
			auto Stage = app->GetScene<Scene>()->GetActiveStage();//!ステージの取得
			auto& Objects = Stage->GetGameObjectVec();//!ステージの中のオブジェクトを取得

			//CSVの全体の配列
			//CSVからすべての行を抜き出す
			auto& LineVec = m_MeatPositon.GetCsvVec();

			for (size_t i = 0; i < LineVec.size(); i++) {
				//トークン（カラム）の配列
				vector<wstring> Tokens;
				//トークン（カラム）単位で文字列を抽出(L','をデリミタとして区分け)
				Util::WStrToTokenVector(Tokens, LineVec[i], L',');
				for (size_t j = 0; j < Tokens.size(); j++) {
					//XとZの位置を計算
					float XPos = (float)((int)j - 8.6f) * 10.0f;
					float ZPos = (float)(8.6f - (int)i) * 10.0f;
					if (Tokens[j] == L"5")//5の時にゲームステージに追加
					{
						Stage->AddGameObject<Meat>(Vec3(5.0f, 5.0f, 5.0f), Vec3(0.0f, 0.0f, 0.0f), Vec3(XPos, 4.0f, ZPos));
					}
				}
			}
		}

		void HumanState::CreateWoodBox()
		{

			auto& app = App::GetApp();//!アプリの取得
			auto Stage = app->GetScene<Scene>()->GetActiveStage();//!ステージの取得
			auto& Objects = Stage->GetGameObjectVec();//!ステージの中のオブジェクトを取得

			wstring DataDir;
			App::GetApp()->GetDataDirectory(DataDir);
			auto scene = App::GetApp()->GetScene<Scene>();


			// フォルダの指定
			auto csvDirectory = DataDir + L"csvFolder\\";
			//!MetaPositonファイルの読み込み
			m_GameStageCsvD.SetFileName(csvDirectory + L"GameStageD.csv");
			m_GameStageCsvD.ReadCsv();



			//CSVの全体の配列
		//CSVからすべての行を抜き出す
			auto& LineVec = m_GameStageCsvD.GetCsvVec();
			for (size_t i = 0; i < LineVec.size(); i++) {
				//トークン（カラム）の配列
				vector<wstring> Tokens;
				//トークン（カラム）単位で文字列を抽出(L','をデリミタとして区分け)
				Util::WStrToTokenVector(Tokens, LineVec[i], L',');
				for (size_t j = 0; j < Tokens.size(); j++) {
					//XとZの位置を計算
					float XPos = (float)((int)j - 8.6f) * 10.0f;
					float ZPos = (float)(8.6f - (int)i) * 10.0f;
					if (Tokens[j] == L"3")//3の時にゲームステージに追加
					{
						Stage->AddGameObject<WoodenBox>(Vec3(9.0f, 9.0f, 9.0f), Vec3(0.0f, 0.0f, 0.0f), Vec3(XPos, 3.0f, ZPos));
					}
				}
			}
		}

		void  HumanState::Enter(Player* Player)
		{
			auto playerChange = Player->GetPlayerCange();
			playerChange = static_cast<int>(PlayerModel::human);//!状態を狼にする
			Player->SetPlayerChange(playerChange);
			CreateMeat();
			Player->SetMeatCount(0);
			Player->SetPlayerTaskDay(true);

			CreateWoodBox();//!木箱の作成
			
		}

		void HumanState::Execute(Player* Player)
		{	


			Player->SetSpeed(m_secondEat);

			auto playerDraw = Player->GetComponent<BcPNTnTBoneModelDraw>();//!描画コンポーネントの取得
			auto shadowPtr = Player->GetComponent<Shadowmap>();//!シャドウコンポーネントの取得

			shadowPtr->SetMeshResource(L"Player_WalkAnimation_MESH");
			playerDraw->SetMeshResource(L"Player_WalkAnimation_MESH_WITH_TAN");//!プレイヤーのメッシュの変更

			float elapsedTime = App::GetApp()->GetElapsedTime();
			auto ptrDraw = Player->GetComponent<BcPNTnTBoneModelDraw>();//アニメーション
			ptrDraw->UpdateAnimation(elapsedTime);//!アニメーションの更新

			auto gameTime = Player->GetGameTime();//!ゲームの時間を取得する

			auto scene = App::GetApp()->GetScene<Scene>();
			m_HumanChangeTime += scene->GetGameTime();//!ゲームの時間を変数に足す
			//!ゲーム時間が30秒経過したら
			if (m_HumanChangeTime >= m_maxHumanChangeTime)
			{
				Player->ChangeState(HumanChangeDirectingState::Instance());//!狼のステートに変更
			}

		}

		void HumanState::Exit(Player* Player)
		{
			m_HumanChangeTime = 0.0f;//!人間の時の時間を0秒にする

			
		}
		//-------------------------------------------------------------------------







		//!狼男の状態の時----------------------------------------------------------

		void WolfState::MeatEat(Player* Player)
		{


			auto meatCount = Player->GetMeatCount();
			switch (meatCount)
			{
			case(static_cast<int>(EatCondition::notEat)):
				Player->SetSpeed(m_notEatSpeed);
				break;
			case(static_cast<int>(EatCondition::firstEat)):
				Player->SetSpeed(m_firstEat);
				break;
			case(static_cast<int>(EatCondition::secondEat)):
				Player->SetSpeed(m_secondEat);
				break;
			case(static_cast<int>(EatCondition::thirdEat)):
				Player->SetSpeed(m_thirdEat);
				break;
			}
		}

		void WolfState::RemoveWoodBox()
		{
			//!木の箱の削除
			auto& app = App::GetApp();//!アプリの取得
			auto Stage = app->GetScene<Scene>()->GetActiveStage();//!ステージの取得
			auto& Objects = Stage->GetGameObjectVec();//!ステージの中のオブジェクトを取得

			for (auto& Obj : Objects)//!オブジェクトの要素分
			{
				auto stageMeat = dynamic_pointer_cast<WoodenBox>(Obj);//!建物の取得
				if (stageMeat)
				{
					Stage->RemoveGameObject<WoodenBox>(Obj);
				}
			}
		}

		void WolfState::RemoveMeat()
		{
			//!肉の削除
			auto& app = App::GetApp();//!アプリの取得
			auto Stage = app->GetScene<Scene>()->GetActiveStage();//!ステージの取得
			auto& Objects = Stage->GetGameObjectVec();//!ステージの中のオブジェクトを取得

			for (auto& Obj : Objects)//!オブジェクトの要素分
			{
				auto stageMeat = dynamic_pointer_cast<Meat>(Obj);//!建物の取得
				if (stageMeat)
				{
					Stage->RemoveGameObject<Meat>(Obj);
				}
			}
		}

		WolfState* WolfState::Instance()
		{
			static WolfState instance;
			return &instance;
		}

		void WolfState::Enter(Player* Player)
		{
			Player->SetPlayerTaskNight(true);

			auto playerChange = Player->GetPlayerCange();
			playerChange = static_cast<int>(PlayerModel::wolf);//!状態を狼にする
			Player->SetPlayerChange(playerChange);

			
			//サウンド再生
			auto& ptrXA = App::GetApp()->GetXAudio2Manager();
			ptrXA->Start(L"howling", 0, 1.0f);

			RemoveMeat();

			m_WolfChangeTime = 0.0f;
		}

		void WolfState::Execute(Player* Player)
		{


			auto WolfPlayerDraw = Player->GetComponent<BcPNTnTBoneModelDraw>();//!プレイヤーの描画コンポ―ネントを取得
			auto shadowPtr = Player->GetComponent<Shadowmap>();
			shadowPtr->SetMeshResource(L"PlayerWolf_WalkAnimation_MESH");
			WolfPlayerDraw->SetMeshResource(L"PlayerWolf_WalkAnimation_MESH_WITH_TAN");//!プレイヤーのメッシュの変更

			float elapsedTime = App::GetApp()->GetElapsedTime();
			auto ptrDraw = Player->GetComponent<BcPNTnTBoneModelDraw>();//アニメーション
			ptrDraw->UpdateAnimation(elapsedTime);

			auto scene = App::GetApp()->GetScene<Scene>();
			m_WolfChangeTime += scene->GetGameTime();
			if (m_WolfChangeTime >= m_maxHumanChangeTime)
			{
				Player->ChangeState(HumanState::Instance());
			}
			MeatEat(Player);

		}

		void WolfState::Exit(Player* Player)
		{
			auto scene = App::GetApp()->GetScene<Scene>();

			m_WolfChangeTime = 0.0f;
			Player->SetMeatCount(0);
			m_Date++;
			scene->SetDate(m_Date);
			RemoveWoodBox();

			//エフェクトのプレイ
			auto Ptr = Player->GetComponent<Transform>();
			auto TransformEfkInterface = Player->GetTypeStage<GameStage>()->GetEfkInterface();
			Player->SetTransformEfkPlay(ObjectFactory::Create<EfkPlay>(Player->GetTransformEfkEffect(), Ptr->GetPosition()));
		
		}

		//!人間から狼に変身するときの演出ステート-------------------------------------------------
		HumanChangeDirectingState* HumanChangeDirectingState::Instance()
		{
			static HumanChangeDirectingState instance;
			return &instance;
		}

		void HumanChangeDirectingState::Enter(Player* Player)
		{
			Player->SetSpeed(0.0f);
			//エフェクトのプレイ
			auto Ptr = Player->GetComponent<Transform>();
			auto TransformEfkInterface = Player->GetTypeStage<GameStage>()->GetEfkInterface();
			//m_TransformEfkPlay = ObjectFactory::Create<EfkPlay>(m_TransformEfkEffect, Ptr->GetPosition());
			Player->SetTransformEfkPlay(ObjectFactory::Create<EfkPlay>(Player->GetTransformEfkEffect(), Ptr->GetPosition()));
		}

		void HumanChangeDirectingState::Execute(Player* Player)
		{
			//!人から狼になるときのアニメーションモデル
			//! 
			auto scene = App::GetApp()->GetScene<Scene>();
			m_humanChangeDirectingTiem += scene->GetGameTime();//!ゲームの時間を変数に足す
			//if (m_humanChangeDirectingTiem>=2.0f)
			{
				Player->ChangeState(WolfState::Instance());//!狼のステートに変更
			}
		}

		void HumanChangeDirectingState::Exit(Player* Player)
		{
			m_humanChangeDirectingTiem = 0.0f;
		}
		//!----------------------------------------------------------

	}
}