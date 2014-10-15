/*
https://oj.leetcode.com/problems/lru-cache/

LRU Cache 

Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
*/

#include "04_lru_cache.h"
using namespace std;

LRUCache::LRUCache(int capacity){
	entries = new LRUCacheEntry[capacity];
	for (int i=0; i<capacity; i++)
		_freeEntries.push_back(entries+i);
	head = new LRUCacheEntry;
	tail = new LRUCacheEntry;
	head->prev = NULL;
	head->next = tail;
	tail->next = NULL;
	tail->prev = head;
}

LRUCache::~LRUCache()
{
	delete head;
	delete tail;
	delete [] entries;
}


int LRUCache::get(int key){
	LRUCacheEntry* node = _mapping[key];
	if(node)
	{
		detach(node);
		attach(node);
		return node->data;
	}
	else return -1;
}

void LRUCache::set(int key, int data){
	LRUCacheEntry* node = _mapping[key];
	if(node)
	{
		// refresh the link list
		detach(node);
		node->data = data;
		attach(node);
	}
	else{
		if ( _freeEntries.empty() )
		{
			node = tail->prev;
			detach(node);
			_mapping.erase(node->key);
			node->data = data;
			node->key = key;
			_mapping[key] = node;
			attach(node);
		}
		else{
			node = _freeEntries.back();
			_freeEntries.pop_back();
			node->key = key;
			node->data = data;
			_mapping[key] = node;
			attach(node);
		}
	}
}

void LRUCache::detach(LRUCacheEntry* node)
{
	node->prev->next = node->next;
	node->next->prev = node->prev;
}

void LRUCache::attach(LRUCacheEntry* node)
{
	node->next = head->next;
	node->prev = head;
	head->next = node;
	node->next->prev = node;
}

