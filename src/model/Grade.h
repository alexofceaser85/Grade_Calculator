/*
 * Grade.h
 *
 *  Created on: Feb 25, 2023
 *      Author: adecesa1
 */

#ifndef SRC_MODEL_GRADE_H_
#define SRC_MODEL_GRADE_H_

#include <iostream>
using namespace std;

using namespace std;

namespace model {
	class Grade {
		private:
			std::string firstName;
			std::string lastName;
			int grade;
		public:
			Grade();
			Grade(const std::string& firstName, const std::string& lastName, int grade);
			virtual ~Grade();

			const std::string& getFirstName() const;
			const std::string& getLastName() const;
			int getGrade() const;
		};
}

#endif /* SRC_MODEL_GRADE_H_ */
