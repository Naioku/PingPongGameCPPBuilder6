//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "mmsystem.h"

#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
#include "Unit4.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

char* ballBluePicture = "images/ballBlue.bmp";
char* ballGrayPicture = "images/ballGray.bmp";
char* ballLightGreenPicture = "images/ballLightGreen.bmp";
char* ballOrangePicture = "images/ballOrange.bmp";
char* ballWhitePicture = "images/ballWhite.bmp";
char* ballYellowPicture = "images/ballYellow.bmp";

char* paddleBluePicture = "images/paddleBlue.bmp";
char* paddleGrayPicture = "images/paddleGray.bmp";
char* paddleLightGreenPicture = "images/paddleLightGreen.bmp";
char* paddleOrangePicture = "images/paddleOrange.bmp";
char* paddleWhitePicture = "images/paddleWhite.bmp";
char* paddleYellowPicture = "images/paddleYellow.bmp";

int ballColorNumber = 0;
int leftPaddleColorNumber = 0;
int rightPaddleColorNumber = 1;

int moveBallHorizontal = -10;
int moveBallVertical = -6;

int leftPlayerPoints = 0;
int rightPlayerPoints = 0;
int leftPlayerWonSets = 0;
int rightPlayerWonSets = 0;
int setNumber = 1;

void TForm1::resetPositions()
{
    // paddles
    Form1->paddleLeft->Left = 40;
    Form1->paddleLeft->Top = Form1->background->Height/2 - Form1->paddleLeft->Height/2;
    Form1->paddleRight->Left = Form1->background->Width - (40 + Form1->paddleRight->Width);
    Form1->paddleRight->Top = Form1->background->Height/2 - Form1->paddleRight->Height/2;

    // ball
    Form1->ball->Left = Form1->background->Width/2 - Form1->ball->Width/2;
    Form1->ball->Top = Form1->background->Height/2 - Form1->ball->Height/2;

    // ready label
    Form1->Label1->Left = Form1->background->Width/2 - Form1->Label1->Width/2;
    Form1->Label1->Top = Form1->background->Height/2 - Form1->Label1->Height/2;

    // points label
    Form1->Points->Left = Form1->background->Width/2 - Form1->Points->Width/2;
    Form1->Points->Top = 40;

    // left player points label
    Form1->leftPlayerPointsLabel->Left = Form1->Points->Left - Form1->leftPlayerPointsLabel->Width - 20;
    Form1->leftPlayerPointsLabel->Top = 40;

    // right player points label
    Form1->rightPlayerPointsLabel->Left = Form1->Points->Left + Form1->Points->Width + 20;
    Form1->rightPlayerPointsLabel->Top = 40;

    // sets label
    Form1->setsLabel->Left = Form1->background->Width/2 - Form1->setsLabel->Width/2;
    Form1->setsLabel->Top = Form1->background->Height - Form1->setsLabel->Height - 40;

    // left player sets label
    Form1->leftPlayerSetsLabel->Left = Form1->setsLabel->Left - Form1->leftPlayerSetsLabel->Width - 20;
    Form1->leftPlayerSetsLabel->Top = Form1->background->Height - Form1->setsLabel->Height - 40;

    // right player sets label
    Form1->rightPlayerSetsLabel->Left = Form1->setsLabel->Left + Form1->setsLabel->Width + 20;
    Form1->rightPlayerSetsLabel->Top = Form1->background->Height - Form1->setsLabel->Height - 40;

    // pause label
    Form1->pauseLabel->Left = Form1->background->Width/2 - Form1->pauseLabel->Width/2;
    Form1->pauseLabel->Top = Form1->background->Height/2 - Form1->pauseLabel->Height/2;

    // settings menu
    Form1->Panel1->Left = Form1->background->Width/2 - Form1->Panel1->Width/2;
    Form1->Panel1->Top = Form1->background->Height/2 - Form1->Panel1->Height/2;
}

