#include <stdio.h>
/* end为数组最大值*/
void maxheap_down(int *a,int start,int end)
{//将当前节点start从上至下，使得start为最大结点
    int curr = start;
    int left = 2*curr+1;
    int i;
    for(;left <= end;curr = left,left = 2*left+1)
    {
        if(left+1 <= end && a[left] < a[left+1])
            left++;
        if(a[left] > a[curr])
        {
            int tmp = a[left];
            a[left] = a[curr];
            a[curr] = tmp;
        }
        else
            break;
    }
}

void swap(int &a,int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}
void heap_sort_asc(int *a,int n)
{//n是数组大小
    int i;
    //从i 从 (n-1-1)/2 ~ 0
    for(i = (n-2)/2; i>=0; i--)
    {
        maxheap_down(a,i,n-1);
    }

    swap(a[0],a[n-1]);

    for(i = n-2; i > 0; i--)
    {
        maxheap_down(a,0,i);
        swap(a[0],a[i]);
    }

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
    heap_sort_asc(a,n);

    for(i = 0; i < n; i++)
    {
        printf("%d ",a[i]);
    }

    printf("\n");

    return 0;

}
