
#include <iostream>

class Fraction
{
private:
	int numerator_;
	int denominator_;

	int find_nod(int a, int b) {
		while (a != 0 && b != 0) {
			if (a > b) a = a % b;
			else b = b % a;
		}
		return a + b;
	}

	void shortcut(Fraction& fr) {
		int nod = find_nod(fr.numerator_, fr.denominator_);
		if (nod != 1) {
			fr.numerator_ = fr.numerator_ / nod;
			fr.denominator_ = fr.denominator_ / nod;
		}
		if (fr.denominator_ < 0) {
			fr.numerator_ *= -1;
			fr.denominator_ *= -1;
		}
	}

public:
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}

	bool operator==(Fraction& fr) {
		shortcut(*this);
		shortcut(fr);
		return this->numerator_ == fr.numerator_ && this->denominator_ == fr.denominator_;
	}

	bool operator!=(Fraction& fr) {
		return !(*this==fr);
	}

	bool operator<(Fraction& fr) {
		double a = numerator_ / static_cast<double>(denominator_);
		double b = fr.numerator_ / static_cast<double>(fr.denominator_);
		return a < b;
	}

	bool operator>(Fraction& fr) {
		double a = numerator_ / static_cast<double>(denominator_);
		double b = fr.numerator_ / static_cast<double>(fr.denominator_);
		return a > b;
	}

	bool operator>=(Fraction& fr) {
		double a = numerator_ / static_cast<double>(denominator_);
		double b = fr.numerator_ / static_cast<double>(fr.denominator_);
		return a >= b;
	}

	bool operator<=(Fraction& fr) {
		double a = numerator_ / static_cast<double>(denominator_);
		double b = fr.numerator_ / static_cast<double>(fr.denominator_);
		return a <= b;
	}
};

int main()
{
	Fraction f1(4, 3);
	Fraction f2(12, 9);

	std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
	std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';
	std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';
	std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';
	std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';
	std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';
	return 0;
}
