// Online C++ compiler to run C++ program online
#include <iostream>
typedef struct {
    char firstName[50];
    char middleName[50];
    char lastName[50];
} EmployeeName;

typedef struct {
    int day;
    int month;
    int year;
} DateOfBirth;

typedef struct {
    char street[100];
    char city[50];
    char country[50];
} EmployeeAddress;

typedef struct {
    char telephoneNumber[20];
    char mobileNumber[20];
    char emailAddress[100];
} EmployeeContacts;

typedef struct {
    char job[100];
} EmployeeJob;

typedef struct {
    double basic;
    double additional;
    double reductions;
    double taxes;
} EmployeeSalary;

typedef struct {
    EmployeeName name;
    DateOfBirth dateOfBirth;
    EmployeeAddress address;
    EmployeeContacts contacts;
    EmployeeJob job;
    EmployeeSalary salary;
} Employee;
int main() {
    // Write C++ code here
    std::cout << "Try programiz.pro";

    return 0;
}