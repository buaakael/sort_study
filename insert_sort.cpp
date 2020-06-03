#include <iostream>
#include <vector>

void print(std::vector<int> v)
{
    for (std::vector<int>::const_iterator it = v.begin(); it != v.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

void InsertSort(std::vector<int> v)
{
    for (int i = 1; i < v.size(); ++i)
    {
        if (v[i] < v[i - 1])
        {
            int temp = v[i];
            int j;
            for (j = i - 1; j >= 0 && v[j] > temp; --j)
            {
                v[j + 1] = v[j];
            }
            v[j + 1] = temp;
        }
    }
    print(v);
}

int main()
{
    std::vector<int> v = {3, 8, 4, 6, 1, 5, 7, 9, 2};
    InsertSort(v);
    print(v);
}
