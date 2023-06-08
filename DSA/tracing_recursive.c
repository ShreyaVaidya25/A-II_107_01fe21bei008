#include<stdio.h>
#include<stdlib.h>

void Recursion(int n);
int main()
{
    int n;
    printf("Enter the value of n");
    printf("%d",n);
    scanf("%d",&n);
    Recursion(n-1);
}
void Recursion(int n)
{
 if(n>0)
 {
    int i;
    printf("%d",n);
    Recursion(n-1);
    Recursion(n-1);
 }
}
