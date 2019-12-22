//=============================================================================
//
// �X�e�[�g�}�V�� [BaseState.h]
// Author:GP12B332 19 ���J���u
//
//=============================================================================
#ifndef _BASESTATE_H_
#define _BASESTATE_H_

//****************************************************
// �e���v���[�g�N���X��`
//****************************************************
template <class T, class ENUM>
class BaseState
{
public:
	virtual void OnStart(T& entity) = 0;	// ����
	virtual ENUM OnUpdate(T& entity) = 0;	// �X�V
	virtual void OnDraw(T& entity) = 0;		// �`��
};

#endif
