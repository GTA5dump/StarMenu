#pragma once

enum SubMenus { //Add Sub Menus in here
	NOMENU,
	mainmenu,
	sub,
	settings,
	exitgta,
	settingstheme,
	Credits,
	themeloader,
	position,
	settingstitlerect,
	settingsscroller,
	settingsoptiontext,
	font,
	network,
	vehicle,
	world,
	pedspawner,
	other,
	tunables,
	plist,
	pmenu,
	weapon,
	bullets,
	teleport,
	animationen,
	mapmods,
	items,
	model,
	weather,
	animation,
	money,
	drops,
	drop,
	playerwaepons,
	outfit,
	playervehicle,
	verweigert,
	overlay,
	spawnplayervehicle,
	spawnvehiclelocal,
	lowriders,
	anderes,
	super,
	sport,
	others,
	muscle,
	gottengains,
	heist,
	motorcycles,
	offroade,
	planes,
	helicopters,
	emergency,
	military,
	special,
	boats,
	spawnvehicles,
	spawnplayervehicleLocal,
	spawnvehicle,
	troll,
	sportclassic,
	playerlist,
	hornboost,
	vehicleoptions,
	playermenu,
	weatheroptions,
	Allplayer,
	recoverymenu,
	protection,
	onlineoptions,
	moddedvehicle,
	ride,
	unlockall,
	stats,
	weaponmods,
	weaponammo,
	shootthings,
	outfitt,
	ped,
	movement,
	carmovement,
	dropss,







	lowriders1,
	anderes1,
	super1,
	sport1,
	muscle1,
	gottengains1,
	heist1,
	motorcycles1,
	offroade1,
	planes1,
	helicopters1,
	emergency1,
	military1,
	special1,
	boats1,
	spawnvehicles1,

};
extern enum SubMenus;

typedef struct VECTOR2 {
	float x, y;
};
typedef struct VECTOR2_2 {
	float w, h;
};
typedef struct RGBAF {
	int r, g, b, a, f;
};
typedef struct RGBA {
	int r, g, b, a;
};
typedef struct RGB {
	int r, g, b;
};


namespace Drawing {
	void Header();
	void Text(const char* text, RGBAF rgbaf, VECTOR2 position, VECTOR2_2 size, bool center);
	void Text(const char * text, RGBAF rgbaf, VECTOR2 position, float size);

	void Title(const char* text, RGBAF rgbaf, VECTOR2 position, VECTOR2_2 size, bool center);
	//void Title2(const char* text, RGBAF rgbaf, VECTOR2 position, VECTOR2_2 size, bool center);
	void Rect(RGBA rgba, VECTOR2 position, VECTOR2_2 size);
	void Rect(RGBA rgba, VECTOR2 position, VECTOR2_2 size);
	void Spriter(std::string Streamedtexture, std::string textureName, float x, float y, float width, float height, float rotation, int r, int g, int b, int a);
}

namespace Settings {
	/*bool MenuPlayer(const char* option, SubMenus newSub, int player);
	bool MenuPlayer(const char* option, SubMenus newSub, int player, std::function<void()> function);*/
	extern bool selectPressed;
	extern bool leftPressed;
	//extern bool setspoofrankpl;
	extern bool schwesselfick;
	extern bool schwesselfickk;
	extern bool rightPressed;
	extern bool amount405;
	extern bool center;
	extern int titleRectTexture;
	extern bool headerlist;
	extern int alpha;
	extern int setspoofrankpl;
	extern int LVL;
	extern bool controllerinput;
	extern int gayStealth;
	extern int stealthDelay405;
	extern int run;
	extern bool GlareOnOff;
	extern float GlareXPos;
	extern bool DrawGradientRect;
	extern float bulletp;
	extern float camerra;
	extern float bulletppp;
	extern int bullet;
	extern int notoirff;
	extern int offradard;
	extern bool Authcheckder2;
	extern int Hourfick;
	extern int Minufick;
	extern int secfick;
	extern bool Virustroll;
	extern bool Authcheck;
	extern int maxVisOptions;
	extern int currentOption;
	extern int optionCount;
	extern int alpha2;
	extern float menuX;
	extern float menuY;
	extern bool playertenkped;
	void TenKPedMoney(bool toggle);
}

