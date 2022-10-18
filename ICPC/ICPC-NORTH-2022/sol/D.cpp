#include<iostream>
using namespace std;
int a[13];
int main(){
    int n;
    a[0]=1;
    int b[100000],c=0;
    cin>>n;
    for(int i=1;i<=9;i++){
        a[i]=a[i-1]*i;
    }
    int t=9;
    if(n==1){
        cout<<0;
        return 0;
    }
    while(n>=0){
        if(n==0)break;
        if(n-a[t]<0){
            t--;
        }else{
            n-=a[t];
            b[c]=t;
            c++;
        }
    }
    for(int i=c-1;i>=0;i--){
        cout<<b[i];
    }
}
