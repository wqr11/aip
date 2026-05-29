#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unordered_map>

using std::cin;
using std::cout;

constexpr int GROUPS = 5;
constexpr int STUDENTS_IN_GROUP = 20;
constexpr int QUESTIONS = 20;

int main()
{
    srand(time(nullptr));

    std::unordered_map<int, int> group_scores;
    std::unordered_map<int, int> question_scores;

    for (int g = 0; g < GROUPS; ++g)
    {
        int group_score = 0;

        for (int s = 0; s < STUDENTS_IN_GROUP; ++s)
        {
            for (int q = 0; q < QUESTIONS; ++q)
            {

                int val = rand() & 1;

                if (val)
                {
                    ++question_scores[q];
                    ++group_score;
                }
                else
                {
                    --question_scores[q];
                    --group_score;
                }
            }
        }

        group_scores[g] = group_score;
    }

    cout << "Группа Итого" << '\n';

    int wgroup = -1;
    int wgroup_score = 999;
    for (int g = 0; g < GROUPS; ++g)
    {
        if (group_scores[g] < wgroup_score)
        {
            wgroup = g;
            wgroup_score = group_scores[g];
        }
        cout << g << " " << group_scores[g] << '\n';
    }

    int wquestion = -1;
    int wquestion_score = 999;
    for (int q = 0; q < QUESTIONS; ++q)
    {
        if (question_scores[q] < wquestion_score)
        {
            wquestion = q;
            wquestion_score = question_scores[q];
        }
    }

    cout << "Самая неблагополучная группа - " << wgroup << " со счётом в " << wgroup_score << '\n';
    cout << "Самый трудный вопрос - " << wquestion << " со счётом в " << wquestion_score << '\n';
}