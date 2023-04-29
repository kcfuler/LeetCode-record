// 定义双向链表
struct DoubleLinkedList
{
  int key, val;
  DoubleLinkedList *prev;
  DoubleLinkedList *next;
  DoubleLinkedList() : key(0), val(0), prev(nullptr), next(nullptr) {}
  DoubleLinkedList(int _key, int _val) : key(_key), val(_val), prev(nullptr), next(nullptr) {}
};

class LRUCache
{
private:
  unordered_map<int, DoubleLinkedList *> cache;
  DoubleLinkedList *head;
  DoubleLinkedList *tail;
  int capacity;
  int size;
  void remove(DoubleLinkedList *node)
  {
    node->next->prev = node->prev;
    node->prev->next = node->next;
  }

  void addToHead(DoubleLinkedList *node)
  {
    node->next = head->next;
    node->prev = head;
    head->next->prev = node;
    head->next = node;
  }

  void moveToHead(DoubleLinkedList *node)
  {
    remove(node);
    addToHead(node);
  }

  DoubleLinkedList *removeTail()
  {
    DoubleLinkedList *node = tail->prev;
    remove(node);
    return node;
  }

public:
  LRUCache(int _capacity) : capacity(_capacity), size(0)
  {
    head = new DoubleLinkedList();
    tail = new DoubleLinkedList();
    head->next = tail;
    tail->prev = head;
  }

  int get(int key)
  {
    if (!cache.count(key)) // 不存在
    {
      return -1;
    }
    // 如果 key 存在，通过hash定位，再移到头部
    DoubleLinkedList *node = cache[key];
    moveToHead(node);
    return node->val;
  }

  void put(int key, int val)
  {
    // 如果没有，就新增
    if (!cache.count(key))
    {
      DoubleLinkedList *node = new DoubleLinkedList(key, val);
      addToHead(node);
      cache[key] = node;
      size++;

      if (size > capacity)
      {
        DoubleLinkedList *removed = removeTail();
        cache.erase(removed->key); // 从哈希表中移除
        delete removed;            // 防止内存泄漏
        size--;
      }
    }
    else
    {
      DoubleLinkedList *node = cache[key];
      moveToHead(node);
      node->val = val;
    }
  }
};
