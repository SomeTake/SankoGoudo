//=============================================================================
//
// �C���X�^���V���O���b�V���G�t�F�N�g [InstancingEffect.h]
// �����F���b�V���p�C���X�^���V���O�G�t�F�N�g
// Author:GP12B332 19 ���J���u
//
//=============================================================================
#ifndef _INSTANCINGMESHEFFECT_H_
#define _INSTANCINGMESHEFFECT_H_

#include "../../main.h"
#include "RendererEffect.h"

//****************************************************
// �N���X��`
//****************************************************
class InstancingMeshEffect : public RendererEffect
{
public:
	//�R���X�g���N�^�A�f�X�g���N�^
	InstancingMeshEffect();
	~InstancingMeshEffect();

private:
	//�V�F�[�_�ւ̃n���h��
	D3DXHANDLE hTechnique;
};

#endif