#include <stdio.h>


void select_sort(int *a,int n)
{
    if(a == NULL || n <=0 )
        return;
    int i,j;
    int min;
    //选择排序
    //每次找到一个最小值
    for(i = 0;i < n; i++)
    {
        min = i;
        for(j = i+1; j < n; j++)
        {
            if(a[j] < a[min])
            {
                min = j;
            }

        }
        if(i != min)
        {
            int tmp = a[i];
            a[i] = a[min];
            a[min] = tmp;
        }
    }
}
int main(void)
{
    int i,n;
    int a[20];
    printf("输入数组大小n:");
    scanf("%d",&n);

    printf("请输入%d个数:\n",n);
    for(i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    select_sort(a,n);

    for(i = 0; i < n; i++)
    {
        printf("%d ",a[i]);
    }

    printf("\n");

    return 0;

}
