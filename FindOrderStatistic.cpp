#include <cstdint>
#include <iostream>
#include <vector>

template <class Type>
void Swap(Type& one, Type& two) {
    Type st = one;
    one = two;
    two = st;
}

template <class Type>
size_t Partition(std::vector<Type>& arr, size_t left, size_t right) {
    Type support_elem = arr[left];
    size_t i_key = left + 1;
    size_t j_key = right;
    while (i_key <= j_key) {
        while (i_key < right and arr[i_key] < support_elem) {
            i_key += 1;
        }
        while (arr[j_key] > support_elem) {
            j_key -= 1;
        }
        if (i_key >= j_key) {
            break;
        }
        Swap(arr[i_key], arr[j_key]);
        i_key += 1;
        j_key -= 1;
    }
    Swap(arr[j_key], arr[left]);
    return j_key;
}

template <class Type>
Type FindOrderStatistic(std::vector<Type>& arr, size_t k_num) {
    size_t left = 0;
    size_t right = arr.size() - 1;
    while (left <= right) {
        size_t mid = Partition(arr, left, right);
        if (mid == k_num) {
            return arr[mid];
        }
        if (k_num < mid) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return Type(0);
}
