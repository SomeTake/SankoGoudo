//=====================================
//
// グラウンドチップ[GroundChip.h]
// 役割：地面のチップ
// Author:GP12B332 19 染谷武志
//
//=====================================
#ifndef _GROUNDCHIP_H_
#define _GROUNDCHIP_H_

#include "../Core/GameObject.h"
#include "Ground.h"

class BoardPolygon;

//****************************************************
// クラス定義
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
	Ground::Type chipID;	// チップの内部番号を保存
};

#endif
