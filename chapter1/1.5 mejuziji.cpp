            #include<iostream>  
#include<math.h>  
using namespace std;  
  
  
int DecimalToBinary(int m, int *b) {    
    int k = 0;  
    while(m) {  
        b[k] = m % 2;  
        k++;  
        m = m / 2;  
    }  
    return k;  
}  
  
  
int countOne(int *b, int n) {  
    int cOne = 0;  
    for(int i = 0; i < n; i++)  
        if(b[i] == 1)  
            cOne++;  
    return cOne;  
}  
  
  
void printSet(int *a, int *b, int l, int k, int cOne) {  
    cout<<"{";  
    for(int v = k-1; v >= 0; v--) {  
        if(b[v] == 1) {  
            cout<<a[v];  
            --cOne;  
            if(cOne > 0) {  
                cout<<",";      
            }  
        }  
    }  
    cout<<"}"<<endl;  
}  
   
  
int main(int argc, char *argv[]) {  
      
    int n, l, r;  
    cin>>n;     
    if(n > 30) {   
        cout<<"out of bound"<<endl;  
        return 1;  
    }     
    int *a = new int[n];  
    int *b = new int[n];  
    for(int c = 0; c < n; c++)  
        cin>>a[c];  
    cin>>l>>r;  
    if(l > r || r > pow(2, n) || r - l > 1000) {   
        cout<<"input wrong number"<<endl;  
        return 1;  
    }   
    for(int s = 0; s < n; s++) {  
        for(int t = 0; t < n - s -1; t++) {  
            int temp = 0;  
            if(a[t] > a[t+1]) {  
                temp = a[t];  
                a[t] = a[t+1];  
                a[t+1] = temp;  
            }  
        }  
    }  
      
   int l1 = l - 1;  
   for(int i = l1; i < r;  i++) {  
        if(i == 0) {   
            cout<<"{}"<<endl;  
            continue;  
        }  
        int k = DecimalToBinary(i, b);  
        int cOne = countOne(b, n);  
        printSet(a, b, i, k, cOne);  
        for(int w = 0; w < n; w++)  
            b[w] = 0;  
   }  
      
    delete []b;  
    delete []a;  
    return 0;  
}  
  