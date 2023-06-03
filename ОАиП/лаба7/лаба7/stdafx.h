#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <string>

using namespace std;

struct Stack
{
	int data;             
	Stack* head;		
	Stack* next;		
};


void show(Stack* myStk);      
int pop(Stack* myStk);           
void push(int x, Stack* myStk);
void clear(Stack * myStk);
bool prov(Stack* myStk);
void infile(Stack*);
void fromfile();
