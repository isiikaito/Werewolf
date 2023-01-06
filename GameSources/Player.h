/*!
@file Player.h
@brief プレイヤーなど
*/

#pragma once
#include "stdafx.h"

namespace basecross {

	namespace kaito
	{
		//!前方宣言
		template<class entity_type>
		class State;
		//!前方宣言
		template <class entity_type>
		class StateMachine;
	}

	//--------------------------------------------------------------------------------------
	///	プレイヤー
	//--------------------------------------------------------------------------------------
	enum class PlayerModel {
		human,
		wolf
	};


	class Player : public GameObject
	{
	private:

		int m_playerChange;//!プレイヤーの見た目の状態
		int m_KeyCount;//!鍵を持っている個数カウント
		int m_AlertleveCount;//!警戒度のカウント
		int m_MaxKeyCount;//!鍵の所持数の最大
		const float m_Ded;//!死亡
		int m_PlayerPositionOnSecondMax;//!プレイヤーの位置の配列の最大の長さ
		int m_PlayerHp;//!プレイヤーの体力
		int m_meatCount;//!肉を取得した数
		const int m_reset;//1ループリセット
		float m_wolfPlayerSpeed;//!狼男になったときのスピード
		float m_humanPlayerSpeed;//!人間の時のスピード
		float m_PlayerPositionTime;//!プレイヤーの位置を取得するまでの時間
		float m_wolfHowlingTime;//!狼男が鳴く時間
		float m_disappearTime;//!消える時間
		float m_dedTime;//!プレイヤーが死んでからの時間
		float m_Speed;            //!スピード
		float m_ChangeTime;          //!時間
		float m_GetPlayerPositionTime;//!プレイヤーの位置の取得
		const float m_humanTime;//!人間の時間
		const float m_wolfTime;//!狼の時間
		bool m_IsPlayerFound;//!プレイヤーが見つかった稼働羽化
		bool m_IsPlayerDed;//!プレイヤーが死んだかどうかの判定
		bool m_IsFastHowling;//!初めて狼男が鳴くとき
		bool m_gameOverDrawActive;//!ゲームオーバースプライトの表示
		InputHandlerB<Player> m_InputHandlerB;//!コントローラーのボタンの取得B
		std::vector<Vec3>m_PlayerPositionOnSecond;//!プレイヤーの毎秒ごとの位置の取得
		kaito::StateMachine<Player>* m_StateMachine;//!プレイヤーのステートマシン
		float m_gameTime;
		float m_vibration;//コントローラーの振動
		
		//エフェクト
		shared_ptr<EfkEffect> m_EfkEffect;
		//エフェクト実行オブジェクト
		shared_ptr<EfkPlay> m_EfkPlay;
	public:
		//構築と破棄
		//--------------------------------------------------------------------------------------
		/*!
		@brief	コンストラクタ
		@param[in]	StagePtr	ステージ
		*/
		//--------------------------------------------------------------------------------------
		Player(const shared_ptr<Stage>& StagePtr);
		//--------------------------------------------------------------------------------------
		/*!
		@brief	デストラクタ
		*/
		//--------------------------------------------------------------------------------------
		virtual ~Player() {}

		//アクセサ
		//--------------------------------------------------------------------------------------
		/*!
		@brief	初期化
		*/
		//--------------------------------------------------------------------------------------
		virtual void OnCreate() override;

		//--------------------------------------------------------------------------------------
		/*!
		@brief	更新
		*/
		//--------------------------------------------------------------------------------------
		virtual void OnUpdate();

		//--------------------------------------------------------------------------------------
		/*!
		@brief	プレイヤーが使用するコントローラーの入力
		*/
		//--------------------------------------------------------------------------------------
		Vec2 GetInputState() const;//!プレイヤーが使用するコントローラーの入力

		//--------------------------------------------------------------------------------------
		/*!
		@brief	コントローラから方向ベクトルを得る
		*/
		//--------------------------------------------------------------------------------------
		Vec3 GetMoveVector() const;//!

		//--------------------------------------------------------------------------------------
		/*!
		@brief	プレイヤーの移動
		*/
		//--------------------------------------------------------------------------------------
		void MovePlayer();

		//--------------------------------------------------------------------------------------
		/*!
		@brief	村人を殺す処理
		*/
		//--------------------------------------------------------------------------------------
		void Villagerkiller();

		//--------------------------------------------------------------------------------------
		/*!
		@brief	ハンターを殺す処理
		*/
		//--------------------------------------------------------------------------------------
		void Hunterkiller();

		//--------------------------------------------------------------------------------------
		/*!
		@brief	鍵のスプライトの作成
		*/
		//--------------------------------------------------------------------------------------
		void CreateKeySprite();//!鍵のスプライトの作成

		//--------------------------------------------------------------------------------------
		/*!
		@brief	脱出処理
		*/
		//--------------------------------------------------------------------------------------
		void Escape();

		//--------------------------------------------------------------------------------------
		/*!
		@brief	敵の死体を消す処理
		*/
		//--------------------------------------------------------------------------------------
		void VillagerDisappear();

		//--------------------------------------------------------------------------------------
		/*!
		@brief	敵の死体を消す処理
		*/
		//--------------------------------------------------------------------------------------
		void HunterDisappear();

		//--------------------------------------------------------------------------------------
		/*!
		@brief	コントローラーのボタン判定B
		*/
		//--------------------------------------------------------------------------------------
		void OnPushB();

		shared_ptr<SoundItem>m_Wolk;
		shared_ptr<SoundItem>m_Howling;


