//=============================================================================
//
// タスク [Task.h]
// 役割：タスクの基底クラス
// Author:GP12B332 19 染谷武志
//
//=============================================================================
#ifndef _TASK_H_
#define _TASK_H_

#include <functional>

//****************************************************
// クラス定義
//****************************************************
class Task
{
public:
	Task(const std::function<void(void)>& task);
	virtual ~Task();
	virtual void Update() = 0;
	virtual void Stop();		// 停止
	virtual void Resume();		// 再開
	virtual void Pause();		// 一時停止
	virtual bool IsFinished();	// 終了判定

	// 状態定義
	enum State
	{
		Idle,		// 実行中
		Paused,		// 一時停止中
		Finished	// 終了済み
	};

protected:
	int cnt;	// 発生までのカウンタ
	int time;	// 発生時間
	std::function<void(void)> func;	// タスク
	State current;					// 現在の状態
};

#endif
