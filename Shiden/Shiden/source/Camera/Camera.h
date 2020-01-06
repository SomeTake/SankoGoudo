//=====================================
//
// �J����[Camera.h]
// �����F�J����
// Author:GP12B332 19 ���J���u
//
//=====================================
#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "../../Main.h"
#include "../Core/GameObject.h"

//****************************************************
// �N���X��`
//****************************************************
class Camera :
	public GameObject
{
public:
	Camera();
	virtual ~Camera();

	virtual void Update();
	virtual void Set()const;

	static void SetMainCamera(Camera* camera);
	static const Camera* MainCamera();

	// ���[���h���X�N���[��
	D3DXVECTOR3 Projection(const D3DXVECTOR3& pos);

	// �X�N���[�������[���h
	D3DXVECTOR3 UnProjecttion(const D3DXVECTOR3& pos, float z);

	// �r���[�s��擾
	D3DXMATRIX GetViewMtx()const;

	// �r���[�t�s��擾
	D3DXMATRIX GetInverseViewMxt();

	// �v���W�F�N�V�����s��擾
	D3DXMATRIX GetProjectionMtx()const;

	// ������Z�q�̃I�[�o�[���[�h
	Camera& operator=(const Camera& rhs);

protected:
	// ����p�A�A�X�y�N�g��A�j�A�l�A�t�@�[�l
	float viewAngle, viewAspect, viewNear, viewFar;
	// �r���[�A�v���W�F�N�V�����A�r���[�|�[�g�s��
	D3DXMATRIX view, proj, viewport;
	D3DXMATRIX VPV;
	// �r���[�A�v���W�F�N�V�����A�r���[�|�[�g�t�s��
	D3DXMATRIX inView, inProj, inViewport;
	D3DXMATRIX inVPV;

	// ���C���J�����̃C���X�^���X
	static Camera* mainCamera;

};

#endif
