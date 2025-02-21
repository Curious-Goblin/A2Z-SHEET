class Solution
{
public:
    int extractMax()
    {
        int maxElement = H[0];
        swap(H[0], H[s]);
        s--;
        shiftDown(0);
        return maxElement;
    }
};

/*
we have to return the max element of a heap or binary heap or priority queue here a max heap in which the 
parent node is always greater than or equal to their children node, so i got the max element and then
swapped it with the last(smallest) element and then deleted the max element which was asked in the
question.
*/