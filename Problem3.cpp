#include<iostream>
#include<vector>
#include<string>
#include<cmath>
using namespace std;

void makeSameSize(vector<int> & new_x, vector<int> & new_y);
void convertStringToInt(vector<string> x, vector<string> y, vector<int> & new_x, vector<int> & new_y, vector<string> n, vector<int> & n1);
void compliment(vector<int> & y);
void addition(vector<int> new_x, vector<int> new_y, vector<int> & sum);
void add_1_to_vector(vector<int> & y);
void print(vector<int> x);
bool sizeCheck(vector<int> & x, vector<int> & y);
void removeLastDigit(vector<int> & x);
void divide(vector<int> x, vector<int> y, vector<int> & q, vector<int> & r);
void copyVector(vector<int> & x, vector<int> & y);
void removeTrailingZero(vector<int> & x);


// this function converts the binary strings to ints
void convertStringToInt(vector<string> x, vector<string> y, vector<int> & new_x, vector<int> & new_y, vector<string> n, vector<int> & n1)
{

	for (int i = 0; i < x.size(); i++) {
		new_x.insert(new_x.begin() + i, stoi(x[i]));

	}
	for (int i = 0; i < y.size(); i++) {

		new_y.insert(new_y.begin() + i, stoi(y[i]));
	}
	for (int i = 0; i < n.size(); i++) {

		n1.insert(n1.begin() + i, stoi(n[i]));
	}

}

// this function makes both numbers equal lenght by adding zeroes wherever needed 
void makeSameSize(vector<int> & new_x, vector<int> & new_y)
{
	int size_x = new_x.size();
	int size_y = new_y.size();
	if (size_x > size_y) {
		for (int i = size_x - size_y - 1; i >= 0; i--)
		{

			new_y.push_back(0);
		}
	}
	else if (size_y > size_x) {
		for (int i = size_y - size_x - 1; i >= 0; i--)
		{

			new_x.push_back(0);
		}
	}
}
void compliment(vector<int> & y)
{
	for (int i = 0; i < y.size(); i++)
	{
		if (y[i] == 0)
		{
			y[i] = 1;
		}
		else if (y[i] == 1)
		{
			y[i] = 0;
		}
	}
}

void add_1_to_vector(vector<int> & y)
{
	vector<int> q = { 1 };
	vector<int> newVect;
	addition(y, q, newVect);
	makeSameSize(y, newVect);
	for (int i = 0; i < newVect.size(); i++)
	{
		y[i] = newVect[i];
	}
}

void removeLastDigit(vector<int> & x)
{
	x.pop_back();
}
void removeTrailingZero(vector<int> & x)
{

	bool flag = false;

	while (flag == false) {
		int size = x.size();
		if (size - 1 == 0) {
			flag = true;
		}
		else if (x[size - 1] == 0) {
			x.pop_back();
		}
		else if (x[size - 1] != 0) {
			flag = true;
		}
	}
}
void addition(vector<int> new_x, vector<int> new_y, vector<int> & sum)
{

	int carry = 0;
	makeSameSize(new_x, new_y);

	for (int i = 0; i <new_x.size(); i++)
	{
		if (new_x[i] + new_y[i] + carry == 2) {
			carry = 1;
			sum.push_back(0);
		}
		else if (new_x[i] == 0 && new_y[i] == 0 && carry != 1) {
			carry = 0;
			sum.push_back(0);
		}
		else if (new_x[i] + new_y[i] + carry == 3) {
			carry = 1;
			sum.push_back(1);
		}
		else if (new_x[i] == 0 && new_y[i] == 0 && carry == 1) {
			carry = 0;
			sum.push_back(1);
		}
		else {
			carry = 0;
			sum.push_back(1);
		}
	}
	if (carry == 1) {
		sum.push_back(carry);
	}
	removeTrailingZero(sum);
}

bool sizeCheck(vector<int> & x, vector<int> & y)
{

	makeSameSize(x, y);
	long long int size_x = 0;
	long long int size_y = 0;
	for (int i = 0; i < x.size(); i++) {
		if (x[i] == 1) {
			size_x = size_x + pow(2, i);
		}
	}
	for (int i = 0; i < y.size(); i++) {
		if (y[i] == 1) {
			size_y = size_y + pow(2, i);
		}
	}
	if (size_x >= size_y)
	{
		return true;
	}
	else if (size_y > size_x) {
		return false;
	}
}

