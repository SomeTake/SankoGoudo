//=============================================================================
//
// �^�X�N�}�l�[�W�� [TaskManager.cpp]
// �����F�^�X�N�Ǘ��N���X
// Author:GP12B332 19 ���J���u
//
//=============================================================================
#include "TaskManager.h"
#include "../../Main.h"
#include "Task.h"
#include "DelayedTask.h"
#include "RegularTask.h"

//==========================================
// �X�V
//==========================================
void TaskManager::Update()
{
	// �I�������^�X�N���폜
	taskList.remove_if([](std::shared_ptr<Task> task) 
	{
		return task->IsFinished();
	});

	// �^�X�N���s
	for (auto && task : taskList)
	{
		task->Update();
	}
}

//==========================================
// �S�폜
//==========================================
void TaskManager::AllDelete()
{
	taskList.clear();
}

//==========================================
// �x���^�X�N�쐬
//==========================================
TaskHandle TaskManager::CreateDelayedTask(int delay, const std::function<void(void)>& task)
{
	std::shared_ptr<DelayedTask> ptr = std::make_shared<DelayedTask>(delay, task);
	taskList.push_back(ptr);
	return TaskHandle(ptr);
}

//==========================================
// ����^�X�N�쐬
//==========================================
TaskHandle TaskManager::CreateRegularTask(int interval, const std::function<void(void)>& task)
{
	std::shared_ptr<RegularTask> ptr = std::make_shared<RegularTask>(interval, task);
	taskList.push_back(ptr);
	return TaskHandle(ptr);
}

//==========================================
// �R���X�g���N�^
//==========================================
TaskHandle::TaskHandle()
{
}

//==========================================
// �R���X�g���N�^
//==========================================
TaskHandle::TaskHandle(std::shared_ptr<Task> task) :
	task(task)
{
}

//==========================================
// �f�X�g���N�^
//==========================================
TaskHandle::~TaskHandle()
{
}

//==========================================
// �R�s�[������Z�q�I�[�o�[���[�h
//==========================================
TaskHandle & TaskHandle::operator=(const TaskHandle & src)
{
	task.reset();
	task = src.task;
	return *this;
}

//==========================================
// ��~
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
// �ĊJ
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
// �ꎞ��~
//==========================================
void TaskHandle::Pause()
{
	std::shared_ptr<Task> ptr = task.lock();
	if (ptr)
	{
		ptr->Pause();
	}
}
