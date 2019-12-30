//=============================================================================
//
// ゲーム [Game.cpp]
// Author:GP12B332 19 染谷武志
//
//=============================================================================
#include "Game.h"
#include "TaskManager.h"
#include "../Core/Tween.h"

Tween* Tween::mInstance = NULL;

//==========================================
// コンストラクタ
//==========================================
Game::Game(HINSTANCE hInstance, HWND hWnd)
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();

	manager = new SceneManager();
	screen = new Screen(D3DXVECTOR2((float)SCREEN_WIDTH, (float)SCREEN_HEIGHT), D3DXVECTOR2(0.0f, 0.0f));
	Tween::mInstance = new Tween();
}

//==========================================
// デストラクタ
//==========================================
Game::~Game()
{
	SAFE_DELETE(manager);
	SAFE_DELETE(screen);
	SAFE_DELETE(Tween::mInstance);

	TaskManager::Instance()->AllDelete();
}

//==========================================
// 更新
//==========================================
void Game::Update()
{
	manager->Update();
	Tween::mInstance->Update();

	TaskManager::Instance()->Update();
}

//==========================================
// 描画
//==========================================
void Game::Draw()
{
	const D3DXCOLOR backColor = D3DXCOLOR(0.0f, 0.0f, 0.05f, 1.0f);
	screen->DrawBegin(backColor);

	manager->Draw();
	screen->DrawTexture();

	screen->DrawEnd();
}
