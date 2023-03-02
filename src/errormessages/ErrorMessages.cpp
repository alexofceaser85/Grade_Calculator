#include "ErrorMessages.h"
#include <string>

using namespace std;

namespace errormessages {

ErrorMessages::ErrorMessages() {

}

ErrorMessages::~ErrorMessages() {

}

const std::string ErrorMessages::FileNameToLoadCannotBeEmpty =
		"The file name to load cannot be empty";

const std::string ErrorMessages::FileNameToSaveCannotBeEmpty =
		"The file name to save cannot be empty";

const std::string ErrorMessages::FirstNameForStudentGradeCannotBeEmpty =
		"The first name for student cannot be empty";

const std::string ErrorMessages::LastNameForStudentGradeCannotBeEmpty =
		"The last name for student cannot be empty";

const std::string ErrorMessages::GradeValueForStudentGradeCannotBeLessThanZero =
		"The grade value for student cannot be less than zero";
}
