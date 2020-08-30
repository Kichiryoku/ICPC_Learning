#include <iostream>
#include <queue>
#include <stack>
#define MAXN 100
using namespace std;

struct Node
{
    int row, col;
    Node() :row(), col(){}  // 无参的构造函数
    Node(int a, int b) :row(a), col(b){}
    bool operator==(const Node b) const
	{
		return this->row == b.row && this->col == b.col;
	}
};

bool is_Visited[MAXN][MAXN];
Node Father_Node[MAXN][MAXN];   // 访问节点的父结点，即从哪儿来
int Move_Dir[MAXN][MAXN];   // 各点从父节点来的移动方向
int dr[4] = {-1, 1, 0, 0}, dc[4] = {0, 0, -1, 1};   // 上下左右的方向变化
char direction[4] = {'U', 'D', 'L', 'R'};
int M, N, st_Row, st_Col, ed_Row, ed_Col;
int maze[MAXN][MAXN], dist[MAXN][MAXN]; // dist 标记各点到起点的最短距离，当然在BFS层次遍历下保证为最短路径

void BFS(int row, int col)
{
    /* 从起点访问 */
    queue<Node> q;
    Node Start_Point = Node(row, col);
    Father_Node[row][col] = Start_Point;
    is_Visited[row][col] = true;
    dist[row][col] = 0;

    q.push(Start_Point);

    while (!q.empty())
    {
        Node point = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int dRow = point.row + dr[i], dCol = point.col + dc[i];
            if (!is_Visited[dRow][dCol] && dRow >= 0 && dRow < M && dCol >= 0 && dCol < N && maze[dRow][dCol])
            {
                is_Visited[dRow][dCol] = true;
                dist[dRow][dCol] = dist[point.row][point.col] + 1;
                Father_Node[dRow][dCol] = point; 
                Move_Dir[dRow][dCol] = i;
                q.push(Node(dRow, dCol));
            }
        }

    }
}

void Print_Path(int row, int col)
{
    /* 从终点访问 */
    stack<char> path;
    path.push(direction[Move_Dir[row][col]]);
    while (true)
    {
        Node fNode = Father_Node[row][col];
        int fRow = fNode.row, fCol = fNode.col;
        if (Father_Node[fRow][fCol] == fNode)
            break;  // 此时到起点了
        path.push(direction[Move_Dir[fRow][fCol]]);
        row = fRow, col = fCol;
    }

    cout << "从起点开始的移动方向:" << endl;
    while (!path.empty())
    {
        cout << path.top();
        path.pop(); 
    }
    cout << endl;

}

int main()
{
    // cout << "输入迷宫的行列数" << endl;
    cin >> M >> N;
    // cout << "输入迷宫地图，1代表道路，0代表墙壁" << endl;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
            cin >> maze[i][j];
    }
    /*
    cout << "迷宫地图如下" << endl;

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
            cout << maze[i][j] << " ";
        cout << endl;
    }
    */

    // cout << "输入起点终点坐标" << endl;
    cin >> st_Row >> st_Col >> ed_Row >> ed_Col;

    BFS(st_Col, st_Col);
    Print_Path(ed_Row, ed_Col);

    return 0;
}

/*
6 5
1 1 0 1 1
1 0 1 1 1
1 0 1 0 0
1 0 1 1 1
1 1 1 0 1
1 1 1 1 1
0 0 0 4
*/