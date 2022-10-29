
#include <iostream>
#include <vector>
#include <iterator>

void counting_sort(std::vector<int> &arr) {
    int max = arr[0];
    int min = arr[0];

    for(int i = 1; i < arr.size(); ++i) {
        if (max < arr[i]) {
            max = arr[i];
        }
        if (min > arr[i]) {
            min = arr[i];
        }
    }
    std::vector<int> bucket(max - min + 1);
    for (auto i : arr) {
        ++bucket[i - min];
    }
    arr.clear();
    for(int i = 0; i < bucket.size(); ++i) {
        int count = bucket[i];
        while (count > 0) {
            arr.push_back(i + min);
            --count;
        }
    }
}

int main(){
    std::vector<int> arr = {9,2,1,3,4,4,5,6,1,2,3,9,9,19,99,100,0};
    counting_sort(arr);
    std::copy (arr.begin(), arr.end(), std::ostream_iterator<int>(std::cout, " "));
}