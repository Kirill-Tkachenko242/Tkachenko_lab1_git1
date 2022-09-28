


#include <iostream>
#include <vector>
#include <fstream>



using namespace std;






struct Pipe
{
    double lenght;
    double diametr;
    string repair;
};


bool IsLenghtCorrect(double d)
{
    return d >= 2 && d <= 10000;
}
bool IsDiametrCorrect(double d)
{
    return d >= 2 && d <= 1000;
}

Pipe InputPipe()
{
    Pipe s;
    do
    {
        cin.clear();
        cin.ignore(100000, '\n');
        cout << "lenght:";
        cin >> s.lenght;
    }while (cin.fail() || !IsLenghtCorrect(s.lenght));
    do
    {
        cin.clear();
        cin.ignore(100000, '\n');
        cout << "diametr: ";
        cin >> s.diametr;
    }while (cin.fail() || !IsDiametrCorrect(s.diametr));
    cout << "repair: ";
    cin >> s.repair;
    return s;
}

void PrintPipe(const Pipe& s)
{
    cout << "lenght: " << s.lenght;
    cout << "\tdiametr: " << s.diametr;
    cout << "\trepair: " << s.repair << endl;
}


Pipe LoadPipe()
{
    Pipe s;
    ifstream fin;
    fin.open("data.txt", ios::in);
    if (fin.is_open())
    {
        fin >> s.lenght;
        fin >> s.diametr;
        fin >> s.repair;
        fin.close();
    }
    return s;
}

void SavePipe(const Pipe& s)
{
    ofstream fout;
    fout.open("data.txt", ios::out);
    if (fout.is_open())
    {
        fout << s.lenght << endl 
             << s.diametr << endl
             << s.repair << endl;
        fout.close();
    }
}


void EditPipe(Pipe& s)
{
    s.diametr -= 0.5;
    s.diametr = IsDiametrCorrect(s.diametr) ? s.diametr:2;

}

void PrintMenu()
{
    cout << "1.Input pipe" << endl
        << "2.Print pipe" << endl
        << "3.Save to file" << endl
        << "4.Load from file" << endl
        << "5. Edit pipe" << endl
        << "0. Exit" << endl;
}

int main()
{
    Pipe st;
    while (1)
    {
        PrintMenu();
        int i = 0;
        cin >> i;
        switch (i)
        {
        case 1:
        {
            st = InputPipe();
            break;
        }
        case 2:
        {
            PrintPipe(st);
            break;
        }
        case 3:
        {
            SavePipe(st);
            break;
        }
        case 4:
        {
            st = LoadPipe();
            break;
        }
        case 5:
        {
            EditPipe(st);
            break;
        }
        case 0:
        {
            return 0;
        }
        default:
        {
            cout << "Wrong action" << endl;
        }
        }
    }
    return 0;
}


