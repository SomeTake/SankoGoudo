//=============================================================================
//
// トゥイーン [Tween.h]
// 役割：トゥイーン用
// Author:GP12B332 19 染谷武志
//
//=============================================================================
#ifndef _TWEEN_H_
#define _TWEEN_H_

#include "../../Main.h"
#include "Easing.h"
#include "Transform.h"
#include "GameObject.h"
#include <functional>
#include <list>
#include "../DesignPattern/BaseSingleton.h"

//****************************************************
// クラス定義
//****************************************************
class Tween :
	public BaseSingleton<Tween>
{
	friend class Game;
public:
	// 移動
	static void Move(GameObject& ref, const D3DXVECTOR3& startPosition, const D3DXVECTOR3& endPosition, int duration, EaseType type, std::function<void(void)> callback = nullptr);
	static void Move(GameObject& ref, const D3DXVECTOR3& endPosition, int duration, EaseType type, std::function<void(void)> callback = nullptr);

	// スケール
	static void Scale(GameObject& ref, const D3DXVECTOR3& startScale, const D3DXVECTOR3& endScale, int duration, EaseType type, std::function<void(void)> callback = nullptr);
	static void Scale(GameObject& ref, const D3DXVECTOR3& endScale, int duration, EaseType type, std::function<void(void)> callback = nullptr);

	// 回転
	static void Rotate(GameObject& ref, const D3DXVECTOR3& startEulerAngle, const D3DXVECTOR3& endEulerAngle, int duration, EaseType type, std::function<void(void)> callback = nullptr);
	static void Rotate(GameObject& ref, const D3DXVECTOR3& endEulerAngle, int duration, EaseType type, std::function<void(void)> callback = nullptr);
	static void Turn(GameObject& ref, const D3DXVECTOR3& endDirection, int duration, EaseType type, const D3DXVECTOR3& dummyAxis, std::function<void(void)> callback = nullptr);

protected:
	// 内部クラスの前方宣言
	class Tweener;

	std::weak_ptr<Transform> reference;
	int cntFrame;
	int duration;
	EaseType type;
	using Callback = std::function<void(void)>;
	Callback callback;

private:
	static Tween* mInstance;
	Tween();
	~Tween();
	void Update();
	void ClearContainer();
	void ClearAll();

	std::list<Tween::Tweener*> tweenerList;
};

#endif
