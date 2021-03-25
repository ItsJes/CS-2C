#include <iostream>
#include <string>

using namespace std;

int recursive(int n)
{
   if (n == 0)
      return 0;

   if (n % 2 == 1)
     return recursive(n / 2) + 1;
   else
     return recursive(n / 2);

}

void test_case(int n, int testCaseResult)
{ 
   int rec = recursive(n);

   if (testCaseResult == rec)
   {
      cout << "Passed!" << endl;

   }
   else
      cout << "Failed!" << endl;

   cout << "Number: " << n << endl
      << "Test Case results for number of 1's: " << testCaseResult << endl
      << "Actual Results: " << rec << endl << endl;
}

int main()
{
   test_case(12, 2);
   test_case(12, 3);
   test_case(45, 4);
   test_case(45, 6);
   test_case(1, 1);
}

/*----------------------------- Posted Run --------------------------------------
Passed!
Number: 12
Test Case results for number of 1's: 2
Actual Results: 2

Failed!
Number: 12
Test Case results for number of 1's: 3
Actual Results: 2

Passed!
Number: 45
Test Case results for number of 1's: 4
Actual Results: 4

Failed!
Number: 45
Test Case results for number of 1's: 6
Actual Results: 4

Passed!
Number: 1
Test Case results for number of 1's: 1
Actual Results: 1

Press any key to continue . . .
---------------------------------------------------------------------------------*/