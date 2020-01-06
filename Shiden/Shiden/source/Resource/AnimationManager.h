//=====================================
//
// アニメーションマネージャ[AnimationManager.h]
// 役割：アニメーション管理クラス
// Author:GP12B332 19 染谷武志
//
//=====================================
#ifndef _ANIMATIONMANAGER_H_
#define _ANIMATIONMANAGER_H_

#include "../../main.h"
#include <vector>
#include <unordered_map>

class AnimationContainer;
//****************************************************
// クラス定義
//****************************************************
class AnimationManager
{
public:
	AnimationManager();
	~AnimationManager();

	void Update();
	void Draw(LPD3DXMATRIX mtxWorld);

	HRESULT LoadXFile(LPCSTR fileName, const char* errorSrc);
	HRESULT LoadAnimation(LPCSTR setName, int setNo, float shiftTime = 0.2f);

	void SetPlaySpeed(UINT animID, float speed);
	void SetDeltaTime(UINT animID, float deltaTimePerFrame);

	void ChangeAnim(UINT next, bool forceChange = false);
	void SetFinishTransition(UINT srcID, UINT destID);

private:
	AnimationContainer *container;
	UINT currentAnimID;

	float elapsedTime;
	float animationPeriod;

	std::vector <float> playSpeedList;
	std::vector<float> deltaTimeList;
	std::unordered_map<UINT, UINT> transitionMap;

	bool ShouldTransition();
};

#endif
