//=============================================================================
//
// �^�X�N [Task.h]
// �����F�^�X�N�̊��N���X
// Author:GP12B332 19 ���J���u
//
//=============================================================================
#ifndef _TASK_H_
#define _TASK_H_

#include <functional>

//****************************************************
// �N���X��`
//****************************************************
class Task
{
public:
	Task(const std::function<void(void)>& task);
	virtual ~Task();
	virtual void Update() = 0;
	virtual void Stop();		// ��~
	virtual void Resume();		// �ĊJ
	virtual void Pause();		// �ꎞ��~
	virtual bool IsFinished();	// �I������

	// ��Ԓ�`
	enum State
	{
		Idle,		// ���s��
		Paused,		// �ꎞ��~��
		Finished	// �I���ς�
	};

protected:
	int cnt;	// �����܂ł̃J�E���^
	int time;	// ��������
	std::function<void(void)> func;	// �^�X�N
	State current;					// ���݂̏��
};

#endif
