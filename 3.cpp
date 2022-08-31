#include <iostream>

class Something
{
public:
    Something() { topSecretValue = 42; }
    bool somePublicBool;
    int somePublicInt;
    std::string somePublicString;
private:
    int topSecretValue;
};

class something 
{
public:
    bool somePublicBool;
    int somePublicInt;
    std::string somePublicString;
    int topSecretValue;
    int cast(Something* ptrr) {
        something *ptr = reinterpret_cast<something*>(ptrr);
        return ptr->topSecretValue;
    }
private:
    something() { topSecretValue = 42; }
};
int main() {
    Something obj;
    something* ptr;
    std::cout << ptr->cast(&obj);

    return 0;
}