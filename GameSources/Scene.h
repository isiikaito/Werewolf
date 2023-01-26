/*!
@file Scene.h
@brief シーン
*/
#pragma once

#include "stdafx.h"

namespace basecross{

	//--------------------------------------------------------------------------------------
	///	ゲームシーン
	//--------------------------------------------------------------------------------------
	class Scene : public SceneBase{
	private:
		
		int m_keyNamber;
		int m_AlertlevelCount;//!警戒度の数字
		bool m_IsGameOver;//!ゲームオーバーしたかどうか
		bool m_IsGameOverSprite;//!ゲームオーバースプライトの表示ができているか
		float m_gameStageTime;//!昼と夜の時間
		int m_meatNumber;//!肉の位置が保存されたCSVの数字
		int m_date;//!現在の日付
		bool m_IsplayerChangeDirecting;//!プレイヤーの変身するかどうか
		float m_dayTime;
		float m_playerConditionTime;//!プレイヤーの状態の時間
	public:

		void CreateResourses();//リソース
		//----------------------------------------------------------------------(----------------
		/*!
		@brief コンストラクタ
		*/
		//--------------------------------------------------------------------------------------
		Scene() :SceneBase(), m_AlertlevelCount(0), m_date(0), m_playerConditionTime(0.0f), m_IsplayerChangeDirecting(0.0f), m_IsGameOver(false), m_dayTime(0.0f), m_IsGameOverSprite(false), m_gameStageTime(0.0f), m_keyNamber(0), m_meatNumber(0) {}
		//--------------------------------------------------------------------------------------
		/*!
		@brief デストラクタ
		*/
		//--------------------------------------------------------------------------------------
		virtual ~Scene();
		//--------------------------------------------------------------------------------------	
		/*!
		@brief 初期化
		@return	なし
		*/
		//--------------------------------------------------------------------------------------
		virtual void OnCreate() override;
		
		//--------------------------------------------------------------------------------------
		/*!
		@brief イベント取得
		@return	なし
		*/
		//--------------------------------------------------------------------------------------
		virtual void OnEvent(const shared_ptr<Event>& event) override;
		//--------------------------------------------------------------------------------------
		/*!
		@brief 警戒度の取得
		@return	警戒度のカウント
		*/
		//--------------------------------------------------------------------------------------
		int GetAlertlevelCount()
		{
			return m_AlertlevelCount;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief 警戒度の設定
		@return	なし
		*/
		//--------------------------------------------------------------------------------------
		void SetAlertlevelCount(int AlertlevelCount);
		void CreateEnemy();

		//--------------------------------------------------------------------------------------
		/*!
		@brief ゲームオーバーの取得
		@return	ゲームオーバーしたかどうか
		*/
		//--------------------------------------------------------------------------------------
		bool GetGameOver()
		{
			return m_IsGameOver;
		}
		
		//--------------------------------------------------------------------------------------
		/*!
		@brief ゲームオーバーの設定
		@return	ゲームオーバーしたかどうか
		*/
		//--------------------------------------------------------------------------------------
		void SetGameOver(bool gameOver)
		{
			m_IsGameOver = gameOver;
		}

		//--------------------------------------------------------------------------------------
		/*!
		@brief ゲームオーバースプライト表示の取得
		@return	ゲームオーバーしたかどうか
		*/
		//--------------------------------------------------------------------------------------
		bool GetGameOverSprite()
		{
			return m_IsGameOverSprite;
		}

		//--------------------------------------------------------------------------------------
		/*!
		@brief ゲームオーバースプライト表示の設定
		@return	ゲームオーバーしたかどうか
		*/
		//--------------------------------------------------------------------------------------
		void SetGameOverSprite(bool gameOverSprite)
		{
			m_IsGameOverSprite = gameOverSprite;
		}

		//--------------------------------------------------------------------------------------
		/*!
		@brief 鍵のcsvのナンバーの取得
		@return	ゲームオーバーしたかどうか
		*/
		//--------------------------------------------------------------------------------------
		int GetKeyNamber()
		{
			return m_keyNamber;
		}

		//--------------------------------------------------------------------------------------
	    /*!
	    @brief 鍵のcsvのナンバーの設定
	    @return	ゲームオーバーしたかどうか
	    */
	    //--------------------------------------------------------------------------------------
		void SetKeyNamber(int keyNamber)
		{
			m_keyNamber = keyNamber;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief ゲームの時間の取得
		*/
		//--------------------------------------------------------------------------------------
		float GetGameTime()
		{
			return m_gameStageTime;
		}

		//--------------------------------------------------------------------------------------
		/*!
		@brief ゲームの時間の設定
		*/
		//--------------------------------------------------------------------------------------
		void SetGameTime(float gameStageTime)
		{
			m_gameStageTime = gameStageTime;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief 鍵のcsvのナンバーの取得
		@return	ゲームオーバーしたかどうか
		*/
		//--------------------------------------------------------------------------------------
		int GetMeatNamber()
		{
			return m_meatNumber;
		}


		//--------------------------------------------------------------------------------------
		/*!
		@brief 日付の設定
		*/
		//--------------------------------------------------------------------------------------
		void SetDate(int Date)
		{
			m_date = Date;
		}
		//--------------------------------------------------------------------------------------
		/*!
		@brief 日付の取得
		@return	現在の日付
		*/
		//--------------------------------------------------------------------------------------
		int GetDate()
		{
			return m_date;
		}

		//--------------------------------------------------------------------------------------
		/*!
		@brief 鍵のcsvのナンバーの設定
		@return	ゲームオーバーしたかどうか
		*/
		//--------------------------------------------------------------------------------------
		void SetMeatNamber(int MeatNamber)
		{
			m_meatNumber = MeatNamber;
		}

		//--------------------------------------------------------------------------------------
		/*!
		@brief テクスチャの読み込み
		*/
		//--------------------------------------------------------------------------------------
		void RoadTexture(const wstring&TextureName, const wstring& UseTextureName);

		//--------------------------------------------------------------------------------------
		/*!
		@brief プレイヤーが変身するかどうかの取得
		*/
		//--------------------------------------------------------------------------------------
		bool GetPlayerChangeDirecting()
		{
			return m_IsplayerChangeDirecting;
		}

		//--------------------------------------------------------------------------------------
		/*!
		@brief ゲームの時間の設定
		*/
		//--------------------------------------------------------------------------------------
		void SetPlayerChangeDirecting(bool PlayerChangeDirecting)
		{
			m_IsplayerChangeDirecting = PlayerChangeDirecting;
		}


		//--------------------------------------------------------------------------------------
		/*!
		@brief プレイヤーが変身するかどうかの取得
		*/
		//--------------------------------------------------------------------------------------
	     float GetDayTime()
		{
			return m_dayTime;
		}

		//--------------------------------------------------------------------------------------
		/*!
		@brief ゲームの時間の設定
		*/
		//--------------------------------------------------------------------------------------
		void SetDayTime(float DayTime)
		{
			m_dayTime = DayTime;
		}

		//--------------------------------------------------------------------------------------
		/*!
		@brief　プレイヤーの状態の時間の取得
		*/
		//--------------------------------------------------------------------------------------
		float GetPlayerConditionTime()
		{
			return m_playerConditionTime;
		}

		//--------------------------------------------------------------------------------------
		/*!
		@brief　プレイヤーの状態の時間の設定
		*/
		//--------------------------------------------------------------------------------------
		void SetPlayerConditionTime(float PlayerConditionTime)
		{
			m_playerConditionTime = PlayerConditionTime;
		}

		
		
	};

}

//end basecross
