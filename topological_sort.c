#include<stdio.h>
#include<stdlib.h>
#define max 20
int main(){
    int rear=0;
    int front=0;
    int adj[max][max];
    int queue[max];
    int indegree[max];
    int n;int top[max];int k=0;
    printf("enter the number of vertices");
    scanf("%d",&n);
     printf("enter the adjacency matrix");
     for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&adj[i][j]);
        }
     }
     for(int k=0;k<n;k++){ // indegree=0;
        indegree[k]=0;
     }
     for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(adj[i][j]==1){
                indegree[j]+=1;
            }
        }
     }
     for(int i=0;i<n;i++){
        if(indegree[i]==0){
            queue[rear++]=i;
        }
     }

     while(front<rear){
        int v=queue[front++];
        top[k++]=v;
        for(int i=0;i<n;i++){
            if(adj[v][i]==1){
                indegree[i]-=1;
                if(indegree[i]==0){
                    queue[rear++]=i;
                }

            }
            
        }
       
     }

}