#include <iostream>
#include <fstream>
#include <string>
#include "stdafx.h"
using namespace std;
const unsigned int NAME_SIZE = 30;
const unsigned int CITY_SIZE = 20;

struct Address
{
    char name[NAME_SIZE];
    char city[CITY_SIZE];
    Address* next;
    Address* prev;
};

int counter = 0;

int menu(void)
{
    char s[80];  int c;
    cout << endl;
    cout << "1. Ввод имени" << endl;
    cout << "2. Удаление имени" << endl;
    cout << "3. Вывод на экран" << endl;
    cout << "4. Поиск" << endl;
    cout << "5. Запись в файл" << endl;
    cout << "6. Чтение из файла" << endl;
    cout << "7. Удаление K последних элементов" << endl;
    cout << "8. 1 доп" << endl;
    cout << "11. Выход" << endl;
    cout << endl;
    do
    {
        cout << "Ваш выбор: ";
        cin.sync();
        cin.ignore(cin.rdbuf()->in_avail());
        cin.clear();
        gets_s(s);
        cout << endl;
        c = atoi(s);
    } while (c < 0 || c > 11);
    return c;
}

void insert(Address* e, Address** phead, Address** plast) //Добавление в конец списка
{
    Address* p = *plast;
    if (*plast == NULL)
    {
        e->next = NULL;
        e->prev = NULL;
        *plast = e;
        *phead = e;
        counter++;
        return;
    }
    else
    {
        p->next = e;
        e->next = NULL;
        e->prev = p;
        *plast = e;
        counter++;
    }
   
}
//----------------------------------------------------------- 
Address* setElement()      // Создание элемента и ввод его значений с клавиатуры
{
    Address* temp = new  Address();
    if (!temp)
    {
        cerr << "Ошибка выделения памяти памяти";
        return NULL;
    }
    cout << "Введите имя: ";
    cin.getline(temp->name, NAME_SIZE - 1, '\n');
    cin.ignore(cin.rdbuf()->in_avail());
    cin.clear();
    cout << "Введите город: ";
    cin.getline(temp->city, CITY_SIZE - 1, '\n');
    cin.ignore(cin.rdbuf()->in_avail());
    cin.clear();
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}
//-----------------------------------------------------------
void outputList(Address** phead, Address** plast)      //Вывод списка на экран
{
    Address* t = *phead;
    while (t)
    {

        cout << t->name << ' ' << t->city << endl;
        t = t->next;
    }
    cout << "" << endl;
}
//-----------------------------------------------------------
void find(char name[NAME_SIZE], Address** phead)    // Поиск имени в списке
{
    Address* t = *phead;
    while (t)
    {
        if (!strcmp(name, t->name))
            break;
        t = t->next;
    }
    if (!t)
        cerr << "Имя не найдено" << endl;
    else
        cout << t->name << ' ' << t->city << endl;
}
//-----------------------------------------------------------
void delet(char name[NAME_SIZE], Address** phead, Address** plast)  // Удаление имени 
{
    struct Address* t = *phead;
    while (t)
    {
        if (!strcmp(name, t->name))
            break;
        t = t->next;
    }

    if (!t)
        cerr << "Имя не найдено" << endl;
    else
    {
        if (*phead == t)
        {
            *phead = t->next;
            if (*phead)
                (*phead)->prev = NULL;
            else
                *plast = NULL;
        }
        else
        {
            t->prev->next = t->next;
            if (t != *plast)
                t->next->prev = t->prev;
            else
                *plast = t->prev;
        }
        delete t;
        counter--;
        cout << "Элемент удален" << endl;
    }
}

void writeToFile(Address** phead)  //Запись в файл
{
    ofstream fout;
    fout.open("file.txt");
    Address* t = *phead;
    if (phead == NULL) {
        cout << "Список пуст" << endl;
    }
    else {
        if (fout.is_open()) {
            while (t != NULL) {
                fout << t->name << ' ' << t->city << endl;
                t = t->next;
            }

            cout << "Запись в файл успешна завершена" << endl;
            fout.close();
        }
        else {
            cout << "error" << endl;
        }
    }
}
//-----------------------------------------------------------
void readFromFile(Address** phead, Address** plast)   //Считывание из файла
{
    string str;
    ifstream fin;

    fin.open("file.txt");
    if (fin.is_open()) {
        while (!fin.eof()) {
            getline(fin, str);
            cout << str << endl;
        }
    }
    else {
        cout << "error" << endl;
    }
}


void deleteKLast(int k, Address*& phead, Address*& plast) {
    Address* t;

    if (counter < k) {
        cout << "Некорректное значение\n";
    }
    else {
        for (int i = 0; i < k; i++)
        {
            t = plast;
            if (phead == t)
            {
                phead = t->next;
                if (phead)
                    (phead)->prev = NULL;
                else
                    plast = NULL;
            }
            else
            {
                t->prev->next = t->next;
                if (t != plast)
                    t->next->prev = t->prev;
                else
                    plast = t->prev;
            }
            delete t;
        }
        counter -= k;
        cout << "Элементы удалены" << endl;
    }
    
}

//-----------------------------------------------------------
int main(void) {
    setlocale(LC_CTYPE, "Rus");
    Address* head = NULL;
    Address* last = NULL;


    while (true)
    {
        switch (menu())
        {
        case 1:  insert(setElement(), &head, &last);
            break;
        case 2: {
            char dname[NAME_SIZE];
            cout << "Введите имя: ";
            cin.getline(dname, NAME_SIZE - 1, '\n');
            cin.ignore(cin.rdbuf()->in_avail());
            cin.sync();
            delet(dname, &head, &last);
        }
              break;
        case 3: outputList(&head, &last);
            break;
        case 4: {
            char fname[NAME_SIZE];
            cout << "Введите имя: ";
            cin.getline(fname, NAME_SIZE - 1, '\n');
            cin.ignore(cin.rdbuf()->in_avail());
            cin.sync();
            find(fname, &head);
        }
              break;
        case 5:writeToFile(&head); break;
        case 6:readFromFile(&head, &last); break;
        case 7: 
            int k;
            cout << "Введите количество k: "; 
            cin >> k;
            deleteKLast(k, head, last); 
            break;
        case 8: dop1(); break;
        case 11: exit(0);
        default: exit(1);
        }
    }
    return 0;
}