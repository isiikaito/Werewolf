/*!
@file CircleClockSprite.h
@author Ayumu Muroi
@brief 時計の円盤の表示
*/

#pragma once
#include "stdafx.h"

namespace basecross {
	class CircleClockSprite : public GameObject {
	private:
		bool m_Trace;         //!透明
		Vec2 m_StartScale;    //!大きさ
		Vec3 m_StartPos;      //!位置
		wstring m_TextureClock; //!テクスチャ
		float m_CircleTime; //!回転

	public:

		CircleClockSprite(const shared_ptr<Stage>& StagePtr, const wstring& TextureKey, bool Trace,
			const Vec2& StartScale, const Vec2& StartPos);
		//破棄
		virtual ~CircleClockSprite();
		//初期化
		virtual void OnCreate() override;
		//更新
		virtual void OnUpdate() override;

	};
}
//end basecross
