#include <iostream>
#include <queue>

#include <cstdio>

#define MAX_JOY_VALUE 2000000
using namespace std;

struct movie
{
    int l, v;
    movie() :l(), v() {}
    movie(int L, int V) :l(L), v(V) {}
};

struct joy_value
{
    bool operator() (movie a, movie b)
    {
        return a.l * a.v < b.l * b.v;
    }
};

int main()
{
    freopen("ICPC_Learning/Data_Structure/queue/zexal_cinema_stdin.in", "r", stdin);
    priority_queue<movie, vector<movie>, joy_value > movie_select;
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        int L, V;
        cin >> L >> V;
        movie_select.push(movie(L, V));
    }
    long long sum_of_time = 0;
    int min_joy_value = MAX_JOY_VALUE;
    for (int j = 1; j <= k; j++)
    {
        movie tmp = movie_select.top();
        sum_of_time += tmp.l;
        min_joy_value = tmp.v < min_joy_value ? tmp.v : min_joy_value;
        movie_select.pop();
    }
    long long sum_of_joy_value = sum_of_time * min_joy_value;
    cout << sum_of_joy_value << endl;
    return 0;
}
