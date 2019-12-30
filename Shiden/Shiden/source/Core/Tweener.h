//=============================================================================
//
// �g�D�C�[�i�[ [Tweener.h]
// �����F�g�D�C�[�������N���X
// Author:GP12B332 19 ���J���u
//
//=============================================================================
#ifndef _TWEENER_H_
#define _TWEENER_H_

#include "Tween.h"

//****************************************************
// �N���X��`
//****************************************************
class Tween::Tweener :
	public Tween
{
public:
	Tweener(std::shared_ptr<Transform>& ref, int duration, EaseType type, Tween::Callback callback);
	virtual ~Tweener();
	bool IsFinished();
	virtual void Update() = 0;
	inline void CheckCallback();
};

//****************************************************
// �N���X��`
//****************************************************
class MoveTweener :
	public Tween::Tweener
{
public:
	MoveTweener(std::shared_ptr<Transform>& ref, const D3DXVECTOR3& start, const D3DXVECTOR3& end, int duration, EaseType type, Tween::Callback callback);
	void Update()override;

private:
	D3DXVECTOR3 start, end;
};

//****************************************************
// �N���X��`
//****************************************************
class ScaleTweener :
	public Tween::Tweener
{
public:
	ScaleTweener(std::shared_ptr<Transform>& ref, const D3DXVECTOR3& start, const D3DXVECTOR3& end, int duration, EaseType type, Tween::Callback callback);
	void Update()override;

private:
	D3DXVECTOR3 start, end;
};

//****************************************************
// �N���X��`
//****************************************************
class RotateTweener :
	public Tween::Tweener
{
public:
	RotateTweener(std::shared_ptr<Transform>& ref, const D3DXVECTOR3& start, const D3DXVECTOR3& end, int duration, EaseType type, Tween::Callback callback);
	RotateTweener(std::shared_ptr<Transform>& ref, const D3DXQUATERNION& start, const D3DXQUATERNION& end, int duration, EaseType type, Tween::Callback callback);
	void Update()override;

private:
	D3DXQUATERNION start, end;
};

#endif