#include <iostream>
#include <vector>
#include <deque>
#include <map>
using namespace std;
int GridPathsNiave(int width, int height) {
	if (width == 1) return 1;
	if (height == 1) return 1;
	return GridPathsNiave(width - 1, height) + GridPathsNiave(width, height - 1);
}
int GridPaths(int width, int height) {
	vector<vector<int>> memos(width, vector<int>(height, 1));
	for (int j = 1; j < width; j++) {
		for (int k = 1; k < width; k++) {
			memos[j][k] = memos[j - 1][k] + memos[j][k - 1];
		}
	}
	return memos[width - 1][height - 1];

}

bool canSumNiave(int goal, std::deque<int> items) {
	for (int i = 0; i < items.size(); i++) {
		int temp = items[0];
		if ((goal - temp) == 0)return true;
		if (goal - temp > 0) {
			items.pop_front();
			if (canSumNiave(goal-temp, items))return true;
			items.push_back(temp);
		}
	}
	return false;
}
std::map<int, bool> empt;
bool canSumMulti(int goal, std::deque<int> items, std::map<int, bool> &memos=empt) {
	for (int i = 0; i < items.size(); i++) {
		int temp = items[i];
		if ((goal - temp) == 0)return true;
		if (memos.count(goal - temp) == 1)return true;
		if (goal - temp > 0) {
			if (canSumMulti(goal - temp, items, memos)) {
				memos[goal - temp] = true;
				return true;
			}
		}
	}
	return false;
}



 int main() {
	 std::deque<int> test{ 2,3,4,5,7 };
	 std::cout << canSumMulti(12, test);
	 std::cout << canSumMulti(1, test);
	 std::cout << canSumMulti(2, test);
	 std::cout << canSumMulti(3, test);
	 std::cout << canSumMulti(7, test);
	 std::cout << canSumMulti(23, test);
	 std::cout << canSumMulti(20, test);

	return 1;
}