#include <iostream>
using namespace std;
#define ll   long long

int N=1000000;
bool sieve[1000000];
void createSieve()
{
    for(int i=2; i<=N; i++)sieve[i]=true;
    for(int i=2; i*i<=N; i++)
    {
        if(sieve[i]!=false)
        {
            for(int j=i*i; j<=N; j=j+i)
            {
                sieve[j]=false;
            }
        }
    }
}


int main()
{
    createSieve();
	int t;
	cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        if(sieve[n]==true)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }

    return 0;
}


