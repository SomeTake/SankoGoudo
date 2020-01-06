//=====================================
//
// アニメーションリソース[AnimationResource.h]
// 役割：アニメーションリソース
// Author:GP12B332 19 染谷武志
//
//=====================================
#ifndef _ANIMATIONRESOURCE_H_
#define _ANIMATIONRESOURCE_H_

#include "../../main.h"

//****************************************************
// 前方宣言
//****************************************************
class AnimationContainer;

//****************************************************
// クラス定義
//****************************************************
class AnimationResource
{
public:
	AnimationResource();
	virtual ~AnimationResource();

	HRESULT Load(const char* fileName, const char* errorSrc);

	void Clone(AnimationContainer* container);

private:
	LPD3DXFRAME rootFrame;
	LPD3DXANIMATIONCONTROLLER animController;

	int animSetNum;

	HRESULT SetupBoneMatrixPointers(LPD3DXFRAME frameBase, LPD3DXFRAME frameRoot);
};
#endif