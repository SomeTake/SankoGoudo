//=============================================================================
//
// �V�[���Q�[��[SceneGame.cpp]
// Author : GP12B332 19 ���J���u
//
//=============================================================================
#include "SceneGame.h"
#include "../Player/PlayerController.h"

//==========================================
// ����
//==========================================
void SceneManager::SceneGame::OnStart(SceneManager & entity)
{
}

//==========================================
// �X�V
//==========================================
SceneManager::State SceneManager::SceneGame::OnUpdate(SceneManager & entity)
{
	// �C���X�^���X�̍X�V
	entity.playerController->Update();

	return State::Game;
}

//==========================================
// �`��
//==========================================
void SceneManager::SceneGame::OnDraw(SceneManager & entity)
{
	// �t�B�[���h�̕`��

	// ���b�V���̕`��
	entity.playerController->Draw();

	// �p�[�e�B�N���̕`��

	// UI�̕`��
}
