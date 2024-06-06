// Heapsort
 
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define TRUE 1
#define FALSE 0

void heapbottomup(int h[],int n) {
   	int i, heap, v, j, k;
   	for(i = n/2; i > 0; i--){
		k = i;
		v = h[k];
		heap = FALSE;
		while( !heap && (2*k) <= n){
			j = 2 * k;
			if( j < n )
   	  		    if( h[j] < h[j+1] )
			        j = j+1;
      		if( v >= h[j])
			    heap = TRUE;
			else {
				h[k] = h[j];
				k = j;
			}
	    }
        h[k] = v;
    }
}

void heapsort(int h[],int n){    
	int i,temp,last=n;
	if(n<=1)
        return;
    else{
        heapbottomup(h,n);
        temp = h[last];
        h[last] = h[1];
        h[1]=temp;
        last--;
        heapsort(h,n-1);
	}
}
int main(){
    int h[20],n,i;
	double clk;
    clock_t starttime,endtime;
	printf("\nEnter the number of resumes\n");
	scanf("%d",&n);
	srand(time(0));
	for(i=1;i<=n;i++) {
        h[i]=rand()%100;
        printf("\nThe candidates ranks are: \t%d",h[i]);
    }
    starttime=clock();
	heapsort(h,n);
    endtime=clock();
    clk=(double)(endtime-starttime)/CLOCKS_PER_SEC;
	printf("\nThe ranks in sorted order:\t");
	for(i=1;i<=n;i++)
	    printf("%d\t",h[i]);
    printf("\nThe run time is %f\n",clk);
 
    return 0;
}