//=============================================================================
//
// プレイヤーコントローラ[PlayerController.h]
// 役割：プレイヤー操作
// Author:GP12B332 19 染谷武志
//
//=============================================================================
#ifndef _PLAYERCONTROLLER_H_
#define _PLAYERCONTROLLER_H_

class PlayerActor;

//****************************************************
// クラス定義
//****************************************************
class PlayerController
{
public:
	PlayerController(int ctrlNo);
	~PlayerController();

	void Update();
	void Draw();

private:
	PlayerActor* actor;		// アクターのインスタンス
	int controllerNo;		// コントローラ番号

	// 操作
	void Move();
};

#endif