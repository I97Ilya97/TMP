#include <iostream>
#include <string>
#include <fstream>



bool checking(std::string const & tx,std::string const & s)
{
	std::fstream f(tx, std::fstream::in);
	std::string S1;
	while (!f.eof()) 
	{
		getline(f, S1);
		if (s == S1) return false;
	}
	return true;
}

void print(std::string const & tx1, std::string const & tx2)
{
	std::fstream f1(tx1, std::fstream::in), f2(tx2, std::fstream::in);
	std::string str;
	int n = 1;
	while (!f1.eof())
	{
		getline(f1, str);
		if (checking(tx2, str))
			std::cout << tx1 << " " << str << " " << n << std::endl;
		n++;
	}
}

///////////////////////
int main() 
{

	std::string tx1 = "1.txt";
	std::string tx2 = "2.txt";
	print(tx1, tx2);
	print(tx2, tx1);
	system("pause");
	return 0;
}
