//=====================================
//
// グラウンドチップ[GroundChip.cpp]
// 役割：地面のチップ
// Author:GP12B332 19 染谷武志
//
//=====================================
#include "GroundChip.h"
#include "../Resource/BoardPolygon.h"
#include "../Resource/ResourceManager.h"

//=====================================
// コンストラクタ
//=====================================
GroundChip::GroundChip(D3DXVECTOR3 pos, Ground::Type id)
{
	chipID = id;

	switch (chipID)
	{
	case Ground::Type::Road:
		polygon = new BoardPolygon();
		ResourceManager::Instance()->GetPolygon("White", polygon);
		polygon->SetDiffuse(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
		transform->SetPosition(pos);
		transform->Rotate(90.0f, 0.0f, 0.0f);
		//transform->SetScale(D3DXVECTOR3(100.0f, 100.0f, 0.0f));
		break;
	case Ground::Type::None:
		break;
	default:
		break;
	}
}

//=====================================
// デストラクタ
//=====================================
GroundChip::~GroundChip()
{
	SAFE_DELETE(polygon);
}

//=====================================
// 更新
//=====================================
void GroundChip::Update()
{
}

//=====================================
// 描画
//=====================================
void GroundChip::Draw()
{
	if (chipID == Ground::Type::None)
		return;

	D3DXMATRIX mtx = transform->GetMatrix();
	polygon->Draw(mtx);
}
