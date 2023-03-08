// #include <bits/stdc++.h>
// using namespace std;

// class lpSGT{
//     public:
//     vector<int>seg, lazy;
//     lpSGT(int n)
//     {
//         seg.resize(4*n);
//         lazy.resize(4*n);
//     }
    
//     public:
//     void build(int indx, int low, int high, int arr[])
//     {
//         if(low==high)
//         {
//             seg[indx]=arr[low];
//             return;
//         }
        
//         int mid = (low+high)>>1;
//         build(2*indx+1, low, mid, arr);
//         build(2*indx+2, mid+1, high, arr);
//         seg[indx] = seg[2*indx+1] + seg[2*indx+2];
//     }
    
//     void update(int indx, int low, int high, int l, int r, int val)
//     {
//         //while traversing check for previous pending addition in the lazy tree!!
//         if(lazy[indx]!=0)
//         {
//             seg[indx] = (high-low+1)*lazy[indx];
                
//             if(low!=high)
//             {
//                 lazy[2*indx+1] = (high-low+1)*lazy[indx];
//                 lazy[2*indx+2] = (high-low+1)*lazy[indx];
//             }
//             lazy[indx]=0;
//         }
        
//         // l r low high or low high l r
//         if(r<low || high<l)
//         {
//             return;
//         }
        
//         //complete l low high r
//         if(low>=l && high<=r)
//         {
//             seg[indx] +=(high-low+1)*val;
            
//             if(low!=high)
//             {
//                 lazy[2*indx+1] +=val;
//                 lazy[2*indx+2] +=val;
//             }
//             return;
//         }
        
//         //partial 
//         int mid = (low+mid)>>1;
//         update(2*indx+1, low, mid, l, r, val);
//         update(2*indx+2, mid+1, high, l, r, val);
//         seg[indx] = seg[2*indx+1]+seg[2*indx+2];
//     }
    
//     int query(int indx, int low, int high, int l, int r)
//     {
//         //while traversing check for previous pending addition in the lazy tree!!
//         if(lazy[indx]!=0)
//         {
//             seg[indx] = (high-low+1)*lazy[indx];
                
//             if(low!=high)
//             {
//                 lazy[2*indx+1] = (high-low+1)*lazy[indx];
//                 lazy[2*indx+2] = (high-low+1)*lazy[indx];
//             }
//             lazy[indx]=0;
//         }
        
//         // l r low high or low high l r
//         if(r<low || high<l)
//         {
//             return 0;
//         }
        
//         //complete l low high r
//         if(low>=l && high<=r)
//         {
//             return seg[indx];
//         }
        
//         int mid = (low+high)>>1;
//         int left = query(2*indx+1, low , mid, l, r);
//         int right = query(2*indx+2, mid+1, high, l, r);
//         return left+right;
//     }
// };


// int main()
// {
//     int n;
//     cin>>n;
//     int arr[n];
//     for(int i=0; i<n; i++)cin>>arr[i];
//     lpSGT st(n);
//     st.build(0, 0, n-1, arr);
//     int q;
//     cin>>q;
//     while(q--)
//     {
//         int type;
//         cin>>type;
//         if(type==1) //get the sum of the range
//         {
//             int l, r;
//             cin>>l>>r;
//             cout<<st.query(0, 0, n-1, l, r)<<endl;
//         }else{
//             int l, r, val;
//             cin>>l>>r>>val;
//             st.update(0, 0, n-1, l, r, val);
//         }
//     }
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;

class ST {
	vector<int> seg, lazy; 
public: 
	ST(int n) {
		seg.resize(4 * n); 
		lazy.resize(4 * n); 
	}
public: 
	void build(int ind, int low, int high, int arr[]) {
		if(low == high) {
			seg[ind] = arr[low];
			return; 
		}
		int mid = (low + high) >> 1; 
		build(2*ind+1, low, mid, arr); 
		build(2*ind+2, mid+1, high, arr); 
		seg[ind] = seg[2*ind+1] + seg[2*ind+2];
	}
public:
	void update(int ind, int low, int high, int l, int r, 
		int val) {
		// update the previous remaining updates 
		// and propogate downwards 
		if(lazy[ind] != 0) {
			seg[ind] += (high - low + 1) * lazy[ind]; 
			// propogate the lazy update downwards
			// for the remaining nodes to get updated 
			if(low != high) {
				lazy[2*ind+1] += lazy[ind]; 
				lazy[2*ind+2] += lazy[ind]; 
			}
 
			lazy[ind] = 0; 
		}
 
		// no overlap 
		// we don't do anything and return 
		// low high l r or l r low high 
		if(high < l or r < low) {
			return; 
		}
 
		// complete overlap 
		// l low high r 
		if(low>=l && high <= r) {
			seg[ind] += (high - low + 1) * val; 
			// if a leaf node, it will have childrens
			if(low != high) {
				lazy[2*ind+1] += val; 
				lazy[2*ind+2] += val; 
			}
			return; 
		}
		// last case has to be no overlap case
		int mid = (low + high) >> 1; 
		update(2*ind+1, low, mid, l, r, val);
		update(2*ind+2, mid+1, high, l, r, val); 
		seg[ind] = seg[2*ind+1] + seg[2*ind+2]; 
	}
public: 
	int query(int ind, int low, int high, int l, int r) {
 
		// update if any updates are remaining 
		// as the node will stay fresh and updated 
		if(lazy[ind] != 0) {
			seg[ind] += (high - low + 1) * lazy[ind]; 
			// propogate the lazy update downwards
			// for the remaining nodes to get updated 
			if(low != high) {
				lazy[2*ind+1] += lazy[ind]; 
				lazy[2*ind+2] += lazy[ind]; 
			}
 
			lazy[ind] = 0; 
		}
 
		// no overlap return 0; 
		if(high < l or r < low) {
			return 0; 
		}
 
		// complete overlap 
		if(low>=l && high <= r) return seg[ind]; 
 
		int mid = (low + high) >> 1; 
		int left = query(2*ind+1, low, mid, l, r);
		int right = query(2*ind+2, mid+1, high, l, r);
		return left + right; 
	}
};
int main() {
	int n;
	cin >> n; 
	int arr[n];
	for(int i = 0;i<n;i++) cin >> arr[i]; 
	ST st(n+1); 
	st.build(0,0,n-1, arr); 
 
	int q;
	cin >> q; 
	while(q--) {
		int type;
		cin >> type; 
		if(type==1) {
			int l, r;
			cin >> l >> r;
			cout << st.query(0,0,n-1,l,r) << endl; 
		}
		else {
			int l, r, val;
			cin >> l >> r >> val; 
			st.update(0,0,n-1,l,r,val);
		}
	}
	return 0; 
}




