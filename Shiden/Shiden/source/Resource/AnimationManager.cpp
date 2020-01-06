//=====================================
//
// アニメーションマネージャ[AnimationManager.cpp]
// 役割：アニメーション管理クラス
// Author:GP12B332 19 染谷武志
//
//=====================================
#include "AnimationManager.h"
#include "AnimationContainer.h"
#include "ResourceManager.h"

#include <assert.h>

using namespace std;
//==========================================
// コンストラクタ
//==========================================
AnimationManager::AnimationManager() :
	currentAnimID(0)
{
	container = new AnimationContainer();
}

//==========================================
// デストラクタ
//==========================================
AnimationManager::~AnimationManager()
{
	SAFE_DELETE(container);
}

//==========================================
// 更新
//==========================================
void AnimationManager::Update()
{
	//経過時間を更新
	elapsedTime += deltaTimeList[currentAnimID] * playSpeedList[currentAnimID];

	//遷移判定
	if (ShouldTransition())
	{
		ChangeAnim(transitionMap[currentAnimID], true);
	}
}

//==========================================
// 描画
//==========================================
void AnimationManager::Draw(LPD3DXMATRIX mtxWorld)
{
	//アニメーションの更新
	container->Update(deltaTimeList[currentAnimID]);

	container->Draw(mtxWorld);
}

//==========================================
// Xファイル読み込み
//==========================================
HRESULT AnimationManager::LoadXFile(LPCSTR fileName, const char* errorSrc)
{
	bool res = S_OK;
	ResourceManager::Instance()->GetSkinMesh(fileName, container);

	if (res != S_OK)
		return res;

	playSpeedList.resize(container->GetNumAnimationSets());
	for (auto&& playSpeed : playSpeedList)
	{
		playSpeed = 1.5f;
	}

	deltaTimeList.resize(container->GetNumAnimationSets());
	for (auto&& deltaTime : deltaTimeList)
	{
		deltaTime = 1.0f / 30.0f;
	}

	return S_OK;
}

//==========================================
// アニメーションセット読み込み
//==========================================
HRESULT AnimationManager::LoadAnimation(LPCSTR setName, int setNo, float shiftTime)
{
	HRESULT res = S_OK;

	container->SetupCallbackKeyFrames(setName);

	res = container->LoadAnimation(setName, setNo);

	if (res != S_OK)
		return res;

	container->SetShiftTime(setNo, shiftTime);

	return S_OK;
}

//==========================================
// プレイスピード設定
//==========================================
void AnimationManager::SetPlaySpeed(UINT animID, float speed)
{
	assert(animID >= 0);
	assert(animID < playSpeedList.size());

	playSpeedList[animID] = speed;
}

//==========================================
// 遷移時間設定
//==========================================
void AnimationManager::SetDeltaTime(UINT animID, float delta)
{
	assert(animID >= 0);
	assert(animID < deltaTimeList.size());

	deltaTimeList[animID] = delta;
}

//==========================================
// アニメーション変更処理
//==========================================
void AnimationManager::ChangeAnim(UINT next, bool forceChange)
{
	container->ChangeAnim(next, playSpeedList[next], forceChange);

	currentAnimID = next;
	elapsedTime = 0.0f;
	animationPeriod = container->GetPeriodAnimation();
}

//==========================================
// アニメーション遷移設定
//==========================================
/**************************************
アニメーション遷移設定処理
***************************************/
void AnimationManager::SetFinishTransition(UINT srcID, UINT destID)
{
	transitionMap[srcID] = destID;
}

//==========================================
// アニメーション遷移判定
//==========================================
bool AnimationManager::ShouldTransition()
{
	if (transitionMap.count(currentAnimID) == 0)
		return false;

	if (elapsedTime < animationPeriod)
		return false;

	return true;
}