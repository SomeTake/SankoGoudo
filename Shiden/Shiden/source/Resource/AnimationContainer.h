//=====================================
//
// アニメーションコンテナ[AnimationContainer.h]
// 役割：アニメーションデータ保存用コンテナクラス
// Author:GP12B332 19 染谷武志
//
//=====================================
#ifndef _ANIMATIONCONTAINER_H_
#define _ANIMATIONCONTAINER_H_

#include "MyAllocateHierarchy.h"

//****************************************************
// クラス定義
//****************************************************
typedef struct
{
	LPCSTR setname;					//アニメーションセットの名前
	ID3DXAnimationSet *animSet;		//アニメーションセット
	float shiftTime;				//シフトするのにかかる時間
	float currentWeightTime;		//現在のウェイト時間
}AnimStatus;

class AnimationContainer
{
	friend class AnimationResource;
public:
	AnimationContainer();
	virtual ~AnimationContainer();

	HRESULT LoadAnimation(LPCSTR setName, int setNo);
	void Update(float time);
	void Draw(LPD3DXMATRIX worldMtx);
	void ChangeAnim(UINT animID, float playSpeed, bool forceChange = false);
	void SetShiftTime(UINT animID, float interval);

	HRESULT SetupCallbackKeyFrames(LPCSTR setName);
	D3DXMATRIX GetBoneMatrix(const char* boneName);

	UINT GetNumAnimationSets();
	float GetPeriodAnimation();

	int keyFrameCount;							//Callback KeyFramesを処理した数
	bool isMotionEnd;							//今再生しているアニメーションが最後かどうか
	bool isStopMove;							//キャラが移動を停止しているかどうか	

private:
	LPD3DXANIMATIONCONTROLLER animController;	//アニメーションコントローラ
	UINT currentAnimID;							//現在のアニメーション番号
	UINT prevAnimID;							//前のアニメーション番号
	AnimStatus *status;							//アニメーションセットのデータ
	MyAllocateHierarchy *allocater;				//Xファイルの情報を確保する
	LPD3DXFRAME rootFrame;						//ルートフレーム
	int animSetNum;								//アニメーションセットの数

	//メッシュコンテナ描画処理
	void DrawMeshContainer(LPD3DXMESHCONTAINER meshContainerBase, LPD3DXFRAME frameBase);
	void DrawFrame(LPD3DXFRAME frame);
	void UpdateFrameMatrixes(LPD3DXFRAME frameBase, LPD3DXMATRIX parentMatrix);
	D3DXFRAME_DERIVED* SearchBoneFrame(const char* boneName, D3DXFRAME* frame);
};

struct AnimCallBackHandler : public ID3DXAnimationCallbackHandler
{
	AnimationContainer *animContainer;
	LPCSTR setName;
	int animStatus;
	HRESULT CALLBACK HandleCallback(THIS_ UINT track, LPVOID pCallbackData);
};


#endif
