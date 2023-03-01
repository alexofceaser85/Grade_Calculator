/*
 * IncludesTest.cpp
 *
 *  Created on: Feb 28, 2023
 *      Author: adecesa1
 */

#include "ApplicationSettings.h"

namespace settings {
ApplicationSettings::ApplicationSettings() {
	// TODO Auto-generated constructor stub

}

ApplicationSettings::~ApplicationSettings() {
	// TODO Auto-generated destructor stub
}

const char ApplicationSettings::GradeLetters[5] = {'A', 'B', 'C', 'D', 'F'};
const int ApplicationSettings::MinimumGradeValues[5] = {90, 80, 70, 60, 0};
const int ApplicationSettings::MaximumGradeValues[5] = {100, 89, 79, 69, 59};

}
