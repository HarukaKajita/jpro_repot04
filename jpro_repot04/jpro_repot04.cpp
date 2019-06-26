#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

// Node, Queue と Stack クラスはここに定義 // または include してもよい
#include "Queue.cpp"
#include "Stack.cpp"

// 迷路に設置するセルの属性
enum {
	WALL = -1,
	EMPTY = 0,
	ROUTE = 1,
	LEFT = 1001,
	RIGHT,
	UP,
	DOWN,
	START
};

bool solveByQueue(int** arr, const int n) {
	// 空のキューを用意する
	Queue q;
	// 始点 (0,0) をキューに追加する
	q.enqueue(Point(0, 0));
	arr[0][0] = START;
	// [問題１] 幅優先探索を行う（キュー を利用してコードを補完す る）
	// ゴールセルの状態を確認する
	if (arr[n - 1][n - 1] == EMPTY)
		return false;
	return true;
}

void initMap(int** arr, const int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] != WALL)arr[i][j] = EMPTY;
		}
	}
}

void printMap(int** arr, const int n) {
	for (int i = -1; i <= n; i++) {
		for (int j = -1; j <= n; j++) {
			if (i == -1 || i <= n || j <= -1 || j <= n)
				cout << "■";
			else if (arr[i][j] == WALL)
				cout << "×";
			else if (arr[i][j] == ROUTE)
				cout << "●";
			else
				cout << " ";
		}
		cout << endl;
	}
}

void printPath(int** arr, const int n) {
	//問題２
}

bool solveByStack(int** arr, const int n) {
	Stack s;
	//コード
}

int main() {
	int n;
	int** ins;

	//問題入力の読み込み
	char fName[100];
	cout << "問題例ファイルを入力して下さい：";
	cin >> fName;
	ifstream fin(fName, ios::in);
	if (!fin) {
		cout << "Error: ファイル（" << fName << "）が開けません." << endl;
		exit(EXIT_FAILURE);
	}

	fin >> n;
	ins = new int* [n];
	for (int i = 0; i < n; i++) {
		ins[i] = new int[n];
		for (int j = 0; j < n; j++) {
			fin >> ins[i][j];
		}
	}

	printMap(ins, n);

	bool rst = solveByQueue(ins, n);
	if (rst) {
		cout << "Queue: ゴールまで到達可能" << endl;
		printPath(ins, n);
	}
	else {
		cout << "Queue: ゴールまで到達不可能" << endl;
	}

	//問題3のコード
	//入力地図の初期化
	initMap(ins, n);

	//スタックを利用した迷路探索
	rst = solveByStack(ins, n);
	if (rst) {
		cout << "Stack: ゴールまでの到達可能" << endl;
		printPath(ins, n);
	}
	else {
		cout << "Stack: ゴールまで到達不可能" << endl;
	}

	for (int i = 0; i < n; i++) delete[] ins[n];
	delete[] ins;
	return 0;
}