void TForm1::stopGame()
{
    Form1->ballTimer -> Enabled = false;
    Form1->ball -> Visible = false;
}

void TForm1::startGame()
{
    Form1->ballTimer -> Enabled = true;
    Form1->ball -> Visible = true;
}

void TForm1::nextRound(char whoWon)
{
    stopGame();
    resetPositions();
    if (whoWon == 'L') moveBallHorizontal = -10; // left won, so left is bouncing first, etc.
    else if (whoWon == 'R') moveBallHorizontal = 10;
    ready();
}

void TForm1::playBallBounceSound()
{
    switch (ballColorNumber)
    {
        case 0:
        {
            sndPlaySound("sounds/ballBounce1.wav", SND_ASYNC);
            break;
        }
        case 1:
        {
            sndPlaySound("sounds/ballBounce2.wav", SND_ASYNC);
            break;
        }
        case 2:
        {
            sndPlaySound("sounds/ballBounce3.wav", SND_ASYNC);
            break;
        }
        case 3:
        {
            sndPlaySound("sounds/ballBounce4.wav", SND_ASYNC);
            break;
        }
        case 4:
        {
            sndPlaySound("sounds/ballBounce5.wav", SND_ASYNC);
            break;
        }
        case 5:
        {
            sndPlaySound("sounds/ballBounce6.wav", SND_ASYNC);
            break;
        }
    }
}

void TForm1::changeBallColor()
{
    ballColorNumber = random(6);

    switch (ballColorNumber)
    {
        case 0:
        {
            Form1->ball->Picture->LoadFromFile(ballBluePicture);
            break;
        }
        case 1:
        {
            Form1->ball->Picture->LoadFromFile(ballGrayPicture);
            break;
        }
        case 2:
        {
            Form1->ball->Picture->LoadFromFile(ballLightGreenPicture);
            break;
        }
        case 3:
        {
            Form1->ball->Picture->LoadFromFile(ballOrangePicture);
            break;
        }
        case 4:
        {
            Form1->ball->Picture->LoadFromFile(ballWhitePicture);
            break;
        }
        case 5:
        {
            Form1->ball->Picture->LoadFromFile(ballYellowPicture);
            break;
        }
    }
}

void TForm1::changePaddlesColors()
{
    switch(leftPaddleColorNumber)
    {
        case 0:
        {
            Form1->paddleLeft->Picture->LoadFromFile(paddleBluePicture);
            break;
        }
        case 1:
        {
            Form1->paddleLeft->Picture->LoadFromFile(paddleGrayPicture);
            break;
        }
        case 2:
        {
            Form1->paddleLeft->Picture->LoadFromFile(paddleLightGreenPicture);
            break;
        }
        case 3:
        {
            Form1->paddleLeft->Picture->LoadFromFile(paddleOrangePicture);
            break;
        }
        case 4:
        {
            Form1->paddleLeft->Picture->LoadFromFile(paddleWhitePicture);
            break;
        }
        case 5:
        {
            Form1->paddleLeft->Picture->LoadFromFile(paddleYellowPicture);
            break;
        }
    }

    switch(rightPaddleColorNumber)
    {
        case 0:
        {
            Form1->paddleRight->Picture->LoadFromFile(paddleBluePicture);
            break;
        }
        case 1:
        {
            Form1->paddleRight->Picture->LoadFromFile(paddleGrayPicture);
            break;
        }
        case 2:
        {
            Form1->paddleRight->Picture->LoadFromFile(paddleLightGreenPicture);
            break;
        }
        case 3:
        {
            Form1->paddleRight->Picture->LoadFromFile(paddleOrangePicture);
            break;
        }
        case 4:
        {
            Form1->paddleRight->Picture->LoadFromFile(paddleWhitePicture);
            break;
        }
        case 5:
        {
            Form1->paddleRight->Picture->LoadFromFile(paddleYellowPicture);
            break;
        }
    }
}

