#include <iostream>
using namespace std;

void    rasm(int x, int r, string a, int *d) {
	int i = 0;

    if (x == r)
            cout << a << endl;
    else {
        for (int i = 97; i <= 111; i++) {
            if (d[i - 97] < r - 2) {
                a[x] = i;
				d[i - 97]++;
                rasm(x + 1, r, a, d);
				d[i - 97]--;
            }
        }
    }
}

void	init_rasm() {
	int n;
	string a = "";
	int *d = new int[15];

	cout << "enter number of letters: ";
	cin >> n;
	if (n < 3) {
		cout << "n must be >= 3";
		return ;
	}
	for (int i = 0; i < 15; i++)
		d[i] = 0;
	a.insert(0, n, 'a');
	rasm(0, n, a, d);
	delete []d;
}

int main() {
    init_rasm();
    return (0);
}
