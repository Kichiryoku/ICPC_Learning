#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

#define MAX_JOY_VALUE 2000000
using namespace std;

struct movie
{
    int l, v;
    movie() :l(), v() {}
    movie(int L, int V) :l(L), v(V) {}
};

bool cmp(const movie a, const movie b)
{
    if (a.l * a.v == b.l * b.v)
        return a.v > b.v;
    return a.l * a.v > b.l * b.v;
}

int main()
{
    freopen("ICPC_Learning/Data_Structure/queue/zexal_cinema_stdin.in", "r", stdin);
    vector<movie> movie_select;
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        int L, V;
        cin >> L >> V;
        movie_select.push_back(movie(L, V));
    }
    sort(movie_select.begin(), movie_select.end(), cmp);
    long long sum_of_time = 0;
    int min_joy_value = MAX_JOY_VALUE;
    for (int j = 0; j < k; j++)
    {
        sum_of_time += movie_select[j].l;
        min_joy_value = min(min_joy_value, movie_select[j].v);
    }
    long long sum_of_joy_value = sum_of_time * min_joy_value;
    cout << sum_of_joy_value << endl;
    return 0;
}
