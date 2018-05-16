#include <iostream>
#include <stdlib.h> //system cls
#include <conio.h>  //-getch()
#include <fstream> //odczyt i zapis tablicy osoba i firmy na dysk do pliku bin.//
#include <string.h>  //sortowanie babelkowe - rzutowanie wskaznikow lancuchow na stringi - l.558,589,527,496
//i_findex osoby, i_n numer osoby   .xxxx.xxxx struktyru zawieraj¹ca siê w strukturze
using namespace std;

/////////////////////////STRUCTURY POCZATKOWE///////////////////
struct s_adres
{
char ulica[10];  //tablica 10 znakow
int numer_domu;
char kod[10];
char miasto[10];
};
/////////////////////////STRUCTURY GLOWNE///////////////////
struct s_firma
{
char nazwa[10];
char profesja[10];
s_adres adres;
char telefon[10];
};

struct s_osoba
{
 char nazwisko[10];
 char imie[10];
 char telefon[10];
 s_adres adres;
};
////////////////////////////
void powitanie();  //zadeklarowanie
void pozegnanie();
void menu_glowne();

void dopisz_osobe();
void wypisz_wszystkie_osoby_wg_nawisk();
void wypisz_wszystkie_osoby_wg_telefonow();
void odczyt_danych_osoby();
void zmien_dane_osoby();
void usun_osobe();

void dopisz_firme();
void wypisz_wszystkie_firmy_wg_nazw();
void wypisz_wszystkie_firmy_wg_telefonow();
void odczyt_danych_firmy();
void zmien_dane_firmy();
void usun_firme();

void zapis_danych_na_dysk_osob();
void odczyt_danych_z_dysku_osob();
void zapis_danych_na_dysk_firm();
void odczyt_danych_z_dysku_firm();

void sortowanie_danych();
void sortowanie_osob_wg_nazwiska();
void sortowanie_osob_wg_telefonu();
void sortowanie_firm_wg_nazwy();
void sortowanie_firm_wg_telefonu();

////////////////////////////

s_osoba osoba[100], osoba_pom;    //osoba pom - pomocnicza przy sort bab.
s_firma firmy[100], firma_pom;
int i_os, i_f;
int n_os, n_f;
bool sort_osob=true, sort_firm=true;

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
int main()
{
    powitanie();
    odczyt_danych_z_dysku_osob();//automatyczne odczytywanie
    odczyt_danych_z_dysku_firm();//automatyczne odczytywanie
    menu_glowne();
    zapis_danych_na_dysk_osob(); //automatyczne zapisywanie
    zapis_danych_na_dysk_firm(); //automatyczne zapisywanie
    pozegnanie();
}
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////


void powitanie()
{
system("cls");
cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
cout<<"                            Ksiazka telefoniczna    :)"<<endl;
cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
cout<<"                            UWAGA!!!!!   Wcisnij ENTER aby kontynuowac"<<endl;
getch();
}

void pozegnanie()
{
system("cls");
cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
cout<<"                            Zamykamy ksiazke telefoniczna"<<endl;
cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
cout<<"                            Zapraszamy ponownie"<<endl;
getch();
system("cls");
}

