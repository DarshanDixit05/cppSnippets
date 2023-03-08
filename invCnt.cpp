    typedef long long ll;
    void _merge(ll left , ll mid, ll right, long long arr[], long long &invCnt)
    {
        ll i=left;
        ll j=mid+1;
        ll k=left; //pointer to update temp array
        ll temp[right];
        while((i<=mid) && (j<=right))
        {
            if(arr[i]<=arr[j])
            {
                temp[k++] = arr[i++];
            }else{
                temp[k++] = arr[j++];
                invCnt+=(mid-i+1);
            }
        }
        
        while(i<=mid)temp[k++]=arr[i++];
        while(j<=right)temp[k++]=arr[j++];
        
        for(ll i=left; i<=right; i++)
        {
            arr[i]=temp[i];
        }
    }
    void _mergerSort(ll left, ll right, long long arr[], long long &invCnt)
    {
        if(left<right)
        {
            ll mid = (left+right)>>1;
            _mergerSort(left, mid, arr, invCnt);
            _mergerSort(mid+1, right, arr, invCnt);
            
            _merge(left, mid, right, arr, invCnt);
        }
    }
