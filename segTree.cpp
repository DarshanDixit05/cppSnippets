#include <bits/stdc++.h>
using namespace std;

class SegTree
{
  vector < int >seg;
    public : 
    SegTree (int n)
  {
    seg.resize (4 * n + 1);
  }
  void buildSeg (int indx, int low, int high, int arr[])
  {
    if (low == high)
      {
	seg[indx] = arr[low];
	return;
      }

    int mid = (low + high) >> 1;
    buildSeg (2 * indx + 1, low, mid, arr);
    buildSeg (2 * indx + 2, mid + 1, high, arr);
    seg[indx] = min (seg[2 * indx + 1], seg[2 * indx + 2]);
  }

  int query (int indx, int low, int high, int l, int r)
  {
    //out of range
    if (r < low || l > high)
      return INT_MAX;

    //complete match
    if (low >= l && high <= r)
      return seg[indx];

    //partial match
    int mid = (low + high) >> 1;
    int left = query (2 * indx + 1, low, mid, l, r);
    int right = query (2 * indx + 2, mid + 1, high, l, r);
    return min (left, right);
  }

  void update (int indx, int low, int high, int i, int val)
  {
    if (low == high)
      {
	seg[indx] = val;
	return;
      }

    int mid = (low + high) >> 1;
    if (i <= mid)
      update (2 * indx + 1, low, mid, i, val);
    else
      update (2 * indx + 2, mid + 1, high, i, val);
    seg[indx] = min (seg[2 * indx + 1], seg[2 * indx + 2]);
  }

};

int
main ()
{
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++)
    cin >> arr[i];
    
    SegTree sg(n);
    
  int seg[4 * n];
  sg.buildSeg (0, 0, n - 1, arr);
  int q;
  cin >> q;
  while (q--)
    {
      int l, r, type;
      cin >> type;
      if (type == 1)
	{
	  cin >> l >> r;
	  cout << sg.query (0, 0, n - 1, l, r) << endl;
	}
      else
	{
	  int i, val;
	  cin >> i >> val;
	  sg.update (0, 0, n - 1, i, val);
	  arr[i] = val;
	}
    }
  return 0;
}
