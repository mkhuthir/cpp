#include <iostream>
using namespace std;

class Robot
{ 
  public:
    int Speed()
    {
     return 10;        
    }
};

class Wheel: public Robot
{};

int main() 
{
    Wheel wheel1;
    Wheel *wheel1_pt = &wheel1;

    cout << "Wheel Speed Accesed by the Object= " << wheel1.Speed() <<endl;
    cout << "Wheel Speed Accesed by the Pointer= " << wheel1_pt->Speed() <<endl;
    cout << "Address of wheel 1 object= " << wheel1_pt << endl;

    return 0;
}

