class KthLargest {
public:
    vector<int> myArray;
    int k;
    KthLargest(int k, vector<int>& nums) {

        myArray = nums;
        this->k=k;
    }
    
    int add(int val) {
        myArray.push_back(val);
   sort(myArray.rbegin(), myArray.rend());

   return myArray[k-1];
    }
};
