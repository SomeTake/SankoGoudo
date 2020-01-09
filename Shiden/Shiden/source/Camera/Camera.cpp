//=====================================
//
// カメラ[Camera.cpp]
// 役割：カメラ
// Author:GP12B332 19 染谷武志
//
//=====================================
#include "Camera.h"

//=====================================
// スタティックメンバ初期化
//=====================================
Camera* Camera::mainCamera = NULL;

//=====================================
// コンストラクタ
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
// デストラクタ
//=====================================
Camera::~Camera()
{
}

//=====================================
// 更新
//=====================================
void Camera::Update()
{
	D3DXVECTOR3 eyeposition = transform->GetPosition();
	D3DXVECTOR3 targetposition = eyeposition + transform->Forward();
	D3DXVECTOR3 upVector = transform->Up();

	// ビュー行列作成
	D3DXMatrixIdentity(&view);
	D3DXMatrixLookAtLH(&view, &eyeposition, &targetposition, &upVector);

	// プロジェクション行列作成
	D3DXMatrixIdentity(&proj);
	D3DXMatrixPerspectiveFovLH(&proj, viewAngle, viewAspect, viewNear, viewFar);

	// 変換行列
	VPV = view * proj * viewport;

	// 逆行列の計算
	D3DXMatrixInverse(&inView, NULL, &view);
	D3DXMatrixInverse(&inProj, NULL, &proj);
	D3DXMatrixInverse(&inVPV, NULL, &VPV);
}

//=====================================
// カメラの情報をセット
//=====================================
void Camera::Set()const
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();

	// ビュー行列設定
	pDevice->SetTransform(D3DTS_VIEW, &view);

	// プロジェクション行列設定
	pDevice->SetTransform(D3DTS_PROJECTION, &proj);
}

//=====================================
// 引数をメインカメラとしてセット
//=====================================
void Camera::SetMainCamera(Camera * camera)
{
	mainCamera = camera;
}

//=====================================
// メインカメラの情報を取得
//=====================================
const Camera * Camera::MainCamera()
{
	return mainCamera;
}

//=====================================
// ワールド座標をスクリーン座標に変換して取得
//=====================================
D3DXVECTOR3 Camera::Projection(const D3DXVECTOR3 & pos)
{
	D3DXVECTOR3 out;
	D3DXVec3TransformCoord(&out, &pos, &mainCamera->VPV);
	return out;
}

//=====================================
// スクリーン座標をワールド座標に変換して取得
//=====================================
D3DXVECTOR3 Camera::UnProjecttion(const D3DXVECTOR3 & pos, float z)
{
	D3DXVECTOR3 out;
	D3DXVec3TransformCoord(&out, &D3DXVECTOR3(pos.x, pos.y, z), &mainCamera->inVPV);
	return out;
}

//=====================================
// ビュー行列を取得
//=====================================
D3DXMATRIX Camera::GetViewMtx()const
{
	return mainCamera->view;
}

//=====================================
// ビュー逆行列を取得
//=====================================
D3DXMATRIX Camera::GetInverseViewMxt()
{
	return mainCamera->inView;
}

//=====================================
// プロジェクション行列を取得
//=====================================
D3DXMATRIX Camera::GetProjectionMtx()const
{
	return mainCamera->proj;
}

//=====================================
// 代入演算子のオーバーロード
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
