//=====================================
//
// �{�[�h�|���S��[BoardPolygon.h]
// �����F3D�|���S��
// Author:GP12B332 19 ���J���u
//
//=====================================
#ifndef _BOARDPOLYGON_H_
#define _BOARDPOLYGON_H_

#include "../../main.h"

//****************************************************
// �O���錾
//****************************************************
class PolygonResource;
class SpriteEffect;

//****************************************************
// �N���X��`
//****************************************************
class BoardPolygon
{
	friend class PolygonResource;
public:
	//�R���X�g���N�^�A�f�X�g���N�^
	BoardPolygon();
	BoardPolygon(SpriteEffect* effect);
	~BoardPolygon();

	//�`�揈��
	void Draw(const D3DXMATRIX& mtxWorld);

	//UV�����ݒ菈��
	void SetTexDiv(const D3DXVECTOR2& div);

	//�e�N�X�`���ʂ��ԍ��ݒ菈��
	void SetTextureIndex(int index);

	//�f�B�t���[�Y�ݒ菈��
	void SetDiffuse(const D3DXCOLOR& color);

protected:
	LPDIRECT3DDEVICE9 pDevice;

	LPDIRECT3DVERTEXBUFFER9 vtxBuff;
	LPDIRECT3DTEXTURE9 texture;

	PolygonResource *resource;

	SpriteEffect *effect;
};

#endif