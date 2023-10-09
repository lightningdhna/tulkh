#include <algorithm>
#include<iostream>
#include <vector>
#define ll long long
using namespace std;

const int mxN = 1e3 + 2;
const int mxK = 1e2 + 2;
int n, k;
int d[mxN + 1][mxN + 1];
vector<ll> dsum;


vector<int> cur[mxK];
bool vis[mxN];

ll path_len[mxK];
ll min_max_path_len = 0;

vector<int > best_ans[mxK];
ll best_value = 1e9;

int func_call_cnt = 0;
void search(int postman, int id)
{
	func_call_cnt++;
	//update best answer
	if (postman > k)
	{
		ll max_len = 0;
		for (int i = 0; i < k; i++)
		{
			max_len = max(max_len, path_len[i]);
		}
		if (max_len < best_value)
		{
			best_value = max_len;
			for (int i = 0; i < k; i++)
				best_ans[i] = cur[i];
		}
		return;
	}
	int rq_left = 0;
	for (int i = 1; i <= n; i++)
	{
		if (vis[i])
			continue;
		rq_left++;
		// check bound condition
		if (path_len[postman] + d[cur[postman][id - 1]][i] > best_value)
			return;

		// branch continue to go to rq i


		cur[postman].push_back(i);
		vis[i] = true;
		path_len[postman] += d[cur[postman][id - 1]][i];

		search(postman, id + 1);


		path_len[postman] -= d[cur[postman][id - 1]][i];
		vis[i] = false;
		cur[postman].pop_back();
	}

	// branch and bound go to next postman
	if (!rq_left)
	{
		//branch
		search(postman + 1, 1);
		return;
	}

	if (postman < k - 1)
	{
		// bound check
		if (ceil(dsum[rq_left - 1] * 1.0 / (k - postman - 1)) > best_value)
		{
			return;
		}
		//branch 
		search(postman + 1, 1);
	}

}

int main()
{
	using namespace std;
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	freopen_s(new FILE*, "input.txt", "r", stdin);

	cin >> n >> k;


	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			cin >> d[i][j];
			if (i ^ j)
			{
				dsum.push_back(d[i][j]);
			}
		}
		//d[n][0] = 0;
	}
	sort(dsum.begin(), dsum.end());
	for (int i = 1; i < int(dsum.size()); i++)
		dsum[i] += dsum[i - 1];


	for (int i = 0; i < k; i++)
		cur[i].push_back(0);
	search(0, 1);
	cout << k << endl;
	for (int i = 0; i < k; i++)
	{
		cout << best_ans[i].size() << endl;
		for (const auto rq : best_ans[i])
			cout << rq << " ";
		cout << endl;
	}
	//cout << "number of recursive function called" << endl;
	//cout << func_call_cnt << endl;
}