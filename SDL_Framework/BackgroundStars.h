#pragma once
#include "StarLayer.h"

class BackgroundStars {
public:
	static BackgroundStars * Instance();
	static void Release();

	void Scroll(bool b);

	void Update();
	void Render();

private:
	static BackgroundStars* sInstance;
	static const int LAYER_COUNT = 3;
	StarLayer* mLayers[LAYER_COUNT];

	BackgroundStars();
	~BackgroundStars();
};