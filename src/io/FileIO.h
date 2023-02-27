/*
 * FileIO.h
 *
 *  Created on: Feb 27, 2023
 *      Author: adecesa1
 */

#ifndef SRC_IO_FILEIO_H_
#define SRC_IO_FILEIO_H_

#include "Grade.h"
#include <vector>
#include <string>

using namespace std;
using namespace model;

namespace io {
	class FileIO {
		public:
			static vector<Grade> loadGradesFromFile(string filename);
			static void saveFileOutput(string filename, string fileContents);
		};
	}
#endif /* SRC_IO_FILEIO_H_ */
