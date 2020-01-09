//=============================================================================
//
// シーンマネージャ[SceneManager.cpp]
// Author : GP12B332 19 染谷武志
//
//=============================================================================
#include "SceneManager.h"
#include "SceneTitle.h"
#include "SceneGame.h"
#include "SceneResult.h"
#include "../Camera/Camera.h"
#include "../Effect/SpriteEffect.h"
#include "../Player/PlayerController.h"
#include "../Field/FieldController.h"
#include "../Resource/ResourceManager.h"

//==========================================
// コンストラクタ
//==========================================
SceneManager::SceneManager()
{
	// ステートマシンの作成
	fsm.resize(State::Max, NULL);
	fsm[State::Title] = new SceneTitle();
	fsm[State::Game] = new SceneGame();
	fsm[State::Result] = new SceneResult();

	// リソースの読み込み
	ResourceManager::Instance()->MakePolygon("White", "data/Texture/White.png", D3DXVECTOR2(50.0f, 50.0f));

	// インスタンスの作成
	camera = new Camera();
	Camera::SetMainCamera(camera);
	playerController = new PlayerController(1);
	fieldController = new FieldController();

	// 初期シーンを設定
	ChangeState(State::Game);
}

//==========================================
// デストラクタ
//==========================================
SceneManager::~SceneManager()
{
	// ステートマシンの削除
	for (auto&& p : fsm)
	{
		delete p;
		p = NULL;
	}
	fsm.clear();

	// インスタンス削除
	SAFE_DELETE(camera);
	SAFE_DELETE(playerController);
	SAFE_DELETE(fieldController);
}

//==========================================
// 更新
//==========================================
void SceneManager::Update()
{
	// カメラ更新
	camera->Update();

	// 情報をシェーダーに渡す
	SpriteEffect::SetView(camera->GetViewMtx());
	SpriteEffect::SetProjection(camera->GetProjectionMtx());

	// ステートマシンの更新
	State next = fsm[currentState]->OnUpdate(*this);
}

//==========================================
// 描画
//==========================================
void SceneManager::Draw()
{
	Camera::MainCamera()->Set();

	// ステートマシンの描画
	fsm[currentState]->OnDraw(*this);
}

//==========================================
// ステートの変更
//==========================================
void SceneManager::ChangeState(State next)
{
	prevState = currentState;

	currentState = next;

	if (fsm[currentState] != NULL)
	{
		fsm[currentState]->OnStart(*this);
	}
}
