/*
 * GradesManager.h
 *
 *  Created on: Feb 25, 2023
 *      Author: adecesa1
 */

#ifndef SRC_MODEL_GRADESMANAGER_H_
#define SRC_MODEL_GRADESMANAGER_H_

#include <StudentGrade.h>
#include <algorithm>
#include <vector>
using namespace std;

namespace model {
	/**
	 * The manager for the grades
	 */
	class GradesManager {
		private :
			vector<StudentGrade> grades;
		public:
			/**
			 * The constructor for the grades manager
			 *
			 * Precondition: None
			 * Postcondition: None
			 */
			GradesManager();
			/**
			 * The destructor for the grades manager
			 *
			 * Precondition: None
			 * Postcondition: None
			 */
			virtual ~GradesManager();

			/**
			 * Adds a grade
			 *
			 * Precondition: None
			 * Postcondition: The grade is added
			 *
			 * Param: grade The grade to add
			 */
			void add(StudentGrade& grade);
			/**
			 * Gets the grades sorted by last name
			 *
			 * Precondition: None
			 * Postcondition: None
			 *
			 * Return: The grades sorted by last name
			 */
			vector<StudentGrade> getGradesSortedByLastName() const;
			/**
			 * Gets the grades sorted by grade value
			 *
			 * Precondition: None
			 * Postcondition: None
			 *
			 * Return: The grades sorted by grade value
			 */
			vector<StudentGrade> getGradesSortedByGradeValue() const;
			/**
			 * Loads the grades from file
			 *
			 * Precondition: None
			 * Postcondition: The grades from file are added
			 *
			 * Param: filename The file name to load from
			 */
			void loadFromFile(std::string& filename);
			/**
			 * Saves the grades to a file
			 *
			 * Precondition: None
			 * Postcondition: None
			 *
			 * Param: filename the name of the file to save to
			 * Param: data the data to save
			 */
			void saveGradesData(std::string& filename, std::string& data);
		};

		/**
		 * Compares the grades by name
		 *
		 * Precondition: None
		 * Postcondition: None
		 *
		 * Param: firstGrade The first grade of the comparison
		 * Param: secondGrade The second grade of the comparison
		 *
		 * Return: The grade comparison
		 */
		bool compareByName (const StudentGrade &firstGrade, const StudentGrade &secondGrade);
		/**
		 * Compares the grades by grade value
		 *
		 * Precondition: None
		 * Postcondition: None
		 *
		 * Param: firstGrade The first grade of the comparison
		 * Param: secondGrade The second grade of the comparison
		 *
		 * Return: The grade comparison
		 */
		bool compareByGrade (const StudentGrade &firstGrade, const StudentGrade &secondGrade);
	}

#endif /* SRC_MODEL_GRADESMANAGER_H_ */
