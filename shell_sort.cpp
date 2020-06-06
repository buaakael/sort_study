#include <iostream>
#include <vector>
//因为堆排序下标为0时会有bug，循环结束不了，所以此处将vector数组第一位定义为0了
void print(std::vector<int> v)
{
    for (std::vector<int>::const_iterator it = v.begin(); it != v.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

void HeapAdjust(std::vector<int> &v, int s, int m)
{
    int temp;
    temp = v[s];
    for (int i = 2 * s; i <= m; i *= 2)
    {
        if (i < m && v[i] < v[i + 1])
            ++i;
        if (temp >= v[i])
            break;
        v[s] = v[i];
        s = i;
    }
    v[s] = temp;
}

void ShellSort(std::vector<int> v)
{
    for (int i = (v.size() - 1) / 2; i > 0; --i)
    {
        HeapAdjust(v, i, v.size());
    }

    for (int i = v.size() - 1; i > 1; --i)
    {
        int temp = v[i];
        v[i] = v[1];
        v[1] = temp;
        HeapAdjust(v, 1, i - 1);
    }
    print(v);
}


int main()
{
    std::vector<int> v = {0, 3, 8, 4, 6, 1, 5, 7, 9, 2};
    ShellSort(v);
    print(v);
}
