#include <iostream> 

#include <string>

#include <cstring>

class lesson {
public:
	char lesson_name[30];
	double mark;
	int unit;
};

class etelaat_daneshjoo {

public:	
	char ID[30];
	char name[30];  
	char family[30];
	double average;
	int shomaresh_lesson;
	lesson students_mark[10];

};
etelaat_daneshjoo student[100];


int shomaresh_d = 0;
FILE* save_d;
FILE* save_d_check;
using namespace std;                

void main_menu();

int main()
{
	main_menu();
	return 0;
}

void main_menu()
{
	system("cls");

	cout << "                                               " << "____________________Welcome to ISFAHAN UNIVERSITY System >> Menu___________________" << endl;

	cout << endl;

	cout << "************************************************************************************************************************************************************************" << endl;

	cout << endl;

	cout << "\t <1> : Enter Info Student " << endl;

	cout << "\t <2> : Enter Info Lesson " << endl;
	
	cout << "\t <3> : See Average " << endl;

	cout << "\t <4> : Save Your Info " << endl;

	cout << "\t <5> : Load Your Info " << endl;

	cout << "\t <6> : Show Info " << endl;

	cout << "\t <7> : Change Info " << endl;

	cout << "\t <8> : EXIT" << endl;

	cout << endl;

	cout << "\t Your Choice: ";

	char choice;

	cin >> choice;

	if (choice == '1') {

		system("cls");

		cout << "                             " << "____________________Welcome to ISFAHAN UNIVERSITY System >> Menu >> Enter Info Student ___________________" << endl;

		cout << endl;

		cout << "************************************************************************************************************************************************************************" << endl;

		cout << endl;


		cout << "\t Please Enter Your ID: ";

		cin.ignore();

		fgets(student[shomaresh_d].ID, 30, stdin);

		cout << endl << "\t Your First Name: ";

		fgets(student[shomaresh_d].name, 30, stdin);

		cout << endl << "\t Your Last Name: ";

		fgets(student[shomaresh_d].family, 30, stdin);

		if (student[shomaresh_d].name[0] >= 97) {

			student[shomaresh_d].name[0] = student[shomaresh_d].name[0] - 32;
		}

		cout << "                                                        *******************************************************" << endl;


		cout << "                                                             \t        " << "Dear " << student[shomaresh_d].name << endl;

		cout << "                                                             \t        " << "Your Info Saved Seccessfully" << endl;

		cout << "                                                        *******************************************************" << endl;

		cout << endl << endl;

		shomaresh_d += 1;

		cout << "\t For going to Menu Press ENTER ";

		cin.ignore();

		main_menu();


	}

	if (choice == '2') {

		system("cls");

		cout << "                             " << "____________________Welcome to ISFAHAN UNIVERSITY System >> Menu >> Enter Info Lesson ___________________" << endl;

		cout << endl;

		cout << "************************************************************************************************************************************************************************" << endl;

		cout << endl;

		int i;

		etelaat_daneshjoo check_d;

		student[shomaresh_d].shomaresh_lesson = 0;

		cout << "\t Please ENTER Student ID: ";

		cin.ignore();

		fgets(check_d.ID, 30, stdin);

		for (i = 0; i < shomaresh_d; i++) {
			if (strcmp(student[i].ID , check_d.ID)==0) {
				break;
			}
		}

		if (i == shomaresh_d) {
			cout << endl << "\t There isn't This student" << endl << endl;

			cout << "\t Press ENTER For EXIT ";

			cin.ignore();

			exit(0);

			

		}

		cout << endl << "\t Please Enter Lesson Name: ";

		fgets(student[i].students_mark[student[i].shomaresh_lesson].lesson_name, 30, stdin);

		cout << endl << "\t Please ENTER Lesson Unit: ";

		cin >> student[i].students_mark[student[i].shomaresh_lesson].unit;

		cout << endl << "\t Please ENTER Your Mark: ";

		cin >> student[i].students_mark[student[i].shomaresh_lesson].mark;

		student[i].shomaresh_lesson += 1;

		char Edame_entekhab_lesson;

		cout << endl << endl << "\t Do You Want To Add Another Lesson? ";
		
		cin >> Edame_entekhab_lesson;

		while (Edame_entekhab_lesson == 'y' || Edame_entekhab_lesson == 'Y') {

			cout << endl << "\t Please Enter Lesson Name: ";

			cin.ignore();

			fgets(student[i].students_mark[student[i].shomaresh_lesson].lesson_name, 30, stdin);

			cout << endl << "\t Please ENTER Lesson Unit: ";

			cin >> student[i].students_mark[student[i].shomaresh_lesson].unit;

			cout << endl << "\t Please ENTER Your Mark: ";

			cin >> student[i].students_mark[student[i].shomaresh_lesson].mark;

			student[i].shomaresh_lesson += 1;

			cout << endl << endl << "\t Do You Want To Add Another Lesson? ";

			cin >> Edame_entekhab_lesson;

		}

		int  w, unit = 0;

			unit = 0;

			student[i].average = 0;

			for (w = 0; w < student[i].shomaresh_lesson; w++) {

				unit += student[i].students_mark[w].unit;

				student[i].average += student[i].students_mark[w].unit * student[i].students_mark[w].mark;

			}

			student[i].average = student[i].average / unit;


		cout << "\n\t For going to Menu Press ENTER ";

		cin.ignore();

		cin.ignore();

		main_menu();



	}

	if (choice == '3') {

		system("cls");

		cout << "                             " << "____________________Welcome to ISFAHAN UNIVERSITY System >> Menu >> See Average ___________________" << endl;

		cout << endl;

		cout << "************************************************************************************************************************************************************************" << endl;

		cout << endl;


		int j;

		cout << "\t Please ENTER Your ID: ";

		char moadel_dcheck[30];

		cin.ignore();

		fgets(moadel_dcheck, 30, stdin);

		for (j = 0; j < shomaresh_d; j++) {
		
			if (strcmp(student[j].ID, moadel_dcheck) == 0) {

				cout << "\t\t Name: " << student[j].name << endl;
				cout << "\t -----------------------------------------------\n";
				cout << "\t\t Family: " << student[j].family << endl;
				cout << "\t -----------------------------------------------\n";
				cout << "\t\t average: " << student[j].average << endl;
				cout << "\t -----------------------------------------------\n" << endl;

			}

		}

		int average_shomaresh;

		etelaat_daneshjoo average_check;

		fopen_s(&save_d, "save_d.dat", "a+b");

		if (!save_d) {

			cout << "\t File wasn't Found";

		}

		int counter = 0;

		fread(&average_check, sizeof(etelaat_daneshjoo), 1, save_d);

		while (!feof(save_d)) {

			for (average_shomaresh = 0; average_shomaresh < shomaresh_d; average_shomaresh++) {

				if (strcmp(average_check.ID, student[average_shomaresh].ID) == 0 ) {
					break;
				}

			}

			if (average_shomaresh == shomaresh_d) {
				if (strcmp(average_check.ID, moadel_dcheck) == 0) {
					
					cout << "\t\t Name: " << average_check.name << endl;
					cout << "\t -----------------------------------------------\n";
					cout << "\t\t Family: " <<average_check.family<< endl;
					cout << "\t -----------------------------------------------\n";
					cout << "\t\t average: " << average_check.average << endl;
					cout << "\t -----------------------------------------------\n" << endl;
				
				}
				}

			fread(&average_check, sizeof(etelaat_daneshjoo), 1, save_d);


		}

		fclose(save_d);

		cout << "\t For going to Menu Press ENTER ";

		cin.ignore();


		main_menu();

	}

	if (choice == '4') {

		system("cls");

		cout << "                                            " << "____________________Welcome to ISFAHAN UNIVERSITY System >> Menu >> Save Info ___________________" << endl;

		cout << endl;

		cout << "************************************************************************************************************************************************************************" << endl;

		cout << endl;

		cout << "\t Press ENTER For Saving Info ";

		cin.ignore();

		cin.ignore();

		int sh_d;

		etelaat_daneshjoo check_saved;

		fopen_s(&save_d_check, "save_d_check.dat", "a+b");

		if (!save_d_check) {
			cout << "\t File wasn't Found";
			exit(0);
		}



		fopen_s(&save_d, "save_d.dat", "ab");

		if (!save_d) {
			cout << "\t File wasn't Found";
			exit(0);
		}

		for (sh_d = 0; sh_d < shomaresh_d; sh_d++) {
			bool abc = true;
			fread(&check_saved, sizeof(etelaat_daneshjoo), 1, save_d_check);

			while (!feof(save_d_check)) {

				if (strcmp(student[sh_d].ID,check_saved.ID)==0) {

					abc = false;
					
					break;

				}

				fread(&check_saved, sizeof(etelaat_daneshjoo), 1, save_d_check);


			}
			if (abc) {

			fwrite(&student[sh_d], sizeof(etelaat_daneshjoo), 1, save_d);

			}

		}

		fclose(save_d_check);

		fclose(save_d);

		fopen_s(&save_d_check, "save_d_check.dat", "ab");

		if (!save_d_check) {
			cout << "\t File wasn't Found";
			exit(0);
		}


		fopen_s(&save_d, "save_d.dat", "rb");

		if (!save_d) {
			cout << "\t File wasn't Found";
			exit(0);
		}

		fread(&check_saved, sizeof(etelaat_daneshjoo), 1, save_d);

		while (!feof(save_d)) {

			fwrite(&check_saved, sizeof(etelaat_daneshjoo), 1, save_d_check);


			fread(&check_saved, sizeof(etelaat_daneshjoo), 1, save_d);

			}

		fclose(save_d_check);

		fclose(save_d);


		cout << "                                                        *******************************************************" << endl << endl;

		cout << "                                                             \t        " << "Information Saved Seccessfully" << endl << endl;

		cout << "                                                        *******************************************************" << endl;
		cout << "\n\t For going to Menu Press ENTER ";

		cin.ignore();


		main_menu();


	}

	if (choice == '5') {

		system("cls");

		cout << "                                            " << "____________________Welcome to ISFAHAN UNIVERSITY System >> Menu >> Load Info ___________________" << endl;

		cout << endl;

		cout << "************************************************************************************************************************************************************************" << endl;

		cout << endl;

		char checkload_d[30];

		cout << "\t Please ENTER Student ID: ";

		cin.ignore();

		fgets(checkload_d, 30, stdin);

		etelaat_daneshjoo check_load_file;

		fopen_s(&save_d, "save_d.dat", "rb");

		if (!save_d) {

			cout << "\t File wasn't Found";

			exit(0);

		}

		fread(&check_load_file, sizeof(etelaat_daneshjoo), 1, save_d);
		int j = 0;
		while (!feof(save_d)) {

			if (strcmp(check_load_file.ID, checkload_d) == 0) {

				cout << "\n\t ID: " << check_load_file.ID << endl;
				cout << "\t -----------------------------------------------\n" << endl;

				cout << "\t Name: " << check_load_file.name << endl;
				cout << "\t -----------------------------------------------\n" << endl;

				cout << "\t Family: " << check_load_file.family << endl;
				cout << "\t -----------------------------------------------\n" << endl;
				cout << "\t\t\t Lesson Information" << endl;
				cout << "\t -----------------------------------------------" << endl;
				for (j = 0; j < check_load_file.shomaresh_lesson; j++)
				{
					cout << "\t\t\t     Name: " << check_load_file.students_mark[j].lesson_name << endl;
					cout << "\t\t\t     Unit: " << check_load_file.students_mark[j].unit << endl;
					cout << "\t\t\t     Score: " << check_load_file.students_mark[j].mark << endl;
					cout << "\t -----------------------------------------------" << endl;
				}
				cout << "\t\t\t     Average: " << check_load_file.average << endl;
				
			}

			fread(&check_load_file, sizeof(etelaat_daneshjoo), 1, save_d);


		}

		fclose(save_d);       


		cout << "\n\t For going to Menu Press ENTER ";

		cin.ignore();


		main_menu();




	}

	if (choice == '6') {

		system("cls");

		cout << "                             " << "____________________Welcome to ISFAHAN UNIVERSITY System >> Menu >> Show Info ___________________" << endl;

		cout << endl;

		cout << "************************************************************************************************************************************************************************" << endl;

		cout << endl;

		cout << "\t Please ENTER Your ID: ";

		int j = 0;

		char moadel_dcheck[30];

		cin.ignore();

		fgets(moadel_dcheck, 30, stdin);

		int i = 0;

		for (j = 0; j < shomaresh_d; j++) {

			if (strcmp(student[j].ID, moadel_dcheck) == 0) {


				cout << "\n\t ID: " << student[j].ID << endl;
				cout << "\t -----------------------------------------------\n" << endl;

				cout << "\t Name: " << student[j].name << endl;
				cout << "\t -----------------------------------------------\n" << endl;

				cout << "\t Family: " << student[j].family << endl;
				cout << "\t -----------------------------------------------\n" << endl;
				cout << "\t\t\t Lesson Information" << endl;
				cout << "\t -----------------------------------------------" << endl;
				for (i = 0; i < student[j].shomaresh_lesson; i++)
				{
					cout << "\t\t\t     Name: " << student[j].students_mark[i].lesson_name << endl;
					cout << "\t\t\t     Unit: " << student[j].students_mark[i].unit << endl;
					cout << "\t\t\t     Score: " << student[j].students_mark[i].mark << endl;
					cout << "\t -----------------------------------------------" << endl;
				}
				cout << "\t\t\t     Average: " << student[j].average << endl;
			break;

			}

		}

		int show_shomaresh;

		etelaat_daneshjoo show_check;

		fopen_s(&save_d, "save_d.dat", "a+b");

		if (!save_d) {

			cout << "\t File wasn't Found";

		}

		int counter = 0;

		fread(&show_check, sizeof(etelaat_daneshjoo), 1, save_d);

		while (!feof(save_d)) {

			for (show_shomaresh = 0; show_shomaresh < shomaresh_d; show_shomaresh++) {

				if (strcmp(show_check.ID, student[show_shomaresh].ID) == 0) {
					break;
				}

			}

			if (show_shomaresh == shomaresh_d) {
				if (strcmp(show_check.ID, moadel_dcheck) == 0) {

				cout << "\n\t ID: " << show_check.ID << endl;
				cout << "\t -----------------------------------------------\n" << endl;

				cout << "\t Name: " << show_check.name << endl;
				cout << "\t -----------------------------------------------\n" << endl;

				cout << "\t Family: " << show_check.family << endl;
				cout << "\t -----------------------------------------------\n" << endl;
				cout << "\t\t\t Lesson Information" << endl;
				cout << "\t -----------------------------------------------" << endl;
				for (j = 0; j < show_check.shomaresh_lesson; j++)
				{
					cout << "\t\t\t     Name: " << show_check.students_mark[j].lesson_name << endl;
					cout << "\t\t\t     Unit: " << show_check.students_mark[j].unit << endl;
					cout << "\t\t\t     Score: " << show_check.students_mark[j].mark << endl;
					cout << "\t -----------------------------------------------" << endl;
				}
				cout << "\t\t\t     Average: " << show_check.average << endl;
				
				break;

				}
			}

			fread(&show_check, sizeof(etelaat_daneshjoo), 1, save_d);


		}

		fclose(save_d);

		cout << "\n\t For going to Menu Press ENTER ";

		cin.ignore();


		main_menu();


	}

	if (choice == '7') {

		system("cls");

		cout << "                             " << "____________________Welcome to ISFAHAN UNIVERSITY System >> Menu >> Change Info ___________________" << endl;

		cout << endl;

		cout << "************************************************************************************************************************************************************************" << endl;

		cout << endl;


		cout << "\t Please ENTER Your ID: ";

		int j = 0;

		char change_dcheck[30];

		cin.ignore();

		fgets(change_dcheck, 30, stdin);

		int change_counter = 0;

		etelaat_daneshjoo chaange_student_info[100];

		etelaat_daneshjoo enteghal;

		fopen_s(&save_d, "save_d.dat", "rb");

		fread(&enteghal, sizeof(etelaat_daneshjoo), 1, save_d);

		while (!feof(save_d)) {

			chaange_student_info[change_counter] = enteghal;

			change_counter++;

			fread(&enteghal, sizeof(etelaat_daneshjoo), 1, save_d);


		}

		fclose(save_d);

		for (j = 0; j < change_counter; j++) {

			if (strcmp(chaange_student_info[j].ID, change_dcheck) == 0) {

				break;
			}

		}
		cout << endl << "\t Please ENTER Your New ID: ";

		fgets(chaange_student_info[j].ID, 30, stdin);

		cout << endl << "\t Please Enter Your New Name: ";

		fgets(chaange_student_info[j].name, 30, stdin);

		cout << endl << "\t Please ENTER Your New Family: ";

		fgets(chaange_student_info[j].family, 30, stdin);

		chaange_student_info[j].shomaresh_lesson = 0;

		cout << endl << "\t Please Enter Lesson Name: ";

		fgets(chaange_student_info[j].students_mark[student[j].shomaresh_lesson].lesson_name, 30, stdin);

		cout << endl << "\t Please ENTER Lesson Unit: ";

		cin >> chaange_student_info[j].students_mark[chaange_student_info[j].shomaresh_lesson].unit;

		cout << endl << "\t Please ENTER Your Mark: ";

		cin >> chaange_student_info[j].students_mark[chaange_student_info[j].shomaresh_lesson].mark;

		chaange_student_info[j].shomaresh_lesson += 1;

		char change_edame_lesson;

		cout << endl << endl << "\t Do You Want To Add Another Lesson? ";

		cin >> change_edame_lesson;

		while (change_edame_lesson == 'y' || change_edame_lesson == 'Y') {

			cout << endl << "\t Please Enter Lesson Name: ";

			cin.ignore();

			fgets(chaange_student_info[j].students_mark[chaange_student_info[j].shomaresh_lesson].lesson_name, 30, stdin);

			cout << endl << "\t Please ENTER Lesson Unit: ";

			cin >> chaange_student_info[j].students_mark[chaange_student_info[j].shomaresh_lesson].unit;

			cout << endl << "\t Please ENTER Your Mark: ";

			cin >> chaange_student_info[j].students_mark[chaange_student_info[j].shomaresh_lesson].mark;

			chaange_student_info[j].shomaresh_lesson += 1;

			cout << endl << endl << "\t Do You Want To Add Another Lesson? ";

			cin >> change_edame_lesson;

		}

		int  w, unit = 0;

			chaange_student_info[j].average = 0;

			for (w = 0; w < chaange_student_info[j].shomaresh_lesson; w++) {

				unit += chaange_student_info[j].students_mark[w].unit;

				chaange_student_info[j].average += chaange_student_info[j].students_mark[w].unit * chaange_student_info[j].students_mark[w].mark;

			}

			chaange_student_info[j].average = chaange_student_info[j].average / unit;

		

		fopen_s(&save_d_check, "save_d_check.dat", "wb");

		fopen_s(&save_d, "save_d.dat", "wb");

		for (j = 0; j < change_counter; j++) {

			fwrite(&chaange_student_info[j], sizeof(etelaat_daneshjoo), 1, save_d);

			fwrite(&chaange_student_info[j], sizeof(etelaat_daneshjoo), 1, save_d_check);


		}
		fclose(save_d);

		fclose(save_d_check);

		cout << "\n\t For going to Menu Press ENTER ";

		cin.ignore();

		cin.ignore();

		main_menu();



	}

	if (choice == '8') {
	
		system("cls");

		cout << "                            " << "____________________Thanks for using Isfahan University System ( By Mohammad Jafari ) ___________________" << endl;

		cout << endl;

		cout << "************************************************************************************************************************************************************************" << endl;

		cout << endl;

		cout << "\t Press ENTER for EXIT";

		cin.ignore();

		cin.ignore();

		exit(0);

	}
} 