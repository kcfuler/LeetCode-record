class DoubleLinkListNode:
    def __init__(self, key: int, val: int):
        self.key = key
        self.val = val
        self.prev = None
        self.next = None


class LRUCache:
    def __init__(self, capacity: int):
        self.cache = dict()
        self.head = DoubleLinkListNode(0, 0)
        self.tail = DoubleLinkListNode(0, 0)
        self.head.next = self.tail
        self.tail.next = self.head
        self.capacity = capacity
        self.size = 0

    def get(self, key: int) -> int:
        if key not in self.cache:
            return -1
        node = self.cache[key]
        self.__move_to_head(node)
        return node.val

    def put(self, key: int, value: int) -> None:
        if key in self.cache:
            node = self.cache[key]
            node.val = value
            self.__move_to_head(node)
        else:
            new_node = DoubleLinkListNode(key, value)
            self.__add_to_head(new_node)
            self.cache[key] = new_node
            self.size += 1

            if self.size > self.capacity:
                node = self.__remove_tail()
                self.cache.pop(node.key)
                self.size -= 1

    def __move_to_head(self, node):
        self.__remove_node(node)
        self.__add_to_head(node)

    def __remove_node(self, node: DoubleLinkListNode):
        node.prev.next = node.next
        node.next.prev = node.prev

    def __add_to_head(self, node: DoubleLinkListNode):
        node.next = self.head.next
        node.prev = self.head.prev
        self.head.next.prev = node
        self.head.next = node

    def __remove_tail(self):
        node = self.tail.prev
        self.__remove_node(node)
        return node
