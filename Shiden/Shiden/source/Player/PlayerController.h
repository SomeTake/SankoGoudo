//=============================================================================
//
// �v���C���[�R���g���[��[PlayerController.h]
// �����F�v���C���[����
// Author:GP12B332 19 ���J���u
//
//=============================================================================
#ifndef _PLAYERCONTROLLER_H_
#define _PLAYERCONTROLLER_H_

class PlayerActor;

//****************************************************
// �N���X��`
//****************************************************
class PlayerController
{
public:
	PlayerController(int ctrlNo);
	~PlayerController();

	void Update();
	void Draw();

private:
	PlayerActor* actor;		// �A�N�^�[�̃C���X�^���X
	int controllerNo;		// �R���g���[���ԍ�

	// ����
	void Move();
};

#endif