#include <iostream>
using namespace std;

class Abs
{
private:
    int a, b;

public:

    void set(int x, int y)
    {
        a = x;
        b = y;
    }

    void display()
    {
        cout<<"a="<<a<< endl;
        cout<<"b="<<b<< endl;
    }

    void display(int z)
    {
        cout<<z+14<<endl;
    }
};

class Parent
{
public:
    void print()
    {
        cout << "Parent" << endl;
    }
};


class Child : public Parent
{
public:

    void print()
    {
        cout << "Child" << endl;
    }

};


int main()
{
    Abs obj;
    obj.set(10, 20);
    obj.display();
    obj.display(3);

    Parent obj1;
    Child obj2 = Child();
    obj1.print();
    obj2.print();

    return 0;
}



