#include <iostream>
#include <vector>
#include <string>

class Battleship {
private:
    bool board[5][5]{};
    int guesses{};
    int maxGuessAllowed{};
    int locationX{}, locationY{};

public:
    Battleship(int maxGuessAllowed) : maxGuessAllowed{maxGuessAllowed} {}

    void setShip() {
        locationX = rand() % 5;
        locationY = rand() % 5;
        board[locationX][locationY] = true;
    }

    int getGuesses() const {
        return guesses;
    }

    bool gameOver() const {
        return guesses >= maxGuessAllowed;
    }

    void guess() {
        int x{}, y{};
        while (!gameOver()) {
            std::cout << "Enter the x and y coordinates: ";
            std::cin >> x >> y;
            if (x < 0 || x > 4 || y < 0 || y > 4) {
                std::cout << "Out of bounds" << std::endl;
            } else {
                guesses++;
                if (board[x][y]) {
                    std::cout << "You hit the ship!" << std::endl;
                    break;
                } else {
                    if (locationX - 1 == x || locationX + 1 == x) {
                        std::cout << "You are close to x" << std::endl;
                    }
                    if (locationY - 1 == y || locationY + 1 == y) {
                        std::cout << "You are close to y" << std::endl;
                    }
                    if (locationX == x && locationY != y) {
                        std::cout << "x is right" << std::endl;
                    }
                    if (locationY == y && locationX != x) {
                        std::cout << "y is right" << std::endl;
                    }
                    std::cout << "You missed" << std::endl;
                }
            }
        }
    }
};

int main() {
    Battleship b1(5);
    b1.setShip();
    b1.guess();
    return 0;
}
