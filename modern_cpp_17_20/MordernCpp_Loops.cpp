//3 main versions of for loop in modern Cpp

#include<vector>
#include <algorithm>
#include <execution>
#include <ranges>


class Player
{
public:
    float hp;
    //other attributes
};

std::vector<Player> players;



int main()
{
    std::vector<Player> players1;
    std::vector<Player> players2;
    std::vector<Player> players3;
    //1. range-based for loop, introduced in C++11
    for(auto&player : players1)
    {
        if(player.hp ==0.f) player.hp = 100.f;
    };


    //for_each for parralle tasks starting from Cpp17
    std::for_each(std::execution::par_unseq, players2.begin(), players2.end(),
    lambda);



    // cpp20, ranges pipline
    auto dead_players3 = players3 | std::views::filter(lambda);
    std::ranges::for_each(dead_players3, [](auto&p){p.hp = 100.f});

    return 0;
}

