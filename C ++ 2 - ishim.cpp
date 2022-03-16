#include <iomanip>
#include <valarray>
#include <iostream>
#include <string>
using namespace std;
int main()
{ valarray <char> belgi('*',25);
for(int i=0;i<25;i++)
 cout<<setw(2)<<belgi[i];
 cout<<endl;
 size_t boshlash=2;	
 size_t uzunlik[]={4,3};
 size_t farq[]={4,3};
 gslice kif213(boshlash,valarray<size_t>(uzunlik,2),valarray<size_t>(farq,2));
 belgi[kif213]='%';
  cout<<"yangi qiymatlar"<<endl;
  for(int i=0;i<belgi.size();i++)
 cout<<setw(2)<<belgi[i];
 cout<<endl;
 cout<<"yangi qiymatlar indexlari"<<endl;
  for(int i=0;i<belgi.size();i++)
  {
  	 if(belgi[i]=='%')cout<<setw(3)<<i;}
cout<<endl;
system("Pause");
return 0;
}
