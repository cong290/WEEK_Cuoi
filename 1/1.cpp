#include<iostream>

using namespace std;

// Khởi tạo mảng ngẫu nhiên
void generate_rand_array(int arr[], int N)
{
	srand((unsigned int)time(NULL));

	for (int i = 0; i < N; i++)
	{

		arr[i] = rand() % 1001;		// Các phần tử có giá trị từ 0 đến 1000
	}
}

// Hàm chia mảng thành 2 dãy con 
int partition(int arr[], int left, int right)
{
	int pivot = arr[right];    // phần tử "chuẩn"
	int i = (left - 1);

	for (int j = left; j <= right - 1; j++)
	{
		if (arr[j] <= pivot)
		{
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[right]);
	return (i + 1);
}

// Quick sort
void QuickSort(int arr[], int left, int right)
{
	if (left < right)
	{
		// Chia dãy (left, right) thành 2 dãy con
		int p = partition(arr, left, right);

		QuickSort(arr, left, p - 1);
		QuickSort(arr, p + 1, right);
	}
}

// Hàm tính thời gian thực hiện của thuật toán Quick sort
void time_use_QuickSort(int arr[], int l, int r) {
	clock_t start, end;
	double cpu_time_used;
	start = clock();

	QuickSort(arr, l, r);

	end = clock();
	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	cout << "Thoi gian thuc hien thuat toan Quick sort la: " << cpu_time_used << endl;
}

// Bubble Sort
void BubbleSort(int arr[], int n)
{
	int i, j;
	bool swapped;
	for (i = 0; i < n - 1; i++)
	{
		swapped = false;
		for (j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
				swapped = true;
			}
		}

		// Nếu không có swap nào được thực hiện thì mảng đã được sắp xếp 
		if (swapped == false)
			break;
	}
}

// Hàm tính thời gian thực hiện của thuật toán Bubble sort
void time_use_BubbleSort(int arr[], int n) {
	clock_t start, end;
	double cpu_time_used;
	start = clock();

	BubbleSort(arr, n);

	end = clock();
	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	cout << "Thoi gian thuc hien thuat toan Bubble sort la: " << cpu_time_used;
}

int main()
{
	int N = 50000;
	int rand_array[50000];

	generate_rand_array(rand_array, N);

	int Left = 0;
	int Right = N - 1;

	//time_use_QuickSort(rand_array, Left, Right);

	time_use_BubbleSort(rand_array, N);

	return 0;
}