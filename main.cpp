#include <Novice.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>

const char kWindowTitle[] = "LC1C_26_マルヤマユウキ_天まで届け_ネジ巻きロケット";

struct Vector2 {
	float x;
	float y;
};
struct Icon {
	Vector2 pos;
	float w;
	float h;
	int Hit;
	int keyON;
};
struct HitBox {
	float left;
	float right;
	float top;
	float bottom;
};

enum Game {
	tittle,
	Screw,
	flying,
};

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	int mouseX = 0;
	int mouseY = 0;


	Vector2 TittleBG = { 0,0 }; ///1440
	Icon Tittle{ {640,200},500,250 };
	Icon start = { {640,400,},300,100,false,false };
	Icon quit = { {640,550,},300, 100,false,false };
	Vector2 scale = { 6.0f,2.0f };
	Icon conHelp = { {850,500},200,100,false,false };

	Icon rocket = { {640,1800},200,400,false,false };
	Icon screw = { {735,1770},100,100 };
	Icon help = { {1920,360},450,500 };
	Icon OKButton = { {1920,550},200,100,false,false };
	Icon startSign = { {640,360},0,0,false,false };
	int startIconON = false;
	Icon stopSign = { {640,360},0,0,false };
	int stopIconON = false;
	int moveCountDown[2] = { 120,60 };
	int startCountDown[2] = { 120,60 };
	int finishCountDown = 60;
	int screwTime = 600;
	int screwStart = false;
	int count = 0;
	int screwNO = 0;
	int switchGB = false;
	int switchTime = 240;

	Icon FRocket = { {640,360},200,400,false,false };
	Icon FScrew = { {735,330},100,100 };
	Icon scoreB = { {640,360},384,224,false,false };
	Icon Next = { {736,480},88,72,false,false };
	Icon Yes = { {440,400},128,64,false,false };
	Icon No = { {840,400},192,64,false,false };
	Vector2 FBackGround = { 0,-10080 };
	Vector2 WO = { 0,-10080 };
	int flyCountON = false;
	int flyCountDown = 240;
	float theta = 0.0f;
	float amplitude = 2.0f;
	int waveON = false;
	int ignition = false;
	int rocketStop = false;
	int flyScore = 0;
	int highScore = 0;
	int flyingHeight = 0;
	int FLY = 0;
	int FLY3 = 0;
	int FLY2 = 0;
	int FLY1 = 0;
	int FlyH = 0;
	int FlyH3 = 0;
	int FlyH2 = 0;
	int FlyH1 = 0;
	int ResultON = false;
	int RCount = 180;
	int FullScore = false;
	int BonusON = false;
	int BonusTime = 60;

	int Reset = false;

	Game game = tittle;

	int Cursor = Novice::LoadTexture("./NoviceResources/images/cursor.png");

	int ConHelp = Novice::LoadTexture("./NoviceResources/images/ConHelp.png");
	int tittleBG = Novice::LoadTexture("./NoviceResources/images/TittleBackGround.png");
	int TITTLE = Novice::LoadTexture("./NoviceResources/images/tittle.png");
	int START = Novice::LoadTexture("./NoviceResources/images/start.png");
	int StartHit = Novice::LoadTexture("./NoviceResources/images/startHit.png");
	int Quit = Novice::LoadTexture("./NoviceResources/images/quit.png");
	int QuitHit = Novice::LoadTexture("./NoviceResources/images/quitHit.png");

	int screwBG = Novice::LoadTexture("./NoviceResources/images/ScrewBackGround.png");
	int SwitchBG = Novice::LoadTexture("./NoviceResources/images/SwitchBackGround.png");
	int StartSign = Novice::LoadTexture("./NoviceResources/images/startSign.png");
	int FinishSign = Novice::LoadTexture("./NoviceResources/images/finish.png");
	int Rocket = Novice::LoadTexture("./NoviceResources/images/rocket.png");
	int Spring[4];
	Spring[0] = Novice::LoadTexture("./NoviceResources/images/spring1.png");
	Spring[1] = Novice::LoadTexture("./NoviceResources/images/spring2.png");
	Spring[2] = Novice::LoadTexture("./NoviceResources/images/spring3.png");
	Spring[3] = Novice::LoadTexture("./NoviceResources/images/spring4.png");
	int HelpWindow = Novice::LoadTexture("./NoviceResources/images/helpWindow.png");
	int OK = Novice::LoadTexture("./NoviceResources/images/OK.png");
	int OKHIT = Novice::LoadTexture("./NoviceResources/images/OK-Hit.png");
	int CountTime[11];
	CountTime[0] = Novice::LoadTexture("./NoviceResources/images/screwsTime0.png");
	CountTime[1] = Novice::LoadTexture("./NoviceResources/images/screwsTime1.png");
	CountTime[2] = Novice::LoadTexture("./NoviceResources/images/screwsTime2.png");
	CountTime[3] = Novice::LoadTexture("./NoviceResources/images/screwsTime3.png");
	CountTime[4] = Novice::LoadTexture("./NoviceResources/images/screwsTime4.png");
	CountTime[5] = Novice::LoadTexture("./NoviceResources/images/screwsTime5.png");
	CountTime[6] = Novice::LoadTexture("./NoviceResources/images/screwsTime6.png");
	CountTime[7] = Novice::LoadTexture("./NoviceResources/images/screwsTime7.png");
	CountTime[8] = Novice::LoadTexture("./NoviceResources/images/screwsTime8.png");
	CountTime[9] = Novice::LoadTexture("./NoviceResources/images/screwsTime9.png");
	CountTime[10] = Novice::LoadTexture("./NoviceResources/images/screwsTime10.png");

	int FlyBG = Novice::LoadTexture("./NoviceResources/images/FlyBackGround.png");
	int IgnitionR = Novice::LoadTexture("./NoviceResources/images/RocketIgnition.png");
	int Score = Novice::LoadTexture("./NoviceResources/images/Score.png");
	int HighScore = Novice::LoadTexture("./NoviceResources/images/highScore.png");
	int ScoreON[10];
	ScoreON[0] = Novice::LoadTexture("./NoviceResources/images/0.png");
	ScoreON[1] = Novice::LoadTexture("./NoviceResources/images/1.png");
	ScoreON[2] = Novice::LoadTexture("./NoviceResources/images/2.png");
	ScoreON[3] = Novice::LoadTexture("./NoviceResources/images/3.png");
	ScoreON[4] = Novice::LoadTexture("./NoviceResources/images/4.png");
	ScoreON[5] = Novice::LoadTexture("./NoviceResources/images/5.png");
	ScoreON[6] = Novice::LoadTexture("./NoviceResources/images/6.png");
	ScoreON[7] = Novice::LoadTexture("./NoviceResources/images/7.png");
	ScoreON[8] = Novice::LoadTexture("./NoviceResources/images/8.png");
	ScoreON[9] = Novice::LoadTexture("./NoviceResources/images/9.png");
	int ScoreB = Novice::LoadTexture("./NoviceResources/images/ScoreBoard.png");
	int HScoreB = Novice::LoadTexture("./NoviceResources/images/HighScoreBoard.png");
	int NextB = Novice::LoadTexture("./NoviceResources/images/NextButton.png");
	int NextHit = Novice::LoadTexture("./NoviceResources/images/NextButtonON.png");
	int WhiteOut = Novice::LoadTexture("./NoviceResources/images/WhiteOut.png");
	int BonusBG = Novice::LoadTexture("./NoviceResources/images/BonusImage.png");

	int Shadow = Novice::LoadTexture("./NoviceResources/images/Shadow.png");
	int YES = Novice::LoadTexture("./NoviceResources/images/Yes.png");
	int YESHit = Novice::LoadTexture("./NoviceResources/images/YesON.png");
	int NO = Novice::LoadTexture("./NoviceResources/images/NO.png");
	int NOHit = Novice::LoadTexture("./NoviceResources/images/NoON.png");

	int TittleBGM = Novice::LoadAudio("./NoviceResources/sounds/tittle.wav");
	int TittleVoice = -1;

	int ScrewBGM1 = Novice::LoadAudio("./NoviceResources/sounds/ScrewBGM1.wav");
	int ScrewVoice1 = -1;
	int ScrewBGM2 = Novice::LoadAudio("./NoviceResources/sounds/ScrewBGM2.wav");
	int ScrewVoice2 = -1;
	int ScrewSE = Novice::LoadAudio("./NoviceResources/sounds/ScrewSE.wav");
	int ScrewSEVoice = -1;
	int StartSE = Novice::LoadAudio("./NoviceResources/sounds/startSE.wav");
	int StartVoice = -1;
	int StopSE = Novice::LoadAudio("./NoviceResources/sounds/stopSE.wav");
	int StopVoice = -1;

	int FlyCountBGM = Novice::LoadAudio("./NoviceResources/sounds/FlyCount.wav");
	int FlyCountVoice = -1;
	int FlyBGM = Novice::LoadAudio("./NoviceResources/sounds/FlyBGM.wav");
	int FlyVoice = -1;

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		HitBox conHHit = { conHelp.pos.x - (conHelp.w / 2),conHelp.pos.x + (conHelp.w / 2),conHelp.pos.y - (conHelp.h / 2),conHelp.pos.y + (conHelp.h / 2) };
		HitBox startHit = { start.pos.x - (start.w / 2),start.pos.x + (start.w / 2),start.pos.y - (start.h / 2),start.pos.y + (start.h / 2) };
		HitBox quitHit = { quit.pos.x - (quit.w / 2),quit.pos.x + (quit.w / 2),quit.pos.y - (quit.h / 2),quit.pos.y + (quit.h / 2) };
		HitBox OKHit = { OKButton.pos.x - (OKButton.w / 2),OKButton.pos.x + (OKButton.w / 2),OKButton.pos.y - (OKButton.h / 2),OKButton.pos.y + (OKButton.h / 2) };
		HitBox Start = { startSign.pos.x - (startSign.w / 2),startSign.pos.x + (startSign.w / 2),startSign.pos.y - (startSign.h / 2),startSign.pos.y + (startSign.h / 2) };
		HitBox Stop = { stopSign.pos.x - (stopSign.w / 2),stopSign.pos.x + (stopSign.w / 2),stopSign.pos.y - (stopSign.h / 2),stopSign.pos.y + (stopSign.h / 2) };
		HitBox nextHit = { Next.pos.x - (Next.w / 2),Next.pos.x + (Next.w / 2),Next.pos.y - (Next.h / 2),Next.pos.y + (Next.h / 2) };
		HitBox yesHit = { Yes.pos.x - (Yes.w / 2),Yes.pos.x + (Yes.w / 2),Yes.pos.y - (Yes.h / 2),Yes.pos.y + (Yes.h / 2) };
		HitBox noHit = { No.pos.x - (No.w / 2),No.pos.x + (No.w / 2),No.pos.y - (No.h / 2),No.pos.y + (No.h / 2) };

		///
		/// ↓更新処理ここから
		///
		Novice::GetMousePosition(&mouseX, &mouseY);
		Novice::SetMouseCursorVisibility(0);
		switch (game) {
		case tittle:
			start.Hit = false;
			quit.Hit = false;
			conHelp.Hit = false;
			if (conHelp.keyON == 0) {
				if (conHHit.left <= mouseX &&
					mouseX <= conHHit.right &&
					conHHit.top <= mouseY &&
					mouseY <= conHHit.bottom) {
					conHelp.Hit = true;
				}
				if (conHelp.Hit == 1 && Novice::IsTriggerMouse(0)) {
					conHelp.keyON = true;
				}
			}


			//------スタートボタン------//
			if (conHelp.keyON == 1) {
				if (startHit.left <= mouseX &&
					mouseX <= startHit.right &&
					startHit.top <= mouseY &&
					mouseY <= startHit.bottom) {
					start.Hit = true;
				}
			}

			if (start.Hit == 1 && Novice::IsTriggerMouse(0)) {
				start.keyON = true;
			}
			if (start.keyON == 1) {
				start.Hit = true;
				if (start.w > 0 && quit.w > 0) {
					start.w -= scale.x;
					quit.w -= scale.x;
				}
				else if (start.w < 0 && quit.w < 0) {
					start.w = 0.0f;
					quit.w = 0.0f;
				}
				if (start.h > 0 && quit.h > 0) {
					start.h -= scale.y;
					quit.h -= scale.y; 
				}
				else if (start.h < 0 && quit.h < 0) {
					start.h = 0.0f;
					quit.h = 0.0f;
				}
			}
			//------------------//

			//------シーン切り替え------//
			if (start.w == 0 && start.h == 0) {
				if (moveCountDown[0] > 0) {
					moveCountDown[0] -= 1;
				}
				if (moveCountDown[0] == 0) {
					if (TittleBG.y > -1440) {
						Tittle.pos.y -= 5;
						TittleBG.y -= 5;
					}
				}
			}
			if (TittleBG.y == -1440) {
				game = Screw;
			}
			//------------------//

			//------ゲーム終了------//
			if (conHelp.keyON == 1) {
				if (quitHit.left <= mouseX &&
					mouseX <= quitHit.right &&
					quitHit.top <= mouseY &&
					mouseY <= quitHit.bottom) {
					quit.Hit = true;
				}
			}

			if (quit.Hit == 1 && Novice::IsTriggerMouse(0)) {
				quit.keyON = true;
			}
			//------------------//
			break;
		case Screw:
			//------説明ウィンドウ------//
			if (moveCountDown[1] > 0) {
				moveCountDown[1] -= 1;
			}
			if (moveCountDown[1] == 0) {
				if (help.pos.x > 640) {
					help.pos.x -= 100;
					OKButton.pos.x -= 100;
				}
				if (help.pos.x <= 640) {
					help.pos.x = 640;
					OKButton.pos.x = 640;
				}
			}
			OKButton.Hit = false;
			if (OKHit.left <= mouseX &&
				mouseX <= OKHit.right &&
				OKHit.top <= mouseY &&
				mouseY <= OKHit.bottom) {
				OKButton.Hit = true;
			}
			if (OKButton.Hit == 1 && Novice::IsTriggerMouse(0)) {
				OKButton.keyON = true;
			}
			if (OKButton.keyON == 1) {
				OKButton.Hit = true;
				if (help.pos.x < 1640) {
					help.pos.x += 200;
					OKButton.pos.x += 200;
				}
			}
			//------------------//

			//------ネジ巻きスタート------//
			if (OKButton.keyON == 1 && help.pos.x >= 1640) {
				if (startCountDown[0] > 0) {
					startCountDown[0] -= 1;
				}
			}
			if (startCountDown[0] == 0) {
				startIconON = true;
				startSign.Hit = true;
			}
			if (startSign.Hit == 1) {
				if (startSign.w < 400 && startSign.h < 200) {
					startSign.w += 20;
					startSign.h += 10;
				}
				if (startSign.w >= 400) {
					startCountDown[1] -= 1;
				}
				if (startCountDown[1] == 0) {
					if (startSign.w > 0 && startSign.h > 0) {
						startSign.w -= 80;
						startSign.h -= 40;
					}
					if (startSign.w <= 0) {
						startSign.w = 0;
						startSign.h = 0;
						startIconON = false;
						screwStart = true;
					}
				}
			}
			//------------------//

			//------ネジ巻き------//
			else if (screwTime == 0) {
				screwStart = false;
			}
			if (screwStart == 1) {
				if (screwTime > 0) {
					screwTime--;
				}
			}
			if (screwStart == 1 && Novice::IsTriggerMouse(0)) {
				if (screwTime > 0) {
					if (count <= 100) {
						count++;
					}
					screwNO++;
				}
			}
			if (screwNO > 3) {
				screwNO = 0;
			}
			//------------------//

			//------ネジ巻き終了------//
			if (screwTime == 0) {
				stopIconON = true;

			}
			if (stopIconON == 1) {
				if (stopSign.w < 400 && stopSign.h < 80) {
					stopSign.w += 20;
					stopSign.h += 5;
				}
				if (stopSign.h >= 80) {
					if (finishCountDown > 0) {
						finishCountDown -= 1;
					}
				}
				if (finishCountDown == 0) {
					if (stopSign.w > 0 && stopSign.h > 0) {
						stopSign.w -= 40;
						stopSign.h -= 10;
					}
					if (stopSign.w <= 0) {
						stopSign.w = 0;
						stopSign.h = 0;
						stopIconON = false;
					}
				}
			}
			if (finishCountDown == 0 && stopSign.w == 0) {
				if (switchTime > 0) {
					switchTime--;
				}
			}
			if (switchTime <= 180) {
				switchGB = true;
			}
			if (switchTime <= 150) {
				switchGB = false;
			}
			if (switchTime <= 90) {
				switchGB = true;
			}
			if (switchTime <= 45) {
				switchGB = false;
			}
			if (switchTime == 0) {
				game = flying;
			}

			break;
		case flying:
			FRocket.pos.x = sinf(theta) * amplitude + 640;
			if (FScrew.pos.x < 2000) {
				FScrew.pos.x += 5;
			}
			if (FScrew.pos.x >= 2000) {
				flyCountON = true;
			}
			if (flyCountON == 1) {
				if (flyCountDown > 0) {
					flyCountDown--;
				}
			}
			if (flyCountDown <= 180) {
				waveON = true;
			}
			if (flyCountDown <= 120) {
				ignition = true;
			}
			if (flyCountDown == 0) {
				FRocket.keyON = true;
			}
			if (waveON == 1) {
				theta += float(M_PI) / 5.0f;
			}
			//flyingHeight = 990;
			if (count >= 99) {
				flyingHeight = 999;
			}
			else if (count < 99) {
				flyingHeight = (count * 10) + (count / 2);
			}
			if (flyingHeight == 999) {
				FullScore = true;
			}
			if (FRocket.keyON == 1) {
				if (flyScore < flyingHeight) {
					flyScore++;
					if (FullScore == 1) {
						if (FBackGround.y < 0) {
							FBackGround.y += 10;
							WO.y += 10;
						}
					}
					else {
						FBackGround.y += 10;
					}

				}
				if (FRocket.pos.y > 300) {
					if (flyingHeight > 0) {
						FRocket.pos.y -= 10;
						FScrew.pos.y -= 10;
					}
				}
				FLY = flyScore;
				FLY3 = FLY / 100;
				FLY = FLY % 100;
				FLY2 = FLY / 10;
				FLY = FLY % 10;
				FLY1 = FLY / 1;
				FLY = FLY % 1;
			}
			if (WO.y >= -90) {
				if (BonusTime > 0) {
					BonusTime--;
				}
			}

			if (BonusTime == 0) {
				BonusON = true;
			}
			if (flyCountDown == 0 && flyScore == flyingHeight) {
				rocketStop = true;
			}
			if (rocketStop == 1) {
				theta = 0.0f;
				ignition = false;
				if (FullScore == 1) {
					if (BonusON == 1) {
						if (RCount > 0) {
							RCount--;
						}
					}
				}
				else {
					if (RCount > 0) {
						RCount--;
					}
				}
			}

			Next.Hit = false;
			if (RCount == 0) {
				if (Next.keyON == 0) {
					ResultON = true;
					if (nextHit.left <= mouseX &&
						mouseX <= nextHit.right &&
						nextHit.top <= mouseY &&
						mouseY <= nextHit.bottom) {
						Next.Hit = true;
					}
				}

			}
			if (Next.Hit == 1 && Novice::IsTriggerMouse(0)) {
				Next.keyON = true;
				ResultON = false;
			}
			Yes.Hit = false;
			No.Hit = false;
			if (Next.keyON == 1) {
				if (flyScore > highScore) {
					highScore = flyScore;

				}
				if (yesHit.left <= mouseX &&
					mouseX <= yesHit.right &&
					yesHit.top <= mouseY &&
					mouseY <= yesHit.bottom) {
					Yes.Hit = true;
				}
				if (noHit.left <= mouseX &&
					mouseX <= noHit.right &&
					noHit.top <= mouseY &&
					mouseY <= noHit.bottom) {
					No.Hit = true;
				}
			}
			FlyH = highScore;
			FlyH3 = FlyH / 100;
			FlyH = FlyH % 100;
			FlyH2 = FlyH / 10;
			FlyH = FlyH % 10;
			FlyH1 = FlyH / 1;
			FlyH = FlyH % 1;

			if (Yes.Hit == 1 && Novice::IsTriggerMouse(0)) {
				Yes.keyON = true;
			}
			if (No.Hit == 1 && Novice::IsTriggerMouse(0)) {
				No.keyON = true;
			}
			if (Yes.keyON == 1 || No.keyON == 1) {
				Reset = true;
			}
			if (Yes.keyON == 1) {
				game = Screw;
			}
			if (No.keyON == 1) {
				game = tittle;
			}

			break;
		}
		if (Reset == 1) {
			//TITTLE//
			conHelp.keyON = false;
			TittleBG.y = 0;
			start.Hit = false;
			quit.Hit = false;
			moveCountDown[0] = 120;
			Tittle.pos.y = 200;
			start.pos.y = 400;
			start.w = 300;
			start.h = 100;
			start.keyON = false;
			quit.pos.y = 550;
			quit.w = 300;
			quit.h = 100;
			start.keyON = false;
			//----//

			//SCREW//
			moveCountDown[1] = 60;
			help.pos.x = 1920;
			OKButton.pos.x = 1920;
			startCountDown[0] = 120;
			startCountDown[1] = 60;
			finishCountDown = 60;
			screwTime = 600;
			count = 0;
			screwNO = 0;
			switchTime = 240;
			OKButton.keyON = false;
			startSign.Hit = false;
			screwStart = false;
			stopIconON = false;
			//----//

			//FYLING//
			FRocket.pos.y = 360;
			FScrew.pos.x = 735;
			FScrew.pos.y = 330;
			FBackGround.y = -10080;
			flyCountDown = 240;
			RCount = 120;
			flyingHeight = 0;
			flyCountON = false;
			FRocket.keyON = false;
			rocketStop = false;
			flyScore = 0;
			FLY = 0;
			FLY3 = FLY / 100;
			FLY = FLY % 100;
			FLY2 = FLY / 10;
			FLY = FLY % 10;
			FLY1 = FLY / 1;
			FLY = FLY % 1;
			ResultON = false;
			Next.keyON = false;
			Yes.keyON = false;
			No.keyON = false;
			FullScore = false;
			BonusON = false;
			BonusTime = 60;
			//----//
			Reset = false;

		}






		//波が上に行き下に行き360度言ったらフラグをFalseに

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		switch (game) {
		case tittle:
			Novice::DrawSprite(int(TittleBG.x), int(TittleBG.y), tittleBG, 1, 1, 0.0f, WHITE);
			Novice::DrawSprite(int(Tittle.pos.x - (Tittle.w / 2)), int(Tittle.pos.y - (Tittle.h / 2)), TITTLE, 1, 1, 0.0f, WHITE);

			if (start.Hit == 1) {
				Novice::DrawQuad(int(startHit.left), int(startHit.top), int(startHit.right), int(startHit.top), int(startHit.left), int(startHit.bottom), int(startHit.right), int(startHit.bottom), 0, 0, 300, 100, StartHit, WHITE);
			}
			else {
				Novice::DrawQuad(int(startHit.left), int(startHit.top), int(startHit.right), int(startHit.top), int(startHit.left), int(startHit.bottom), int(startHit.right), int(startHit.bottom), 0, 0, 300, 100, START, WHITE);
			}
			if (quit.Hit == 1) {
				Novice::DrawQuad(int(quitHit.left), int(quitHit.top), int(quitHit.right), int(quitHit.top), int(quitHit.left), int(quitHit.bottom), int(quitHit.right), int(quitHit.bottom), 0, 0, 300, 100, QuitHit, WHITE);
			}
			else {
				Novice::DrawQuad(int(quitHit.left), int(quitHit.top), int(quitHit.right), int(quitHit.top), int(quitHit.left), int(quitHit.bottom), int(quitHit.right), int(quitHit.bottom), 0, 0, 300, 100, Quit, WHITE);
			}
			if (conHelp.keyON == 0) {
				Novice::DrawSprite(0, 0, ConHelp, 1, 1, 0.0f, WHITE);
				if (conHelp.Hit == 1) {
					Novice::DrawQuad(int(conHHit.left), int(conHHit.top), int(conHHit.right), int(conHHit.top), int(conHHit.left), int(conHHit.bottom), int(conHHit.right), int(conHHit.bottom), 0, 0, 200, 100, OKHIT, WHITE);
				}
				else {
					Novice::DrawQuad(int(conHHit.left), int(conHHit.top), int(conHHit.right), int(conHHit.top), int(conHHit.left), int(conHHit.bottom), int(conHHit.right), int(conHHit.bottom), 0, 0, 200, 100, OK, WHITE);
				}
			}
			break;
		case Screw:
			if (switchGB == 0) {
				Novice::DrawSprite(0, 0, screwBG, 1, 1, 0.0f, WHITE);
			}
			if (switchGB == 1) {
				Novice::DrawSprite(0, 0, SwitchBG, 1, 1, 0.0f, WHITE);
			}

			if (switchTime == 240) {
				if (screwTime > 540) {
					Novice::DrawSprite(200, 100, CountTime[10], 1, 1, 0.0f, WHITE);
				}
				else if (screwTime > 480) {
					Novice::DrawSprite(200, 100, CountTime[9], 1, 1, 0.0f, WHITE);
				}
				else if (screwTime > 420) {
					Novice::DrawSprite(200, 100, CountTime[8], 1, 1, 0.0f, WHITE);
				}
				else if (screwTime > 360) {
					Novice::DrawSprite(200, 100, CountTime[7], 1, 1, 0.0f, WHITE);
				}
				else if (screwTime > 300) {
					Novice::DrawSprite(200, 100, CountTime[6], 1, 1, 0.0f, WHITE);
				}
				else if (screwTime > 240) {
					Novice::DrawSprite(200, 100, CountTime[5], 1, 1, 0.0f, WHITE);
				}
				else if (screwTime > 180) {
					Novice::DrawSprite(200, 100, CountTime[4], 1, 1, 0.0f, WHITE);
				}
				else if (screwTime > 120) {
					Novice::DrawSprite(200, 100, CountTime[3], 1, 1, 0.0f, WHITE);
				}
				else if (screwTime > 60) {
					Novice::DrawSprite(200, 100, CountTime[2], 1, 1, 0.0f, WHITE);
				}
				else if (screwTime > 0) {
					Novice::DrawSprite(200, 100, CountTime[1], 1, 1, 0.0f, WHITE);
				}
				else if (screwTime == 0) {
					Novice::DrawSprite(200, 100, CountTime[0], 1, 1, 0.0f, WHITE);
				}
			}

			if (screwNO == 0) {
				Novice::DrawSprite(int(screw.pos.x - (screw.w / 2)), int(330 - (screw.h / 2)), Spring[0], 1, 1, 0.0f, WHITE);
			}
			if (screwNO == 1) {
				Novice::DrawSprite(int(screw.pos.x - (screw.w / 2)), int(330 - (screw.h / 2)), Spring[1], 1, 1, 0.0f, WHITE);
			}
			if (screwNO == 2) {
				Novice::DrawSprite(int(screw.pos.x - (screw.w / 2)), int(330 - (screw.h / 2)), Spring[2], 1, 1, 0.0f, WHITE);
			}
			if (screwNO == 3) {
				Novice::DrawSprite(int(screw.pos.x - (screw.w / 2)), int(330 - (screw.h / 2)), Spring[3], 1, 1, 0.0f, WHITE);
			}
			Novice::DrawSprite(int(rocket.pos.x - (rocket.w / 2)), int(360 - (rocket.h / 2)), Rocket, 1, 1, 0.0f, WHITE);
			if (help.pos.x < 1640) {
				Novice::DrawSprite(int(help.pos.x - (help.w / 2)), int(help.pos.y - (help.h / 2)), HelpWindow, 1, 1, 0.0f, WHITE);
				if (OKButton.Hit == 1) {
					Novice::DrawBox(int(OKButton.pos.x - (OKButton.w / 2)), int(OKButton.pos.y - (OKButton.h / 2)), int(OKButton.w), int(OKButton.h), 0.0f, 0xc85554ff, kFillModeSolid);
					Novice::DrawSprite(int(OKButton.pos.x - (OKButton.w / 2)), int(OKButton.pos.y - (OKButton.h / 2)), OKHIT, 1, 1, 0.0f, WHITE);
				}
				else {
					Novice::DrawBox(int(OKButton.pos.x - (OKButton.w / 2)), int(OKButton.pos.y - (OKButton.h / 2)), int(OKButton.w), int(OKButton.h), 0.0f, 0x478384ff, kFillModeSolid);
					Novice::DrawSprite(int(OKButton.pos.x - (OKButton.w / 2)), int(OKButton.pos.y - (OKButton.h / 2)), OK, 1, 1, 0.0f, WHITE);
				}
			}
			if (startIconON == 1) {
				Novice::DrawQuad(int(Start.left), int(Start.top), int(Start.right), int(Start.top), int(Start.left), int(Start.bottom), int(Start.right), int(Start.bottom), 0, 0, 400, 200, StartSign, WHITE);
			}
			if (stopIconON == 1) {
				Novice::DrawQuad(int(Stop.left), int(Stop.top), int(Stop.right), int(Stop.top), int(Stop.left), int(Stop.bottom), int(Stop.right), int(Stop.bottom), 0, 0, 400, 80, FinishSign, WHITE);
			}
			break;
		case flying:
			Novice::DrawSprite(int(FBackGround.x), int(FBackGround.y), FlyBG, 1, 1, 0.0f, WHITE);
			if (screwNO == 0) {
				Novice::DrawSprite(int(FScrew.pos.x - (FScrew.w / 2)), int(FScrew.pos.y - (FScrew.h / 2)), Spring[0], 1, 1, 0.0f, WHITE);
			}
			if (screwNO == 1) {
				Novice::DrawSprite(int(FScrew.pos.x - (FScrew.w / 2)), int(FScrew.pos.y - (FScrew.h / 2)), Spring[1], 1, 1, 0.0f, WHITE);
			}
			if (screwNO == 2) {
				Novice::DrawSprite(int(FScrew.pos.x - (FScrew.w / 2)), int(FScrew.pos.y - (FScrew.h / 2)), Spring[2], 1, 1, 0.0f, WHITE);
			}
			if (screwNO == 3) {
				Novice::DrawSprite(int(FScrew.pos.x - (FScrew.w / 2)), int(FScrew.pos.y - (FScrew.h / 2)), Spring[3], 1, 1, 0.0f, WHITE);
			}

			if (ignition == 0) {
				Novice::DrawSprite(int(FRocket.pos.x - (FRocket.w / 2)), int(FRocket.pos.y - (FRocket.h / 2)), Rocket, 1, 1, 0.0f, WHITE);
			}
			if (ignition == 1) {
				Novice::DrawSprite(int(FRocket.pos.x - (FRocket.w / 2)), int(FRocket.pos.y - (FRocket.h / 2)), IgnitionR, 1, 1, 0.0f, WHITE);
			}

			if (flyCountON == 1) {
				if (flyCountDown > 180) {
					Novice::DrawSprite(550, 270, CountTime[3], 1, 1, 0.0f, WHITE);
				}
				else if (flyCountDown > 120) {
					Novice::DrawSprite(550, 270, CountTime[2], 1, 1, 0.0f, WHITE);
				}
				else if (flyCountDown > 06) {
					Novice::DrawSprite(550, 270, CountTime[1], 1, 1, 0.0f, WHITE);
				}
			}
			if (Next.keyON == 0) {
				Novice::DrawSprite(50, 109, Score, 1, 1, 0.0f, WHITE);
				Novice::DrawSprite(80, 93, ScoreON[FLY3], 1, 1, 0.0f, WHITE);
				Novice::DrawSprite(110, 93, ScoreON[FLY2], 1, 1, 0.0f, WHITE);
				Novice::DrawSprite(140, 93, ScoreON[FLY1], 1, 1, 0.0f, WHITE);

				Novice::DrawSprite(1010, 25, HighScore, 1, 1, 0.0f, WHITE);
				Novice::DrawSprite(1090, 93, ScoreON[FlyH3], 1, 1, 0.0f, WHITE);
				Novice::DrawSprite(1120, 93, ScoreON[FlyH2], 1, 1, 0.0f, WHITE);
				Novice::DrawSprite(1150, 93, ScoreON[FlyH1], 1, 1, 0.0f, WHITE);

			}
			if (FullScore == 1) {
				if (BonusON == 1) {
					Novice::DrawSprite(0, 0, BonusBG, 1, 1, 0.0f, WHITE);
				}
				if (BonusON == 0) {
					Novice::DrawSprite(int(WO.x), int(WO.y), WhiteOut, 1, 1, 0.0f, WHITE);
				}
			}
			if (ResultON == 1) {
				if (flyScore <= highScore) {
					Novice::DrawSprite(int(scoreB.pos.x - (scoreB.w / 2)), int(scoreB.pos.y - (scoreB.h / 2)), ScoreB, 1, 1, 0.0f, WHITE);
				}
				else if (flyScore > highScore) {
					Novice::DrawSprite(int(scoreB.pos.x - (scoreB.w / 2)), int(scoreB.pos.y - (scoreB.h / 2)), HScoreB, 1, 1, 0.0f, WHITE);
				}
				if (Next.Hit == 1) {
					Novice::DrawQuad(int(nextHit.left), int(nextHit.top), int(nextHit.right), int(nextHit.top), int(nextHit.left), int(nextHit.bottom), int(nextHit.right), int(nextHit.bottom), 0, 0, 88, 72, NextHit, WHITE);
				}
				else {
					Novice::DrawQuad(int(nextHit.left), int(nextHit.top), int(nextHit.right), int(nextHit.top), int(nextHit.left), int(nextHit.bottom), int(nextHit.right), int(nextHit.bottom), 0, 0, 88, 72, NextB, WHITE);
				}
				Novice::DrawSprite(565, 356, ScoreON[FLY3], 1, 1, 0.0f, WHITE);
				Novice::DrawSprite(595, 356, ScoreON[FLY2], 1, 1, 0.0f, WHITE);
				Novice::DrawSprite(625, 356, ScoreON[FLY1], 1, 1, 0.0f, WHITE);
			}
			if (Next.keyON == 1) {
				Novice::DrawSprite(0, 0, Shadow, 1, 1, 0.0f, WHITE);
				if (Yes.Hit == 1) {
					Novice::DrawQuad(int(yesHit.left), int(yesHit.top), int(yesHit.right), int(yesHit.top), int(yesHit.left), int(yesHit.bottom), int(yesHit.right), int(yesHit.bottom), 0, 0, 128, 64, YESHit, WHITE);
				}
				else {
					Novice::DrawQuad(int(yesHit.left), int(yesHit.top), int(yesHit.right), int(yesHit.top), int(yesHit.left), int(yesHit.bottom), int(yesHit.right), int(yesHit.bottom), 0, 0, 128, 64, YES, WHITE);
				}
				if (No.Hit == 1) {
					Novice::DrawQuad(int(noHit.left), int(noHit.top), int(noHit.right), int(noHit.top), int(noHit.left), int(noHit.bottom), int(noHit.right), int(noHit.bottom), 0, 0, 192, 64, NOHit, WHITE);
				}
				else {
					Novice::DrawQuad(int(noHit.left), int(noHit.top), int(noHit.right), int(noHit.top), int(noHit.left), int(noHit.bottom), int(noHit.right), int(noHit.bottom), 0, 0, 192, 64, NO, WHITE);
				}
			}
			break;
		}

		switch (game) {
		case tittle:
			Novice::StopAudio(FlyVoice);
			if (conHelp.keyON == 1) {
				if (Novice::IsPlayingAudio(TittleVoice) == 0 || TittleVoice == -1) {
					TittleVoice = Novice::PlayAudio(TittleBGM, true, 0.3f);
				}
			}
			break;
		case Screw:
			Novice::StopAudio(TittleVoice);
			Novice::StopAudio(FlyVoice);
			if (Novice::IsPlayingAudio(ScrewVoice1) == 0 || ScrewVoice1 == -1) {
				ScrewVoice1 = Novice::PlayAudio(ScrewBGM1, true, 0.3f);
			}
			if (OKButton.keyON == 1) {
				Novice::StopAudio(ScrewVoice1);
			}
			if (startSign.w >= 50) {
				if (Novice::IsPlayingAudio(StartVoice) == 0 || StartVoice == -1) {
					StartVoice = Novice::PlayAudio(StartSE, false, 1);
				}
			}
			if (startCountDown[1] < 60) {
				Novice::StopAudio(StartVoice);
			}
			if (screwStart == 1) {
				if (Novice::IsPlayingAudio(ScrewVoice2) == 0 || ScrewVoice2 == -1) {
					ScrewVoice2 = Novice::PlayAudio(ScrewBGM2, true, 0.3f);
				}
				if (Novice::IsTriggerMouse(0)) {
					if (Novice::IsPlayingAudio(ScrewSEVoice) == 0 || ScrewSEVoice == -1) {
						ScrewSEVoice = Novice::PlayAudio(ScrewSE, false, 1);
					}
				}
			}
			if (screwTime == 0) {
				Novice::StopAudio(ScrewVoice2);
				Novice::StopAudio(ScrewSEVoice);
			}
			if (stopIconON == 1) {
				if (Novice::IsPlayingAudio(StopVoice) == 0 || StopVoice == -1) {
					StopVoice = Novice::PlayAudio(StopSE, 0, 1);
				}
			}
			if (finishCountDown == 0) {
				Novice::StopAudio(StopVoice);
			}
			break;
		case flying:
			if (flyCountON == 1) {
				if (Novice::IsPlayingAudio(FlyCountVoice) == 0 || FlyCountVoice == -1) {
					FlyCountVoice = Novice::PlayAudio(FlyCountBGM, false, 1);
				}
			}
			if (flyCountDown == 0) {
				Novice::StopAudio(FlyCountVoice);
			}
			if (FRocket.keyON == 1) {
				if (Novice::IsPlayingAudio(FlyVoice) == 0 || FlyVoice == -1) {
					FlyVoice = Novice::PlayAudio(FlyBGM, true, 0.3f);
				}
			}
			break;
		}
		Novice::DrawSprite(mouseX - 15, mouseY - 15, Cursor, 1, 1, 0.0f, WHITE);

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0 || quit.keyON == 1) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
