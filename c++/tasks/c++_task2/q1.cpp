#include <iostream>
#include <string>

class Car {
private:
    std::string company;
    int model;
    int year;

public:

    Car(const std::string &comp,int mod, int yr) 
        : company(comp), model(mod), year(yr) {}

    std::string getCompany() const {
        return company;
    }

    int getModel() const {
        return model;
    }

    int getYear() const {
        return year;
    }


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
  
    Car myCar("Toyota", 3421, 2020);

  
    std::cout << "Initial values:\n";
    std::cout << "Company: " << myCar.getCompany() << "\n";
    std::cout << "Model: " << myCar.getModel() << "\n";
    std::cout << "Year: " << myCar.getYear() << "\n";

    myCar.setCompany("Honda");
    myCar.setModel(1234);
    myCar.setYear(2022);

    
    std::cout << "\nModified values:\n";
    std::cout << "Company: " << myCar.getCompany() << "\n";
    std::cout << "Model: " << myCar.getModel() << "\n";
    std::cout << "Year: " << myCar.getYear() << "\n";

    return 0;
}
