#include "BackgroundStars.h"

BackgroundStars* BackgroundStars::sInstance = nullptr;

BackgroundStars* BackgroundStars::Instance() {
	if (sInstance == nullptr) {
		sInstance = new BackgroundStars();
	}

	return sInstance;
}

void BackgroundStars::Release() {
	delete sInstance;
	sInstance = nullptr;
}

void BackgroundStars::Scroll(bool b) {
	Star::Scroll(b);
}

void BackgroundStars::Update() {
	for (auto layer : mLayers) {
		layer->Update();
	}
}

void BackgroundStars::Render() {
	for (auto layer : mLayers) {
		layer->Render();
	}
}

BackgroundStars::~BackgroundStars() {
	for (int i = 0; i < LAYER_COUNT; i++) {
		delete mLayers[i];
		mLayers[i] = nullptr;
	}
}
