// https://aonecode.com/amazon-online-assessment-cutoff-ranks
/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <algorithm>

int solution(int cutOffRank, int num, int* scores)
{
    std::sort(scores, scores + num, std::greater<int>());
    int output = 0;
    int lastScore = 0;
    
    // if all the scores are zeros, no one can level up
    if (scores[0] == 0)
    {
        return 0;
    }
    
    int it = 0;
    int rank = 0;
    do
    {
        
        if (scores[it] != lastScore)
        {
            rank = it + 1;
        }
        // printf("score: %d it: %d rank: %d output: %d\n", scores[it], it, rank, output);
        if (rank <= cutOffRank && scores[it] != 0)
        {
            output++;
        }
        lastScore = scores[it];
        it++;
    } while (it < num);
    
    return output;
}

void test1()
{
    int cutOffRank = 3;
    int num = 4;
    int scores[num] = {100, 25, 50, 50};
    std::cout << "Expected: 3\n";
    std::cout << "Output: " << solution(cutOffRank, num, scores) << "\n\n";
}

void test2()
{
    int cutOffRank = 4;
    int num = 5;
    int scores[num] = {2, 2, 3, 4, 5};
    std::cout << "Expected: 5\n";
    std::cout << "Output: " << solution(cutOffRank, num, scores) << "\n\n";
}

void test3()
{
    int cutOffRank = 2;
    int num = 5;
    int scores[num] = {20, 20, 3, 20, 20};
    std::cout << "Expected: 4\n";
    std::cout << "Output: " << solution(cutOffRank, num, scores) << "\n\n";
}

void test4()
{
    int cutOffRank = 5;
    int num = 5;
    int scores[num] = {20, 0, 0, 5, 20};
    std::cout << "Expected: 3\n";
    std::cout << "Output: " << solution(cutOffRank, num, scores) << "\n\n";
}

int main()
{
    test1();
    test2();
    test3();
    test4();
    return 0;
}
