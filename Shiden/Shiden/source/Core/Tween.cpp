//=============================================================================
//
// トゥイーン [Tween.cpp]
// 役割：トゥイーン用
// Author:GP12B332 19 染谷武志
//
//=============================================================================
#include "Tween.h"
#include "Tweener.h"

//==========================================
// コンストラクタ
//==========================================
Tween::Tween()
{
	if (mInstance == NULL)
	{
		mInstance = this;
	}
}

//==========================================
// デストラクタ
//==========================================
Tween::~Tween()
{
	mInstance->ClearAll();

	if (mInstance == this)
	{
		mInstance = NULL;
	}
}

//==========================================
// 更新
//==========================================
void Tween::Update()
{
	for (auto&& tweener : tweenerList)
	{
		tweener->Update();
	}

	ClearContainer();
}

//==========================================
// コンテナ削除
//==========================================
void Tween::ClearContainer()
{
	for (auto&& tweener : tweenerList)
	{
		if (!tweener->IsFinished())
			continue;

		SAFE_DELETE(tweener);
	}

	tweenerList.remove_if([](auto&& tweener) {
		return tweener == NULL;
	});
}

//==========================================
// 全削除
//==========================================
void Tween::ClearAll()
{
	for (auto&& tweener : tweenerList)
	{
		SAFE_DELETE(tweener);
	}
	tweenerList.clear();
}

