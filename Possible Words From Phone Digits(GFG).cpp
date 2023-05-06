//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


// } Driver Code Ends
//User function Template for C++
string dict[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

class Solution
{
    public:
    set<string> collec;
  void allComb(int a[], int N, int ind, string &curr)
  {
    if (ind == N)
    {
      collec.insert(curr);
      return;
    }
    string presentString = dict[a[ind]];
    for (int i = 0; i < presentString.size(); ++i)
    {
      curr.push_back(presentString[i]);
      allComb(a, N, ind + 1, curr);
      curr.pop_back();
    }
  }
  vector<string> possibleWords(int a[], int N)
  {
    // Your code here
    collec.clear();
    string curr = "";
    allComb(a, N, 0, curr);
    vector<string> allCombinations;
    for (auto val : collec)
    {
      allCombinations.push_back(val);
    }
    return allCombinations;
  }
};


//{ Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}
// } Driver Code Ends
