//=============================================================================
//
// シーンリザルト[SceneResult.cpp]
// Author : GP12B332 19 染谷武志
//
//=============================================================================
#include "SceneResult.h"

//==========================================
// 入場
//==========================================
void SceneManager::SceneResult::OnStart(SceneManager & entity)
{
}

//==========================================
// 更新
//==========================================
SceneManager::State SceneManager::SceneResult::OnUpdate(SceneManager & entity)
{
	return State::Result;
}

//==========================================
// 描画
//==========================================
void SceneManager::SceneResult::OnDraw(SceneManager & entity)
{
}
