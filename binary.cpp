// "Binary gap"
// Convert a positive intiger 'N' to binary representation
// check maximal sequence of consecutive zeros
// Example 1: N=529 -> 1000010001 (contains two binary gaps: one of length 4 and one of length 3) therefore max. =4
// Example 2: 20 -> 10100 (contains one binary gap of length 1)
// C++14 (g++ 6.2.0)

#include <algorithm>
#include <iostream>

using namespace std;

int solution(int N) {
	// 'i' counter of sequence of consecutive zeros
	// 'tab[]' matrix for counters
	int i = 0, j = 0, tab[50];
	int w = 0;
	// searching for first '1' (initial zeros don't matter)
	while (N % 2 == 0) { N = N / 2; }
	//cout <<"First '1' in the sequence " << "  "<< N << endl;
	while (N > 0)
	{
		tab[j] = i; // assigning "zeros counter" to matrix (tab[0] = 0)
		j++;
		i = 0;
		if (N % 2 == 1) {
			N = N / 2;
			// counting zeros
			while (N % 2 == 0 && N > 0) {
				i++;
				N = N / 2;
			}
		}
	}
	cout << endl;
	if (j > 0)
	{
		for (int i = 1; i <j; i++)
		{
			if (tab[i] > tab[i - 1]) w = tab[i];
			else w = tab[i - 1];
		}
	}
	else w = 0; // when no binary gap and j=0
	cout << w << endl;
	return 0;
}

int main()
{
	unsigned int a;
	cin >> a;
	cout << endl;
	
	solution(a);

	return 0;
}