void menu_glowne()
{
char znak_gl;
system("cls");
//////////////////////////////////MENU GLOWNE///////////////////////////////
cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
cout<<"                  1. Wpisywanie danych osoby"<<endl;
cout<<endl;
cout<<"                  2. Odczyt danych osoby"<<endl;
cout<<endl;
cout<<"                  3. Zmiana danych osoby  "<<endl;
cout<<endl;
cout<<"                  4. Usuwanie danych osoby"<<endl;
cout<<endl;
cout<<endl;
cout<<"                  5. Wpisywanie danych firmy"<<endl;
cout<<endl;
cout<<"                  6. Odczyt danych firmy "<<endl;
cout<<endl;
cout<<"                  7. Zmiana_danych firmy "<<endl;
cout<<endl;
cout<<"                  8. Usuwanie danych firmy "<<endl;
cout<<endl;
cout<<endl;
cout<<"                  9. Sortowanie danych "<<endl;
cout<<endl;
cout<<"                  K. Zakoncz i zapisz"<<endl;
cout<<endl;

znak_gl=getch();
if (znak_gl=='1') { dopisz_osobe();        }
if (znak_gl=='2') { odczyt_danych_osoby(); }
if (znak_gl=='3') { zmien_dane_osoby();    }
if (znak_gl=='4') { usun_osobe();          }

if (znak_gl=='5') { dopisz_firme();        }
if (znak_gl=='6') { odczyt_danych_firmy(); }
if (znak_gl=='7') { zmien_dane_firmy();    }
if (znak_gl=='8') { usun_firme();          }

if (znak_gl=='9') { sortowanie_danych();   }
if (znak_gl=='k') { pozegnanie();          }

 else
  {menu_glowne();                          }  //rekurencja, powrot do poczatku funkcji
 }

void dopisz_osobe()
{
system("cls");
  i_os++;
cout <<"Podaj nazwisko osoby    (max 10 znakow)"<<endl;
cin>> osoba[i_os].nazwisko;
cout <<endl;
cout <<"Podaj imie osoby    (max 10 znakow)"<<endl;
cin>> osoba[i_os].imie;
cout <<endl;
cout <<"Podaj ulice przy ktorej mieszka osoba    (max 10 znakow)"<<endl;
cin>> osoba[i_os].adres.ulica;
cout <<endl;
cout <<"Podaj numer domu na ulicy przy ktorej mieszka osoba    (podaj cyfre)"<<endl;
cin>> osoba[i_os].adres.numer_domu;
cout <<endl;
cout <<"Podaj kod miejscowosci w ktorej mieszka osoba    (max 10 znakow)"<<endl;
cin>> osoba[i_os].adres.kod;
cout <<endl;
cout <<"Podaj nazwe  miejscowosci w ktorej mieszka osoba    (max 10 znakow)"<<endl;
cin>> osoba[i_os].adres.miasto;
cout <<endl;
cout <<"Podaj numer telefonu osoby    (9 cyfr)"<<endl<<endl;
cin>> osoba[i_os].telefon;
getch();
}

void dopisz_firme()
{
system("cls");
i_f++;
cout <<"Podaj nazwe firmy    (max 10 znakow)"<<endl;
cin>> firmy[i_f].nazwa;
cout <<"Podaj profesje firmy    (max 10 znakow)"<<endl;
cin>> firmy[i_f].profesja;
cout <<"Podaj ulice przy ktorej dziala firma    (max 10 znakow)"<<endl;
cin>> firmy[i_f].adres.ulica;
cout <<"Podaj numer domu na ulicy przy ktorej dziala firma   (podaj liczbe)"<<endl;
cin>> firmy[i_f].adres.numer_domu;
cout <<"Podaj kod miejscowosci w ktorej dziala firma    (max 10 znakow)"<<endl;
cin>> firmy[i_f].adres.kod;
cout <<"Podaj nazwe  miejscowosci w ktorej dziala firma    (max 10 znakow)"<<endl;
cin>> firmy[i_f].adres.miasto;
cout <<"Podaj numer telefonu firmy    (9 cyfr)"<<endl;
cin>> firmy[i_f].telefon;
getch();
}

