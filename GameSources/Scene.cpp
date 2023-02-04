
/*!
@file Scene.cpp
@brief シーン実体
*/

#include "stdafx.h"
#include "Project.h"
#include "DescriptionStage.h"

namespace basecross{

	//--------------------------------------------------------------------------------------
	///	ゲームシーン
	//--------------------------------------------------------------------------------------
	void Scene::RoadTexture(const wstring& TextureName, const wstring& UseTextureName)
	{
		wstring dataDir;
		//サンプルのためアセットディレクトリを取得
		App::GetApp()->GetAssetsDirectory(dataDir);

		//!テクスチャ
		wstring strTexture = dataDir + L"Texture\\" + TextureName;
		App::GetApp()->RegisterTexture(UseTextureName, strTexture);
	}

	void Scene::CreateResourses()
	{
		//!テクスチャ

		//!時計の円盤のスプライト
		RoadTexture(L"Circle.png", L"Circle_TX");
		//!ゲージの背景
		RoadTexture(L"Background.png", L"Background_TX");
		RoadTexture(L"Frame.png", L"Frame_TX");
		RoadTexture(L"FullGage.png", L"Full_TX");
		RoadTexture(L"HeadManCommet1.png", L"HeadManCommet1_TX");
		RoadTexture(L"HeadManCommet2.png", L"HeadManCommet2_TX");
		RoadTexture(L"HeadManCommet3.png", L"HeadManCommet3_TX");

		RoadTexture(L"QuestMessage_Noon.png", L"CommentDay_TX");
		//!昼から夜になったらでるテクスチャ
		RoadTexture(L"QuestMessage_Night.png", L"CommentNignt_TX"); 
		//!数字の取得
		RoadTexture(L"Nomber_3.png", L"NUMBER_TX");
		//!危険度のゲージのスプライト
		RoadTexture(L"Arrow.png", L"Arrow_TX");
		//!警戒度ゲージ
		RoadTexture(L"testGauge.png", L"AlertlevelGaugeGauge_TX");
		//!はてなマークのスプライト
		RoadTexture(L"LoseSightOf.png", L"LoseSightOf_TX");
		//!ビックリマークのスプライト
		RoadTexture(L"Surprised.png", L"Surprised_TX");
		//!時計のスプライト
		RoadTexture(L"Clock.png", L"Clock_TX");
		//!プレイヤーのHPスプライト
		RoadTexture(L"PlayerHp.png", L"PlayerHp_TX");
		//!キースプライト
		RoadTexture(L"key.png", L"KEY_TX");
		//!ゲームクリア画面
		RoadTexture(L"GameClear.png", L"GAMECLEAR_TX");
		//!ゲームオーバー画面
		RoadTexture(L"GameOver.png", L"GAMEOVER_TX");

		RoadTexture(L"Title.jpg", L"MESSAGE_TX");
		//!カギの枠
		RoadTexture(L"ItemField.png", L"ItemField_TX");
		//!説明書1のテクスチャ
		RoadTexture(L"Explanation_01.png", L"DescriptionSprite1_TX");
		//!説明書2のテクスチャ
		RoadTexture(L"Explanation_02.png", L"DescriptionSprite2_TX");
		//!説明書3のテクスチャ
		RoadTexture(L"DescriptionSprite3.png", L"DescriptionSprite3_TX");
		//!説明書4のテクスチャ
		RoadTexture(L"DescriptionSprite4.png", L"DescriptionSprite4_TX");
		
		wstring dataDir;
		//サンプルのためアセットディレクトリを取得
		App::GetApp()->GetAssetsDirectory(dataDir);

	
	
		
	

		//!床のモデル読み込み
		auto staticModelMesh1 = MeshResource::CreateStaticModelMesh(dataDir,L"MayaModel\\" L"StageFloor.bmf");
		App::GetApp()->RegisterResource(L"STAGEFLOOR_MESH", staticModelMesh1);

		//!ボックスの追加
		auto staticModelMesh2 = MeshResource::CreateStaticModelMesh(dataDir, L"MayaModel\\" L"Box.bmf");
		App::GetApp()->RegisterResource(L"BOX_MESH", staticModelMesh2);
	
		//!壁のモデル読み込み
		auto staticModelMesh3 = MeshResource::CreateStaticModelMesh(dataDir, L"MayaModel\\" L"StageWall.bmf");
		App::GetApp()->RegisterResource(L"STAGEWALL_MESH", staticModelMesh3);
	
		//!建物のモデル読み込み
		auto staticModelMesh4 = MeshResource::CreateStaticModelMesh(dataDir, L"MayaModel\\" L"House.bmf");
		App::GetApp()->RegisterResource(L"STAGEBUILDING_MESH", staticModelMesh4);

		//!鍵のモデル読み込み
		auto staticModelMesh5 = MeshResource::CreateStaticModelMesh(dataDir, L"MayaModel\\" L"Key.bmf");
		App::GetApp()->RegisterResource(L"KEY_MESH", staticModelMesh5);

		////!門のモデルの読み込み
		//auto staticModelMesh6 = MeshResource::CreateStaticModelMesh(dataDir, L"MayaModel\\" L"StageGate.bmf");
		//App::GetApp()->RegisterResource(L"STAGEGATE_MESH", staticModelMesh6);

		//!地面のモデルの読み込み
		auto staticModelMesh7 = MeshResource::CreateStaticModelMesh(dataDir, L"MayaModel\\" L"Ground.bmf");
		App::GetApp()->RegisterResource(L"GROUND_MESH", staticModelMesh7);

	
		//!柵のモデルの読み込み
		auto staticModelMesh9 = MeshResource::CreateStaticModelMesh(dataDir, L"MayaModel\\" L"StageFence.bmf");
		App::GetApp()->RegisterResource(L"STAGE_FENCE", staticModelMesh9);

		//!柵のモデルの読み込み
		auto staticModelMesh10 = MeshResource::CreateStaticModelMesh(dataDir, L"MayaModel\\" L"Wood.bmf");
		App::GetApp()->RegisterResource(L"STAGE_WOOD", staticModelMesh10);

	    //!肉のモデルの読み込み
		auto staticModelMesh11 = MeshResource::CreateStaticModelMesh(dataDir, L"MayaModel\\" L"Meat.bmf");
		App::GetApp()->RegisterResource(L"MEAT_MESH", staticModelMesh11);


		//モデル
		//ボーンモデルの通常リソース
		// 敵のアニメーション
		auto humanMultiModelMesh = MeshResource::CreateBoneModelMesh(dataDir, L"MayaModel\\" L"Enemy_Animation.bmf");
		App::GetApp()->RegisterResource(L"Player_WalkAnimation_MESH", humanMultiModelMesh);

		//ボーンモデルのタンジェント付きリソース
		humanMultiModelMesh = MeshResource::CreateBoneModelMeshWithTangent(dataDir, L"MayaModel\\" L"Enemy_Animation.bmf");
		App::GetApp()->RegisterResource(L"Player_WalkAnimation_MESH_WITH_TAN", humanMultiModelMesh);

		// プレイヤー（狼）のアニメーション
		auto playrWolfMultiModelMesh = MeshResource::CreateBoneModelMesh(dataDir, L"MayaModel\\" L"Wolf_Animation.bmf");
		App::GetApp()->RegisterResource(L"PlayerWolf_WalkAnimation_MESH", playrWolfMultiModelMesh);

		playrWolfMultiModelMesh = MeshResource::CreateBoneModelMeshWithTangent(dataDir, L"MayaModel\\" L"Wolf_Animation.bmf");
		App::GetApp()->RegisterResource(L"PlayerWolf_WalkAnimation_MESH_WITH_TAN", playrWolfMultiModelMesh);

		// ハンターのアニメーション
		auto EnemyHunterMultiModelMesh = MeshResource::CreateBoneModelMesh(dataDir, L"MayaModel\\" L"Hunter_Animation.bmf");
		App::GetApp()->RegisterResource(L"EnemyHunter_Animation_MESH", EnemyHunterMultiModelMesh);

		EnemyHunterMultiModelMesh = MeshResource::CreateBoneModelMeshWithTangent(dataDir, L"MayaModel\\" L"Hunter_Animation.bmf");
		App::GetApp()->RegisterResource(L"EnemyHunter_Animation_MESH_WITH_TAN", EnemyHunterMultiModelMesh);

		// 村人のアニメーション
		auto EnemyVillagerMultiModelMesh = MeshResource::CreateBoneModelMesh(dataDir, L"MayaModel\\" L"EnemyVillager_Animation.bmf");
		App::GetApp()->RegisterResource(L"EnemyVillager_WalkAnimation_MESH", EnemyVillagerMultiModelMesh);

		EnemyVillagerMultiModelMesh = MeshResource::CreateBoneModelMeshWithTangent(dataDir, L"MayaModel\\" L"EnemyVillager_Animation.bmf");
		App::GetApp()->RegisterResource(L"EnemyVillager_WalkAnimation_MESH_WITH_TAN", EnemyVillagerMultiModelMesh);

		// プレイヤー（人間）のアニメーション
		auto PlayerMultiModelMesh = MeshResource::CreateBoneModelMesh(dataDir, L"MayaModel\\" L"Player_Animation.bmf");
		App::GetApp()->RegisterResource(L"Player_WalkAnimation2_MESH", PlayerMultiModelMesh);

		PlayerMultiModelMesh = MeshResource::CreateBoneModelMeshWithTangent(dataDir, L"MayaModel\\" L"Player_Animation.bmf");
		App::GetApp()->RegisterResource(L"Player_WalkAnimation2_MESH_WITH_TAN", PlayerMultiModelMesh);

		// 扉のアニメーション
		auto GateMultiModelMesh = MeshResource::CreateBoneModelMesh(dataDir, L"MayaModel\\" L"Gate_Animation.bmf");
		App::GetApp()->RegisterResource(L"GateAnimation_MESH", GateMultiModelMesh);

		GateMultiModelMesh = MeshResource::CreateBoneModelMeshWithTangent(dataDir, L"MayaModel\\" L"Gate_Animation.bmf");
		App::GetApp()->RegisterResource(L"GateAnimation_MESH_WITH_TAN", GateMultiModelMesh);

		//法線マップ
		wstring strTexture = dataDir + L"PlalyerBanpMap.png";
		App::GetApp()->RegisterTexture(L"OBJECT_NORMAL_TX", strTexture);

		//!BGM
		wstring strMusic = dataDir + L"Sound\\" L"BGM.wav";//ゲーム中のBGM
		App::GetApp()->RegisterWav(L"bgm", strMusic);

		 strMusic = dataDir + L"Sound\\" L"MeatEat.wav";//肉を食べる音
		App::GetApp()->RegisterWav(L"MeatEat", strMusic);

		strMusic = dataDir + L"Sound\\" L"WoodBoxBreak.wav";//肉を食べる音
		App::GetApp()->RegisterWav(L"WoodBoxBreak", strMusic);
		
			

		strMusic = dataDir + L"Sound\\" L"Title.wav";//タイトル画面のBGM
		App::GetApp()->RegisterWav(L"TitleBGM", strMusic);

		strMusic = dataDir + L"Sound\\" L"walk.wav";//歩く音
		App::GetApp()->RegisterWav(L"WalkBGM", strMusic);

		wstring decisionWav = dataDir + "Sound\\" L"decision.wav";//ボタンを押したときの音
		App::GetApp()->RegisterWav(L"decision", decisionWav);

		wstring killWav = dataDir + "Sound\\" L"kill.wav";//敵を殺した時の音
		App::GetApp()->RegisterWav(L"kill", killWav);

		wstring howlingWav = dataDir + "Sound\\" L"howling.wav";//狼に変身した時の遠吠え
		App::GetApp()->RegisterWav(L"howling", howlingWav);

		wstring screamWav = dataDir + "Sound\\" L"scream.wav";//村人の叫び声
		App::GetApp()->RegisterWav(L"scream", screamWav);

		wstring acquisitionWav = dataDir + "Sound\\" L"acquisition.wav";//カギを拾う音
		App::GetApp()->RegisterWav(L"acquisition", acquisitionWav);

		wstring firingWav = dataDir + "Sound\\" L"firing.wav";//カギを拾う音
		App::GetApp()->RegisterWav(L"firing", firingWav);

		wstring GameClearWav = dataDir + "Sound\\" L"GameClear.wav";//ゲームクリア音
		App::GetApp()->RegisterWav(L"GameClear", GameClearWav);

		wstring GameOverWav = dataDir + "Sound\\" L"GameOver.wav";//ゲームオーバー音
		App::GetApp()->RegisterWav(L"GameOver", GameOverWav);

		wstring FlipPageWav = dataDir + "Sound\\" L"FlipPage.wav";//ゲームオーバー音
		App::GetApp()->RegisterWav(L"FlipPage", FlipPageWav);

	

	}

