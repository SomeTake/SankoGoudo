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
#include "../Camera/Camera.h"
#include "../Effect/SpriteEffect.h"
#include "../Player/PlayerController.h"

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

	// �C���X�^���X�̍쐬
	camera = new Camera();
	Camera::SetMainCamera(camera);
	playerController = new PlayerController(1);

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

	// �C���X�^���X�폜
	SAFE_DELETE(camera);
	SAFE_DELETE(playerController);
}

//==========================================
// �X�V
//==========================================
void SceneManager::Update()
{
	// �J�����X�V
	camera->Update();

	// �����V�F�[�_�[�ɓn��
	SpriteEffect::SetView(camera->GetViewMtx());
	SpriteEffect::SetProjection(camera->GetProjectionMtx());

	// �X�e�[�g�}�V���̍X�V
	State next = fsm[currentState]->OnUpdate(*this);
}

//==========================================
// �`��
//==========================================
void SceneManager::Draw()
{
	Camera::MainCamera()->Set();

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
