#include <iostream>

using namespace std;

bool operator <(const string &str1, const string &str2)
{
   return (str1.compare(str2) < 0);
}

bool operator >(const string &str1, const string &str2)
{
   return (str1.compare(str2) > 0);
}

template<typename T>
T Min(T first, T second)
{
   if (first < second)
      return first;
   else
      return second;

}

template<typename T>
T Max(T first, T second)
{
   if (first > second)
      return first;
   else
      return second;
}

template<typename T>
void Test_Case_Min(T first, T second, T testCaseResult)
{
   T min = Min(first, second);
   if (testCaseResult == min)
   {
      cout << "Passed!" << endl;

   }
   else
      cout << "Failed!" << endl;

   cout << "First is " << first << endl
     << "Second is " << second << endl
      << "Actual: " << min << endl
      << "Test Case Results: " << testCaseResult << endl << endl;
}

template<typename T>
void Test_Case_Max(T first, T second, T testCaseResult)
{
   T max = Max(first, second);
   if (testCaseResult == max)
   {
      cout << "Passed!" << endl;

   }
   else
      cout << "Failed!" << endl;

   cout << "First is " << first << endl
      << "Second is " << second << endl
      << "Actual: " << max << endl
      << "Test Case Results: " << testCaseResult << endl << endl;
}

int main()
{

   // test min value
   cout << "Test for Min Value:" << endl;
   Test_Case_Min(5, 6, 4);
   Test_Case_Min(6, 20, 6);
   Test_Case_Min(6.7, 9.8, 6.7);
   Test_Case_Min(55.5, 7.5, 5.5);

   // test max value
   cout << "Test for Max Value:" << endl;
   Test_Case_Max(56, 6, 56);
   Test_Case_Max(6, 56, 6);
   Test_Case_Max(67.6, 5.0, 67.6);
   Test_Case_Max(10.5, 45.4, 33.6);

   // test min with string
   cout << "Test Min Value with String:" << endl;
   Test_Case_Min("name", "teaspoon", "name");
   Test_Case_Min("name", "teaspoon", "teaspoon");

   // test max with string
   cout << "Test Max Value with String:" << endl;
   Test_Case_Max("iphone", "tea", "tea");
   Test_Case_Max("iphone", "tea", "iphone");
}

/*----------------------------- Posted Run --------------------------------------
Test for Min Value:
Failed!
First is 5
Second is 6
Actual: 5
Test Case Results: 4

Passed!
First is 6
Second is 20
Actual: 6
Test Case Results: 6

Passed!
First is 6.7
Second is 9.8
Actual: 6.7
Test Case Results: 6.7

Failed!
First is 55.5
Second is 7.5
Actual: 7.5
Test Case Results: 5.5

Test for Max Value:
Passed!
First is 56
Second is 6
Actual: 56
Test Case Results: 56

Failed!
First is 6
Second is 56
Actual: 56
Test Case Results: 6

Passed!
First is 67.6
Second is 5
Actual: 67.6
Test Case Results: 67.6

Failed!
First is 10.5
Second is 45.4
Actual: 45.4
Test Case Results: 33.6

Test Min Value with String:
Passed!
First is name
Second is teaspoon
Actual: name
Test Case Results: name

Failed!
First is name
Second is teaspoon
Actual: name
Test Case Results: teaspoon

Test Max Value with String:
Failed!
First is iphone
Second is tea
Actual: iphone
Test Case Results: tea

Passed!
First is iphone
Second is tea
Actual: iphone
Test Case Results: iphone

Press any key to continue . . .
---------------------------------------------------------------------------------*/