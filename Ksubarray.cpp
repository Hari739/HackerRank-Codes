#include<stdio.h>

#define ll  unsigned long long
#define MOD 1000000007
ll min (ll x, ll y) {return x < y? x : y; }
 

ll Max (ll x, ll y) {return x > y? x : y; }


int main(){
	
	int t;
	scanf("%d",&t);
	while(t--){
		
		ll i,n,k;
		scanf("%llu%llu",&n,&k);
		ll a[n];
		for(i=0;i<n;i++){
			scanf("%llu",&a[i]);
		}
		ll pos_max=1;
		ll neg_min =1;
		ll max=1;
		
		for (i=0;i<n;i++){
			
			if(a[i]>0){
				
				pos_max = ((pos_max%MOD)*(a[i]%MOD))%MOD;
				neg_min = min (neg_min*a[i],1);
			}
			else{
				ll temp = pos_max;
				pos_max = Max ((neg_min*a[i])%MOD,1);
				neg_min = (temp%MOD)*(a[i]);

			}
			if(max<pos_max)
				max= pos_max;
			
		}
		
		printf("%llu\n",max);
		
		
	}
	
	
	
	
	
	
	
}



