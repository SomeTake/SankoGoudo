//=====================================
//
// �v���C���[�A�N�^�[[PlayerActor.h]
// �����F����p�A�N�^�[�\������
// Author:GP12B332 19 ���J���u
//
//=====================================
#ifndef _PLAYERACTOR_H_
#define _PLAYERACTOR_H_

#include "../Core/GameObject.h"
#include "../Resource/AnimationManager.h"

//****************************************************
// �N���X��`
//****************************************************
class PlayerActor :
	public GameObject
{
public:
	// �A�j���[�V�����X�e�[�g
	enum State
	{
		Idle,
		Running,
		Max
	};

	// �A�j���[�V�����f�[�^
	struct Data {
		const char* tag;
		float playSpeed;
		float shiftTime;
		float deltaTime;
	};

	PlayerActor();
	~PlayerActor();

	void Update();
	void Draw();

	// �A�j���[�V�����̐؂�ւ�
	void ChangeAnim(State next, bool animLoop = false);

private:
	AnimationManager* anim;
	static const char* fileName;
	static const Data data[State::Max];
};

#endif
