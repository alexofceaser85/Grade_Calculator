/*
 * Grade.cpp
 *
 *  Created on: Feb 25, 2023
 *      Author: adecesa1
 */

#include "StudentGrade.h"
#include "ErrorMessages.h"
using namespace std;
using namespace errormessages;

namespace model {
	/**
	 * The zero parameter constructor for the grade
	 *
	 * Precondition: None
	 * Postcondition: None
	 */
	StudentGrade::StudentGrade() {
		this->firstName = std::string();
		this->lastName = std::string();
		this->grade = 0;
	}
	/**
	 * The three parameter constructor for the grade
	 *
	 * Precondition: firstName.empty() == false
	 * && lastName.empty() == false
	 * && grade >= 0
	 * Postcondition: this->getFirstName() == firstName
	 * && this->getLastName() == lastName
	 * && this->getGrade() == grade
	 *
	 * Param: firstName the student first name
	 * Param: lastName the student last name
	 * Param: grade the grade value
	 */
	StudentGrade::StudentGrade(const std::string& firstName, const std::string& lastName, int grade) {
		if (firstName.empty()) {
			throw invalid_argument(ErrorMessages::FirstNameForStudentGradeCannotBeEmpty);
		}

		if (lastName.empty()) {
			throw invalid_argument(ErrorMessages::LastNameForStudentGradeCannotBeEmpty);
		}

		if (grade < 0) {
			throw invalid_argument(ErrorMessages::GradeValueForStudentGradeCannotBeLessThanZero);
		}

		this->firstName = firstName;
		this->lastName = lastName;
		this->grade = grade;
	}
	/**
	 * The destructor for the student grade
	 *
	 * Precondition: None
	 * Postcondition: None
	 */
	StudentGrade::~StudentGrade() {

	}
	/**
	 * Gets the first name
	 *
	 * Precondition: None
	 * Postcondition: None
	 */
	const std::string& StudentGrade::getFirstName() const {
		return firstName;
	}
	/**
	 * Gets the last name
	 *
	 * Precondition: None
	 * Postcondition: None
	 */
	const std::string& StudentGrade::getLastName() const {
		return lastName;
	}
	/**
	 * Gets the grade value
	 *
	 * Precondition: None
	 * Postcondition: None
	 */
	int StudentGrade::getGrade() const {
		return grade;
	}
}

