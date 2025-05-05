#include <_time.h>
#include <iostream>
#include <unistd.h>

#include "../includes/Base.hpp"
#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"

Base *generate() {
	int random_number = rand() % 4;

	if (random_number == 1) {
		std::cout << "🟢 >> Generate : A" << std::endl;
		return new A();
	} else if (random_number == 2) {
		std::cout << "🟢 >> Generate : B" << std::endl;
		return new B();
	} else {
		std::cout << "🟢 >> Generate : C" << std::endl;
		return new C();
	}
}

void identify(Base *p) {
	if (dynamic_cast<A *>(p) != NULL) {
		std::cout << "🔍 POI >> identify >> A" << std::endl;
	} else if (dynamic_cast<B *>(p) != NULL) {
		std::cout << "🔍 POI >> identify >> B" << std::endl;
	} else if (dynamic_cast<C *>(p) != NULL) {
		std::cout << "🔍 POI >> identify >> C" << std::endl;
	} else {
		std::cout << "🔍 POI >> identify >> unknown type" << std::endl;
	}
}

void identify(Base &p) {
	try {
		A &test_obj = dynamic_cast<A &>(p);
		(void) test_obj;
		std::cout << "🔍 REF >> identify >> A" << std::endl;
	} catch (...) {
	}
	try {
		B &test_obj = dynamic_cast<B &>(p);
		(void) test_obj;
		std::cout << "🔍 REF >> identify >> B" << std::endl;
	} catch (...) {
	}
	try {
		C &test_obj = dynamic_cast<C &>(p);
		(void) test_obj;
		std::cout << "🔍 REF >> identify >> C" << std::endl;
	} catch (...) {
	}
}


int main(void) {
	srand(time(0));

	Base base;

	Base *_1 = generate();
	identify(*_1);
	identify(_1);

	std::cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << std::endl;
	usleep(200);

	Base *_2 = generate();
	identify(*_2);
	identify(_2);

	std::cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << std::endl;
	usleep(200);

	Base *_3 = generate();
	identify(*_3);
	identify(_3);


	delete _1;
	delete _2;
	delete _3;

	return 0;
}
