#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#define N 100 

using namespace std;


void losuj(int T[]);
void wypisz(int T[]);
double srednia(int T[]);
double mediana(int T[]);
void ile(int T[], int Tab[]);
void f6(int Tab[]);
void histogram(int Tab[]);

int main()
{
    srand(time(NULL));

    int student[N];
    int ocena[11] = {0};
    
    
    losuj(student);

    cout<<"student = {";
    wypisz(student);
    cout<<"}\n\n";

    cout<<"srednia = "<<srednia(student)<<endl;
    cout<<"mediana = "<<mediana(student)<<endl;
    cout<<"\n";

    ile(student, ocena);
    cout<<"\n\n";
    f6(ocena);
    cout<<"\n\n\n";   
    histogram(ocena);


    system("pause");
}

void losuj(int T[])
{
    
     
    for(int i = 0; i<N; i++)
    {
        T[i] = (rand() % (10+1)) + 0; 
    }


}
void wypisz(int T[])
{
    for(int i = 0 ; i < N; i++)
    {
        if(i<N-1)
            cout<< T[i]<<", ";
        else
            cout<<T[i];
    }

}
double srednia(int T[])
{
    int suma = 0;
    double wynik = 0;

    for(int i = 0; i<N;i++)
    {
        suma += T[i];
    }
    wynik = (double)suma/N;

    return wynik;

}
double mediana(int T[])
{
    int pom;
    double wynik;
    for(int i=0;i<N;i++)
    {
        for(int j=1;j<N-i;j++)
        {
            if(T[j-1]>T[j])
            {
                pom = T[j-1];
                T[j-1] = T[j];
                T[j] = pom;
            }
        }	
    }


    if(N%2 == 0)
    {   
        wynik  = (T[N/2 -1] + T[N/2])/2.0;
    }
    else
    {
        wynik =  T[N/2];
    }

    return wynik;
		
}
void ile(int T[], int Tab[])
{
    for(int i = 0; i<N; i++)
    {
        Tab[T[i]]++; 
    }

    for(int i = 0; i<11; i++)
    {
        cout<<"ocena '"<<i<<"' wystepuje "<< Tab[i]<<" razy"<<endl;
    }
}
void f6(int Tab[])
{
    int wynik = Tab[0];
    
    for(int i = 1; i<11; i++)
    {
        if(Tab[i]>wynik)
        {
            wynik = Tab[i];
        }
    }
  
    cout<<"najwiecej jest ocen ";
    for(int i = 0; i <11; i++)
    {
        if(Tab[i] == wynik)
        {
            cout<<i<<" ";
        }
    }
    
    
} 
 void histogram(int Tab[])
{
    for(int i = 0; i<11; i++)
    {
        cout<<i<<" ";
        if(Tab[i] != 0)
        {
            for(int j = 0; j<Tab[i];j++)
            {
              cout<<" * ";
            }
        }
        
        cout<<endl;
    }
}


