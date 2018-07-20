#include <iostream>

#include <vector> 
#include <algorithm> 
using namespace std; 
void printarrayINT(int arr[], int n){
	for (int i  = 0; i < n; i++)
	{
		cout << arr[i] << " "; 
	}
	cout << "\n"; 
}
/////COUNTING SORT. 
void countsort(int arr[], int n){
	int max, min, id;
	int i, j; 
	//find max, min. 
	max = min = arr[0]; 
	for (i = 0; i < n; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
		if (arr[i] < min)
		{
			min = arr[i];
		}
	}
	//output array. 
	int range = max - min + 1;
	int *output = new int[range];
	for (i = 0; i < range; i++)
	{
		output[i] = 0; 
	}
	for (i = 0; i < n; i++)
	{
		output[arr[i] - min] ++; 
	}

	id = 0; 
	for (i = min; i <= max; i++)
	{
		for (j = 0; j < output[i-min]; j++)
		{
			arr[id++] = i;
		}
	}
	//restore heap. 
	delete[] output;
}
//print array float.
void printarrFloat(float arr[], int n){
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " "; 
	}
	cout << "\n"; 
}
//radix sort float number. 
void radixsort(float arr[], int n){
	float *output = new float[n]; 
	float bucket[10]; 
	float max; 
	int i, j, freq = 1;
	//find max; 
	max = arr[0]; 
	for (i = 0; i < n; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i]; 
		}
	}
	//tinh id, xep vao bucket array
	int id; 
	while (max / freq > 0)
	{
		//set memory. 
		memset(bucket, 0, sizeof(float) * 10); 
		memset(output, 0, sizeof(float) * n); 
		for (i = 0; i < n; i++)
		{
			id = (int (arr[i] / freq) % 10); 
			bucket[id] ++;
		}
		for (i = 1; i < 10; i++)
		{
			bucket[i] += bucket[i - 1]; 
		}
		for (i = n-1; i >= 0; i--)
		{
			id = (int(arr[i] / freq) % 10);
			id = --bucket[id]; 
			output[id] = arr[i];
		}
		for (i = 0; i < n; i++)
		{
			arr[i] = output[i];
		}
		freq *= 10;
	}
}
//////////BUCKET SORT. 
const int b_size = 10; 
void bucketsort(float arr[], int n){
	vector<float> B[b_size]; 
	int i, j, id; 
	float max, devider; //max and devider. 
	//find max. 
	max = arr[0]; 
	for (i = 0; i < n; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	devider = ceil(float(max + 1) / b_size); 
	for (i = 0; i < n; i++)
	{
		j = floor(arr[i] / devider);
		//push back.
		B[j].push_back(arr[i]);
	}
	//sort in bucket. 
	for (i = 0; i < b_size; i++)
	{
		sort(B[i].begin(), B[i].end());
	}
	//xuat. 
	id = 0; 
	for (i = 0; i < b_size; i++)
	{
		for (j = 0; j < B[i].size(); j++)
		{
			arr[id++] = B[i][j];
		}
	}
}
int main(){
	float arr[100];
		int i, n; 
	cout << "nhap sz: "; cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> arr[i]; 
	}
	float neg[10], pos[10]; int j = 0, k = 0, l = 0;
	for (i = 0; i < n; i++)
	{
		if (arr[i] <0)
		{
			neg[j] = arr[i];
			neg[j] = abs(neg[j]); 
			j++; 
		}
		else
		{
			pos[k] = arr[i]; 
			k++; 
		}
	}
	//radix sort neg, pos.
	/*radixsort(neg, j); 
	cout << "mang am: "; 
	for (i = 0; i < j; i++)
	{
		cout << neg[i] << " "; 
	}
	cout << "\n";
	radixsort(pos, k);
	cout << "mang duong: ";
	for (i = 0; i < k; i++)
	{
		cout << pos[i] << " ";
	}
	cout << "\n";
*/
	bucketsort(neg, j); printarrFloat(neg, j); 
	cout << "\n"; 
	bucketsort(pos, k); printarrFloat(pos, k);
	cout << "\n";
	//ghep 2 mang. 
	l = j - 1; 
	for (i = 0; i < j; i++)
	{
		arr[i] = neg[l];
		arr[i] -= neg[l] * 2; 
		l++; 
	}
	l = 0; 
	for (i = j; i < n; i++)
	{
		arr[i] = pos[l++]; 
	}
	cout << "mang sx la: "; 
	printarrFloat(arr, n); 
	return 0;
}