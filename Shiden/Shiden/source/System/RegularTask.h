//=============================================================================
//
// ���M�����[�^�X�N [RegularTask.h]
// �����F����I�ɔ���������^�X�N
// Author:GP12B332 19 ���J���u
//
//=============================================================================
#ifndef _REGULARTASK_H_
#define _REGULARTASK_H_

#include "Task.h"

//****************************************************
// �N���X��`
//****************************************************
class RegularTask :
	public Task
{
public:
	RegularTask(int interval, const std::function<void(void)>& task);
	~RegularTask();

	void Update()override;
};

#endif
