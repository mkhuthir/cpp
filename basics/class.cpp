#include <iostream>
using namespace std;

class Robot
{ 
  public:
    int Speed()
    {
    return 10;        
    }
    
    char* Name()
    {
    return (char*)"TurtleBot3";
    }
};

int main() 
{

  Robot robot1;
  cout << "Speed= " << robot1.Speed() << endl << "Name: " << robot1.Name() << endl;  

  return 0;
}
