#pragma once
using namespace std;
const unsigned int CITY_SIZE = 20;

struct DATA
{
	string author;
	string name;
	string publish;
	string type;
	string origin;
};

struct address
{

	DATA data;
	address* next;
	address* prev;
};
void insert(address* e, address** phead, address** plast);
address* setElement();
void outputList(address** phead, address** plast);
void find(string name, address** phead);
void countList(address** phead, address** plast);
void delAll(address** phead, address** plast);