#include <iostream>

class Musician 
{
public:
    virtual void play() = 0;
    
    virtual void listen(Musician& music) = 0; 
        
    virtual bool isPlaying() = 0;
        
    virtual ~Musician() = default;
};

class Saxophonist:public Musician 
{
public:
    void play() {
        std::cout << "Play saxophon" << std::endl;
    }
    void listen(Musician&) {
        std::cout << "Saxophon" << std::endl;
    }
    bool isPlyaing() {
        return false;
    }
};

class Pianist:public Musician 
{
public:
    void play() {
        std::cout << "Play Piano" << std::endl;
    }
    void listen(Musician&) {
        std::cout << "Listen Piano" << std::endl;
    }
    bool isPlaying() {
        return true;
    }
};

class Bassist:public Musician
{
public:
    void play() {
        std::cout << "Play bassist" << std::endl;
    }
    void listen(Musician&) {
        std::cout << "Listen bassist" << std::endl;
    }
    bool isPlaying() {
        return false;
    }
};

class Drummer:public Musician
{
public:
    void play() {
        std::cout << "Play Drummer" << std::endl;
    }    
    void listen(Musician&) {
        std::cout << "Listen drummer" << std::endl;
    }
    bool isPlaying() {
        return false;
    }
};

int main() {
    
    return 0;
}
