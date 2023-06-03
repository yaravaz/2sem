#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

class HashTable {
public:
    HashTable(int size): 
        m_size(size), 
        m_table(size) 
    {}

    void insert(int key, int value) {
        int index = hash(key);
        m_table[index].emplace_back(key, value);
    }

    pair<int, int>* find(int key) {
        int index = hash(key);
        for (auto& item : m_table[index]) {
            if (item.first == key) {
                return &item;
            }
        }
        return nullptr;
    }

private:
    int hash(int key) const {
        return key % m_size;
    }

    int m_size;
    vector<vector<pair<int, int>>> m_table;
};

int main() {
    setlocale(LC_ALL, "rus");

    HashTable table16(16);
    HashTable table32(32);

    for (int i = 0; i < 100; ++i) {
        table16.insert(i, i);
        table32.insert(i, i);
    }

    auto start_time16 = chrono::steady_clock::now();
    for (int i = 0; i < 1000000; ++i) {
        auto result = table16.find(i % 100);
    }
    auto end_time16 = chrono::steady_clock::now();
    cout << "Время поиска в первой таблице: " << chrono::duration_cast<chrono::milliseconds>(end_time16 - start_time16).count() << " ms" << endl;

    auto start_time32 = chrono::steady_clock::now();
    for (int i = 0; i < 1000000; ++i) {
        auto result = table32.find(i % 100);
    }
    auto end_time32 = chrono::steady_clock::now();
    cout << "Время поиска во второй таблице: " << chrono::duration_cast<chrono::milliseconds>(end_time32 - start_time32).count() << " ms" << endl;

    return 0;
}