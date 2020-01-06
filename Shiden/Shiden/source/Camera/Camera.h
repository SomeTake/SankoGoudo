//=====================================
//
// カメラ[Camera.h]
// 役割：カメラ
// Author:GP12B332 19 染谷武志
//
//=====================================
#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "../../Main.h"
#include "../Core/GameObject.h"

//****************************************************
// クラス定義
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

	// ワールド→スクリーン
	D3DXVECTOR3 Projection(const D3DXVECTOR3& pos);

	// スクリーン→ワールド
	D3DXVECTOR3 UnProjecttion(const D3DXVECTOR3& pos, float z);

	// ビュー行列取得
	D3DXMATRIX GetViewMtx()const;

	// ビュー逆行列取得
	D3DXMATRIX GetInverseViewMxt();

	// プロジェクション行列取得
	D3DXMATRIX GetProjectionMtx()const;

	// 代入演算子のオーバーロード
	Camera& operator=(const Camera& rhs);

protected:
	// 視野角、アスペクト比、ニア値、ファー値
	float viewAngle, viewAspect, viewNear, viewFar;
	// ビュー、プロジェクション、ビューポート行列
	D3DXMATRIX view, proj, viewport;
	D3DXMATRIX VPV;
	// ビュー、プロジェクション、ビューポート逆行列
	D3DXMATRIX inView, inProj, inViewport;
	D3DXMATRIX inVPV;

	// メインカメラのインスタンス
	static Camera* mainCamera;

};

#endif
