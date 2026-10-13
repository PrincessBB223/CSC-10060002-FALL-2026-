#include <iostream>

int main()
{
    double weight;
    int num =8;

    std::cout << "Enter the package weight: ";
    std::cin >> weight;

    if (weight <= 1)
    {
        std::cout << "Light Shipping";
    }
    else if (weight <= 5)
    {
        std::cout << "Standard Shipping";
    }
    else if (weight <= 10)
    {
        std::cout << "Medium Shipping";
    }
    else if (weight <= 20)
    {
        std::cout << "Heavy Shipping";
    }
    else
    {
        std::cout << "Oversized Shipping";
    }

    return 0;
}

    Q 10

#include <iostream>
using namespace std;

    int main()
    {
        double gpa;
        bool fullTime;

        cout << "Enter the student's GPA: ";
        cin >> gpa;

        cout << "Is the student enrolled full-time? (1 for yes, 0 for no): ";
        cin >> fullTime;

        if (gpa >= 3.5 && fullTime)
        {
            cout << "Student qualifies for the scholarship.";
        }
        else
        {
            cout << "Student does not qualify for the scholarship.";
        }

        return 0;
    }

q 13

#include <iostream>
using namespace std;

int main()
{
    int creditScore;
    double income;

    cout << "Enter your credit score: ";
    cin >> creditScore;

    cout << "Enter your annual income: ";
    cin >> income;

    if (creditScore >= 700)
    {
        if (income >= 50000)
        {
            cout << "Loan approved";

        else
        {
            cout << "Loan denied";
        }
    }
    else
    {
        cout << "Not eligible";
    }

    return 0;
}



note to self: be more careful with typos and std usage ... please pay attention to questions! great job today :))










