#include<list>
#include<unordered_map>
using namespace std;
struct LRUCacheEntry
{
	int key;
	int data;
	LRUCacheEntry* prev;
	LRUCacheEntry* next;
};

class LRUCache{
private:
	unordered_map<int, LRUCacheEntry*>	_mapping;
	vector<LRUCacheEntry* >		_freeEntries;
	LRUCacheEntry *				head;
	LRUCacheEntry *				tail;
	LRUCacheEntry *				entries;
public:
	LRUCache(int capacity);
	~LRUCache();
	int get(int key);
	void set(int key, int value);
private:
	void detach(LRUCacheEntry* node);
	void attach(LRUCacheEntry* node);
};