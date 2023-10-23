#include <iostream>
#include <vector>
#include <algorithm>
#include "salary.hpp"

int main()
{
    int n;
    std::cin >> n;

    std::vector<Employee> employees(n);
    for (auto &e : employees)
    {
        std::cin >> e.name >> e.age >> e.salary >> e.department;
    }

    auto average = calculate_average(employees);
    std::sort(average.begin(), average.end());

    for (const auto &info : average)
    {
        std::cout << info.first << ' ' << info.second << '\n';
    }

    return 0;
}