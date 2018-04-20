#include <stdio.h>

int partionRevolve(int *a,int n,int key)
{
    int left = 0;
    int mid = -1;
    int right = n;
    while(left <= right)
    {
        mid = left + (left+right)/2;
        if(a[mid] == key)
            return mid;
        else if( key < a[mid])
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}

int partionRecursive(int *a,int start,int end,int key)
{
    if(a == NULL || start < 0 || end < 0)
        return -1;
    int ret = -1;
    if(start <= end)
    {
        int mid = start + (start+end)/2;
        if(a[mid] == key)
            return mid;
        else if(key < a[mid])
            return partionRecursive(a,start,mid-1,key);
        else
            return partionRecursive(a,mid+1,end,key);
    }
    return ret;
}


int main(void)
{
    int i,n;
    int key;
    int a[20];
    printf("输入数组大小n:");
    scanf("%d",&n);

    printf("请输入%d个递增数:\n",n);
    for(i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    printf("请输入要查找的值Key:");
    scanf("%d",&key);
    int pos = partionRecursive(a,0,n-1,key);
    printf("Recursive位于%d\n",pos);

    pos = partionRevolve(a,n-1,key);
    printf("Revolve位于%d\n",pos);
    return 0;
}
