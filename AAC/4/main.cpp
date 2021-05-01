#include <iostream>
using namespace std;

void print_arr(int *a, int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i];
	cout << endl;
}

void recursion(int *m, int n, int k, int i) {
    if (i == n) {
        print_arr(m, n);
        return ;
    }
    for (int j = 1; j <= k; j++) {
        m[i] = j;
        recursion(m, n, k, i + 1);
    }
}

int main(){
    int n, k;
    int *m;

    cout << "Enter n ";
    cin >> n;
    cout << "Enter k: ";
    cin >> k;
    m = new int[n];
    recursion(m, n, k, 0);
    delete [] m;
    return 0;
}