	//!駆け付けた敵の作成

	//!敵(スケール、ローテイション、ポジション)の構造体
	struct TransformCreate {
		//!構造体テンプレート
		Vec3 scale = Vec3(0.0f);//!大きさ
		Vec3 rotation = Vec3(0.0f);//!回転
		Vec3 position = Vec3(0.0f);//!位置
		wstring EnemykeyName = L"";//!村人の巡回ルートのキーフレームを取得

		TransformCreate() :
			TransformCreate(Vec3(0.0f), Vec3(0.0f), Vec3(0.0f), wstring(L""))
		{}
		//!構造体の初期化
		TransformCreate(
			const Vec3& scale,
			const Vec3& rotation,
			const Vec3& position,
			const wstring& EnemykeyName
		) :
			scale(scale),
			rotation(rotation),
			position(position),
			EnemykeyName(EnemykeyName)
		{}
	};

	//!敵(スケール、ローテイション、ポジション)の関数
	std::vector<TransformCreate>TransformDate(const wstring& folderName, const wstring& fileName, const wstring& keyName) {
		std::vector<TransformCreate>result;//!変数名
		vector<wstring>LineVec;//!CSVの行単位の配列

		auto& app = App::GetApp();//!アプリの取得
		wstring DataDir;
		App::GetApp()->GetDataDirectory(DataDir);
		auto fullPass = DataDir + folderName + fileName;

		CsvFile csvFile;
		csvFile.SetFileName(fullPass);
		csvFile.ReadCsv();

		csvFile.GetSelect(LineVec, 0, keyName);//!0番目のカラムがL"Villager"である行を抜き出す

		for (auto& v : LineVec)
		{
			vector<wstring>Tokens;//!トークン(カラム)の配置
			Util::WStrToTokenVector(Tokens, v, L',');//!トークン(カラム)単位で文字列を抽出(',')
			//!トークン(カラム)をスケール、回転、位置に読み込む
			Vec3 Scale(
				(float)_wtof(Tokens[1].c_str()),
				(float)_wtof(Tokens[2].c_str()),
				(float)_wtof(Tokens[3].c_str())
			);
			Vec3 Rot;
			//!回転は「XM_PLDIV2」の文字列になっている場合がある
			Rot.x = (Tokens[4] == L"XM_PIDIV2") ? XM_PIDIV2 : (float)_wtof(Tokens[4].c_str());
			Rot.y = (Tokens[5] == L"XM_PIDIV2") ? XM_PIDIV2 : (float)_wtof(Tokens[5].c_str());
			Rot.z = (Tokens[6] == L"XM_PIDIV2") ? XM_PIDIV2 : (float)_wtof(Tokens[6].c_str());

			//!村人の位置
			Vec3 Pos(
				(float)_wtof(Tokens[7].c_str()),
				(float)_wtof(Tokens[8].c_str()),
				(float)_wtof(Tokens[9].c_str())
			);
			wstring	EnemykeyName = Tokens[10];
			result.push_back(TransformCreate(Scale, Rot, Pos, EnemykeyName));

		}

		return result;
	}

	



