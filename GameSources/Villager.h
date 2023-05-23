/*!
@file Villager.h
@brief 村人の作成
*@author isii kaito
*/

#pragma once
#include "stdafx.h"
#include "BaseEnemy.h"
namespace basecross
{
	//--------------------------------------------------------
	//!村人
	//--------------------------------------------------------
	class Villager :public BaseEnemy
	{
	private:

		std::vector<Vec3> m_patrolPoints;	//!巡回ポイント
		Vec3  m_Position;					//!位置
		Vec3 m_Rotation;					//!回転
		Vec3 m_Scale;						//!大きさ
		int m_playerChange;					//!プレイヤーの状態
		float m_Speed;						//!スピード
		int m_patrolindex;					//!パトロールポイントのインデックス
		float m_StateChangeSize;			//!ステートを切り替える大きさ
		bool m_dedDecision;					//!生死の判定
		int m_damage;						//!プレイヤーに与えるダメージ量


	public:
		//--------------------------------------------------------------------------------------
		/*!
		@brief	コンストラクタ
		@param[in]	StagePtr	ステージ
		*/
		Villager(const shared_ptr<Stage>& StagePtr,
			const Vec3& Scale,
			const Vec3& Rotation,
			const Vec3& Position,
			const std::vector<Vec3>& patrolPoints
		);
		//--------------------------------------------------------------------------------------
		/*!
		@brief	デストラクタ
		*/
		virtual ~Villager(){}
	public:

		//--------------------------------------------------------------------------------------
		/*!
		@brief	村人のスピードの取得
		@return 村人のスピード
		*/
		float GetSpeed()
		{
			return m_Speed;
		}

		//--------------------------------------------------------------------------------------
		/*!
		@brief	村人のスピードの設定
		@引数 村人のスピード
		*/
		void SetSpeed(float VillagerSpeed)
		{
			m_Speed = VillagerSpeed;
		}

		//--------------------------------------------------------------------------------------
		/*!
		@brief	ステートチェンジサイズ
		@return ステートチェンジサイズ
		*/
		float GetStateChangeSize() const {
			return m_StateChangeSize;
		}

		//--------------------------------------------------------------------------------------
		/*!
		@brief	村人を殺す判定
		*/
		void VillagerDed();

		//--------------------------------------------------------------------------------------
		/*!
		@brief	初期化
		*/
		virtual void OnCreate();

		//--------------------------------------------------------------------------------------
		/*!
		@brief	更新
		*/
		virtual void OnUpdate();

		//--------------------------------------------------------------------------------------
		/*!
		@brief	プレイヤーとエネミーの衝突判定
		*/
		virtual void OnCollisionEnter(shared_ptr<GameObject>& Other);
	};



}
//!end basecross
