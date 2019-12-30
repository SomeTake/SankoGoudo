//=============================================================================
//
// �g�����X�t�H�[�� [Transform.h]
// �����F���W�A�X�P�[���A��]�v�Z
// Author:GP12B332 19 ���J���u
//
//=============================================================================
#include "Transform.h"

//==========================================
// �R���X�g���N�^
//==========================================
Transform::Transform() :
	pos(D3DXVECTOR3(0.0f, 0.0f, 0.0f)), scl(D3DXVECTOR3 (1.0f, 1.0f, 1.0f)), rot(Quaternion::Identity)
{
}

//==========================================
// �R���X�g���N�^
//==========================================
Transform::Transform(D3DXVECTOR3 pos, D3DXVECTOR3 rot, D3DXVECTOR3 scl) :
	pos(pos), scl(scl), rot(Quaternion::Identity)
{
	D3DXQuaternionRotationYawPitchRoll(&this->rot, rot.y, rot.x, rot.z);
}

//==========================================
// �R���X�g���N�^
//==========================================
Transform::Transform(const Transform & trans) :
	pos(trans.pos), scl(trans.scl), rot(trans.rot)
{
}

//==========================================
// ������Z�q�̃I�[�o�[���[�h
//==========================================
Transform Transform::operator=(const Transform & trans)
{
	pos = trans.pos;
	rot = trans.rot;
	scl = trans.scl;

	return *this;
}

//==========================================
// ���W�̈ړ��i�ړ��ʎw��j
//==========================================
void Transform::Move(const D3DXVECTOR3 & velocity)
{
	pos += velocity;
}

//==========================================
// ���W�̃Z�b�g�i���W�w��j
//==========================================
void Transform::SetPosition(const D3DXVECTOR3 & pos)
{
	this->pos = pos;
}

//==========================================
// ���W�̎擾
//==========================================
D3DXVECTOR3 Transform::GetPosition()
{
	return pos;
}

//==========================================
// ��]�i�f�B�O���[�x�j
//==========================================
void Transform::Rotate(float degX, float degY, float degZ)
{
	D3DXQUATERNION q;
	D3DXQuaternionRotationYawPitchRoll(&q, D3DXToRadian(degY), D3DXToRadian(degX), D3DXToRadian(degZ));
	D3DXQuaternionMultiply(&rot, &rot, &q);
}

//==========================================
// ��]�i�f�B�O���[�x�j
//==========================================
void Transform::SetRotation(const D3DXVECTOR3 & rot)
{
	this->rot = Quaternion::FromEuler(rot);
}

//==========================================
// ��]�i�N�H�[�^�j�I���j
//==========================================
void Transform::SetRotation(const D3DXQUATERNION & rot)
{
	this->rot = rot;
}

//==========================================
// �p�x�̎擾�i�N�H�[�^�j�I���j
//==========================================
D3DXQUATERNION Transform::GetRotation()
{
	return rot;
}

//==========================================
// �p�x�̎擾�i�I�C���[�p�j
//==========================================
D3DXVECTOR3 Transform::GetEulerAngle()
{
	return Quaternion::ToEuler(rot);
}

//==========================================
// �g��i���j
//==========================================
void Transform::Scale(const D3DXVECTOR3 & delta)
{
	scl.x *= delta.x;
	scl.y *= delta.y;
	scl.z *= delta.z;
}

//==========================================
// �g��i�{���w��j
//==========================================
void Transform::SetScale(const D3DXVECTOR3 & scale)
{
	scl = scale;
}

//==========================================
// ���݂̑傫���擾
//==========================================
D3DXVECTOR3 Transform::GetScale()
{
	return scl;
}

//==========================================
// �O������
//==========================================
D3DXVECTOR3 Transform::Forward()
{
	D3DXVECTOR3 forward = D3DXVECTOR3(0.0f, 0.0f, 1.0f);
	D3DXMATRIX rotation;

	D3DXMatrixRotationQuaternion(&rotation, &rot);
	D3DXVec3TransformCoord(&forward, &forward, &rotation);
	
	return forward;
}

