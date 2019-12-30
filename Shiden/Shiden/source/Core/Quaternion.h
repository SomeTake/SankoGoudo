//=============================================================================
//
// クォータニオン [Quaternion.h]
// 役割：クォータニオン計算用
// Author:GP12B332 19 染谷武志
//
//=============================================================================
#ifndef _QUATERNION_H_
#define _QUATERNION_H_

#include "../../Main.h"

//****************************************************
// クラス定義
//****************************************************
class Quaternion
{
public:
	// クォータニオンからオイラー角への変換
	static D3DXVECTOR3 ToEuler(const D3DXQUATERNION& q);

	// オイラー角からクォータニオンへの変換
	static D3DXQUATERNION FromEuler(const D3DXVECTOR3& e);

	// 変換行列からクォータニオンへの変換
	static D3DXQUATERNION GetRotation(const D3DXMATRIX& mtx);

	// 等価比較処理
	static bool Equal(const D3DXQUATERNION& q1, const D3DXQUATERNION& q2);

	// 単位クォータニオン定数
	static D3DXQUATERNION Identity;

private:
	Quaternion();
};

#endif
