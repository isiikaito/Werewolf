#pragma once
#include "stdafx.h"
#include "StateMchine.h"
#include "Player.h"

namespace basecross
{
	namespace kaito
	{
		//!プレイヤーが人間状態の時のステート---------------------------
		class HumanState :public State<Player>
		{
		private:
			HumanState() {}
			float m_HumanChangeTime = 0.0f;
			CsvFile m_MeatPositon;//!肉のポジションのCSVファイル
			int m_MeatNumber=0;//!肉の位置が保存されたCSVファイルの番号
			//!シングルトンパターン
			HumanState(const HumanState&) = delete;//!関数を削除する
			HumanState& operator=(const HumanState&) = delete;//!operatorの中にある=を削除（コピーされないように）

		public:
			static HumanState* Instance();

			void CreateMeat();
			void ReadCsv(const wstring& FileNume);
			virtual void Enter(Player* Player)override;
			virtual void Execute(Player* Player)override;
			virtual void Exit(Player* Player)override;
		};

		//-------------------------------------------------------------------


		//!プレイヤーが狼男状態の時のステート---------------------------
		class WolfState :public State<Player>
		{
		private:
			WolfState() {}
			WolfState(const WolfState&) = delete;//!関数を削除する
			WolfState& operator=(const WolfState&) = delete;//!operatorの中にある=を削除(コピーされないように)
			float m_WolfChangeTime = 0.0f;
		

		public:
			static WolfState* Instance();
			void MeatEat(Player* Player);
			virtual void Enter(Player* Player)override;
			virtual void Execute(Player* Player)override;
			virtual void Exit(Player* Player)override;
		};
	}
	//-------------------------------------------------------------------
}