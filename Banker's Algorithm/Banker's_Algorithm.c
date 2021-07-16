#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n,resources;
    printf("\nEnter the no. of processes: ");
    scanf("%d",&n);
    printf("\nEnter the no. of resources: ");
    scanf("%d",&resources);
    int instance[resources];
    int avail[resources];
    for(int i=0;i<resources;i++)
    {
        printf("\nEnter the no of instances in resource  %d: ",i+1);
        scanf("%d",&instance[i]);
    }
    int max[n][resources];
    int allocated[n][resources];
    int need[n][resources];
    printf("max matrix\n");
    for(int i =0;i<n;i++)
    {
        for(int j =0;j<resources;j++)
        {
            scanf("%d",&max[i][j]);
        }
    }
    printf("allocated matrix\n");
    for(int i =0;i<n;i++)
    {
        for(int j =0;j<resources;j++)
        {

            scanf("%d",&allocated[i][j]);
            need[i][j]= max[i][j]-allocated[i][j];
        }
    }
    int sum=0;
    for(int i =0;i<resources;i++)
    {
        sum=0;
        for(int j =0;j<n;j++)
        {
            sum += allocated[j][i];
        }
        avail[i]=instance[i]-sum;
    }
    printf("\n");
    int count=0;
    int finished[n];
    for(int i=0;i<n;i++)
    {
        finished[i]=0;
    }
    int deadlock_flag=0;
    int rem=n;
    int seq[n];
    for(int i=0;count<n && deadlock_flag!=rem;)
    {
        printf("available resources :");
        for(int i =0;i<resources;i++)
        {
            printf("%d ",avail[i]);
        }
        int flag =0;
        if(finished[i]==0)
        {
            for(int j =0;j<resources;j++)
            {
                if(need[i][j]<=avail[j])
                {
                    flag++;
                }
            }
            if(flag==resources)
            {
                printf("For process %d need < available",i);
                for(int j =0;j<resources;j++)
                {
                    avail[j]+=allocated[i][j];
                }
                finished[i]=1;
                seq[count++]=i;
                rem--;
                deadlock_flag=0;
            }
            else
            {
                printf("For process %d need > available",i);
               deadlock_flag++;
            }
        }
        i=(i+1)%n;

    }
    if(deadlock_flag==rem && deadlock_flag!=0)
    {
        printf("\nDeadlock");
    }
    else
    {
        printf("\nSafeSequence: ");
        for(int i=0;i<n;i++)
        {
            printf("p%d  --->",seq[i]);
        }
    }
}

