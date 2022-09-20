


#include <iostream>

#include <vector>



using namespace std;






struct Pipe
{
    double lenght;
    double diametr;
    string repair;
};



Pipe InputPipe()
{
    Pipe s;
    cout << "lenght:";
    cin >> s.lenght;
    cout << "diametr: ";
    cin >> s.diametr;
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


void EditPipe(Pipe& s)
{
    s.diametr -= 0.5;
}

void SavePipe(const Pipe& s)
{

    cout << "lenght: " << s.lenght;
    cout << "\tdiametr: " << s.diametr;
    cout << "\trepair: " << s.repair << endl;
}




int main()
{
    Pipe st = InputPipe();
    PrintPipe(st);
    EditPipe(st);
    PrintPipe(st);
    return 0;
}


