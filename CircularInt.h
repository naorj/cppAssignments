using namespace std;
class CircularInt;

class CircularInt {

	int low;
	int high;
	int current;

public:
	CircularInt(int a, int b);
	friend ostream& operator <<(ostream& os, const CircularInt& m);
	friend CircularInt& operator+=(CircularInt& t, int a);
	friend CircularInt& operator++(CircularInt& t, int);
	friend int operator-(CircularInt &t);
	friend CircularInt& operator-(int num, CircularInt& t);
	friend int operator+(CircularInt&a, CircularInt&b);
	friend CircularInt& operator*=(CircularInt &t, int num);
	friend string operator/(CircularInt& t, int num);
	friend bool operator==(CircularInt& a, CircularInt& b);
	friend CircularInt& operator-(CircularInt& t,int num);
};
