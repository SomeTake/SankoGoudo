//=====================================
//
// �O���E���h�`�b�v[GroundChip.h]
// �����F�n�ʂ̃`�b�v
// Author:GP12B332 19 ���J���u
//
//=====================================
#ifndef _GROUNDCHIP_H_
#define _GROUNDCHIP_H_

#include "../Core/GameObject.h"
#include "Ground.h"

class BoardPolygon;

//****************************************************
// �N���X��`
//****************************************************
class GroundChip :
	public GameObject
{
public:
	GroundChip(D3DXVECTOR3 pos, Ground::Type id);
	~GroundChip();

	void Update();
	void Draw();

private:
	BoardPolygon* polygon;
	Ground::Type chipID;	// �`�b�v�̓����ԍ���ۑ�
};

#endif
