#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace chrono;

int partition(vector<int>& arr, int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j < high; j++)
    {
        if(arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high)
{
    if(low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{  
    cout<<"Enter the number of elements:";
    int n;
    cin >> n;

    vector<int> arr(n);

    cout<<"Enter the elements:";
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    auto start = high_resolution_clock::now();

    quickSort(arr, 0, n - 1);

    auto stop = high_resolution_clock::now();

    cout << "Sorted Array:\n";

    for(int x : arr)
        cout << x << " ";

    auto duration = duration_cast<microseconds>(stop - start);

    cout << "\nRuntime: " << duration.count() << " microseconds\n";

    return 0;
}