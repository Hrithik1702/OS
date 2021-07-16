#include <stdio.h>
#include <stdlib.h>
int main()
{
    printf("Enter No. of Disk Access Requests: ");
    int n,head;
    scanf("%d",&n);
    int disk[n+2];
    printf("Enter Disk Starting track number: ");
    scanf("%d",&disk[0]);
    printf("Enter Disk Ending track number: ");
    scanf("%d",&disk[n+1]);
    printf("Enter Starting head position: ");
    scanf("%d",&head);
    printf("Disk Access Request Sequence: ");
    for(int i=1;i<n+1;i++)
    {
        disk[i] = rand()%200;
        printf("%d ",disk[i]);
    }
    for(int i=0;i<n+2;i++)
    {
        for(int j=0;j<n+1-i;j++)
        {
            if (disk[j]>disk[j+1])
            {
                int temp = disk[j];
                disk[j]=disk[j+1];
                disk[j+1]=temp;
            }
        }
    }

    int ser[n+2];
    int thm=0,ind;
    for(int i=0;i<n+2;i++)
    {
        if(disk[i]>=head)
        {
            ser[0]=head;
            ind=i;
            break;
        }
    }
    int serind=1;
    int count =0;
    for(int i=ind;count<n+2;i=(i+1)%(n+2))
    {
        ser[serind]=disk[i];
        if(ser[serind-1]-ser[serind]<0)
        {
            thm+= ser[serind]-ser[serind-1];
        }
        else
        {
            thm+= ser[serind-1]-ser[serind];
        }
        serind++;
        count++;
    }

    printf("\nService sequence according to SCAN algorithm:\n");
    for(int i=0;i<=n+2;i++)
    {
        printf("%d ",ser[i]);
    }
    printf("\nTotal Head Movements:%d Cylinders",thm);
    return 0;
}
