// Online C++ compiler to run C++ program online
#include <iostream>

int main() {
    // Write C++ code here
    double initialPopulation = 162100; 
    double growthRate = 0.065; 
    double targetPopulation = 1000000; 
    double calc=initialPopulation;
    int count =0;
    while(calc<targetPopulation)
    {
        calc=calc + (initialPopulation*growthRate);
        count++;
        
    }
    std::cout << "Initial Population: " << initialPopulation << std::endl;
    std::cout << "Growth Rate: " << (growthRate * 100) << "% per year" << std::endl;
    std::cout << "Target Population: " << targetPopulation << std::endl;
    std::cout << "Number of years to surpass one million (approx.): " << count << std::endl;
    

    return 0;
}