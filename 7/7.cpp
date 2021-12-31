#include<iostream>

using namespace std;

void find_max(int arr[], int n)
{
	int max = arr[0];
	int index_start;
	int num_elements;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= n-i; j++)
		{
			int sum = 0;

			int k;
			for (k = j; k < j+i; k++)
			{
				
				sum += arr[k];
			}
			if (sum > max)
			{
				max = sum;

				index_start = j;
				num_elements = i;
			}
		}
	}

	if (max < 0)
	{
		cout << "Mang rong\n";
		return;
	}

	cout << "max = " << max<<endl;
	cout << "Day con lien tuc co tong lon nhat: ";
	int index;
	for (index = index_start; index <= num_elements+1; index++)
	{
		cout << arr[index] << " ";
	}
}

int main()

{
	int a[8] = {-2, -5, 6, -2, -3, 1, 5, -6};

	find_max(a, 8);

	return 0;
}