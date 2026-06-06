// #include<stdio.h>
// void printper(int perm[],int n){
//     for(int i=0;i<n;i++){
//         printf("%d ",perm[i]);
//     }
//     printf("\n");
//     return;
// }
// int getmob(int perm[],int dir[],int n){
//     int mobile=0;
//     int mobile_index=-1;
     
//     for(int i=0;i<n;i++){
//         // moving towards left
//         if(i!=0 && dir[i]==-1){
//             if(perm[i]>perm[i-1] && mobile<perm[i]){
//                 mobile=perm[i];
//                 mobile_index=i;
//             }
//         }
//         if(i!=n-1 && dir[i]==1){
//             if(perm[i]>perm[i+1] && mobile<perm[i]){
//                 mobile=perm[i];
//                 mobile_index=i;
//             }
//         }
//     }
//     return mobile_index;

// }
// void john(int n){
//     int perm[n];
//     int dir[n];
//     //intialize the perm and dir
//    for(int i=0;i<n;i++){
//     perm[i]=i+1;
//     dir[i]=-1;
//    }
//    printper(perm,n);
//    while(1){
//     int mobile_ind=getmob(perm,dir,n);
//     if(mobile_ind==-1){
//         return;
//     }
//     // swap
//     int swap=mobile_ind+dir[mobile_ind];
//     int temp=perm[mobile_ind];
//     perm[mobile_ind]=perm[swap];
//     perm[swap]=temp;
//     // swap the directions also
//     temp=dir[mobile_ind];
//     dir[mobile_ind]=dir[swap];
//     dir[swap]=temp;
//     // swap the direction the elements greater then the mobile element
//     int mobile_element=perm[swap];
//     for(int i=0;i<n;i++){
//         if(perm[i]>mobile_element){
//             dir[i]=-dir[i];
//         }
//     }
    
//     printper(perm,n);
//    }
// }
// int main(){
//     john(4);
// }
// #include<stdio.h>
// void swap(int *a, int *b) {
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }
// int partition(int a[],int low,int high){
//     int pivot=a[low];
//     int i=low+1;
//     int j=high;
//     while(i<j){
//         while(a[i]<pivot && i<=high){
//             i++;

//         }
//         while(a[j]>pivot){
//             j--;
//         }
//         swap(&a[i],&a[j]);

//     }
//     swap(&pivot,&a[j]);
//     return j;

// }
// void quicksort(int a[],int low,int high){
//     if(low<high){
//        int j= partition(a,low,high);
//       quicksort(a,low,j);
//       quicksort(a,j+1,high);
//     }
// }

// #include<stdio.h>
// void swap(int *a, int *b) {
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }
// void heapify(int a[],int n,int i){
//  int root=i;
//  int left=2*i+1;
//  int right=2*i+2;
// if(left<n && a[left]>a[root]){
//     root=left;
// }
// if(right<n && a[right]>a[root]){
//     root=right;
// }
// if(root!=i){
//     swap(&a[i],&a[root]);
//     heapify(a,n,root);
// }
// }
// void heapsort(int a[],int n){
//     for(int i=(n-1)/2;i>=0;i--){
//         heapify(a,n,i);
//     }
//     // actual sorting takes place here
//     for(int i=n-1;i>=0;i--){
//         swap(&a[0],&a[i]);
//         heapify(a,i,0);
//     }
// }

// #include <stdio.h>

// int max(int a, int b)
// {
//     return (a > b) ? a : b;
// }
// int main(){
//     int n;
//     int W=5;
//     int val[n];int wt[n];

//     printf("enter the number of elements");
//     scanf("%d",&n);
//     printf("enter the profits");
//     for(int i=0;i<n;i++){
//         scanf("%d",&val[i]);
//     }
//     printf("enter the weights of the object ");
//     for(int i=0;i<n;i++){
//         scanf("%d",&wt[i]);
//     }
//     int dp[n+1][W+1];
//     for(int i=0;i<=n;i++){
//         for(int w=0;w<=n;w++){
//             if(i==0 || w==0){
//               dp[i][w]=0;
//             }
//             if(wt[i-1]<=w){
//                 dp[i][w]=max(dp[i-1][w],val[i-1]+dp[i-1][w-wt[i-1]]);
//             }
//             else{
//                 dp[i][w]=dp[i-1][w];
//             }

//         }
//     }
// }
#include<stdio.h>
#define max 10

int graph[max][max];
int indegree[max]={0};
int queue[max],front=0,rare=-1;

void topological(int n,int graph[n][n]){
   

    for(int i=0;i<n;i++){
        if(indegree[i]==0){
            queue[++rare]=i;
        }
    }
    
    printf("TOPOLOGICAL SORTING :\n");

    while(front<=rare){
        int u=queue[front++];
        printf("%d ",u);

        for(int i=0;i<n;i++){
            if(graph[u][i]==1){
                indegree[i]--;

                if(indegree[i]==0){
                    queue[++rare]=i;
                }
            }

        }
    }
}

int main()
{
    int n;
    printf("\nEnter number of vertex: ");
    scanf("%d",&n);

    printf("Enter adj matrix for graph : \n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&graph[i][j]);
            if(graph[i][j]==1){
                indegree[j]++;
            }
        }
    }

    topological(n,graph);

}