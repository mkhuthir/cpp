#include <iostream>
using namespace std;

int main () 
{
   int var = 10;
   int *ptr = &var;
   *ptr+=1;
   cout << "Variable=" << var <<endl;

   return 0;
}
