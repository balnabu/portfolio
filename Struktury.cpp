//Przemyslaw Lis
#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>

using namespace std;
struct student
{
    string nazwisko;
    double ocena[3];
    double srednia;
};

void wczytaj(student dane[]);
double srednia(student dane[]);
int wiecej(student dane[], double sr);
void wyswietl(student dane[]);
void wypiszstudent(student dane[], string s);
void najwieksza(student dane[]);
int main()
{
    srand(time(NULL));

    student dane[5];

    wczytaj(dane);
    double sr = 0;
    
    sr = srednia(dane);

    cout<<endl;
    cout<<"srednia wszystkich studentow = ";
    cout<<sr;
    cout<<"\n";

    cout<<"studentow ktorzy maja srednia powyzej sredniej jest: "<<wiecej(dane, sr)<<"\n";
    najwieksza(dane);
    cout<<"\n";

    wyswietl(dane);
    cout<<"\n";

    string s;
    cout<<"podaj nazwisko studenta ktorego dane wyswietlic: ";
    cin>>s;
    wypiszstudent(dane, s);
   

    

    cout<<"\n\n";
    system("pause");
}
void wczytaj(student dane[])
{   
    double suma = 0;
    
    for(int i = 0; i<5; i++)
    {
        cout<<"podaj nazwisko studenta: ";
        cin>>dane[i].nazwisko;
    }

    for(int i = 0; i<5; i++)
    {
        suma = 0;

        for(int j = 0; j<3; j++)
        {
            dane[i].ocena[j] = (rand() % (10-4+1) +4) /2.0;
            suma +=  (double)dane[i].ocena[j];
        } 
        
        dane[i].srednia = suma/3.0;
    }
}
double srednia(student dane[])
{
    double suma = 0;
    double wynik = 0;
    for(int i = 0; i<5; i++)
    {
        suma += dane[i].srednia;
    }
    wynik = suma/5.0;

    return (double)wynik;

}
int wiecej(student dane[], double sr)
{
    int wynik = 0;
    for(int i = 0; i<5; i++)
    {
        if(dane[i].srednia > sr) wynik++;
    }

    return wynik;
}
void wyswietl(student dane[])
{
    for(int i = 0; i<5; i++)
    {
        cout<<"nazwisko: "<<dane[i].nazwisko<<" oceny: ";
        for(int j = 0; j<3; j++)
        {
            cout<<dane[i].ocena[j]<<" ";
        }
        cout<<"srednia = "<<dane[i].srednia<<endl;
    }
}
void wypiszstudent(student dane[], string s)
{
    bool flaga = false;

    for(int i = 0; i<5; i++)
    {
        if(dane[i].nazwisko == s)
        {
            cout<<"nazwisko: "<<dane[i].nazwisko<<" oceny: ";
             for(int j = 0; j<3; j++)
             {
                 cout<<dane[i].ocena[j]<<" ";
             }
              cout<<"srednia = "<<dane[i].srednia<<endl;
              flaga = true;
        }
        
    }

    if(flaga == false) cout<<"nie ma takiego studenta";
   
    
    
}
void najwieksza(student dane[])
{
    double pom = dane[0].srednia;
    int index = 0;

    for(int i = 1; i<5; i++)
    {
        if(dane[i].srednia > pom)
        {
            pom = dane[i].srednia;
            index = i;
        }
    }

    cout<<"student z najwieksza srednia to: "<<dane[index].nazwisko<<" oceny: ";
    
    for(int j = 0; j<3; j++)
    {
        cout<<dane[index].ocena[j]<<" ";
    }

    cout<<"srednia = "<<dane[index].srednia<<endl;
}
