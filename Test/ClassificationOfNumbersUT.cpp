#include "pch.h"
#include "CppUnitTest.h"

#include "ClassificationOfNumbers.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

using EvanAssignments::Lib::ClassificationOfNumbers::Compare;
using EvanAssignments::Lib::ClassificationOfNumbers::Relationship;

// Specialization of ToString for Relationship enum
namespace Microsoft {
	namespace VisualStudio {
		namespace CppUnitTestFramework {

			template<>
			std::wstring ToString<EvanAssignments::Lib::ClassificationOfNumbers::Relationship>(
				const EvanAssignments::Lib::ClassificationOfNumbers::Relationship& rel)
			{
				switch (rel) {
				case Relationship::LessThan:
					return L"LessThan";
				case Relationship::GreaterThan:
					return L"GreaterThan";
				case Relationship::EqualTo:
					return L"EqualTo";
				default:
					return L"Invalid Relationship";
				}
			}

		} // namespace CppUnitTestFramework
	} // namespace VisualStudio
} // namespace Microsoft

namespace Test::ClassificationOfNumbers
{
	
	TEST_CLASS(CompareTestClass)
	{
	public:

		TEST_METHOD(CompareTest)
		{
			Assert::AreEqual(Relationship::GreaterThan, Compare(-2, -9));
			Assert::AreEqual(Relationship::GreaterThan, Compare(3, -4));
			Assert::AreEqual(Relationship::GreaterThan, Compare(2, -3));
			Assert::AreEqual(Relationship::GreaterThan, Compare(0, -4));
			Assert::AreEqual(Relationship::EqualTo, Compare(abs(-9), 9));
			Assert::AreEqual(Relationship::EqualTo, Compare(0.5, 1./2.));
			Assert::AreEqual(Relationship::LessThan, Compare(0.08, 0.2));
			Assert::AreEqual(Relationship::GreaterThan, Compare(5./8., 5./9.));
			Assert::AreEqual(Relationship::LessThan, Compare(1. / 6., 0.17));
			Assert::AreEqual(Relationship::GreaterThan, Compare(-2, -6));
			Assert::AreEqual(Relationship::LessThan, Compare(-5, 0));
			Assert::AreEqual(Relationship::LessThan, Compare(-10, -3));
			Assert::AreEqual(Relationship::GreaterThan, Compare(0.3, 0.25));
			Assert::AreEqual(Relationship::EqualTo, Compare(abs(-6), 6));
			Assert::AreEqual(Relationship::GreaterThan, Compare(3./5., 0.55));
		}
	};

}
