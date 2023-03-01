/*
 * ErrorMessages.cpp
 *
 *  Created on: Feb 28, 2023
 *      Author: adecesa1
 */

#include "ErrorMessages.h"
#include <string>

using namespace std;

ErrorMessages::ErrorMessages() {
	const static std::string FileNameToLoadCannotBeNull = "The file name to load cannot be null";
}

ErrorMessages::~ErrorMessages() {
	// TODO Auto-generated destructor stub
}