		//--------------------------------------------------------------------------------------
		/*!
		@brief	プレイヤーの状態の取得
		*/
		//--------------------------------------------------------------------------------------
		int GetPlayerCange()const
		{
			return m_playerChange;
		}

		//--------------------------------------------------------------------------------------
		/*!
		@brief	プレイヤーの状態の設定
		*/
		//--------------------------------------------------------------------------------------
		void SetPlayerChange(int playerChange)
		{
			m_playerChange = playerChange;
		}

		//--------------------------------------------------------------------------------------
		/*!
		@brief	毎秒ごとのプレイヤーの位置の取得
		*/
		//--------------------------------------------------------------------------------------
		std::vector<Vec3>GetPlayerPositionOnSecond()const
		{
			return m_PlayerPositionOnSecond;
		}

		//--------------------------------------------------------------------------------------
		/*!
		@brief	毎秒ごとのプレイヤーの位置の設定
		*/
		//--------------------------------------------------------------------------------------
		void SetPlayerPositionOnSecond(const std::vector<Vec3>PlayerPositionOnSecond)
		{
			m_PlayerPositionOnSecond = PlayerPositionOnSecond;
		}

		//--------------------------------------------------------------------------------------
		/*!
		@brief	プレイヤーのHP取得
		*/
		//--------------------------------------------------------------------------------------
		int GetPlayerHp()
		{
			return m_PlayerHp;
		}

		//--------------------------------------------------------------------------------------
		/*!
		@brief	プレイヤーのHPの設定
		*/
		//--------------------------------------------------------------------------------------
		void SetPlayerHp(int PlayerHp)
		{
			m_PlayerHp = PlayerHp;
		}

		//--------------------------------------------------------------------------------------
		/*!
		@brief	プレイヤーが見つかった判定の取得
		*/
		//--------------------------------------------------------------------------------------
		bool GetPlayerFound()
		{
			return m_IsPlayerFound;
		}

		//--------------------------------------------------------------------------------------
		/*!
		@brief	プレイヤーが見つかった判定の設定
		*/
		//--------------------------------------------------------------------------------------
		void SetPlayerFound(bool PlayerFound)
		{
			m_IsPlayerFound = PlayerFound;
		}

		//--------------------------------------------------------------------------------------
		/*!
		@brief	スピードの取得
		*/
		//--------------------------------------------------------------------------------------
		float GetSpeed()
		{
			return m_Speed;
		}

		//--------------------------------------------------------------------------------------
		/*!
		@brief	スピードの設定
		*/
		//--------------------------------------------------------------------------------------
		void SetSpeed(float speed)
		{
			m_Speed = speed;
		}

		//--------------------------------------------------------------------------------------
		/*!
		@brief	プレイヤーが死んだかどうかの取得
		*/
		//--------------------------------------------------------------------------------------
		bool GetIsplayerDed()
		{
			return m_IsPlayerDed;
		}

		//--------------------------------------------------------------------------------------
		/*!
		@brief	プレイヤーが死んだかどうかの取得
		*/
		//--------------------------------------------------------------------------------------
		void SetIsplayerDed(bool playerDed)
		{
			m_IsPlayerDed = playerDed;
		}

		//--------------------------------------------------------------------------------------
		/*!
		@brief	ゲームオーバースプライトを表示するかの取得
		*/
		//--------------------------------------------------------------------------------------
		bool GetGameOverDrawActive()
		{
			return m_gameOverDrawActive;
		}

		//--------------------------------------------------------------------------------------
		/*!
		@brief	ゲームオーバースプライトを表示するかの設定
		*/
		//--------------------------------------------------------------------------------------
		void SetGameOverDrawActive(bool gameOverDrawActive)
		{
			m_gameOverDrawActive = gameOverDrawActive;
		}

		//--------------------------------------------------------------------------------------
		/*!
		@brief	ゲームステージの時間
		*/
		//--------------------------------------------------------------------------------------
		float GetGameTime()
		{
			return m_gameTime;
		}

		//--------------------------------------------------------------------------------------
		/*!
		@brief	ゲームステージの時間
		*/
		//--------------------------------------------------------------------------------------
		void SetGameTime(float gameTime)
		{
			m_gameTime = gameTime;
		}


		//--------------------------------------------------------------------------------------
		/*!
		@brief	プレイヤーとカギの衝突判定
		*/
		//--------------------------------------------------------------------------------------
		virtual void OnCollisionEnter(shared_ptr<GameObject>& Other);


		//--------------------------------------------------------------------------------------
		/*!
		@brief	プレイヤーが死んだ時の処理
		*/
		//--------------------------------------------------------------------------------------
		void PlayerDed();

		//--------------------------------------------------------------------------------------
		/*!
		@brief	ゲームオーバーの処理
		*/
		//--------------------------------------------------------------------------------------
		void PlayerGameOver();

		//--------------------------------------------------------------------------------------
		/*!
		@brief	プレイヤーのポジションを一定数取得の処理
		*/
		//--------------------------------------------------------------------------------------
		void GetPlayerPositionBrett();

		//--------------------------------------------------------------------------------------
		/*!
		@brief	敵を倒したときの音
		*/
		//--------------------------------------------------------------------------------------
		void EnemyDedSound();
		
		//--------------------------------------------------------------------------------------
		/*!
		@brief	ステートマシンのアクセッサ
		*/
		//--------------------------------------------------------------------------------------

		const kaito::StateMachine<Player>* GetFSM()const
		{
			return m_StateMachine;
		}

		//--------------------------------------------------------------------------------------
		/*!
		@brief	ステートの変更
		*/
		//--------------------------------------------------------------------------------------

		virtual void ChangeState(kaito::State<Player>* NewState);


		
	};
}
//end basecross

