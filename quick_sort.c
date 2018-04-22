#include <stdio.h>


void quick_sort(int *a,int start,int end)
{

    if(a == NULL || start < 0 || end <= 0 || start >= end)
        return;
    int i = start,j = end;
    int k =  a[i];
    while(i < j)
    {
        while(i < j && a[j] > k)//从右往左找第一个小于k的值
            j--;
        if(i < j)
            a[i++] = a[j];
        while(i < j && a[i] < k) //从左往右找第一个大于k的值
            i++;
        if( i < j )
            a[j--] = a[i];
    }
    a[i] = k;

    quick_sort(a,start,i-1);
    quick_sort(a,i+1,end);

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
   quick_sort(a,0,n-1);

    for(i = 0; i < n; i++)
    {
        printf("%d ",a[i]);
    }

    printf("\n");

    return 0;

}
