/*
Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.

Examples: 
[2,3,4] , the median is 3

[2,3], the median is (2 + 3) / 2 = 2.5

Design a data structure that supports the following two operations:

void addNum(int num) - Add a integer number from the data stream to the data structure.
double findMedian() - Return the median of all elements so far.
For example:

add(1)
add(2)
findMedian() -> 1.5
add(3) 
findMedian() -> 2

*/

class MedianFinder {
public:

    priority_queue<int> firstQ; 
    priority_queue<int, std::vector<int>, std::greater<int> > secondQ;

 
    // Adds a number into the data structure.
    void addNum(int num) {
        if(firstQ.empty()) {
            firstQ.push(num);
            
        } else {
            
            //Compare top's and insert accordingly
            if(num < firstQ.top()) {
                firstQ.push(num);
            } else {
                
                secondQ.push(num);
            }
            
            
            //Compare size's. If abs(diff)>1. pop from one and insert in another
            if(firstQ.size() > (secondQ.size()+1)) {
                auto tmp = firstQ.top();
                firstQ.pop();
                secondQ.push(tmp);
            } else if (secondQ.size() > (firstQ.size()+1)) {
                auto tmp = secondQ.top();
                secondQ.pop();
                firstQ.push(tmp);
                
            }
            
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        
        if(firstQ.size()==secondQ.size()) {
            double first = firstQ.top();
            double second = secondQ.top();
            return (first+second)/2;
            
        } else if(firstQ.size()>secondQ.size()) {
            return (double)firstQ.top();
            
        } else {
            return (double)secondQ.top();
        }
        
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();
