#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace chrono;

int main()
{   
    cout<<"Enter the number of iteams:";
    int n;
    cin >> n;

    vector<int> weight(n), value(n);
    cout<<"Enter the weights:";
    for(int i = 0; i < n; i++)
        cin >> weight[i];
    
    cout<<"Enter the values:";    
    for(int i = 0; i < n; i++)
        cin >> value[i];
  
    cout<<"Enter the capacity:";    
    int W;
    cin >> W;

    auto start = high_resolution_clock::now();

    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for(int i = 1; i <= n; i++)
    {
        for(int w = 1; w <= W; w++)
        {
            if(weight[i - 1] <= w)
                dp[i][w] = max(value[i - 1] + dp[i - 1][w - weight[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    auto stop = high_resolution_clock::now();

    cout << "Maximum Profit = " << dp[n][W] << endl;

    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Runtime: " << duration.count() << " microseconds\n";

    return 0;
}