void TForm1::refreshCaptions()
{
    Form1->leftPlayerPointsLabel->Caption = IntToStr(leftPlayerPoints);
    Form1->rightPlayerPointsLabel->Caption = IntToStr(rightPlayerPoints);
    Form1->leftPlayerSetsLabel->Caption = IntToStr(leftPlayerWonSets);
    Form1->rightPlayerSetsLabel->Caption = IntToStr(rightPlayerWonSets);
    switch(setNumber)
    {
        case 1:
        {
            Form4->leftPlayerSet1PointsLabel->Caption = IntToStr(leftPlayerPoints);
            Form4->rightPlayerSet1PointsLabel->Caption = IntToStr(rightPlayerPoints);
            break;
        }
        case 2:
        {
            Form4->leftPlayerSet2PointsLabel->Caption = IntToStr(leftPlayerPoints);
            Form4->rightPlayerSet2PointsLabel->Caption = IntToStr(rightPlayerPoints);
            break;
        }
        case 3:
        {
            Form4->leftPlayerSet3PointsLabel->Caption = IntToStr(leftPlayerPoints);
            Form4->rightPlayerSet3PointsLabel->Caption = IntToStr(rightPlayerPoints);
            break;
        }
    }
}

void TForm1::addPoint(char toWhom)
{
    if (toWhom == 'L')
    {
        leftPlayerPoints++;
    }
    else if (toWhom == 'R')
    {
        rightPlayerPoints++;
    }
    refreshCaptions();
}

void TForm1::pause()
{
    stopGame();
    Form1->pauseLabel->Visible = true;
}

void TForm1::resume()
{
    Form1->pauseLabel->Visible = false;
    startGame();
}

void TForm1::ready()
{
    stopGame();
    Form1->Label1->Visible = true;
    Application->ProcessMessages(); Sleep(1200);
    Form1->Label1->Visible = false;
    startGame();
}

void TForm1::addSet(char toWhom)
{
    pause();
    if (toWhom == 'L')
    {
        leftPlayerWonSets++;
    }
    else if (toWhom == 'R')
    {
        rightPlayerWonSets++;
    }
    refreshCaptions();
    if ((leftPlayerWonSets >= 2) || (rightPlayerWonSets >= 2)) winDialog();
    else Form4->ShowModal();
    setNumber++;
}

void TForm1::resetPoints()
{
    leftPlayerPoints = 0;
    rightPlayerPoints = 0;
    refreshCaptions();
}

void TForm1::resetSets()

{
    leftPlayerWonSets = 0;
    rightPlayerWonSets = 0;
    refreshCaptions();
}

void TForm1::showSettingsMenu()
{
    Form1->greetingsLabel1->Visible = true;
    Form1->greetingsLabel2->Visible = true;
    Form1->menuBackgroud->Visible = true;
    Form1->Label3->Visible = true;
    Form1->Label4->Visible = true;
    Form1->leftPaddleColorGroupBox->Visible = true;
    Form1->rightPaddleColorGroupBox->Visible = true;
    Form1->startButton->Visible = true;
    Form1->resetButton->Visible = true;
    Form1->Panel1->Visible = true;
}

void TForm1::hideSettingsMenu()
{
    Form1->greetingsLabel1->Visible = false;
    Form1->greetingsLabel2->Visible = false;
    Form1->menuBackgroud->Visible = false;
    Form1->Label3->Visible = false;
    Form1->Label4->Visible = false;
    Form1->leftPaddleColorGroupBox->Visible = false;
    Form1->rightPaddleColorGroupBox->Visible = false;
    Form1->startButton->Visible = false;
    Form1->resetButton->Visible = false;
    Form1->Panel1->Visible = false;
}

