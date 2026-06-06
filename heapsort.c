#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

void heapify(int a[],int n,int i)
{
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;

    if(left<n && a[left]>a[largest])
        largest=left;

    if(right<n && a[right]>a[largest])
        largest=right;

    if(largest!=i)
    {
        swap(&a[i],&a[largest]);
        heapify(a,n,largest);
    }
}

void heapSort(int a[],int n)
{
    // Build Max Heap
    for(int i=n/2-1;i>=0;i--)
        heapify(a,n,i);

    // Extract elements
    for(int i=n-1;i>0;i--)
    {
        swap(&a[0],&a[i]);
        heapify(a,i,0);
    }
}

int main()
{
    int n;

    printf("Enter n: ");
    scanf("%d",&n);

    int a[n];

    for(int i=0;i<n;i++)
        a[i]=rand()%10000;

    clock_t start,end;

    start=clock();

    heapSort(a,n);

    end=clock();

    printf("\nSorted Array:\n");

    for(int i=0;i<n;i++)
        printf("%d ",a[i]);

    double time_taken=(double)(end-start)/CLOCKS_PER_SEC;

    printf("\n\nTime Taken = %f seconds\n",time_taken);

    return 0;
}