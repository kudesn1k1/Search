#include "Search.hpp"


using namespace std;

template <typename T, typename BinPred>//КРИТЕРИЙ СРАВНЕНИЯ
int BinarySearch(T target, T* a, int n, BinPred op = operator <) {
    if (!is_sorted(a, a + n)) { cout << "The massive is not sorted" << endl; return -1; };
    int begin = 0;
    int end = n;
    while (end > begin) {
        int i = (begin + end) / 2;
        if (op(a[i], target) == 1) begin = i + 1;
        else if (op(a[i], target) == -1) end = i - 1;
        else return i;
    }
    return -1;
}

int sravn(double x, double y) {
    if (x > y) return -1;
    else if (x < y) return 1;
    else return 0;
}

/////////////////////////////////////////    

template<typename T>
bool interpol_search(T* k, T key, int n)
{
    int high = n;
    int low = 0;
    while (high > low)
    {
        int i = (((key - k[low]) / (k[high] - k[low])) * (high - low)) + low;
        if (k[i] > key) high = i - 1;
        else if (k[i] < key) low = i + 1;
        else return true;
    }
    return false;
}

/////////////////


template <typename T>
struct Elem
{
    T el; int ind;
};

template <typename T>
bool IndexPosledSearch(T* arr, int n, int m, T key)
{
    if (key < arr[0] || key > arr[n - 1]) return false;
    int s = (n - 1) / m + 1;

    Elem<int>* arr_index = new Elem<int>[s];
    int i, j;
    for (j = 0; j < s; ++j)
    {
        int pindex = (j + 1) * m - 1;
        if (pindex > n - 1) pindex = n - 1;
        arr_index[j].ind = pindex;
        arr_index[j].el = arr[pindex];
    }
    for (j = 0; j < s; ++j)
        if (key <= arr_index[j].el) break;
    for (i = arr_index[j].ind - m + 1; i <= arr_index[j].ind; ++i)
        if (abs(arr[i] - key) < 0.0001)  return true;
    return false;
};