#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
using namespace std;

//-----------------------------------------
//-------------------ID--------------------
//-----------------------------------------
void  id() {
    cout << "\t  * * *   *       *   *       *   * * *   *       *      * * *   * * *   * * *    *         **    * * *  " << endl;
    Sleep(50);
    cout << "\t    *     * *     *    *     *      *     * *     *    *           *     *    *   *        *      *       " << endl;
    Sleep(50);
    cout << "\t    *     *   *   *     *   *       *     *   *   *   *            *     * * *    *        ***    * * *  " << endl;
    Sleep(50);
    cout << "\t    *     *     * *      * *        *     *     * *    *           *     *    *   *        *          * " << endl;
    Sleep(50);
    cout << "\t  * * *   *       *       *       * * *   *       *      * * *   * * *   * * *     * * *    **    * * *  " << endl;
    Sleep(50);
}

//-----------------------------------------
//---------------NEW RECORD----------------
//-----------------------------------------
class new_record{
private:
    string Name, Father_Name, Grade;
    float Roll_No, Total_Marks, Marks_Obt, Percentage, PF_Marks, ITC_Marks, PHY_Marks, CALC_Marks, ENG_Marks;

public:
    void sendData();
    void setData();
};

//-----------------------------------------
//--------------SEARCH DATA----------------
//-----------------------------------------
class search_data {
private:
    string Roll_No, Name, Father_Name, PF_Marks, ITC_Marks, PHY_Marks, CALC_Marks, ENG_Marks, Total_Marks, Marks_Obt, Percentage, Grade;
    string Roll_Input;

public:
    void search();
};

//-----------------------------------------
//----------DISPLAY ALL RECORDS------------
//-----------------------------------------
class all_records {
private:
    string Roll_No, Name, Father_Name, PF_Marks, ITC_Marks, PHY_Marks, CALC_Marks, ENG_Marks, Total_Marks, Marks_Obt, Percentage, Grade;

public:
    void records();
};

//-----------------------------------------
//----------DELETE ALL RECORDS-------------
//-----------------------------------------
class delete_records {
public:
    void delete_r();
};

//-----------------------------------------
//---------------MAIN MANU-----------------
//-----------------------------------------
class main_manu : public new_record , public search_data, public delete_records, public all_records{
public:
    virtual void main_m() {
        system("cls");
        system("color 5");
        cout << "\n\n\n";
        id();
        cout << endl;
        cout << "\t\t\t\t=============================================" << endl;
        Sleep(50);
        cout << "\t\t\t\t=================MAIN MANU===================" << endl;
        Sleep(50);
        cout << "\t\t\t\t=============================================" << endl;

        cout << "\n\n\t\t1- Enter A New Record";
        Sleep(50);
        cout << "\n\n\t\t2- Search A Record";
        Sleep(50);
        cout << "\n\n\t\t3- Delete ALL Record";
        Sleep(50);
        cout << "\n\n\t\t4- Display All Records";
        Sleep(50);
        cout << "\n\n\t\t5- Exit";
        cout << "\n\n\t\tSelect From <1-5>";

        int value = 0;
        cin >> value;

        if (value == 1) {
            setData();
            sendData();
        }
        else if (value == 2) {
            search();
        }
        else if (value == 3) {
            delete_r();
        }
        else if (value == 4) {
            records();
        }
        else if (value == 5) {
            exit;
        }
        else {
            cout << "\n\n\t\tPlease Enter Correct Selection Value";
            cin.ignore();
            cin.get();
            main_m();
        }
    }
};


//-----------------------------------------
//----------------Home Page----------------
//-----------------------------------------
class homepage : public main_manu {
public:
    homepage() {
        system("cls");
        cout << "\n\n\n";
        id();
        cout << endl;
        cout << "\t\t\t\t=============================================" << endl;
        Sleep(50);
        cout << "\t\t\t\t====STUDENT REPORT CARD MANEGEMENT SYSTEM====" << endl;
        Sleep(50);
        cout << "\t\t\t\t=============================================" << endl;
        Sleep(50);
        cout << "\n\n\t\t\t======================PROJECT BY=====================" << endl;
        Sleep(50);
        cout << "\n\n\n\t\t\t\tBCSM-S21-047--------------Muneeb Ahmad";;
        Sleep(50);
        cout << "\n\n\n\t\t\tPress Enter key to continue...";
        cin.ignore();

        main_m();
    }
};


