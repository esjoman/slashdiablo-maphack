#include "Resolution.h"
#include "../../D2Ptrs.h"
#include "../../BH.h"
#include "../../D2Stubs.h"
#include "../../D2Helpers.h"

using namespace std;

void Resolution::OnLoad() {
	use1300x700 = BH::config->ReadBoolean("Res1300x700", false);
}

void Resolution::OnUnload() {
}

int GetMode(int height) {
	switch(height)
	{
		case 800:
			return 2;
		case 640:
			return 1;
	}
	return 3;
}

//Shaggi's resolution fix, all credits to him
void SetResolution(int x, int y) {
	//GetMode(*p_D2CLIENT_ScreenSizeY);
	int mode = GetMode(y);
	*p_D2CLIENT_CropMode = 0;
	D2WIN_SetResolutionMode(mode);
	*p_D2CLIENT_ScreenSizeX = *p_D2CLIENT_MapPosX = *p_D2CLIENT_SizeX1 = *p_D2CLIENT_SizeX2 = x;
	*p_D2CLIENT_ScreenSizeY = *p_D2CLIENT_SizeY1 = y;
	*p_D2CLIENT_MapPosY = y - 40; // subtract 40 to correct offsets
	D2CLIENT_ResizeDiablo();
	
}

void Resolution::OnGameJoin(const string& name, const string& pass, int diff) {
	if (use1300x700) {
		SetResolution(1300, 700);
	}
}