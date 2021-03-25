#include <iostream>
#include <sstream>
#include "List.h"
using namespace std;

int main()
{
   List<int> lst = List<int>();
   const int lstLen = 10;
    List<int>::iterator it = lst.begin();
   for (int i = 0; i < lstLen; i++)
   {
      lst.insert(it, i);
      ++it;
   }

   lst.showList();
   
   return 0;
}

