#include<iostream>

using namespace std;

// Hàm xuất ra dãy con liên tục
void output_subarray(int arr[], int num, int index_start)
{
	
}

// Hàm tìm dãy con liên tục có tổng lớn nhất
void find_subarray_max(int arr[], int n)
{
	int max = arr[0];
	int index_start = -1;
	int num_elements = 0;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= n-i; j++)
		{
			int sum = 0;

			for (int k = j; k < j+i; k++)
			{
				
				sum = sum + arr[k];
			}
			if (sum > max)
			{
				max = sum;

				index_start = j;
				num_elements = i;
			}
		}
	}
	// Kiểm tra mảng con rỗng
	if (max < 0)
	{
		cout << "Mang rong\n";
		return;
	}

	cout << "max = " << max<<endl;
	cout << "Day con lien tuc co tong lon nhat: ";
	for (int index = index_start; index < index_start + num_elements ; index++)
	{
		cout << arr[index] << " ";
	}
}

int main()
{
	int a[8] = {-2, -5, 6, -2, -3, 1, 5, -6};

	find_subarray_max(a, 8);

	return 0;
}