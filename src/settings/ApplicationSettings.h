/*
 * IncludesTest.h
 *
 *  Created on: Feb 28, 2023
 *      Author: adecesa1
 */

#ifndef SRC_SETTINGS_APPLICATIONSETTINGS_H_
#define SRC_SETTINGS_APPLICATIONSETTINGS_H_

namespace settings {
class ApplicationSettings {
public:
	ApplicationSettings();
	virtual ~ApplicationSettings();

	const static int DefaultNumberOfColumns = 4;
	const static int DefaultColumnWidth = 20;

	const static bool DefaultDisplayGradeWithOutput = false;
	const static bool DefaultDisplayHistogramWithOutput = false;
	const static bool DefaultSortStudentGradesByGrade = false;

	static const char GradeLetters[5];
	static const int GradeLettersSize = sizeof(GradeLetters) / sizeof(char);
	static const int MinimumGradeValues[5];
	static const int MaximumGradeValues[5];
};
}
#endif /* SRC_SETTINGS_APPLICATIONSETTINGS_H_ */
