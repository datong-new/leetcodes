#include<iostream>
#include<vector>
using namespace std;

vector<int> get_primes(int max_m, vector<int> & min_primes) {
	vector<int> primes;
	for (int i=2; i<=max_m; i++) {
		if (min_primes[i]==0) {
			primes.push_back(i);
			min_primes[i] = i;
		}
		/* this method is overtime.
		for (int j=i+i; j<=max_m; j+=i) {
			check[j]=1;
			if (min_primes[j]==0) min_primes[j]=i;
		}
		*/
		
		for (int j=0; j<primes.size(); j++) {
			if (i*primes[j] > max_m) break;
			min_primes[i*primes[j]] = primes[j];
			if (i%primes[j]==0) break;
		}
	}
	return primes;
}

int splitArray(vector<int> & nums) {
	int max_m = 2;
	for (int i: nums) max_m = max(max_m, i);
	vector<int> min_primes (max_m+1, 0);
        // get all primes less than max_m
	// set min_prime for each num in nums;
	vector<int> primes = get_primes(max_m, min_primes);
//	for (int i=0; i<min_primes.size(); i++) cout<<i<<"\t"<<min_primes[i]<<endl;

	vector<int> dp (max_m+1, 0);
	int prev_min = 0;
	int current_min;
	for (int i=0; i<nums.size(); i++) {
		int num = nums[i];
		current_min = prev_min + 1;
		while(num>2) {
			int min_prime = min_primes[num];
			if (dp[min_prime]==0) dp[min_prime]=current_min;
			else dp[min_prime] = min(prev_min+1, dp[min_prime]);
			num = num / min_primes[num];
			current_min = min(dp[min_prime], current_min);
		}
		prev_min = current_min;
	}
	return current_min;
}

int main() {
	//vector<int> nums = {2,3,3,2,3,3};
	vector<int> nums = {326614, 489921};
	//vector<int> nums = {37657,174469,633487,679039,840163,885103,857713,815569,816859,708031,883237,706049,869983,777977,851569,789031,771181,738713,867319,781771,859919,784307,899309,879919,860333,702067,706267,801127,896447,796363,724079,765097,868697,793511,709769,721163,824393,739513,705073,818569,740191,772697,851293,750401,848791,804743,721087,761897,803731,833179,702379,925579,918041,906329,907667,918443,905477,924041,908653,911459,922321,918763,922457,918539,921959,905783,914791,920473,906973,914191,911783,918899,924793,930379,931289,927403,931529,929749,928871,928819,927677,928337,928453,927323,927001,931691,929647,929011,930667,930071,927361,929977,928337,927323,931097,936127,932497,950879,963559,973801};
	cout<<"nums size:"<<nums.size()<<endl;
	int min_splits = splitArray(nums);
	cout<<"min_splits"<<min_splits;
}

