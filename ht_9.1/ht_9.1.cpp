
#include <iostream>

class Fraction
{
private:
	int numerator_;
	int denominator_;

public:
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}

	bool operator==(Fraction& fr) {
		double a = numerator_ / static_cast<double>(denominator_);
		double b = fr.numerator_ / static_cast<double>(fr.denominator_);
		return a == b;
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
	Fraction f2(6, 11);

	std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
	std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';
	std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';
	std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';
	std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';
	std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';
	return 0;
}
