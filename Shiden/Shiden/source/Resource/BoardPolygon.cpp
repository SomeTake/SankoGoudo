//=====================================
//
// ボードポリゴン[BoardPolygon.cpp]
// 役割：3D板ポリゴン
// Author:GP12B332 19 染谷武志
//
//=====================================
#include "BoardPolygon.h"
#include "ResourceManager.h"
#include "PolygonResource.h"
#include "../Effect/SpriteEffect.h"

//==========================================
// コンストラクタ
//==========================================
BoardPolygon::BoardPolygon() :
	vtxBuff(nullptr),
	texture(nullptr),
	effect(nullptr)
{
	pDevice = GetDevice();
	effect = new SpriteEffect();
}

//==========================================
// コンストラクタ
//==========================================
BoardPolygon::BoardPolygon(SpriteEffect * effect) :
	vtxBuff(nullptr),
	texture(nullptr),
	effect(effect)
{
	pDevice = GetDevice();
}

//==========================================
// デストラクタ
//==========================================
BoardPolygon::~BoardPolygon()
{
	SAFE_RELEASE(vtxBuff);
	SAFE_RELEASE(texture);
	SAFE_DELETE(effect);

	if (resource != NULL)
		resource->OnRelease();
}

//==========================================
// 描画
//==========================================
void BoardPolygon::Draw(const D3DXMATRIX& mtxWorld)
{
	effect->SetWorld(mtxWorld);
	effect->Commit();

	pDevice->SetTexture(0, texture);

	pDevice->SetStreamSource(0, vtxBuff, 0, sizeof(VERTEX_MATERIAL));

	pDevice->SetFVF(FVF_VERTEX_MATERIAL);

	effect->Begin();
	effect->BeginPass(0);
	pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, NUM_POLYGON);
	effect->EndPass();
	effect->End();
}

//==========================================
// UV分割設定
//==========================================
void BoardPolygon::SetTexDiv(const D3DXVECTOR2& div)
{
	effect->SetTextureDivine(div);
}

//==========================================
// UVインデックス設定
//==========================================
void BoardPolygon::SetTextureIndex(int index)
{
	effect->SetTextureIndex(index);
}

//==========================================
// ディフューズ設定
//==========================================
void BoardPolygon::SetDiffuse(const D3DXCOLOR & color)
{
	effect->SetDiffuse(color);
}
