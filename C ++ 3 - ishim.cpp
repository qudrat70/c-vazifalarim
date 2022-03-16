#include <iostream>
using namespace std;
int row, column; 
struct Fraction
{
  int up, down = 1; 
}; 
Fraction table[50][50]; 
int answer[51]; 
int head[51]; 
int inBase(); 
int outBase(int); 
void showTable(); 
Fraction reduction(Fraction); 
Fraction add(Fraction, Fraction); 
Fraction minu(Fraction, Fraction); 
Fraction multi(Fraction, Fraction); 
Fraction divide(Fraction, Fraction); 
int abs(int); 
int gcd(int, int);
int main()
{  
  cout << "Matritsa o'lchamini kiriting : "; cin>>row>>column;
  cout << "Matritsa qiymatlarini kiriting : " << endl;
  for (int i = 1; i <= row; i++)
  {
    for (int j = 1; j <= column; j++)
    {
      cin >> table[i][j].up;
    }
  }
  cout << "Simpleks jadvalning satr o'zgaruvchisini kiriting : " << endl;
  for (int i = 2; i <= row; i++)
    cin >> answer[i];
    cout << "Simpleks jadvalning ustun o'zgaruvchisini kiriting : " << endl;
    for (int i = 1; i <= column-1; i++)
    cin >> head[i];
  cout << "_________________________________________________________" << endl;
  showTable();
  cout << endl;
  int inVar = inBase(); 
  int outVar; 
  int isOk = 0; 
  while (!isOk)
  {
    if (inVar == 0)
    {
      isOk = 1;
    }
    else
    {
      outVar = outBase(inVar);
      if (outVar == 0)
      {
        isOk = 2;
      }
    }
    if (!isOk)
    {
      Fraction temp = table[outVar][inVar];
      for (int j = 1; j <= column; j++)
        table[outVar][j] = divide(table[outVar][j], temp);
      for (int i = 1; i <= row; i++)
      {
        if (i == outVar)
          continue;
        else
        {
          temp = table[i][inVar];
          temp.up = -temp.up;
          for (int j = 1; j <= column; j++)
            table[i][j] = add(multi(temp, table[outVar][j]), table[i][j]);
        }
      }
      answer[outVar] = inVar;
      showTable();
      inVar = inBase();
      cout << endl;
    }
  }
  if (isOk == 1)
  {
    cout << "Masalaning yechimi quyidagicha ! " << endl;
    cout << "eng kichik qiymati min = ";
    if (table[1][column].down == 1)
      cout << table[1][column].up << endl;
    else
      cout << table[1][column].up << "/" << table[1][column].down << endl;
  }
  else
  {
    cout << "Yechim ko'p!" << endl;
  }
  return 0;
}
int inBase()
{
  int result = 0;
  for (int j = 1; j <= column-1; j++)
  {
    if (table[1][j].up > 0)
    {
      if (result == 0)
        result = j;
      else if (minu(table[1][j], table[1][result]).up > 0)
        result = j;
    }
  }
  return result;
}
int outBase(int num)
{
  int result = 0; 
  Fraction temp[column+1]; 
  for (int i = 2; i <= row; i++)
  {
    if (table[i][num].up > 0)
    {
      if (result == 0)
        result = i;
      temp[i] = divide(table[i][column], table[i][num]);
      if (minu(temp[i], temp[result]).up < 0)
        result = i;
    }
  }
  return result;
}
void showTable()
{
  cout << "    ";
  for (int i = 1; i <= column-1; i++)
    cout << "x" << head[i] << "   ";
  cout << endl;
  cout << "    ";
  for (int j = 1; j <= column; j++)
  {
    if (table[1][j].down == 1)
      cout << table[1][j].up << "   ";
    else
      cout << table[1][j].up << "/" << table[1][j].down << "  ";
  }
  cout << endl;
  for (int i = 2; i <= row; i++)
  {
    cout << "x" << answer[i] << "  ";
    for (int j = 1; j <= column; j++)
    {
      if (table[i][j].down == 1)
        cout << table[i][j].up << "   ";
      else
        cout << table[i][j].up << "/" << table[i][j].down << "  ";
    }
    cout << endl;
  }
}
Fraction reduction(Fraction result)
{
  if (result.down < 0)
  {
    result.up = -result.up;
    result.down = -result.down;
  }
  if (result.up == 0)
  {
    result.down = 1;
  }
  else
  {
    int d = gcd(abs(result.up), abs(result.down));
    result.up /= d;
    result.down /= d;
  }
  return result;
}
Fraction add(Fraction f1, Fraction f2)
{
  Fraction result;
  result.up = f1.up * f2.down + f2.up * f1.down;
  result.down = f1.down * f2.down;
  return reduction(result);
}
Fraction minu(Fraction f1, Fraction f2)
{
  Fraction result;
  result.up = f1.up * f2.down - f2.up * f1.down;
  result.down = f1.down * f2.down;
return reduction(result);
}
Fraction multi(Fraction f1, Fraction f2)
{
  Fraction result;
  result.up = f1.up * f2.up;
  result.down = f1.down * f2.down;
  return reduction(result);
}
Fraction divide(Fraction f1, Fraction f2)
{
  Fraction result;
  result.up = f1.up * f2.down;
  result.down = f1.down * f2.up;
  return reduction(result);
}
int gcd(int a, int b)
{
  return !b ? a : gcd(b, a%b);
}
int abs(int a)
{
  if (a < 0)
    return -a;
  else
    return a;
}
