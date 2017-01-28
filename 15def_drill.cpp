#include "../std_lib_facilities.h"

struct Person {
	Person() {}
	Person(string n, int a) {
		if (a < 0 || a>=150) error("age out of range");
		if (contain_forb_kw(n)) error("charactor not allowed in name");
		name = n;
		age = a;
	}

	string get_name() const {return name;};
	int get_age() const {return age;};
private:
	string name;
	int age;
	bool contain_forb_kw(string n) {
		for (char c : n) {
			//cout << "enter char check: " << c << '\n';
			switch (c) {
			case ';': case ':': case '"':
			case '\'': case '[': case ']':
			case '*': case '&': case '^':
			//	cout << "forb kw caught \n";
				return true; 
			}
		}
		return false;
	}
};

ostream& operator<<(ostream& os, Person p)
{
	return os << p.get_name() << " : "
			<< p.get_age() << '\n';
}

istream& operator>>(istream& is, Person& p)
{

	string s;
	int i;
	if (is >> s >> i) {
	//	cout << "debug: s:" << s << " i:" << i << '\n';
		p = Person {s, i};
	}
	return is;
//	return is >> p.name >> p.age;
}

int main ()
{
	Person p;
	vector<Person> vp;
	cout << "Input name and age \n";
	while (cin >> p) {
		vp.push_back(p);
	}
	for (Person i : vp)
		cout << i;
}
