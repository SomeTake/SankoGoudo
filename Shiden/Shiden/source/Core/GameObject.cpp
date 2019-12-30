//=============================================================================
//
// �Q�[���I�u�W�F�N�g [GameObject.cpp]
// �����F�Q�[���I�u�W�F�N�g�p���N���X
// Author:GP12B332 19 ���J���u
//
//=============================================================================
#include "GameObject.h"

//==========================================
// �R���X�g���N�^
//==========================================
GameObject::GameObject() :
	transform(std::make_shared<Transform>()),
	isActive(true)
{
}

//==========================================
// �R���X�g���N�^
//==========================================
GameObject::GameObject(const GameObject & gameObject) :
	transform(std::make_shared<Transform>(*gameObject.transform)),
	isActive(true)
{
}

//==========================================
// �R���X�g���N�^
//==========================================
GameObject::GameObject(const Transform & transform) :
	transform(std::make_shared<Transform>(transform)),
	isActive(true)
{
}

//==========================================
// �R���X�g���N�^
//==========================================
GameObject::GameObject(const bool & active) :
	transform(std::make_shared<Transform>()),
	isActive(active)
{
}

//==========================================
// �R���X�g���N�^
//==========================================
GameObject::GameObject(const Transform & transform, const bool & active) :
	transform(std::make_shared<Transform>(transform)),
	isActive(active)
{
}

//==========================================
// �R���X�g���N�^
//==========================================
GameObject::GameObject(Transform * transform) :
	isActive(true)
{
	this->transform.reset(transform);
}

//==========================================
// �R���X�g���N�^
//==========================================
GameObject::GameObject(Transform * transform, const bool & active) :
	isActive(active)
{
	this->transform.reset(transform);
}

//==========================================
// �f�X�g���N�^
//==========================================
GameObject::~GameObject()
{
	transform.reset();
}

//==========================================
// ������Z�q�̃I�[�o�[���[�h
//==========================================
GameObject & GameObject::operator=(const GameObject & object)
{
	std::shared_ptr<Transform> sptr = transform;
	transform.reset();
	transform = std::make_shared<Transform>(*object.transform);
	return *this;
}

bool GameObject::IsActive()
{
	return isActive;
}

void GameObject::SetActive(bool active)
{
	isActive = active;
}

D3DXVECTOR3 GameObject::GetPosition()
{
	return transform->GetPosition();
}

D3DXVECTOR3 GameObject::GetRotation()
{
	return transform->GetEulerAngle();
}

D3DXVECTOR3 GameObject::GetScale()
{
	return transform->GetScale();
}

Transform GameObject::GetTransform()
{
	return *transform;
}

void GameObject::SetPosition(const D3DXVECTOR3 & pos)
{
	transform->SetPosition(pos);
}

void GameObject::SetRotation(const D3DXVECTOR3 & rot)
{
	transform->SetRotation(rot);
}

void GameObject::SetScale(const D3DXVECTOR3 & scl)
{
	transform->SetScale(scl);
}

void GameObject::SetTransform(const Transform & trans)
{
	*this->transform = trans;
}