void zmien_dane_osoby()
{
system("cls");
wypisz_wszystkie_osoby_wg_nawisk();
if (i_os>0)
    {
    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<"             Podaj numer osoby, ktorej pelne dane chcesz zmienic"<<endl;
    cin>>n_os;
    system("cls");
    cout <<"Podaj nowe nazwisko osoby    (max 10 znakow)"<<endl;
    cin>> osoba[n_os].nazwisko;
    cout <<endl;
    cout <<"Podaj nowe imie osoby    (max 10 znakow)"<<endl;
    cin>> osoba[n_os].imie;
    cout <<endl;
    cout <<"Podaj nowa ulice przy ktorej mieszka osoba    (max 10 znakow)"<<endl;
    cin>> osoba[n_os].adres.ulica;
    cout <<endl;
    cout <<"Podaj nowy numer domu na ulicy przy ktorej mieszka osoba    (podaj liczbe)"<<endl;
    cin>> osoba[n_os].adres.numer_domu;
    cout <<endl;
    cout <<"Podaj nowy kod miejscowosci w ktorej mieszka osoba    (max 10 znakow)"<<endl;
    cin>> osoba[n_os].adres.kod;
    cout <<endl;
    cout <<"Podaj nowa nazwe  miejscowosci w ktorej mieszka osoba    (max 10 znakow)"<<endl;
    cin>> osoba[n_os].adres.miasto;
    cout <<endl;
    cout <<"Podaj nowy numer telefonu osoby    (9 cyfr)"<<endl;
    cin>> osoba[n_os].telefon;
    getch();
    }
}

void zmien_dane_firmy()
{
system("cls");
wypisz_wszystkie_firmy_wg_nazw();
if (i_f>0)
    {
    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<"             Podaj numer firmy, ktorej pelne dane chcesz zmienic"<<endl;
    cin>>n_f;
    system("cls");
    cout <<"Podaj nowa nazwe firmy    (max 10 znakow)"<<endl;
    cin>> firmy[n_f].nazwa;
    cout <<"Podaj nowa profesje firmy    (max 10 znakow)"<<endl;
    cin>> firmy[n_f].profesja;
    cout <<"Podaj nowa ulice przy ktorej dziala firma    (max 10 znakow)"<<endl;
    cin>> firmy[n_f].adres.ulica;
    cout <<"Podaj nowa numer domu na ulicy przy ktorej dziala firma   (podaj liczbe)"<<endl;
    cin>> firmy[n_f].adres.numer_domu;
    cout <<"Podaj nowy kod miejscowosci w ktorej dziala firma    (max 10 znakow)"<<endl;
    cin>> firmy[n_f].adres.kod;
    cout <<"Podaj nowa nazwe  miejscowosci w ktorej dziala firma    (max 10 znakow)"<<endl;
    cin>> firmy[n_f].adres.miasto;
    cout <<"Podaj nowy numer telefonu firmy    (9 cyfr)"<<endl;
    cin>> firmy[n_f].telefon;
    getch();
    }
}

void usun_osobe()
{
int i;
system("cls");
wypisz_wszystkie_osoby_wg_nawisk();
if (i_os>0)
    {
    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<"             Podaj numer osoby, ktorej dane chcesz usunac"<<endl;
    cin>>n_os;
    system("cls");
    wypisz_wszystkie_osoby_wg_nawisk();
    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<"                       Obecnie jest  "<<i_os<<" osob w ksiazce"<<endl;
    for(i=n_os;i<i_os;i++)
        {
        osoba[i]=osoba[i+1];
        }
    i_os--;
    wypisz_wszystkie_osoby_wg_nawisk();
    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<"                       Obecnie jest  "<<i_os<<" osob w ksiazce"<<endl;
    getch();
    }
}

void usun_firme()
{
int i;
system("cls");
wypisz_wszystkie_firmy_wg_nazw();
if (i_f>0)
    {
    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<"             Podaj numer firmy, ktorej dane chcesz usunac"<<endl;
    cin>>n_f;
    system("cls");
    wypisz_wszystkie_osoby_wg_nawisk();
    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<"                       Obecnie jest  "<<i_f<<" firm w ksiazce"<<endl;
    for(i=n_f;i<i_f;i++)
        {
        firmy[i]=firmy[i+1];
        }
    i_f--;
    wypisz_wszystkie_firmy_wg_nazw();
    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<"                       Obecnie jest  "<<i_f<<" firm w ksiazce"<<endl;
    getch();
    }
}

