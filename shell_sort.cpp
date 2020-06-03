#include <iostream>
#include <vector>

void print(std::vector<int> v)
{
    for (std::vector<int>::const_iterator it = v.begin(); it != v.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

void ShellSort(std::vector<int> v)
{
    int increment = v.size();//初始化增量值
    do
    {
        increment = increment / 3 + 1;//增量的选取是个技术活
        for (int i = increment + 1; i < v.size(); ++i)
        {
            if (v[i] < v[i - increment])
            {
                int temp = v[i];
                int j;
                for (j = i - increment; j >= 0 && temp < v[j]; j -= increment)
                {
                    v[j + increment] = v[j];
                }
                v[j + increment] = temp;
            }
        }
    }
    while (increment > 1);
    print(v);
}

int main()
{
    std::vector<int> v = {3, 8, 4, 6, 1, 5, 7, 9, 2};
    ShellSort(v);
    print(v);
}
