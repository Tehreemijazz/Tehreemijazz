#include<iostream>
#include<cstdlib>
#include<string.h>
using namespace std;
int main() {
 char cond;
string n;
int p;
 cout << " ------------------------------" << endl;
 cout << " -----CEASER CIPHER MACHINE----" << endl;
 cout << " ------------------------------" << endl;
 cout << " _                                   _" << endl;
 cout << "|              Developers             |" << endl;
 cout << "|        Tehreem Ijaz (22-CS-41)      |" << endl;
 cout << "|        Rameen Hassan (22-CS-84)     |" << endl;
 cout << "|_                                   _|" << endl;
 cout << "\nThis Program is For Personal Use! \nNo One Can Access Other then Developers." << endl;
 cout << "\nLOGIN " << endl;
  do {
 cout << "\nEnter Your Name in Block letters = "; 
 cin >> n;
 cout << "Enter Your Password Provided By Company = ";
  //cin >> p;
  while(!(cin>>p)){
  	cout<<"Error a number must be enter";
  	cin.clear();
  	cin.ignore(123,'\n');
  }
 if ((n == "TEHREEM") || (n == "RAMEEN"))
 {
 if ((p == 1234) || (p == 5678))
 {
 cout << "       ***    " << endl;
 cout << " Access Granted" << endl;
 cout << "       ***    " << endl;
 cout << ":::::::::::::::::::::::::::::::::::" << endl;
 cout << ":::::::::::::::::::::::::::::::::::" << endl;
 cout << "::Welcome To Ceaser Cipher Machine:" << endl;
 cout << ":::::::::::::::::::::::::::::::::::" << endl;
 cout << ":::::::::::::::::::::::::::::::::::" << endl;
 cout << "\n\n\nUse(_)Underscores Instead of Blank Spaces" << endl;
 cout << "\nEnter the message:" << endl;
 char msg[100];
char ch;
//take the message as input
 cin >> msg; 
 int i = 0,choice, key=5;
 cout << "Tehreem and Rameen cipher conversation activated!\n";
 cout << "Enter your choice \n1. Encryption \n2. Decryption \n";
 cin >> choice;
 //for encryption
 if (choice == 1) 
 {
 for (int i = 0; msg[i] != '\0'; ++i) {
 ch = msg[i];
 //encrypt for lowercase letter
if (ch >= 'a' && ch <= 'z') {
 ch = ch + key;
 if (ch > 'z') {
 ch = ch - 'z' + 'a' - 1;
 }
 msg[i] = ch;
 }
 //encrypt for uppercase letter
else if (ch >= 'A' && ch <= 'Z') {
 ch = ch + key;
 if (ch > 'Z') {
 ch = ch - 'Z' + 'A' - 1;
 }
 msg[i] = ch;
 }
 }
 cout << "The Encrypted Message is = \n";cout << msg;
 }
 //for decryption
 	if(choice==2)
		{
			char ch;
			for(int i=0;msg[i]!='\0';++i)
			{
				ch==msg[i];
				//decrypt for lowercase letter
				if(ch>='a'&& ch<='z'){
					if(ch<'a'){
						ch=ch+'z' -'a'+1;
					}
					msg[i]=ch;
				}
				//decrypt for uppercase letter
				else if(ch>='A'&& ch<='Z'){
					if(ch<'A'){
						ch=ch+'Z' -'A'+1;
					}
					msg[i]=ch;
				}
			}
			cout<<" Decrypted message is =\n"<<msg;
			}		
 }
 else
 cout << "Ooops We Think You Forget Your Password...!";
 }
 else
 cout << "How Can You Forget Your Name Man? (-_-)";
 cout << "\nWant to repeat the cipher? (Y/N) " << endl;
 cin >> cond;
 } while (cond == 'Y' || cond == 'y');
  system("pause");
 return 0;
}
