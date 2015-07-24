//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "stdio.h"

int a[20][20];  // ������ ����� 20*20 ������
int x=30,y=30;
int live=0;

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
 switch(Key)
 {
  case VK_LEFT :        /// ������ �����
  if(a[x/30-1][y/30]!=1)
  {
  if(a[x/30-1][y/30]==2) { a[x/30-1][y/30]=0; live++; } // ���� ����� ������� ����������� �����
  x-=30;
  }
  break;

  case VK_UP :       /// ������ �����
  if(a[x/30][y/30-1]!=1)
  {
  if(a[x/30][y/30-1]==2) { a[x/30][y/30-1]=0; live++; } // ���� ����� ������� ����������� �����
  y-=30;
  }
  break;

  case VK_RIGHT :  /// ������ ������
  if(a[x/30+1][y/30]!=1)
  {
   if(a[x/30+1][y/30]==2) {a[x/30+1][y/30]=0; live++; }  // ���� ����� ������� ����������� �����
   x+=30;
  }
  break;

  case VK_DOWN :   /// ������ ����
  if(a[x/30][y/30+1]!=1)
  {
   if(a[x/30][y/30+1]==2) {a[x/30][y/30+1]=0; live++; } // ���� ����� ������� ����������� �����
   y+=30;
  }
  break;

 }
 FormPaint(Sender);
         
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormPaint(TObject *Sender)
{
   for(int i=0;i<20;i++)
   {
   for(int j=0;j<20;j++)
   {
    switch(a[i][j])
    {
      case 0 : Form1->Canvas->Brush->Color=clGreen; break;
      case 1 : Form1->Canvas->Brush->Color=clRed; break;
      case 2 : Form1->Canvas->Brush->Color=clYellow; break;
    }
    Form1->Canvas->Rectangle(i*30,j*30,i*30+30,j*30+30);  // 30 = ������ ������ � ��������
   }
   }
   Form1->Canvas->Ellipse(x,y,x+30,y+30);  // ������ ���������
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
  FILE *f;
  if(f=fopen((ExtractFilePath(Application->ExeName) + "map.txt").c_str(),"r"))
  {
   for(int i=0;i<20;i++)
   {
   for(int j=0;j<21;j++)  // �� ������� ������ ��-�� ������� ����� ������
   {
    char t=fgetc(f);
    switch(t)
    {
    case '0' : a[i][j]=0; break;  // 48 - ��� ������� 0
    case '1' : a[i][j]=1; break;  // 49 - ��� ������� 1
    case '2' : a[i][j]=2; break;  // 50 - ��� ������� 2
    }
   }
   }
   }
}
//---------------------------------------------------------------------------
