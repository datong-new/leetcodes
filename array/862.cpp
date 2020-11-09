#include<iostream>
#include<vector>
#include<deque>
using namespace std;


int shortestSubarray(vector<int>& A, int K) {
	int len = A.size();
        vector<int> sums(len+1, 0);
        deque<int> queue;
        for (int i=0; i<len; i++)
                sums[i+1] = sums[i] + A[i];
        int res = len + 1;

        for (int i=0; i<len+1; i++) {
                while (!queue.empty() && sums[i]<=sums[queue.back()]){
                        queue.pop_back();
                }
                while (!queue.empty() && sums[i]-sums[queue.front()]>=K){
                        res = min(res, i-queue.front());
                        queue.pop_front();
                }
                queue.push_back(i);
        }
        if (res==len+1) res = -1;
        return res;
}

int main() {
	vector<int> A {2, -1, 2};
	
	int K = 3;
	int min_len = shortestSubarray(A, K);
	std::cout<<min_len;
}
