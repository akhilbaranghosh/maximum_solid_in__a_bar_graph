#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    stack<int> weight,index;
    weight.push(v[0]);
    index.push(0);
    int max=v[0];
    int end=0;
    for(int i=1;i<n;i++){
        if(weight.top()<v[i]){
            weight.push(v[i]);
            index.push(i);
        } else{
            int temp=i;
            while (!weight.empty()&&weight.top()>v[i]){
                int wt=weight.top()*(i - index.top());
                if(wt>max)max=wt;
                temp=index.top();
                weight.pop();
                index.pop();
            }
            weight.push(v[i]);
            index.push(temp);
        }
    }
    if(!weight.empty()){
        int temp=index.top();
        while (!weight.empty()){
            int wt=weight.top()*(temp + 1 - index.top());
            if(wt>max)max=wt;
            weight.pop();
            index.pop();
        }
    }
    cout << max;
}
//6, 2, 5, 4, 5, 1, 6
/*
7
6
2
5
4
5
1
6

 */