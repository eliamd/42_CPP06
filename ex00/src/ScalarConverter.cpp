//
// Created by Eliam on 29/04/2025.
//

#include "../includes/ScalarConverter.hpp"
#include <cmath>
#include <limits>
#include <iomanip>

enum Type {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	INVALID
};

void ScalarConverter::convert(std::string &literal) {
	Type type = INVALID;
	double value = 0.0;

	//CHAR
	if (literal.length() == 1 && !std::isdigit(literal[0])) {
		type = CHAR;
		value = static_cast<double>(literal[0]);
		//INF etc...
	} else if (literal == "nan" || literal == "+inf" || literal == "-inf") {
		type = DOUBLE;
		if (literal == "nan")
			value = std::numeric_limits<double>::quiet_NaN();
		else if (literal == "+inf")
			value = std::numeric_limits<double>::infinity();
		else
			value = -std::numeric_limits<double>::infinity();
	} else if (literal == "nanf" || literal == "+inff" || literal == "-inff") {
		type = FLOAT;
		if (literal == "nanf")
			value = std::numeric_limits<float>::quiet_NaN();
		else if (literal == "+inff")
			value = std::numeric_limits<float>::infinity();
		else
			value = -std::numeric_limits<float>::infinity();
	} else {
		// FLOAT
		bool isFloat = false;
		if (literal.length() > 2 && literal[literal.length() - 1] == 'f') {
			isFloat = true;
			literal = literal.substr(0, literal.length() - 1);
		}

		//INT or DOUBLE
		char *endptr;
		value = strtod(literal.c_str(), &endptr);
		if (*endptr == '\0') {
			if (literal.find('.') == std::string::npos) {
				type = INT;
			} else {
				type = isFloat ? FLOAT : DOUBLE;
			}
		} else {
			type = INVALID;
		}
	}

	// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ DISPLAY ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
	std::cout << "char: ";
	if (type == INVALID || std::isnan(value) || std::isinf(value)) {
		std::cout << "impossible" << std::endl;
	} else if (value < 0 || value > 127) {
		std::cout << "impossible" << std::endl;
	} else if (value < 32 || value > 126) {
		std::cout << "Non displayable" << std::endl;
	} else {
		std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
	}

	std::cout << "int: ";
	if (type == INVALID || std::isnan(value) || std::isinf(value) ||
	    value > static_cast<double>(std::numeric_limits<int>::max()) ||
	    value < static_cast<double>(std::numeric_limits<int>::min())) {
		std::cout << "impossible" << std::endl;
	} else {
		std::cout << static_cast<int>(value) << std::endl;
	}

	std::cout << "float: ";
	if (type == INVALID) {
		std::cout << "impossible" << std::endl;
	} else if (std::isnan(value)) {
		std::cout << "nanf" << std::endl;
	} else if (std::isinf(value) && value > 0) {
		std::cout << "+inff" << std::endl;
	} else if (std::isinf(value) && value < 0) {
		std::cout << "-inff" << std::endl;
	} else {
		std::cout << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
	}

	std::cout << "double: ";
	if (type == INVALID) {
		std::cout << "impossible" << std::endl;
	} else if (std::isnan(value)) {
		std::cout << "nan" << std::endl;
	} else if (std::isinf(value) && value > 0) {
		std::cout << "+inf" << std::endl;
	} else if (std::isinf(value) && value < 0) {
		std::cout << "-inf" << std::endl;
	} else {
		std::cout << std::fixed << std::setprecision(1) << value << std::endl;
	}
}
