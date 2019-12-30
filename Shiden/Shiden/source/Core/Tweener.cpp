//=============================================================================
//
// トゥイーナー [Tweener.cpp]
// 役割：トゥイーン内部クラス
// Author:GP12B332 19 染谷武志
//
//=============================================================================
#include "Tweener.h"

//==========================================
// コンストラクタ
//==========================================
Tween::Tweener::Tweener(std::shared_ptr<Transform>& ref, int duration, EaseType type, Tween::Callback callback)
{
	this->reference = ref;
	this->cntFrame = 0;
	this->duration = duration;
	this->type = type;
	this->callback = callback;
}

//==========================================
// デストラクタ
//==========================================
Tween::Tweener::~Tweener()
{
	reference.reset();
}

//==========================================
// 終了判定
//==========================================
bool Tween::Tweener::IsFinished()
{
	if (reference.expired())
		return true;

	return cntFrame >= duration;
}

//==========================================
// コールバック使用判定
//==========================================
inline void Tween::Tweener::CheckCallback()
{
	if (cntFrame < duration)
		return;

	if (callback == nullptr)
		return;

	callback();
}

//==========================================
// コンストラクタ
//==========================================
MoveTweener::MoveTweener(std::shared_ptr<Transform>& ref, const D3DXVECTOR3 & start, const D3DXVECTOR3 & end, int duration, EaseType type, Tween::Callback callback) :
	Tween::Tweener(ref, duration, type, callback)
{
	this->start = start;
	this->end = end;
}

//==========================================
// 更新
//==========================================
void MoveTweener::Update()
{
	cntFrame++;

	std::shared_ptr<Transform> transform = reference.lock();
	if (transform)
	{
		float time = (float)cntFrame / duration;
		transform->SetPosition(Easing::EaseValue(time, start, end, type));
		CheckCallback();
	}
}

//==========================================
// コンストラクタ
//==========================================
ScaleTweener::ScaleTweener(std::shared_ptr<Transform>& ref, const D3DXVECTOR3 & start, const D3DXVECTOR3 & end, int duration, EaseType type, Tween::Callback callback) :
	Tween::Tweener(ref, duration, type, callback)
{
	this->start = start;
	this->end = end;
}

//==========================================
// 更新
//==========================================
void ScaleTweener::Update()
{
	cntFrame++;

	std::shared_ptr<Transform> transform = reference.lock();
	if (transform)
	{
		float t = (float)cntFrame / duration;
		transform->SetScale(Easing::EaseValue(t, start, end, type));
		CheckCallback();
	}
}

//==========================================
// コンストラクタ
//==========================================
RotateTweener::RotateTweener(std::shared_ptr<Transform>& ref, const D3DXVECTOR3 & start, const D3DXVECTOR3 & end, int duration, EaseType type, Tween::Callback callback) :
	Tween::Tweener(ref, duration, type, callback)
{
	this->start = Quaternion::FromEuler(start);
	this->end = Quaternion::FromEuler(end);
}

//==========================================
// コンストラクタ
//==========================================
RotateTweener::RotateTweener(std::shared_ptr<Transform>& ref, const D3DXQUATERNION & start, const D3DXQUATERNION & end, int duration, EaseType type, Tween::Callback callback) :
	Tween::Tweener(ref, duration, type, callback)
{
	this->start = start;
	this->end = end;
}

//==========================================
// 更新
//==========================================
void RotateTweener::Update()
{
	cntFrame++;

	std::shared_ptr<Transform> transform = reference.lock();
	if (transform)
	{
		float t = Easing::EaseValue((float)cntFrame / duration, 0.0f, 1.0f, type);
		D3DXQUATERNION quaternion;
		D3DXQuaternionSlerp(&quaternion, &start, &end, t);
		transform->SetRotation(quaternion);
		CheckCallback();
	}
}
