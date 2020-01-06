//=====================================
//
// ���b�V�����\�[�X[MeshResource.h]
// �����F���b�V���f�[�^�ۊ�
// Author:GP12B332 19 ���J���u
//
//=====================================
#ifndef _MESHRESOURCE_H_
#define _MESHRESOURCE_H_

#include "../../main.h"
#include <string>
#include <vector>

//****************************************************
// �O���錾
//****************************************************
class MeshContainer;

//****************************************************
// �N���X��`
//****************************************************
class MeshResource
{
public:
	MeshResource(const std::string& path);
	~MeshResource();

	void Clone(MeshContainer* container);
	void OnRelease();

private:
	LPD3DXMESH mesh;
	std::vector<D3DMATERIAL9> materials;
	std::vector<LPDIRECT3DTEXTURE9> textures;
	DWORD materialNum;

	unsigned cntRef;
};
#endif