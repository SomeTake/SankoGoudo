//=============================================================================
//
// �Q�[���I�u�W�F�N�g [GameObject.h]
// �����F�Q�[���I�u�W�F�N�g�p���N���X
// Author:GP12B332 19 ���J���u
//
//=============================================================================
#ifndef _GAMEOBJECT_H_
#define _GAMEOBJECT_H_

#include "Transform.h"
#include <memory>

//****************************************************
// �N���X��`
//****************************************************
class GameObject
{
	friend class Tween;
public:
	GameObject();
	GameObject(const GameObject& gameObject);
	GameObject(const Transform& transform);
	GameObject(const bool& active);
	GameObject(const Transform& transform, const bool& active);
	GameObject(Transform* transform);
	GameObject(Transform* transform, const bool& active);
	virtual ~GameObject();

	// ������Z�q�̃I�[�o�[���[�h
	virtual GameObject& operator=(const GameObject& object);

	// �A�N�e�B�u
	bool IsActive();
	void SetActive(bool active);

	// �g�����X�t�H�[���֘A�Q�b�^�[�Z�b�^�[
	virtual D3DXVECTOR3 GetPosition();
	virtual D3DXVECTOR3 GetRotation();
	virtual D3DXVECTOR3 GetScale();
	virtual Transform GetTransform();

	virtual void SetPosition(const D3DXVECTOR3& pos);
	virtual void SetRotation(const D3DXVECTOR3& rot);
	virtual void SetScale(const D3DXVECTOR3& scl);
	virtual void SetTransform(const Transform& trans);

protected:
	bool isActive;

	std::shared_ptr<Transform> transform;
};

#endif