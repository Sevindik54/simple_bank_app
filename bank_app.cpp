#include <iostream>
using namespace std;
class Bank
 {private:
 int HesapNo;
 char ad[30];
 long tutar;
 
 public:
 void OpenAccount()
 {cout << "Hesap No Giriniz: ";
 cin >> HesapNo;
 cout << "Musteri ismi: ";
 cin >> ad;
 cout << "Tutar: ";
 cin >> tutar;
 }
 void ShowAccount()
 {cout << "Hesap No: " << HesapNo << endl;
 cout << "ad: " << ad << endl;
 cout << "tutar: " << tutar << endl;
 }
 void Deposit()
 {
 long Ytutar;
 cout << "yatiralacak para tutari giriniz? ";
 cin >> Ytutar;
 tutar = tutar + Ytutar;
 }
 void Withdrawal()
 {long Ctutar;
 cout << "Para cekilecek tutari giriniz? ";
 cin >> Ctutar;
 if (Ctutar <= tutar)
 tutar = tutar - Ctutar;
 else
 cout << "hesap bakiyeniz..." << endl;
 }
 int Search(int);
 };
 int Bank::Search(int a)
 {
 if (HesapNo == a) 
 {ShowAccount();
 return (1);
 }
 return (0);
 }
 int main()
 {
 int g;
 cout<<"kas kisilik bir hesap olacaktir?"<<endl;
 cin>>g;Bank C[g];
 int found = 0, a, ch, i;
 for (i = 0; i < g; i++){
 	C[i].OpenAccount();
  }
  
  do {
  	cout << "\n\n1:Hepsini goster \n2:Hesap No ile ara \n3:Para Yatirma \n4:ParaCekmem\n5:Exit" << endl;
	  cout << "islem yapmak istediginz menu giriniz: ";
	  cin >> ch;
	  switch (ch)
	   {case 1:for (i = 0; i <g; i++){
	   C[i].ShowAccount();
		}
		break;
		case 2:
		cout << "hesap no? ";
		cin >> a;
		for (i = 0; i <g; i++) {found = C[i].Search(a);
		if (found)
		break;
		}
		if (!found)
		cout << "Hesap No yalnistir" << endl;
		break;
		case 3:
		cout << "hesap no? ";
		cin >> a;
		for (i = 0; i <g; i++)
		 {found = C[i].Search(a);
		 if (found)
		  {C[i].Deposit();
		 break;
		 }
		}
		if (!found)
		cout << "bulunamadi" << endl;
		break;
		case 4:
		cout << "hesap no? ";
		cin >> a;
		for (i = 0; i < g; i++)
		 {found = C[i].Search(a);
		 if (found) {C[i].Withdrawal();
		 break;
		 }
		 }if (!found)
		 cout << "bulunamadi" << endl;
		 break;
		 case 5: // exit
		 cout << "iyi gunler iyi calismalar" << endl;
		 break;
		 default:
		 cout << "Yalnis menu" << endl;
		 }
		 }while (ch != 5);
		 return 0;}
