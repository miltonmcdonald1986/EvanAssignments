#pragma once

namespace EvanAssignments::Lib::ClassificationOfNumbers
{

	enum class Relationship
	{
		LessThan,
		GreaterThan,
		EqualTo,
		Unknown
	};

	template<typename T>
	Relationship Compare(const T& t0, const T& t1)
	{
		return Relationship::Unknown;
	}

}
