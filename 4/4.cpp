#include<iostream>

using namespace std;

void input_array(int arr[], int& n)
{
	cout << "Nhap so luong phan tu mang: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i << "]:";
		cin >> arr[i];
	}
}

void output_array(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

// Giải thuật tìm bộ ba phần tử arr[i] + arr[j] + arr[k] = key với độ phức tạp về thời gian tùy ý
void find_triplet(int arr[], int n,int key)
{
	bool l = false;
	for (int i = 0; i < n-2; i++)
	{
		for (int j = i+1; j < n-1; j++)
		{
			for (int k = j+1; k < n; k++)
			{
				if (arr[i] + arr[j] + arr[k] == key)
				{
					cout << "Bo ba phan tu can tim la: " << arr[i] << " " << arr[j] << " " << arr[k] << endl;
					l = true;
				}
			}
		}
	}
	if (l == false)
	{
		cout << "Khong ton tai bo ba phan tu thoa man\n";
	}
}

void sort_array(int arr[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (arr[i] > arr[j])
				swap(arr[i], arr[j]);
		}
	}
}

// Giải thuật tìm bộ ba phần tử arr[i] + arr[j] + arr[k] = key với độ phức tạp về thời gian là O(n^2)
void find_triplet_2(int arr[], int n, int key)
{
	int L, R;
	bool l = false;

	// Sắp xếp mảng tăng dần 
	sort_array(arr, n);

	for (int i = 0; i < n - 2; i++)
	{
		L = i+1;
		R = n - 1;

		while (L < R)
		{
			if (arr[L] + arr[R] + arr[i] == key)
			{
				l = true;
				cout << "Bo ba phan tu can tim la: " << arr[i] << " " << arr[L] << " " << arr[R] << endl;
				L++;
				R--;
			}
			else if (arr[L] + arr[R] + arr[i] < key)
				L++;
			else
				R--;
		}
	}
	if (l == false)
	{
		cout << "Khong ton tai bo ba phan tu thoa man\n";
	}
}

int main()
{
	int a[101];
	int n;

	input_array(a, n);
	output_array(a, n);

	int key;
	cout << "Nhap vao gia tri key: ";
	cin >> key;

	// Câu a:
	cout << "########## CAU A ##########\n";
	find_triplet(a, n,key);

	// Câu b:
	cout << "########## CAU B ##########\n";
	find_triplet_2(a, n, key);

	return 0;
}