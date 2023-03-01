/*
 * Grade.cpp
 *
 *  Created on: Feb 25, 2023
 *      Author: adecesa1
 */

#include "Grade.h"
using namespace std;

namespace model {
	Grade::Grade() {
		this->firstName = std::string();
		this->lastName = std::string();
		this->grade = 0;
	}

	Grade::Grade(const std::string& firstName, const std::string& lastName, int grade) {
		this->firstName = firstName;
		this->lastName = lastName;
		this->grade = grade;
	}

	Grade::~Grade() {
		// TODO Auto-generated destructor stub
	}

	const std::string& Grade::getFirstName() const {
		return firstName;
	}

	const std::string& Grade::getLastName() const {
		return lastName;
	}

	int Grade::getGrade() const {
		return grade;
	}
}

