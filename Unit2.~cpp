//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <fstream>

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;

//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm2::FormCreate(TObject *Sender)
{
    Label1->Left = background->Width/2 - Label1->Width/2;
    Label1->Top = 40;
    Label2->Caption = "Welcome, welcome... This game is the final test of your\n"
                      "abilities. If you two will pass THIS you will prove that you have\n"
                      "an eagle eye and dexterity of ninja. Rules of the TEST are quite\n"
                      "simple..and difficult - it depends of you... First of all you have to\n"
                      "choose one of these colors for your paddle. Then you start\n"
                      "a match in a ping-pong game, so you will be able to prove your\n"
                      "skills and experience. Once the game is started make the mind\n"
                      "clear and observe if color of THE BALL is the same like your\n"
                      "paddle. If it is!...you must not even touch it! If you do...you lost\n"
                      "a point :) So deep breathe and... Let's play game... ;p";
                      
    Label2->Left = background->Width/2 - Label2->Width/2;
    Label2->Top = Label1->Top + 65;

}
//---------------------------------------------------------------------------


void __fastcall TForm2::startButtonClick(TObject *Sender)
{
    Form2->Close();    
}
//---------------------------------------------------------------------------



