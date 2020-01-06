//=============================================================================
//
// インスタンシングメッシュエフェクト [InstancingEffect.cpp]
// 役割：メッシュ用インスタンシングエフェクト
// Author:GP12B332 19 染谷武志
//
//=============================================================================
#include "InstancingMeshEffect.h"
#include "../Resource/ResourceManager.h"

//==========================================
// コンストラクタ
//==========================================
InstancingMeshEffect::InstancingMeshEffect()
{
	//エフェクト読み込み
	ResourceManager::Instance()->GetEffect("data/EFFECT/InstancingMesh.cfx", effect);

	//ハンドル取得
	hView = effect->GetParameterByName(0, "mtxView");
	hProjection = effect->GetParameterByName(0, "mtxProjection");

	hMatDiffuse = effect->GetParameterByName(0, "materialDiffuse");
	hMatAmbient = effect->GetParameterByName(0, "materialAmbient");
	hMatSpecular = effect->GetParameterByName(0, "materialSpecular");

	hLightDirection = effect->GetParameterByName(0, "lightDirection");
	hLightDiffuse = effect->GetParameterByName(0, "lightDiffuse");
	hLightAmbient = effect->GetParameterByName(0, "lightAmbient");
	hLightSpecular = effect->GetParameterByName(0, "lightSpecular");

	hTechnique = effect->GetTechniqueByName("tech");
	effect->SetTechnique(hTechnique);
}

//==========================================
// デストラクタ
//==========================================
InstancingMeshEffect::~InstancingMeshEffect()
{
	SAFE_RELEASE(effect);
}
