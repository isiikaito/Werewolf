/*!
@file BaseEnemy.h
@brief 敵の作成
@autohor isii kaito
*/
#pragma once
#include "stdafx.h"

//!抽象クラス
namespace basecross
{
	namespace kaito
	{
		//!前方宣言
		template<class entity_type>
		class State;
		//!前方宣言
		template <class entity_type>
		class StateMachine;
	}

	class BaseEnemy :public GameObject
	{
		//!ステートマシーン
		kaito::StateMachine<BaseEnemy>* m_StateMachine;//!ステートマシンクラスのインスタンスの生成
		std::vector<Vec3>m_EnemyPatrolPoints;//!敵の巡回ポイント
		Vec3 m_Force;//!フォース
		Vec3 m_Velocity;//!速度
		float m_StateChangeSize;//!ステートの変更
		float m_MaxSpeed;//!最大の速度
		int m_Enemypatorolindex;//!敵の巡回ポイントの数

	protected:
		//!構造と破棄
		BaseEnemy(const shared_ptr<Stage>& StagePtr);
		virtual ~BaseEnemy()noexcept = default;//!デストラクタ

	public:
		//!アクセッサ

		//!ステートマシーンのアクセッサ
		const kaito::StateMachine<BaseEnemy>* GetFSM()const
		{
			return m_StateMachine;
		}
		//!ステートを変更する長さの取得
		float GatStateChangeSize()const
		{
			return m_StateChangeSize;
		}

		//!ステートを変更する長さの設定
		void SetStageChangeSize(float& ChangeSize)
		{
			m_StateChangeSize = ChangeSize;
		}

		//!力の取得
		const Vec3& GetForce()const
		{
			return m_Force;
		}

		//!力の設定
		void SetForce(const Vec3& f)
		{
			m_Force = f;
		}

		//!力の追加
		void AddForce(const Vec3& f)
		{
			m_Force += f;
		}

		//!現在の速度の取得
		const Vec3& GetVelocity()const
		{
			return m_Velocity;
		}

		//!現在の速度の設定
		void SetVelocity(const Vec3& v)
		{
			m_Velocity = v;
		}

		//!最大の速度の取得
		float& GetMaxSpeed()
		{
			return m_MaxSpeed;
		}

		//!敵の巡回ポイントの取得
		std::vector<Vec3>GetEnemyPatorolPoints()const
		{
			return m_EnemyPatrolPoints;
		}

		//!敵の巡回ポイントの設定
		void SetpatorolPoints(const std::vector<Vec3>& path)
		{
			m_EnemyPatrolPoints = path;
		}

		//!敵の巡回ポイント数の取得
		int GetEnemyPatorolindex()
		{
			return m_Enemypatorolindex;
		}

		//!敵の巡回ポイント数の設定
		void SetEnemyPatorolindex(int& patrolindex)
		{
			m_Enemypatorolindex = patrolindex;
		}
		
		//!適応力
		void ApplyForce();
		virtual void ChangeState(kaito::State<BaseEnemy>* NewState);
		shared_ptr<GameObject>GetTarget()const;
		virtual void OnCreate()override {};
		virtual void OnUpdate()override;
	};

}
