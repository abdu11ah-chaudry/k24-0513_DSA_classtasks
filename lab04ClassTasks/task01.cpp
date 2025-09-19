#include <iostream>
using namespace std;
int main(){
    int x[]={64,34,25,12,22,11,90};
    int n=7,c=0;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            c++;
            if(x[j]>x[j+1]){
                int t=x[j];
                x[j]=x[j+1];
                x[j+1]=t;
            }
        }
    }
    for(int i=0;i<n;i++) cout<<x[i]<<" ";
    cout<<"\nTotal number of comparisions performed: "<<c;
}
