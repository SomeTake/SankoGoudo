//=============================================================================
//
// タスクマネージャ [TaskManager.cpp]
// 役割：タスク管理クラス
// Author:GP12B332 19 染谷武志
//
//=============================================================================
#include "TaskManager.h"
#include "../../Main.h"
#include "Task.h"
#include "DelayedTask.h"
#include "RegularTask.h"

//==========================================
// 更新
//==========================================
void TaskManager::Update()
{
	// 終了したタスクを削除
	taskList.remove_if([](std::shared_ptr<Task> task) 
	{
		return task->IsFinished();
	});

	// タスク実行
	for (auto && task : taskList)
	{
		task->Update();
	}
}

//==========================================
// 全削除
//==========================================
void TaskManager::AllDelete()
{
	taskList.clear();
}

//==========================================
// 遅延タスク作成
//==========================================
TaskHandle TaskManager::CreateDelayedTask(int delay, const std::function<void(void)>& task)
{
	std::shared_ptr<DelayedTask> ptr = std::make_shared<DelayedTask>(delay, task);
	taskList.push_back(ptr);
	return TaskHandle(ptr);
}

//==========================================
// 定期タスク作成
//==========================================
TaskHandle TaskManager::CreateRegularTask(int interval, const std::function<void(void)>& task)
{
	std::shared_ptr<RegularTask> ptr = std::make_shared<RegularTask>(interval, task);
	taskList.push_back(ptr);
	return TaskHandle(ptr);
}

//==========================================
// コンストラクタ
//==========================================
TaskHandle::TaskHandle()
{
}

//==========================================
// コンストラクタ
//==========================================
TaskHandle::TaskHandle(std::shared_ptr<Task> task) :
	task(task)
{
}

//==========================================
// デストラクタ
//==========================================
TaskHandle::~TaskHandle()
{
}

//==========================================
// コピー代入演算子オーバーロード
//==========================================
TaskHandle & TaskHandle::operator=(const TaskHandle & src)
{
	task.reset();
	task = src.task;
	return *this;
}

//==========================================
// 停止
//==========================================
void TaskHandle::Stop()
{
	std::shared_ptr<Task> ptr = task.lock();
	if (ptr)
	{
		ptr->Stop();
	}
}

//==========================================
// 再開
//==========================================
void TaskHandle::Resume()
{
	std::shared_ptr<Task> ptr = task.lock();
	if (ptr)
	{
		ptr->Resume();
	}
}

//==========================================
// 一時停止
//==========================================
void TaskHandle::Pause()
{
	std::shared_ptr<Task> ptr = task.lock();
	if (ptr)
	{
		ptr->Pause();
	}
}