namespace Menu {
	namespace Drawing {
		void Text(const char* text, RGBAF rgbaf, VECTOR2 position, VECTOR2_2 size, bool center);
		void Rect(RGBA rgba, VECTOR2 position, VECTOR2_2 size);
		void Spriter(std::string Streamedtexture, std::string textureName, float x, float y, float width, float height, float rotation, int r, int g, int b, int a);
		void DrawSprite(char* textureDict, char* textureName, float x, float y, float width, float height, float rotation, int r, int g, int b, int a);

	}
	namespace Drawing {
		void Header();
		void Text(const char* text, RGBAF rgbaf, VECTOR2 position, VECTOR2_2 size, bool center);
		void Text(const char * text, RGBAF rgbaf, VECTOR2 position, float size);

		void Title(const char* text, RGBAF rgbaf, VECTOR2 position, VECTOR2_2 size, bool center);
		//void Title2(const char* text, RGBAF rgbaf, VECTOR2 position, VECTOR2_2 size, bool center);
		void Rect(RGBA rgba, VECTOR2 position, VECTOR2_2 size);
		void Rect(RGBA rgba, VECTOR2 position, VECTOR2_2 size);
		void Spriter(std::string Streamedtexture, std::string textureName, float x, float y, float width, float height, float rotation, int r, int g, int b, int a);
	}

	
	namespace Settings {
		void DrawGlare(float pX, float pY, float scaleX, float scaleY, int red, int green, int blue, int alpha);
		void render_globe(const float x, const float y, const float sx, const float sy, const int r, const int g, const int b);
		void DRAW_TEXTURE(std::string Streamedtexture, std::string textureName, float x, float y, float width, float height, float rotation, int r, int g, int b, int a);
		extern bool selectPressed;
		extern bool leftPressed;
		extern bool rightPressed;
		extern bool center;
		extern bool controllerinput;
		extern bool GlareOnOff;
		extern float GlareXPos;

		extern int titleRectTexture;
		extern int maxVisOptions;
		extern int currentOption;
		extern int optionCount;

		extern SubMenus currentMenu;
		extern int menuLevel;
		extern int optionsArray[1000];
		extern SubMenus menusArray[1000];

		extern float menuX;
		extern RGBAF count;
		extern RGBAF titleText;
		extern RGBA titleRect;
		extern RGBAF breakText;
		extern RGBA breakTextRect;
		extern RGBAF optionText;
		extern RGBA selectedText;
		extern RGBAF arrow;
		extern RGBAF integre;
		extern RGBA optionRect;
		extern RGBA scroller;
		extern RGBA line;
		extern RGBA linee;
		extern RGBA primary;
		extern RGBA secondary;
		extern float menuX;
		extern float menuY;
		extern RGBA titleEnd;
		extern RGBA text;
		extern RGBA Scrollergradient;
		extern RGBAF count;
		extern RGBAF titleText;
		extern RGBAF PremiumTitle;
		extern RGBAF SelectedText;
		extern RGBA titleline;
		extern RGBA scrollerr;
		extern RGBAF integre;
		extern RGBA title_sprite;
		extern RGBA title_sprite2;
		extern RGBAF title_end;
		extern RGBAF integre2;
		extern RGBAF titleText3;
		extern RGBAF titleText2;
		extern RGBA titleRect;
		extern RGBAF breakText;
		extern RGBAF optionText;
		extern RGBAF optionTextt;
		extern RGBA selectedText;
		extern RGBAF arrow;
		extern RGBAF arrow2;
		extern RGBAF arrowww;
		extern RGBAF integre;
		extern RGBA optionRect;
		extern RGBA optionRectt;
		extern RGBA scroller;
		extern RGBA scroller_pos_now;
		extern RGBA line;
		extern RGBA Endrect;
		extern RGBA linego;
		extern RGBA primary;
		extern RGBA secondary;
		extern RGBA Endrectlol;
		extern RGBA Endrectloll;
		extern RGBA Endrectloool;
		extern RGBA titleEndd;

