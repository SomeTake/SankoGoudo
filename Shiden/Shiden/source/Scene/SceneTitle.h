//=============================================================================
//
// �^�C�g���V�[�� [TitleGame.h]
// Author : GP12B332 19
//
//=============================================================================
#ifndef _SCENETITLE_H_
#define _SCENETITLE_H_

#include "SceneManager.h"

//****************************************************
// �N���X��`
//****************************************************
class SceneManager::SceneTitle :
	public SceneManager::SceneState
{
public:
	void OnStart(SceneManager& entity)override;		// ����
	State OnUpdate(SceneManager& entity)override;	// �X�V
	void OnDraw(SceneManager& entity)override;		// �`��
};
#endif