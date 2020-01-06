//=====================================
//
// メッシュリソース[MeshResource.h]
// 役割：メッシュデータ保管
// Author:GP12B332 19 染谷武志
//
//=====================================
#ifndef _MESHRESOURCE_H_
#define _MESHRESOURCE_H_

#include "../../main.h"
#include <string>
#include <vector>

//****************************************************
// 前方宣言
//****************************************************
class MeshContainer;

//****************************************************
// クラス定義
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