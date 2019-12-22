//=============================================================================
//
// ゲーム [Game.h]
// Author:GP12B332 19 染谷武志
//
//=============================================================================
#ifndef _GAME_H_
#define _GAME_H_

#include "Screen.h"
#include "../Scene/SceneManager.h"

//****************************************************
// クラス定義
//****************************************************
class Game
{
public:
	Game(HINSTANCE hInstance, HWND hWnd);
	~Game();
	void Update();
	void Draw();

private:
	SceneManager* manager;	// シーンマネージャ
	Screen* screen;			// スクリーン
};

#endif
