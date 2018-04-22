#include <stdio.h>


void shell_sort(int *a,int n)
{
    if(a == NULL || n<= 0 )
        return;

    int i,j;
    //步长每次减半
    int gap,k;
    for(gap = n/2; gap > 0; gap =gap/ 2)
    {
        for(k = 0; k < gap; k++)
        //将从0-(gap-1)的元素轮一遍
            for(i = k + gap; i < n; i = i+gap)
            {//直接插入排序，加入步长gap
                for(j = i - gap; j >= 0; j -= gap)
                {
                    if(a[j] > a[j+gap])
                    {
                        int tmp = a[j];
                        a[j] = a[j+gap];
                        a[j+gap] = tmp;
                    }
                    else
                        break;
                }
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
    shell_sort(a,n);

    for(i = 0; i < n; i++)
    {
        printf("%d ",a[i]);
    }

    printf("\n");

    return 0;

}
