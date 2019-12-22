//=============================================================================
//
// スクリーン [Screen.h]
// Author:GP12B332 19 染谷武志
//
//=============================================================================
#ifndef _SCREEN_H_
#define _SCREEN_H_

#include "../../Main.h"

//****************************************************
// クラス定義
//****************************************************
class Screen
{
public:
	Screen(D3DXVECTOR2 size, D3DXVECTOR2 position);
	~Screen();

	void DrawBegin(const D3DXCOLOR& backColor);
	void DrawTexture();
	void DrawEnd();

private:
	// 描画用サブスクリーンを作成
	LPDIRECT3DTEXTURE9 renderTexture;
	LPDIRECT3DSURFACE9 renderSurface;
	LPDIRECT3DSURFACE9 oldSuface;
	LPDIRECT3DVERTEXBUFFER9 screenVtx;
	D3DXVECTOR2 size;
	D3DXVECTOR2 position;

	void MakeRenderTarget();
	void MakeScreen();
};

#endif
