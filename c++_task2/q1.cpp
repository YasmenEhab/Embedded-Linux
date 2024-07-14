#include <iostream>
#include <string>

class Car {
private:
    std::string company;
    int model;
    int year;

public:
    // Constructor
    Car(const std::string &comp,int mod, int yr) 
        : company(comp), model(mod), year(yr) {}

    // Getters
    std::string getCompany() const {
        return company;
    }

    int getModel() const {
        return model;
    }

    int getYear() const {
        return year;
    }

    // Setters
    void setCompany(const std::string &comp) {
        company = comp;
    }

    void setModel(int mod) {
        model = mod;
    }

    void setYear(int yr) {
        year = yr;
    }
};

int main() {
    // Create a Car object
    Car myCar("Toyota", 3421, 2020);

    // Print the initial values
    std::cout << "Initial values:\n";
    std::cout << "Company: " << myCar.getCompany() << "\n";
    std::cout << "Model: " << myCar.getModel() << "\n";
    std::cout << "Year: " << myCar.getYear() << "\n";

    // Modify the values
    myCar.setCompany("Honda");
    myCar.setModel(1234);
    myCar.setYear(2022);

    // Print the modified values
    std::cout << "\nModified values:\n";
    std::cout << "Company: " << myCar.getCompany() << "\n";
    std::cout << "Model: " << myCar.getModel() << "\n";
    std::cout << "Year: " << myCar.getYear() << "\n";

    return 0;
}