//-----------------------------------------
//----------NEW RECORD Functions-----------
//-----------------------------------------
void new_record :: setData() {
    system("cls");
    system("color 3");
    cout << "\n\n\n";
    id();
    cout << endl;
    cout << "\t\t\t\t=============================================" << endl;
    Sleep(50);
    cout << "\t\t\t\t=================NEW RECORD==================" << endl;
    Sleep(50);
    cout << "\t\t\t\t=============================================" << endl;

    //Taking Input From User
    cout << "\n\n\t\tEnter Roll Number:               ";
    cin >> Roll_No;
    cin.ignore();
    cout << "\n\t\tEnter Your Name:                   ";
    getline(cin, Name);
    cout << "\n\t\tEnter Your Father Name:            ";
    getline(cin, Father_Name);
    cout << "\n\t\tEnter Your PF Marks Out Of 100:    ";
    cin >> PF_Marks;
    cout << "\n\t\tEnter Your ITC Marks Out Of 100:   ";
    cin >> ITC_Marks;
    cout << "\n\t\tEnter Your PHY Marks Out Of 100:   ";
    cin >> PHY_Marks;
    cout << "\n\t\tEnter Your CALC Marks Out Of 100:  ";
    cin >> CALC_Marks;
    cout << "\n\t\tEnter Your ENG Marks Out Of 100:   ";
    cin >> ENG_Marks;

    //Total Marks
    Total_Marks = 500;
    cout << "\n\t\tTotal Marks:                       " << Total_Marks << "\n";

    //Obtained Marks Calculations
    Marks_Obt = (PF_Marks + ITC_Marks + PHY_Marks + CALC_Marks + ENG_Marks);
    cout << "\n\t\tObtained Marks:                    " << Marks_Obt << "\n";

    //Percentage Calculation
    Percentage = (Marks_Obt / Total_Marks) * 100;
    cout << "\n\t\tPercentage:                        " << Percentage << "%\n";

    //Grade Calculation
    if (Percentage >= 90) {
        Grade = "A+";
    }
    else if (Percentage < 90 && Percentage >= 80) {
        Grade = "A";
    }
    else if (Percentage < 80 && Percentage >= 70) {
        Grade = "B";
    }
    else if (Percentage < 70 && Percentage >= 60) {
        Grade = "C";
    }
    else if (Percentage < 60 && Percentage >= 50) {
        Grade = "D";
    }
    else {
        Grade = "F";
    }
    cout << "\n\t\tYour Grade:\t                   " << Grade << "\n";
}

void new_record::sendData() {
    main_manu obj;

    //Sending All Entered Data Into The File.
    fstream myfile;
    myfile.open("data.csv", ios::app);

    if (myfile.is_open()) {
        myfile << Roll_No << "," << Name << "," << Father_Name << "," << PF_Marks << "," << ITC_Marks << "," << PHY_Marks << "," << CALC_Marks << "," << ENG_Marks << "," << Total_Marks << "," << Marks_Obt << "," << Percentage << "," << Grade << endl;
    }
    else if (!myfile.is_open()) {
        cout << "File Not Exists";
    }
    myfile.close();
    if (!myfile.is_open()) {
        cout << "\n\t\tNew Record Saved Successfully!";
    }

    //Returning To Main Menu
    cin.ignore();
    cin.get();
    obj.main_m();
}



//-----------------------------------------
//---------SEARCH DATA Function------------
//-----------------------------------------
void search_data :: search() {
    main_manu obj;

    system("cls");
    system("color c");
    cout << "\n\n\n";
    id();
    cout << endl;
    cout << "\t\t\t\t=============================================" << endl;
    Sleep(50);
    cout << "\t\t\t\t=========SEARCH STUDENT REPORT CARD==========" << endl;
    Sleep(50);
    cout << "\t\t\t\t=============================================" << endl;

    fstream myfile;
    myfile.open("data.csv", ios::in);

    if (!myfile.is_open()) {
        cout << "Error While Opening File" << '\n';
        obj.main_m();
    }

    Sleep(50);
    cout << "\n\n";
    cout << "\tPlease Enter Roll No: ";
    cin >> Roll_Input;
    cout << endl;
    while (myfile.good())
    {
        getline(myfile, Roll_No, ',');
        getline(myfile, Name, ',');
        getline(myfile, Father_Name, ',');
        getline(myfile, PF_Marks, ',');
        getline(myfile, ITC_Marks, ',');
        getline(myfile, PHY_Marks, ',');
        getline(myfile, CALC_Marks, ',');
        getline(myfile, ENG_Marks, ',');
        getline(myfile, Total_Marks, ',');
        getline(myfile, Marks_Obt, ',');
        getline(myfile, Percentage, ',');
        getline(myfile, Grade, '\n');

        if (Roll_Input == Roll_No)
        {
            cout << "\t\tStudent Name:                  " << Name << endl;
            Sleep(50);
            cout << "\t\tStudent Father Name:           " << Father_Name << endl;
            Sleep(50);
            cout << "\t\tPrograming Fundmentals Marks:  " << PF_Marks << endl;
            Sleep(50);
            cout << "\t\tITC Marks Are:                 " << ITC_Marks << endl;
            Sleep(50);
            cout << "\t\tApplied Physics Marks:         " << PHY_Marks << endl;
            Sleep(50);
            cout << "\t\tCalculus Marks:                " << CALC_Marks << endl;
            Sleep(50);
            cout << "\t\tEnglish Marks:                 " << ENG_Marks << endl;
            Sleep(50);
            cout << "\t\tToalt Marks:                   " << Total_Marks << endl;
            Sleep(50);
            cout << "\t\tObtained Marks:                " << Marks_Obt << endl;
            Sleep(50);
            cout << "\t\tPercentage:                    " << Percentage << "%" << endl;
            Sleep(50);
            cout << "\t\tGrade:                         " << Grade << endl;
            cout << "\n\n\tPress Enter Key To Continoue..";
            cin.ignore();
            cin.get();
            myfile.close();
            obj.main_m();
        }
    }
}

