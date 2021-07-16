#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>


void *add(double* arr)
{
    arr[2]= arr[0]+arr[1];
    printf("\nAddition:");
    printf("%lf + %lf = %lf",arr[0],arr[1],arr[2]);
    arr[0]=arr[2];
}

void *sub(double* arr)
{
    arr[2]= arr[0]-arr[1];
    printf("\nSubtraction:");
    printf("%lf - %lf = %lf",arr[0],arr[1],arr[2]);
    arr[0]=arr[2];
}

void *mul(double* arr)
{
    arr[2]= arr[0]*arr[1];
    printf("\nMultiplication:");
    printf("%lf * %lf = %lf",arr[0],arr[1],arr[2]);
    arr[0]=arr[2];
}

void *divison(double* arr)
{
    arr[2]= arr[0]/arr[1];
    printf("\nDivision:");
    printf("%lf / %lf = %lf",arr[0],arr[1],arr[2]);
    arr[0]=arr[2];
}

int main()
{
    double a[3];
    int ch;
    pthread_t tid_add;
    pthread_t tid_sub;
    pthread_t tid_mul;
    pthread_t tid_div;
    printf("Opertaion choice:");
    printf("\n1.Addition ");
    printf("\n2.Subtraction ");
    printf("\n3.Multiplication");
    printf("\n4.Division:");
    printf("\nEnter a number: ");
    scanf("%lf",&a[0]);

    do{
        printf("\n\nEnter the operation to be performed or -1 to exit: ");
        scanf("%d",&ch);

        if(ch ==1)
        {
            printf("\nEnter a number: ");
            scanf("%lf",&a[1]);
            pthread_create(&tid_add,NULL,add,a);
            pthread_join(tid_add,NULL);
        }
        else if(ch ==2)
        {
            printf("\nEnter a number: ");
            scanf("%lf",&a[1]);
            pthread_create(&tid_sub,NULL,sub,a);
            pthread_join(tid_sub,NULL);
        }
        else if(ch ==3)
        {
            printf("\nEnter a number: ");
            scanf("%lf",&a[1]);
            pthread_create(&tid_mul,NULL,mul,a);
           pthread_join(tid_mul,NULL);
        }
        else if(ch ==4)
        {
            printf("\nEnter a number: ");
            scanf("%lf",&a[1]);
            pthread_create(&tid_div,NULL,divison,a);
            pthread_join(tid_div,NULL);
        }
        else if(ch!=-1)
        {
            printf("\nInvalid choice");
        }

    }while(ch!=-1);
printf("\nFinal value:%lf",a[0]);
}
