#include "Class.h"
#include "CallCSV.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <array>

using namespace std;
int main() {
	CallCSV callCSV;
	callCSV.CallClassroom();
	callCSV.CallClassroom_Blacklist();
	callCSV.CallLecture();
	callCSV.CallLecture_has_Student();
	callCSV.CallLecturer();
	callCSV.CallLecturer_Blacklist();
	callCSV.CallStudentGroup();
	callCSV.CallStudentGroup_Blacklist();
	Class thisclass;
	thisclass.CreateTimeTable();
	return 0;
}

