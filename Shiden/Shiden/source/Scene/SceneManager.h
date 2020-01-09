//=============================================================================
//
// �V�[���}�l�[�W��[SceneManager.h]
// Author : GP12B332 19 ���J���u
//
//=============================================================================
#ifndef _SCENEMANAGER_H_
#define _SCENEMANAGER_H_

#include <vector>
#include "../../Main.h"

// �O���錾
class Camera;
class PlayerController;
class FieldController;

//****************************************************
// �N���X��`
//****************************************************
class SceneManager
{
public:
	// ���
	enum State {
		Title,
		Game,
		Result,
		Max
	};

	SceneManager();
	~SceneManager();

	// �e�폈��
	void Update();
	void Draw();

	// ��ԑJ�ڏ���
	void ChangeState(State next);

private:
	// �����N���X�̑O���錾
	class SceneTitle;
	class SceneGame;
	class SceneResult;

	State currentState, prevState;		// ���݁A�ȑO�̏��
	using SceneState = BaseState<SceneManager, State>;
	std::vector<SceneState*> fsm;		// �X�e�[�g�}�V��

	// �e��C���X�^���X
	Camera* camera;
	PlayerController* playerController;
	FieldController* fieldController;
};
#endif
