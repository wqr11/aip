#include <iostream>
#include <cstring>

using namespace std;

struct Student
{
    char surname[50];
    int year;
    char faculty[50];
};

struct Faculty
{
    char name[50];
    int count;
};

int find_faculty_idx(Faculty *faculties, int size, char *faculty_name)
{
    for (int i = 0; i < size; ++i)
    {
        if (strcmp(faculties[i].name, faculty_name) == 0)
        {
            return i;
        };
    }
    return -1;
}

int main()
{
    FILE *f = fopen("records.csv", "r");

    Student students[100];
    int students_count = 0;

    while (fscanf(f, "%49[^,],%d,%49s\n",
                  students[students_count].surname,
                  &students[students_count].year,
                  students[students_count].faculty) == 3)
    {
        students_count++;
    }
    fclose(f);

    Faculty faculties[50];
    int faculties_count = 0;

    for (int i = 0; i < students_count; ++i)
    {
        Student *s = &students[i];
        int fid = find_faculty_idx(faculties, faculties_count, s->faculty);
        if (fid < 0)
        {
            strcpy(faculties[faculties_count].name, s->faculty);
            ++faculties[faculties_count].count;
            ++faculties_count;
        }
        else
        {
            ++faculties[fid].count;
        }
    }

    cout << "Факультеты и количество студентов:\n";
    for (int i = 0; i < faculties_count; ++i)
    {
        cout << faculties[i].name << ": " << faculties[i].count << '\n';
    }

    return 0;
}