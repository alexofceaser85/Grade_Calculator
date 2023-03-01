/*
 * ErrorMessages.cpp
 *
 *  Created on: Feb 28, 2023
 *      Author: adecesa1
 */

#include "ErrorMessages.h"
#include <string>

using namespace std;

namespace errormessages {

/**
 * The constructor for the error messages
 *
 * Precondition: None
 * Postcondition: None
 */
ErrorMessages::ErrorMessages() {

}

/**
 * The destructor for the error messages
 *
 * Precondition: None
 * Postcondition: None
 */
ErrorMessages::~ErrorMessages() {

}

/**
 * The error message for the file name to load being empty
 */
const std::string ErrorMessages::FileNameToLoadCannotBeEmpty = "The file name to load cannot be empty";
/**
 * The error message for the file name to save being empty
 */
const std::string ErrorMessages::FileNameToSaveCannotBeEmpty = "The file name to save cannot be empty";
/**
 * The error message for the first name being empty
 */
const std::string ErrorMessages::FirstNameForStudentGradeCannotBeEmpty = "The first name for student cannot be empty";
/**
 * The error message for the last name being empty
 */
const std::string ErrorMessages::LastNameForStudentGradeCannotBeEmpty = "The last name for student cannot be empty";
/**
 * The error message for the grade being less than zero
 */
const std::string ErrorMessages::GradeValueForStudentGradeCannotBeLessThanZero = "The grade value for student cannot be less than zero";
}