void TForm1::playAgain()
{
    resetPositions();
    resetPoints();
    resetSets();
    refreshCaptions();
    randomize();
    changeBallColor();
    stopGame();
    showSettingsMenu();

    Form4->Height = 280;
    Form4->restartButton->Caption = "Restart";
    Form4->nextButton->Caption = "Next Set";
    Form4->restartButton->Top = Form4->Height - Form4->restartButton->Height - 50;
    Form4->nextButton->Top = Form4->Height - Form4->nextButton->Height - 50;

    Form1->pauseLabel->Visible = false;
    Form4->Label1->Visible = false;
    Form4->Label2->Visible = false;
    Form4->Label3->Visible = false;
    Form4->Label4->Visible = false;
}

void TForm1::winDialog()
{
    Form4->Height = 460;
    Form4->restartButton->Caption = "Play again!";
    Form4->nextButton->Caption = "Another time :)";
    Form4->restartButton->Top = Form4->Height - Form4->restartButton->Height - 50;
    Form4->nextButton->Top = Form4->Height - Form4->nextButton->Height - 50;

    if (leftPlayerWonSets > rightPlayerWonSets) Form4->Label2->Caption = "Player Left";
    else Form4->Label2->Caption = "Player Right";

    Form4->Label1->Visible = true;
    Form4->Label2->Visible = true;
    Form4->Label3->Visible = true;
    Form4->Label4->Visible = true;

    Form4->ShowModal();
}

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ballTimerTimer(TObject *Sender)
{

    ball->Left += moveBallHorizontal;
    ball->Top += moveBallVertical;

    int helpingParameter = 10;

    // bounce from left
    //if (ball->Left - helpingParameter <= background->Left) moveBallHorizontal = -moveBallHorizontal;

    // bounce from right
    //if (ball->Left + ball->Width + helpingParameter >= background->Width) moveBallHorizontal = -moveBallHorizontal;

    // bounce from top
    if (ball->Top - helpingParameter <= background->Top)
    {
        moveBallVertical = -moveBallVertical;
        playBallBounceSound();
        changeBallColor();
    }
    // bounce from bottom
    if (ball->Top + ball->Height + helpingParameter >= background->Height)
    {
        moveBallVertical = -moveBallVertical;
        playBallBounceSound();
        changeBallColor();
    }

    // pass by right paddle
    if (ball->Left >= paddleRight->Left + paddleRight->Width+15)
    {
        if (ballColorNumber == rightPaddleColorNumber)
        {
            addPoint('R');
            changeBallColor();
            if (rightPlayerPoints < 10) nextRound('R');
        }
        else
        {
            addPoint('L');
            changeBallColor();
            if (leftPlayerPoints < 10) nextRound('L');
        }
    }
    // pass by left paddle
    if (ball->Left <= paddleLeft->Left - 15)
    {
        if (ballColorNumber == leftPaddleColorNumber)
        {
            addPoint('L');
            changeBallColor();
            if (leftPlayerPoints < 10) nextRound('L');
        }
        else
        {
            addPoint('R');
            changeBallColor();
            if (rightPlayerPoints < 10) nextRound('R');
        }
    }
    //bounce from right paddle
    else if (ball->Top > paddleRight->Top - ball->Height + 10 && ball->Top < paddleRight->Top + paddleRight->Height - 10 && ball->Left + ball->Width > paddleRight->Left)
    {
        playBallBounceSound();
        if (moveBallHorizontal > 0)
        {
            moveBallHorizontal = -moveBallHorizontal;
            if (ballColorNumber == rightPaddleColorNumber)
            {
                addPoint('L');
                if (leftPlayerPoints < 10) nextRound('L');
            }
            changeBallColor();
        }
    }
    //bounce from left paddle
    else if (ball->Top > paddleLeft->Top - ball->Height + 10 && ball->Top < paddleLeft->Top + paddleLeft->Height - 10 && ball->Left < paddleLeft->Left + paddleLeft->Width)
    {
        playBallBounceSound();
        if (moveBallHorizontal < 0)
        {
            moveBallHorizontal = -moveBallHorizontal;
            if (ballColorNumber == leftPaddleColorNumber)
            {
                addPoint('R');
                if (rightPlayerPoints < 10) nextRound('R');
            }
            changeBallColor();
        }
    }

    if (leftPlayerPoints >= 10)
    {
        addSet('L');
        resetPoints();
        nextRound('L');
    }
    else if(rightPlayerPoints >= 10)
    {
        addSet('R');
        resetPoints();
        nextRound('L');
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::paddleLeftTimerMoveUpTimer(TObject *Sender)
{
    if (paddleLeft->Top > 10) paddleLeft->Top -= 10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::paddleLeftTimerMoveDownTimer(TObject *Sender)
{
    if (paddleLeft->Top + paddleLeft->Height < background->Height - 10) paddleLeft->Top += 10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::paddleRightTimerMoveUpTimer(TObject *Sender)
{
    if (paddleRight->Top > 10) paddleRight->Top -= 10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::paddleRightTimerMoveDownTimer(TObject *Sender)
{
    if (paddleRight->Top + paddleRight->Height < background->Height - 10) paddleRight->Top += 10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if (Key == 0x57) paddleLeftTimerMoveUp->Enabled = true; // W key
    if (Key == 0x53) paddleLeftTimerMoveDown->Enabled = true; // S key
    if (Key == VK_UP) paddleRightTimerMoveUp->Enabled = true;
    if (Key == VK_DOWN) paddleRightTimerMoveDown->Enabled = true;
    if (Key == VK_RETURN)
    {
        resume();
        ready();
    }
    if (Key == 0x50)
    {
        pause();
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if (Key == 0x57) paddleLeftTimerMoveUp->Enabled = false;
    if (Key == 0x53) paddleLeftTimerMoveDown->Enabled = false;
    if (Key == VK_UP) paddleRightTimerMoveUp->Enabled = false;
    if (Key == VK_DOWN) paddleRightTimerMoveDown->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
    resetPositions();
    randomize();
    changeBallColor();
    stopGame();
    showSettingsMenu();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::leftBlueClick(TObject *Sender)
{
    leftPaddleColorNumber = 0;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::leftGrayClick(TObject *Sender)
{
    leftPaddleColorNumber = 1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::leftLightGreenClick(TObject *Sender)
{
    leftPaddleColorNumber = 2;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::leftOrangeClick(TObject *Sender)
{
    leftPaddleColorNumber = 3;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::leftWhiteClick(TObject *Sender)
{
    leftPaddleColorNumber = 4;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::leftYellowClick(TObject *Sender)
{
    leftPaddleColorNumber = 5;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::rightBlueClick(TObject *Sender)
{
    rightPaddleColorNumber = 0;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::rightGrayClick(TObject *Sender)
{
    rightPaddleColorNumber = 1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::rightLightGreenClick(TObject *Sender)
{
    rightPaddleColorNumber = 2;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::rightOrangeClick(TObject *Sender)
{
    rightPaddleColorNumber = 3;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::rightWhiteClick(TObject *Sender)
{
    rightPaddleColorNumber = 4;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::rightYellowClick(TObject *Sender)
{
    rightPaddleColorNumber = 5;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::startButtonClick(TObject *Sender)
{
    changePaddlesColors();
    hideSettingsMenu();
    resume();
    ready();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Settings1Click(TObject *Sender)
{
    pause();
    showSettingsMenu();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Exit1Click(TObject *Sender)
{
    Application->Terminate();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Rules1Click(TObject *Sender)
{
    pause();
    Form2->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Aboutapp2Click(TObject *Sender)
{
    pause();
    Form3->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::resetButtonClick(TObject *Sender)
{
    playAgain();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormResize(TObject *Sender)
{
    resetPositions();
}
//---------------------------------------------------------------------------

