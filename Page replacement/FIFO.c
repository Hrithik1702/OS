#include <stdio.h>
#include <stdlib.h>
#include<time.h>
int main()
{
    int nf,n;
    printf("\nEnter the no. of frames: ");
    scanf("%d",&nf);
    int frames[nf];
    printf("\nEnter the no. of enteries: ");
    scanf("%d",&n);
    int ref[n];
    printf("\nThe randomly generated reference string: ");
    for(int i =0;i<n;i++)
    {
        scanf("%d",&ref[i]);
    }
    int old=0;
    for(int i =0;i<nf;i++)
    {
        frames[i]=-1;
    }
    int pagefault=0;
    int flag=0;
    int hit=0;
    int ind=0;
    for(int ind =0;ind<n;ind++)
    {
        flag=0;
        int page = ref[ind];
        for(int i=0;i<nf;i++)
        {
            if(frames[i]==page)
            {
                hit++;
                break;
            }
            else
            {
                flag++;
            }
        }
        if(flag==nf)
        {
            pagefault++;
            flag =0;
            for(int i=0;i<nf;i++)
            {
                if(frames[i]==-1)//free frames available
                {
                    frames[i]=page;
                    flag++;
                    break;
                }
            }
            if(flag==0)//no free frames
            {
               frames[old]=page;
               old=(old+1)%nf;
            }
        }
        printf("\nFrames after referring the page %d \n",page);
        for(int i =0;i<nf;i++)
        {
            printf("%d ",frames[i]);
        }
    }
    printf("\nNumber of page faults: %d",pagefault);
    printf("\nNumber of hits: %d",hit);
}

