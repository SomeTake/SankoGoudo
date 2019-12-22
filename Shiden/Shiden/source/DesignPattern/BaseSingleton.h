//=============================================================================
//
// �V���O���g�� [BaseSingleton.h]
// Author:GP12B332 19 ���J���u
//
//=============================================================================
#ifndef _BASESINGLETON_H_
#define _BASESINGLETON_H_

//****************************************************
// �e���v���[�g�N���X��`
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