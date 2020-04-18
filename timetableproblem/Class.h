#pragma once
#include "CallCSV.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <array>
#include <iomanip>
#include <vector>

using namespace std;

class Class {
	public:
		void CreateTimeTable() {
			CallCSV *callCSV = new CallCSV;
			string final_idLectureObject[107];
			string final_idLectureObject_placed[107];
			string final_idLecturer[107];
			string final_idLecturer_placed[107];
			string final_idLecture[107];
			string final_idLecture_Lecture_has_StudentGroup[134];
			string final_idStudentGroup_Lecture_has_StudentGroup[134];
			string final_idStudentGroup_Lecture_has_StudentGroup_placed[134];
			string final_idClassroom[10];
			string final_idClassroom_placed[10];
			string final_idDayAndTimeLot[30];
			final_idDayAndTimeLot[0] = "1_1";
			final_idDayAndTimeLot[1] = "1_2";
			final_idDayAndTimeLot[2] = "1_3";
			final_idDayAndTimeLot[3] = "1_4";
			final_idDayAndTimeLot[4] = "1_5";
			final_idDayAndTimeLot[5] = "1_6";
			final_idDayAndTimeLot[6] = "2_1";
			final_idDayAndTimeLot[7] = "2_2";
			final_idDayAndTimeLot[8] = "2_3";
			final_idDayAndTimeLot[9] = "2_4";
			final_idDayAndTimeLot[10] = "2_5";
			final_idDayAndTimeLot[11] = "2_6";
			final_idDayAndTimeLot[12] = "3_1";
			final_idDayAndTimeLot[13] = "3_2";
			final_idDayAndTimeLot[14] = "3_3";
			final_idDayAndTimeLot[15] = "3_4";
			final_idDayAndTimeLot[16] = "3_5";
			final_idDayAndTimeLot[17] = "3_6";
			final_idDayAndTimeLot[18] = "4_1";
			final_idDayAndTimeLot[19] = "4_2";
			final_idDayAndTimeLot[20] = "4_3";
			final_idDayAndTimeLot[21] = "4_4";
			final_idDayAndTimeLot[22] = "4_5";
			final_idDayAndTimeLot[23] = "4_6";
			final_idDayAndTimeLot[24] = "5_1";
			final_idDayAndTimeLot[25] = "5_2";
			final_idDayAndTimeLot[26] = "5_3";
			final_idDayAndTimeLot[27] = "5_4";
			final_idDayAndTimeLot[28] = "5_5";
			final_idDayAndTimeLot[29] = "5_6";
			for (int i = 1; i < 107; i++) {
				final_idLectureObject[i] = callCSV->getLecture_idLectureObject(i);
				final_idLecturer[i] = callCSV->getLecture_idLecturer(i);
				final_idLecture[i] = callCSV->getLecture_idLecture(i);
			}
			for (int i = 1; i < 134; i++) {
				final_idLecture_Lecture_has_StudentGroup[i] = callCSV->getLecture_has_StudentGroup_idLecture(i);
				final_idStudentGroup_Lecture_has_StudentGroup[i] = callCSV->getLecture_has_StudentGroup_idStudentGroup(i);
			}
			for (int i = 1; i < 10; i++) {
				final_idClassroom[i] = callCSV->getClassroom_idClassroom(i);
			}
			int k = 1;
			int c = 1;
			int sG = 1;
			string gesuchtesG;
			string gesuchteK;
			bool veraendert = false;
			bool sGzugewiesen = false;
			for (int j = 0; j < 30; j++) {
				k = 1;
				c = 1;
				sG = 1;
				while ((final_idLectureObject_placed[k] == "placed" && k < 106)) {
					veraendert = false;
					k++;
					veraendert = true;
				}
				while ((final_idLectureObject_placed[k] != "placed") && (final_idLecturer_placed[k] != "placed") && (final_idClassroom_placed[c] != "placed") && (final_idStudentGroup_Lecture_has_StudentGroup_placed[sG] != "placed")) {
				//while ((final_idLectureObject_placed[k] != "placed") && (final_idLecturer_placed[k] != "placed") && (final_idClassroom_placed[c] != "placed")) {
					final_idDayAndTimeLot[j] = final_idDayAndTimeLot[j] + " LectureObject:" + final_idLectureObject[k] + " mit Lecturer:" + final_idLecturer[k] + " in Classroom:" + final_idClassroom[c] + '\n';
					//cout << final_idDayAndTimeLot[j] << '\n';
					final_idLectureObject_placed[k] = "placed";
					for (int m = 0; m < 134; m++) {
						if (final_idLecture_Lecture_has_StudentGroup[m]._Equal(final_idLecture[k]) && sGzugewiesen == false){
							sGzugewiesen = true;
							sG = m;
						}
						if (final_idLecture_Lecture_has_StudentGroup[m]._Equal(final_idLecture[k])) {
							final_idDayAndTimeLot[j] = final_idDayAndTimeLot[j] + " mit StudentGroup:" + final_idStudentGroup_Lecture_has_StudentGroup[m] + '\n';
							gesuchtesG = final_idStudentGroup_Lecture_has_StudentGroup[m];
							for (int o = 0; o < 134; o++) {
								if (final_idStudentGroup_Lecture_has_StudentGroup[o]._Equal(gesuchtesG)) {
									final_idStudentGroup_Lecture_has_StudentGroup_placed[o] = "placed";
								}
							}
							final_idStudentGroup_Lecture_has_StudentGroup_placed[m] = "placed";
							cout << final_idDayAndTimeLot[j] << '\n';
						}

					}
					sGzugewiesen = false;
					final_idClassroom_placed[c] = "placed";
					for (int l = 0; l < 107; l++) {
						if (final_idLecturer[l]._Equal(final_idLecturer[k])) {
							final_idLecturer_placed[l] = "placed";
						}
					}
					if (k < 106) {
						k++;
					}
					if (c < 9) {
						c++;
					}
					while (((final_idLectureObject_placed[k] != "placed") == true) && ((final_idLecturer_placed[k] != "placed") == false) && (k < 106)) {
						k++;
					}
					while (((final_idLectureObject_placed[k] == "placed") == true) && ((final_idLecturer_placed[k] == "placed") == false) && (k < 106)) {
						k++;
					}
					while (((final_idStudentGroup_Lecture_has_StudentGroup_placed[sG] == "placed") && (sG < 133) == true)) {
						sG++;
						if (sG == 134) {
							sG = 1;
						}

					}
					gesuchtesG = "";
				}
				for (int i = 0; i < 107; i++) {
					final_idLecturer_placed[i] = "";
				}
				for (int i = 0; i < 10; i++) {
					final_idClassroom_placed[i] = "";
				}
				for (int i = 0; i < 134; i++) {
					final_idStudentGroup_Lecture_has_StudentGroup_placed[i] == "";
				}
				if (veraendert == false) {
					k = 1;
				}
				cout << final_idDayAndTimeLot[j] << '\n';
			}
			for (int i = 0; i < 30; i++) {
				writeToFile("felixhahn_timetableproblem.txt", final_idDayAndTimeLot[i]);
			}
			delete callCSV;
		};

		void writeToFile(std::string file_name, std::string field_one) {
			std::ofstream file;
			file.open(file_name, std::ios_base::app);
			file << field_one << std::endl;
			file.close();
		};
};

