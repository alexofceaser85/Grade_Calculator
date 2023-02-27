/*
 * Grade.cpp
 *
 *  Created on: Feb 25, 2023
 *      Author: adecesa1
 */

#include "Grade.h"

namespace model {
	Grade::Grade() {
		this->firstName = string();
		this->lastName = string();
		this->grade = 0;
	}

	Grade::Grade(const string& firstName, const string& lastName, int grade) {
		this->firstName = firstName;
		this->lastName = lastName;
		this->grade = grade;
	}

	Grade::~Grade() {
		// TODO Auto-generated destructor stub
	}

	const string& Grade::getFirstName() const {
		return firstName;
	}

	const string& Grade::getLastName() const {
		return lastName;
	}

	int Grade::getGrade() const {
		return grade;
	}

	bool Grade::operator< (const Grade &other) const {
		return this->grade < other.getGrade();
	}
}

