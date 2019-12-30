//=============================================================================
//
// クォータニオン [Quaternion.cpp]
// 役割：クォータニオン計算用
// Author:GP12B332 19 染谷武志
//
//=============================================================================
#include "Quaternion.h"

//****************************************************
// スタティックメンバ初期化
//****************************************************
D3DXQUATERNION Quaternion::Identity = D3DXQUATERNION(0.0f, 0.0f, 0.0f, 1.0f);

//=============================================================================
// クォータニオンからオイラー角への変換
//=============================================================================
D3DXVECTOR3 Quaternion::ToEuler(const D3DXQUATERNION & q)
{
	float x = q.x;
	float y = q.y;
	float z = q.z;
	float w = q.w;

	float x2 = x * x;
	float y2 = y * y;
	float z2 = z * z;

	float xy = x * y;
	float xz = x * z;
	float yz = y * z;
	float wx = w * x;
	float wy = w * y;
	float wz = w * z;

	// 1 - 2y^2 - 2z^2
	float m00 = 1.0f - (2.0f * y2) - (2.0f * z2);

	// 2xy + 2wz
	float m01 = (2.0f * xy) + (2.0f * wz);

	// 2xy - 2wz
	float m10 = (2.0f * xy) - (2.0f * wz);

	// 1 - 2x^2 - 2z^2
	float m11 = 1.0f - (2.0f * x2) - (2.0f * z2);

	// 2xy + 2wy
	float m20 = (2.0f * xz) + (2.0f * wy);

	// 2yz + 2wx
	float m21 = (2.0f * yz) + (2.0f * wz);

	// 1 - 2x^2 - 2y^2
	float m22 = 1.0f - (2.0f * x2) - (2.0f * y2);

	float tx, ty, tz;

	if (Math::EqualAbout(m21, 1.0f))
	{
		tx = D3DX_PI / 2.0f;
		ty = 0.0f;
		tz = atan2f(m10, m00);
	}
	else if (Math::EqualAbout(m21, -1.0f))
	{
		tx = -D3DX_PI;
		ty = 0;
		tz = atan2f(m10, m00);
	}
	else
	{
		tx = asinf(-m21);
		ty = atan2f(m20, m22);
		tz = atan2f(m01, m11);
	}

	D3DXVECTOR3 out;
	out.x = Math::WrapAround(0.0f, 360.0f, D3DXToDegree(tx));
	out.y = Math::WrapAround(0.0f, 360.0f, D3DXToDegree(ty));
	out.z = Math::WrapAround(0.0f, 360.0f, D3DXToDegree(tz));

	return out;
}

//=============================================================================
// オイラー角からクォータニオンへの変換
//=============================================================================
D3DXQUATERNION Quaternion::FromEuler(const D3DXVECTOR3 & e)
{
	D3DXVECTOR3 v = D3DXVECTOR3(D3DXToRadian(e.x), D3DXToRadian(e.y), D3DXToRadian(e.z));
	D3DXQUATERNION out;
	D3DXQuaternionRotationYawPitchRoll(&out, v.y, v.x, v.z);
	return out;
}

//=============================================================================
// 変換行列からクォータニオンへの変換
//=============================================================================
D3DXQUATERNION Quaternion::GetRotation(const D3DXMATRIX & mtx)
{
	float elem[4];
	elem[0] = mtx._11 - mtx._22 - mtx._33 + 1.0f;
	elem[1] = -mtx._11 + mtx._22 - mtx._33 + 1.0f;
	elem[2] = -mtx._11 - mtx._22 + mtx._33 + 1.0f;
	elem[3] = mtx._11 + mtx._22 + mtx._33 + 1.0f;

	int biggestIndex = 0;
	for (int i = 0; i < 4; i++)
	{
		if (elem[i] > elem[biggestIndex])
		{
			biggestIndex = i;
		}
	}

	float q[4];
	float v = sqrtf(elem[biggestIndex] * 0.5f);
	q[biggestIndex] = v;
	float mult = 0.25f / v;

	switch (biggestIndex)
	{
	case 0:
		q[1] = (mtx._21 + mtx._12) * mult;
		q[2] = (mtx._13 + mtx._31) * mult;
		q[3] = (mtx._32 + mtx._23) * mult;
		break;
	case 1:
		q[0] = (mtx._21 + mtx._12) * mult;
		q[2] = (mtx._32 + mtx._23) * mult;
		q[3] = (mtx._13 + mtx._31) * mult;
		break;
	case 2:
		q[0] = (mtx._13 + mtx._31) * mult;
		q[1] = (mtx._32 + mtx._23) * mult;
		q[3] = (mtx._21 + mtx._12) * mult;
		break;
	case 3:
		q[0] = (mtx._32 + mtx._23) * mult;
		q[1] = (mtx._13 + mtx._31) * mult;
		q[2] = (mtx._21 + mtx._12) * mult;
		break;
	default:
		break;
	}

	return D3DXQUATERNION(q);
}

//=============================================================================
// 等価比較処理
//=============================================================================
bool Quaternion::Equal(const D3DXQUATERNION & q1, const D3DXQUATERNION & q2)
{
	if (!Math::EqualAbout(q1.x, q2.x))
		return false;
	if (!Math::EqualAbout(q1.y, q2.y))
		return false;
	if (!Math::EqualAbout(q1.z, q2.z))
		return false;
	if (!Math::EqualAbout(q1.w, q2.w))
		return false;

	return true;
}
