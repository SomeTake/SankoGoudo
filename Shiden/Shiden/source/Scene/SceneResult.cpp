//=============================================================================
//
// �V�[�����U���g[SceneResult.cpp]
// Author : GP12B332 19 ���J���u
//
//=============================================================================
#include "SceneResult.h"

//==========================================
// ����
//==========================================
void SceneManager::SceneResult::OnStart(SceneManager & entity)
{
}

//==========================================
// �X�V
//==========================================
SceneManager::State SceneManager::SceneResult::OnUpdate(SceneManager & entity)
{
	return State::Result;
}

//==========================================
// �`��
//==========================================
void SceneManager::SceneResult::OnDraw(SceneManager & entity)
{
}
