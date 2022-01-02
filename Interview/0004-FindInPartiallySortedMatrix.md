## 问题介绍

我们需要从从二维数组中查找元素, 而二维数组每行和每列都已经递增排序了.

## 尝试解答

因为我发现对角线方向是绝对递增, 所以尝试使用二分解决问题.

但我逐渐发觉这个解法对矩阵的形状有一定的依赖, 实现起来不够优雅.

## 思路借鉴

但我看了海涛的讲解后发现他的解法十分优雅.

```cpp
bool matrix_find(const int* matrix, int rows, int columns, int goal) {
	if (matrix == nullptr) return false;

	int x = columns - 1, y = 0;
	while (x > -1 && y < rows) {
		int tr_corner_val = matrix[y * columns + x];
		if      (goal < tr_corner_val) x--;
		else if (goal > tr_corner_val) y++;
		else return true;
	}

	return false;
}

typedef bool matrix_find_func(const int* matrix, int rows, int columns, int goal);

void matrix_find_test(matrix_find_func* implement) {
	int matrix[4][4]{
		{1, 2, 8, 9},
		{2, 4, 9, 12},
		{4, 7, 10, 13},
		{6, 8, 11, 15}
	};
	bool result;
	result = implement(matrix[0], 4, 4, 7);
	cout << "1: " << (result == true ? "pass" : "fail") << endl;

	result = implement(matrix[0], 4, 4, 3);
	cout << "2: " << (result == false ? "pass" : "fail") << endl;

	result = implement(nullptr, 0, 0, 0);
	cout << "3: " << (result == false ? "pass" : "fail") << endl;
}
```

## 答案对照

海涛对所有特殊输入进行了提前处理, 而我则将一部分责任交给内循环的条件了.

海涛使用了数组形式访问, 而我采用解引用, 看起来我的写法就没那么优雅了.

海涛给出的测试用例我非常欣赏, 也是实现时的一个不足之处吧, 考虑的太少了.

```cpp
bool matrix_find(const int* matrix, int rows, int columns, int goal) {
	if (matrix == nullptr) return false;

	int x = columns - 1, y = 0;
	while (x > -1 && y < rows) {
		int tr_corner_val = matrix[y * columns + x];
		if      (goal < tr_corner_val) x--;
		else if (goal > tr_corner_val) y++;
		else return true;
	}

	return false;
}

typedef bool matrix_find_func(const int* matrix, int rows, int columns, int goal);

void matrix_find_test(matrix_find_func* implement) {
	int matrix[4][4]{
		{1, 2, 8, 9},
		{2, 4, 9, 12},
		{4, 7, 10, 13},
		{6, 8, 11, 15}
	};
	bool result;
	result = implement(matrix[0], 4, 4, 7);
	cout << "1: " << (result == true ? "pass" : "fail") << endl;

	result = implement(matrix[0], 4, 4, 1);
	cout << "2: " << (result == true ? "pass" : "fail") << endl;

	result = implement(matrix[0], 4, 4, 15);
	cout << "3: " << (result == true ? "pass" : "fail") << endl;

	result = implement(matrix[0], 4, 4, 3);
	cout << "4: " << (result == false ? "pass" : "fail") << endl;

	result = implement(matrix[0], 4, 4, 0);
	cout << "5: " << (result == false ? "pass" : "fail") << endl;

	result = implement(matrix[0], 4, 4, 16);
	cout << "6: " << (result == false ? "pass" : "fail") << endl;

	result = implement(nullptr, 4, 4, 7);
	cout << "7: " << (result == false ? "pass" : "fail") << endl;

	result = implement(matrix[0], -1, -1, 7);
	cout << "8: " << (result == false ? "pass" : "fail") << endl;
}
```