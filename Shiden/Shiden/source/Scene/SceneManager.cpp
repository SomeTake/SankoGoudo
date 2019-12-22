//=============================================================================
//
// �V�[���}�l�[�W��[SceneManager.h]
// Author : GP12B332 19 ���J���u
//
//=============================================================================
#include "SceneManager.h"
#include "SceneTitle.h"
#include "SceneGame.h"
#include "SceneResult.h"

//==========================================
// �R���X�g���N�^
//==========================================
SceneManager::SceneManager()
{
	// �X�e�[�g�}�V���̍쐬
	fsm.resize(State::Max, NULL);
	fsm[State::Title] = new SceneTitle();
	fsm[State::Game] = new SceneGame();
	fsm[State::Result] = new SceneResult();

	// �����V�[����ݒ�
	ChangeState(State::Title);
}

//==========================================
// �f�X�g���N�^
//==========================================
SceneManager::~SceneManager()
{
	// �X�e�[�g�}�V���̍폜
	for (auto&& p : fsm)
	{
		delete p;
		p = NULL;
	}
	fsm.clear();
}

//==========================================
// �X�V
//==========================================
void SceneManager::Update()
{
	// �X�e�[�g�}�V���̍X�V
	State next = fsm[currentState]->OnUpdate(*this);
}

//==========================================
// �`��
//==========================================
void SceneManager::Draw()
{
	// �X�e�[�g�}�V���̕`��
	fsm[currentState]->OnDraw(*this);
}

//==========================================
// �X�e�[�g�̕ύX
//==========================================
void SceneManager::ChangeState(State next)
{
	prevState = currentState;

	currentState = next;

	if (fsm[currentState] != NULL)
	{
		fsm[currentState]->OnStart(*this);
	}
}
