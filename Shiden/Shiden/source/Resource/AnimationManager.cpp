//=====================================
//
// �A�j���[�V�����}�l�[�W��[AnimationManager.cpp]
// �����F�A�j���[�V�����Ǘ��N���X
// Author:GP12B332 19 ���J���u
//
//=====================================
#include "AnimationManager.h"
#include "AnimationContainer.h"
#include "ResourceManager.h"

#include <assert.h>

using namespace std;
//==========================================
// �R���X�g���N�^
//==========================================
AnimationManager::AnimationManager() :
	currentAnimID(0)
{
	container = new AnimationContainer();
}

//==========================================
// �f�X�g���N�^
//==========================================
AnimationManager::~AnimationManager()
{
	SAFE_DELETE(container);
}

//==========================================
// �X�V
//==========================================
void AnimationManager::Update()
{
	//�o�ߎ��Ԃ��X�V
	elapsedTime += deltaTimeList[currentAnimID] * playSpeedList[currentAnimID];

	//�J�ڔ���
	if (ShouldTransition())
	{
		ChangeAnim(transitionMap[currentAnimID], true);
	}
}

//==========================================
// �`��
//==========================================
void AnimationManager::Draw(LPD3DXMATRIX mtxWorld)
{
	//�A�j���[�V�����̍X�V
	container->Update(deltaTimeList[currentAnimID]);

	container->Draw(mtxWorld);
}

//==========================================
// X�t�@�C���ǂݍ���
//==========================================
HRESULT AnimationManager::LoadXFile(LPCSTR fileName, const char* errorSrc)
{
	bool res = S_OK;
	ResourceManager::Instance()->GetSkinMesh(fileName, container);

	if (res != S_OK)
		return res;

	playSpeedList.resize(container->GetNumAnimationSets());
	for (auto&& playSpeed : playSpeedList)
	{
		playSpeed = 1.5f;
	}

	deltaTimeList.resize(container->GetNumAnimationSets());
	for (auto&& deltaTime : deltaTimeList)
	{
		deltaTime = 1.0f / 30.0f;
	}

	return S_OK;
}

//==========================================
// �A�j���[�V�����Z�b�g�ǂݍ���
//==========================================
HRESULT AnimationManager::LoadAnimation(LPCSTR setName, int setNo, float shiftTime)
{
	HRESULT res = S_OK;

	container->SetupCallbackKeyFrames(setName);

	res = container->LoadAnimation(setName, setNo);

	if (res != S_OK)
		return res;

	container->SetShiftTime(setNo, shiftTime);

	return S_OK;
}

//==========================================
// �v���C�X�s�[�h�ݒ�
//==========================================
void AnimationManager::SetPlaySpeed(UINT animID, float speed)
{
	assert(animID >= 0);
	assert(animID < playSpeedList.size());

	playSpeedList[animID] = speed;
}

//==========================================
// �J�ڎ��Ԑݒ�
//==========================================
void AnimationManager::SetDeltaTime(UINT animID, float delta)
{
	assert(animID >= 0);
	assert(animID < deltaTimeList.size());

	deltaTimeList[animID] = delta;
}

//==========================================
// �A�j���[�V�����ύX����
//==========================================
void AnimationManager::ChangeAnim(UINT next, bool forceChange)
{
	container->ChangeAnim(next, playSpeedList[next], forceChange);

	currentAnimID = next;
	elapsedTime = 0.0f;
	animationPeriod = container->GetPeriodAnimation();
}

//==========================================
// �A�j���[�V�����J�ڐݒ�
//==========================================
/**************************************
�A�j���[�V�����J�ڐݒ菈��
***************************************/
void AnimationManager::SetFinishTransition(UINT srcID, UINT destID)
{
	transitionMap[srcID] = destID;
}

//==========================================
// �A�j���[�V�����J�ڔ���
//==========================================
bool AnimationManager::ShouldTransition()
{
	if (transitionMap.count(currentAnimID) == 0)
		return false;

	if (elapsedTime < animationPeriod)
		return false;

	return true;
}