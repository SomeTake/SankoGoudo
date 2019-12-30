//=============================================================================
//
// �}�C�}�X [MyMath.h]
// �����F�v�Z�p
// Author:GP12B332 19 ���J���u
//
//=============================================================================
#ifndef _MYMATH_H_
#define _MYMATH_H_

//****************************************************
// �N���X��`
//****************************************************
class Math {
public:
	// ���������_��r����
	template<typename T>
	static bool EqualAbout(const T& a, const T& b)
	{
		return fabs(a - b) <= DBL_EPSILON * fmax(1, fmax(fabs(a), fabs(b)));
	}

	// ���b�v����
	static int WrapAround(int min, int max, int value)
	{
		int mod = (value - min) % (max - min);
		return (mod >= 0) ? mod + min : mod + max;
	}
	static float WrapAround(float min, float max, float value)
	{
		float mod = fmod(value - min, max - min);
		return (mod >= 0) ? mod + min : mod + max;
	}

	// 2���x�W�F�Ȑ�
	template<typename T>
	static T QuadraticBezier(const T& start, const T& end, const T& c, float time)
	{
		return powf(1.0f - time, 2.0f) * start + 2 * time * (1.0f - time) * c + powf(time, 2.0f) * end;
	}

	//3���x�W�F�Ȑ�
	template<typename T>
	static T CubibBezier(const T& start, const T& end, const T& c1, const T& c2, float time)
	{ 
		return powf(1.0f - time, 3.0f) * start + 3.0f * powf(1.0f - time, 2.0f) * time * c1 + 3.0f * (1.0f - time) * powf(time, 2.0f) * c2 + powf(time, 3.0f) * end;
	}
private:
	Math(){}
};

#endif