void wypisz_wszystkie_osoby_wg_nawisk()
{
int i;
if (i_os==0)
    {
    system("cls");
    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<"                 Aktualnie nie ma zadnych osob w bazie"<<endl;
    getch();
    }
if (i_os>0)
    {
    system("cls");
    for(i=1;i<=i_os;i++)
        {
        cout<< "      "<<i<<"      Nazwisko: "<<osoba[i].nazwisko<<" Imie: "<<osoba[i].imie<<endl;
        }
    }
}

void wypisz_wszystkie_firmy_wg_nazw()
{
int i;
if (i_f==0)
    {
    system("cls");
    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<"                 Aktualnie nie ma zadnych firm w bazie"<<endl;
    getch();
    }
if (i_f>0)
    {
    system("cls");
    for(i=1;i<=i_f;i++)
        {
        cout<< "     "<<i<<"      Nazwa: "<<firmy[i].nazwa<<endl;
        }
    }
}

void wypisz_wszystkie_osoby_wg_telefonow()
{
int i;
if (i_os==0)
    {
    system("cls");
    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<"                 Aktualnie nie ma zadnych osob w bazie"<<endl;
    getch();
    }
if (i_os>0)
    {
    system("cls");
    for(i=1;i<=i_os;i++)
        {
        cout<< "       "<<i<<"      Telefon to: "<<osoba[i].telefon<<endl;
        }
    }
};

void wypisz_wszystkie_firmy_wg_telefonow()
{
int i;
if (i_f==0)
    {
    system("cls");
    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<"                 Aktualnie nie ma zadnych firm w bazie"<<endl;
    getch();
    }
if (i_f>0)
    {
    system("cls");
    for(i=1;i<=i_f;i++)
        {
        cout<< "       "<<i<<"      Telefon to: "<<firmy[i].telefon<<endl;
        }
    }
};

void odczyt_danych_osoby()
{
system("cls");
if (sort_osob==true) {wypisz_wszystkie_osoby_wg_nawisk();}
if (sort_osob==false) {wypisz_wszystkie_osoby_wg_telefonow();}
if (i_os>0)
    {
    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<"             Podaj numer osoby, ktorej pelne dane chcesz znac"<<endl;
    cin>>n_os;
    system("cls");
    cout <<"Nazwisko osoby:"<<endl;
    cout <<osoba[n_os].nazwisko<<endl<<endl;
    cout <<"Imie osoby:"<<endl;
    cout << osoba[n_os].imie<<endl<<endl;
    cout <<"Ulice przy ktorej mieszka osoba:"<<endl;
    cout <<osoba[n_os].adres.ulica<<endl<<endl;
    cout <<"Numer domu"<<endl;
    cout <<osoba[n_os].adres.numer_domu<<endl<<endl;
    cout <<"Kod miejscowosci"<<endl;
    cout << osoba[n_os].adres.kod<<endl<<endl;
    cout <<"Nazwa miejscowosci"<<endl;
    cout <<osoba[n_os].adres.miasto<<endl<<endl;
    cout <<"Numer telefonu:"<<endl;
    cout << osoba[n_os].telefon<<endl<<endl;
    getch();
    }
}

void odczyt_danych_firmy()
{
system("cls");
if (sort_firm==true)  {wypisz_wszystkie_firmy_wg_nazw();}
if (sort_firm==false) {wypisz_wszystkie_firmy_wg_telefonow();}
if (i_f>0)
    {
    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<"             Podaj numer firmy, ktorej pelne dane chcesz znac"<<endl;
    cin>>n_f;
    system("cls");
    cout <<"Nazwa firmy:"<<endl;
    cout <<firmy[n_f].nazwa<<endl<<endl;
    cout <<"Profesja firmy:"<<endl;
    cout <<firmy[n_f].profesja<<endl<<endl;
    cout <<"Ulice przy ktorej dziala firma:"<<endl;
    cout <<firmy[n_f].adres.ulica<<endl<<endl;
    cout <<"Numer domu"<<endl;
    cout <<firmy[n_f].adres.numer_domu<<endl<<endl;
    cout <<"Kod miejscowosci"<<endl;
    cout << firmy[n_f].adres.kod<<endl<<endl;
    cout <<"Nazwa miejscowosci"<<endl;
    cout <<firmy[n_f].adres.miasto<<endl<<endl;
    cout <<"Numer telefonu:"<<endl;
    cout << firmy[n_f].telefon<<endl<<endl;
    getch();
    }
}

