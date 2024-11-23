#pragma once
#include "AnimatedTexture.h"
#include "InputManager.h"

using namespace SDLFramework;

class StartScreen : public GameEntity {
public:
	StartScreen();
	~StartScreen();

	void ChangeSelectedMode(int change);

	void Update() override;
	void Render() override;

private:
	Timer* mTimer;
	InputManager* mInputManager;

	//Screen Animation Variables
	Vector2 mAnimationStartPos;
	Vector2 mAnimationEndPos;
	float mAnimationTotalTime;
	float mAnimationTimer;
	bool mAnimationDone;

	//Top Bar Entities
	//Empty GameEntity/GameObject
	GameEntity* mTopBar;
	Texture* mPlayerOne;
	Texture* mPlayerTwo;
	Texture* mHiScore;

	//Logo Entities
	GameEntity* mLogoHolder;
	Texture* mLogo;
	AnimatedTexture* mAnimatedLogo;

	//Play Mode
	GameEntity* mPlayModes;
	Texture* mOnePlayerMode;
	Texture* mTwoPlayerMode;
	Texture* mCursor;
	Vector2 mCursorStartPos;
	Vector2 mCursorOffsetPos;
	int mSelectedMode;

	//Bottom Bar
	GameEntity* mBottomBar;
	Texture* mNamco;
	Texture* mDates;
	Texture* mRights;
};