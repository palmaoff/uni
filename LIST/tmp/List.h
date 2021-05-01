#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct Node {
	int info;
	Node* next;
};
typedef Node* Tlist;
void Init(Tlist& list);
bool empty(Tlist list);
void Add_to_head(Tlist& list, int elem);
void Add_to_end(Tlist& list, int elem);
void Print(Tlist list);
int del_from_head(Tlist& list);
void Clear(Tlist& list);
int count_nodes(Tlist list);
void create_as_stack(Tlist& list, ifstream& file);
int max_negative(Tlist list);