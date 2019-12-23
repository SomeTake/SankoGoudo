//=============================================================================
//
// ディレイドタスク [DelayedTask.h]
// 役割：遅延して発生させるタスク
// Author:GP12B332 19 染谷武志
//
//=============================================================================
#ifndef _DELAYEDTASK_H_
#define _DELAYEDTASK_H_

#include "Task.h"

//****************************************************
// クラス定義
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
