#include <iostream>
#include <queue>
#include <stack>
#define MAXN 100
using namespace std;

struct Node
{
    int row, col, Move_Dir; // Move_Dir 表示从该节点移向下一个节点走的方向
};

bool is_Visited[MAXN][MAXN];
Node Father_Node[MAXN][MAXN];   // 访问节点的父结点，即从哪儿来
int dr[4] = {-1, 1, 0, 0}, dc[4] = {0, 0, -1, 1};   // 上下左右的方向变化
char *direction = "UDLR";

void BFS(int row, int col)
{
    /* 从起点访问 */
}

void Print_Path(int row, int col)
{
    /* 从终点访问 */

}

int main()
{
    return 0;
}