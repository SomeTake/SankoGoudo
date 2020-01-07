//=============================================================================
//
// シーンゲーム[SceneGame.cpp]
// Author : GP12B332 19 染谷武志
//
//=============================================================================
#include "SceneGame.h"
#include "../Player/PlayerController.h"

//==========================================
// 入場
//==========================================
void SceneManager::SceneGame::OnStart(SceneManager & entity)
{
}

//==========================================
// 更新
//==========================================
SceneManager::State SceneManager::SceneGame::OnUpdate(SceneManager & entity)
{
	// インスタンスの更新
	entity.playerController->Update();

	return State::Game;
}

//==========================================
// 描画
//==========================================
void SceneManager::SceneGame::OnDraw(SceneManager & entity)
{
	// フィールドの描画

	// メッシュの描画
	entity.playerController->Draw();

	// パーティクルの描画

	// UIの描画
}
