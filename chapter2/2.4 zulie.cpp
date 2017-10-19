#include<iostream>

using namespace std;

bool isGood = true;

int isOnly(int a[], int x, int index, int n)
{
	for(int j=0;j<n;j++)
		if((j!=index)&&(a[j]==x))
			return 0;
	return 1;
}

int findOnly(int a[], int l, int r)
{	//find a number only appears once and retuens its index, else return -1
	for(int i=l;i<=r;i++)
		if(isOnly(a, a[i], i, r-l+1)==1)
			return i;
	return -1;
	
}

void depart(int a[], int l, int r)
{	//we use the theory of divide-and-conquer
	if(!isGood)
		return;
	if(l>=r)
		return;
	if(r-l==1)
	{	if(a[r]==a[l])
			isGood=false;  
		return;
	}
	int index=findOnly(a,l,r);
	if(index==-1)
	{
		isGood=false;
		return;
	}
	if(index==l)
		depart(a, index+1, r);
	if(index==r)
		depart(a, l, index-1);
	else
	{
		depart(a, l, index-1);
		depart(a, index+1, r);
	}
}


int main(int argc, char* argv[]) 
{
	int t, n;
	cin>>t;
	int t1=t;
	int *c = new int[t1]; //record state('1' means 'Good', '0' means 'Bad')of import array

	while(t--){
        cin>>n;
		int *a = new int[n];
        for(int loop = 0; loop < n; loop++)
             cin>>a[loop];

		depart(a,0,n-1);
        if(isGood)
        {   
 			c[t]=1;
		}
        else
        {  
			c[t]=0;
		}

		isGood = true; //reset for next array's judgement
		delete []a;
		a=NULL;
    }

	for(int i = t1-1; i>=0; i--)  
   	{	//while we store the state from top to buttom, so we must have a same sequence when printing it
   		if(c[i]==1)
   			cout<<"Good"<<endl;
		else
 			cout<<"Bad"<<endl;
   	}
	delete []c;
    c=NULL;

	return 0;
}
