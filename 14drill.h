
struct B1 {
	virtual void vf() {
		cout << "B1::vf()" << '\n';
	}
	void f() {
		cout << "B1::f()" << '\n';
	}
	virtual void pvf() = 0;
};

struct D1 : B1 {
/*
	void vf() {
		cout << "D1::vf()" << '\n';
	}
*/
	void f() {
		cout << "D1::f()" << '\n';
	}
};

struct D2 : D1 {
	void pvf() {
		cout << "D2::pvf()" << '\n';
	}
};

struct B2 {
	virtual void pvf() = 0;
};

struct D21 : B2 {
	D21(string ss) :s{ss} {}
	void pvf() {
		cout << s << '\n';
	}
private:
	string s;
};

struct D22 : B2 {
	D22 (int ii) :i{ii} {}
	void pvf() {
		cout << i << '\n';
	}
private:
	int i;
};
