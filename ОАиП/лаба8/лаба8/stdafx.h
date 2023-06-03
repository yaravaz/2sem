#pragma once
#include <iostream>
#include <string>

using namespace std;

struct Q {
	char a;
	Q* next;
	Q* head;
	Q* tail;
};

void PushQ(Q* queue, int Size);
void ViewQ(Q* queue);
int SizeQ(Q* queue);
void PopQ(Q* queue);