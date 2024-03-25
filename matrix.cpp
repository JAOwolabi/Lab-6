#include <stdio.h>
#include <iostream>
#include <fstream>
#include "matrix.h"

void matrix::createMatrix()
{
	std::ifstream inFile;
	inFile.open("matrix_input.txt");
	inFile >> rows;
	inFile >> cols;
	grid = new double *[rows];
	grid_temp = new double *[rows];
	for (int i = 0; i < rows; i++)
	{
		grid[i] = new double[cols];
		grid_temp[i] = new double[cols];
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			inFile >> grid[i][j];
		}
	}
	return;
}

// 1-2
void matrix::printMatrix()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			std::cout << grid[i][j] << "\t";
		}
		std::cout << "\n";
	}
}

// 3
void matrix::addMatrix()
{

	std::cout << "Addition of given two matrices is:\n";

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			grid_temp[i][j] = grid[i][j] + grid[i][j];
		}
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			std::cout << grid_temp[i][j] << "\t";
		}
		std::cout << "\n";
	}
}

// 4
void matrix::subtractMatrix()
{

	std::cout << "Subtraction of given two matrices is:\n";

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			grid_temp[i][j] = grid[i][j] - grid[i][j];
		}
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			std::cout << grid_temp[i][j] << "\t";
		}
		std::cout << "\n";
	}
}

// 7
double matrix::getMax()
{
	double max_element = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (grid[i][j] > max_element)
				max_element = grid[i][j];
		}
	}

	return max_element;
}

// 6
void matrix::changeElement(int r, int c, int no)
{
	grid[r][c] = no;
	return;
}

// 4
void matrix::multiplyMatrix()
{
	std::cout << "Multiplication of given two matrices is:\n";

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			grid_temp[i][j] = 0;

			for (int k = 0; k < rows; k++)
			{
				grid_temp[i][j] += grid[i][k] * grid[k][j];
			}

			std::cout << grid_temp[i][j] << "\t";
		}

		std::cout << std::endl;
	}
}

// 8
void matrix::transposeMatrix()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			grid_temp[j][i] = grid[i][j];
		}
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			std::cout << grid_temp[i][j] << "\t";
		}
		std::cout << "\n";
	}
}

matrix::~matrix()
{
	for (int i = 0; i < rows; i++)
	{
		delete[] grid[i];
		delete[] grid_temp[i];
	}
	delete[] grid;
	delete[] grid_temp;
}
