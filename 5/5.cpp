#include<iostream>

using namespace std;

int min_Coins(int coins[], int m, int X)
{
    if (X == 0) 
        return 0;

    int res = INT_MAX;

    // Thử lần lượt các mệnh giá có giá trị nhỏ hơn X
    for (int i = 0; i < m; i++)
    {
        if (coins[i] <= X)
        {
            int sub_res = min_Coins(coins, m, X - coins[i]);

            if (sub_res != INT_MAX && sub_res + 1 < res)
                res = sub_res + 1;
        }
    }
    return res;
}

int main()
{
    int n = 4;
    int coins[] = { 1, 5, 6, 9 };
    // Tại sao có đồng xu có mệnh giá “1” ?? Vì đảm bảo giá trị xu cần đổi đều có thể đổi được với mọi trường hợp  
    
    int X = 13;

    cout << "Menh gia: ";
    for (int i = 0; i < n; i++)
    {
        if (i == n - 1)
            cout << coins[i];
        else
            cout << coins[i] << ", ";
    }
    cout << "\nSo luong dong tien xu it nhat co the doi "<<X<<" xu: "<< min_Coins(coins, n, X)<<endl;

    return 0;
}