//=============================================================================
//
// シングルトン [BaseSingleton.h]
// Author:GP12B332 19 染谷武志
//
//=============================================================================
#ifndef _BASESINGLETON_H_
#define _BASESINGLETON_H_

//****************************************************
// テンプレートクラス定義
//****************************************************
template <class T>
class BaseSingleton
{
public:
	static T* Instance()
	{
		static T mInstance;
		return &mInstance;
	}

protected:
	BaseSingleton(){}
	virtual ~BaseSingleton() {}

	BaseSingleton(const BaseSingleton &) = delete;
	BaseSingleton(BaseSingleton &&) = delete;

	BaseSingleton& operator=(const BaseSingleton &) = delete;
	BaseSingleton& operator=(BaseSingleton &&) = delete;
};

#endif