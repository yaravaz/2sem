#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Student {
    string surname;
    string name;
    string patronymic;
    int birth_year;
    int course;
    string group_number;
    int grades[5];
    Student* prev;
    Student* next;
};

void add_student(Student*& head, Student*& tail, string surname, string name, string patronymic,
    int birth_year, int course, string group_number, int grades[]) {
    Student* new_student = new Student;
    new_student->surname = surname;
    new_student->name = name;
    new_student->patronymic = patronymic;
    new_student->birth_year = birth_year;
    new_student->course = course;
    new_student->group_number = group_number;
    for (int i = 0; i < 5; i++) {
        new_student->grades[i] = grades[i];
    }
    new_student->prev = tail;
    new_student->next = nullptr;
    if (tail == nullptr) {
        head = new_student;
    }
    else {
        tail->next = new_student;
    }
    tail = new_student;
}

void print_students(Student* head) {
    while (head != nullptr) {
        cout << head->surname << " " << head->name << " " << head->patronymic << ", "
            << head->birth_year << ", " << head->course << ", " << head->group_number << ", "
            << head->grades[0] << " " << head->grades[1] << " " << head->grades[2] << " "
            << head->grades[3] << " " << head->grades[4] << endl;
        head = head->next;
    }
}

void sort_students(Student*& head, Student*& tail) {
    vector<Student*> students;
    while (head != nullptr) {
        students.push_back(head);
        head = head->next;
    }
    sort(students.begin(), students.end(), [](const Student* a, const Student* b) {
        if (a->course == b->course) {
            return a->surname < b->surname;
        }
        else {
            return a->course < b->course;
        }
        });
    head = students[0];
    head->prev = nullptr;
    for (int i = 1; i < students.size(); i++) {
        students[i]->prev = students[i - 1];
        students[i - 1]->next = students[i];
    }
    tail = students.back();
    tail->next = nullptr;
}

void print_group_averages(Student* head) {
    while (head != nullptr) {
        int total_grades[5] = { 0, 0, 0, 0, 0 };
        int count = 0;
        while (head != nullptr && head->group_number == head->prev->group_number) {
            for (int i = 0; i < 5; i++) {
                total_grades[i] += head->grades[i];
            }
            count++;
            head = head->next;
        }
        cout << "Group " << head->prev->group_number << " averages: ";
        for (int i = 0; i < 5; i++) {
            cout << static_cast<double>(total_grades[i]) / count << " ";
        }
        cout << endl;
    }
}

void find_oldest_youngest(Student* head, Student*& oldest, Student*& youngest) {
    oldest = head;
    youngest = head;
    while (head != nullptr) {
        if (head->birth_year < oldest->birth_year) {
            oldest = head;
        }
        if (head->birth_year > youngest->birth_year) {
            youngest = head;
        }
        head = head->next;
    }
}

void print_best_students(Student* head) {
    while (head != nullptr) {
        string current_group = head->group_number;
        Student* best_student = head;
        double best_average = static_cast<double>(
            head->grades[0] + head->grades[1] + head->grades[2] + head->grades[3] + head->grades[4]
            ) / 5;
        while (head != nullptr && head->group_number == current_group) {
            double current_average = static_cast<double>(
                head->grades[0] + head->grades[1] + head->grades[2] + head->grades[3] + head->grades[4]
                ) / 5;
            if (current_average > best_average) {
                best_student = head;
                best_average = current_average;
            }
            head = head->next;
        }
        cout << "Best student in group " << current_group << ": " << best_student->surname
            << " " << best_student->name << " " << best_student->patronymic << ", average: "
            << best_average << endl;
    }
}

int main() {
    Student* head = nullptr;
    Student* tail = nullptr;
    int grades1[5] = { 5, 4, 5, 4, 5 };
    add_student(head, tail, "Ivanov", "Ivan", "Ivanovich", 2000, 1, "101", grades1);
    int grades2[5] = { 4, 5, 4, 5, 4 };
    add_student(head, tail, "Petrov", "Petr", "Petrovich", 2000, 1, "101", grades2);
    int grades3[5] = { 3, 3, 3, 4, 4 };
    add_student(head, tail, "Sidorov", "Sidor", "Sidorovich", 1999, 2, "201", grades3);
    int grades4[5] = { 5, 5, 5, 4, 5 };
    add_student(head, tail, "Smirnov", "Sergey", "Sergeevich", 1999, 2, "201", grades4);

    // Sort the students by course and surname
    sort_students(head, tail);

    // Print the list of students
    print_students(head);

    // Print the group averages for each subject
    print_group_averages(head);

    // Find the oldest and youngest students
    Student* oldest;
    Student* youngest;
    find_oldest_youngest(head, oldest, youngest);
    cout << "Oldest student: " << oldest->surname << " " << oldest->name << " " << oldest->patronymic
        << ", birth year: " << oldest->birth_year << endl;
    cout << "Youngest student: " << youngest->surname << " " << youngest->name << " " << youngest->patronymic
        << ", birth year: " << youngest->birth_year << endl;

    // Print the best student in each group
    print_best_students(head);

    return 0;
}