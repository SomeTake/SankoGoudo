//=============================================================================
//
// トランスフォーム [Transform.h]
// 役割：座標、スケール、回転計算
// Author:GP12B332 19 染谷武志
//
//=============================================================================
#ifndef _TRANSFORM_H_
#define _TRANSFORM_H_

#include "../../Main.h"

//****************************************************
// クラス定義
//****************************************************
class Transform
{
protected:
	D3DXVECTOR3 pos;	// 座標
	D3DXVECTOR3 scl;	// 大きさ
	D3DXQUATERNION rot;	// 回転

public:
	Transform();
	Transform(D3DXVECTOR3 pos, D3DXVECTOR3 rot, D3DXVECTOR3 scl);
	Transform(const Transform& trans);
	virtual ~Transform() {}

	// 代入演算子のオーバーロード
	virtual Transform operator =(const Transform& trans);

	// 移動
	virtual void Move(const D3DXVECTOR3& velocity);
	virtual void SetPosition(const D3DXVECTOR3& pos);
	virtual D3DXVECTOR3 GetPosition();

	// 回転
	virtual void Rotate(float degX, float degY, float degZ);
	virtual void SetRotation(const D3DXVECTOR3& rot);
	virtual void SetRotation(const D3DXQUATERNION& rot);
	virtual D3DXQUATERNION GetRotation();
	virtual D3DXVECTOR3 GetEulerAngle();

	// スケール
	virtual void Scale(const D3DXVECTOR3& delta);
	virtual void SetScale(const D3DXVECTOR3& scale);
	virtual D3DXVECTOR3 GetScale();

	// 向き
	virtual D3DXVECTOR3 Forward();
	virtual D3DXVECTOR3 Back();
	virtual D3DXVECTOR3 Right();
	virtual D3DXVECTOR3 Left();
	virtual D3DXVECTOR3 Up();
	virtual D3DXVECTOR3 Down();

	// ワールド変換
	virtual void SetWorld(const D3DXMATRIX* parent = NULL);
	virtual D3DXMATRIX GetMatrix();

	// 指定の位置に向かせる
	virtual void LookAt(const D3DXVECTOR3& target);
};

#endif
