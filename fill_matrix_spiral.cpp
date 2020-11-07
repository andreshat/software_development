#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

#define M 5
#define N 5

void vectGen(int size, vector<int> &vect)
{
   for (int i = 0; i < size; i++)
   {
      vect.push_back(i+1);
   }
} 

void spiralOrder(vector<int> &arr, vector<vector <int>> &mat)
{
	int top = 0, bottom = mat[0].size() - 1;
	int left = 0, right = mat.size() - 1;

	int index = 0;

	while (1)
	{
		if (left > right)
			break;
		// print top row
		for (int i = left; i <= right; i++)
			mat[top][i]  = arr[index++];
		top++;

		if (top > bottom)
			break;
		// print right column
		for (int i = top; i <= bottom; i++)
			mat[i][right] = arr[index++];
		right--;

		if (left > right)
			break;
		// print bottom row
		for (int i = right; i >= left; i--)
			mat[bottom][i] = arr[index++];
		bottom--;

		if (top > bottom)
			break;
		// print left column
		for (int i = bottom; i >= top; i--)
			mat[i][left] = arr[index++];
		left++;
	}
}

// Create Spiral Matrix from given array
int main()
{
   int size = N*M;
   vector <int> arr;
   vectGen(size, arr);
	// int arr[N*N] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
	// 				16, 17, 18, 19, 20, 21, 22, 23, 24, 25 };
	vector <vector <int>> mat(N, vector <int> (M));

	spiralOrder(arr, mat);

	for (int i = 0; i < mat.size(); i++)
	{
		for (int j = 0; j < mat[0].size(); j++)
			cout << setw(3) << mat[i][j];
		cout << '\n';
	}

	return 0;
}