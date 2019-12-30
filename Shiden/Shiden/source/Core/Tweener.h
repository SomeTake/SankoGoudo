//=============================================================================
//
// トゥイーナー [Tweener.h]
// 役割：トゥイーン内部クラス
// Author:GP12B332 19 染谷武志
//
//=============================================================================
#ifndef _TWEENER_H_
#define _TWEENER_H_

#include "Tween.h"

//****************************************************
// クラス定義
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
// クラス定義
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
// クラス定義
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
// クラス定義
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