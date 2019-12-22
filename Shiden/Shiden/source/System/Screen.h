//=============================================================================
//
// �X�N���[�� [Screen.h]
// Author:GP12B332 19 ���J���u
//
//=============================================================================
#ifndef _SCREEN_H_
#define _SCREEN_H_

#include "../../Main.h"

//****************************************************
// �N���X��`
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
	// �`��p�T�u�X�N���[�����쐬
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
