#include "Hash_Table.h"


//init hash table
Hash_Table::Hash_Table(int HashMapSize)
{
	HashMap.reserve(HashMapSize);
	for (int i=0;i<HashMapSize;i++)
	{
		HashMap[i] = nullptr;
	}
}
//Insert a node into the hash table
bool Hash_Table::Hash_Insert(int key, string name)
{
	HashNode *NewNode = new HashNode;
	NewNode->Key = key;
	NewNode->Name = name;
	Hash_Insert(NewNode);
	return true;
}
//Insert a node into the hash Table
bool Hash_Table::Hash_Insert(HashNode* new_node)
{
	int HashKey = HashFunc(new_node->Key);
	//链表地址法解决hash冲突，另一种方法是开放定址法
	new_node->pNext = HashMap[HashKey];//存在相同的地址时，生成链表
	HashMap[HashKey] = new_node;

	return true;
}
//Delete all of the node which value equals to key
bool Hash_Table::Hash_Delete(int key)
{
	int HashKey = HashFunc(key);
	if (nullptr == HashMap[HashKey])
	{
		return false;
	}
	HashNode* pDelNode = HashMap[HashKey];
	while (HashMap[HashKey])
	{
		pDelNode = HashMap[HashKey];
		HashMap[HashKey] = pDelNode->pNext;
		delete pDelNode;
	}
	return true;
}
//Delete a node which valued _key and name = _name
bool Hash_Table::Hash_Delete(int key, string name)
{
	int HashKey = HashFunc(key);
	if (nullptr == HashMap[HashKey])
	{
		return false;
	}
	bool IsExist = false;
	HashNode* pDelNode = HashMap[HashKey];
	HashNode* pTempNode = HashMap[HashKey];
	while (pDelNode)
	{
		if (pDelNode->Name == name)
		{
			IsExist = true;
			break;
		}
		pTempNode = pDelNode;
		pDelNode = pDelNode->pNext;
	}
	if ((pDelNode == pTempNode) && (pDelNode = HashMap[HashKey]))
	{//链表首部
		HashMap[HashKey] = pDelNode->pNext;
	}
	else
	{
		pTempNode->pNext = pDelNode->pNext;
	}
	//存在返回true，不存在返回false
	return (IsExist ? true:false);
}
//Delete a node from the hash table which equals to node
bool Hash_Table::Hash_Delete(HashNode* node)
{
	return Hash_Delete(node->Key,node->Name);
}

HashNode* Hash_Table::Hash_Search(int key)
{
	return HashMap[key];
}
HashNode* Hash_Table::Hash_Search(int key, string name)
{
	int HashKey = HashFunc(key);
	HashNode* pSearchNode = HashMap[HashKey];
	while (pSearchNode)
	{
		if (name == pSearchNode->Name)
		{
			break;
		}
		pSearchNode = pSearchNode->pNext;
		
	}
	return pSearchNode;
}

Hash_Table::~Hash_Table()
{
}
