#include <iostream>

class base
{
protected:
    int basedata;
};

class derived1 : public base
{

};

class derived2 : public base
{

};

class derived3 : public derived1, public derived2
{
public:
    int getData()
    {
        return derived2::basedata;
    }
};


int main() 
{
    derived3 obj;
    std::cout << obj.getData();
}