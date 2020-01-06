//=====================================
//
// ���b�V�����\�[�X[MeshResource.cpp]
// �����F���b�V���f�[�^�ۊ�
// Author:GP12B332 19 ���J���u
//
//=====================================
#include "MeshResource.h"
#include "MeshContainer.h"
#include "ResourceManager.h"

//=====================================
// �R���X�g���N�^
//=====================================
MeshResource::MeshResource(const std::string & path) :
	mesh(NULL),
	materialNum(0),
	cntRef(0)
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();
	LPD3DXBUFFER tmpMaterial;

	//X�t�@�C���ǂݍ���
	HRESULT res = D3DXLoadMeshFromX(path.c_str(),
		D3DXMESH_MANAGED,
		pDevice,
		NULL,
		&tmpMaterial,
		NULL,
		&materialNum,
		&mesh);

	if (res != S_OK)
		return;

	//�אڏ����쐬���čœK��
	std::vector<DWORD> adjList;
	adjList.resize(3 * mesh->GetNumFaces());
	mesh->GenerateAdjacency(1.0f / 512, &adjList[0]);
	mesh->OptimizeInplace(D3DXMESHOPT_ATTRSORT, &adjList[0], 0, 0, 0);

	//�}�e���A����D3DXMATERIAL�Ƃ��čœK��
	materials.resize(materialNum);
	D3DXMATERIAL* matBuffer = (D3DXMATERIAL*)tmpMaterial->GetBufferPointer();
	for (DWORD i = 0; i < materialNum; i++)
	{
		materials[i] = matBuffer[i].MatD3D;
	}

	//�e�N�X�`���ǂݍ���
	textures.resize(materialNum, NULL);
	const std::string DirectoryName = path.substr(0, path.find_last_of('/'));
	for (DWORD i = 0; i < materialNum; i++)
	{
		if (matBuffer[i].pTextureFilename == NULL)
			continue;

		std::string fileName = DirectoryName + "/" + std::string(matBuffer[i].pTextureFilename);
		ResourceManager::Instance()->LoadTexture(fileName.c_str());
		ResourceManager::Instance()->GetTexture(fileName.c_str(), textures[i]);
	}

	SAFE_RELEASE(tmpMaterial);
}

//=====================================
// �f�X�g���N�^
//=====================================
MeshResource::~MeshResource()
{
	SAFE_RELEASE(mesh);

	for (auto&& texture : textures)
	{
		SAFE_RELEASE(texture);
	}

	//�N���[������MeshContainer������ɉ������Ă��邩�m�F
	assert(cntRef == 0);
}

//=====================================
// �N���[��
//=====================================
void MeshResource::Clone(MeshContainer * container)
{
	if (container == NULL)
		return;

	if (mesh == NULL)
		return;

	//�������ς݂ł���΃����[�X����
	if (container->initialized)
	{
		container->ReleaseResource();
	}

	//���b�V���̎Q�Ƃ�ێ�
	container->mesh = mesh;
	mesh->AddRef();

	//�}�e���A�����R�s�[
	container->materials = materials;

	//�e�N�X�`���ւ̎Q�Ƃ�ݒ�
	container->textures = textures;
	for (auto&& texture : textures)
	{
		if (texture == NULL)
			continue;

		texture->AddRef();
	}

	//�}�e���A������ۑ�
	container->materialNum = materialNum;

	//���g�����\�[�X�Ƃ��ēo�^
	container->resource = this;

	container->initialized = true;

	cntRef++;
}

//=====================================
// �����[�X���ɊJ�����̃`�F�b�N
//=====================================
void MeshResource::OnRelease()
{
	cntRef--;
}