#include "Judge.hpp"
#include "Problem.hpp"
#include "BABAlgorithm.hpp"
#include "LargeNeiborhoodSearch.hpp"


#include <iostream>
#include <algorithm>
#include<chrono>



#define get_time() high_resolution_clock::now()

using namespace std;
using namespace chrono;
auto start_time = get_time();


Problem problem;
Judge judge(problem);

inline int cal_time_ms()
{
	const auto cur = get_time();
	return duration_cast<nanoseconds>(cur - start_time).count() / 1e6;
}



int main()
{

	freopen_s(new FILE*, "input.txt", "r", stdin);
	freopen_s(new FILE*, "output.txt", "w", stdout);

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	//problem.read_input("input.txt");
	problem.read_input();
	judge = Judge(problem);
	//judge.print_input_solution("my_output.txt");
	//cout << judge.cal_score(BAB(problem).solve());
	LNS(problem).print_solution();
	//cout << endl << cal_time_ms() << " ms" << endl;
}