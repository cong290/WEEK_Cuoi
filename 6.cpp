#include<iostream>

using namespace std;

void input_array(int arr[],int &n)
{
    cout << "Nhap so luong phan tu mang: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i << "]:";
		cin >> arr[i];
	}
}

void output_array(int arr[],int n)
{
    for(int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

// Câu a: Giải thuật tìm phần tử đa số trong mảng với độ phức tạp về thời gian tùy ý
void find_majorrity_element(int arr[],int n)
{
    int arr_logic[100];
    for(int i = 0; i < n; i++)
    {
        arr_logic[i] = 0;  
    }
    for(int i = 0; i <= n/2; i++)
    {
        if(arr_logic[i] == 0)
        {
            int count = 1;
            for(int j = i+1; j < n; j++)
            {
                if(arr[j] == arr[i])
                {
                    count++;
                    arr_logic[j] = 1;
                }
            }
            if(count > n/2)
            {
                cout<<"Phan tu da so trong mang la: "<<arr[i]<<endl;
                return ;            
            }
        }
    }
   cout<<"Khong co phan tu da so trong mang\n";
}

// Câu b: Giải thuật tìm phần tử đa số trong mảng có độ phức tạp về thời gian là O(n)

// hàm Kiểm tra một phần tử là phần tử đa số trong mảng
bool isMajority(int arr[], int n, int cand)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == cand)
            count++;
    }
    if (count > n / 2)
        return 1;
    else
        return 0;
}

// Hàm tìm phần tử đa số với độ phức tạp thời gian O(n)
void find_majority_element_2(int arr[], int n)
{
    int index = 0;
    int count = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[index] == arr[i])
            count++;
        else
            count--;
        if (count == 0) 
        {
            index = i;
            count = 1;
        }
    }
    if (isMajority(arr, n, arr[index]))
        cout << "Phan tu da so trong mang la: " << arr[index] <<endl;
    else
        cout << "Khong co phan tu da so trong mang";
}

int main()
{
    int a[100];
    int n;

    input_array(a,n);
    output_array(a,n);

    // Câu a:
    cout << "########## CAU A ##########\n";
    find_majorrity_element(a, n);
    cout << "########## CAU B ##########\n";
    find_majority_element_2(a, n);

    return 0;
}