#include "pch.h"
#include "CppUnitTest.h"
#include "../lab09.1(A)/lab09.1(A).cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Student* students = new Student[2];

			students[1].surname = "����";
			students[1].course = 3;
			students[1].physicsGrade = 4;
			students[1].mathGrade = 3;
			students[1].ITGrade = 4;

			int GoodGradesCount;

			Assert::AreEqual((students, 2, "����", 3, GoodGradesCount), GoodGradesCount);


		}
	};
}
