class Solution {
public:
    // time : O(log(max(n,k)))
    // space : O(1)
    //bit manuplation

    int mySolution(int n , int k ){
        int i =0;
        int changes = 0;
        while(n>>i||k>>i){
            int bitMask = 1<<i;
            int Nval = (n&bitMask)>>i;
            int Kval = (k&bitMask)>>i;
            cout<<Nval<<" "<<Kval<<endl;
            if(Nval == 0 && Kval==1)
                return -1;
            else if(Nval == 1 && Kval == 0)
                changes++;
            i++;
        }   
        return changes;
    }
    int betterWrittenCode(int n , int k ){
        int changes = 0;
        while (n > 0 || k > 0) {
            // Extract the least significant bits of n and k
            int Nval = n & 1;
            int Kval = k & 1;
            
            // Check the conditions for changes or impossibility
            if (Nval == 0 && Kval == 1)
                return -1; // Not possible to convert
            else if (Nval == 1 && Kval == 0)
                changes++; // Need to change 1 to 0
            
            // Right shift n and k to process the next bit
            n >>= 1;
            k >>= 1;
        }
        return changes;

    }
    int minChanges(int n, int k) {
        return betterWrittenCode(n,k);
    }
};

