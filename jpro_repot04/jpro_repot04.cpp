#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

//#define Q1
//#define Q2
#define Q3

// Node, Queueと Stack クラスはここに定義
// または include してもよい
#include "Queue.h"
#include "Stack.h"

// 迷路に設置するセルの属性
enum {
	WALL = -1,      // 壁
	EMPTY = 0,      // 通路
	ROUTE = 1,      // ゴールまでの道
	LEFT = 1001,    // 左のセルからきた（探索途中用）
	RIGHT,          // 右のセルからきた（探索途中用）
	UP,             // 上のセルからきた（探索途中用）
	DOWN,           // 下のセルからきた（探索途中用）
	START           // 出発セル（探索途中用）
};

bool solveByQueue(int** arr, const int n) {
	// 空のキューを用意する
	Queue q;

	// 始点(0,0)をキューに追加する
	q.enqueue(Point(0, 0));
	arr[0][0] = START;

	// [問題１]幅優先探索を行う（キューを利用してコードを補完する）
	while (!q.isEmpty()) {
		Point p = q.dequeue();
#ifdef _DEBUG
		cout << p << "を中心に探索開始" << endl;
#endif // _DEBUG

		Point neighbors[4] = {
			Point(p.getX()    , p.getY() - 1),
			Point(p.getX() + 1, p.getY()),
			Point(p.getX()    , p.getY() + 1),
			Point(p.getX() - 1, p.getY())
		};

		for (int i = 0; i < 4; i++) {
			const int x = neighbors[i].getX();
			const int y = neighbors[i].getY();
			if (x == n || x == -1 || y == n || y == -1) continue;
			if (arr[x][y] == EMPTY) {

				q.enqueue(neighbors[i]);
#ifdef _DEBUG
				cout << neighbors[i] << "をエンキューしました" << endl;
#endif // _DEBUG

#ifdef  Q1
				arr[x][y] = ROUTE;
#elif defined Q2 || defined Q3
				if (i == 0) {
					arr[x][y] = RIGHT;
#ifdef _DEBUG
					cout << "RIGHT" << endl;
#endif // _DEBUG
				}
				else if (i == 1) {
					arr[x][y] = UP;
#ifdef _DEBUG
					cout << "UP" << endl;
#endif // _DEBUG
				}
				else if (i == 2) {
					arr[x][y] = LEFT;
#ifdef _DEBUG
					cout << "LEFT" << endl;
#endif // _DEBUG
				}
				else if (i == 3) {
					arr[x][y] = DOWN;
#ifdef _DEBUG
					cout << "DOWN" << endl;
#endif // _DEBUG
				}
#endif
			}
		}

	}


	// ゴールセルの状態を確認する
	if (arr[n - 1][n - 1] == EMPTY)
		return false;
	return true;
}

//Stackを利用して迷路を解く
bool solveByStack(int** arr, const int n) {
	arr[0][0] = START;
	Stack s;
	s.push(Point(0, 0));

	while (!s.isEmpty()) {
		Point p = s.pop();
		Point neighbor[4] = {
			Point(p.getX() + 1, p.getY()),
			Point(p.getX() - 1, p.getY()),
			Point(p.getX()    , p.getY() - 1),
			Point(p.getX()    , p.getY() + 1)
		};

		for (int i = 0; i < 4; i++)
		{
			int x = neighbor[i].getX();
			int y = neighbor[i].getY();
			if (x == -1 || x == n || y == -1 || y == n) continue;
			if (arr[x][y] == EMPTY) {
				if (i == 0) {
					arr[x][y] = UP;
				}
				else if (i == 1) {
					arr[x][y] = DOWN;
				}
				else if (i == 2) {
					arr[x][y] = RIGHT;
				}
				else if (i == 3) {
					arr[x][y] = LEFT;
				}
				s.push(neighbor[i]);
			}
		}
	}

	// ゴールセルの状態を確認する
	if (arr[n - 1][n - 1] == EMPTY)
		return false;
	return true;
}

