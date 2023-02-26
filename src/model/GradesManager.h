/*
 * GradesManager.h
 *
 *  Created on: Feb 25, 2023
 *      Author: adecesa1
 */

#ifndef SRC_MODEL_GRADESMANAGER_H_
#define SRC_MODEL_GRADESMANAGER_H_

#include "Grade.h"

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
		};
#endif /* SRC_MODEL_GRADESMANAGER_H_ */
}
