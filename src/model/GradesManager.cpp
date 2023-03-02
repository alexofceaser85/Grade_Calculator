#include <StudentGrade.h>
#include "FileIO.h"
#include "GradesManager.h"

using namespace std;
using namespace io;

namespace model {

GradesManager::GradesManager() {
	this->grades = vector<StudentGrade>();
}

GradesManager::~GradesManager() {

}

bool compareByName(const StudentGrade &firstGrade,
		const StudentGrade &secondGrade) {
	if (firstGrade.getLastName() == secondGrade.getLastName()) {
		return firstGrade.getFirstName() < secondGrade.getFirstName();
	}
	return firstGrade.getLastName() < secondGrade.getLastName();
}

bool compareByGrade(const StudentGrade &firstGrade,
		const StudentGrade &secondGrade) {
	if (firstGrade.getGrade() == secondGrade.getGrade()) {
		return compareByName(firstGrade, secondGrade);
	}
	return firstGrade.getGrade() > secondGrade.getGrade();
}

void GradesManager::add(StudentGrade &grade) {
	grades.push_back(grade);
}

vector<StudentGrade> GradesManager::getGradesSortedByLastName() const {
	vector<StudentGrade> sortableGrades = this->grades;
	std::sort(sortableGrades.begin(), sortableGrades.end(), compareByName);
	return sortableGrades;
}

vector<StudentGrade> GradesManager::getGradesSortedByGradeValue() const {
	vector<StudentGrade> sortableGrades = this->grades;
	std::sort(sortableGrades.begin(), sortableGrades.end(), compareByGrade);
	return sortableGrades;
}

void GradesManager::loadFromFile(std::string &filename) {
	vector<StudentGrade> loadedGrades = FileIO::loadGradesFromFile(filename);

	for (StudentGrade grade : loadedGrades) {
		this->grades.push_back(grade);
	}
}

void GradesManager::saveGradesData(std::string &filename, std::string &data) {
	FileIO::saveFileOutput(filename, data);
}
}