// Mapを初期化する
void initMap(int** arr, const int n) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (arr[i][j] != WALL)
				arr[i][j] = EMPTY;
}

// Mapをプリントする
void printMap(int** arr, const int n) {
	for (int i = -1; i <= n; i++) {

		for (int j = -1; j <= n; j++) {
			if (i == -1 || i == n || j == -1 || j == n)
				cout << "■";
			else if (arr[i][j] == WALL)
				cout << "×";
			else if (arr[i][j] == ROUTE)
				cout << "●";

#ifdef _DEBUG
			else if (arr[i][j] == UP)
				cout << "↑";
			else if (arr[i][j] == LEFT)
				cout << "←";
			else if (arr[i][j] == DOWN)
				cout << "↓";
			else if (arr[i][j] == RIGHT)
				cout << "→";
#endif // _DEBUG

			else
				cout << "　";
		}
		cout << endl;

	}
}

void printPath(int** arr, const int n) {
	// [問題２]スタックを利用して，ゴールまでの経路と地図を描画する
	// 描画する際に，printMap関数を利用してよい
	Stack s;
	Point p = Point(n - 1, n - 1);
	s.push(p);

	while (arr[p.getX()][p.getY()] != START) {//スタートまでの経路をスタックに格納する
		int dir = arr[p.getX()][p.getY()];
#ifdef _DEBUG
		cout << p << " : ";
#endif // _DEBUG
		if (dir == UP) {
			p += Point(-1, 0);
#ifdef _DEBUG
			cout << "UP" << endl;;
#endif // _DEBUG
		}
		else if (dir == LEFT) {
			p += Point(0, -1);
#ifdef _DEBUG
			cout << "LEFT" << endl;;
#endif // _DEBUG
		}
		else if (dir == DOWN) {
			p += Point(1, 0);
#ifdef _DEBUG
			cout << "DOWN" << endl;;
#endif // _DEBUG
		}
		else if (dir == RIGHT) {
			p += Point(0, 1);
#ifdef _DEBUG
			cout << "RIGHT" << endl;;
#endif // _DEBUG
		}
		s.push(p);//経路をスタックに記録
	}

	//ゴールからスタートまでの座標がスタックに積まれた状態になっている
	//経路を出力する
	cout << "Path : ";
	while (!s.isEmpty()) {
		Point p = s.pop();
		arr[p.getX()][p.getY()] = ROUTE;
		cout << p << " ";
	}
	cout << endl;

	printMap(arr, n);
}

int main() {
	int n;
	int** ins;

	// 問題入力の読み込み
	char fName[100];
	cout << "問題例ファイルを入力してください：";
	cin >> fName;
	ifstream fin(fName, ios::in);
	if (!fin) {
		cout << "Error: ファイル(" << fName << ")が開けません．" << endl;
		exit(1);
	}
	fin >> n;
	ins = new int* [n];
	for (int i = 0; i < n; i++) {
		ins[i] = new int[n];
		for (int j = 0; j < n; j++)
			//※下方向が、X軸正の向き。
			//※右方向が、Y軸正の向き。
			fin >> ins[i][j];
	}

	// 入力地図の描画
	printMap(ins, n);

	// キューを利用する迷路探索
	bool rst = solveByQueue(ins, n);
#ifdef _DEBUG
	printMap(ins, n);
#endif // _DEBUG


	if (rst) {
		cout << "Queue: ゴールまで到達可能" << endl;
#if defined Q2 || defined Q3
		printPath(ins, n);
#endif 
	}
	else {
		cout << "Queue: ゴールまで到達不可能" << endl;
	}

#ifdef Q3

	//[問題３] に関係するコード
	// 入力地図の初期化
	initMap(ins, n);

	// スタックを利用する迷路探索
	rst = solveByStack(ins, n);
	if (rst) {
		cout << "Stack: ゴールまで到達可能" << endl;
		printPath(ins, n);
	}
	else {
		cout << "Stack: ゴールまで到達不可能" << endl;
	}
#endif // Q3

	for (int i = 0; i < n; i++)
		delete[] ins[i];
	delete[] ins;
	return 0;
}