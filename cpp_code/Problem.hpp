#pragma once


#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

class Problem
{
public:
	int vertices_number = 0;
	int postman_number = 0;
	vector < vector<int>> distance_matrix;
	void read_input()
	{
		cin >> vertices_number >> postman_number;
		distance_matrix.resize(vertices_number + 1);
		for (int i = 0; i <= vertices_number; i++)
		{
			distance_matrix[i].resize(vertices_number + 1);
			for (int j = 0; j <= vertices_number; j++)
			{
				cin >> distance_matrix[i][j];
			}
		}

	}
	void read_input(string path_url)
	{
		ifstream file(path_url);
		file >> vertices_number >> postman_number;
		distance_matrix.resize(vertices_number + 1);
		for (int i = 0; i <= vertices_number; i++)
		{
			distance_matrix[i].resize(vertices_number + 1);
			for (int j = 0; j <= vertices_number; j++)
			{
				file >> distance_matrix[i][j];
			}
		}
	}


};
