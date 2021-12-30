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

void find_majorrity_element(int arr[],int n)
{
    int arr_logic[100];
    for(int i = 0; i < n; i++)
    {
        arr_logic[i] = 0;  
    }
    for(int i = 0;i <= n/2;i++)
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
                cout<<"Phan tu da so la: "<<arr[i];
                return ;            
            }
        }
   }
   cout<<"Khong co phan tu da so\n";
}

int main()
{
    int a[100];
    int n;

    input_array(a,n);
    output_array(a,n);

    find_majorrity_element(a, n);

    return 0;
}