		extern int keyPressDelay;
		extern int keyPressPreviousTick;
		extern int keyPressDelay2;
		extern int keyPressPreviousTick2;
		extern int keyPressDelay3;
		extern int keyPressPreviousTick3;
		extern int openKey;
		extern int backKey;
		extern int upKey;
		extern int downKey;
		extern int leftKey;
		extern int rightKey;
		extern int selectKey;
		extern int arrowupKey;
		extern int arrowdownKey;
		extern int arrowleftKey;
		extern int arrowrightKey;
		extern int enterKey;
		extern int deleteKey;
		extern int openpress;
		extern int downpress;
		extern int uppress;
		extern int backpress;
		extern int click;
		extern int leftpress;
		extern int rightpress;

		extern int TimePD;
		extern int TimePD1;
		extern int TimePD2;
		extern int TimePD3;
		extern int TimePD4;
		extern int TimePD5;
		extern int Bags;
		extern int TimePD6;
		extern int TimePD7;
		extern int TimePD8;
		extern int TimePD9;
		extern int TimePD10;
		extern int TimePD11;
		extern int TimePD12;
		extern int TimePD13;
		extern int TimePD14;




	}
	namespace MenuLevelHandler {
		void MoveMenu(SubMenus menu);
		void BackMenu();
	}
	namespace Checks {
		void Controlls();
	}
	namespace Tools {
		char* StringToChar(std::string string);
	}
	namespace Files {
		void WriteStringToIni(std::string string, std::string file, std::string app, std::string key);
		std::string ReadStringFromIni(std::string file, std::string app, std::string key);
		void WriteIntToIni(int intValue, std::string file, std::string app, std::string key);
		int ReadIntFromIni(std::string file, std::string app, std::string key);
		void WriteFloatToIni(float floatValue, std::string file, std::string app, std::string key);
		float ReadFloatFromIni(std::string file, std::string app, std::string key);
		void WriteBoolToIni(bool b00l, std::string file, std::string app, std::string key);
		bool ReadBoolFromIni(std::string file, std::string app, std::string key);
	}
	void Title(const char* title);
	void info(const char * title);
	void Vehicle(std::string texture1, std::string texture2);
	void Speedometer(char* text);
	void fps(char* text);
	void AddSmallTitle(char* text);
	void AddSmallInfo(char* text, short line);
	bool FileExists(const std::string& fileName);
	int RegisterFile(const std::string& fullPath, const std::string& fileName);
	void AddSmallTitle2(char* text);
	void AddSmallInfo2(char* text, short line);
	void AddSmallTitle3(char* text);
	void AddSmallInfo3(char* text, short line);
	bool Break(const char* option);
	bool Option(const char* option);
	bool Option(const char* option, std::function<void()> function);
	bool MenuOption(const char* option, SubMenus newSub);
	bool MenuOption(const char* option, SubMenus newSub, std::function<void()> function);
	bool Toggle(const char* option, bool& b00l);
	bool MenuOption(const char* option, bool& b00l);
	bool Int(const char* option, int& _int, int min, int max);
	bool Int(const char* option, int& _int, int min, int max, int step);
	bool Int(const char* option, int& _int, int min, int max, std::function<void()> function);
	bool Int(const char* option, int& _int, int min, int max, int step, std::function<void()> function);
	bool Float(const char* option, float& _float, int min, int max);
	bool Float(const char* option, float& _float, int min, int max, int step);
	bool Float(const char* option, float& _float, int min, int max, std::function<void()> function);
	bool Float(const char* option, float& _float, int min, int max, int step, std::function<void()> function);
	bool IntVector(const char* option, std::vector<int> Vector, int& position);
	bool IntVector(const char* option, std::vector<int> Vector, int& position, std::function<void()> function);
	bool FloatVector(const char* option, std::vector<float> Vector, int& position);
	bool FloatVector(const char* option, std::vector<float> Vector, int& position, std::function<void()> function);
	bool StringVector(const char* option, std::vector<std::string> Vector, int& position);
	bool StringVector(const char* option, std::vector<std::string> Vector, int& position, std::function<void()> function);
	bool StringVector(const char* option, std::vector<char*> Vector, int& position);
	bool StringVector(const char* option, std::vector<char*> Vector, int& position, std::function<void()> function);
	bool Teleport(const char* option, Vector3 coords);
	bool Teleport(const char* option, Vector3 coords, std::function<void()> function);
	void End();
}
