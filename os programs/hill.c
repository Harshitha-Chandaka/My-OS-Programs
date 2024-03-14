#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int i,j,a[100][100],pt[100],ct[100],t=0,n,m,msg[100];
    printf("Enter the no. of rows and cols: ");
    scanf("%d %d",&n,&m);
    printf("Enter the plaintext: ");
    scanf("%s", msg);
    
    for(i=0;i<strlen(msg);i++)
    {
        pt[i]= msg[i]-65;
        printf("%d",pt[i]);
    }
}
    
