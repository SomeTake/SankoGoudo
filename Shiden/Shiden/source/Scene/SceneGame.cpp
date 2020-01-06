#include "SceneGame.h"
#include "../Player/PlayerController.h"

void SceneManager::SceneGame::OnStart(SceneManager & entity)
{
}

SceneManager::State SceneManager::SceneGame::OnUpdate(SceneManager & entity)
{
	// インスタンスの更新
	entity.playerController->Update();

	return State::Game;
}

void SceneManager::SceneGame::OnDraw(SceneManager & entity)
{
	// フィールドの描画

	// メッシュの描画
	entity.playerController->Draw();

	// パーティクルの描画

	// UIの描画
}
