 #include<set>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
 
long long n , num , k , ans;
long long minNum , maxNum;
multiset<long long>s;
 
int main(){
    while(scanf("%lld" , &n) && n){
        ans = 0;
        s.clear();
        for(int i = 0 ; i < n ; i++){
            scanf("%lld" , &k); 
            for(int j = 0 ; j < k ; j++){
                scanf("%lld" , &num);     
                s.insert(num);
            }
            if(s.size() > 0){
                multiset<long long>::iterator it;
                it = s.begin();
                minNum = *it;          
                it = s.end();
                it--; 
                maxNum = *it; 
                s.erase(it);
                if(s.size() > 0){ 
                    it = s.begin(); 
                    s.erase(it); 
                } 
                ans += maxNum - minNum; 
            } 
        } 
        printf("%lld\n" , ans);
        break; 
    } 
    return 0;
}
 