//=============================================================================
//
// �Q�[���V�[�� [SceneGame.h]
// Author : GP12B332 19
//
//=============================================================================
#ifndef _SCENEGAME_H_
#define _SCENEGAME_H_

#include "SceneManager.h"

//****************************************************
// �N���X��`
//****************************************************
class SceneManager::SceneGame :
	public SceneManager::SceneState
{
public:
	void OnStart(SceneManager& entity)override;		// ����
	State OnUpdate(SceneManager& entity)override;	// �X�V
	void OnDraw(SceneManager& entity)override;		// �`��
};

#endif
