/*
 * The settings for the application
 */

#ifndef SRC_SETTINGS_APPLICATIONSETTINGS_H_
#define SRC_SETTINGS_APPLICATIONSETTINGS_H_

#include <string>

using namespace std;

namespace settings {
/**
 * The class holding the settings for the application
 */
class ApplicationSettings {
public:
	/**
	 * The constructor for the application settings
	 */
	ApplicationSettings();
	/**
	 * The destructor for the application settings
	 */
	virtual ~ApplicationSettings();

	/**
	 * The default number of columns
	 */
	const static int DefaultNumberOfColumns = 4;
	/**
	 * The default column width
	 */
	const static int DefaultColumnWidth = 20;

	/**
	 * The default display grade with output
	 */
	const static bool DefaultDisplayGradeWithOutput = false;
	/**
	 * The default display histogram with output
	 */
	const static bool DefaultDisplayHistogramWithOutput = false;
	/**
	 * The default sort student grades by grade
	 */
	const static bool DefaultSortStudentGradesByGrade = false;

	/**
	 * The grade letters
	 */
	static const char GradeLetters[5];
	/**
	 * The size of the grade letters
	 */
	static const int GradeLettersSize = sizeof(GradeLetters) / sizeof(char);
	/**
	 * The minimum grade values
	 */
	static const int MinimumGradeValues[5];
	/**
	 * The maximum grade values
	 */
	static const int MaximumGradeValues[5];
	/**
	 * The usage statement
	 */
	static const std::string &UsageStatement;
};
}
#endif /* SRC_SETTINGS_APPLICATIONSETTINGS_H_ */
