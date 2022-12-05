/**
*@file WoodenBox.cpp
*@brief 木箱の実装が定義されているソースファイル
*@author kaito isii
*@details 木箱の実体実装
*/

#include "stdafx.h"
#include "Project.h"

namespace basecross {


	//--------------------------------------------------------------------------------------
	//	class FixedBox : public GameObject;
	//--------------------------------------------------------------------------------------
	//構築と破棄
	WoodenBox::WoodenBox(const shared_ptr<Stage>& StagePtr,
		const Vec3& Scale,
		const Vec3& Rotation,
		const Vec3& Position
	) :
		GameObject(StagePtr),
		m_Scale(Scale),
		m_Rotation(Rotation),
		m_Position(Position),
		m_oneday(0),
		m_Time(1)

	{
	}

	//初期化
	void WoodenBox::OnCreate() {
		//!衝突判定の設定
		auto ptrTrans = GetComponent<Transform>();
		ptrTrans->SetScale(m_Scale);      //!大きさ
		ptrTrans->SetRotation(m_Rotation);//!回転
		ptrTrans->SetPosition(m_Position);//!位置

		// モデルとトランスフォームの間の差分行列
		Mat4x4 spanMat;
		spanMat.affineTransformation(
			Vec3(0.8f, 0.14f, 0.045f),//!大きさ
			Vec3(0.0f, 0.0f, 0.0f),
			Vec3(0.0f, 0.0f, 0.0f),   //!回転
			Vec3(-0.35f, -0.7f, 0.05f)  //!位置
		);

		auto ptrShadow = AddComponent<Shadowmap>();       //!影をつける（シャドウマップを描画する）
		auto ptrDraw = AddComponent<PNTStaticModelDraw>();//!描画コンポーネント
		auto Coll = AddComponent<CollisionObb>();         //!キューブ型の当たり判定の追加
		Coll->SetFixed(true);                             //!ほかのオブジェクトの影響を受けない（例プレイヤーに当たったら消えるなどの処理）
		auto group = GetStage()->GetSharedObjectGroup(L"StageWall_Group");//!グループを取得
		group->IntoGroup(GetThis<StageWall>());//!グループにステージの壁を入れる

		//!影の形（メッシュ）を設定
		ptrShadow->SetMeshResource(L"STAGE_FENCE");
		ptrShadow->SetMeshToTransformMatrix(spanMat);

		//!メッシュの設定
		ptrDraw->SetMeshResource(L"STAGE_FENCE");
		ptrDraw->SetMeshToTransformMatrix(spanMat);
		/*Coll->SetDrawActive(true);*/
		

		SetAlphaActive(true);//!SetDiffiuseのカラー変更を適用

	}

	void WoodenBox::OnUpdate() {

		auto ptrDraw = AddComponent<PNTStaticModelDraw>();//!描画コンポーネント
		float elapsedTime = App::GetApp()->GetElapsedTime();//!elapsedTimeを取得することにより時間を使える

		// !夜から昼になる処理
		if (m_oneday == static_cast<int>(Oneday::midday))
		{
			m_Time += elapsedTime / 30; //!時間を変数に足す
			ptrDraw->SetEmissive(Col4(m_Time, m_Time, m_Time, 1.0f)); // !夜にする処理
			if (m_Time >= 1.0f)
			{
				m_oneday = static_cast<int>(Oneday::night);
			}
		}

		// !昼から夜になる処理
		if (m_oneday == static_cast<int>(Oneday::night))
		{
			m_Time += -elapsedTime / 30; //時間を変数に減らす
			ptrDraw->SetEmissive(Col4(m_Time, m_Time, m_Time, 1.0f)); // !朝にする処理
			if (m_Time <= 0.0f)
			{
				m_oneday = static_cast<int>(Oneday::midday);
			}
		}

		return;
	}

}