#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <array>
using namespace std;

class CallCSV {
	public:
		string Classroom_idClassroom[10];
		string Classroom_Name[10];
		string Classroom_Capacity[10];

		string Classroom_Blacklist_idDay[11];
		string Classroom_Blacklist_idTimeSlot[11];
		string Classroom_Blacklist_idClassroom[11];

		string Lecture_idLectureObject[107];
		string Lecture_idLecture[107];
		string Lecture_idLecturer[107];

		string Lecture_has_StudentGroup_idLecture[134];
		string Lecture_has_StudentGroup_idStudentGroup[134];
		string Lecture_has_StudentGroup_numParticipants[134];

		string Lecturer_idLecturer[31];
		string Lecturer_Name[31];

		string Lecturer_Blacklist_idDay[31];
		string Lecturer_Blacklist_idTimeSlot[31];
		string Lecturer_Blacklist_idLecturer[31];

		string StudentGroup_idStudentGroup[31];

		string StudentGroup_Blacklist_idDay[9];
		string StudentGroup_Blacklist_idTimeSlot[9];
		string StudentGroup_Blacklist_idStudentGroup[9];

		void CallClassroom() {
			ifstream Classroom;
			Classroom.open("Classroom.csv");
			cout << "TABLE Classroom\n----------------------" << '\n';
			while (Classroom.good()) {
				for (int i = 1; i < 10; i++) {
					getline(Classroom, Classroom_idClassroom[i], ';');
					getline(Classroom, Classroom_Name[i], ';');
					getline(Classroom, Classroom_Capacity[i], '\n');
					cout << "ID-Classroom: " << Classroom_idClassroom[i] << '\n';
					cout << "Name: " << Classroom_Name[i] << '\n';
					cout << "Capacity: " << Classroom_Capacity[i] << '\n';
					cout << "----------------------" << '\n';
				}
			}
			Classroom.close();
		};

		void CallClassroom_Blacklist() {
			ifstream Classroom_Blacklist;
			Classroom_Blacklist.open("Classroom_Blacklist.csv");
			cout << "TABLE Classroom_Blacklist\n----------------------" << '\n';
			while (Classroom_Blacklist.good()) {
				for (int i = 1; i < 11; i++) {
					getline(Classroom_Blacklist, Classroom_Blacklist_idDay[i], ';');
					getline(Classroom_Blacklist, Classroom_Blacklist_idTimeSlot[i], ';');
					getline(Classroom_Blacklist, Classroom_Blacklist_idClassroom[i], '\n');
					cout << "ID-Day: " << Classroom_Blacklist_idDay[i] << '\n';
					cout << "ID-Time: " << Classroom_Blacklist_idTimeSlot[i] << '\n';
					cout << "ID-Classroom: " << Classroom_Blacklist_idClassroom[i] << '\n';
					cout << "----------------------" << '\n';
				}
			}
			Classroom_Blacklist.close();
		};

		void CallLecture() {
			ifstream Lecture;
			Lecture.open("Lecture.csv");
			cout << "TABLE Lecture\n----------------------" << '\n';
			while (Lecture.good()) {
				for (int i = 1; i < 107; i++) {
					getline(Lecture, Lecture_idLectureObject[i], ';');
					getline(Lecture, Lecture_idLecture[i], ';');
					getline(Lecture, Lecture_idLecturer[i], '\n');
					cout << "ID-LectureObject: " << Lecture_idLectureObject[i] << '\n';
					cout << "ID-Lecture: " << Lecture_idLecture[i] << '\n';
					cout << "ID-Lecturer: " << Lecture_idLecturer[i] << '\n';
					cout << "----------------------" << '\n';
				}
			}
			Lecture.close();
		};

