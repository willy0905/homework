#include <string>
#include <vector>
class Team
{
public:
    std::string name;
    // Time to solve each problem, -1 means not solved
    std::vector<int> problems;
};

void rank_teams(std::vector<Team>&tem) {
    for (int i = 0; i < tem.size(); i++) {
        for (int j = i; j < tem.size(); j++) {
            int sp1 = 0, sp2 = 0, t1 = 0, t2 = 0;
            for (int k = 0; k < tem[i].problems.size(); k++) {
                if (tem[i].problems[k] != -1) {
                    sp1++;
                    t1 += tem[i].problems[k];
                }
            }
            for (int k = 0; k < tem[j].problems.size(); k++) {
                if (tem[j].problems[k] != -1) {
                    sp2++;
                    t2 += tem[j].problems[k];
                }
            }
            if (sp2 > sp1 || (sp1 == sp2 && t2 <= t1)) {
                std::swap(tem[i], tem[j]);
            }
        }
    }
};