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

		void  HumanState::Enter(Player* Player)
		{
			auto playerChange = Player->GetPlayerCange();
			playerChange = static_cast<int>(PlayerModel::human);//!状態を狼にする
			Player->SetPlayerChange(playerChange);
			CreateMeat();

		}

		void HumanState::Execute(Player* Player)
		{	
			Player->SetSpeed(m_secondEat);

			auto playerDraw = Player->GetComponent<BcPNTnTBoneModelDraw>();
			auto shadowPtr = Player->GetComponent<Shadowmap>();

			shadowPtr->SetMeshResource(L"Player_WalkAnimation_MESH");
			playerDraw->SetMeshResource(L"Player_WalkAnimation_MESH_WITH_TAN");//!プレイヤーのメッシュの変更

			float elapsedTime = App::GetApp()->GetElapsedTime();
			auto ptrDraw = Player->GetComponent<BcPNTnTBoneModelDraw>();//アニメーション
			ptrDraw->UpdateAnimation(elapsedTime);

			auto gameTime = Player->GetGameTime();

			auto scene = App::GetApp()->GetScene<Scene>();
			m_HumanChangeTime += scene->GetGameTime();
			if (m_HumanChangeTime >= m_maxHumanChangeTime)
			{
				Player->ChangeState(WolfState::Instance());
			}

		}

		void HumanState::Exit(Player* Player)
		{
			m_HumanChangeTime = 0.0f;
		}
		//-------------------------------------------------------------------------


		//!狼男の状態の時----------------------------------------------------------

		void WolfState::MeatEat(Player* Player)
		{


			auto meatCount = Player->GetMeatCount();
			switch (meatCount)
			{
			case(0):
				Player->SetSpeed(m_notEatSpeed);
				break;
			case(1):
				Player->SetSpeed(m_firstEat);
				break;
			case(2):
				Player->SetSpeed(m_secondEat);
				break;
			case(3):
				Player->SetSpeed(m_thirdEat);
				break;
			}
		}
		WolfState* WolfState::Instance()
		{
			static WolfState instance;
			return &instance;
		}

		void WolfState::Enter(Player* Player)
		{
			auto playerChange = Player->GetPlayerCange();
			playerChange = static_cast<int>(PlayerModel::wolf);//!状態を狼にする
			Player->SetPlayerChange(playerChange);

			//サウンド再生
			auto ptrXA = App::GetApp()->GetXAudio2Manager();
			ptrXA->Start(L"howling", 0, 1.0f);

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
			m_WolfChangeTime = 0.0f;
			Player->SetMeatCount(0);
		}
	}
}