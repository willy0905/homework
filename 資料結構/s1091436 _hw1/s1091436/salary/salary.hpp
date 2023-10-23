#include <string>
#include <vector>

class Employee
{
public:
    std::string name;
    int age;
    int salary;
    std::string department;
};

std::vector<std::pair<std::string, int>>
calculate_average(const std::vector<Employee>& emp) {
    std::vector<std::pair<std::string, int>> ans;
    std::vector<std::string>str;
    std::vector<int>salary(0);
    std::vector<int>time(0);
    for (int i = 0; i < emp.size(); i++) {
        bool check = true;
        for (int j = 0; j < str.size(); j++) {
            if (emp[i].department == str[j]) {
                check = false;
                time[j]++;
                salary[j] += emp[i].salary;
                break;
            }
        }
        if (check) {
            str.push_back(emp[i].department);
            salary.push_back(emp[i].salary);
            time.push_back(1);
        }
    }
    for (int i = 0; i < str.size(); i++) {
        std::pair<std::string, int> x;
        x.first = str[i];
        x.second = salary[i]/time[i];
        ans.push_back(x);
    }
    return ans;
};
