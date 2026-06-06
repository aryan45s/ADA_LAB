int partition(int a[], int low, int high)
{
    int pivot = a[low];
    int i = low + 1;
    int j = high;

    while(i < j)
    {
        while(i <= high && a[i] < pivot)
            i++;

        while(a[j] > pivot)
            j--;

        if(i < j)
            swap(&a[i], &a[j]);
    }

    swap(&a[low], &a[j]);

    return j;
}

void quicksort(int a[], int low, int high)
{
    if(low < high)
    {
        int j = partition(a, low, high);

        quicksort(a, low, j - 1);
        quicksort(a, j + 1, high);
    }
}