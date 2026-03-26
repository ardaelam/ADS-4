#include <algorithm>

int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; ++i)
        for (int j = i + 1; j < len; ++j)
            if (arr[i] + arr[j] == value) ++count;
    return count;
}

int countPairs2(int *arr, int len, int value) {
    int count = 0;
    int left = 0, right = len - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == value) {
            if (arr[left] == arr[right]) {
                int n = right - left + 1;
                count += n * (n - 1) / 2;
                break;
            }
            int leftVal = arr[left], leftCnt = 0;
            while (left <= right && arr[left] == leftVal) { ++leftCnt; ++left; }
            int rightVal = arr[right], rightCnt = 0;
            while (right >= left && arr[right] == rightVal) { ++rightCnt; --right; }
            count += leftCnt * rightCnt;
        } else if (sum < value) {
            ++left;
        } else {
            --right;
        }
    }
    return count;
}

int countPairs3(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; ++i) {
        int target = value - arr[i];
        if (target < 0) continue;
        int left = i + 1, right = len - 1;
        int first = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] >= target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        first = left;
        if (first >= len || arr[first] != target) continue;
        left = i + 1, right = len - 1;
        int last = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        last = right;
        count += (last - first + 1);
    }
    return count;
}
