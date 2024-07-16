#include <iostream>
#include <fstream>
#include <array>
#include <algorithm>
#include <iomanip>

using namespace std;
int main()
{

    ifstream in{"input.txt"};
    
    if (!in)
    {
        cerr << "Error input opening the file\n";

        return 1;
    }

    ofstream out{ "output.txt" };

    if (!out)
    {
        cerr << "Error output opening the file\n";

        return 1;
    }

    

    int sum = 0;
    double avg = 0;
    int min = 0;
    int max = 0;
    int index = 0;

    vector<int> arr;
    int num;

    while (in >> num) {
        arr.push_back(num);
    }
    in.close();
    for (int &num : arr) {
        sum += num;
        if (num < min) min = num;
        if (num > max) max = num;
    }

    
    avg = static_cast<double>(sum) / arr.size();

    
    out << "-------------------------------------------------------------------------------------------------------------------\n";
    out << setw(10) << "Sum" << setw(10) << "Avg" << setw(10) << "Min" << setw(10) << "Max" << endl;
    out << "--------------------------------------------------------------------------------------------------------------------\n";
    out << setw(10) << sum << setw(10) << avg << setw(10) << min << setw(10) << max << endl;
    out << "--------------------------------------------------------------------------------------------------------------------\n";

    
    out.close();
}