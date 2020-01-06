//=============================================================================
//
// �C���X�^���V���O���b�V���G�t�F�N�g [InstancingEffect.cpp]
// �����F���b�V���p�C���X�^���V���O�G�t�F�N�g
// Author:GP12B332 19 ���J���u
//
//=============================================================================
#include "InstancingMeshEffect.h"
#include "../Resource/ResourceManager.h"

//==========================================
// �R���X�g���N�^
//==========================================
InstancingMeshEffect::InstancingMeshEffect()
{
	//�G�t�F�N�g�ǂݍ���
	ResourceManager::Instance()->GetEffect("data/EFFECT/InstancingMesh.cfx", effect);

	//�n���h���擾
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
// �f�X�g���N�^
//==========================================
InstancingMeshEffect::~InstancingMeshEffect()
{
	SAFE_RELEASE(effect);
}
