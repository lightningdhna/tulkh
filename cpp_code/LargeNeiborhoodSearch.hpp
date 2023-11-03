#pragma once
#include "Problem.hpp"

#include<iostream>
#include<cmath>
#include<algorithm>
#include<random>

#define Route vector<int>
#define Solution vector<Route>


using namespace std;

class LNS
{
	std::random_device rd;
	std::mt19937 gen(rd());
public:
	int n, k;
	vector<vector<int>> dis;

	Solution best_solution;
	int best_score;

	LNS(const Problem& problem)
	{
		n = problem.vertices_number;
		k = problem.postman_number;
		dis = problem.distance_matrix;

	}
	Solution split_route(Route r) const
	{

		auto check = [=](int mid)->bool
			{
				int k_need = 1;
				int cur = 0;
				int len = 0;
				for (int i = 1; i <= n;)
				{

					if (len + dis[cur][r[i]] > mid)
					{
						// new route
						cur = 0;
						len = 0;
						++k_need;
					}
				}
			};
		Solution s(k);

		int left = 0, right = 1e6;
		// todo make right-left smaller

		while (left < right)
		{
			int mid = (left + right) >> 1;

		}
	}

	Solution random_init() const
	{
		Route r(n + 1);
		for (int i = 1; i <= n; i++)
			r[i] = i;

		shuffle(r.begin() + 1, r.end(), gen);

	}

	Solution solve()
	{
		// LNS
		//init
		// loop
			// destroy
			// repair
			// update ( SA)

		return best_solution;
	}

	void print_solution() const
	{
		cout << best_solution.size() << endl;
		for (const auto& route : best_solution)
		{
			cout << route.size() << endl;
			for (auto& v : route)
			{
				cout << v << " ";
			}
			cout << endl;
		}
	}


	void destroy()
	{

	}



};
