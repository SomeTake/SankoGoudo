//=============================================================================
//
// �g�����X�t�H�[�� [Transform.h]
// �����F���W�A�X�P�[���A��]�v�Z
// Author:GP12B332 19 ���J���u
//
//=============================================================================
#ifndef _TRANSFORM_H_
#define _TRANSFORM_H_

#include "../../Main.h"

//****************************************************
// �N���X��`
//****************************************************
class Transform
{
protected:
	D3DXVECTOR3 pos;	// ���W
	D3DXVECTOR3 scl;	// �傫��
	D3DXQUATERNION rot;	// ��]

public:
	Transform();
	Transform(D3DXVECTOR3 pos, D3DXVECTOR3 rot, D3DXVECTOR3 scl);
	Transform(const Transform& trans);
	virtual ~Transform() {}

	// ������Z�q�̃I�[�o�[���[�h
	virtual Transform operator =(const Transform& trans);

	// �ړ�
	virtual void Move(const D3DXVECTOR3& velocity);
	virtual void SetPosition(const D3DXVECTOR3& pos);
	virtual D3DXVECTOR3 GetPosition();

	// ��]
	virtual void Rotate(float degX, float degY, float degZ);
	virtual void SetRotation(const D3DXVECTOR3& rot);
	virtual void SetRotation(const D3DXQUATERNION& rot);
	virtual D3DXQUATERNION GetRotation();
	virtual D3DXVECTOR3 GetEulerAngle();

	// �X�P�[��
	virtual void Scale(const D3DXVECTOR3& delta);
	virtual void SetScale(const D3DXVECTOR3& scale);
	virtual D3DXVECTOR3 GetScale();

	// ����
	virtual D3DXVECTOR3 Forward();
	virtual D3DXVECTOR3 Back();
	virtual D3DXVECTOR3 Right();
	virtual D3DXVECTOR3 Left();
	virtual D3DXVECTOR3 Up();
	virtual D3DXVECTOR3 Down();

	// ���[���h�ϊ�
	virtual void SetWorld(const D3DXMATRIX* parent = NULL);
	virtual D3DXMATRIX GetMatrix();

	// �w��̈ʒu�Ɍ�������
	virtual void LookAt(const D3DXVECTOR3& target);
};

#endif
