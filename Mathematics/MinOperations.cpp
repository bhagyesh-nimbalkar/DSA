class Solution {
public:
    int minOperations(int n) {
   
     
      // just write the series fro n=1 to n==6;
      //notice the mid elemnt is equal to n for every series
      // try to make every element equal to the mid element (which will be n)
      //and  that diffeerence will be a series of odd numbers
      //and calculate the sum of this series 
       // and sum of m odd numbers is m*m 
       
                 // if n is even then      //if n is odd
      
      return (n%2==0) ? (n/2)*(1ll)*(n/2) :  ((n/2)+1)*(1ll)*(n/2);


    }
};