	//!パトロールポイントの構造体
	struct PointCreate {
		std::vector<Vec3>m_patorlPositions = vector<Vec3>(0);

		PointCreate() :
			PointCreate(vector<Vec3>(0)) {}
		PointCreate(const std::vector<Vec3>& patrolPoints) :
			m_patorlPositions(patrolPoints)
		{}
	};

	//!パトロールポイント
	PointCreate PointDate(const wstring& folderName, const wstring& fileName, const wstring& keyName)
	{
		PointCreate PatorlPoint;

		vector<wstring>LineVec;
		auto& app = App::GetApp();//!アプリの取得
		wstring DataDir;
		App::GetApp()->GetDataDirectory(DataDir);
		auto fullPass = DataDir + folderName + fileName;//!

		CsvFile csvFile;
		csvFile.SetFileName(fullPass);
		csvFile.ReadCsv();

		csvFile.GetSelect(LineVec, 0, keyName);//!0番目のカラムがkeyNameである行を抜き出す
		for (auto& v : LineVec)
		{
			vector<wstring>Tokens;//!トークン(カラム)の配置
			Util::WStrToTokenVector(Tokens, v, L',');//!トークン(カラム)単位で文字列を抽出(',')

			auto& routePositions = PatorlPoint.m_patorlPositions;

			routePositions.push_back(
				Vec3((float)_wtof(Tokens[1].c_str()),
					(float)_wtof(Tokens[2].c_str()),
					(float)_wtof(Tokens[3].c_str())));
		}

		return PatorlPoint;
	}


