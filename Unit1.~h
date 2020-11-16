//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TShape *background;
    TImage *paddleLeft;
    TImage *paddleRight;
    TImage *ball;
    TTimer *ballTimer;
    TTimer *paddleLeftTimerMoveUp;
    TTimer *paddleLeftTimerMoveDown;
    TTimer *paddleRightTimerMoveDown;
    TTimer *paddleRightTimerMoveUp;
    TLabel *Label1;
    TLabel *Points;
    TLabel *leftPlayerPointsLabel;
    TLabel *rightPlayerPointsLabel;
    TShape *menuBackgroud;
    TMainMenu *MainMenu1;
    TMenuItem *Fi1;
    TMenuItem *Settings1;
    TMenuItem *Exit1;
    TMenuItem *Aboutapp1;
    TMenuItem *Rules1;
    TMenuItem *Aboutapp2;
    TLabel *setsLabel;
    TLabel *rightPlayerSetsLabel;
    TLabel *leftPlayerSetsLabel;
    TLabel *pauseLabel;
    TPanel *Panel1;
    TLabel *greetingsLabel1;
    TLabel *greetingsLabel2;
    TLabel *Label3;
    TLabel *Label4;
    TGroupBox *leftPaddleColorGroupBox;
    TRadioButton *leftBlue;
    TRadioButton *leftGray;
    TRadioButton *leftLightGreen;
    TRadioButton *leftOrange;
    TRadioButton *leftWhite;
    TRadioButton *leftYellow;
    TGroupBox *rightPaddleColorGroupBox;
    TRadioButton *rightBlue;
    TRadioButton *rightGray;
    TRadioButton *rightLightGreen;
    TRadioButton *rightOrange;
    TRadioButton *rightWhite;
    TRadioButton *rightYellow;
    TButton *startButton;
    TButton *resetButton;
    void __fastcall ballTimerTimer(TObject *Sender);
    void __fastcall paddleLeftTimerMoveUpTimer(TObject *Sender);
    void __fastcall paddleLeftTimerMoveDownTimer(TObject *Sender);
    void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall paddleRightTimerMoveDownTimer(TObject *Sender);
    void __fastcall paddleRightTimerMoveUpTimer(TObject *Sender);
    void __fastcall FormCreate(TObject *Sender);

    void __fastcall leftBlueClick(TObject *Sender);
    void __fastcall leftGrayClick(TObject *Sender);
    void __fastcall leftLightGreenClick(TObject *Sender);
    void __fastcall leftOrangeClick(TObject *Sender);
    void __fastcall leftWhiteClick(TObject *Sender);
    void __fastcall leftYellowClick(TObject *Sender);

    void __fastcall rightBlueClick(TObject *Sender);
    void __fastcall rightGrayClick(TObject *Sender);
    void __fastcall rightLightGreenClick(TObject *Sender);
    void __fastcall rightOrangeClick(TObject *Sender);
    void __fastcall rightWhiteClick(TObject *Sender);
    void __fastcall rightYellowClick(TObject *Sender);

    void __fastcall startButtonClick(TObject *Sender);
    void __fastcall Settings1Click(TObject *Sender);
    void __fastcall Exit1Click(TObject *Sender);
    void __fastcall Rules1Click(TObject *Sender);
    void __fastcall Aboutapp2Click(TObject *Sender);
    void __fastcall resetButtonClick(TObject *Sender);
    void __fastcall FormResize(TObject *Sender);
private:	// User declarations
    void resetPositions();
    void stopGame();
    void startGame();
    void nextRound(char whoWon);
    void playBallBounceSound();
    void changeBallColor();
    void changePaddlesColors();
    void refreshCaptions();
    void addPoint(char toWhom);
    void pause();
    void resume();
    void ready();
    void addSet(char toWhom);
    void resetPoints();
    void resetSets();
    void showSettingsMenu();
    void hideSettingsMenu();
    void winDialog();

public:		// User declarations
    __fastcall TForm1(TComponent* Owner);
    void playAgain();
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
