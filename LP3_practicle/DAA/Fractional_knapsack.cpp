
#include <iostream>
#include <algorithm>
using namespace std;

struct Item
{
    int weight;
    int profit;
    float ratio;
};

bool compare(Item a, Item b)
{
    return a.ratio > b.ratio;
}

int main()
{
    int n, capacity;
    float totalProfit = 0;

    cout << "Enter number of items: ";
    cin >> n;

    Item item[100];

    cout << "Enter weight and profit of each item:\n";

    for (int i = 0; i < n; i++)
    {
        cin >> item[i].weight >> item[i].profit;

        item[i].ratio =
            (float)item[i].profit / item[i].weight;
    }

    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    sort(item, item + n, compare);

    for (int i = 0; i < n; i++)
    {
        if (capacity == 0)
            break;

        if (item[i].weight <= capacity)
        {
            totalProfit += item[i].profit;
            capacity -= item[i].weight;
        }
        else
        {
            totalProfit +=
                item[i].ratio * capacity;

            capacity = 0;
        }
    }

    cout << "\nMaximum Profit = " << totalProfit;

    return 0;
}
