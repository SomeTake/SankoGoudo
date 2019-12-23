//=============================================================================
//
// �^�X�N�}�l�[�W�� [TaskManager.h]
// �����F�^�X�N�Ǘ��N���X
// Author:GP12B332 19 ���J���u
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
// �N���X��`
//****************************************************
class TaskManager :
	public BaseSingleton<TaskManager>
{
	friend class Game;
public:
	void AllDelete();

	// �x���^�X�N�쐬
	TaskHandle CreateDelayedTask(int delay, const std::function<void(void)>& task);

	// ����^�X�N�쐬
	TaskHandle CreateRegularTask(int interval, const std::function<void(void)>& task);

private:
	void Update();

	std::list<std::shared_ptr<Task>> taskList;	// �^�X�N���X�g
};

//****************************************************
// �N���X��`
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
