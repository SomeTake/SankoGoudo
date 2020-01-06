//=============================================================================
//
// インスタンシングメッシュエフェクト [InstancingEffect.h]
// 役割：メッシュ用インスタンシングエフェクト
// Author:GP12B332 19 染谷武志
//
//=============================================================================
#ifndef _INSTANCINGMESHEFFECT_H_
#define _INSTANCINGMESHEFFECT_H_

#include "../../main.h"
#include "RendererEffect.h"

//****************************************************
// クラス定義
//****************************************************
class InstancingMeshEffect : public RendererEffect
{
public:
	//コンストラクタ、デストラクタ
	InstancingMeshEffect();
	~InstancingMeshEffect();

private:
	//シェーダへのハンドル
	D3DXHANDLE hTechnique;
};

#endif