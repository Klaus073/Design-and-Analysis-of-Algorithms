
#include <iostream>
#include <math.h>

using namespace std;

int getLength(long long value) {
	int counter = 0;
	while (value != 0) {
		counter++;
		value /= 10;
	}
	return counter;
}

long long multiply(long long x, long long y) {
	int xLength = getLength(x);
	int yLength = getLength(y);

	// the bigger of the two lengths
	int N = (int)(fmax(xLength, yLength));

	// if the max length is small it's faster to just flat out multiply the two nums
	if (N < 10)
		return x * y;

	//max length divided and rounded up
	N = (N/2) + (N%2);

	long long multiplier = pow(10, N);	//step 1

	long long b = x/multiplier;//step 2
	long long a = x - (b * multiplier);//step 3
	long long d = y / multiplier;//step 4
	long long c = y - (d * N);//step 5

	long long z0 = multiply(a,c);
	long long z1 = multiply(a + b, c + d);
	long long z2 = multiply(b, d);


    return z0 + ((z1 - z0 - z2) * multiplier) + (z2 * (long long)(pow(10, 2 * N)));

}



int main() {
	// two numbers
	long long a = 2406994;
	long long b = 2328563;
	cout << multiply(a,b) << endl;
	return 0;
}