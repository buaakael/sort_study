#include <iostream>
#include <vector>

void print(std::vector<int> v)
{
    for (std::vector<int>::const_iterator it = v.begin(); it != v.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

void SelectSort(std::vector<int> v)
{
    int min;
    for (int i = 0; i < v.size() - 1; ++i)
    {
        min = i;
        for (int j = i + 1; j < v.size(); ++j)
        {
            if (v[min] > v[j])
                min = j;
        }
        if (i != min)
        {
            int temp = v[i];
            v[i] = v[min];
            v[min] = temp;
        }
    }
    print(v);
}

int main()
{
    std::vector<int> v = {3, 8, 4, 6, 1, 5, 7, 9, 2};
    SelectSort(v);
    print(v);
}
