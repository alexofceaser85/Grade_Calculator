/*
 * GradesManager.h
 *
 *  Created on: Feb 25, 2023
 *      Author: adecesa1
 */

#ifndef SRC_MODEL_GRADESMANAGER_H_
#define SRC_MODEL_GRADESMANAGER_H_

#include "Grade.h"
#include <algorithm>
#include <vector>
using namespace std;

namespace model {
	class GradesManager {
		private :
			vector<Grade> grades;
		public:
			GradesManager();
			virtual ~GradesManager();

			void add(Grade& grade);
			vector<Grade> getGrades() const;
			vector<Grade> getGradesSortedByLastName() const;
			vector<Grade> getGradesSortedByGradeValue() const;
			void loadFromFile(string filename);
			void saveGradesData(string filename, string data);
		};

		bool compareByName (const Grade &a, const Grade &b);
		bool compareByGrade (const Grade &a, const Grade &b);
	}

#endif /* SRC_MODEL_GRADESMANAGER_H_ */
