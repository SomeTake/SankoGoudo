//=============================================================================
//
// �C�[�W���O [Easing.h]
// �����F�C�[�W���O�p
// Author:GP12B332 19 ���J���u
//
//=============================================================================
#ifndef _EASING_H_
#define _EASING_H_

#include "../../Main.h"
#include "MyMath.h"

enum EaseType
{
	Linear,
	InSine,
	OutSine,
	InOutSine,
	InQuad,
	OutQuad,
	InOutQuad,
	InCubic,
	OutCubic,
	InOutCubic,
	InQuart,
	OutQuart,
	InOutQuart,
	InQuint,
	OutQuint,
	InOutQuint,
	InExpo,
	OutExpo,
	InOutExpo,
	InCirc,
	OutCirc,
	InOutCirc,
	InBack,
	OutBack,
	InOutBack,
	EaseTypeMax
};

//*****************************************************************************
// �N���X�錾
//*****************************************************************************
class Easing
{
public:
	/***************************
	�C�[�W���O�v�Z����
	***************************/
	template <class T>
	static T EaseValue(float time, const T& start, const T& end, EaseType type)
	{
		if (time >= 1.0f)
			return end;

		if (time <= 0.0f)
			return start;

		T result;

		if (type == EaseType::Linear)
		{
			result = (end - start) * time + start;
		}
		else
		{
			float c[4];
			GetController(c, type);

			float x = CubicBezier(c[0], c[1], c[2], c[3], time);
			result = (end - start) * CubicBezier(c[0], c[1], c[2], c[3], x) + start;
		}

		return result;
	}

private:
	/***************************
	�C�[�W���O�p�x�W�F�v�Z����
	***************************/
	static float CubicBezier(float x1, float y1, float x2, float y2, float t)
	{
		return Math::CubibBezier(D3DXVECTOR2(0.0f, 0.0f), D3DXVECTOR2(1.0f, 1.0f), D3DXVECTOR2(x1, y1), D3DXVECTOR2(x2, y2), t).y;
	}

	/***************************
	����_�擾����
	***************************/
	static void GetController(float *out, EaseType type)
	{
		//Linear�ȊO�̐���_
		static float controller[EaseTypeMax][4] = {
			{ 0.47f, 0.0f, 0.745f, 0.715f },
			{ 0.39f, 0.575f, 0.565f, 1.0f },
			{ 0.445f, 0.05f, 0.55f, 0.95f },
			{ 0.55f, 0.085f, 0.68f, 0.53f },
			{ 0.25f, 0.46f, 0.45f, 0.94f },
			{ 0.455f, 0.03f, 0.515f, 0.955f },
			{ 0.55f, 0.055f, 0.675f, 0.19f },
			{ 0.215f, 0.61f, 0.355f, 1.0f },
			{ 0.645f, 0.045f, 0.355f, 1.0f },
			{ 0.895f, 0.03f, 0.685f, 0.22f },
			{ 0.165f, 0.84f, 0.44f, 1.0f },
			{ 0.77f, 0.0f, 0.175f, 1.0f },
			{ 0.755f, 0.05f, 0.855f, 0.06f },
			{ 0.23f, 1.0f, 0.32f, 1.0f },
			{ 0.86f, 0.0f, 0.07f, 1.0f },
			{ 0.95f, 0.05f, 0.795f, 0.035f },
			{ 0.19f, 1.0f, 0.22f, 1.0f },
			{ 1.0f, 0.0f, 0.0f, 1.0f },
			{ 0.6f, 0.04f, 0.98f, 0.335f },
			{ 0.075f, 0.82f, 0.165f, 1.0f },
			{ 0.785f, 0.135f, 0.15f, 0.86f },
			{ 0.6f, -0.28f, 0.735f, 0.045f },
			{ 0.175f, 0.885f, 0.32f, 1.275f },
			{ 0.68f, -0.55f, 0.265f, 1.55f },
		};

		for (int i = 0; i < 4; i++)
		{
			//Linear�͐���_�������Ă��Ȃ��̂�type - 1��������
			out[i] = controller[type - 1][i];
		}
	}

	Easing();
};

#endif
