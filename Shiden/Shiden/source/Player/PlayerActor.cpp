//=====================================
//
// �v���C���[�A�N�^�[[PlayerActor.cpp]
// �����F����p�A�N�^�[�\������
// Author:GP12B332 19 ���J���u
//
//=====================================
#include "PlayerActor.h"

//=====================================
// �X�^�e�B�b�N�����o������
//=====================================
const PlayerActor::Data PlayerActor::data[] = {
	{"Idle", 1.0f, 0.3f, 1/30.0f},
	{"Running", 1.0f, 0.3f, 1 / 30.0f},
};
const char* PlayerActor::fileName = "data/Model/Player.x";

//=====================================
// �R���X�g���N�^
//=====================================
PlayerActor::PlayerActor()
{
	transform->SetPosition(D3DXVECTOR3(2500.0f, 0.0f, -2500.0f));
	transform->SetScale(D3DXVECTOR3(1.0f, 1.0f, 1.0f));
	transform->SetRotation(D3DXVECTOR3(0.0f, 180.0f, 0.0f));
	SetActive(true);

	// �A�j���[�V��������
	anim = new AnimationManager();
	anim->LoadXFile(fileName, "Player");

	// �A�j���[�V�����Z�b�g�쐬
	for (int i = 0; i < State::Max; i++)
	{
		anim->LoadAnimation(data[State(i)].tag, i, data[State(i)].shiftTime);
		anim->SetPlaySpeed(i, data[State(i)].playSpeed);
		anim->SetDeltaTime(i, data[State(i)].deltaTime);
	}

	// �A�j���[�V�����J�ڂ̃Z�b�g
	for (int i = 0; i < State::Max; i++)
	{
		anim->SetFinishTransition(State(i), State(0));
	}
}

//=====================================
// �f�X�g���N�^
//=====================================
PlayerActor::~PlayerActor()
{
	SAFE_DELETE(anim);
}

//=====================================
// �X�V
//=====================================
void PlayerActor::Update()
{
	anim->Update();
}

//=====================================
// �`��
//=====================================
void PlayerActor::Draw()
{
	if (!IsActive())
		return;

	D3DXMATRIX mtxWorld = transform->GetMatrix();
	transform->SetWorld();

	anim->Draw(&mtxWorld);
}

//=====================================
// �A�j���[�V�����̐؂�ւ�
//=====================================
void PlayerActor::ChangeAnim(State next, bool animLoop)
{
	//���[�v�ݒ�
	if (animLoop)
	{
		anim->SetFinishTransition(next, next);
	}
	else
	{
		anim->SetFinishTransition(next, State::Idle);
	}

	anim->ChangeAnim((UINT)next, true);
}
