#include "StudentGrade.h"
#include "ErrorMessages.h"
using namespace std;
using namespace errormessages;

namespace model {

StudentGrade::StudentGrade() {
	this->firstName = std::string();
	this->lastName = std::string();
	this->grade = 0;
}

StudentGrade::StudentGrade(const std::string &firstName,
		const std::string &lastName, int grade) {
	if (firstName.empty()) {
		throw invalid_argument(
				ErrorMessages::FirstNameForStudentGradeCannotBeEmpty);
	}

	if (lastName.empty()) {
		throw invalid_argument(
				ErrorMessages::LastNameForStudentGradeCannotBeEmpty);
	}

	if (grade < 0) {
		throw invalid_argument(
				ErrorMessages::GradeValueForStudentGradeCannotBeLessThanZero);
	}

	this->firstName = firstName;
	this->lastName = lastName;
	this->grade = grade;
}

StudentGrade::~StudentGrade() {

}

const std::string& StudentGrade::getFirstName() const {
	return firstName;
}

const std::string& StudentGrade::getLastName() const {
	return lastName;
}

int StudentGrade::getGrade() const {
	return grade;
}
}