		void CallLecture_has_Student() {
			ifstream Lecture_has_StudentGroup;
			Lecture_has_StudentGroup.open("Lecture_has_StudentGroup.csv");
			cout << "TABLE Lecture_has_StudentGroup\n----------------------" << '\n';
			while (Lecture_has_StudentGroup.good()) {
				for (int i = 1; i < 134; i++) {
					getline(Lecture_has_StudentGroup, Lecture_has_StudentGroup_idLecture[i], ';');
					getline(Lecture_has_StudentGroup, Lecture_has_StudentGroup_idStudentGroup[i], ';');
					getline(Lecture_has_StudentGroup, Lecture_has_StudentGroup_numParticipants[i], '\n');
					cout << "ID-Lecture: " << Lecture_has_StudentGroup_idLecture[i] << '\n';
					cout << "StudentGroup: " << Lecture_has_StudentGroup_idStudentGroup[i] << '\n';
					cout << "Participants: " << Lecture_has_StudentGroup_numParticipants[i] << '\n';
					cout << "----------------------" << '\n';
				}
			}
			Lecture_has_StudentGroup.close();
		};

		void CallLecturer() {
			ifstream Lecturer;
			Lecturer.open("Lecturer.csv");
			cout << "TABLE Lecturer\n----------------------" << '\n';
			while (Lecturer.good()) {
				for (int i = 1; i < 31; i++) {
					getline(Lecturer, Lecturer_idLecturer[i], ';');
					getline(Lecturer, Lecturer_Name[i], '\n');
					cout << "ID-Lecture: " << Lecturer_idLecturer[i] << '\n';
					cout << "Participants: " << Lecturer_Name[i] << '\n';
					cout << "----------------------" << '\n';
				}
			}
			Lecturer.close();
		};

		void CallLecturer_Blacklist() {
			ifstream Lecturer_Blacklist;
			Lecturer_Blacklist.open("Lecturer_Blacklist.csv");
			cout << "TABLE Lecturer_Blacklist\n----------------------" << '\n';
			while (Lecturer_Blacklist.good()) {
				for (int i = 1; i < 31; i++) {
					getline(Lecturer_Blacklist, Lecturer_Blacklist_idDay[i], ';');
					getline(Lecturer_Blacklist, Lecturer_Blacklist_idTimeSlot[i], ';');
					getline(Lecturer_Blacklist, Lecturer_Blacklist_idLecturer[i], '\n');
					cout << "ID-Lecture: " << Lecturer_Blacklist_idDay[i] << '\n';
					cout << "ID-Lecture: " << Lecturer_Blacklist_idTimeSlot[i] << '\n';
					cout << "Participants: " << Lecturer_Blacklist_idLecturer[i] << '\n';
					cout << "----------------------" << '\n';
				}
			}
			Lecturer_Blacklist.close();
		};

		void CallStudentGroup() {
			ifstream StudentGroup;
			StudentGroup.open("StudentGroup.csv");
			cout << "TABLE StudentGroup\n----------------------" << '\n';
			while (StudentGroup.good()) {
				for (int i = 1; i < 31; i++) {
					getline(StudentGroup, StudentGroup_idStudentGroup[i], '\n');
					cout << "ID-StudentGroup: " << StudentGroup_idStudentGroup[i] << '\n';
					cout << "----------------------" << '\n';
				}
			}
			StudentGroup.close();
		};

		void CallStudentGroup_Blacklist() {
			ifstream StudentGroup_Blacklist;
			StudentGroup_Blacklist.open("StudentGroup_Blacklist.csv");
			cout << "TABLE StudentGroup_Blacklist\n----------------------" << '\n';
			while (StudentGroup_Blacklist.good()) {
				for (int i = 1; i < 9; i++) {
					getline(StudentGroup_Blacklist, StudentGroup_Blacklist_idDay[i], ';');
					getline(StudentGroup_Blacklist, StudentGroup_Blacklist_idTimeSlot[i], ';');
					getline(StudentGroup_Blacklist, StudentGroup_Blacklist_idStudentGroup[i], '\n');
					cout << "ID-Day: " << StudentGroup_Blacklist_idDay[i] << '\n';
					cout << "ID-TimeSlot: " << StudentGroup_Blacklist_idTimeSlot[i] << '\n';
					cout << "ID-StudentGroup: " << StudentGroup_Blacklist_idStudentGroup[i] << '\n';
					cout << "----------------------" << '\n';
				}
			}
			StudentGroup_Blacklist.close();
		};

