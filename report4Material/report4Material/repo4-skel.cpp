#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

// Node, Queueと Stack クラスはここに定義
// または include してもよい

// 迷路に設置するセルの属性
enum{
    WALL = -1,      // 壁
    EMPTY = 0,      // 通路
    ROUTE = 1,      // ゴールまでの道
    LEFT = 1001,    // 左のセルからきた（探索途中用）
    RIGHT,          // 右のセルからきた（探索途中用）
    UP,             // 上のセルからきた（探索途中用）
    DOWN,           // 下のセルからきた（探索途中用）
    START           // 出発セル（探索途中用）
};

bool solveByQueue(int** arr, const int n){
    // 空のキューを用意する
    Queue q;
    
    // 始点(0,0)をキューに追加する
    q.enqueue(Point(0, 0));
    arr[0][0] = START;
    
    // [問題１]幅優先探索を行う（キューを利用してコードを補完する）


    
    // ゴールセルの状態を確認する
    if(arr[n-1][n-1] == EMPTY)
        return false;
    return true;
}

// Mapを初期化する
void initMap(int** arr, const int n){
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(arr[i][j] !=  WALL)
                arr[i][j] = EMPTY;
}

// Mapをプリントする
void printMap(int** arr, const int n){
    for(int i=-1; i<=n; i++){
        for(int j=-1; j<=n; j++){
            if(i == -1 || i == n || j == -1 || j == n)
                cout << "■";
            else if(arr[i][j] == WALL)
                cout << "×";
            else if(arr[i][j] == ROUTE)
                cout << "●";
            else
                cout << " ";
        }
        cout << endl;
    }
}

void printPath(int** arr, const int n){
    // [問題２]スタックを利用して，ゴールまでの経路と地図を描画する
    // 描画する際に，printMap関数を利用してよい
}

int main(){
    int n;
    int** ins;

    // 問題入力の読み込み
    char fName[100];
    cout << "問題例ファイルを入力してください：";
    cin >> fName;
    ifstream fin(fName, ios::in);
    if( !fin ){
        cout << "Error: ファイル(" << fName << ")が開けません．" << endl;
        exit(1);
    }
    fin >> n;
    ins = new int*[n];
    for(int i=0; i<n; i++){
        ins[i] = new int[n];
        for(int j=0; j<n; j++)
            fin >> ins[i][j];
    }

    // 入力地図の描画
    printMap(ins, n);

    // キューを利用する迷路探索
	bool rst = solveByQueue(ins, n);
	if(rst){
        cout << "Queue: ゴールまで到達可能" << endl;
		printPath(ins, n); 
    }
	else{
		cout << "Queue: ゴールまで到達不可能" << endl;
    }

    /*[問題３]に関係するコード
    // 入力地図の初期化
    initMap(ins, n);

    // スタックを利用する迷路探索
	rst = solveByStack(ins, n);
	if(rst){
        cout << "Stack: ゴールまで到達可能" << endl;
		printPath(ins, n);
    }
	else{
		cout << "Stack: ゴールまで到達不可能" << endl;
    }
    */

    for(int i=0; i<n; i++)
        delete[] ins[i];
    delete[] ins;
    return 0;
}