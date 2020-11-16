//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop


#include "Unit4.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm4 *Form4;

//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm4::nextButtonClick(TObject *Sender)
{
    if (nextButton->Caption == "Another time :)") Application->Terminate();
    else Form4->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm4::restartButtonClick(TObject *Sender)
{
    Form1->playAgain();
    Form4->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm4::FormClose(TObject *Sender, TCloseAction &Action)
{
    if(nextButton->Caption != "Next Set") Application->Terminate();    
}
//---------------------------------------------------------------------------
