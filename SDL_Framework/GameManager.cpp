#include "GameManager.h"

namespace SDLFramework {
    GameManager* GameManager::sInstance = nullptr;

    GameManager* GameManager::Instance() {
        if (sInstance == nullptr) {
            sInstance = new GameManager();
        }

        return sInstance;
    }

    void GameManager::Release() {
        delete sInstance;
        sInstance = nullptr;
    }

    void GameManager::Run() {
        //Main Game Loop
        while (!mQuit) {
            mTimer->Update();
            //Event Polling Loop
            //While there are events inside of our events varaible...
            while (SDL_PollEvent(&mEvents)) {
                //Handle each and every event we want to look for
                switch (mEvents.type) {
                case SDL_QUIT:
                    mQuit = true;
                    break;
                }
            }

            if (mTimer->DeltaTime() >= 1.0f / FRAME_RATE) {
                mTimer->Reset();
                Update();
                LateUpdate();
                Render();
            }
        }
    }

    void GameManager::Update() {
        mInputManager->Update();

        mStartScreen->Update();
        mBackgroundStars->Update();

        if (mInputManager->KeyDown(SDL_SCANCODE_W)) {
            
        }
        else if (mInputManager->KeyDown(SDL_SCANCODE_S)) {
            
        }
        //To prevent diagonal movement, add an else to the if statement below
        if (mInputManager->KeyDown(SDL_SCANCODE_A)) {
            
        }
        else if (mInputManager->KeyDown(SDL_SCANCODE_D)) {
            
        }

        if (mInputManager->KeyPressed(SDL_SCANCODE_SPACE)) {

        }

        if (mInputManager->KeyReleased(SDL_SCANCODE_SPACE)) {
            
        }
    }

    void GameManager::LateUpdate() {
        mPhysicsManager->Update();
        mInputManager->UpdatePrevInput();
    }

    void GameManager::Render() {
        //This is the old frame we need to clear
        mGraphics->ClearBackBuffer();
        mBackgroundStars->Render();
        mStartScreen->Render();

        //Actually showing everthing that we have told to render
        mGraphics->Render();
    }

    GameManager::GameManager() : mQuit(false) {
        //calling to our Graphics Singleton
        mGraphics = Graphics::Instance();

        if (!Graphics::Initialized()) {
            mQuit = true;
        }

        //Initialize all other modules
        mTimer = Timer::Instance();
        mAssetManager = AssetManager::Instance();
        mInputManager = InputManager::Instance();
        mAudioManager = AudioManager::Instance();
        mPhysicsManager = PhysicsManager::Instance();
        mRandom = Random::Instance();
        mBackgroundStars = BackgroundStars::Instance();
        

        //Create my Physics Layers
        mPhysicsManager->SetLayerCollisionMask(PhysicsManager::CollisionLayers::Friendly,
            PhysicsManager::CollisionFlags::Hostile |
            PhysicsManager::CollisionFlags::HostileProjectile);

        mPhysicsManager->SetLayerCollisionMask(PhysicsManager::CollisionLayers::Hostile,
            PhysicsManager::CollisionFlags::Friendly |
            PhysicsManager::CollisionFlags::FriendlyProjectile);

        //Creating Screens
        mStartScreen = new StartScreen();

        //Creating GameObjects
        std::cout << "Random Float Test: " << mRandom->RandomFloat() << std::endl;
        std::cout << "Random Float Test: " << mRandom->RandomFloat() << std::endl;
        std::cout << "Random Float Test: " << mRandom->RandomFloat() << std::endl;

        std::cout << "Random Int Test: " << mRandom->RandomInt() << std::endl;
        std::cout << "Random Int Test: " << mRandom->RandomInt() << std::endl;
        std::cout << "Random Int Test: " << mRandom->RandomInt() << std::endl;

        std::cout << "Random Range(Int) Test: " << mRandom->RandomRange(0, 10) << std::endl;
        std::cout << "Random Range(Int) Test: " << mRandom->RandomRange(0, 10) << std::endl;
        std::cout << "Random Range(Int) Test: " << mRandom->RandomRange(0, 10) << std::endl;

        std::cout << "Random Range(Float) Test: " << mRandom->RandomRange(0.0f, 10.0f) << std::endl;
        std::cout << "Random Range(Float) Test: " << mRandom->RandomRange(0.0f, 10.0f) << std::endl;
        std::cout << "Random Range(Float) Test: " << mRandom->RandomRange(0.0f, 10.0f) << std::endl;

    }

    GameManager::~GameManager() {
        //Release Variables
        delete mStartScreen;
        mStartScreen = nullptr;

        //Release Modules
        Graphics::Release();
        mGraphics = nullptr;

        Timer::Release();
        mTimer = nullptr;

        AssetManager::Release();
        mAssetManager = nullptr;

        InputManager::Release();
        mInputManager = nullptr;

        AudioManager::Release();
        mAudioManager = nullptr;

        PhysicsManager::Release();
        mPhysicsManager = nullptr;

        Random::Release();
        mRandom = nullptr;

        BackgroundStars::Release();
        mBackgroundStars = nullptr;

        //Quit SDl Subsystems
        SDL_Quit();
    }
    //Namespace bracket is below
}