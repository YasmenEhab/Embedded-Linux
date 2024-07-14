#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

class Vertex {
private:
    int x;
    int y;

public:
    
    Vertex() {
        setRandomValues();
    }

    
    void setRandomValues() {
        x = std::rand() % 201 - 100; // Random number between -100 and 100
        y = std::rand() % 201 - 100; // Random number between -100 and 100
    }

    
    int getX() const {
        return x;
    }

    
    int getY() const {
        return y;
    }

    
    std::string toString() const {
        return "Vertex: (" + std::to_string(x) + ", " + std::to_string(y) + ")";
    }
};

int main() {
   
    std::srand(std::time(nullptr));

    
    Vertex vertices[5];

    
    std::cout << "Generated vertices:\n";
    for (int i = 0; i < 5; ++i) {
        std::cout << vertices[i].toString() << "\n";
    }

    return 0;
}

