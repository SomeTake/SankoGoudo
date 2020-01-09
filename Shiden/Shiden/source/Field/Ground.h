//=====================================
//
// グラウンド[Ground.cpp]
// 役割：地面
// Author:GP12B332 19 染谷武志
//
//=====================================
#ifndef _GROUND_H_
#define _GROUND_H_

#include "../../Main.h"
#include "FieldPosition.h"
#include <vector>

class GroundChip;

//****************************************************
// クラス定義
//****************************************************
class Ground
{
public:
	// 地面の種類
	enum Type
	{
		Road = -1,
		None = 0,

		Max
	};

	Ground();
	~Ground();

	void Update();
	void Draw();

	Type ChieckType(const D3DXVECTOR3& pos);	// 座標がある場所の地面の種類を取得

private:
	static const char* data;					// CSVデータ
	std::vector<std::vector<int>> groundData;	// CSVデータ読み込み先
	int maxX, maxZ;								// データの数
	std::vector<GroundChip*> chipVec;			// インスタンス

	void LoadCSV();

};

#endif
