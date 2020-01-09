//=====================================
//
// プレイヤーアクター[PlayerActor.cpp]
// 役割：操作用アクター表示処理
// Author:GP12B332 19 染谷武志
//
//=====================================
#include "PlayerActor.h"

//=====================================
// スタティックメンバ初期化
//=====================================
const PlayerActor::Data PlayerActor::data[] = {
	{"Idle", 1.0f, 0.3f, 1/30.0f},
	{"Running", 1.0f, 0.3f, 1 / 30.0f},
};
const char* PlayerActor::fileName = "data/Model/Player.x";

//=====================================
// コンストラクタ
//=====================================
PlayerActor::PlayerActor()
{
	transform->SetPosition(D3DXVECTOR3(2500.0f, 0.0f, -2500.0f));
	transform->SetScale(D3DXVECTOR3(1.0f, 1.0f, 1.0f));
	transform->SetRotation(D3DXVECTOR3(0.0f, 180.0f, 0.0f));
	SetActive(true);

	// アニメーション生成
	anim = new AnimationManager();
	anim->LoadXFile(fileName, "Player");

	// アニメーションセット作成
	for (int i = 0; i < State::Max; i++)
	{
		anim->LoadAnimation(data[State(i)].tag, i, data[State(i)].shiftTime);
		anim->SetPlaySpeed(i, data[State(i)].playSpeed);
		anim->SetDeltaTime(i, data[State(i)].deltaTime);
	}

	// アニメーション遷移のセット
	for (int i = 0; i < State::Max; i++)
	{
		anim->SetFinishTransition(State(i), State(0));
	}
}

//=====================================
// デストラクタ
//=====================================
PlayerActor::~PlayerActor()
{
	SAFE_DELETE(anim);
}

//=====================================
// 更新
//=====================================
void PlayerActor::Update()
{
	anim->Update();
}

//=====================================
// 描画
//=====================================
void PlayerActor::Draw()
{
	if (!IsActive())
		return;

	D3DXMATRIX mtxWorld = transform->GetMatrix();
	transform->SetWorld();

	anim->Draw(&mtxWorld);
}

//=====================================
// アニメーションの切り替え
//=====================================
void PlayerActor::ChangeAnim(State next, bool animLoop)
{
	//ループ設定
	if (animLoop)
	{
		anim->SetFinishTransition(next, next);
	}
	else
	{
		anim->SetFinishTransition(next, State::Idle);
	}

	anim->ChangeAnim((UINT)next, true);
}
