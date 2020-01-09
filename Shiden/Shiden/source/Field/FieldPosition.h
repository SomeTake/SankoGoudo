#ifndef _FIELDPOSITION_H_
#define _FIELDPOSITION_H_

#include "../../Main.h"
#include <tuple>

struct FieldPosition
{
	int x, z;
	FieldPosition()
	{
		x = 0;
		z = 0;
	}
	FieldPosition(int x, int z)
	{
		this->x = x;
		this->z = z;
	}

	inline D3DXVECTOR3 ConvertToWorldPosition() const
	{
		return { x * 100.0f, 0.0f, z * -100.0f };
	}
	static FieldPosition ConvertToFieldPosition(const D3DXVECTOR3& pos)
	{
		return { (int)pos.x / 10, abs((int)pos.z / 10) };
	}
	bool operator <(const FieldPosition& rhs) const
	{
		return std::tie(x, z) < std::tie(rhs.x, rhs.z);
	}
	FieldPosition operator + (const FieldPosition& rhs) const
	{
		return FieldPosition(x + rhs.x, z + rhs.z);
	}

	bool operator ==(const FieldPosition& rhs) const
	{
		return x == rhs.x && z == rhs.z;
	}
};

#endif