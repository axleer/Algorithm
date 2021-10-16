##### Concept

Iterator is used for forward list.

##### Implement

```cpp
template<typename E>
class Iterator {
private:
    Node<E> * now;
public:
    Iterator(Node<E> * head) : now(head) {}

    bool has_next() {
        return now != nullptr;
    }

    E next() {
        auto item = now->item;
        now       = now->next;
        return item;
    }
};
```
