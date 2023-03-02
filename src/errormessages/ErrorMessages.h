/*
 * The error messages for the application
 */

#ifndef SRC_ERRORMESSAGES_ERRORMESSAGES_H_
#define SRC_ERRORMESSAGES_ERRORMESSAGES_H_

#include <string>

using namespace std;

namespace errormessages {
/**
 * The class for the error messages
 */
class ErrorMessages {
public:
	/**
	 * The constructor for the error messages
	 *
	 * Precondition: None
	 * Postcondition: None
	 */
	ErrorMessages();
	/**
	 * The destructor for the error messages
	 *
	 * Precondition: None
	 * Postcondition: None
	 */
	virtual ~ErrorMessages();
	/**
	 * The error message for the file name to load being empty
	 */
	const static std::string FileNameToLoadCannotBeEmpty;
	/**
	 * The error message for the file name to save being empty
	 */
	const static std::string FileNameToSaveCannotBeEmpty;
	/**
	 * The error message for the first name being empty
	 */
	const static std::string FirstNameForStudentGradeCannotBeEmpty;
	/**
	 * The error message for the last name being empty
	 */
	const static std::string LastNameForStudentGradeCannotBeEmpty;
	/**
	 * The error message for the grade being less than zero
	 */
	const static std::string GradeValueForStudentGradeCannotBeLessThanZero;
};
}
#endif /* SRC_ERRORMESSAGES_ERRORMESSAGES_H_ */

