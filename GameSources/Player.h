/*!
@file Player.h
@brief プレイヤーなど
*/

#pragma once
#include "stdafx.h"

namespace basecross{

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
		float m_Speed;            //!スピード
		float m_ChangeTime;          //!時間
		float m_GetPlayerPositionTime;//!プレイヤーの位置の取得
		int m_playerChange;//!プレイヤーの見た目の状態
		int m_KeyCount;//!鍵を持っている個数カウント
		const float m_humanTime;//!人間の時間
		const float m_wolfTime;//!狼の時間
		const int m_reset;//1ループリセット
		int m_MaxKeyCount;//!鍵の所持数の最大
		int m_Ded;//!敵の死亡
		int m_PlayerPositionOnSecondMax;//!プレイヤーの位置の配列の最大の長さ
		std::vector<Vec3>m_PlayerPositionOnSecond;//!プレイヤーの毎秒ごとの位置の取得
		float m_PlayerPositionTime;//!プレイヤーの位置を取得するまでの時間

	
		InputHandlerB<Player> m_InputHandlerB;//!コントローラーのボタンの取得B


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
		//初期化
		virtual void OnCreate() override;
		//更新
		virtual void OnUpdate() ;
        Vec2 GetInputState() const;//!プレイヤーが使用するコントローラーの入力
		Vec3 GetMoveVector() const;//!コントローラから方向ベクトルを得る
		void MovePlayer();         //!プレイヤーの移動
		void Villagerkiller();//!村人を殺す処理
		void CreateKeySprite();//!鍵のスプライトの作成
		void AppearanceChange();//!プレイヤーの見た目の変化
		void OnPushB();//!コントローラーのボタン判定B

        //!プレイヤーの状態の取得
		int GetPlayerCange()const
		{
			return m_playerChange;
		}

		//!プレイヤーの状態の設定
		void SetPlayerChange(int playerChange)
		{
			m_playerChange = playerChange;
		}

		//!毎秒ごとのプレイヤーの位置の取得
		std::vector<Vec3>GetPlayerPositionOnSecond()const
		{
			return m_PlayerPositionOnSecond;
		}

		//!毎秒ごとのプレイヤーの位置の設定
		void SetPlayerPositionOnSecond(const std::vector<Vec3>PlayerPositionOnSecond)
		{
			m_PlayerPositionOnSecond = PlayerPositionOnSecond;
		}


		virtual void OnCollisionEnter(shared_ptr<GameObject>& Other);//プレイヤーとカギの衝突判定
	};
}
//end basecross

