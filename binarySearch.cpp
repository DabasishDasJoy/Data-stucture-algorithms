#include<bits/stdc++.h>

using namespace std;

int binarySearch(vector<int>&nums, int key){
    int l = 0, r = nums.size() - 1;
    while(l <= r){
        int mid = l + ((r - l) / 2); // This eliminates the chance of type overflow
        
        if(nums[mid] == key)
            return mid;
        else if(key > nums[mid])
            l = mid + 1;
        else
            r = mid - 1;
    }

    return -1;
}

int main()
{
    vector<int>arr{10, 20, 30, 40, 50};

    int res = binarySearch(arr, 30);
    cout << res << endl;
    if(res != -1)
        cout << "Key found at position: " << res + 1<< endl;
    else
        cout << "Key not Found!"<< endl;
        
}