	void Scene::CreateEnemy()
	{
		
		auto datasHunter = TransformDate(L"csvFolder\\", L"RushedEnemy.csv", L"Hunter");//!ハンターのExcelのデータ
		for (auto& dataHunter : datasHunter)
		{
			auto pointData = PointDate(L"csvFolder\\", L"Point.csv", dataHunter.EnemykeyName);//!敵の巡回ポイントの名前を取り出す
			auto HunterPtr = GetActiveStage()->AddGameObject<Hunter>(dataHunter.scale, dataHunter.rotation, dataHunter.position, pointData.m_patorlPositions);//!増員されるハンターの作成
			GetActiveStage()->AddGameObject<LoseSightOf>(HunterPtr);
			GetActiveStage()->AddGameObject<SurprisedSprite>(HunterPtr);

		}
		
	}

	void Scene::SetAlertlevelCount(int AlertlevelCount)
	{
		//m_alertLevelCountと違うなら
		if (m_AlertlevelCount != AlertlevelCount) {

			//アラートレベルが1なら
			if (AlertlevelCount == 1) {

				//敵の生成
				CreateEnemy();
			}

		}

	}
	void Scene::OnCreate(){
		try {
			CreateResourses();//!リソース作成
			//クリアする色を設定
			Col4 Col;
			Col.set(31.0f / 255.0f, 30.0f / 255.0f, 71.0f / 255.0f, 255.0f / 255.0f);
			SetClearColor(Col);
			//自分自身にイベントを送る
			//これにより各ステージやオブジェクトがCreate時にシーンにアクセスできる

			PostEvent(0.0f, GetThis<ObjectInterface>(), GetThis<Scene>(), L"ToTitleStage");

		}
		catch (...) {
			throw;
		}

	}

	Scene::~Scene() {
	}

	void Scene::OnEvent(const shared_ptr<Event>& event) {
		if (event->m_MsgStr == L"ToGameStage") {
			//最初のアクティブステージの設定
			ResetActiveStage<GameStage>();
		}
		else if (event->m_MsgStr == L"ToTitleStage")//!タイトルステージ
		{
			ResetActiveStage<TitleStage>();
		}
		
		else if (event->m_MsgStr == L"ToGameClearStage")//!ゲームクリアステージ
		{
			ResetActiveStage<GameClearStage>();
		}
		else if (event->m_MsgStr == L"ToDescriptionStage")
		{
			ResetActiveStage<DescriptionStage>();
		}
	}

}
//end basecross
