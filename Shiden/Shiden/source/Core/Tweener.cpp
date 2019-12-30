//=============================================================================
//
// �g�D�C�[�i�[ [Tweener.cpp]
// �����F�g�D�C�[�������N���X
// Author:GP12B332 19 ���J���u
//
//=============================================================================
#include "Tweener.h"

//==========================================
// �R���X�g���N�^
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
// �f�X�g���N�^
//==========================================
Tween::Tweener::~Tweener()
{
	reference.reset();
}

//==========================================
// �I������
//==========================================
bool Tween::Tweener::IsFinished()
{
	if (reference.expired())
		return true;

	return cntFrame >= duration;
}

//==========================================
// �R�[���o�b�N�g�p����
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
// �R���X�g���N�^
//==========================================
MoveTweener::MoveTweener(std::shared_ptr<Transform>& ref, const D3DXVECTOR3 & start, const D3DXVECTOR3 & end, int duration, EaseType type, Tween::Callback callback) :
	Tween::Tweener(ref, duration, type, callback)
{
	this->start = start;
	this->end = end;
}

//==========================================
// �X�V
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
// �R���X�g���N�^
//==========================================
ScaleTweener::ScaleTweener(std::shared_ptr<Transform>& ref, const D3DXVECTOR3 & start, const D3DXVECTOR3 & end, int duration, EaseType type, Tween::Callback callback) :
	Tween::Tweener(ref, duration, type, callback)
{
	this->start = start;
	this->end = end;
}

//==========================================
// �X�V
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
// �R���X�g���N�^
//==========================================
RotateTweener::RotateTweener(std::shared_ptr<Transform>& ref, const D3DXVECTOR3 & start, const D3DXVECTOR3 & end, int duration, EaseType type, Tween::Callback callback) :
	Tween::Tweener(ref, duration, type, callback)
{
	this->start = Quaternion::FromEuler(start);
	this->end = Quaternion::FromEuler(end);
}

//==========================================
// �R���X�g���N�^
//==========================================
RotateTweener::RotateTweener(std::shared_ptr<Transform>& ref, const D3DXQUATERNION & start, const D3DXQUATERNION & end, int duration, EaseType type, Tween::Callback callback) :
	Tween::Tweener(ref, duration, type, callback)
{
	this->start = start;
	this->end = end;
}

//==========================================
// �X�V
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
