#include<iostream>

using namespace std;

void input_array_increase(int arr[], int& n)
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

// Giải thuật tìm cặp phần tử arr[i] + arr[j] = key với độ phức tạp về thời gian tùy ý
void find_pair_of_elements(int arr[], int n, int key)
{
	bool l = false;
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			if (arr[i] + arr[j] == key)
			{
				l = true;
				cout << "Cap phan tu thoa man la: " << arr[i] << " " << arr[j] << endl;
			}
		}
	}
	if (l == false)
	{
		cout << "Khong ton tai cap phan tu thoa man\n";
	}
}

// Giải thuật tìm cặp phần tử arr[i] + arr[j] = key với độ phức tạp về thời gian là O(n)
void find_pair_of_elements_2(int arr[], int n, int key)
{
	int L = 0;
	int R = n - 1;
	bool l = false;

	while(L < R)
	{
		if (arr[L] + arr[R] == key)
		{
			l = true;
			cout << "Cap phan tu thoa man la: " << arr[L] << " " << arr[R] << endl;
			L++;
			R--;
		}
		else if (arr[L] + arr[R] < key)
			L++;
		else
			R--;
	}
	if (l == false)
	{
		cout << "Khong ton tai cap phan tu thoa man\n";
	}
}

int main() {
	int a[101];
	int n;

	input_array_increase(a, n);
	output_array(a, n);

	int key;
	cout << "Nhap vao gia tri key: ";
	cin >> key;

	// Câu a:
	cout << "########## CAU A ##########\n";
	find_pair_of_elements(a, n, key);

	// Câu b:
	cout << "########## CAU B ##########\n";
	find_pair_of_elements_2(a, n, key);

	return 0;
}