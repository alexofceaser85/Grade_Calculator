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

namespace model {
	class Grade {
		private:
			std::string firstName;
			std::string lastName;
			int grade;
		public:
			Grade();
			Grade(const string& firstName, const string& lastName, int grade);
			virtual ~Grade();

			const string& getFirstName() const;
			const string& getLastName() const;
			int getGrade() const;
			bool operator< (const Grade &other) const;
		};
}

#endif /* SRC_MODEL_GRADE_H_ */
