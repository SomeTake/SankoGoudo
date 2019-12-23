//=============================================================================
//
// �Q�[�� [Game.cpp]
// Author:GP12B332 19 ���J���u
//
//=============================================================================
#include "Game.h"
#include "TaskManager.h"

//==========================================
// �R���X�g���N�^
//==========================================
Game::Game(HINSTANCE hInstance, HWND hWnd)
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();

	manager = new SceneManager();
	screen = new Screen(D3DXVECTOR2((float)SCREEN_WIDTH, (float)SCREEN_HEIGHT), D3DXVECTOR2(0.0f, 0.0f));
}

//==========================================
// �f�X�g���N�^
//==========================================
Game::~Game()
{
	SAFE_DELETE(manager);
	SAFE_DELETE(screen);

	TaskManager::Instance()->AllDelete();
}

//==========================================
// �X�V
//==========================================
void Game::Update()
{
	manager->Update();

	TaskManager::Instance()->Update();
}

//==========================================
// �`��
//==========================================
void Game::Draw()
{
	const D3DXCOLOR backColor = D3DXCOLOR(0.0f, 0.0f, 0.05f, 1.0f);
	screen->DrawBegin(backColor);

	manager->Draw();
	screen->DrawTexture();

	screen->DrawEnd();
}
