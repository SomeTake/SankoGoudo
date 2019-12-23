//=============================================================================
//
// レギュラータスク [RegularTask.h]
// 役割：定期的に発生させるタスク
// Author:GP12B332 19 染谷武志
//
//=============================================================================
#ifndef _REGULARTASK_H_
#define _REGULARTASK_H_

#include "Task.h"

//****************************************************
// クラス定義
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