//==========================================
// ��������
//==========================================
D3DXVECTOR3 Transform::Back()
{
	D3DXVECTOR3 back = D3DXVECTOR3(0.0f, 0.0f, -1.0f);
	D3DXMATRIX rotation;

	D3DXMatrixRotationQuaternion(&rotation, &rot);
	D3DXVec3TransformCoord(&back, &back, &rotation);

	return back;
}

//==========================================
// �E������
//==========================================
D3DXVECTOR3 Transform::Right()
{
	D3DXVECTOR3 right = D3DXVECTOR3(1.0f, 0.0f, 0.0f);
	D3DXMATRIX rotation;

	D3DXMatrixRotationQuaternion(&rotation, &rot);
	D3DXVec3TransformCoord(&right, &right, &rotation);

	return right;
}

//==========================================
// ��������
//==========================================
D3DXVECTOR3 Transform::Left()
{
	D3DXVECTOR3 left = D3DXVECTOR3(-1.0f, 0.0f, 0.0f);
	D3DXMATRIX rotation;

	D3DXMatrixRotationQuaternion(&rotation, &rot);
	D3DXVec3TransformCoord(&left, &left, &rotation);

	return left;
}

//==========================================
// �������
//==========================================
D3DXVECTOR3 Transform::Up()
{
	D3DXVECTOR3 up = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	D3DXMATRIX rotation;

	D3DXMatrixRotationQuaternion(&rotation, &rot);
	D3DXVec3TransformCoord(&up, &up, &rotation);

	return up;
}

//==========================================
// ��������
//==========================================
D3DXVECTOR3 Transform::Down()
{
	D3DXVECTOR3 down = D3DXVECTOR3(0.0f, -1.0f, 0.0f);
	D3DXMATRIX rotation;

	D3DXMatrixRotationQuaternion(&rotation, &rot);
	D3DXVec3TransformCoord(&down, &down, &rotation);

	return down;
}

//==========================================
// ���[���h�ϊ�
//==========================================
void Transform::SetWorld(const D3DXMATRIX * parent)
{
	D3DXMATRIX world = GetMatrix();
	LPDIRECT3DDEVICE9 pDevice = GetDevice();

	if (parent != NULL)
	{
		D3DXMatrixMultiply(&world, &world, parent);
	}

	pDevice->SetTransform(D3DTS_WORLD, &world);
}

//==========================================
// ���[���h���W�̎擾
//==========================================
D3DXMATRIX Transform::GetMatrix()
{
	D3DXMATRIX world;

	// ��]
	D3DXMatrixRotationQuaternion(&world, &rot);

	// �X�P�[��
	world._11 *= scl.x;
	world._12 *= scl.x;
	world._13 *= scl.x;

	world._21 *= scl.y;
	world._22 *= scl.y;
	world._23 *= scl.y;
	
	world._31 *= scl.z;
	world._32 *= scl.z;
	world._33 *= scl.z;

	// �ړ�
	world._41 = pos.x;
	world._42 = pos.y;
	world._43 = pos.z;

	return world;
}

//==========================================
// �w��̈ʒu�Ɍ�������
//==========================================
void Transform::LookAt(const D3DXVECTOR3 & target)
{
	D3DXVECTOR3 z = target - pos;
	D3DXVec3Normalize(&z, &z);

	D3DXVECTOR3 x;
	D3DXVec3Cross(&x, &D3DXVECTOR3(0.0f, 1.0f, 0.0f), &z);
	D3DXVec3Normalize(&x, &x);

	D3DXVECTOR3 y;
	D3DXVec3Cross(&y, &z, &x);
	D3DXVec3Normalize(&y, &y);

	D3DXMATRIX m;
	D3DXMatrixIdentity(&m);
	m._11 = x.x;
	m._12 = y.x;
	m._13 = z.x;

	m._21 = x.y;
	m._22 = y.y;
	m._23 = z.y;

	m._31 = x.z;
	m._32 = y.z;
	m._33 = z.z;

	D3DXQUATERNION q = Quaternion::GetRotation(m);
	rot = q;
}

