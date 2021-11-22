#include <iostream>
#include <vector>



class BigInteger
{
	static const unsigned int BASE = 1000000;
	static const unsigned int BASE_SIZE = 6;


	int sign_ = 1;
	std::vector<unsigned int> number_;

public:
	// ����������� �� ��������� -- ����� ��� �������� �������� (������ ����)
	// ����������� ����������� explicit BigInteger(const BigInteger& another);
	// ����������� ����������� explicit BigInteger(BigInteger&& another);
	// ��������� ����� isLess
	// bool isLess(const BigInteger& another);
	// �������� ��� ����� �������� �������� / ���������
	// ��������, ��� ����� ��������� ����������
	explicit BigInteger(int num)
	{
		if (num < 0)
		{
			sign_ = -1;
			num *= -1;
		}
		do
		{
			number_.push_back(num % BASE);
			num /= BASE;
		} while (num != 0);
	}

	void Print()
	{
		if (sign_ == -1)
		{
			std::cout << "-";
		}

		for (int i = number_.size() - 1; i >= 0; --i)
		{
			std::cout << number_[i];
		}

	}
};

int main()
{
	BigInteger a(-105677865);
	a.Print();
}