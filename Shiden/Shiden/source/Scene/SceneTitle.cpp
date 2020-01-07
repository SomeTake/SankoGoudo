//=============================================================================
//
// シーンタイトル[SceneTitle.cpp]
// Author : GP12B332 19 染谷武志
//
//=============================================================================
#include "SceneTitle.h"

//==========================================
// 入場
//==========================================
void SceneManager::SceneTitle::OnStart(SceneManager & entity)
{
}

//==========================================
// 更新
//==========================================
SceneManager::State SceneManager::SceneTitle::OnUpdate(SceneManager & entity)
{
	return State::Title;
}

//==========================================
// 描画
//==========================================
void SceneManager::SceneTitle::OnDraw(SceneManager & entity)
{
}
