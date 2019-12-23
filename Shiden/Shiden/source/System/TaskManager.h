//=============================================================================
//
// タスクマネージャ [TaskManager.h]
// 役割：タスク管理クラス
// Author:GP12B332 19 染谷武志
//
//=============================================================================
#ifndef _TASKMANAGER_H_
#define _TASKMANAGER_H_

#include <functional>
#include <list>
#include <memory>
#include "../DesignPattern/BaseSingleton.h"

class Task;
class DelayedTask;
class RegularTask;
class TaskHandle;
//****************************************************
// クラス定義
//****************************************************
class TaskManager :
	public BaseSingleton<TaskManager>
{
	friend class Game;
public:
	void AllDelete();

	// 遅延タスク作成
	TaskHandle CreateDelayedTask(int delay, const std::function<void(void)>& task);

	// 定期タスク作成
	TaskHandle CreateRegularTask(int interval, const std::function<void(void)>& task);

private:
	void Update();

	std::list<std::shared_ptr<Task>> taskList;	// タスクリスト
};

//****************************************************
// クラス定義
//****************************************************
class TaskHandle
{
public:
	TaskHandle();
	TaskHandle(std::shared_ptr<Task>);
	~TaskHandle();

	TaskHandle& operator =(const TaskHandle& scr);

	void Stop();
	void Resume();
	void Pause();

private:
	std::weak_ptr<Task> task;
};

#endif
