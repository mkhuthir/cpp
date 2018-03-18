#include <iostream>
using namespace std;

int my_array[11]={0,1,2,3,4,5,6,7,8,9,10};

void FindEven(int array[])
{
    for(int i=0; i<=10; i++)
    {
        if(array[i] % 2 == 0)
            cout << array[i]<<endl;
    }
}

int main() 
{
    FindEven(my_array);

    return 0;
}
