//=====================================
//
// �A�j���[�V�������\�[�X[AnimationResource.h]
// �����F�A�j���[�V�������\�[�X
// Author:GP12B332 19 ���J���u
//
//=====================================
#ifndef _ANIMATIONRESOURCE_H_
#define _ANIMATIONRESOURCE_H_

#include "../../main.h"

//****************************************************
// �O���錾
//****************************************************
class AnimationContainer;

//****************************************************
// �N���X��`
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