/*
 * Holds the information for the Grade
 */

#ifndef SRC_MODEL_STUDENTGRADE_H_
#define SRC_MODEL_STUDENTGRADE_H_

#include <iostream>
using namespace std;

using namespace std;

namespace model {
/**
 * The class that holds the grade information
 */
class StudentGrade {
private:
	std::string firstName;
	std::string lastName;
	int grade;
public:
	/**
	 * The zero parameter constructor for the grade
	 *
	 * Precondition: None
	 * Postcondition: None
	 */
	StudentGrade();
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
	StudentGrade(const std::string &firstName, const std::string &lastName,
			int grade);
	/**
	 * The destructor for the student grade
	 *
	 * Precondition: None
	 * Postcondition: None
	 */
	virtual ~StudentGrade();
	/**
	 * Gets the first name
	 *
	 * Precondition: None
	 * Postcondition: None
	 *
	 * Return: The first name
	 */
	const std::string& getFirstName() const;
	/**
	 * Gets the last name
	 *
	 * Precondition: None
	 * Postcondition: None
	 *
	 * Return: The last name
	 */
	const std::string& getLastName() const;
	/**
	 * Gets the grade value
	 *
	 * Precondition: None
	 * Postcondition: None
	 *
	 * Return: The grade value
	 */
	int getGrade() const;
};
}

#endif /* SRC_MODEL_STUDENTGRADE_H_ */
