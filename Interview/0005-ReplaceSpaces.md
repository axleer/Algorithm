## 问题介绍

需要将给定字符串进行URL编码, 但只需要编码空格.

## 尝试解答

我很自然的找到了$T(n) = O(n)$的解法.

```c++
/**
  This function can replace ' ' to '%20'
  in a c-style string end with '\0'.

  User must delete the return pointer,
  even the string doesn't contain ' '.

  Pass in nullpter will not raise an error,
  instead return a special value nullpter.
*/
char* replace_whitespace(const char* str) {
	if (str == nullptr) return nullptr;

	int pos, whitespaces = 0;
	for (pos = 0; str[pos] != '\0'; pos++) {
		if (str[pos] == ' ') whitespaces++;
	}

	auto res = new char[pos + 2 * whitespaces + 1];
	for (int i = 0, j = 0; i < pos; i++) {
		if (str[i] == ' ') {
			res[j++] = '%';
			res[j++] = '2';
			res[j++] = '0';
		}
		else res[j++] = str[i];
	}
	res[pos + 2 * whitespaces] = '\0';
	
	return res;
}

typedef char* replace_whitespace_func(const char*);

void replace_whitespace_test(replace_whitespace_func* implement) {
	const char* cases[]{
		"We are happy",
		" Begin",
		"End ",
		""
	};
	const char* ans[]{
		"We%20are%20happy",
		"%20Begin",
		"End%20",
		""
	};

	for (int i = 0; i < 4; i++) {
		const char* ret = implement(cases[i]);
		cout << i + 1 << ": " << (strcmp(ret, ans[i]) ? "fail" : "pass") << endl;
		delete ret;
	}
	cout << "5: " << (implement(nullptr) == nullptr ? "pass" : "fail") << endl;
}
```

## 答案对照

海涛提到我们需要问清楚实在原字符串实现, 还是新开辟字符串实现, 而我默认选择了新开辟.

而在一番分析后, 发现好像在原字符串上实现更有挑战, 用到了从后向前双指针填充, 十分巧妙.

海涛在实现原字符串上的实现对, 在预留长度不足时选择了直接返回, 我更倾向通知用户.

我也发现我的测试集仍然没有海涛的全面, 涵盖的测试范围过窄, 连续空格测试用例根本没有!

```c++
void replace_whitespace_test(replace_whitespace_func* implement) {
	const char* cases[]{
		"We are happy",
		"Hello  world",
		" Begin",
		"End ",
		"Normal",
		"",
		" ",
		"  "
	};
	const char* ans[]{
		"We%20are%20happy",
		"Hello%20%20world",
		"%20Begin",
		"End%20",
		"Normal",
		"",
		"%20",
		"%20%20"
	};

	for (int i = 0; i < 8; i++) {
		const char* ret = implement(cases[i]);
		cout << i + 1 << ": " << (strcmp(ret, ans[i]) ? "fail" : "pass") << endl;
		delete ret;
	}
	cout << "9: " << (implement(nullptr) == nullptr ? "pass" : "fail") << endl;
}
```
