//=====================================
//
// キーボード[Keyboard.h]
// Author:GP12B332 19 染谷武志
//
//=====================================
#ifndef _KEYBOARD_H_
#define _KEYBOARD_H_

#include "../../main.h"

/**************************************
クラス定義
***************************************/
namespace Keyboard
{
	HRESULT Init(HINSTANCE hInst, HWND hWnd, LPDIRECTINPUT8 pInput);
	void Uninit();
	void Update();

	bool GetPress(int nKey);
	bool GetTrigger(int nKey);
	bool GetRepeat(int nKey);
	bool GetRelease(int nKey);
};

#endif	