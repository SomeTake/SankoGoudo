//=============================================================================
//
// �Q�[�� [Game.h]
// Author:GP12B332 19 ���J���u
//
//=============================================================================
#ifndef _GAME_H_
#define _GAME_H_

#include "Screen.h"
#include "../Scene/SceneManager.h"

//****************************************************
// �N���X��`
//****************************************************
class Game
{
public:
	Game(HINSTANCE hInstance, HWND hWnd);
	~Game();
	void Update();
	void Draw();

private:
	SceneManager* manager;	// �V�[���}�l�[�W��
	Screen* screen;			// �X�N���[��
};

#endif
