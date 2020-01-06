//=====================================
//
// プレイヤーアクター[PlayerActor.h]
// 役割：操作用アクター表示処理
// Author:GP12B332 19 染谷武志
//
//=====================================
#ifndef _PLAYERACTOR_H_
#define _PLAYERACTOR_H_

#include "../Core/GameObject.h"
#include "../Resource/AnimationManager.h"

//****************************************************
// クラス定義
//****************************************************
class PlayerActor :
	public GameObject
{
public:
	// アニメーションステート
	enum State
	{
		Idle,
		Running,
		Max
	};

	// アニメーションデータ
	struct Data {
		const char* tag;
		float playSpeed;
		float shiftTime;
		float deltaTime;
	};

	PlayerActor();
	~PlayerActor();

	void Update();
	void Draw();

	// アニメーションの切り替え
	void ChangeAnim(State next, bool animLoop = false);

private:
	AnimationManager* anim;
	static const char* fileName;
	static const Data data[State::Max];
};

#endif
