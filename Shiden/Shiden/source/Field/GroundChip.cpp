//=====================================
//
// �O���E���h�`�b�v[GroundChip.cpp]
// �����F�n�ʂ̃`�b�v
// Author:GP12B332 19 ���J���u
//
//=====================================
#include "GroundChip.h"
#include "../Resource/BoardPolygon.h"
#include "../Resource/ResourceManager.h"

//=====================================
// �R���X�g���N�^
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
// �f�X�g���N�^
//=====================================
GroundChip::~GroundChip()
{
	SAFE_DELETE(polygon);
}

//=====================================
// �X�V
//=====================================
void GroundChip::Update()
{
}

//=====================================
// �`��
//=====================================
void GroundChip::Draw()
{
	if (chipID == Ground::Type::None)
		return;

	D3DXMATRIX mtx = transform->GetMatrix();
	polygon->Draw(mtx);
}
