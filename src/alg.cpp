// Copyright 2021 NNTU-CS
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
        int* first = std::lower_bound(arr + i + 1, arr + len, target);
        int* last  = std::upper_bound(arr + i + 1, arr + len, target);
        count += (last - first);
    }
    return count;
}
