#include <stdio.h>


void merge(int *a,int start,int mid, int end)
{

    char tmp[end-start+1];
    if(a == NULL || start < 0 || mid <=0 || end <= 0 )
        return;
    int i = start,j = mid+1,k = 0;
    while(i <= mid && j <= end)
    {
        if(a[i] <= a[j])
            tmp[k++] = a[i++];
        else
            tmp[k++] = a[j++];
    }
    while(i <= mid)
        tmp[k++] = a[i++];
    while(j <= end)
        tmp[k++] = a[j++];


    for(i = 0; i < k; i++)
    {
        a[start+i] = tmp[i];
    }

}

void merge_sort(int *a,int start,int end)
{
    if(a == NULL || start <0 || end <= 0 || start >= end )
        return;
    int mid = (start + end)/2;

    merge_sort(a,start,mid);
    merge_sort(a,mid+1,end);

    merge(a,start,mid,end);
}


int main(void)
{
    int i,n;
    int key;
    int a[20];
    printf("输入数组大小n:");
    scanf("%d",&n);

    printf("请输入%d个数:\n",n);
    for(i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    merge_sort(a,0,n-1);

    for(i = 0; i < n; i++)
    {
        printf("%d ",a[i]);
    }

    printf("\n");

    return 0;

}
