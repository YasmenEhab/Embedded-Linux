#include <iostream>

class Time {
private:
    int hours;
    int minutes;
    int seconds;

public:
    
    Time() : hours(0), minutes(0), seconds(0) {}

    
    Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {}

   
    void Display_12() const {
        std::cout << hours << ":" << minutes << ":" << seconds << std::endl;
    }

    
    friend Time operator+(const Time& obj1, const Time& obj2);
};

Time operator+(const Time& obj1, const Time& obj2) {
    Time res;
    res.hours = obj1.hours + obj2.hours;
    res.minutes = obj1.minutes + obj2.minutes;
    res.seconds = obj1.seconds + obj2.seconds;


    if (res.seconds >= 60) {
        res.seconds -= 60;
        res.minutes += 1;
    }

    if (res.minutes >= 60) {
        res.minutes -= 60;
        res.hours += 1;
    }

    return res;
}

int main() {
    Time o1(1, 45, 30);
    Time o2(2, 10, 20);
    Time o3 = o1 + o2;

    o3.Display_12();

    return 0;
}
