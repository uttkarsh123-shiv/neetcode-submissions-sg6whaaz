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

    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i=0;i<myArray.size();i++){
        pq.push(myArray[i]);

        if(pq.size() > k) {
            pq.pop();
        }
    }

    return pq.top();
    }
};
