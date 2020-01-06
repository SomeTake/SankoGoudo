//=====================================
//
// �{�[�h�|���S��[BoardPolygon.cpp]
// �����F3D�|���S��
// Author:GP12B332 19 ���J���u
//
//=====================================
#include "BoardPolygon.h"
#include "ResourceManager.h"
#include "PolygonResource.h"
#include "../Effect/SpriteEffect.h"

//==========================================
// �R���X�g���N�^
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
// �R���X�g���N�^
//==========================================
BoardPolygon::BoardPolygon(SpriteEffect * effect) :
	vtxBuff(nullptr),
	texture(nullptr),
	effect(effect)
{
	pDevice = GetDevice();
}

//==========================================
// �f�X�g���N�^
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
// �`��
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
// UV�����ݒ�
//==========================================
void BoardPolygon::SetTexDiv(const D3DXVECTOR2& div)
{
	effect->SetTextureDivine(div);
}

//==========================================
// UV�C���f�b�N�X�ݒ�
//==========================================
void BoardPolygon::SetTextureIndex(int index)
{
	effect->SetTextureIndex(index);
}

//==========================================
// �f�B�t���[�Y�ݒ�
//==========================================
void BoardPolygon::SetDiffuse(const D3DXCOLOR & color)
{
	effect->SetDiffuse(color);
}
