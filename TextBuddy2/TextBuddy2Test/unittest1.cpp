#include "stdafx.h"
#include "CppUnitTest.h"
#include "Data.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TextBuddy2Test
{		
	TEST_CLASS(TestEverything)
	{
	public:
		
		TEST_METHOD(ConstructorFileNameTest)
		{
			const std::string TEST_FILE_NAME = "something.txt";
			Data data(TEST_FILE_NAME);
			Assert::AreEqual(data.getFileName(), TEST_FILE_NAME);
			// TODO: Your test code here
		}

	};
}