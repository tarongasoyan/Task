#include <iostream>

class Singleton
{
public:
    static Singleton *getinstance() {
        if (!isntance) {
            isntance = new Singleton();
            return isntance;
        }
        return isntance;
    }
    ~Singleton() {isntance = nullptr;}
private:
    Singleton() = default;
    static Singleton *isntance;
};

Singleton *Singleton::isntance = nullptr;

int main() {
    Singleton *ptr = Singleton::getinstance();
    Singleton *ptr1 = Singleton::getinstance();
    Singleton *ptr2 = Singleton::getinstance();
    
    std::cout << ptr << std::endl;
    std::cout << ptr1 << std::endl;
    std::cout << ptr2 << std::endl;
    delete ptr;

    return 0;
}
