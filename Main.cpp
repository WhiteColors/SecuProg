#include <iostream>

using namespace std;

class Money {
private:
    int val_;
    int cents_;
public:

    Money(int dollars, int cents) : val_(dollars), cents_(cents) {}

    int dollars() const { return val_; }
    int cents() const { return cents_; }

    Money operator+(const Money& rhs) const {
		int new_dollars = val_ + rhs.val_;
		int new_cents = cents_ + rhs.cents_;
		if (new_cents > 99) {
			new_dollars += 1;
			new_cents -= 100;
		}
		return Money(new_dollars, new_cents);
    }

    Money operator-(const Money& rhs) const {
		int new_dollars = val_ - rhs.val_;
		int new_cents = cents_ - rhs.cents_;
		if (new_cents > 99) {
			new_dollars += 1;
			new_cents -= 100;
		}
		return Money(new_dollars, new_cents);
    }

    Money operator*(const Money& rhs) const {
		int new_dollars = val_ * rhs.val_;
		int new_cents = cents_ * rhs.cents_;
		if (new_cents > 99) {
			new_dollars += 1;
			new_cents -= 100;
		}
		return Money(new_dollars, new_cents);
    }

    Money& operator+=(const Money& rhs) {
		val_ += rhs.val_;
		cents_ += rhs.cents_;
		if (cents_ > 99) {
			val_ += cents_ / 100;
			cents_ %= 100;
		}
		return *this;
    }
	
    Money& operator-=(const Money& rhs) {
		val_ -= rhs.val_;
		cents_ -= rhs.cents_;
		if (cents_ > 99) {
			val_ += cents_ / 100;
			cents_ %= 100;
		}
        return *this;
    }
	
    Money& operator*=(const Money& rhs) {
		val_ *= rhs.val_;
		cents_ *= rhs.cents_;
		if (cents_ > 99) {
			val_ += cents_ / 100;
			cents_ %= 100;
		}
		return *this;
    }

    bool operator==(const Money& rhs) const {
		return val_ == rhs.val_ && cents_ == rhs.cents_;
    }

    bool operator!=(const Money& rhs) const {
        return !(*this == rhs);
    }

    bool operator<(const Money& rhs) const {
        return val_ < rhs.val_ || (val_ == rhs.val_ && cents_ < rhs.cents_);
    }

    bool operator>(const Money& rhs) const {
        return rhs < *this;
    }

    bool operator<=(const Money& rhs) const {
        return !(rhs < *this);
    }

    bool operator>=(const Money& rhs) const {
        return !(*this < rhs);
    }

friend ostream& operator<<(ostream& os, const Money& money) {
        os << money.val_ << "." << money.cents_;
        return os;
    }
};

int main() {
    Money m1(10, 20);
    Money m2(80, 90);
    cout << m1 << " + " << m2 << " = " << m1 + m2 << endl;
    return 0;
}