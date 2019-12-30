//=============================================================================
//
// �N�H�[�^�j�I�� [Quaternion.h]
// �����F�N�H�[�^�j�I���v�Z�p
// Author:GP12B332 19 ���J���u
//
//=============================================================================
#ifndef _QUATERNION_H_
#define _QUATERNION_H_

#include "../../Main.h"

//****************************************************
// �N���X��`
//****************************************************
class Quaternion
{
public:
	// �N�H�[�^�j�I������I�C���[�p�ւ̕ϊ�
	static D3DXVECTOR3 ToEuler(const D3DXQUATERNION& q);

	// �I�C���[�p����N�H�[�^�j�I���ւ̕ϊ�
	static D3DXQUATERNION FromEuler(const D3DXVECTOR3& e);

	// �ϊ��s�񂩂�N�H�[�^�j�I���ւ̕ϊ�
	static D3DXQUATERNION GetRotation(const D3DXMATRIX& mtx);

	// ������r����
	static bool Equal(const D3DXQUATERNION& q1, const D3DXQUATERNION& q2);

	// �P�ʃN�H�[�^�j�I���萔
	static D3DXQUATERNION Identity;

private:
	Quaternion();
};

#endif