void sortowanie_danych()
{
char znak_sort;
system("cls");
//////////////////////////////////MENU GLOWNE///////////////////////////////
cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
cout<<"                  1. Sortowanie osob wedlug nazwiska "<<endl;
cout<<endl;
cout<<"                  2. Sortowanie osob wedlug telefonu"<<endl;
cout<<endl;
cout<<endl;
cout<<"                  3. Sortowanie firm wedlug nazwy "<<endl;
cout<<endl;
cout<<"                  4. Sortowanie firm wedlug telefonu"<<endl;
cout<<endl;
cout<<endl;
cout<<"                  W. Wroc"<<endl;
cout<<endl;
znak_sort=getch();
if (znak_sort=='1') {  sortowanie_osob_wg_nazwiska();   sortowanie_danych(); }
if (znak_sort=='2') {  sortowanie_osob_wg_telefonu();   sortowanie_danych(); }

if (znak_sort=='3') {  sortowanie_firm_wg_nazwy();      sortowanie_danych(); }
if (znak_sort=='4') {  sortowanie_firm_wg_telefonu();   sortowanie_danych(); }
if (znak_sort=='w') {  menu_glowne(); }
 else
  {sortowanie_danych(); }
}

void sortowanie_osob_wg_nazwiska()
{
system("cls");
int i,j;
if (i_os==0)
    {
    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<"                   Brak danych do osobowych posortowania"<<endl;
    getch();
    }
if (i_os>0)
    {
    for(i=1;i<=i_os;i++)
       {
       for(j=1;j<=i_os;j++)
          {//////////////////////////////////////////
          if((string)osoba[j].nazwisko>(string)osoba[j+1].nazwisko)
               {
               osoba_pom=osoba[j];
               osoba[j]=osoba[j+1];
               osoba[j+1]=osoba_pom;
               }
          }////////////////////////////////////////////
       }
       cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
       cout<<"                   Dane zostaly posortowane wedlug nawisk osob"<<endl;
       sort_osob=true;
       getch();
    }
};

void sortowanie_osob_wg_telefonu()
{
system("cls");
int i,j;
if (i_os==0)
    {
    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<"                   Brak danych ososbowych do posortowania"<<endl;
    getch();
    }
if (i_os>0)
    {
    for(i=1;i<=i_os;i++)
       {
       for(j=1;j<=i_os;j++)
          {//////////////////////////////////////////
          if((string)osoba[j].telefon>(string)osoba[j+1].telefon)
               {
               osoba_pom=osoba[j];
               osoba[j]=osoba[j+1];
               osoba[j+1]=osoba_pom;
               }
          }////////////////////////////////////////////
       }
       cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
       cout<<"                   Dane zostaly posortowane wedlug numerow telefonow osob"<<endl;
       sort_osob=false;
       getch();
    }
};

void sortowanie_firm_wg_nazwy()
{
system("cls");
int i,j;
if (i_f==0)
    {
    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<"                   Brak danych firmowych do posortowania"<<endl;
    getch();
    }
if (i_f>0)
    {
    for(i=1;i<=i_os;i++)
       {
       for(j=1;j<=i_os;j++)
          {//////////////////////////////////////////
          if((string)firmy[j].nazwa>(string)firmy[j+1].nazwa)
               {
               firma_pom=firmy[j];
               firmy[j]=firmy[j+1];
               firmy[j+1]=firma_pom;
               }
          }////////////////////////////////////////////
       }
       cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
       cout<<"                   Dane zostaly posortowane wedlug nazw firm"<<endl;
       sort_firm=true;
       getch();
    }
};

