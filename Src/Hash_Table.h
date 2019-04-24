#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct HashNode
{
	int Key;
	string Name;
	HashNode *pNext;
};
class Hash_Table
{
private:
	vector <HashNode *> HashMap;
	int HashFunc(int key) { return (key*73)%101; }//hash function

public:
	Hash_Table(int HashMapSize);

	bool Hash_Insert(int key,string name);
	bool Hash_Insert(HashNode* new_node);

	bool Hash_Delete(int key);
	bool Hash_Delete(int key, string name);
	bool Hash_Delete(HashNode* node);

	HashNode* Hash_Search(int key);
	HashNode* Hash_Search(int key, string name);
	~Hash_Table();
};

