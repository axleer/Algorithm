##### Concept

Bag is used to collect items and find one item when we need it.

##### Implement

```cpp
template<typename E>
class Bag {
private:
    Node<E> * head = nullptr;

public:
    // @Function: Add item to the head.
    void add(E item) {
        auto old_head = head;
        head = new Node<E>;
        head->item = item;
        head->next = old_head;
    }

    Iterator<E> iterator() {
        return Iterator<E>(head);
    }
};
```
