class MedianFinder {
private:
    priority_queue<int> maxHeap; // first half
    priority_queue<int,vector<int>,greater<>> minHeap; // second half
public:

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        int firstHalfMax = maxHeap.empty() ? 0 : maxHeap.top();
        int secondHalfMin = minHeap.empty() ? 0 : minHeap.top();

        bool isSameSize = minHeap.size()==maxHeap.size();
        bool moreElementsInSecondHalf = minHeap.size() > maxHeap.size();

        if(isSameSize){
            if(num >= secondHalfMin){
                minHeap.push(num);
            }
            else{
                maxHeap.push(num);
            }
        }
        else{
            if(moreElementsInSecondHalf){
                if(num >= secondHalfMin){
                    minHeap.pop();
                    maxHeap.push(secondHalfMin);

                    minHeap.push(num);
                }
                else{
                    maxHeap.push(num);
                }
            }
            else{
                if(num <= firstHalfMax){
                    maxHeap.pop();
                    minHeap.push(firstHalfMax);

                    maxHeap.push(num);
                }
                else{
                    minHeap.push(num);
                }
            }
        }
    }
    
    double findMedian() {
        if(maxHeap.size()==minHeap.size()){
            double mx = maxHeap.top();
            double mn = minHeap.top();

            return (mx+mn)/2.0;
        }
        else{
            if(maxHeap.size() > minHeap.size()){
                return maxHeap.top();
            }
            else{
                return minHeap.top();
            }
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */