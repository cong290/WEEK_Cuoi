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
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void find_majorrity_element(int arr[],int n)
{
    for(int i = 0;i < n;i++)
    {
        int count = 0;
        
    }
}

int main()
{
    int a[100];
    int n;

    input_array(a,n);
    output_array(a,n);



    return 0;
}