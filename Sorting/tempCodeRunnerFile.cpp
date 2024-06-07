
      {
           unsigned long long int mid = (low+high)/2;
           if(mid*mid >= x)  high=mid;
           else low=mid+1;
      }
      if(low*low == x || low<4) return low;