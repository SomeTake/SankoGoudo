//=============================================================================
//
// �V�[���^�C�g��[SceneTitle.cpp]
// Author : GP12B332 19 ���J���u
//
//=============================================================================
#include "SceneTitle.h"

//==========================================
// ����
//==========================================
void SceneManager::SceneTitle::OnStart(SceneManager & entity)
{
}

//==========================================
// �X�V
//==========================================
SceneManager::State SceneManager::SceneTitle::OnUpdate(SceneManager & entity)
{
	return State::Title;
}

//==========================================
// �`��
//==========================================
void SceneManager::SceneTitle::OnDraw(SceneManager & entity)
{
}
