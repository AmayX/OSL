#include <bits/stdc++.h>
using namespace std;

int s = 8;

void FCFS(int arr[], int head)
{
	int seek_count = 0;
	int distance, cur_track;

	for (int i = 0; i < s; i++) {
		cur_track = arr[i];

		// calculate absolute distance
		distance = abs(cur_track - head);

		// increase the total count
		seek_count += distance;

		// accessed track is now new head
		head = cur_track;
	}

	cout << "Total number of seek operations = "
		<< seek_count << endl;
	cout << "Seek Sequence is" << endl;

	for (int i = 0; i < s; i++) {
		cout << arr[i] << endl;
	}
}

// Driver code
int main()
{

	// request array
	int arr[s] = { 176, 79, 34, 60, 92, 11, 41, 114 };
	int head = 50;

	FCFS(arr, head);

	return 0;
}
