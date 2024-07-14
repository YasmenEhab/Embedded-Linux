#include <iostream>
#include <cstdlib>
#include <ctime>


struct Vertex {
    int x;
    int y;
};

int main() {
    
    std::srand(std::time(nullptr));
    Vertex vertices[5];

    for (int i = 0; i < 5; ++i) {
        vertices[i].x = std::rand() % 201 - 100; 
        vertices[i].y = std::rand() % 201 - 100; 
    }
    
    std::cout << "Generated vertices:\n";
    for (int i = 0; i < 5; ++i) {
        std::cout << "Vertex " << i + 1 << ": (" << vertices[i].x << ", " << vertices[i].y << ")\n";
    }

    return 0;
}
