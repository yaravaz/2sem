#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <chrono>

#define strl 200000
#define TABLE1_MAX 16
#define TABLE2_MAX 32
#define TABLE3_MAX 64
#define TABLE4_MAX 128
#define INT_MAX 32767

using namespace std;

struct node {
    long long int number;
    string name;
    node* next;
};

struct  hashTable
{
    node** items;
    int size;
    int count;
};

int collisionCount = 0;

int hashFun(int key, int size)
{
    return key % size;
}

int HashFunction(int key, int size, int p)
{
    int key2 = 5 * ((0.6180339887499 * key) - int((0.6180339887499 * key)));
    return (p + key) % size;
}

node* createNode(int key, string s) {
    node* newNode = new node;
    newNode->number = key;
    newNode->name = s;
    newNode->next = NULL;
    return newNode;
}

hashTable* htCreate(int size) {
    hashTable* htNew = new hashTable;
    htNew->size = size;
    htNew->count = 0;
    htNew->items = new node * [size];
    for (int i = 0; i < size; i++)
        htNew->items[i] = NULL;
    return htNew;
}

void deleteHT(hashTable* table) {
    for (int i = 0; i < table->count; i++)
        delete table->items[i];
    delete table;
}

void put(hashTable* table, int key, string name) {
    int index = hashFun(key, table->size);
    node* currentItem = table->items[index];
    node* p0;
    if (table->count == table->size) {
        printf("Ошибка: хеш-таблица заполнена\n");
        return;
    }

    p0 = table->items[index];
    while (p0 != NULL) {
        if (p0->number == key) {
            p0->name = name;
            return;
        }
        p0 = p0->next;
    }

    node* HtItem = createNode(key, name);
    if (currentItem != NULL) {
        collisionCount++;
        while (currentItem->next != NULL) {
            if (currentItem->number == key) {
                currentItem->name = name;
                delete HtItem;
                return;
            }
            currentItem = currentItem->next;
        }
        currentItem->next = HtItem;
    }
    else {
        table->items[index] = HtItem;
    }
    table->count++;
}

node* find(hashTable* table, int key) {
    int index = hashFun(key, table->size);
    node* item = table->items[index];
    if (item == NULL) {
        return NULL;
    }
    while (item->next != NULL) {
        if (item->number == key)
            return item;
        item = item->next;
    }
    if (item->number == key)
        return item;
    return NULL;
}

void showHT(hashTable* table) {
    node* p0;
    for (int i = 0; i < table->size; i++)
    {
        p0 = table->items[i];
        cout << "Индекс: " << i;
        while (p0 != NULL) {
            cout << " номер: " << p0->number << " имя: " << p0->name;
            p0 = p0->next;
            cout << " -> ";
        }
        cout << " NULL" << endl;
    }
}

void deleteItem(hashTable* table, int key) {
    int index = hashFun(key, table->size);
    node* item = find(table, key);
    node* p0 = table->items[index];
    if (p0 == item && item != NULL)
    {
        table->items[index] = item->next;
        delete item;
        table->count--;
        collisionCount--;
        return;
    }
    if (item != NULL) {
        while (p0->next != item)
            p0 = p0->next;
        p0->next = item->next;
        delete item;
        table->count--;
        collisionCount--;
    }
    else {
        cout << "Элемент не найден" << endl;
        return;
    }
}

bool isNumber(string input) {
    for (char c : input) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

int main()
{
    setlocale(LC_CTYPE, "rus");
    unsigned int startTime;
    unsigned int endTime;
    cout << "Введите размер таблицы: ";
    int tablesize;
    cin >> tablesize;
    hashTable* t16 = htCreate(tablesize);
    hashTable* t32 = htCreate(TABLE2_MAX);
    hashTable* t64 = htCreate(TABLE3_MAX);
    hashTable* t128 = htCreate(TABLE4_MAX);
    node* item;
    int choice;
    string name;
    string numberStr;
    long long int number;
    char x;
    bool loop = true;
    cout << "1 - Добавление элемента\n2 - Поиск\n3 - Количество коллизий\n4 - Вывод хеш-таблицы\n5 - Удалить элемент\n0 - Выход\nВведите: \n";
    cin >> choice;
    while (loop) {
        switch (choice)
        {
        case 0: loop = false; break;
        case 1: {
        cout << "Введите элемент" << endl;
        cout << "Номер телефона: ";
        cin >> number;
        if (find(t16, number) != NULL) {
            cout << "Место занято" << endl;
            break;
        }
        if (number > INT_MAX) {
            cout << "Слишком большое число, введите до 32767" << endl;
            break;
        }
        cin.get(x);
        cout << "Имя пользователя: ";
        getline(cin, name);
        put(t16, number, name);

        cout << "Ваш выбор: " << endl;
        cin >> choice;
        cout << endl;
        break;
        }
            case 2: {
                cout << "Введите номер: ";
                cin >> number;

                auto begin = std::chrono::high_resolution_clock::now();

                item = find(t16, number);

                auto end = std::chrono::high_resolution_clock::now();
                auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
                double long el = elapsed.count();

                if (item != NULL)
                    cout << item->number << " " << item->name << endl;
                else
                    cout << "Элемент не найден" << endl;

                cout << "Время поиска: " << el << " нс\n";

                cout << "Что дальше?" << endl;
                cin >> choice;
                cout << endl;
                break;
            }
            case 3: {
                cout << "Количество коллизий: " << collisionCount << endl;

                cout << "Что дальше?" << endl;
                cin >> choice;
                cout << endl;
                break;
            }
            case 4: {
                cout << "Вывод хеш-таблицы: " << endl;
                showHT(t16);

                cout << "Что дальше?" << endl;
                cin >> choice;
                cout << endl;
                break;
            }
            case 5: {
                cout << "Ввести номер удаляемого элемента: ";
                cin >> number;
                deleteItem(t16, number);

                cout << "Что дальше?" << endl;
                cin >> choice;
                cout << endl;
                break;
            }
            }

        }
        deleteHT(t16);
        deleteHT(t32);
        deleteHT(t64);
        deleteHT(t128);
    }
