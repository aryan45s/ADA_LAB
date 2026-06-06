#include<stdio.h>

struct Item
{
    int weight;
    int profit;
    float ratio;
};

void sort(struct Item item[], int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(item[j].ratio < item[j+1].ratio)
            {
                struct Item temp = item[j];
                item[j] = item[j+1];
                item[j+1] = temp;
            }
        }
    }
}

int main()
{
    int n;
    float capacity;

    printf("Enter number of items: ");
    scanf("%d",&n);

    struct Item item[n];

    for(int i=0;i<n;i++)
    {
        printf("Weight Profit: ");
        scanf("%d%d",
              &item[i].weight,
              &item[i].profit);

        item[i].ratio =
        (float)item[i].profit /
        item[i].weight;
    }

    printf("Enter capacity: ");
    scanf("%f",&capacity);

    sort(item,n);

    float totalProfit = 0;

    for(int i=0;i<n;i++)
    {
        if(item[i].weight <= capacity)
        {
            totalProfit += item[i].profit;
            capacity -= item[i].weight;
        }
        else
        {
            totalProfit +=
            item[i].profit *
            (capacity/item[i].weight);

            break;
        }
    }

    printf("Maximum Profit = %.2f",
           totalProfit);

    return 0;
}