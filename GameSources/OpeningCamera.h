/*!
@file opningh.h
@brief オープニングカメラ
*@author isii kaito
*/

#pragma once
#include "stdafx.h"

namespace basecross {

	//--------------------------------------------------------------------------------------
	//	オープニングカメラ（コンポーネントではない）
	//--------------------------------------------------------------------------------------
	class OpeningCamera : public Camera {
	public:
		//--------------------------------------------------------------------------------------
		/*!
		@brief	コンストラクタ
		*/
		OpeningCamera();

		//--------------------------------------------------------------------------------------
		/*!
		@brief	デストラクタ
		*/
		virtual ~OpeningCamera();

		//--------------------------------------------------------------------------------------
		/*!
		@brief 更新処理
		*/
		virtual void OnUpdate()override;
	};
}
