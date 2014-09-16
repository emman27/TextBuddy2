#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TextBuddy2Test
{		
	TEST_CLASS(TestEverything)
	{
	public:
		
		TEST_METHOD(ConstructorFileNameTest){
			Data data(TEST_FILE_NAME);
			Assert::AreEqual(data.getFileName(), TEST_FILE_NAME);
			// TODO: Your test code here
		}

		TEST_METHOD(FileSave){
			const std::string TEST_STRING = "Hello you";
			Data data(TEST_FILE_NAME);
			data.clear();
			data.add(TEST_STRING);
			data.saveFile();
			Data anotherdata(TEST_FILE_NAME);
			Assert::AreEqual(anotherdata.get(1), TEST_STRING);
			Assert::AreEqual(anotherdata.getSize(), 1);
		}

		TEST_METHOD(Sort){
			std::vector<std::string> expectedOutput;
			std::string first = "abc";
			std::string second = "def";
			std::string third = "ghi";
			expectedOutput.push_back(first);
			expectedOutput.push_back(second);
			expectedOutput.push_back(third);
			Data data(TEST_FILE_NAME);
			data.clear();
			data.add(second);
			data.add(third);
			data.add(first);
			data.sort();

			Assert::AreEqual(int(expectedOutput.size()), data.getSize());

			for(int i = 1; i < 4; i++){
				Assert::AreEqual(data.get(i), expectedOutput[i - 1]);
			}
		}

		TEST_METHOD(Search){
			std::string first = "abc";
			std::string second = "defhi";
			std::string third = "ghi";
			Data data(TEST_FILE_NAME);
			data.clear();
			data.add(first);
			data.add(second);
			data.add(third);

			SearchResult expected;
			expected.add("2. defhi");
			expected.add("3. ghi");

			SearchResult res = data.search("hi");
			
			for(int i = 0; i < 2; i++){
				Assert::AreEqual(expected.getAll()[i], res.getAll()[i]);
			}
		}
	};
}