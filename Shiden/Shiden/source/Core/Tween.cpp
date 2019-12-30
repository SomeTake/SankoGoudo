//=============================================================================
//
// �g�D�C�[�� [Tween.cpp]
// �����F�g�D�C�[���p
// Author:GP12B332 19 ���J���u
//
//=============================================================================
#include "Tween.h"
#include "Tweener.h"

//==========================================
// �R���X�g���N�^
//==========================================
Tween::Tween()
{
	if (mInstance == NULL)
	{
		mInstance = this;
	}
}

//==========================================
// �f�X�g���N�^
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
// �X�V
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
// �R���e�i�폜
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
// �S�폜
//==========================================
void Tween::ClearAll()
{
	for (auto&& tweener : tweenerList)
	{
		SAFE_DELETE(tweener);
	}
	tweenerList.clear();
}

