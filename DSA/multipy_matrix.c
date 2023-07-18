
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a[100][100],b[100][100],r1,c1,r2,c2,i,j;
    int m[100][100],k;
    printf("Enter the number of rows & columns of first:");
    scanf("%d %d",&r1,&c1);
     printf("Enter the elements of first:\n");
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c1;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("Enter the number of rows & columns of second:");
    scanf("%d %d",&r2,&c2);
    printf("For second matrix:\n");
    for(i=0;i<r2;i++)
    {
        for(j=0;j<c2;j++)
        {
            scanf("%d",&b[i][j]);
        }
    }
    printf("The elements of 1st matrix:\n");
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c1;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    printf("The elements of 2nd matrix:\n");
     for(i=0;i<r2;i++)
    {
        for(j=0;j<c2;j++)
        {
            printf("%d ",b[i][j]);
        }
        printf("\n");
    }

    for(i=0;i<r1;i++)
    {
        for(j=0;j<c2;j++)
        {
            m[i][j]=0;
            for(k=0;k<r2;k++)
            {
              m[i][j]=m[i][j]+a[i][k]*b[k][j];
            }
        }
    }

printf("\n Product of matrix:\n");
for(i=0;i<r1;i++)
{
    for(j=0;j<c2;j++)
    {
        printf("%d ",m[i][j]);
    }
    printf("\n");
}
}
