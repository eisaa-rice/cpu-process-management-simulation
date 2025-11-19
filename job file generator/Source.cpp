// Source.cpp
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

struct Job {
	char jobType; // A B C D
	int processingTime;
	int typeNumber;
	int jobNumber;
	int arrivalTime;
	int waitTime = 0;
};
const int jobSize = sizeof(Job); // 24

int main() {
	fstream randomJobFile("jobs.dat", ios::in | ios::out | ios::trunc | ios::binary);
	if (!randomJobFile) {
		cerr << "jobs.dat could not be opened" << endl;
		return -1;
	}

	fstream organizedJobFile("org.dat", ios::in | ios::out | ios::trunc | ios::binary);
	if (!organizedJobFile) {
		cerr << "org.dat could not be opened" << endl;
		return -1;
	}

	// 5570 total jobs
	Job emptyJob = { ' ', 0, 0, 0, 0, 0 };

	for (int i = 0; i < 5570; i++) {
		randomJobFile.write(reinterpret_cast <const char*>(&emptyJob), jobSize);
	}
	for (int i = 0; i < 5570; i++) {
		organizedJobFile.write(reinterpret_cast <const char*>(&emptyJob), jobSize);
	}

	int jobNumber = 0;

	int A = 1;
	// 2300 type A jobs
	for (int i = 0; i < 2300; i++) {
		static int time = 0;

		emptyJob.jobType = 'A';
		emptyJob.arrivalTime = (((rand() % 3) + 4)) + (time * 5); // 5 +/- 1; 4 5 6
		emptyJob.processingTime = rand() % 5 + 1; // 3 +/- 2; 1 2 3 4 5
		emptyJob.typeNumber = A;
		emptyJob.jobNumber = jobNumber;

		randomJobFile.seekg((static_cast<std::basic_istream<char, std::char_traits<char>>::off_type>(i) * jobSize), ios::beg);
		randomJobFile.write((char*)&emptyJob, jobSize);

		time++; A++; jobNumber++;
	}

	int B = 1;
	// 1700 type B jobs
	for (int i = 2300; i < 4000; i++) {
		static int time = 0;

		emptyJob.jobType = 'B';
		emptyJob.arrivalTime = (((rand() % 3) + 6)) + (time * 7); // 7 +/- 1; 6 7 8
		emptyJob.processingTime = rand() % 9 + 2; // 6 +/- 4; 2 3 4 5 6 7 8 9 10
		emptyJob.typeNumber = B;
		emptyJob.jobNumber = jobNumber;

		randomJobFile.seekg((static_cast<std::basic_istream<char, std::char_traits<char>>::off_type>(i) * jobSize), ios::beg);
		randomJobFile.write((char*)&emptyJob, jobSize);

		time++; B++; jobNumber++;
	}

	int C = 1;
	// 950 type C jobs
	for (int i = 4000; i < 4950; i++) {
		static int time = 0;

		emptyJob.jobType = 'C';
		emptyJob.arrivalTime = ((rand() % 11) + 8) + (time * 13); // 13 +/- 5; 8 9 10 11 12 13 14 15 16 17 18
		emptyJob.processingTime = rand() % 7 + 6; // 9 +/- 3; 6 7 8 9 10 11 12
		emptyJob.typeNumber = C;
		emptyJob.jobNumber = jobNumber;

		randomJobFile.seekg((static_cast<std::basic_istream<char, std::char_traits<char>>::off_type>(i) * jobSize), ios::beg);
		randomJobFile.write((char*)&emptyJob, jobSize);

		time++; C++; jobNumber++;
	}

	int D = 1;
	// 620 type D jobs
	for (int i = 4950; i < 5570; i++) {
		static int time = 0;

		emptyJob.jobType = 'D';
		emptyJob.arrivalTime = ((rand() % 11) + 14) + (time * 19); // 19 +/- 5; 14 15 16 17 18 19 20 21 22 23 24
		emptyJob.processingTime = rand() % 9 + 9; // 13 +/- 4; 9 10 11 12 13 14 15 16 17
		emptyJob.typeNumber = D;
		emptyJob.jobNumber = jobNumber;

		randomJobFile.seekg((static_cast<std::basic_istream<char, std::char_traits<char>>::off_type>(i) * jobSize), ios::beg);
		randomJobFile.write((char*)&emptyJob, jobSize);

		time++; D++; jobNumber++;
	}

	// change from write to read
	randomJobFile.seekg(0, ios::end);

	// order by arrival time (lowest to highest) and if tied by prio (highest to lowest)
	int write = 0;

	// pain.
	for (int i = 1; i < 13000; i++) {
		for (int j = 5569; j > -1; j--) { // reverse linear search 
			randomJobFile.seekg((static_cast<std::basic_istream<char, std::char_traits<char>>::off_type>(j) * jobSize), ios::beg);
			randomJobFile.read((char*)&emptyJob, jobSize);

			if (emptyJob.arrivalTime == i) {
				organizedJobFile.seekg((static_cast<std::basic_istream<char, std::char_traits<char>>::off_type>(write) * jobSize), ios::beg);
				organizedJobFile.write((char*)&emptyJob, jobSize);

				emptyJob = { ' ', 0, 0, 0, 0, 0 }; // reset for next

				write++;
			}
		}
	}

	// change from write to read
	organizedJobFile.seekg(0, ios::end);

	// display the list
	for (int i = 0; i < 5570; i++) {
		organizedJobFile.seekg((static_cast<std::basic_istream<char, std::char_traits<char>>::off_type>(i) * jobSize), ios::beg);
		organizedJobFile.read((char*)&emptyJob, jobSize);

		cout << left << setw(2) << setfill(' ') << emptyJob.jobType << left << setw(20) << setfill(' ') << emptyJob.arrivalTime << left << setw(20) << setfill(' ') << emptyJob.processingTime << endl;
	}

	// bye bye
	randomJobFile.close();
	organizedJobFile.close();

	return 0;
}