void sortowanie_firm_wg_telefonu()
{
system("cls");
int i,j;
if (i_f==0)
    {
    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<"                   Brak danych firmowych do posortowania"<<endl;
    getch();
    }
if (i_f>0)
    {
    for(i=1;i<=i_os;i++)
       {
       for(j=1;j<=i_os;j++)
          {//////////////////////////////////////////
          if((string)firmy[j].telefon>(string)firmy[j+1].telefon)
               {
               firma_pom=firmy[j];
               firmy[j]=firmy[j+1];
               firmy[j+1]=firma_pom;
               }
          }////////////////////////////////////////////
       }
       cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
       cout<<"                   Dane zostaly posortowane wedlug numerow telefonow firm"<<endl;
       sort_firm=false;
       getch();
    }
};

void odczyt_danych_z_dysku_osob()
{
system("cls");
fstream plik1;
plik1.open("dane_osob.bin",ios::binary|ios::in);//in-odczyt danych
if( plik1.good() == true )
     {
     plik1.read((char*)&osoba,sizeof(osoba));
     }
else
     {
     cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
     cout << "              Dostep do pliku zostal zabroniony!" << endl;
     getch();
     }
plik1.close();

fstream plik2;
plik2.open("dane_osob.ios",ios::binary|ios::in);//in-odczyt danych
if( plik2.good() == true )
     {
     plik2.read((char*)&i_os,sizeof(i_os));
     }
plik2.close();
}

void zapis_danych_na_dysk_osob()
{
system("cls");
fstream plik1;
plik1.open("dane_osob.bin",ios::binary|ios::trunc|ios::out);//out-zapis danych,app-dopisywanie danych
if( plik1.good() == true )
     {
     plik1.write((char*)&osoba,sizeof(osoba));
     system("cls");
     }
else
     {
     cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
     cout << "              Dostep do pliku zostal zabroniony!" << endl;
     getch();
     }
plik1.close();

fstream plik2;
plik2.open("dane_osob.ios",ios::binary|ios::trunc|ios::out);//out-zapis danych,app-dopisywanie danych
if( plik2.good() == true )
     {
     plik2.write((char*)&i_os,sizeof(i_os));
     }
plik2.close();
}

void odczyt_danych_z_dysku_firm()
{
system("cls");
fstream plik1;
plik1.open("dane_firm.bin",ios::binary|ios::in);//in-odczyt danych
if( plik1.good() == true )
     {
     plik1.read((char*)&firmy,sizeof(firmy));
     }
else
     {
     cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
     cout << "              Dostep do pliku zostal zabroniony!" << endl;
     getch();
     }
plik1.close();

fstream plik2;
plik2.open("dane_firm.iof",ios::binary|ios::in);//in-odczyt danych
if( plik2.good() == true )
     {
     plik2.read((char*)&i_f,sizeof(i_f));
     }
plik2.close();
}

void zapis_danych_na_dysk_firm()
{
system("cls");
fstream plik1;
plik1.open("dane_firm.bin",ios::binary|ios::trunc|ios::out);//out-zapis danych,app-dopisywanie danych
if( plik1.good() == true )
     {
     plik1.write((char*)&firmy,sizeof(firmy));
     system("cls");
     }
else
     {
     cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
     cout << "              Dostep do pliku zostal zabroniony!" << endl;
     getch();
     }
plik1.close();

fstream plik2;
plik2.open("dane_firm.iof",ios::binary|ios::trunc|ios::out);//out-zapis danych,app-dopisywanie danych
if( plik2.good() == true )
     {
     plik2.write((char*)&i_f,sizeof(i_f));
     }
plik2.close();
}