// print function to output data 
void print(vector<int> x) {
	for (int i = 0; i<x.size(); i++) {
		cout << x[i];
	}
}
void subtract(vector<int> & x, vector<int> & y, vector<int> & sub)
{
	vector<int>temp;
	copyVector(y, temp);
	makeSameSize(x, y);
	compliment(y);
	add_1_to_vector(y);
	addition(x, y, sub);
	removeLastDigit(sub);
	copyVector(temp, y);
	removeTrailingZero(sub);
	removeTrailingZero(y);
}

void copyVector(vector<int> & x, vector<int> & y)
{
	makeSameSize(x, y);
	for (int i = 0; i < x.size(); i++)
	{
		y[i] = x[i];
	}
}
void divide(vector<int> x, vector<int> y, vector<int> & q, vector<int> & r)
{

	q = { 0 };
	bool flag = true;
	bool flag2 = true;
	bool flag3 = true;
	vector<int>sub2;
	bool mod_check = sizeCheck(x, y);
	if (mod_check == false)
	{
		copyVector(x, r);
		flag = false;
		removeTrailingZero(r);


	}
	while (flag == true)
	{
		vector<int> sub;
		subtract(x, y, sub);
		add_1_to_vector(q);
		flag = sizeCheck(sub, y);
		if (flag == false)
		{
			int i = 0;
			while (i < sub.size())
			{
				if (sub[i] != y[i])
				{
					flag2 = false;
				}
				if (flag2 == false)
				{
					flag3 = false;
				}
				i++;
			}

		}


		copyVector(sub, x);
		copyVector(sub, sub2);

	}

	if (flag3 == false) {
		copyVector(sub2, r);
		removeTrailingZero(r);
	}

}

void mod(vector<int> & x, vector<int> & y, vector<int> & r)
{
	vector<int> q;
	divide(x, y, q, r);
	removeTrailingZero(r);
}

void multiply(vector<int> & x, vector<int> & y, vector<int> & product)
{
	vector<int> vect1 = { 0 };

	makeSameSize(x, y);
	for (int i = 0; i < y.size(); i++)
	{
		vector<int> vect2;
		vector<int>copy;
		for (int k = 0; k < i; k++) {
			vect2.insert(vect2.begin() + k, 0);
		}
		for (int j = 0; j < x.size(); j++)
		{

			vect2.push_back(y[i] * x[j]);

		}
		addition(vect1, vect2, copy);
		copyVector(copy, vect1);
	}
	copyVector(vect1, product);
}

void modexp(vector<int> & x, vector<int> & y, vector<int> n, vector<int> & result)
{

	vector<int> z = { 1 };
	vector<int> w;
	copyVector(x, w);


	vector<int> z_copy;
	vector<int> w_copy;
	vector<int> w_n;
	vector<int> z_n;

	for (int i = 0; i < y.size(); i++)
	{
		if (y[i] == 1)
		{
			multiply(z, w, z_copy);
			mod(z_copy, n, z_n);
			copyVector(z_n, z);
		}
		multiply(w, w, w_copy);
		mod(w_copy, n, w_n);
		copyVector(w_n, w);

	}
	copyVector(z, result);
	removeTrailingZero(result);
}
void generateVectors(int n, vector<int> & x, vector<int> & y, vector<int> & N)
{
	N.insert(N.begin(), 1);
	N.insert(N.begin() + 1, 0);
	N.insert(N.begin() + 2, 1);
	for (int i = 1; i <= n; i++)
	{
		N.push_back(0);
	}
	for (int i = 1; i <= n; i++)
	{
		N.push_back(1);
	}
	N.push_back(0);
	N.push_back(1);

	x.insert(x.begin(), 1);
	x.insert(x.begin() + 1, 1);
	for (int i = 1; i <= n; i++)
	{
		x.push_back(0);
	}
	for (int i = 1; i <= n; i++)
	{
		x.push_back(1);
	}

	y.insert(y.begin(), 1);
	y.insert(y.begin() + 1, 0);
	for (int i = 1; i <= n; i++)
	{
		y.push_back(0);
	}
	for (int i = 1; i <= n; i++)
	{
		y.push_back(1);
	}


}
int main()
{
	
	vector<int> new_n;
	vector<int> new_x;
	vector<int> new_y;
	int n;
	cout << "Enter n: ";
	cin >> n;
	vector<int> r;
	generateVectors(n, new_x, new_y, new_n);
	cout << "The generated vectors are as follows: " << endl;
	cout << "x is: ";
	print(new_x);
	cout << endl;
	cout << "Y is: ";
	print(new_y);
	cout << endl;
	cout << "N is: ";
	print(new_n);
	cout << endl;
	modexp(new_x, new_y, new_n, r);
	cout << endl;
	cout << "x^y mod N = ";
	print(r);
	cout << endl;
	system("pause");
	return 0;
}