		auto getClassroom_idClassroom(int s) {
			ifstream Classroom;
			Classroom.open("Classroom.csv");
			while (Classroom.good()) {
				for (int i = 0; i < 10; i++) {
					getline(Classroom, Classroom_idClassroom[i], ';');
					getline(Classroom, Classroom_Name[i], ';');
					getline(Classroom, Classroom_Capacity[i], '\n');
				}
			}
			Classroom.close();
			return Classroom_idClassroom[s];
		};

		auto getLecture_idLectureObject(int s) {
			ifstream Lecture;
			Lecture.open("Lecture.csv");
			while (Lecture.good()) {
				for (int i = 0; i < 107; i++) {
					getline(Lecture, Lecture_idLectureObject[i], ';');
					getline(Lecture, Lecture_idLecture[i], ';');
					getline(Lecture, Lecture_idLecturer[i], '\n');
				}
			}
			Lecture.close();
			return Lecture_idLectureObject[s];
		};

		auto getLecture_idLecture(int s) {
			ifstream Lecture;
			Lecture.open("Lecture.csv");
			while (Lecture.good()) {
				for (int i = 0; i < 107; i++) {
					getline(Lecture, Lecture_idLectureObject[i], ';');
					getline(Lecture, Lecture_idLecture[i], ';');
					getline(Lecture, Lecture_idLecturer[i], '\n');
				}
			}
			Lecture.close();
			return Lecture_idLecture[s];
		};

		auto getLecture_idLecturer(int s) {
			ifstream Lecture;
			Lecture.open("Lecture.csv");
			while (Lecture.good()) {
				for (int i = 0; i < 107; i++) {
					getline(Lecture, Lecture_idLectureObject[i], ';');
					getline(Lecture, Lecture_idLecture[i], ';');
					getline(Lecture, Lecture_idLecturer[i], '\n');
				}
			}
			Lecture.close();
			return Lecture_idLecturer[s];
		};

		auto getLecture_has_StudentGroup_idLecture(int s) {
			ifstream Lecture_has_StudentGroup;
			Lecture_has_StudentGroup.open("Lecture_has_StudentGroup.csv");
			while (Lecture_has_StudentGroup.good()) {
				for (int i = 1; i < 134; i++) {
					getline(Lecture_has_StudentGroup, Lecture_has_StudentGroup_idLecture[i], ';');
					getline(Lecture_has_StudentGroup, Lecture_has_StudentGroup_idStudentGroup[i], ';');
					getline(Lecture_has_StudentGroup, Lecture_has_StudentGroup_numParticipants[i], '\n');
				}
			}
			Lecture_has_StudentGroup.close();
			return Lecture_has_StudentGroup_idLecture[s];
		}

		auto getLecture_has_StudentGroup_idStudentGroup(int s) {
			ifstream Lecture_has_StudentGroup;
			Lecture_has_StudentGroup.open("Lecture_has_StudentGroup.csv");
			while (Lecture_has_StudentGroup.good()) {
				for (int i = 1; i < 134; i++) {
					getline(Lecture_has_StudentGroup, Lecture_has_StudentGroup_idLecture[i], ';');
					getline(Lecture_has_StudentGroup, Lecture_has_StudentGroup_idStudentGroup[i], ';');
					getline(Lecture_has_StudentGroup, Lecture_has_StudentGroup_numParticipants[i], '\n');
				}
			}
			Lecture_has_StudentGroup.close();
			return Lecture_has_StudentGroup_idStudentGroup[s];
		}
};

