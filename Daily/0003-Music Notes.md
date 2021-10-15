#### 1-Description

##### The Problem

FJ is going to teach his cows how to play a song. The song consists of N (1 <= N <= 100) notes, and the i-th note lasts for B_i (1 <= B_i <= 100) beats. The cows will begin playing the song at time 0; thus, they will play note 1 from time 0 to time B_1 - 1, note 2 fromtime B_1 to time B_1 + B_2 - 1, etc.

The cows have lost interest in the song, as they feel that it is long and boring. Thus, to make sure his cows are paying attention, FJ asks them Q (1 <= Q <= 1,000) questions of the form, "During the beat at time T_i (0 <= T_i < length of song), which note should you be playing?" The cows need your help to answer these questions.

##### INPUT FORMAT

Line 1: Two space-separated integers: N and Q

Lines 2..N+1: Line i+1 contains a single integer: B_i

Lines N+2..N+Q+1: Line N+i+1 contains a single integer: T_i

The input contains multiple test cases.

##### SAMPLE INPUT

```plaintext
3 5
2
1
3
2
3
4
0
1

```

##### OUTPUT FORMAT

Lines 1..Q: Line i contains the a single integer that is the note the cows should be playing at time T_i

##### SAMPLE OUTPUT

```plaintext
2
3
3
1
1

```

#### 2-Method

1. First, you should calculate the end time of each note.

2. Then find the suitable time for the note in the question.

#### 3-Answer

```cpp
#include <vector>
#include <iostream>

using namespace std;

#define FASTIO \
ios_base::sync_with_stdio(false); \
cin.tie(nullptr);

// This binary search was a template written by me.
template<typename T, typename E>
void tree_lfind(const T & area, const E find, int & left, int & right) {
    if (left > right) throw runtime_error("invalid range for tree_find");

    while (left != right) {
        int mid = (left + right) >> 1;
        if (area[mid] < find) left  = mid + 1;
        else                  right = mid;
    }
}

vector<int> end_times;

int main() {
    FASTIO

    int notes_amount, questions_amount;
    while (cin >> notes_amount >> questions_amount) {
        end_times.clear();
        end_times.push_back(-1); // Good begining.

        for (int i = 0; i < notes; i++) {
            int    single_note_last;
            cin >> single_note_last;
             // Use index i to get the end time of the prevous note.
            times.push_back(times[i] + single_note_last);
        }

        for (int i = 0; i < questions_amount; i++) {
            int    single_question;
            cin >> single_question;

            // find in range [1, notes_amount].
            int left = 1, right = notes_amount;
            tree_lfind(end_times, single_question, left, right);
            cout << left << endl;
        }
    }
}
```