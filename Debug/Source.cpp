#include<iostream>
#include<time.h>
#include<ctime>
#include<chrono>
#pragma warning(disable:4996)
using namespace std;
struct info
{
	char username[100];
	char password[100];
};
char useraz[100];
int j=0;
info ostadi[1000];                  // structure for add the ostad and daneshjo
info daneshjoi[1000];
void daneshjolist(); // daneshjo list function
void run();          // running exam function
void newexam();      // crete new exam function
void login();        // login function
void modir();        // modir panel function
void addostad();     // adding ostad function
void adddaneshjo();  // adding daneshjo function
void ostad();        // ostad panel function
void daneshjo();     // daneshjo panel function
void ostadlist();    // ostad list function
void exam();         // show exams function
void results();      // results function
int main()
{
	system("cls");
	cout << "                                       " << "****** WELCOME ******" << endl << endl;
	char word;
	cout << "     " << "{L}: log in" << endl;
	cout << "     " << "{E}: exit" << endl<< endl;
	cout << "        " << "choose an object: ";
	cin >> word;                                                 // getting the object
	switch (word)
	{
	case 'L':
		login();
	case 'E':
		break;
	default :
		system("cls");
		cout << "                                       " << "****** WELCOME ******" << endl << endl;
		cout <<endl<< "    your object is not available please press enter key to return";
		cin.ignore().get();
		main();
	}
	return 0;
}
void login()
{
	char role;
	system("cls");
	cout << "                                       " << "****** WELCOME ******" << endl << endl;
	cout << "     " << "{M}: modir" << endl;
	cout << "     " << "{O}: ostad" << endl;
	cout << "     " << "{D}: daneshjo" << endl;
	cout << "     " << "{S}: main screen" << endl << endl;
	cout << "         " << "please choose your position: ";
	cin >> role;                                                        // getting position
	switch (role)
	{
	 case 'M': modir();
	 case 'O': ostad();
	 case 'D': daneshjo();
	 case 'S': main();
	 default :
		 system("cls");
		 cout << "                                       " << "****** WELCOME ******" << endl << endl;
		 cout << endl << "    your position is not available please press enter key to return";
		 cin.ignore().get();
		 login();
	}
}
void newexam()
{
	struct tm t;
	int qu, i = 0,r,d,end,min,sec,hour;
	char questionn[100];
	char name[100];
	char text[100];
	char alaki[2];
	int javab;
	system("cls");
	cout << "                                       " << "****** WELCOME ******" << endl << endl;
	cout << "     " << "please enter exam start time:  year: ";                      // getting the start time of exam 
	cin >> t.tm_year;
	t.tm_year = t.tm_year - 1900;
	cout << "                                    " << "month: ";
	cin >> t.tm_mon;
	t.tm_mon = t.tm_mon - 1;
	cout << "                                    " << "day: ";                             
	cin >> t.tm_mday;
	cout << "                                    " << "hour: ";
	cin >> t.tm_hour;
	cout << "                                    " << "min: ";
	cin >> t.tm_min;
	cout << "                                    " << "sec: ";
	cin >> t.tm_sec;                                                                 // getting the start time of exam 
	cout << endl << "       " << "please enter exam duration:  hour:";               // getting the duration of exam
	cin >> hour;
	cout << "                                    " << "min: ";
	cin >> min;
	cout << "                                    " << "sec: ";
	cin >> sec;                                                                      // getting the duration of exam
	end = (hour * 3600) + (min * 60) + sec;                                          // convert duration to the sec
	cout << endl;
	cout << "     " << "please enter questions number: ";                            // getting question number
	cin >> qu;
	cout << endl;
	d = mktime(&t); 
	cout << "     " << "please enter exam name: ";                                   // gettiing exam name
	cin >> name;
	FILE* ex = fopen(name, "wb");                                                    // write informations on the file        
	fwrite(&qu, sizeof(qu), 1, ex);
	fwrite(&d, sizeof(d), 1, ex);
	fwrite(&end, sizeof(end), 1, ex);
	for (i = 0; i < qu; i++)
	{
	    fgets(alaki, 100, stdin);
		system("cls");
		cout << "                                       " << "****** WELCOME ******" << endl << endl;
		cout << "     " << "please write question" << i + 1 << " text: ";            // getting question text
		fgets(text, 100, stdin);
		fwrite(&text, sizeof(text), 1, ex);
		cout << endl << endl;
		for (r = 0; r < 4; r++)
		{
			cout << "     " << "please write option" << r+1 << ": ";                 // getting question options
			fgets(questionn, 100, stdin);
			cout << endl;
			fwrite(&questionn, sizeof(questionn), 1, ex);
		}
		cout << "     " << "please write correct answer: ";                          // getting correct answer
		cin >> javab;
		fwrite(&javab, sizeof(javab), 1, ex);
	}
	fclose(ex);
	FILE* examname;
	fopen_s(&examname, "examname", "ab");
	fwrite(&name, sizeof(name), 1, examname);                                        //write the exam name on the file
	fclose(examname);
	system("cls");
	cout << "                                       " << "****** WELCOME ******" << endl << endl;
	cout << "     " << "your exam added" << endl << endl;
	cout << "        " << "please press enter key to return";
	cin.ignore().get();
	login();
}
void modir()
{
	int n;
	char username1[100] = "admin", password1[100] = "admin";                             // modir username and password
	char username[100], password[100];
	system("cls");
	cout << "                                       " << "****** WELCOME ******" << endl << endl;
	cout << "     " << "please enter your username: ";
	cin >> username;
	cout << endl;
	cout << "     " << "please enter your password: ";
	cin >> password;                                                                    // getting modir username and password
	if (strcmp(username, username1)!=0 || strcmp(password, password1)!=0)
	{
		system("cls");
		cout << "                                       " << "****** WELCOME ******" << endl << endl;
		cout <<endl<<"       "<<"your username or password is incorrect" << endl<<endl;     
		cout << "       " << "please press enter key to return";                        // checking the modir username and password
		cin.ignore().get(); 
		login();
	}
	system("cls");
	cout << "                                       " << "****** WELCOME ******" << endl << endl;
	cout << "                                           " << "WELCOME MODIR" << endl;
	cout << "      " << "{1}: add new ostad" << endl;
	cout << "      " << "{2}: add new danedhjo" << endl;
	cout << "      " << "{3}: see exams" << endl;
	cout << "      " << "{4}: see exam results" << endl;
	cout << "      " << "{5}: see ostads list" << endl;
	cout << "      " << "{6}: see daneshjo list" << endl;
	cout << "      " << "{7}: back" << endl << endl;
	cout << "         " << "please choose your demand: ";
	cin >> n;                                                                           // getting the modir damend
	switch (n)
	{
	case 1:
		addostad();
	case 2:
		adddaneshjo();
	case 3:
		exam();
	case 4:
		results();
	case 5:
		ostadlist();
	case 6:
		daneshjolist();
	case 7:
		login();
	}
}
void addostad()
{
	FILE* ostadinfo;
	system("cls");
	cout << "                                       " << "****** WELCOME ******" << endl << endl;
	cout << "     " << "please enter ostad username: ";
	cin >> ostadi[j].username;
	cout << endl;
	cout << "     " << "please enter ostad password: ";
	cin >> ostadi[j].password;                                            // getting ostad username and password
	system("cls");
	cout << "                                       " << "****** WELCOME ******" << endl << endl;
	cout << "     " << "ostad added" << endl;
	cout << "     " << "please press enter key to return ";
	fopen_s(&ostadinfo, "ostadinfo", "ab");
	fwrite(&ostadi[j], sizeof(ostadi[j]), 1, ostadinfo);                 // write the ostad info on the file
	fclose(ostadinfo);
	j = j + 1;
	cin.ignore().get();
	login();
}
void adddaneshjo()
{
	FILE* daneshjoinfo;
	system("cls");
	cout << "                                       " << "****** WELCOME ******" << endl << endl;
	cout << "     " << "please enter daneshjo username: ";
	cin >> daneshjoi[j].username;
	cout << endl;
	cout << "     " << "please enter daneshjo password: ";
	cin >> daneshjoi[j].password;                                                           // getting daneshjo username and password
	system("cls");
	cout << "                                       " << "****** WELCOME ******" << endl << endl;
	cout << "     " << "daneshjo added" << endl;
	cout << "     " << "please press enter key to return ";
	fopen_s(&daneshjoinfo, "daneshjoinfo", "ab");
	fwrite(&daneshjoi[j], sizeof(daneshjoi[j]), 1, daneshjoinfo);                          // write daneshjo info on the file
	fclose(daneshjoinfo);
	j = j + 1;
	cin.ignore().get();
	login();
}
void ostad()
{

	FILE* ostadinfo;
	info ostadi[100];
	int i = 0, q;
	char username[100], password[100];
	system("cls");
	cout << "                                       " << "****** WELCOME ******" << endl << endl;
	cout << "     " << "please enter your username: ";
	cin >> username;
	cout << endl;
	cout << "     " << "please enter your password: ";
	cin >> password;                                                           // getting the ostad username and password
	fopen_s(&ostadinfo, "ostadinfo", "rb");
	fread(&ostadi[i], sizeof(ostadi[i]), 1, ostadinfo);
	while (!feof(ostadinfo))
	{
		i = i + 1;
		fread(&ostadi[i], sizeof(ostadi[i]), 1, ostadinfo);                   // read the ostads info file
	}
	fclose(ostadinfo);
	for (q = 0; q < i; q++)
	{
		if (strcmp(ostadi[q].username, username) == 0 && strcmp(ostadi[q].password, password) == 0)
		{
			break;                                                           // cheching the ostad info
		}
	}
	if (q == i)
	{
		system("cls");
		cout << "                                       " << "****** WELCOME ******" << endl << endl;
		cout << endl << "       " << "your username or password is incorrect" << endl << endl;
		cout << "       " << "please press enter key to return";            // ostad info is incorrect
		cin.ignore().get();
		login();
	}
	char os;
	system("cls");
	cout << "                                       " << "****** WELCOME ******" << endl << endl;
	cout << "     " << "{A}: add new exam" << endl;
	cout << "     " << "{S}: see exam results" << endl;
	cout << "     " << "{B}: back" << endl << endl;
	cout << "        " << "please choose an option ";                     // getting ostad option
	cin >> os;
	switch(os)
	{
	case 'A': newexam();
	case 'S': results();
	case 'B': login();
	}
	login();
}
void daneshjo()
{
	FILE* daneshjoinfo;
	info daneshjoi[100];
	int i=0,q;
	char username[100], password[100];
	system("cls");
	cout << "                                       " << "****** WELCOME ******" << endl << endl;
	cout << "     " << "please enter your username: ";
	cin >> username;
	cout << endl;
	cout << "     " << "please enter your password: ";
	cin >> password;                                                                        // getting daneshjo username and password
	fopen_s(&daneshjoinfo, "daneshjoinfo", "rb");
	fread(&daneshjoi[i], sizeof(daneshjoi[i]), 1, daneshjoinfo);
	while (!feof(daneshjoinfo))
	{
		i = i + 1;
		fread(&daneshjoi[i], sizeof(daneshjoi[i]), 1, daneshjoinfo);                       // read the daneshjo info file
	}
	fclose(daneshjoinfo);
	for (q = 0; q < i ; q++)
	{
		if (strcmp(daneshjoi[q].username, username) == 0 && strcmp(daneshjoi[q].password, password) == 0)
		{
			break;                                                                        // checking the daneshjo info
		}
	}
	if (q == i)
	{
		system("cls");
		cout << "                                       " << "****** WELCOME ******" << endl << endl;
		cout << endl << "       " << "your username or password is incorrect" << endl << endl;
		cout << "       " << "please press enter key to return";                         // daneshjo info is incorrect
		cin.ignore().get();
		login();
	}
	strcpy_s(useraz, username);
	char w;
	system("cls");
	cout << "                                       " << "****** WELCOME ******" << endl << endl;
	cout << "     " << "{E} exams" << endl;
	cout << "     " << "{R} exam results" << endl;
	cout << "     " << "{B} back" << endl << endl;
	cout << "        " << "please enter an option: ";                                    // getting the daneshjo option
	cin >> w;
	switch (w)
	{
	case 'E':
		run();
	case 'R':
		results();
	case 'B':
		login();
	}
}
void ostadlist()
{
	system("cls");
	cout << "                                       " << "****** WELCOME ******" << endl << endl;
	FILE* ostadinfo;
	int i = 0,q,z,r;
	info temp;
	fopen_s(&ostadinfo, "ostadinfo", "rb");
	fread(&ostadi[i], sizeof(ostadi[i]), 1, ostadinfo);
	while (!feof(ostadinfo))
	{
		i = i + 1;
		fread(&ostadi[i], sizeof(ostadi[i]), 1, ostadinfo);                                // read the ostads info from file
	}
	fclose(ostadinfo);
	for (z = 0; z < i; z++)
	{
		for (q = 0; q < i - z-1; q++)
		{
			if (strcmp(ostadi[q].username, ostadi[q + 1].username) > 0)
			{
				temp = ostadi[q];
				ostadi[q] = ostadi[q + 1];                                                // sort the ostad informations
				ostadi[q + 1] = temp;
			}
		}
	}
	fopen_s(&ostadinfo, "ostadinfo", "wb");
	for (r = 0; r < i ; r++)
	{
		fwrite(&ostadi[r], sizeof(ostadi[r]), 1, ostadinfo);                             // write the ostad informations on the file
	}
	fclose(ostadinfo);
	i = 0;
	fopen_s(&ostadinfo, "ostadinfo", "rb");
	fread(&ostadi[i], sizeof(ostadi[i]), 1, ostadinfo);
	while (!feof(ostadinfo))                                                            // print the ostads info
	{
		cout <<"ostad"<<"{"<<i+1 <<"} "<<"username: "<<ostadi[i].username <<endl<< "         " <<"password: "<< ostadi[i].password << endl;
		i = i + 1;
		fread(&ostadi[i], sizeof(ostadi[i]), 1, ostadinfo);
	}
	fclose(ostadinfo);
	cin.ignore().get();
	login();
}
void daneshjolist()
{
	system("cls");
	cout << "                                       " << "****** WELCOME ******" << endl << endl;
	FILE* daneshjoinfo;
	int i = 0, q, z, r;
	info temp;
	fopen_s(&daneshjoinfo, "daneshjoinfo", "rb");
	fread(&daneshjoi[i], sizeof(daneshjoi[i]), 1, daneshjoinfo);
	while (!feof(daneshjoinfo))                                                            // read the daneshjo info
	{ 
		i = i + 1;
		fread(&daneshjoi[i], sizeof(daneshjoi[i]), 1,daneshjoinfo);
	}
	fclose(daneshjoinfo);
	for (z = 0; z < i; z++)
	{
		for (q = 0; q < i - z - 1; q++)
		{
			if (strcmp(daneshjoi[q].username, daneshjoi[q + 1].username) > 0)
			{
				temp = daneshjoi[q];
				daneshjoi[q] = daneshjoi[q + 1];                                          // sort the daneshjos info
				daneshjoi[q + 1] = temp;
			}
		}
	}
	fopen_s(&daneshjoinfo, "daneshjoinfo", "wb");
	for (r = 0; r < i; r++)
	{
		fwrite(&daneshjoi[r], sizeof(daneshjoi[r]), 1,daneshjoinfo);                       // write the daneshjo informations on the file
	}
	fclose(daneshjoinfo);
	i = 0;
	fopen_s(&daneshjoinfo, "daneshjoinfo", "rb");
	fread(&daneshjoi[i], sizeof(daneshjoi[i]), 1, daneshjoinfo);                           // print the daneshjo informations
	while (!feof(daneshjoinfo))
	{
		cout << "daneshjo" << "{" << i + 1 << "} " << "username: " << daneshjoi[i].username << endl << "            " << "password: " << daneshjoi[i].password << endl;
		i = i + 1;
		fread(&daneshjoi[i], sizeof(daneshjoi[i]), 1, daneshjoinfo);
	}
	fclose(daneshjoinfo);
	cin.ignore().get();
	login();
}
void exam()
{
	time_t t;
	time(&t);
	char name[100],az[100];
	int tedad,time,sec,end,i=0;
	system("cls");
	cout << "                                       " << "****** WELCOME ******" << endl << endl;
	FILE* examname;
	fopen_s(&examname, "examname", "rb");
	fread(&name, sizeof(name), 1, examname);                                      // readinig the exams info from the file
	while (!feof(examname))
	{
		i = i + 1;
		cout << "     " << "exame {" << i << "}: " << name << endl;               // print exam info
		fread(&name, sizeof(name), 1, examname);
	}
	fclose(examname);
	cout << endl << "         " << "please enter your exam name: ";
	cin >> az;                                                                    // getting the exam name
	FILE* ex = fopen(az, "rb");
	fread(&tedad, sizeof(tedad), 1, ex);
	fread(&time, sizeof(time), 1, ex);                                            // reading the exam info from file
	fread(&end, sizeof(end), 1, ex);
	sec = difftime(time, t);                                                      // calculating the steart time
	system("cls");
	cout << "                                       " << "****** WELCOME ******" << endl << endl;
	if (sec > 0)
	{
		cout << "     " << "exam: " << az << "     " << "question numbers: " << tedad << "     " << "the exam time has not come" << endl;
		cin.ignore().get();
		login();
	}
	else if (sec<0 && sec>-end)
	{
		cout << "     " << "exam: " << az << "     " << "question numbers: " << tedad << "     " << "the exam is on performing" << endl;
	}
	else
	{
		cout << "     " << "exam: " << az << "     " << "question numbers: " << tedad << "     " << "the exam is over" << endl;
		cin.ignore().get();
		login();
	}
	fclose(ex);
	cin.ignore().get();
	login();
}
void run()
{
	int i = 0, tedad, javab, nomre = 0, cjavab, time1, end, sec,a,g=0;
	char text[100];
	char question1[100];
	char question2[100];
	char question3[100];
	char question4[100];
	char name[100],az[100];
	system("cls");
	cout << "                                       " << "****** WELCOME ******" << endl << endl;
	FILE* examname;
	fopen_s(&examname, "examname", "rb");                                // reading the exams info from file
	fread(&name, sizeof(name), 1, examname);
	while (!feof(examname))
	{
		i = i + 1;
		cout << "     " << "exame {" << i << "}: " << name << endl;     // print the info exams
		fread(&name, sizeof(name), 1, examname);
	}
	fclose(examname);
	cout << endl << "         " << "please enter your exam name: ";
	cin >> az;                                                          // getting the exam name
	time_t t;
	time(&t);
	system("cls");
	cout << "                                       " << "****** WELCOME ******" << endl << endl;
	FILE* ex = fopen(az, "rb");
	fread(&tedad, sizeof(tedad), 1, ex);
	fread(&time1, sizeof(time1), 1, ex);                               // reading the exam info from file
	fread(&end, sizeof(end), 1, ex);
	sec = difftime(time1, t);                                          // calculating the time
	if (sec > 0)
	{
		cout << "     " << "exam: " << az << "     " << "question numbers: " << tedad  << "     " << "the exam time has not come" << endl;
		cin.ignore().get();
		login();
	}
	else if (sec<0 && sec>-end)
	{
		cout << "     " << "exam: " << az << "     " << "question numbers: " << tedad << "     " << "the exam is on performin" << endl;
	}
	else
	{
		cout << "     " << "exam: " << az << "     " << "question numbers: " << tedad << "     " << "the exam is over" << endl;
	}
	cout << endl;
	cout << "      " << "please press enter key to start exam";
	cin.ignore().get();
	time(&t);
	sec = difftime(time1, t);                                            // calculating the time
	end = end - abs(sec);
	std::chrono::steady_clock::time_point tend = std::chrono::steady_clock::now() + std::chrono::seconds(end);
	while (std::chrono::steady_clock::now() < tend)
	{
		system("cls");
		cout << "                                       " << "****** WELCOME ******" << endl << endl;
		fread(&text, sizeof(text), 1, ex);
		cout << "   " << i << ". " << text << endl;
		fread(&question1, sizeof(question1), 1, ex);
		fread(&question2, sizeof(question2), 1, ex);
		fread(&question3, sizeof(question3), 1, ex);
		fread(&question4, sizeof(question4), 1, ex);
		cout << "      " << '1' << ". " << question1 << endl << endl;
		cout << "      " << '2' << ". " << question2 << endl << endl;      // show the questions and getting the answer
		cout << "      " << '3' << ". " << question3 << endl << endl;
		cout << "      " << '4' << ". " << question4 << endl << endl;
		i = i + 1;
		cout << "     " << "please enter your answer: ";
		cin >> javab;
		fread(&cjavab, sizeof(cjavab), 1, ex);
		if (javab == cjavab)
		{
			nomre++;
		}
		g++;
		if (g == tedad)break;
	}
	fclose(ex);
	system("cls");
	cout << "                                       " << "****** WELCOME ******" << endl << endl;
	FILE* na = fopen(useraz, "ab");
	fwrite(&az, sizeof(az), 1, na);
	fwrite(&nomre, sizeof(nomre), 1, na);                                 // write the exam name and daneshjo nomre on the file
	fclose(na);
	cout << "     " << "your correct answers number is: " << nomre << endl;
	cout << "     " << "please press enter key to return ";
	cin.ignore().get();
	login();
}
void results()
{
	FILE* result;
	char examname[100], user[100],ex[100];
	int nomre,tedad,time1,end,sec,a;
	time_t t;
	system("cls");
	cout << "                                       " << "****** WELCOME ******" << endl << endl;
	cout << "     " << "please enter daneshjo username: ";
	cin >> user;                                                             // getting the daneshjo username
	cout << endl;
	cout << "     " << "please enter exam name: "; 
	cin >> ex;
	FILE* exam = fopen(ex, "rb");
	fread(&tedad, sizeof(tedad), 1, exam);
	fread(&time1, sizeof(time1), 1, exam);                                            // reading the exam info from file
	fread(&end, sizeof(end), 1, exam);
	a = time(&t);
	sec = difftime(time1, t);
    if (sec<0 && sec>-end)
	{
	system("cls");
	cout << "                                       " << "****** WELCOME ******" << endl << endl;
	cout << "     " << "exam: " << ex << "     " << "question numbers: " << tedad << "     " << "the exam is on performing" << endl;
	cout << "     " << "please press enter key to return";
	cin.ignore().get();
	login();
	}
	system("cls");
	cout << "                                       " << "****** WELCOME ******" << endl << endl;
	FILE* na = fopen(user, "rb");
	fread(&examname, sizeof(examname), 1, na);                              // reading the exams name and daneshjo nomre from file
	fread(&nomre, sizeof(nomre), 1, na);
	while (!feof(na))
	{
		if (strcmp(examname, ex) == 0)
		{
			cout << "      " << "exam: " << examname << "      " << "nomre: " << nomre << endl;
		}
		fread(&examname, sizeof(examname), 1, na);                        
		fread(&nomre, sizeof(nomre), 1, na);                                // pirnt the exams name and daneshjo nomre
	}
	cin.ignore().get();
	login();
}