#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;
// osoba = liczba, wiek = wartosc, 

struct liczba 
{
    int wartosc;
    liczba *nastepna; // wskaznik na nastepny element
    liczba(); // konstruktor
};

liczba::liczba() 
{
    nastepna = 0; // konstruktor
}

struct lista {
    liczba *pierwsza; // wskaznik na poczatek listy
    void dodaj_liczbe(int wartosc);
    void usun_liczbe(int nr);
    void wyswietl_liste();
    void jedynki();
    lista();
};

lista::lista() {
    pierwsza = 0; // konstruktor
}

void lista::dodaj_liczbe(int wartosc)
{
    liczba *nowa = new liczba;    // tworzy nowy element listy
    
    // wypelniamy naszymi danymi
    nowa->wartosc = wartosc;
    
    if (pierwsza==0) // sprawdzamy czy to pierwszy element listy
    {
        // jezeli tak to nowy element jest teraz poczatkiem listy
        pierwsza = nowa;
    }
    else
    {
        // w przeciwnym wypadku wedrujemy na koniec listy
        liczba *temp = pierwsza;
        
        while (temp->nastepna)
        {
            // znajdujemy wskaznik na ostatni element
            temp = temp->nastepna;
        }
        
        temp->nastepna = nowa;  // ostatni element wskazuje na nasz nowy
        nowa->nastepna = 0;     // ostatni nie wskazuje na nic
    }  
}

void lista::jedynki() // szuka powtarzajacych sie podciagow zaczynajacych sie od 1 i je wypisuje
{	int j=0, z=0, repz=0, b=0;  // (j) to licznik Jedynek (z) Zer
    // wskaznik na pierszy element listy
    liczba *temp = pierwsza;
    // przewijamy wskazniki na nastepne elementy
    while (temp)
    {
		if (temp->wartosc==1) // jesli podana liczba to 1, zacznij liczyc
		{	
			if (z>=2) // jesli byly juz 2 zera... wez mniejsza i zrob petle, potem zresetuj z i j
			{
				if(z<j) // jesli z jest mniejsze od j
				{	//wez z powtorzen
					repz=z;
					cout << "[";
					
					while (repz>0)
					{
						cout << "1";
						repz--;
					}
					
					repz=z;
					while (repz>0)
					{
						cout << "0";
						repz--;	
					}
					cout << "], ";
					z=0, j=0; // resetuje liczniki zer i jedynek
					b=1; // spelnia zdane kryteria
				}
				
				else
				{ // wez j powtorzen
					repz=j;
					cout << "[";
					
					while (repz>0)
					{
						cout << "1";
						repz--;
					}
					
					repz=j;
					while (repz>0)
					{
						cout << "0";
						repz--;
					}
					cout << "], ";
					z=0, j=0; // resetuje liczniki zer i jedynek
					b=1; // spelnia zdane kryteria
				};
			}
			j++;
		}
        else if (temp->wartosc==0) // jesli podana liczba to 0...
        {
			if (j>=2)// jesli byly juz przynajmniej 2 jedynki to: teraz licz (j) ilosc zer
			{
			z++;
			}
			else // jesli nie to:     
			{
				z=0, j=0;
			};	
			
			if ((j==z) && (j>=2))
			{
				repz=j;
				cout << "[";
				
				while (repz>0)
				{
					cout << "1";
					repz--;
				}
					
				repz=j;
				while (repz>0)
				{
					cout << "0";
					repz--;
				}
				
				cout << "], ";
				z=0, j=0; // resetuje liczniki zer i jedynek
				b=1; // spelnia zdane kryteria
			}
		}
		else // podano wartosc inna niz 1 lub 0, koniec ciagu
		{
			cout<<'\b'; // usuwa ostatnia litere, w tym przypadku ,
			cout<<'\b';
  			cout<<" ";
		};

        
        temp=temp->nastepna; // przewija do nastepnej liczby w ciagu
    }
    if (b==0)
    {
    	cout<< "\nBrak elementow spelniajacych zdane kryteria.";	
	};
}

int main()
{
    lista *baza = new lista;    //tworzymy liste

	int i=0;
	int wartosc=0;//dodajemy rekordy do bazy
	
	cout << "Podaj ciag cyfer, wpisz cyfre inna niz 1 lub 0 aby zakonczyc\n";
	while(i==0 || i==1) // petla zapisujaca podane cyfry 
	{
		cin>>wartosc;
		i = wartosc;
		baza->dodaj_liczbe(wartosc);	
	}	
	
	cout << endl;
	
	baza->jedynki();
	
	
return 0;	
}
