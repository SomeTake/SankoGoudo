//=============================================================================
//
// ゲームオブジェクト [GameObject.h]
// 役割：ゲームオブジェクト用基底クラス
// Author:GP12B332 19 染谷武志
//
//=============================================================================
#ifndef _GAMEOBJECT_H_
#define _GAMEOBJECT_H_

#include "Transform.h"
#include <memory>

//****************************************************
// クラス定義
//****************************************************
class GameObject
{
	friend class Tween;
public:
	GameObject();
	GameObject(const GameObject& gameObject);
	GameObject(const Transform& transform);
	GameObject(const bool& active);
	GameObject(const Transform& transform, const bool& active);
	GameObject(Transform* transform);
	GameObject(Transform* transform, const bool& active);
	virtual ~GameObject();

	// 代入演算子のオーバーロード
	virtual GameObject& operator=(const GameObject& object);

	// アクティブ
	bool IsActive();
	void SetActive(bool active);

	// トランスフォーム関連ゲッターセッター
	virtual D3DXVECTOR3 GetPosition();
	virtual D3DXVECTOR3 GetRotation();
	virtual D3DXVECTOR3 GetScale();
	virtual Transform GetTransform();

	virtual void SetPosition(const D3DXVECTOR3& pos);
	virtual void SetRotation(const D3DXVECTOR3& rot);
	virtual void SetScale(const D3DXVECTOR3& scl);
	virtual void SetTransform(const Transform& trans);

protected:
	bool isActive;

	std::shared_ptr<Transform> transform;
};

#endif