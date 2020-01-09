//=====================================
//
// �O���E���h[Ground.cpp]
// �����F�n��
// Author:GP12B332 19 ���J���u
//
//=====================================
#ifndef _GROUND_H_
#define _GROUND_H_

#include "../../Main.h"
#include "FieldPosition.h"
#include <vector>

class GroundChip;

//****************************************************
// �N���X��`
//****************************************************
class Ground
{
public:
	// �n�ʂ̎��
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

	Type ChieckType(const D3DXVECTOR3& pos);	// ���W������ꏊ�̒n�ʂ̎�ނ��擾

private:
	static const char* data;					// CSV�f�[�^
	std::vector<std::vector<int>> groundData;	// CSV�f�[�^�ǂݍ��ݐ�
	int maxX, maxZ;								// �f�[�^�̐�
	std::vector<GroundChip*> chipVec;			// �C���X�^���X

	void LoadCSV();

};

#endif
