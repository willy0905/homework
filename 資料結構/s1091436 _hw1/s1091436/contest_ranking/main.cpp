#include <iostream>
#include <vector>
#include "contest_ranking.hpp"

int main()
{
    int n, p;
    std::cin >> n >> p;

    std::vector<Team> teams(n);
    for (auto &team : teams)
    {
        std::cin >> team.name;
        team.problems.resize(p);
        for (std::size_t i = 0; i < p; i++)
            std::cin >> team.problems[i];
    }

    rank_teams(teams);

    for (const auto &team : teams)
        std::cout << team.name << '\n';

    return 0;
}