//-----------------------------------------
//-----DISPLAY ALL RECORDS Function--------
//-----------------------------------------
void all_records :: records() {
    main_manu obj;

    system("cls");
    system("color 2");
    cout << "\n\n\n";
    id();
    cout << endl;
    cout << "\t\t\t\t=============================================" << endl;
    Sleep(50);
    cout << "\t\t\t\t============ALL STUDENTS RECORDS=============" << endl;
    Sleep(50);
    cout << "\t\t\t\t=============================================" << endl;

    fstream myfile;
    myfile.open("data.csv", ios::in);

    if (!myfile.is_open()) {
        cout << "Error While Opening File" << '\n';
        cin.ignore();
        cin.get();
        obj.main_m();
    }

    while (myfile.good())
    {
        getline(myfile, Roll_No, ',');
        getline(myfile, Name, ',');
        getline(myfile, Father_Name, ',');
        getline(myfile, PF_Marks, ',');
        getline(myfile, ITC_Marks, ',');
        getline(myfile, PHY_Marks, ',');
        getline(myfile, CALC_Marks, ',');
        getline(myfile, ENG_Marks, ',');
        getline(myfile, Total_Marks, ',');
        getline(myfile, Marks_Obt, ',');
        getline(myfile, Percentage, ',');
        getline(myfile, Grade, '\n');

        cout << "\n\t\tStudent Roll No:             " << Roll_No << endl;
        Sleep(50);
        cout << "\t\tStudent Name:                  " << Name << endl;
        Sleep(50);
        cout << "\t\tStudent Father Name:           " << Father_Name << endl;
        Sleep(50);
        cout << "\t\tPrograming Fundmentals Marks : " << PF_Marks << endl;
        Sleep(50);
        cout << "\t\tITC Marks Are :                " << ITC_Marks << endl;
        Sleep(50);
        cout << "\t\tApplied Physics Marks :        " << PHY_Marks << endl;
        Sleep(50);
        cout << "\t\tCalculus Marks :               " << CALC_Marks << endl;
        Sleep(50);
        cout << "\t\tEnglish Marks :                " << ENG_Marks << endl;
        Sleep(50);
        cout << "\t\tToalt Marks :                  " << Total_Marks << endl;
        Sleep(50);
        cout << "\t\tObtained Marks :               " << Marks_Obt << endl;
        Sleep(50);
        cout << "\t\tPercentage:                    " << Percentage << "%" << endl;
        Sleep(50);
        cout << "\t\tGrade:                         " << Grade << endl;
        Sleep(50);
        cout << "\t\t--------------------------------------\n";
        Sleep(50);
        cout << "\t\t--------------------------------------\n";
        Sleep(50);
    }
    cout << "\t\tPress Enter To Continue...";
    cin.ignore();
    cin.get();
    obj.main_m();
}

//-----------------------------------------
//-----DELETE ALL RECORDS Functions--------
//-----------------------------------------
void delete_records :: delete_r() {
    main_manu obj;

    system("cls");
    system("color c");
    cout << "\n\n\n";
    id();
    cout << endl;
    cout << "\t\t\t\t=============================================" << endl;
    Sleep(50);
    cout << "\t\t\t\t==============DELETE ALL RECORD===============" << endl;
    Sleep(50);
    cout << "\t\t\t\t=============================================" << endl;

    fstream myfile;

    //input variable declare here
    char cond;
    cout << "\tEnter Y/N To Delete All Records: ";
    cin >> cond;
    Sleep(50);
    cout << "\n\n";

    if (cond == 'Y' || cond == 'y' ) {
        cout << endl;

        myfile.open("data.csv", ios::out | ios::trunc);
        myfile.close();

        cout << "\t\t-----------------------------------------------------\n";
        cout << "\t\t--------------------RECORDS DELETED------------------\n";
        cout << "\t\t-----------------------------------------------------\n\n\n";
        cout << "\n\n\tPress Enter Key To Continoue..";
        cin.ignore();
        cin.get();
        obj.main_m();
    }

    else if (cond == 'N' || cond == 'n') {

    }

    else
    {
        cout << "Please Enter Coreect Choice Y/N To Delete Data!\n";
        Sleep(2500);
        delete_r();
    }
}

int main() {
    homepage h;
    main_manu m;

    return 0;
}
