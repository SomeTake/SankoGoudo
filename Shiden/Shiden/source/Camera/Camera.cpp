//=====================================
//
// �J����[Camera.cpp]
// �����F�J����
// Author:GP12B332 19 ���J���u
//
//=====================================
#include "Camera.h"

//=====================================
// �X�^�e�B�b�N�����o������
//=====================================
Camera* Camera::mainCamera = NULL;

//=====================================
// �R���X�g���N�^
//=====================================
Camera::Camera()
{
	const D3DXVECTOR3 initPos = D3DXVECTOR3(2500.0f, 100.0f, -2600.0f);
	const D3DXVECTOR3 initTarget = D3DXVECTOR3(2500.0f, 0.0f, -2500.0f);
	const float initViewAngle = D3DXToRadian(60);
	const float initViewAspect = (float)SCREEN_WIDTH / (float)SCREEN_HEIGHT;
	const float initViewNear = 10.0f;
	const float initViewFar = 50000.0f;

	transform->SetPosition(initPos);
	transform->LookAt(initTarget);
	viewAngle = initViewAngle;
	viewAspect = initViewAspect;
	viewNear = initViewNear;
	viewFar = initViewFar;

	D3DXMatrixIdentity(&viewport);
	viewport._11 = SCREEN_WIDTH / 2.0f;
	viewport._22 = -SCREEN_HEIGHT / 2.0f;
	viewport._41 = SCREEN_WIDTH / 2.0f;
	viewport._42 = SCREEN_HEIGHT / 2.0f;

	D3DXMatrixInverse(&inVPV, NULL, &VPV);

	Set();
}

//=====================================
// �f�X�g���N�^
//=====================================
Camera::~Camera()
{
}

//=====================================
// �X�V
//=====================================
void Camera::Update()
{
	D3DXVECTOR3 eyeposition = transform->GetPosition();
	D3DXVECTOR3 targetposition = eyeposition + transform->Forward();
	D3DXVECTOR3 upVector = transform->Up();

	// �r���[�s��쐬
	D3DXMatrixIdentity(&view);
	D3DXMatrixLookAtLH(&view, &eyeposition, &targetposition, &upVector);

	// �v���W�F�N�V�����s��쐬
	D3DXMatrixIdentity(&proj);
	D3DXMatrixPerspectiveFovLH(&proj, viewAngle, viewAspect, viewNear, viewFar);

	// �ϊ��s��
	VPV = view * proj * viewport;

	// �t�s��̌v�Z
	D3DXMatrixInverse(&inView, NULL, &view);
	D3DXMatrixInverse(&inProj, NULL, &proj);
	D3DXMatrixInverse(&inVPV, NULL, &VPV);
}

//=====================================
// �J�����̏����Z�b�g
//=====================================
void Camera::Set()const
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();

	// �r���[�s��ݒ�
	pDevice->SetTransform(D3DTS_VIEW, &view);

	// �v���W�F�N�V�����s��ݒ�
	pDevice->SetTransform(D3DTS_PROJECTION, &proj);
}

//=====================================
// ���������C���J�����Ƃ��ăZ�b�g
//=====================================
void Camera::SetMainCamera(Camera * camera)
{
	mainCamera = camera;
}

//=====================================
// ���C���J�����̏����擾
//=====================================
const Camera * Camera::MainCamera()
{
	return mainCamera;
}

//=====================================
// ���[���h���W���X�N���[�����W�ɕϊ����Ď擾
//=====================================
D3DXVECTOR3 Camera::Projection(const D3DXVECTOR3 & pos)
{
	D3DXVECTOR3 out;
	D3DXVec3TransformCoord(&out, &pos, &mainCamera->VPV);
	return out;
}

//=====================================
// �X�N���[�����W�����[���h���W�ɕϊ����Ď擾
//=====================================
D3DXVECTOR3 Camera::UnProjecttion(const D3DXVECTOR3 & pos, float z)
{
	D3DXVECTOR3 out;
	D3DXVec3TransformCoord(&out, &D3DXVECTOR3(pos.x, pos.y, z), &mainCamera->inVPV);
	return out;
}

//=====================================
// �r���[�s����擾
//=====================================
D3DXMATRIX Camera::GetViewMtx()const
{
	return mainCamera->view;
}

//=====================================
// �r���[�t�s����擾
//=====================================
D3DXMATRIX Camera::GetInverseViewMxt()
{
	return mainCamera->inView;
}

//=====================================
// �v���W�F�N�V�����s����擾
//=====================================
D3DXMATRIX Camera::GetProjectionMtx()const
{
	return mainCamera->proj;
}

//=====================================
// ������Z�q�̃I�[�o�[���[�h
//=====================================
Camera & Camera::operator=(const Camera & rhs)
{
	*(this->transform) = *(rhs.transform);
	this->viewAngle = rhs.viewAngle;
	this->viewAspect = rhs.viewAspect;
	this->viewNear = rhs.viewNear;
	this->viewFar = rhs.viewFar;
	this->view = rhs.view;
	this->proj = rhs.proj;

	return *this;
}
