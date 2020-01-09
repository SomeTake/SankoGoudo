//=====================================
//
// グラウンド[Ground.cpp]
// 役割：地面
// Author:GP12B332 19 染谷武志
//
//=====================================
#include "Ground.h"
#include "GroundChip.h"
#include <fstream>
#include <string>

//=====================================
// スタティックメンバ初期化
//=====================================
const char* Ground::data = "data/Map/Field.csv";

//=====================================
// コンストラクタ
//=====================================
Ground::Ground()
{
	// メモリ確保
	groundData.reserve(50);
	for (int i = 0; i < 50; i++)
	{
		std::vector<int> vecX;
		groundData.push_back(vecX);
		groundData.at(i).reserve(50);
	}

	// CSVデータ読み込み
	LoadCSV();

	for (int z = 0; z < maxZ; z++)
	{
		for (int x = 0; x < maxX; x++)
		{
			Type token = (Type)groundData.at(z).at(x);
			if (token != Type::None)
			{
				chipVec.push_back(new GroundChip(D3DXVECTOR3(x * 100.0f, 0.0f, z * -100.0f), token));
			}
		}
	}
}

//=====================================
// デストラクタ
//=====================================
Ground::~Ground()
{
	for (auto&& vec : chipVec)
	{
		SAFE_DELETE(vec);
	}
	chipVec.clear();
	groundData.clear();
}

//=====================================
// 更新
//=====================================
void Ground::Update()
{
	for (auto&& vec : chipVec)
	{
		vec->Update();
	}
}

//=====================================
// 描画
//=====================================
void Ground::Draw()
{
	//chipVec[0]->Draw();
	for (auto&& vec : chipVec)
	{
		vec->Draw();
	}
}

//=====================================
// 座標がある場所の地面の種類を取得
//=====================================
Ground::Type Ground::ChieckType(const D3DXVECTOR3 & pos)
{
	int x = ((int)pos.x + 50) / 100;
	int z = abs((int(pos.z) - 50) / 100);

	return Type(groundData.at(z).at(x));
}

//=====================================
// CSVデータ読み込み
//=====================================
void Ground::LoadCSV()
{
	std::ifstream layerData(data);
	std::string layerLine;
	const char delim = ',';	// 区切り文字
	int x = 0;
	int z = 0;

	while (std::getline(layerData, layerLine))
	{
		x = 0;
		for (std::string::size_type spos, epos = 0;
			(spos = layerLine.find_first_not_of(delim, epos)) != std::string::npos;)
		{
			std::string token = layerLine.substr(spos, (epos = layerLine.find_first_of(delim, spos)) - spos);
			token;
			groundData.at(z).push_back(stoi(token));
			x++;
		}
		z++;
	}

	maxX = x;
	maxZ = z;
}
