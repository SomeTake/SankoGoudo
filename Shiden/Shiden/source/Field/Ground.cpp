//=====================================
//
// �O���E���h[Ground.cpp]
// �����F�n��
// Author:GP12B332 19 ���J���u
//
//=====================================
#include "Ground.h"
#include "GroundChip.h"
#include <fstream>
#include <string>

//=====================================
// �X�^�e�B�b�N�����o������
//=====================================
const char* Ground::data = "data/Map/Field.csv";

//=====================================
// �R���X�g���N�^
//=====================================
Ground::Ground()
{
	// �������m��
	groundData.reserve(50);
	for (int i = 0; i < 50; i++)
	{
		std::vector<int> vecX;
		groundData.push_back(vecX);
		groundData.at(i).reserve(50);
	}

	// CSV�f�[�^�ǂݍ���
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
// �f�X�g���N�^
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
// �X�V
//=====================================
void Ground::Update()
{
	for (auto&& vec : chipVec)
	{
		vec->Update();
	}
}

//=====================================
// �`��
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
// ���W������ꏊ�̒n�ʂ̎�ނ��擾
//=====================================
Ground::Type Ground::ChieckType(const D3DXVECTOR3 & pos)
{
	int x = ((int)pos.x + 50) / 100;
	int z = abs((int(pos.z) - 50) / 100);

	return Type(groundData.at(z).at(x));
}

//=====================================
// CSV�f�[�^�ǂݍ���
//=====================================
void Ground::LoadCSV()
{
	std::ifstream layerData(data);
	std::string layerLine;
	const char delim = ',';	// ��؂蕶��
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
