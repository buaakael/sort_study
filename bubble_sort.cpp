#include <iostream>
#include <vector>

void print(std::vector<int> v)
{
    for (std::vector<int>::const_iterator it = v.begin(); it != v.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}
//简单冒泡排序
void BubbleSort0(std::vector<int> v)
{
    for (int i = 0; i < v.size() - 1; ++i)
    {
        for (int j = i + 1; j < v.size(); ++j)
        {
            if (v[i] > v[j])
            {
                int temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
        }
    }
    print(v);
}
//正宗冒泡排序
void BubbleSort(std::vector<int> v)
{
    for (int i = 0; i < v.size() - 1; ++i)
    {
        for (int j = v.size() - 2; j >= i; --j)
        {
            if (v[j] > v[j + 1])
            {
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
    print(v);
}
//改进冒泡排序
void BubbleSort2(std::vector<int> v)
{
    bool flag = true;
    for (int i = 0; i < v.size() - 1 && flag; ++i)
    {
        flag = false;
        for (int j = v.size() - 2; j >= i; --j)
        {
            if (v[j] > v[j + 1])
            {
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
                flag = true;
            }
        }
    }
    print(v);
}

int main()
{
    std::vector<int> v = {3, 8, 4, 6, 1, 5, 7, 9, 2};
    BubbleSort0(v);
    BubbleSort(v);
    BubbleSort2(v);
    print(v);
}
