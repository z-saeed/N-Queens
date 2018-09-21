#include <iostream>
#include <stack>
#include <cmath>

#define N 8;

using namespace std;

bool isSafe(int coords[N], stack <int> queens, int col, int row)
{
	if(queens.empty()) {
		return true;
	}
	for (int i = 1; i < row; i++) {
		if (col == coords[i - 1]) {
			return false;
		}
		if (abs(row - i) == abs(col - coords[i-1])) {
			return false;
		}
	}
	return true;
}

void showstack(stack <int> s) 
{ 
    while (!s.empty()) 
    { 
        cout << '\t' << s.top(); 
        s.pop(); 
    } 
    cout << '\n'; 
} 

bool insertQueen(stack <int> queens, int coords[N])
{
	if(queens.size() == N) {
		showstack(queens);
		return true;
	}
	for (int i = 1; i <= N; i++) {
		if(isSafe(coords, queens, i, queens.size() + 1)) {
			queens.push(i);
			coords[queens.size() - 1] = i;
			if(insertQueen(queens, coords)) {
				return true;
			} else {
				queens.pop();
			}
		}
	}
	return false;
}

int main()
{
	//8-Queens
	stack <int> queens;
	int coords[N];

	if (insertQueen(queens, coords)) {
		return 0;
	}

	return 0;
}
