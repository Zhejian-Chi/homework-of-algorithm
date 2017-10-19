#include <iostream>  
#include <queue>  
  
using namespace std;  
  
int minimum(int n, int k, long a[]) {  
    priority_queue< int, vector<int>, greater<int> > p_Queue;  
        if((n - 1) % (k - 1) == 0) {          
            for(int i = 0; i < n; i++)  
                p_Queue.push(a[i]);  
            int sum = 0, min = 0;  
            while(p_Queue.size() > k) {  
                sum = 0;  
                for(int i = 0; i < k; i++) {  
                    sum += p_Queue.top();  
                    p_Queue.pop();  
                }  
                p_Queue.push(sum);  
                min += sum;  
            }     
            if(p_Queue.size() == k) {  
                for(int i = 0; i < k; i++) {  
                    min += p_Queue.top();  
                    p_Queue.pop();  
                }  
            }  
            return min;  
    } else {  
            int addZero = k - (n-1) % (k-1) - 1;  
            for(int i=0; i<n; i++)  
                    p_Queue.push(a[i]);  
            for(int c=0; c<addZero; c++)     
                p_Queue.push(0);  
            int sum = 0, min = 0;  
            while(p_Queue.size() > k) {  
                sum = 0;  
                for(int i = 0; i < k; i++) {  
                    sum += p_Queue.top();  
                    p_Queue.pop();  
                }  
                p_Queue.push(sum);  
                min += sum;  
            }     
            if(p_Queue.size() == k) {  
                for(int i=0; i<k; i++) {  
                    min += p_Queue.top();  
                    p_Queue.pop();  
                }  
            }  
            return min;  
    }  
}  
  
int main(int argc, char *argv[]) {  
    long n, k, a[100000];  
    cin>>n>>k;  
    for(int i = 0; i < n; i++) {  
        cin>>a[i];  
    }  
    cout<<minimum(n, k, a)<<endl;  
    return 0;  
}  