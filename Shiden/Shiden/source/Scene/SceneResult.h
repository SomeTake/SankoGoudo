//=============================================================================
//
// ���U���g�V�[�� [SceneResult.h]
// Author : GP12B332 19
//
//=============================================================================
#ifndef _SCENERESULT_H_
#define _SCENERESULT_H_

#include "SceneManager.h"

//****************************************************
// �N���X��`
//****************************************************
class SceneManager::SceneResult :
	public SceneManager::SceneState
{
public:
	void OnStart(SceneManager& entity)override;		// ����
	State OnUpdate(SceneManager& entity)override;	// �X�V
	void OnDraw(SceneManager& entity)override;		// �`��
};

#endif