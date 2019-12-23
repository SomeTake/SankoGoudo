//=============================================================================
//
// �f�B���C�h�^�X�N [DelayedTask.h]
// �����F�x�����Ĕ���������^�X�N
// Author:GP12B332 19 ���J���u
//
//=============================================================================
#ifndef _DELAYEDTASK_H_
#define _DELAYEDTASK_H_

#include "Task.h"

//****************************************************
// �N���X��`
//****************************************************
class DelayedTask :
	public Task
{
public:
	DelayedTask(int delay, const std::function<void(void)>& task);
	~DelayedTask()override;

	void Update()override;
};

#endif
