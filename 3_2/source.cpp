//#include <stack>
//#include <iostream>
//#include <algorithm>
//#include <string>
//#include <stdexcept>
//#include <iterator>
//using namespace std;
//int main()
//{
//	stack<char> words;
//	stack<char> words2;
//	bool flag{};
//	string exp;
//	try
//	{
//		while (true)
//		{
//			size_t index{};
//			getline(cin, exp, '\n');
//			if (exp.empty()) break;
//			while (index != exp.length())
//			{
//				words2.push(exp.at(index++));
//			}
//			exp.erase(remove(begin(exp), end(exp), ' '), end(exp));
//			exp.erase(remove(begin(exp), end(exp), '?'), end(exp));
//			exp.erase(remove(begin(exp), end(exp), ','), end(exp));
//			exp.erase(remove(begin(exp), end(exp), '.'), end(exp));
//			index = 0;
//			while (index != exp.length())
//			{
//				if (words.empty())
//					words.push(exp.at(index++));
//				if (words.top() != exp.at(index))
//					words.push(exp.at(index++));
//
//				while (!words.empty())
//				{
//					if (index != exp.length())
//					{
//						if (words.top() == exp.at(index++))
//							words.pop();
//						else
//							break;
//					}
//					else
//						break;
//				}
//			}
//			if (words.empty()) flag = 1;
//			while (!words2.empty())
//			{
//				cout << words2.top();
//				words2.pop();
//			}
//			if (1 == flag)
//			{
//				cout << "  OK" << endl;
//
//			}
//			else
//			{
//				cout << "  NO" << endl;
//			}
//		}
//	}
//	catch (const exception& e)
//	{
//		cerr << e.what() << endl;
//	}
//	system("pause");
//}