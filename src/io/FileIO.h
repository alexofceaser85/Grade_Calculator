/*
 * Holds the file IO operations for the application
 */

#ifndef SRC_IO_FILEIO_H_
#define SRC_IO_FILEIO_H_

#include <StudentGrade.h>
#include <vector>
#include <string>

using namespace std;
using namespace model;

namespace io {
/**
 * The class for the file IO operations
 */
class FileIO {
public:
	/**
	 * Loads the grade information from the specified file
	 *
	 * Precondition: filename.isEmpty() == false
	 * Postcondition: None
	 *
	 * Param: filename The file name to load from
	 *
	 * Return: The grade information from the file
	 */
	static vector<StudentGrade> loadGradesFromFile(string &filename);
	/**
	 * Saves the program output to the specified file
	 *
	 * Precondition: filename.isEmpty() == false
	 * Postcondition: None
	 *
	 * Param: filename the name of the file to save to
	 * Param: data the data to save
	 */
	static void saveFileOutput(string &filename, string &fileContents);
};
}
#endif /* SRC_IO_FILEIO_H_ */
