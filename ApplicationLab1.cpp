// ApplicationLab1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "ApplicationLab1.h"
#include <fstream>
using namespace std;

struct pipe {
    int id = -1;
    float lenght, diameter;
    bool work; 
};
struct station {
    string name; 
    int id=-1;
    float number, percent, work_station;
};
void check(float& a) {
    cin >> a;
    while (a <= 0 || cin.peek() != '\n')
    {
        cout << "Invalid Input!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please re-enter [positive  only]: ";
        cin >> a;
    }
}
void checkeff(float& a) {
    cin >> a;
    while (a <= 0 || cin.peek() != '\n' || a>100)
    {
        cout << "Invalid Input!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please re-enter [positive  only]: ";
        cin >> a;
    }
}

void checkbool(bool& a) {
    while (!(cin >> a) || (cin.peek() != '\n'))
    {
        cin.clear();
        while (cin.get() != '\n');
        cout << "Input error! Repear please.\n";
    }
}
void checkstring(string& a) {
    while (!(cin >> a) || (cin.peek() != '\n'))
    {
        cin.clear();
        while (cin.get() != '\n');
        cout << "Input error! Repear please.\n";
    }
}
void Menu(int& a, pipe& Pipe, station& Station);
int main()
{
    int a; 
    pipe Pipe;
    station Station; 
    a = 1;
    while (a > 0) {
        Menu(a, Pipe, Station);
    }
}
void input(pipe& Pipe)
{
    Pipe.id = 0;
    cout << "Pipe lenght" << endl;
    check(Pipe.lenght);
    cout << "Pipe diameter" << endl;
    check(Pipe.diameter);
    cout << "Is it work?" << endl;
    checkbool(Pipe.work);
    cout << endl;
}
void inputstation(station& Station)
{
    Station.id = 0;
    cout << "Name of station:" << endl;
    checkstring(Station.name);
    cout << "How many workshop?" << endl;
    check(Station.number);
    cout << "How many working?" << endl;
    check(Station.work_station);
    cout << "Percent of station" << endl;
    checkeff(Station.percent);
}
void changepipe(pipe& Pipe)
{
    if (Pipe.id!=-1) {
        int k;
        cout << "What d u want to change" << endl;
        cout << "1.Length" << endl;
        cout << "2.Diameter" << endl;
        cout << "3.Pipe work" << endl;
        cin >> k;
        switch (k) {
        case 1:
            cout << "Write length" << endl;
            check(Pipe.lenght);
            break;
        case 2:
            cout << "Wtite diameter" << endl;
            check(Pipe.diameter);
            break;
        case 3:
            cout << "Work status" << endl;
            checkbool(Pipe.work);
            break;
        }
    }
    if (Pipe.id ==-1) {
        cout << "Write pipe again" << endl;
        input(Pipe);
    }
}

void outputpipe(pipe& Pipe)
{
    if (Pipe.id != -1) {
        cout << "id:" << Pipe.id << endl;
        cout << "length:" << Pipe.lenght << endl;
        cout << "diameter:" << Pipe.diameter << endl;
        if (Pipe.work == 1)
            cout << "Pipe is work" << endl;
        else
            cout << "Pipe isnt work" << endl;
    }
    if (Pipe.id == -1) {
        cout << "First write pipe" << endl;
        input(Pipe);
    }
          
}

void changestation(station& Station)
{
    if (Station.id != -1) {
        int n;
        cout << "What d u want to choose?" << endl;
        cout << "1.Name" << endl;
        cout << "2.Numbers of workshop" << endl;
        cout << "3.Number of working workshop" << endl;
        cout << "4.Percent" << endl;

        cin >> n;
        switch (n) {
        case 1:
            cout << "Name" << endl;
            checkstring(Station.name);
            break;
        case 2:
            cout << "Number" << endl;
            check(Station.number);
            break;
        case 3:
            cout << "Working workshop" << endl;
            check(Station.work_station);
            break;
        case 4:
            cout << "Percent" << endl;
            check(Station.percent);
            break;
        }
    }
    if (Station.id == -1) {
        cout << "Write station again" << endl;
            inputstation(Station);
    }
}
void file(pipe& Pipe) {
    ofstream fout;
    fout.open("File.txt");
    fout << Pipe.id << " " << Pipe.lenght << " " << Pipe.diameter << " " << Pipe.work;
    fout.close();
}
void file1(station& Station) {
    ofstream fout;
    fout.open("File.txt");
    fout <<Station.id<<" "<< Station.name <<" " << Station.number << " " << Station.work_station << " " << Station.percent;
    fout.close();
}
void file2(pipe&Pipe,station&Station) {
    ofstream fout;
    fout.open("File.txt");
    fout <<Pipe.id << " " << Pipe.lenght << " " << Pipe.diameter << " " << Pipe.work << " " <<Station.id << " " << Station.name << " " << Station.number << " " << Station.work_station << " " << Station.percent;
    fout.close();
}
void write(pipe& Pipe,station&Station) {
    ifstream cin("File.Txt");
    if (cin.is_open())
        cin >> Pipe.id >> Pipe.lenght >> Pipe.diameter >> Pipe.work >> Station.id >> Station.name >> Station.number >> Station.work_station >> Station.percent;
}
void outputstation(station& Station)
{
    if (Station.id != -1) {
        cout << "Station id:" << " " << Station.id << endl;
        cout << "Station name:" << " " << Station.name << endl;
        cout << "Number of workshop: " << " " << Station.number << endl;
        cout << "Number of working workshop:" << " " << Station.work_station << endl;
        cout << "Percent of station: " << " " << Station.percent << endl;
    }
    if (Station.id == -1) {
        cout << "First write station" << endl;
        inputstation(Station);
    }
}

void safe(pipe& Pipe,station& Station) {
    if ((Pipe.id == -1) && (Station.id == -1)) {
        ofstream fout;
        fout.open("File.txt");
        fout << "Not data!";
        fout.close();
    }
    else if ((Pipe.id != -1) && (Station.id != -1)) 
        file2(Pipe, Station);
        else  if (Pipe.id != -1) 
            file(Pipe);
        else file1(Station);
 
}


void Menu(int& a, pipe& Pipe, station& Station)
{
    cout << "Main Menu" << endl;
    cout << "Choose number" << endl;
    cout << "1.Add pipe" << endl;
    cout << "2.Add station" << endl;
    cout << "3.Show pipe number" << endl;
    cout << "4.Show station number" << endl;
    cout << "5.Change pipe" << endl;
    cout << "6.Change station" << endl;
    cout << "7.Save" << endl;
    cout << "8.Load" << endl;
    cout << "0.Exit" << endl;
    cout << "Choose" << endl;
    cin >> a;
    switch (a) {
    case 1:
        input(Pipe);
        break;

    case 2:
        inputstation(Station);
        break;

    case 3:
        outputpipe(Pipe);
        break;

    case 4:
        outputstation(Station);
        break;

    case 5:
        changepipe(Pipe);
        break;

    case 6:
        changestation(Station);
        break;

    case 7:
        safe(Pipe,Station);
        break;
    case 8:
        write(Pipe, Station);
        break;
    }
}










