#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace chrono;

int binarySearch(vector<int>& arr, int key)
{
    int low = 0, high = arr.size() - 1;

    while(low <= high)
    {
        int mid = (low + high) / 2;

        if(arr[mid] == key)
            return mid;

        else if(arr[mid] < key)
            low = mid + 1;

        else
            high = mid - 1;
    }

    return -1;
}

int main()
{
    int n;
    cout<<"Enter the number of elements:";
    cin >> n;

    vector<int> arr(n);
    cout<<"Enter the elements:";
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int key;
    cout<<"Enter the key:";
    cin >> key;

    auto start = high_resolution_clock::now();

    int result = binarySearch(arr, key);

    auto stop = high_resolution_clock::now();

    if(result == -1)
        cout << "Element Not Found\n";
    else
        cout << "Element Found at Index " << result << endl;

    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Runtime: " << duration.count() << " microseconds\n";

    return 0;
}