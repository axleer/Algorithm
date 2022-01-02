## 问题介绍

从尾到头输出链表, 不能修改原来的链表.

## 尝试解答

很容易想到这是一个栈的应用.

```c++
class Node {
public:
	int   val;
	Node* next;
};

/**
  This function can print a linklist reversely.

  When pass in nullptr, print [] instead of empty.
*/
void reverse_print(const Node* head) {
	stack<int> vals;

	while (head != nullptr) {
		vals.push(head->val);
		head = head->next;
	}

	cout << '[';
	while (vals.size() != 0) {
		cout << vals.top() << ',';
		vals.pop();
	}
	cout << ']';
}

typedef void reverse_print_func(const Node* head);

void reverse_print_test(reverse_print_func* implement) {
	Node* head = new Node();
	head->val = 1;
	head->next = new Node();
	head->next->val = 2;
	head->next->next = nullptr;

	implement(head);
	implement(nullptr);

	delete head->next;
	delete head;
}
```

## 答案分析

海涛分析了两种方案一种是栈, 另一种是递归, 而我没考虑那么多.

海涛使用了指针栈, 而我则使用整数栈, 主要是考虑值为内置类型.

这一次我所用的测试集还算全面, 毕竟测试集很容易想得到.