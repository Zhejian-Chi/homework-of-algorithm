
#include <stdio.h>

int sumB=0;

/*
int findMin(int a[], int l, int r)
{
	int min=a[l];
	int s=l;
	for(int index=l+1; index<=r; index++)
	{	if(min>a[index])
		{	
			min=a[index];
			s=index;
		}
		else
			continue;
	}
	return s;
}
*/


/*
int calCost(int a[], int b[], int n)
{
	int index;
	int *cost=new int[n];
	cost[0]=a[0]+b[1];
	cost[n-1]=a[n-1]+b[n-2];
	for(int k=1;k<n-1;k++)
		cost[k]=a[k]+b[k-1]+b[k+1];
	index=findMin(cost, 0, n-1);
	sumB += cost[index];
	delete []cost;
	cost=NULL;
	return index;
}

void moveElem(int a[], int b[], int index, int n)
{
	for(int m=index;m<n-1;m++)
	{
		a[m]=a[m+1];
		b[m]=b[m+1];
	}
}
*/


int findMin(int a[], int b[], int l, int r)
{
	int min=a[l];
	int s=0;
	int sIndex[200];
	int minIndex;
	for(int index=l+1; index<=r; index++)
	{	
		if(min>a[index])
		{	
			min=a[index];
			sIndex[s]=index;
			s++;
		}
		else
			continue;
	}
	if(s==0)
		return l;
	if(s==1)
	{
		return sIndex[0];
	}
	else
	{
		min=b[sIndex[0]];
		//minIndex=sIndex[0];
		for(int lo=0;lo<s;lo++)
		{
			if(min>b[sIndex[lo]])
				min=b[sIndex[lo]];
			minIndex=sIndex[lo];
		}
		return minIndex;
	}
}



int calCost(int b[], int n)
{
	int index;
	int *c = new int[n];
	c[0]=b[1]-b[0];
	c[n-1]=b[n-2]-b[n-1];
	for(int loop=1;loop<n-1;loop++)
		c[loop]=b[loop-1]+b[loop+1]-b[loop];
	index=findMin(c, b, 0, n-1);
	if(index==0)
		sumB += b[1];
	else if(index==n-1)
		sumB += b[n-2];
	else
		sumB += (b[index-1]+b[index+1]);
	
	delete []c;
	c=NULL;
	return index;
}

void moveElem(int b[], int index, int n)
{
	for(int m=index;m<n-1;m++)
	{
		b[m]=b[m+1];
	}

}

int main(int argc, char *argv[])
{
	int n, costA=0;
	
	scanf("%d",&n);
	int *a=new int[n];
	int *b=new int[n];
	
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(int j=0;j<n;j++)
		scanf("%d",&b[j]);
	for(int i1=0;i1<n;i1++)
		costA += a[i1];
	
	//cout<<costA<<endl;
	//cout<<findMin(b,0,n-1);
	
	
	for(int loop=n; loop>1; loop--)
	{
		int index=calCost(b, loop);
		moveElem(b,index,loop);
	}

	
	printf("%d\n",sumB+costA);
		
	/*	
	cost[0]=b[1];
	cost[n-1]=b[n-2];
	for(int k=1;k<n-1;k++)
		cost[k]=b[k-1]+b[k+1];
	*/
	
	/*
	cout<<costA<<endl;
	for(int lo=0;lo<n;lo++)
		cout<<cost[lo]<<" ";
	*/
	
	delete []b;
	b=NULL;
	delete []a;
	a=NULL;
	return 0;
}