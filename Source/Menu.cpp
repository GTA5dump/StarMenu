
#pragma once
#include "stdafx.h"

#include <windows.h>
#include <shellapi.h>

extern bool playertenkped;
void TenKPedMoney(bool toggle);

bool Settings::playertenkped = false;
int Menu::Settings::TimePD;
int Menu::Settings::TimePD1;
int Menu::Settings::TimePD2;
int Menu::Settings::TimePD3;
int Menu::Settings::TimePD4;
int Menu::Settings::TimePD5;
int Menu::Settings::TimePD6;
int Menu::Settings::TimePD7;
int Menu::Settings::TimePD8;
int Menu::Settings::TimePD9;
int Menu::Settings::TimePD10;
int Menu::Settings::TimePD11;
int Menu::Settings::TimePD12;
int Menu::Settings::TimePD13;
int Menu::Settings::TimePD14;



int selectedPlayer = 0;

Vector3 CombineVector(float x, float y, float z)
{
	Vector3 returnVector;
	returnVector.x = x;
	returnVector.y = y;
	returnVector.z = z;
	return returnVector;
}

Vector3 add3(Vector3* vectorA, Vector3* vectorB)
{
	Vector3 result;
	result.x = vectorA->x;
	result.y = vectorA->y;
	result.z = vectorA->z;

	result.x += vectorB->x;
	result.y += vectorB->y;
	result.z += vectorB->z;

	return result;
}
Vector3 multiply3(Vector3* vector, float x)
{
	Vector3 result;
	result.x = vector->x;
	result.y = vector->y;
	result.z = vector->z;

	result.x *= x;
	result.y *= x;
	result.z *= x;

	return result;
}

Vector3 rotDirection(Vector3* rot)
{
	float radianz = rot->z * 0.0174532924f;
	float radianx = rot->x * 0.0174532924f;
	float num = std::abs((float)std::cos((double)radianx));

	Vector3 dir;

	dir.x = (float)((double)((float)(-(float)std::sin((double)radianz))) * (double)num);
	dir.y = (float)((double)((float)std::cos((double)radianz)) * (double)num);
	dir.z = (float)std::sin((double)radianx);

	return dir;
}

char* CharKeyboard(char* windowName = "", int maxInput = 21, char* defaultText = "") {
	GAMEPLAY::DISPLAY_ONSCREEN_KEYBOARD(0, "", "", defaultText, "", "", "", maxInput);
	while (GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD() == 0) WAIT(0);
	if (!GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT()) return "";
	return GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT();
}
int NumberKeyboard() {
	GAMEPLAY::DISPLAY_ONSCREEN_KEYBOARD(1, "", "", "", "", "", "", 10);
	while (GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD() == 0) WAIT(0);
	if (!GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT()) return 0;
	return atof(GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT());
}
void notifyleft(char* msg)
{
	UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(msg);
	UI::_DRAW_NOTIFICATION(2000, 1);
}

Vector3 TPCoords;
void TPto(Vector3 Coords)
{
	int Handle = PLAYER::PLAYER_PED_ID();
	if (PED::IS_PED_IN_ANY_VEHICLE(Handle, 0))
	{
		ENTITY::SET_ENTITY_COORDS(PED::GET_VEHICLE_PED_IS_IN(Handle, false), Coords.x, Coords.y, Coords.z, 0, 0, 0, 1);
	}
	else
		ENTITY::SET_ENTITY_COORDS(Handle, Coords.x, Coords.y, Coords.z, 0, 0, 0, 1);
}

void TeleportToClient(int Client)
{
	Vector3 Coords = ENTITY::GET_ENTITY_COORDS(Client, 1);
	if (PED::IS_PED_SITTING_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID()))
		ENTITY::SET_ENTITY_COORDS(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), Coords.x, Coords.y, Coords.z, 1, 0, 0, 1);
	else
		ENTITY::SET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), Coords.x, Coords.y, Coords.z, 1, 0, 0, 1);
}


bool vehiclegodmode = false;
void VehicleGodmode()
{
	if (vehiclegodmode)
	{
		Ped playerPed = PLAYER::PLAYER_PED_ID();
		Vehicle vehicle = PED::GET_VEHICLE_PED_IS_USING(playerPed);
		ENTITY::SET_ENTITY_INVINCIBLE(vehicle, vehiclegodmode);
		ENTITY::SET_ENTITY_PROOFS(vehicle, vehiclegodmode, vehiclegodmode, vehiclegodmode, vehiclegodmode, vehiclegodmode, vehiclegodmode, vehiclegodmode, vehiclegodmode);
		VEHICLE::SET_VEHICLE_STRONG(vehicle, vehiclegodmode);
		VEHICLE::SET_VEHICLE_CAN_BREAK(vehicle, !vehiclegodmode);
		VEHICLE::SET_VEHICLE_ENGINE_CAN_DEGRADE(vehicle, !vehiclegodmode);
		VEHICLE::SET_VEHICLE_CAN_BE_VISIBLY_DAMAGED(vehicle, !vehiclegodmode);
	}
}

void deletecar(int Client = PLAYER::PLAYER_ID())
{
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	if (PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
	{
		Vehicle playerVeh = PED::GET_VEHICLE_PED_IS_IN(playerPed, false);
		NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(playerVeh);
		if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(playerVeh))
		{
			if (ENTITY::DOES_ENTITY_EXIST(playerVeh))
			{
				ENTITY::SET_ENTITY_AS_MISSION_ENTITY(playerVeh, 1, 1);
				VEHICLE::DELETE_VEHICLE(&playerVeh);
			}
		}
	}
}

uint Veh = PED::GET_VEHICLE_PED_IS_USING(PLAYER::GET_PLAYER_PED(PLAYER::PLAYER_ID()));
void MaxUpgrades(uint veh)
{
	VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
	VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT_INDEX(veh, 1);
	VEHICLE::TOGGLE_VEHICLE_MOD(veh, 18, 1);
	VEHICLE::TOGGLE_VEHICLE_MOD(veh, 22, 1);
	VEHICLE::SET_VEHICLE_MOD(veh, 16, 5, 0);
	VEHICLE::SET_VEHICLE_MOD(veh, 12, 2, 0);
	VEHICLE::SET_VEHICLE_MOD(veh, 11, 3, 0);
	VEHICLE::SET_VEHICLE_MOD(veh, 14, 14, 0);
	VEHICLE::SET_VEHICLE_MOD(veh, 15, 3, 0);
	VEHICLE::SET_VEHICLE_MOD(veh, 13, 2, 0);
	VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, 6);
	VEHICLE::SET_VEHICLE_WINDOW_TINT(veh, 5);
	VEHICLE::SET_VEHICLE_MOD(veh, 23, 19, 1);
	VEHICLE::SET_VEHICLE_MOD(veh, 0, 1, 0);
	VEHICLE::SET_VEHICLE_MOD(veh, 1, 1, 0);
	VEHICLE::SET_VEHICLE_MOD(veh, 2, 1, 0);
	VEHICLE::SET_VEHICLE_MOD(veh, 3, 1, 0);
	VEHICLE::SET_VEHICLE_MOD(veh, 4, 1, 0);
	VEHICLE::SET_VEHICLE_MOD(veh, 5, 1, 0);
	VEHICLE::SET_VEHICLE_MOD(veh, 6, 1, 0);
	VEHICLE::SET_VEHICLE_MOD(veh, 7, 1, 0);
	VEHICLE::SET_VEHICLE_MOD(veh, 8, 1, 0);
	VEHICLE::SET_VEHICLE_MOD(veh, 9, 1, 0);
	VEHICLE::SET_VEHICLE_MOD(veh, 10, 1, 0);
	VEHICLE::_IS_VEHICLE_NEON_LIGHT_ENABLED(veh, 1);
	VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(veh, 0, 1);
	VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(veh, 1, 1);
	VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(veh, 2, 1);
	VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(veh, 3, 1);
	VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(veh, 4, 1);
	VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(veh, 5, 1);
	VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(veh, 6, 1);
	VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(veh, 7, 1);
	VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
	VEHICLE::TOGGLE_VEHICLE_MOD(veh, 20, 1);
	VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
	VEHICLE::SET_VEHICLE_TYRE_SMOKE_COLOR(veh, 0, 0, 0);
	STREAMING::REQUEST_NAMED_PTFX_ASSET("proj_xmas_firework");
	STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_clown_appears");
}

bool Godmode = false;
void godmode()
{
	if (Godmode)
	{
		ENTITY::SET_ENTITY_INVINCIBLE(PLAYER::PLAYER_PED_ID(), true);
	}
	else
	{
		ENTITY::SET_ENTITY_INVINCIBLE(PLAYER::PLAYER_PED_ID(), false);
	}



}
void BypassOnlineVehicleKick(Vehicle vehicle)
{
	Player player = PLAYER::PLAYER_ID();
	int var;
	DECORATOR::DECOR_SET_INT(vehicle, "MPBitset", 0);
}
void autovehi(char* toSpawn);

void autovehi(char* toSpawn) 
{
	Hash model = GAMEPLAY::GET_HASH_KEY(toSpawn);
	if (STREAMING::IS_MODEL_VALID(model))
	{

		STREAMING::REQUEST_MODEL(model);
		while (!STREAMING::HAS_MODEL_LOADED(model)) WAIT(0);
		Vector3 ourCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), false);
		float forward = 5.f;
		float heading = ENTITY::GET_ENTITY_HEADING(PLAYER::PLAYER_PED_ID());
		float xVector = forward * sin(degToRad(heading)) * -1.f;
		float yVector = forward * cos(degToRad(heading));
		Vehicle veh = VEHICLE::erstelle_fahr(model, ourCoords.x + xVector, ourCoords.y + yVector, ourCoords.z, heading, true, false);
		RequestControlOfEnt(veh);
		VEHICLE::SET_VEHICLE_ENGINE_ON(veh, true, true, true);
		VEHICLE::SET_VEHICLE_ON_GROUND_PROPERLY(veh);
		NETWORK::NETWORK_FADE_IN_ENTITY(veh, 0);
		DECORATOR::DECOR_SET_INT(veh, "MPBitset", 0);
		auto networkId = NETWORK::VEH_TO_NET(veh);
		ENTITY::_SET_ENTITY_REGISTER(veh, true);
		BypassOnlineVehicleKick(0);
		if (NETWORK::NETWORK_GET_ENTITY_IS_NETWORKED(veh))
			NETWORK::SET_NETWORK_ID_EXISTS_ON_ALL_MACHINES(networkId, true);
		{
			VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);
			for (int i = 0; i < 50; i++)
			{

				VEHICLE::SET_VEHICLE_MOD(veh, i, VEHICLE::GET_NUM_VEHICLE_MODS(veh, i) - 1, false);
				VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(vehicle, "Redhunter");
				AUDIO::SET_VEH_RADIO_STATION(veh, "OFF");
				//GRAPHICS::_SET_PTFX_ASSET_NEXT_CALL("scr_rcbarry2");
				//GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY("scr_clown_appears", veh, 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 2.0, false, false, false);

			}
		}
	}
}


bool spawnincar = true;
bool spawnmaxed = false;

extern bool spawnincar;
extern bool spawnmaxed;

bool Unlimitedammo = false;
void unlimitedammo()
{
	if (Unlimitedammo)
	{
		WEAPON::SET_PED_INFINITE_AMMO_CLIP(PLAYER::PLAYER_PED_ID(), true);
	}
	else
	{
		WEAPON::SET_PED_INFINITE_AMMO_CLIP(PLAYER::PLAYER_PED_ID(), false);
	}



}

bool TeleportGun = false;
void teleportGun()
{
	if (TeleportGun)
	{
		if (ENTITY::DOES_ENTITY_EXIST(PLAYER::PLAYER_PED_ID()) && PED::IS_PED_SHOOTING_IN_AREA)
		{
			Vector3 iCoord;
			if (WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(PLAYER::PLAYER_PED_ID(), &iCoord))
			{
				ENTITY::SET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), iCoord.x, iCoord.y, iCoord.z + 1, 0, 0, 1, 1);
			}
		}
		else
		{
			NULL;
		}
	}
}

bool Deletegun = false;
void deleteGun()
{
	if (Deletegun)
	{
		if (ENTITY::DOES_ENTITY_EXIST(PLAYER::PLAYER_PED_ID()) && PED::IS_PED_SHOOTING_IN_AREA)
		{
			Vector3 iCoord;
			if (WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(PLAYER::PLAYER_PED_ID(), &iCoord))
			{
				GAMEPLAY::_CLEAR_AREA_OF_EVERYTHING(iCoord.x, iCoord.y, iCoord.z, 2, 0, 0, 0, 0);
			}
		}
		else
		{
			NULL;
		}
	}
}

bool ShadowfitExist()
{
	DWORD dwAttrib = GetFileAttributesA(".\\ShadowFolder");
	return (dwAttrib != INVALID_FILE_ATTRIBUTES && dwAttrib & FILE_ATTRIBUTE_DIRECTORY);
}

bool SolOutfitExist()
{
	DWORD dwAttrib = GetFileAttributesA(".\\ShadowFolder\\Outfits");
	return (dwAttrib != INVALID_FILE_ATTRIBUTES && dwAttrib & FILE_ATTRIBUTE_DIRECTORY);
}

class Ini
{
private:
	std::string inifile;
public:
	Ini(std::string file)
	{
		this->inifile = file;
	}
	void WriteString(std::string string, std::string app, std::string key)
	{
		WritePrivateProfileStringA(app.c_str(), key.c_str(), string.c_str(), this->inifile.c_str());
	}
	std::string GetString(std::string app, std::string key)
	{
		char buf[100];
		GetPrivateProfileStringA(app.c_str(), key.c_str(), "NULL", buf, 100, this->inifile.c_str());
		return (std::string)buf;
	}
	void WriteInt(int value, std::string app, std::string key)
	{
		WriteString(std::to_string(value), app, key);
	}
	int GetInt(std::string app, std::string key)
	{
		return std::stoi(GetString(app, key));
	}
	void WriteFloat(float value, std::string app, std::string key)
	{
		WriteString(std::to_string(value), app, key);
	}
	float GetFloat(std::string app, std::string key)
	{
		return std::stof(GetString(app, key));
	}
};



int outfit1 = 0;
int Zoom = 0;
int outfit2 = 0;
int outfit3 = 0;
int outfit4 = 0;
int mask1 = 0;
int mask2 = 0;
int shirt1 = 0;
int pants1 = 0;
int hands1 = 0;
int shoes1 = 0;
int eyes1 = 0;
int Accessories1 = 0;
int mission1 = 0;
int decals1 = 0;
int collars1 = 0;
bool slowMotion;
bool FreezeTime;

int selectedOutfit = 0;

void SaveOutfit() {
	if (!ShadowfitExist()) {
		CreateDirectoryA(".\\StarModFolder\\Outfits", NULL);
	}
	Ini *settingsIni = new Ini(".\\StarModFolder\\Outfits\\" + to_string(selectedOutfit) + ".ini");
	settingsIni->WriteInt(outfit1, "Outfit", "1");
	settingsIni->WriteInt(mask1, "Outfit", "2");
	settingsIni->WriteInt(shirt1, "Outfit", "3");
	settingsIni->WriteInt(collars1, "Outfit", "4");
	settingsIni->WriteInt(Accessories1, "Outfit", "5");
	settingsIni->WriteInt(pants1, "Outfit", "6");
	settingsIni->WriteInt(hands1, "Outfit", "7");
	settingsIni->WriteInt(shoes1, "Outfit", "8");
	settingsIni->WriteInt(mission1, "Outfit", "9");
	settingsIni->WriteInt(decals1, "Outfit", "10");
}

void LoadOutfit() {
	Ini *settingsIni = new Ini(".\\StarModFolder\\Outfits\\" + to_string(selectedOutfit) + ".ini");
	outfit1 = settingsIni->GetInt("Outfit", "1");
	mask1 = settingsIni->GetInt("Outfit", "2");
	shirt1 = settingsIni->GetInt("Outfit", "3");
	collars1 = settingsIni->GetInt("Outfit", "4");
	Accessories1 = settingsIni->GetInt("Outfit", "5");
	pants1 = settingsIni->GetInt("Outfit", "6");
	hands1 = settingsIni->GetInt("Outfit", "7");
	shoes1 = settingsIni->GetInt("Outfit", "8");
	mission1 = settingsIni->GetInt("Outfit", "9");
	decals1 = settingsIni->GetInt("Outfit", "10");
	delete settingsIni;

}

bool NewDropp7= false;
void newdropp7()
{
	if (NewDropp7)
	{
		if ((timeGetTime() - Menu::Settings::TimePD2) > 400) // Time between drops
		{


			Ped iPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer);
			STREAMING::REQUEST_MODEL(GAMEPLAY::GET_HASH_KEY("prop_xmas_tree_int"));
			if (!STREAMING::HAS_MODEL_LOADED(GAMEPLAY::GET_HASH_KEY("prop_xmas_tree_int"))) {
				WAIT(0);
			}
			else {
				Vector3 playerPosition = ENTITY::GET_ENTITY_COORDS(iPed, FALSE);
				OBJECT::pockup(0xDE78F17E, playerPosition.x, playerPosition.y, playerPosition.z + 0.5f / 10, 0, 200, GAMEPLAY::GET_HASH_KEY("prop_xmas_tree_int"), FALSE, TRUE);
				STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(GAMEPLAY::GET_HASH_KEY("prop_xmas_tree_int"));
			}

			Menu::Settings::TimePD2 = timeGetTime();

		}
	}
}





//Money Drop Other Players 2.5k
bool NewDropp6 = false;
void newdropp6()
{
	if (NewDropp6)
	{
		if ((timeGetTime() - Menu::Settings::TimePD2) > 400) // Time between drops
		{


			Ped iPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer);
			STREAMING::REQUEST_MODEL(GAMEPLAY::GET_HASH_KEY("prop_alien_egg_01"));
			if (!STREAMING::HAS_MODEL_LOADED(GAMEPLAY::GET_HASH_KEY("prop_alien_egg_01")))
			{
				WAIT(0);
			}
			else
			{
				Vector3 playerPosition = ENTITY::GET_ENTITY_COORDS(iPed, FALSE);
				OBJECT::pockup(0xDE78F17E, playerPosition.x, playerPosition.y, playerPosition.z + 0.5f / 10, 0, 2000, GAMEPLAY::GET_HASH_KEY("prop_alien_egg_01"), FALSE, TRUE);
				STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(GAMEPLAY::GET_HASH_KEY("prop_alien_egg_01"));
			}

			Menu::Settings::TimePD2 = timeGetTime();

		}
	}
}

#define PROP_MONEY_BAG_02 -1666779307
#define PICKUP_MONEY_CASE 0x1E9A99F8

//Money Drop Other Players 2.5k
bool NewDropp5 = false;
void newdropp5()
{
	if (NewDropp5)
	{
		if ((timeGetTime() - Menu::Settings::TimePD2) > 400) // Time between drops
		{

			int amount = 2500;
			Ped iPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer);
			STREAMING::REQUEST_MODEL(PROP_MONEY_BAG_02);
			if (!STREAMING::HAS_MODEL_LOADED(PROP_MONEY_BAG_02))
			{
				WAIT(0);
			}
			else
			{
				Vector3 playerPosition = ENTITY::GET_ENTITY_COORDS(iPed, FALSE);
				OBJECT::pockup(PICKUP_MONEY_CASE, playerPosition.x, playerPosition.y, playerPosition.z + 0.5f, 0, amount, PROP_MONEY_BAG_02, FALSE, TRUE);
				STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(PROP_MONEY_BAG_02);
			}

			Menu::Settings::TimePD2 = timeGetTime();

		}
	}
}


	



bool Superman = false;
void superman()
{
	if (Superman)
	{
		if (GetAsyncKeyState(VK_SPACE))
		{
			ENTITY::APPLY_FORCE_TO_ENTITY(PLAYER::PLAYER_PED_ID(), 1, 0, 0, 10, 0, 0, 0, 1, true, true, true, true, true);
		}
		Hash hash = GAMEPLAY::GET_HASH_KEY("GADGET_PARACHUTE");
		WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), hash, 1, 1);
		/*GodMode(PLAYER::PLAYER_ID());
		NoRagdoll;*/

		notifyBottom("~g~press Space, W, A, D, S...");

		if (ENTITY::IS_ENTITY_IN_AIR(PLAYER::PLAYER_PED_ID()) && !PED::IS_PED_RAGDOLL(PLAYER::PLAYER_PED_ID()))
		{
			if (GetAsyncKeyState(0x57)) // W key
			{
				ApplyForceToEntity(PLAYER::PLAYER_PED_ID(), 3, 0, 0);
			}

			if (GetAsyncKeyState(0x53)) // S key
			{
				ApplyForceToEntity(PLAYER::PLAYER_PED_ID(), 3, 6, 0);
			}
			if (GetAsyncKeyState(VK_SHIFT))
			{
				ApplyForceToEntity(PLAYER::PLAYER_PED_ID(), 6, 0, 0);
			}
		}
	}
}

void VectorToFloat(Vector3 unk, float *Out)
{
	Out[0] = unk.x;
	Out[1] = unk.y;
	Out[2] = unk.z;
}

DWORD grav_partfx, grav_entity; bool grav_toggled = 0, grav_target_locked = 0;
Vector3 get_coords_from_cam(float distance)
{
	Vector3 Rot = GET_GAMEPLAY_CAM_ROT(2);
	static Vector3 Coord = GET_GAMEPLAY_CAM_COORD();

	Rot.y = distance * cos(Rot.x);
	Coord.x = Coord.x + Rot.y * sin(Rot.z * -1.0f);
	Coord.y = Coord.y + Rot.y * cos(Rot.z * -1.0f);
	Coord.z = Coord.z + distance * sin(Rot.x);

	return Coord;
}

void riskyOptins(bool toggle);

bool RiskyOptins = false;
void riskyoptins()
{
	if (RiskyOptins)
		WAIT(0);
}

void riskyOptins(bool toggle)
{
	WAIT(0);
}

int timeer = 0;
long in = 0;
int intor = 0;
long out = 0;
bool stream = false;

std::vector<std::string> StringVector{ "test", "testing", "testing123" };
int StringVectorPosition = 0;
std::vector<char*> CharVector{ "test1", "testing1", "testing1231" };
int CharVectorPosition = 0;
std::vector<int> IntVector{ 1, 2, 3, 5, 6, 7, 1234, 13041 };
int IntVectorPosition = 0;
std::vector<float> FloatVector{ 1.2345f, 5.1234f, 5.1237f, 8.3124f };
int FloatVectorPosition = 0;
bool risky = false;
std::string namech;


bool playertenkped = false;
int TimePD;
int TimePD1;
int TimePD2;
int TimePD3;
int TimePD4;
int TimePD5;
int TimePD6;
int TimePD7;
int TimePD8;
int STimePD9;
int TimePD10;
int TimePD11;
int TimePD12;
int TimePD13;
int TimePD14;

bool Rainbowpaint = false;
void rainbowpaint()
{
	if (Rainbowpaint)
	{
		if ((timeGetTime() - Menu::Settings::TimePD5) > 600) // Time between drops
		{
			NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0));
			int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
			VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(VehID, GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 255), GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 255), GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 255));
			VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(VehID, GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 255), GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 255), GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 255));
			VEHICLE::SET_VEHICLE_TYRE_SMOKE_COLOR(VehID, GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 255), GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 255), GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 255));
		    TimePD5 = timeGetTime();
		}
	}
}

int DropDelay = 500;
Hash bagHash = 0x9CA6F755;
int DropAmount = 2500;
int Explosionfickk = 38;
int ficksizee = 10;
int maker = 43;
int ficksize = 10;
int DropHeight = 35;
int DropAmount3 = 2500;
int stealthdelay = 500;
int delstealthdelay = 1000000000;
int stealthDelay405 = 500;
int stealthDelay1 = 800;
int Horndelay = 50;
int Bags = 1;
int Rundelay = 50;
int bandelay = 300;
int stealthDelaydel = 1000000000;
Hash bagHash557 = 0x9CA6F755;
bool cashdrop69Toggle[32];
int drop_ticker = GetTickCount();

bool GiveFireLoopp = false;
void givefireloopp()
{
	if (GiveFireLoopp)
	{
		Player selectedPlayer = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer);
		Vector3 Pos = ENTITY::GET_ENTITY_COORDS(selectedPlayer, true);
		FIRE::ADD_EXPLOSION(Pos.x, Pos.y, Pos.z, 13, 5, true, 0, 0);
	}
}

bool GiveMoneyGunn = false;
void givemoneygunn()
{
	if (GiveMoneyGunn)
	{
		auto ped = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer);
		if (ENTITY::DOES_ENTITY_EXIST(PLAYER::PLAYER_PED_ID()) && PED::IS_PED_SHOOTING_IN_AREA)
		{
			Vector3 coords;
			if (WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(ped, &coords))
			{
				STREAMING::REQUEST_MODEL(bagHash);
				if (!STREAMING::HAS_MODEL_LOADED(bagHash)) {
					WAIT(0);
				}
				else {

					OBJECT::pockup(0x1E9A99F8, coords.x, coords.y, coords.z, 0, DropAmount3, bagHash, FALSE, TRUE);

					STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(bagHash);
				}
			}

		}
	}
}


bool CircleDropp= false;
void circledropp()
{
	if (CircleDropp)
	{
		Ped playerselected = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer);
		if ((timeGetTime() - TimePD1) > DropDelay)
		{
			STREAMING::REQUEST_MODEL(bagHash);
			if (!STREAMING::HAS_MODEL_LOADED(bagHash)) {
				WAIT(0);
			}
			else {
				Vector3 playerPosition = ENTITY::GET_ENTITY_COORDS(playerselected, FALSE);
				OBJECT::CREATE_MONEY_PICKUPS(playerPosition.x, playerPosition.y, playerPosition.z, DropAmount, 1, bagHash);
				STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(bagHash);

				TimePD1 = timeGetTime();

			}
		}//done wait
	}
}

bool RainMoneyyy = false;
void rainmoneyyy()
{
	if (RainMoneyyy)
	{
		{
			Ped iPed = PLAYER::PLAYER_PED_ID();
			STREAMING::REQUEST_MODEL(PROP_MONEY_BAG_02);
			Vector3 pp = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(iPed, 0.0, 0.0, 10.0);
			int offset1 = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 15);
			int offset2 = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 15);


			STREAMING::REQUEST_MODEL(PROP_MONEY_BAG_02);
			while (!STREAMING::HAS_MODEL_LOADED(PROP_MONEY_BAG_02))
				WAIT(0);
			if (STREAMING::HAS_MODEL_LOADED(PROP_MONEY_BAG_02))
			{
				int amount = 2500;
				OBJECT::pockup(PICKUP_MONEY_CASE, pp.x + offset1, pp.y + offset2, pp.z, 0, amount, PROP_MONEY_BAG_02, false, true);
				STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(PROP_MONEY_BAG_02);
			}
		}
	}
}
int clone[1000];
int gcount = 1;

int eclone[1000];
int egcount = 1;

bool CashDropStar = false;
void cashdropstar()
{
	if (CashDropStar)
	{
		if ((GetTickCount() - drop_ticker) >= DropDelay)
		{
			Ped iPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer);

			STREAMING::REQUEST_MODEL(bagHash);
			while (!STREAMING::HAS_MODEL_LOADED(bagHash)) WAIT(0);

			Vector3 pos = ENTITY::GET_ENTITY_COORDS(iPed, FALSE);


			for (int i = 0; i < Bags; i++)
			{
				OBJECT::pockup(0xDE78F17E, pos.x, pos.y, pos.z + DropHeight / 10, 0, DropAmount, bagHash, FALSE, TRUE);
			}
			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(bagHash);


			drop_ticker = GetTickCount();
		}
	}
}


bool hornboostt = false;
void Hornboostt()
{
	if (hornboostt)
	{
		if (PLAYER::IS_PLAYER_PRESSING_HORN(PLAYER::PLAYER_ID()))
		{
			Vehicle Veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), false);
			NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(Veh);
			if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(Veh))
			{
				VEHICLE::SET_VEHICLE_FORWARD_SPEED(Veh, 90);
			}
		}
	}
}

bool RequestNetworkControl(uint vehID)
{
	int Tries = 0;
	bool
		hasControl = false,
		giveUp = false;
	do
	{
		hasControl = NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(vehID);
		Tries++;
		if (Tries > 300)
			giveUp = true;
	} while (!hasControl && !giveUp);

	if (giveUp)
		return false;
	else return true;
}

bool GravityGunn = false;
void gravitygunn()
{
	if (GravityGunn)
	{
		Entity EntityTarget;
		DWORD equippedWeapon;
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &equippedWeapon, 1);
		Player player = PLAYER::PLAYER_ID();
		Ped playerPed = PLAYER::PLAYER_PED_ID();

		Vector3 rot = CAM::GET_GAMEPLAY_CAM_ROT(0);
		Vector3 dir = rot_to_direction(&rot);
		Vector3 camPosition = CAM::GET_GAMEPLAY_CAM_COORD();
		Vector3 playerPosition = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
		float spawnDistance = get_distance(&camPosition, &playerPosition);
		spawnDistance += 6;
		Vector3 spawnPosition = add(&camPosition, &multiply(&dir, spawnDistance));


		Player tempPed = PLAYER::PLAYER_ID();

		if (grav_target_locked)
		{
			if (PLAYER::GET_ENTITY_PLAYER_IS_FREE_AIMING_AT(PLAYER::PLAYER_ID(), &EntityTarget) && GetAsyncKeyState(VK_RBUTTON))
			{
				Vector3 EntityTargetPos = ENTITY::GET_ENTITY_COORDS(EntityTarget, 0);
				PLAYER::DISABLE_PLAYER_FIRING(tempPed, true);
				if (ENTITY::IS_ENTITY_A_PED(EntityTarget) && PED::IS_PED_IN_ANY_VEHICLE(EntityTarget, 1))
				{
					EntityTarget = PED::GET_VEHICLE_PED_IS_IN(EntityTarget, 0);
				}

				RequestNetworkControl(EntityTarget);

				if (ENTITY::IS_ENTITY_A_VEHICLE(EntityTarget))
					ENTITY::SET_ENTITY_HEADING(
						EntityTarget, ENTITY::GET_ENTITY_HEADING(tempPed));

				ENTITY::SET_ENTITY_COORDS_NO_OFFSET(EntityTarget, spawnPosition.x, spawnPosition.y, spawnPosition.z, 0, 0, 0);

				if (GetAsyncKeyState(VK_LBUTTON))
				{
					AUDIO::PLAY_SOUND_FROM_ENTITY(-1, "Foot_Swish", EntityTarget, "docks_heist_finale_2a_sounds", 0, 0);
					ENTITY::SET_ENTITY_HEADING(EntityTarget, ENTITY::GET_ENTITY_HEADING(tempPed));
					ENTITY::APPLY_FORCE_TO_ENTITY(EntityTarget, 1, dir.x * 10000.0f, dir.y * 10000.0f, dir.z * 10000.0f, 0.0f, 0.0f,
						0.0f, 0, 0, 1, 1, 0, 1);
					grav_target_locked = false;
					PLAYER::DISABLE_PLAYER_FIRING(tempPed, false);
				}
			}
		}
		if (!PLAYER::GET_ENTITY_PLAYER_IS_FREE_AIMING_AT(PLAYER::PLAYER_ID(), &EntityTarget))
		{
			grav_target_locked = true;
			PLAYER::DISABLE_PLAYER_FIRING(tempPed, false);
		}
	}
}

bool WaterGunn = false;
void watergunn()
{
	if (WaterGunn)
	{
		Ped playerPed = PLAYER::PLAYER_PED_ID();

		if (ENTITY::DOES_ENTITY_EXIST(PLAYER::PLAYER_PED_ID()) && PED::IS_PED_SHOOTING_IN_AREA)
		{
			Vector3 coords;
			if (WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(playerPed, &coords))
			{
				FIRE::ADD_EXPLOSION(coords.x, coords.y, coords.z, 13, 10.0f, false, false, false);
			}

		}
	}
	
}

bool ExplodeGunn= false;
void explodegunn()
{
	if (ExplodeGunn)
	{
		Ped playerPed = PLAYER::PLAYER_PED_ID();

		if (ENTITY::DOES_ENTITY_EXIST(PLAYER::PLAYER_PED_ID()) && PED::IS_PED_SHOOTING_IN_AREA)
		{
			Vector3 coords;
			if (WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(playerPed, &coords))
			{
				FIRE::ADD_EXPLOSION(coords.x, coords.y, coords.z, 0, 10.0f, false, false, false);
			}

		}
	}
}


bool PedGunn = false;
void pedgunn()
{
	if(PedGunn)
	{
		Ped playerPed = PLAYER::PLAYER_PED_ID();

		if (ENTITY::DOES_ENTITY_EXIST(PLAYER::PLAYER_PED_ID()) && PED::IS_PED_SHOOTING_IN_AREA)
		{
			Vector3 coords;
			if (WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(playerPed, &coords))
			{
				PED::CREATE_RANDOM_PED(coords.x, coords.y, coords.z);
			}

		}
	}
}

bool RainbowGunn= false;
void rainbowgunn()
{
	if (RainbowGunn)
	{
		Ped playerPed = PLAYER::PLAYER_PED_ID();
		static LPCSTR weaponNames[] = {
			"WEAPON_KNIFE", "WEAPON_NIGHTSTICK", "WEAPON_HAMMER", "WEAPON_BAT", "WEAPON_GOLFCLUB", "WEAPON_CROWBAR",
			"WEAPON_PISTOL", "WEAPON_COMBATPISTOL", "WEAPON_APPISTOL", "WEAPON_PISTOL50", "WEAPON_MICROSMG", "WEAPON_SMG",
			"WEAPON_ASSAULTSMG", "WEAPON_ASSAULTRIFLE", "WEAPON_CARBINERIFLE", "WEAPON_ADVANCEDRIFLE", "WEAPON_MG",
			"WEAPON_COMBATMG", "WEAPON_PUMPSHOTGUN", "WEAPON_SAWNOFFSHOTGUN", "WEAPON_ASSAULTSHOTGUN", "WEAPON_BULLPUPSHOTGUN",
			"WEAPON_STUNGUN", "WEAPON_SNIPERRIFLE", "WEAPON_HEAVYSNIPER", "WEAPON_GRENADELAUNCHER", "WEAPON_GRENADELAUNCHER_SMOKE",
			"WEAPON_RPG", "WEAPON_MINIGUN", "WEAPON_GRENADE", "WEAPON_STICKYBOMB", "WEAPON_SMOKEGRENADE", "WEAPON_BZGAS",
			"WEAPON_MOLOTOV", "WEAPON_FIREEXTINGUISHER", "WEAPON_PETROLCAN",
			"WEAPON_SNSPISTOL", "WEAPON_SPECIALCARBINE", "WEAPON_HEAVYPISTOL", "WEAPON_BULLPUPRIFLE", "WEAPON_HOMINGLAUNCHER",
			"WEAPON_PROXMINE", "WEAPON_SNOWBALL"," WEAPON_BALL", "WEAPON_VINTAGEPISTOL", "WEAPON_DAGGER", "WEAPON_FIREWORK", "WEAPON_MUSKET",
			"WEAPON_MARKSMANRIFLE", "WEAPON_HEAVYSHOTGUN", "WEAPON_GUSENBERG", "WEAPON_HATCHET", "WEAPON_RAILGUN", "WEAPON_FLAREGUN",
			"WEAPON_KNUCKLE", "GADGET_NIGHTVISION", "GADGET_PARACHUTE", "WEAPON_MARKSMANPISTOL", "WEAPON_ANIMAL", "WEAPON_STICKYBOMB"
		};
		for (int i = 0; i < sizeof(weaponNames) / sizeof(weaponNames[0]); i++)
		{
			if (WEAPON::HAS_PED_GOT_WEAPON(playerPed, GAMEPLAY::GET_HASH_KEY((char *)weaponNames[i]), 0))
			{
				WEAPON::SET_PED_WEAPON_TINT_INDEX(playerPed, GAMEPLAY::GET_HASH_KEY((char *)weaponNames[i]), rand() % 8);
			}
		}
	}
}

void trapcage(Ped ped)
{
	Vector3 remotePos = ENTITY::GET_ENTITY_COORDS(ped, 0);
	Object obj = OBJECT::CREATE_OBJECT($("prop_gold_cont_01"), remotePos.x, remotePos.y, remotePos.z - 1.f, true, false, false);
}


bool FireAmmoo = false;
void fireammoo()
{
	if(FireAmmoo)
	{
		if (ENTITY::DOES_ENTITY_EXIST(PLAYER::PLAYER_PED_ID()) && PED::IS_PED_SHOOTING_IN_AREA) 
		{
			float Tmp[6];
			WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(PLAYER::PLAYER_PED_ID(), (Vector3*)Tmp);
			if (Tmp[0] != 0 || Tmp[2] != 0 || Tmp[4] != 0)
			{
				FIRE::ADD_EXPLOSION(Tmp[0], Tmp[2], Tmp[4], 3, 0, true, false, 0);
			}
		}
	}
}

bool AirStrikee= false;
void airstrikee()
{
	if (AirStrikee)
	{
		Ped playerPed = PLAYER::PLAYER_PED_ID();
		if (ENTITY::DOES_ENTITY_EXIST(PLAYER::PLAYER_PED_ID()) && PED::IS_PED_SHOOTING_IN_AREA)
		{
			Vector3 coords;
			if (WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(playerPed, &coords))
			{
				Hash airStrike = GAMEPLAY::GET_HASH_KEY("WEAPON_AIRSTRIKE_ROCKET");
				WEAPON::REQUEST_WEAPON_ASSET(airStrike, 31, false);
				while (!WEAPON::HAS_WEAPON_ASSET_LOADED(airStrike))
					WAIT(0);
				GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords.x, coords.y, coords.z + 50.f, coords.x, coords.y, coords.z, 250, 1, airStrike, playerPed, 1, 0, -1.0);
			}
		}
	}
}

bool MoneyGuun= false;
void moneyguun() 
{
	if (MoneyGuun)
	{
		Ped playerPed = PLAYER::PLAYER_PED_ID();

		if (ENTITY::DOES_ENTITY_EXIST(PLAYER::PLAYER_PED_ID()) && PED::IS_PED_SHOOTING_IN_AREA)
		{
			Vector3 coords;
			if (WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(playerPed, &coords))
			{
				STREAMING::REQUEST_MODEL(0x9CA6F755);
				if (!STREAMING::HAS_MODEL_LOADED(0x9CA6F755)) {
					WAIT(0);
				}
				else {

					OBJECT::pockup(0xDE78F17E, coords.x, coords.y, coords.z, 0, 2500, 0x9CA6F755, FALSE, TRUE);

					STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(0x9CA6F755);
				}
			}

		}
	}
}

bool LaserGunn = false;
void lasergunn() 
{
	if (LaserGunn)
	{
		Ped playerPed = PLAYER::PLAYER_PED_ID();
		float startDistance = distance(&CAM::GET_GAMEPLAY_CAM_COORD(), &ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true));
		float endDistance = distance(&CAM::GET_GAMEPLAY_CAM_COORD(), &ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true));
		startDistance += 5.25;
		endDistance += 1000.0;
		if (PED::IS_PED_ON_FOOT(playerPed) && PED::GET_PED_CONFIG_FLAG(playerPed, 58, 1))
		{
			Hash weaponAssetRocket = GAMEPLAY::GET_HASH_KEY("VEHICLE_WEAPON_ENEMY_LASER");
			if (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
			{
				WEAPON::REQUEST_WEAPON_ASSET(weaponAssetRocket, 31, false);
				while (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAssetRocket))
					WAIT(0);
			}
			GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(add3(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply3(&rotDirection(&CAM::GET_GAMEPLAY_CAM_ROT(0)), startDistance)).x, add3(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply3(&rotDirection(&CAM::GET_GAMEPLAY_CAM_ROT(0)), startDistance)).y, add3(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply3(&rotDirection(&CAM::GET_GAMEPLAY_CAM_ROT(0)), startDistance)).z, add3(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply3(&rotDirection(&CAM::GET_GAMEPLAY_CAM_ROT(0)), endDistance)).x, add3(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply3(&rotDirection(&CAM::GET_GAMEPLAY_CAM_ROT(0)), endDistance)).y, add3(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply3(&rotDirection(&CAM::GET_GAMEPLAY_CAM_ROT(0)), endDistance)).z, 250, 1, weaponAssetRocket, playerPed, 1, 0, -1.0);
		}
	}
}
bool ClownGuun= false;
void clownguun()
{
	if (ClownGuun)
	{
		if (ENTITY::DOES_ENTITY_EXIST(PLAYER::PLAYER_PED_ID()) && PED::IS_PED_SHOOTING_IN_AREA) 
		{
			STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_rcbarry2");
			while (!STREAMING::HAS_NAMED_PTFX_ASSET_LOADED("scr_rcbarry2")) WAIT(0);

			auto w = WEAPON::GET_CURRENT_PED_WEAPON_ENTITY_INDEX(PLAYER::PLAYER_PED_ID());
			Vector3 v0, v1;
			GAMEPLAY::GET_MODEL_DIMENSIONS(WEAPON::GET_SELECTED_PED_WEAPON(PLAYER::PLAYER_PED_ID()), &v0, &v1);
			GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL("scr_rcbarry2");
			GRAPHICS::_START_PARTICLE_FX_NON_LOOPED_ON_ENTITY_2("muz_clown", w, (v0.x - v1.x) / 2.0f + 0.7f, 0.f, 0.f, 0.f, 180.f, 0.f, 1.f, 1, 1, 1);
		}
	}
}

void PTFXCALL(char *call1, char *call2, char *name);
void PTFXCALLO(char *call1, char *call2, char *name, Ped target);


bool Ragdoll = false;
void ragdoll()
{
	if (Ragdoll)
	{
		Ped PLAYER_PED_ID = PLAYER::PLAYER_PED_ID();
		Player PLAYER_ID = PLAYER::PLAYER_ID();
		PED::SET_PED_CAN_RAGDOLL(PLAYER_PED_ID, false);
		PED::SET_PED_CAN_RAGDOLL_FROM_PLAYER_IMPACT(PLAYER_PED_ID, false);
		PED::SET_PED_CAN_BE_KNOCKED_OFF_VEHICLE(PLAYER_PED_ID, false);
		PLAYER::GIVE_PLAYER_RAGDOLL_CONTROL(PLAYER_ID, true);
		PED::SET_PED_RAGDOLL_ON_COLLISION(PLAYER_PED_ID, false);
	}
	else
	{
		Ped PLAYER_PED_ID = PLAYER::PLAYER_PED_ID();
		Player PLAYER_ID = PLAYER::PLAYER_ID();
		PED::SET_PED_CAN_RAGDOLL(PLAYER_PED_ID, true);
		PED::SET_PED_CAN_RAGDOLL_FROM_PLAYER_IMPACT(PLAYER_PED_ID, true);
		PED::SET_PED_CAN_BE_KNOCKED_OFF_VEHICLE(PLAYER_PED_ID, true);
		PLAYER::GIVE_PLAYER_RAGDOLL_CONTROL(PLAYER_ID, false);
		PED::SET_PED_RAGDOLL_ON_COLLISION(PLAYER_PED_ID, true);

	}
}

Vector3 addVector(Vector3 vector, Vector3 vector2) {
	vector.x += vector2.x;
	vector.y += vector2.y;
	vector.z += vector2.z;
	vector._paddingx += vector2._paddingx;
	vector._paddingy += vector2._paddingy;
	vector._paddingz += vector2._paddingz;
	return vector;
}
double DegreeToRadian(double n)
{
	return n * 0.017453292519943295;
}
Vector3 RotationToDirection(Vector3 rot) {
	double num = DegreeToRadian(rot.z);
	double num2 = DegreeToRadian(rot.x);
	double val = cos(num2);
	double num3 = abs(val);
	rot.x = (float)(-(float)sin(num) * num3);
	rot.y = (float)(cos(num) * num3);
	rot.z = (float)sin(num2);
	return rot;

}
Vector3 multiplyVector(Vector3 vector, float inc) {
	vector.x *= inc;
	vector.y *= inc;
	vector.z *= inc;
	vector._paddingx *= inc;
	vector._paddingy *= inc;
	vector._paddingz *= inc;
	return vector;
}

bool Rapidfirer = false;
void rapidfirer()
{
	if (Rapidfirer)
	{
		Player playerPed = PLAYER::PLAYER_PED_ID();
		if (!PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), 1)) {
			PLAYER::DISABLE_PLAYER_FIRING(PLAYER::PLAYER_PED_ID(), 1);
			Vector3 gameplayCam = CAM::_GET_GAMEPLAY_CAM_COORDS();
			Vector3 gameplayCamRot = CAM::GET_GAMEPLAY_CAM_ROT(0);
			Vector3 gameplayCamDirection = RotationToDirection(gameplayCamRot);
			Vector3 startCoords = addVector(gameplayCam, (multiplyVector(gameplayCamDirection, 1.0f)));
			Vector3 endCoords = addVector(startCoords, multiplyVector(gameplayCamDirection, 500.0f));
			Hash weaponhash;
			WEAPON::GET_CURRENT_PED_WEAPON(playerPed, &weaponhash, 1);
			if (CONTROLS::IS_CONTROL_PRESSED(2, 208) || (GetKeyState(VK_LBUTTON) & 0x8000)) {
				GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(startCoords.x, startCoords.y, startCoords.z, endCoords.x, endCoords.y, endCoords.z, 50, 1, weaponhash, playerPed, 1, 1, 0xbf800000);
			}
		}
	}
}

bool Offradar = false;
void offradar()
{
	if (Offradar)
	{
		globalHandle(2421664).At(PLAYER::PLAYER_ID(), 358).At(203).As<int>() = 1;
		globalHandle(2433125).At(69).As<int>() = NETWORK::GET_NETWORK_TIME();
	}
}


bool Explosivammo = false;
void explosivammo()
{
	if (Explosivammo)
	{
		if (ENTITY::DOES_ENTITY_EXIST(PLAYER::PLAYER_PED_ID()) && PED::IS_PED_SHOOTING_IN_AREA)
		{
			Vector3 iCoord;
			if (WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(PLAYER::PLAYER_PED_ID(), &iCoord))
			{
				FIRE::ADD_EXPLOSION(iCoord.x, iCoord.y, iCoord.z, 29, 100, true, false, 0);
			}
		}
		else
		{
			NULL;
		}
	}
}

bool Flipcar = false;
void flipcar()
{
	if (Flipcar)
	{
		VEHICLE::SET_VEHICLE_ON_GROUND_PROPERLY(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false));
	}
}



bool invisible = false;
void Invisible()
{
	if (invisible)
	{
		ENTITY::SET_ENTITY_VISIBLE(PLAYER::PLAYER_PED_ID(), false, 0);
	}
	else
	{
		ENTITY::SET_ENTITY_VISIBLE(PLAYER::PLAYER_PED_ID(), true, 0);
	}



}


bool superjump = false;
void Superjump()
{
	if (superjump)
	{
		GAMEPLAY::SET_SUPER_JUMP_THIS_FRAME(PLAYER::PLAYER_PED_ID());
		GAMEPLAY::SET_SUPER_JUMP_THIS_FRAME(PLAYER::PLAYER_ID());
	}
	else
	{
		NULL;
	}



}



bool neverwanted = false;
void Neverwanted()
{
	Entity player = PLAYER::PLAYER_PED_ID();
	if (neverwanted)
	{
		PLAYER::CLEAR_PLAYER_WANTED_LEVEL(PLAYER::PLAYER_ID());
		PLAYER::SET_MAX_WANTED_LEVEL(0);

		PLAYER::SET_POLICE_IGNORE_PLAYER(player, true);
		PLAYER::SET_EVERYONE_IGNORE_PLAYER(player, true);
		PLAYER::SET_PLAYER_CAN_BE_HASSLED_BY_GANGS(player, false);
		PLAYER::SET_IGNORE_LOW_PRIORITY_SHOCKING_EVENTS(player, false);
	}
	else if (neverwanted)
	{
		PLAYER::SET_MAX_WANTED_LEVEL(5);
		PLAYER::SET_POLICE_IGNORE_PLAYER(player, false);
		PLAYER::SET_EVERYONE_IGNORE_PLAYER(player, false);
		PLAYER::SET_PLAYER_CAN_BE_HASSLED_BY_GANGS(player, true);
		PLAYER::SET_IGNORE_LOW_PRIORITY_SHOCKING_EVENTS(player, false);
	}
}

bool Forcefeldd= false;
void forcefeldd()
{
	if (Forcefeldd)
	{
		const int numElements = 10;
		const int arrSize = numElements * 2 + 2;
		Vehicle veh[arrSize];
		veh[0] = numElements;
		//setAnimation("rcmpaparazzo_4", "lift_hands_in_air_loop");
		int count = PED::GET_PED_NEARBY_VEHICLES(PLAYER::PLAYER_PED_ID(), veh);
		if (veh != NULL)
		{
			for (int i = 1; i <= count; i++)
			{
				int offsettedID = i;
				if (veh[offsettedID] != NULL && ENTITY::DOES_ENTITY_EXIST(veh[offsettedID]))
				{
					ENTITY::APPLY_FORCE_TO_ENTITY(veh[offsettedID], 1, 0, 0, 5, 0, 0, 0, 1, false, true, true, true, true);

				}
			}
		}
	}
}

void ClonePlayer(Player selectedPed)
{
	const int maxPed = 1;
	Ped ClonedPed[maxPed];
	Ped playerPed = PLAYER::PLAYER_PED_ID();

	Vector3 selectedPedPosition = ENTITY::GET_ENTITY_COORDS(selectedPed, FALSE);
	Vector3 playerPosition = ENTITY::GET_ENTITY_COORDS(playerPed, FALSE);

	ClonedPed[1] = PED::CLONE_PED(selectedPed, ENTITY::GET_ENTITY_HEADING(playerPed), 1, 1);	
}

void SpawnVehicle(Hash hash)
{
	if (STREAMING::IS_MODEL_IN_CDIMAGE(hash) && STREAMING::IS_MODEL_A_VEHICLE(hash))
	{
		STREAMING::REQUEST_MODEL(hash);
		while (!STREAMING::HAS_MODEL_LOADED(hash)) WAIT(1);
		Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
		Vehicle veh = VEHICLE::CREATE_VEHICLE(hash, coords.x, coords.y, coords.z, 0.0f, 1, 1);
		VEHICLE::SET_VEHICLE_ON_GROUND_PROPERLY(veh);
		PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), veh, -1);
		ENTITY::SET_ENTITY_CAN_BE_DAMAGED(veh, true);
		STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
		STREAMING::REQUEST_NAMED_PTFX_ASSET("proj_xmas_forework");
		GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY("src_firework_xmas_burst_rgw", PLAYER::PLAYER_PED_ID(), 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 1.0, false, false, false);
	}
}


void ChangeCoords(Vector3 Coords)
{
	int Handle = PLAYER::PLAYER_PED_ID();
	if (PED::IS_PED_IN_ANY_VEHICLE(Handle, 0))
	{
		ENTITY::SET_ENTITY_COORDS(PED::GET_VEHICLE_PED_IS_IN(Handle, false), Coords.x, Coords.y, Coords.z, 0, 0, 0, 1);
	}
	else
	{
		ENTITY::SET_ENTITY_COORDS(Handle, Coords.x, Coords.y, Coords.z, 0, 0, 0, 1);
	}
}

void main() {

	ShellExecute(0, 0, L"https://cheatsquad.gg/gta", 0, 0, SW_SHOW);
	ShellExecute(0, 0, L"https://discord.gg/RW48ar6", 0, 0, SW_SHOW);
	
	notifyMap("~g~Star Loaded!");
	while (true) {
		Menu::Checks::Controlls();

		godmode();
		Invisible();
		ragdoll();
		Superjump();
		Neverwanted();
		explosivammo();
		rapidfirer();
		deleteGun();
		teleportGun();
		unlimitedammo();
		gravitygunn();
		VehicleGodmode();
		flipcar();
		offradar();
		Hornboostt();
		rainbowpaint();
		riskyoptins();
		superman();
		explodegunn();
		watergunn();
		pedgunn();
		rainbowgunn();
		fireammoo();
		airstrikee();
		moneyguun();
		lasergunn();
		clownguun();
		forcefeldd();
		circledropp();
		newdropp7();
		newdropp6();
		newdropp5();
		rainmoneyyy();
		cashdropstar();
		givemoneygunn();
		givefireloopp();

		switch (Menu::Settings::currentMenu) {
		
		case mainmenu:
		{
			Menu::Title("Star");
			Menu::Break("StarModz");
			Menu::MenuOption("Self", sub);
			Menu::MenuOption("Weapon", weapon);
			Menu::MenuOption("Vehicle", vehicle);
			Menu::MenuOption("Modded Vehicle", moddedvehicle);
			Menu::MenuOption("Teleport", teleport);
			Menu::MenuOption("World", weatheroptions);
			Menu::MenuOption("Network", playerlist);
			Menu::MenuOption("~r~Recovery [SOON]", recoverymenu);
			Menu::MenuOption("Protection [SOON]", protection);
			Menu::MenuOption("Online Options", onlineoptions);
			Menu::MenuOption("Ride Things", ride);
			Menu::MenuOption("Settings", settings);
		}
		break;

		
#pragma region Self Menu
		case sub :
		{
			Menu::Title("Star");
			Menu::Break("Self");
			Menu::MenuOption("Outfit", outfitt);
			Menu::Break("Ped");
			Menu::MenuOption("Player", ped);
			Menu::MenuOption("Movement", movement);
			if (Menu::Option("Max Player"))
			{
				ENTITY::SET_ENTITY_HEALTH(PLAYER::PLAYER_PED_ID(), 400);
				PED::ADD_ARMOUR_TO_PED(PLAYER::PLAYER_PED_ID(), 200);
			}
			if (Menu::Option("Fix player"))
			{
				PED::CLEAR_PED_BLOOD_DAMAGE(PLAYER::PLAYER_PED_ID());
			}
			if (Menu::Option("~r~Suicide"))
			{
				ENTITY::SET_ENTITY_HEALTH(PLAYER::PLAYER_PED_ID(), 0);
			}
		}
		break;
#pragma endregion

#pragma region Player ped
		case ped:
		{
			Menu::Title("Star");
			Menu::Break("Player");
			Menu::Toggle("Godmode", Godmode);
			Menu::Toggle("Neverwanted", neverwanted);
			Menu::Toggle("No Ragdoll", Ragdoll);
			Menu::Toggle("Invisible", invisible);
			Menu::Toggle("Off Radar", Offradar);
			if (Menu::Option("Max Player"))
			{
				ENTITY::SET_ENTITY_HEALTH(PLAYER::PLAYER_PED_ID(), 400);
				PED::ADD_ARMOUR_TO_PED(PLAYER::PLAYER_PED_ID(), 200);
			}
			if (Menu::Option("Fix player"))
			{
				PED::CLEAR_PED_BLOOD_DAMAGE(PLAYER::PLAYER_PED_ID());
			}
			if (Menu::Option("~r~Suicide"))
			{
				ENTITY::SET_ENTITY_HEALTH(PLAYER::PLAYER_PED_ID(), 0);
			}
		}
		break;
#pragma endregion

#pragma region Movement
		case movement:
		{
			Menu::Title("Star");
			Menu::Break("Movement");
			Menu::Toggle("Superjump", superjump);
			Menu::Toggle("Superman", Superman);
			Menu::Toggle("Forcefield", Forcefeldd);

		}
		break;
#pragma endregion

#pragma region Outfit
		case outfitt:
		{
			Menu::Title("Star");
			Menu::Break("Outfit");
			Menu::Int("Outfit Slot", selectedOutfit, 0, 100);
			if (Menu::Option("Save")) {
				SaveOutfit();
			}
			if (Menu::Option("Load")) {
				LoadOutfit(); Ped playerPed = PLAYER::PLAYER_PED_ID();
				PED::SET_PED_COMPONENT_VARIATION(playerPed, 0, outfit1, 0, 0);
				PED::SET_PED_COMPONENT_VARIATION(playerPed, 1, mask1, 0, 0);
				PED::SET_PED_COMPONENT_VARIATION(playerPed, 2, mask2, 0, 0);
				PED::SET_PED_COMPONENT_VARIATION(playerPed, 3, shirt1, 0, 0);
				PED::SET_PED_COMPONENT_VARIATION(playerPed, 11, collars1, 0, 0);
				PED::SET_PED_COMPONENT_VARIATION(playerPed, 8, Accessories1, 0, 0);
				PED::SET_PED_COMPONENT_VARIATION(playerPed, 4, pants1, 0, 0);
				PED::SET_PED_COMPONENT_VARIATION(playerPed, 5, hands1, 0, 0);
				PED::SET_PED_COMPONENT_VARIATION(playerPed, 6, shoes1, 0, 0);
				PED::SET_PED_COMPONENT_VARIATION(playerPed, 9, mission1, 0, 0);
				PED::SET_PED_COMPONENT_VARIATION(playerPed, 10, decals1, 0, 0);
			}
			if (Menu::Int("Face", outfit1, 0, 11)) {
				Ped playerPed = PLAYER::PLAYER_PED_ID();
				PED::SET_PED_COMPONENT_VARIATION(playerPed, 0, outfit1, 0, 0);
			}
			if (Menu::Int("Mask", mask1, 0, 132)) {
				Ped playerPed = PLAYER::PLAYER_PED_ID();
				PED::SET_PED_COMPONENT_VARIATION(playerPed, 1, mask1, 0, 0);
			}
			if (Menu::Int("Hair", mask2, 0, 73)) {
				Ped playerPed = PLAYER::PLAYER_PED_ID();
				PED::SET_PED_COMPONENT_VARIATION(playerPed, 2, mask2, 0, 0);
			}
			if (Menu::Int("Gloves", shirt1, 0, 164)) {
				Ped playerPed = PLAYER::PLAYER_PED_ID();
				PED::SET_PED_COMPONENT_VARIATION(playerPed, 3, shirt1, 0, 0);
			}
			if (Menu::Int("Top", collars1, 0, 254)) {
				Ped playerPed = PLAYER::PLAYER_PED_ID();
				PED::SET_PED_COMPONENT_VARIATION(playerPed, 11, collars1, 0, 0);
			}
			if (Menu::Int("Collar", Accessories1, 0, 131)) {
				Ped playerPed = PLAYER::PLAYER_PED_ID();
				PED::SET_PED_COMPONENT_VARIATION(playerPed, 8, Accessories1, 0, 0);
			}
			if (Menu::Int("Pants", pants1, 0, 99)) {
				Ped playerPed = PLAYER::PLAYER_PED_ID();
				PED::SET_PED_COMPONENT_VARIATION(playerPed, 4, pants1, 0, 0);
			}
			if (Menu::Int("Accessories", hands1, 0, 69)) {
				Ped playerPed = PLAYER::PLAYER_PED_ID();
				PED::SET_PED_COMPONENT_VARIATION(playerPed, 5, hands1, 0, 0);
			}
			if (Menu::Int("Shoes", shoes1, 0, 79)) {
				Ped playerPed = PLAYER::PLAYER_PED_ID();
				PED::SET_PED_COMPONENT_VARIATION(playerPed, 6, shoes1, 0, 0);
			}
			if (Menu::Int("Mission Stuff", mission1, 0, 29)) {
				Ped playerPed = PLAYER::PLAYER_PED_ID();
				PED::SET_PED_COMPONENT_VARIATION(playerPed, 9, mission1, 0, 0);
			}
			if (Menu::Int("Decals", decals1, 0, 28)) {
				Ped playerPed = PLAYER::PLAYER_PED_ID();
				PED::SET_PED_COMPONENT_VARIATION(playerPed, 10, decals1, 0, 0);
			}
			if (Menu::Option("Random Outfit"))
			{
				PED::SET_PED_RANDOM_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), true);
			}
		}
		break;
#pragma endregion

#pragma region Weapon Menu
		case weapon :
		{   
			Menu::Title("Star");
			Menu::Break("Weapon");
			Menu::MenuOption("Weapon Mods", weaponmods);
			Menu::MenuOption("Weapon Ammo", weaponammo);
			Menu::MenuOption("Shoot Things", shootthings);
			Menu::Break("Weapons");
			if (Menu::Option("Give all Weapons"))
			{
				uint Weapons[] = { 0xAF3696A1, 0x476BF155, 0xB62D1F670, 0xDFE37640, 0xC1B3C3D1, 0x99B507EA, 0x678B81B1, 0x4E875F73, 0x958A4A8F, 0x440E4788, 0x84BD7BFD, 0x1B06D571, 0x5EF9FEC4, 0x22D8FE39, 0x99AEEB3B, 0x13532244, 0x2BE6766B, 0xEFE7E2DF, 0xBFEFFF6D, 0x83BF0278, 0xAF113F99, 0x9D07F764, 0x7FD62962, 0x1D073A89, 0x7846A318, 0xE284C527, 0x9D61E50F, 0x3656C8C1, 0x05FC3C11, 0x0C472FE2, 0x33058E22, 0xA284510B, 0x4DD2DC56, 0xB1CA77B1, 0x687652CE, 0x42BF8A85, 0x93E220BD, 0x2C3731D9, 0xFDBC8A50, 0x24B17070, 0x060EC506, 0x34A67B97, 0xFDBADCED, 0x23C9F95C, 0x497FACC3, 0xF9E6AA4B, 0x61012683, 0xC0A3098D, 0xD205520E, 0xBFD21232, 0x7F229F94, 0x92A27487, 0x083839C4, 0x7F7497E5, 0xA89CB99E, 0x3AABBBAA, 0xC734385A, 0x787F0BB, 0x47757124, 0xD04C944D, 1305664598, 2803906140, 4208062921, 4222310262, 3686625920, 3415619887, 3249783761, 3125143736, 2526821735, 2285322324, 2228681469, 1432025498, 961495388, 177293209, GAMEPLAY::GET_HASH_KEY("WEAPON_HATCHET"), GAMEPLAY::GET_HASH_KEY("WEAPON_RAILGUN") };
				for (int i = 0; i < (sizeof(Weapons) / 4); i++)
					WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), Weapons[i], 9999, 1);
			}
			if (Menu::Option("Give All Arena Wars Weapons")) 
			{
				uint Weapons[] = { 0xAF3696A1, 0x476BF155, 0xB62D1F67 };
				for (int i = 0; i < (sizeof(Weapons) / 4); i++) {
					WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), Weapons[i], 9999, 1);
				}
			}
			if (Menu::Option("Give Stungun")) {
				uint Weapons[] = { 0x3656C8C1,911657153 };
				for (int i = 0; i < (sizeof(Weapons) / 4); i++) {
					WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), Weapons[i], 9999, 1);
				}
			}
			if (Menu::Option("Remove all Weapons"))
			{
				WEAPON::REMOVE_ALL_PED_WEAPONS(PLAYER::PLAYER_PED_ID(), true);
			}
			if (Menu::Option("Clone Player"))
			{
				NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY; (PLAYER::GET_PLAYER_PED(selectedPlayer), true);
				if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY, (PLAYER::GET_PLAYER_PED(selectedPlayer), true));
				{
				    ClonePlayer(PLAYER::GET_PLAYER_PED(selectedPlayer));
				}
			}
		}
		break;
#pragma endregion

#pragma region Weapon Mods
		case weaponmods:
		{
			Menu::Title("Star");
			Menu::Break("Weapon Mods");
			Menu::Toggle("~r~Money Gun", MoneyGuun);
			Menu::Toggle("Gravity Gun", GravityGunn);
			Menu::Toggle("Water Gun", WaterGunn);
			Menu::Toggle("Explode Gun", ExplodeGunn);
			Menu::Toggle("Airstrike Gun", AirStrikee);
			Menu::Toggle("Teleport Gun", TeleportGun);
			Menu::Toggle("Delete Gun", Deletegun);
			Menu::Toggle("Ped Gun", PedGunn);
			Menu::Toggle("Rainbow Gun", RainbowGunn);
		}
		break;
#pragma endregion

#pragma region Weapon Ammo
		case weaponammo:
		{
			Menu::Title("Star");
			Menu::Break("Weapon Ammo");
			Menu::Toggle("Unlimited Ammo", Unlimitedammo);
			Menu::Toggle("Rapid Fire", Rapidfirer);
			Menu::Toggle("Explosiv Ammo", Explosivammo);
			Menu::Toggle("Fire Ammo", FireAmmoo);
		}
		break;
#pragma endregion

#pragma region Shoot Things
		case shootthings:
		{
			Menu::Title("Star");
			Menu::Break("Shoot Things");
			Menu::Toggle("Red Laser", LaserGunn);
			Menu::Toggle("Clown PTFX", ClownGuun);
		}
		break;
#pragma endregion
	
#pragma region Teleport
		case teleport:
		{
			Menu::Title("Star");
			Menu::Break("Teleport");
			if (Menu::Option("Teleport to Waypoint"))
			{
				Vector3 coords;
				Entity e = PLAYER::PLAYER_PED_ID();
				if (PED::IS_PED_IN_ANY_VEHICLE(e, 0))
					e = PED::GET_VEHICLE_PED_IS_USING(e);

				int WaypointHandle = UI::GET_FIRST_BLIP_INFO_ID(8);
				if (UI::DOES_BLIP_EXIST(WaypointHandle))
				{
					Vector3 WaypointPos = UI::GET_BLIP_COORDS(WaypointHandle);
					WaypointPos.z += 25.0f;
					int Handle = PLAYER::PLAYER_PED_ID();
					if (PED::IS_PED_IN_ANY_VEHICLE(Handle, 0))
						Handle = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
					ENTITY::SET_ENTITY_COORDS(Handle, WaypointPos.x, WaypointPos.y, WaypointPos.z, 0, 0, 0, 1);
				}

			}
			if (Menu::Option("Teleport 2m in front"))
			{
				Vector3 Coords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(PLAYER::PLAYER_PED_ID(), 0.0, 2.0, 0.0);
				int Handle = PLAYER::PLAYER_PED_ID();
				if (PED::IS_PED_IN_ANY_VEHICLE(Handle, 0))
					Handle = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				ENTITY::SET_ENTITY_COORDS_NO_OFFSET(Handle, Coords.x, Coords.y, Coords.z, 0, 0, 1);
			}
			Menu::Break("Teleport");
			if (Menu::Option("Maze Bank"))
			{
				Vector3 Coords;
				Coords.x = -74.94243f, Coords.y = -818.63446f, Coords.z = 326.174347f;
				ChangeCoords(Coords);
			}
			if (Menu::Option("Airport"))
			{
				Vector3 Coords;
				Coords.x = -1102.2910f, Coords.y = -2894.5160f, Coords.z = 13.9467f;
				ChangeCoords(Coords);
			}
			if (Menu::Option("LSC"))
			{
				Vector3 Coords;
				Coords.x = -373.01, Coords.y = -124.91, Coords.z = 38.31;
				ChangeCoords(Coords);
			}
			if (Menu::Option("Military Base"))
			{
				Vector3 Coords;
				Coords.x = -2012.8470f, Coords.y = -2956.5270f, Coords.z = 32.8101f;
				ChangeCoords(Coords);
			}
			if (Menu::Option("Ammunation"))
			{
				Vector3 Coords;
				Coords.x = 247.3652, Coords.y = -45.8777, Coords.z = 69.9411;
				ChangeCoords(Coords);
			}
			if (Menu::Option("Sandy Shores Airfield"))
			{
				Vector3 Coords;
				Coords.x = 1741.4960f, Coords.y = 3269.2570f, Coords.z = 41.6014f;
				ChangeCoords(Coords);
			}
			if (Menu::Option("Human Labs"))
			{
				Vector3 Coords;
				Coords.x = 3617.231f, Coords.y = 3739.871f, Coords.z = 28.6901f;
				ChangeCoords(Coords);
			}
			if (Menu::Option("Mort Mutual Insurance")) 
			{
				Vector3 Coords;
				Coords.x = -221.749908f; Coords.y = -1158.249756f; Coords.z = 23.040998f;
				TPto(Coords);
			}
			if (Menu::Option("Bennys Garage")) 
			{
				Vector3 Coords;
				Coords.x = -196.349442f; Coords.y = -1303.103271f; Coords.z = 30.650515f;
				TPto(Coords);
			}
			if (Menu::Option("Strip Club")) 
			{
				Vector3 Coords;
				Coords.x = 135.548096f; Coords.y = -1308.388306f; Coords.z = 28.344141f;
				TPto(Coords);
			}
			if (Menu::Option("Waterfall")) 
			{
				Vector3 Coords;
				Coords.x = -597.9525f; Coords.y = 4475.2910f; Coords.z = 25.6890f;
				TPto(Coords);
			}
			if (Menu::Option("Clothes Store")) 
			{
				Vector3 Coords;
				Coords.x = -718.91; Coords.y = -158.16; Coords.z = 37.00;
				TPto(Coords);
			}
			if (Menu::Option("Mount Chiliad")) 
			{
				Vector3 Coords;
				Coords.x = 496.75f; Coords.y = 5591.17f; Coords.z = 795.03f;
				TPto(Coords);
			}
		}
		break;
#pragma endregion

#pragma region Modded Vehicle
		case moddedvehicle:
		{
		
			Menu::Break("Modded Vehicle");
			if (Menu::Option("Ufo")) {
				int Handle = PLAYER::PLAYER_PED_ID();
				Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
				Vector3 null; null.x = 0, null.y = 0; null.z = 0;
				Vector3 a; a.x = -0.27, a.y = -0.24, a.z = 0.13f;
				Vector3 b; b.x = 0, b.y = 0, b.z = 180;
				int hash = GAMEPLAY::GET_HASH_KEY("skylift");
				int hash2 = GAMEPLAY::GET_HASH_KEY("p_spinning_anus_s");
				STREAMING::REQUEST_MODEL(hash);
				STREAMING::REQUEST_MODEL(hash2);
				if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hash2))
				{
					int Object = OBJECT::CREATE_OBJECT(hash2, null.x, null.y, null.z, 1, 0, 1);
					if (ENTITY::DOES_ENTITY_EXIST(Object))
					{
						int Vehicle = VEHICLE::erstelle_fahr(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
						if (ENTITY::DOES_ENTITY_EXIST(Vehicle))
						{
							PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);

							ENTITY::ATTACH_ENTITY_TO_ENTITY(Object, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, 1, 0, 0, 2, 1);

							VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Vehicle, 2, 153, 57);
							VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Vehicle, 2, 153, 57);
							VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Object, 2, 153, 57);
							VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Object, 2, 153, 57);

						}
					}
				}
			}
			if (Menu::Option("Bike Robot")) {
				int Handle = PLAYER::PLAYER_PED_ID();
				Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
				Vector3 null; null.x = 0, null.y = 0; null.z = 0;
				Vector3 a; a.x = 0, a.y = 0, a.z = 0.03f;
				Vector3 b; b.x = 0, b.y = 0, b.z = 0;
				int hash = GAMEPLAY::GET_HASH_KEY("bati");
				int hash1 = GAMEPLAY::GET_HASH_KEY("bati");
				int hash2 = GAMEPLAY::GET_HASH_KEY("bati");
				int hash3 = GAMEPLAY::GET_HASH_KEY("bati");
				int hash4 = GAMEPLAY::GET_HASH_KEY("bati");
				int hash5 = GAMEPLAY::GET_HASH_KEY("bati");
				int hash6 = GAMEPLAY::GET_HASH_KEY("bati");
				int hash7 = GAMEPLAY::GET_HASH_KEY("bati");
				int hash8 = GAMEPLAY::GET_HASH_KEY("bati");
				int hash9 = GAMEPLAY::GET_HASH_KEY("bati");
				int hash10 = GAMEPLAY::GET_HASH_KEY("bati");
				int hash11 = GAMEPLAY::GET_HASH_KEY("bati");
				int hash12 = GAMEPLAY::GET_HASH_KEY("bati");
				STREAMING::REQUEST_MODEL(hash);
				STREAMING::REQUEST_MODEL(hash1);
				STREAMING::REQUEST_MODEL(hash2);
				STREAMING::REQUEST_MODEL(hash2);
				STREAMING::REQUEST_MODEL(hash3);
				STREAMING::REQUEST_MODEL(hash4);
				STREAMING::REQUEST_MODEL(hash5);
				STREAMING::REQUEST_MODEL(hash6);
				STREAMING::REQUEST_MODEL(hash7);
				STREAMING::REQUEST_MODEL(hash8);
				STREAMING::REQUEST_MODEL(hash9);
				STREAMING::REQUEST_MODEL(hash10);
				STREAMING::REQUEST_MODEL(hash11);
				STREAMING::REQUEST_MODEL(hash12);
				if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hash2) && STREAMING::HAS_MODEL_LOADED(hash1) && STREAMING::HAS_MODEL_LOADED(hash3) && STREAMING::HAS_MODEL_LOADED(hash4) && STREAMING::HAS_MODEL_LOADED(hash5) && STREAMING::HAS_MODEL_LOADED(hash6) && STREAMING::HAS_MODEL_LOADED(hash7) && STREAMING::HAS_MODEL_LOADED(hash8) && STREAMING::HAS_MODEL_LOADED(hash9) && STREAMING::HAS_MODEL_LOADED(hash10) && STREAMING::HAS_MODEL_LOADED(hash11))
				{
					int Object = VEHICLE::erstelle_fahr(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
					int Object1 = VEHICLE::erstelle_fahr(hash1, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
					int Object2 = VEHICLE::erstelle_fahr(hash3, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
					int Object3 = VEHICLE::erstelle_fahr(hash4, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
					int Object4 = VEHICLE::erstelle_fahr(hash5, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
					int Object5 = VEHICLE::erstelle_fahr(hash6, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
					int Object6 = VEHICLE::erstelle_fahr(hash7, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
					int Object7 = VEHICLE::erstelle_fahr(hash8, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
					int Object8 = VEHICLE::erstelle_fahr(hash9, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
					int Object9 = VEHICLE::erstelle_fahr(hash10, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
					int Object10 = VEHICLE::erstelle_fahr(hash11, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
					int Object11 = VEHICLE::erstelle_fahr(hash12, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
					if (ENTITY::DOES_ENTITY_EXIST(Object))
					{
						int Vehicle = VEHICLE::erstelle_fahr(hash2, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
						if (ENTITY::DOES_ENTITY_EXIST(Vehicle))
						{
							PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);

							ENTITY::ATTACH_ENTITY_TO_ENTITY(Object, Vehicle, 0, a.x, a.y, a.z + 1.16f, b.x + 62.0f, b.y, b.z, 0, 1, 0, 0, 2, 1);
							ENTITY::ATTACH_ENTITY_TO_ENTITY(Object1, Vehicle, 0, a.x + 2.5f, a.y, a.z, b.x, b.y, b.z, 0, 1, 0, 0, 2, 1);
							ENTITY::ATTACH_ENTITY_TO_ENTITY(Object3, Vehicle, 0, a.x + 2.5f, a.y, a.z + 1.16f, b.x + 62.0f, b.y, b.z, 0, 1, 0, 0, 2, 1);
							ENTITY::ATTACH_ENTITY_TO_ENTITY(Object4, Vehicle, 0, a.x + 0.5f, a.y + 0.5f, a.z + 2.27f, b.x + 50.0f, b.y - 70.0f, b.z, 0, 1, 0, 0, 2, 1);
							ENTITY::ATTACH_ENTITY_TO_ENTITY(Object5, Vehicle, 0, a.x + 1.95f, a.y + 0.5f, a.z + 2.27f, b.x + 50.0f, b.y + 70.0f, b.z, 0, 1, 0, 0, 2, 1);
							ENTITY::ATTACH_ENTITY_TO_ENTITY(Object6, Vehicle, 0, a.x + 1.24f, a.y + 0.8f, a.z + 5.0f, b.x + 90.0f, b.y, b.z, 0, 1, 0, 0, 2, 1);
							ENTITY::ATTACH_ENTITY_TO_ENTITY(Object7, Vehicle, 0, a.x + 1.24f, a.y + 0.8f, a.z + 3.5f, b.x + 90.0f, b.y, b.z, 0, 1, 0, 0, 2, 1);
							ENTITY::ATTACH_ENTITY_TO_ENTITY(Object8, Vehicle, 0, a.x + 1.24f, a.y + 0.8f, a.z + 6.0f, b.x - 15.0f, b.y, b.z, 0, 1, 0, 0, 2, 1);
							ENTITY::ATTACH_ENTITY_TO_ENTITY(Object9, Vehicle, 0, a.x + 2.0f, a.y + 0.8f, a.z + 4.43f, b.x - 30.0f, b.y - 50.0f, b.z, 0, 1, 0, 0, 2, 1);
							ENTITY::ATTACH_ENTITY_TO_ENTITY(Object10, Vehicle, 0, a.x + 0.6f, a.y + 0.8f, a.z + 4.43f, b.x - 30.0f, b.y + 50.0f, b.z, 0, 1, 0, 0, 2, 1);
							ENTITY::ATTACH_ENTITY_TO_ENTITY(Object2, Vehicle, 0, a.x, a.y + 2.1f, a.z + 3.7f, b.x - 10.0f, b.y + 12.8f, b.z, 0, 1, 0, 0, 2, 1);
							ENTITY::ATTACH_ENTITY_TO_ENTITY(Object11, Vehicle, 0, a.x + 2.8f, a.y + 1.9f, a.z + 3.7f, b.x - 10.0f, b.y - 13.6f, b.z, 0, 1, 0, 0, 2, 1);
						}
					}
				}
			}
			if (Menu::Option("Military Flightsquad")) 
			{
				int Handle = PLAYER::PLAYER_PED_ID();
				Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
				Vector3 null; null.x = 0, null.y = 0; null.z = 0;
				Vector3 a; a.x = 0, a.y = 0, a.z = 0.03f;
				Vector3 b; b.x = 0, b.y = 0, b.z = 0;
				int hash = GAMEPLAY::GET_HASH_KEY("hydra");
				int hash1 = GAMEPLAY::GET_HASH_KEY("hydra");
				int hash2 = GAMEPLAY::GET_HASH_KEY("hydra");
				int hash3 = GAMEPLAY::GET_HASH_KEY("hydra");
				int hash4 = GAMEPLAY::GET_HASH_KEY("hydra");
				int hash5 = GAMEPLAY::GET_HASH_KEY("hydra");
				int hash6 = GAMEPLAY::GET_HASH_KEY("hydra");
				int hash7 = GAMEPLAY::GET_HASH_KEY("hydra");
				int hash8 = GAMEPLAY::GET_HASH_KEY("hydra");

				STREAMING::REQUEST_MODEL(hash);
				STREAMING::REQUEST_MODEL(hash2);
				STREAMING::REQUEST_MODEL(hash1);
				STREAMING::REQUEST_MODEL(hash3);
				STREAMING::REQUEST_MODEL(hash4);
				STREAMING::REQUEST_MODEL(hash5);
				STREAMING::REQUEST_MODEL(hash6);
				STREAMING::REQUEST_MODEL(hash7);
				STREAMING::REQUEST_MODEL(hash8);
				if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hash2) && STREAMING::HAS_MODEL_LOADED(hash1) && STREAMING::HAS_MODEL_LOADED(hash3) && STREAMING::HAS_MODEL_LOADED(hash4) && STREAMING::HAS_MODEL_LOADED(hash5) && STREAMING::HAS_MODEL_LOADED(hash6) && STREAMING::HAS_MODEL_LOADED(hash7) && STREAMING::HAS_MODEL_LOADED(hash8))
				{
					int Object = VEHICLE::erstelle_fahr(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
					int Object1 = VEHICLE::erstelle_fahr(hash1, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
					int Object2 = VEHICLE::erstelle_fahr(hash3, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
					int Object3 = VEHICLE::erstelle_fahr(hash4, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
					int Object4 = VEHICLE::erstelle_fahr(hash5, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
					int Object5 = VEHICLE::erstelle_fahr(hash6, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
					int Object6 = VEHICLE::erstelle_fahr(hash7, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
					int Object7 = VEHICLE::erstelle_fahr(hash8, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
					if (ENTITY::DOES_ENTITY_EXIST(Object))
					{
						int Vehicle = VEHICLE::erstelle_fahr(hash2, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
						if (ENTITY::DOES_ENTITY_EXIST(Vehicle))
						{

							PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);


							ENTITY::ATTACH_ENTITY_TO_ENTITY(Object, Vehicle, 0, a.x, a.y + 15.541162f, a.z, b.x, b.y, b.z, 0, 1, 0, 0, 2, 1);
							ENTITY::ATTACH_ENTITY_TO_ENTITY(Object1, Vehicle, 0, a.x, a.y + 30.541162f, a.z, b.x, b.y, b.z, 0, 1, 0, 0, 2, 1);
							ENTITY::ATTACH_ENTITY_TO_ENTITY(Object2, Vehicle, 0, a.x - 15.0f, a.y + 15.541162f, a.z, b.x, b.y, b.z, 0, 1, 0, 0, 2, 1);
							ENTITY::ATTACH_ENTITY_TO_ENTITY(Object3, Vehicle, 0, a.x + 15.0f, a.y + 15.541162f, a.z, b.x, b.y, b.z, 0, 1, 0, 0, 2, 1);
							ENTITY::ATTACH_ENTITY_TO_ENTITY(Object4, Vehicle, 0, a.x + 15.0f, a.y, a.z, b.x, b.y, b.z, 0, 1, 0, 0, 2, 1);
							ENTITY::ATTACH_ENTITY_TO_ENTITY(Object5, Vehicle, 0, a.x + 30.0f, a.y, a.z, b.x, b.y, b.z, 0, 1, 0, 0, 2, 1);
							ENTITY::ATTACH_ENTITY_TO_ENTITY(Object6, Vehicle, 0, a.x - 15.0f, a.y, a.z, b.x, b.y, b.z, 0, 1, 0, 0, 2, 1);
							ENTITY::ATTACH_ENTITY_TO_ENTITY(Object7, Vehicle, 0, a.x - 30.0f, a.y, a.z, b.x, b.y, b.z, 0, 1, 0, 0, 2, 1);

						}
					}
				}
			}
			if (Menu::Option("Snow Scooter")) 
			{
				int Handle = PLAYER::PLAYER_PED_ID();
				Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
				Vector3 null; null.x = 0, null.y = 0; null.z = 0;
				Vector3 a; a.x = 0, a.y = 0, a.z = 0.03f;
				Vector3 b; b.x = 0, b.y = 0, b.z = 0;
				int hash = GAMEPLAY::GET_HASH_KEY("seashark");
				int hash2 = GAMEPLAY::GET_HASH_KEY("sanchez");
				STREAMING::REQUEST_MODEL(hash);
				STREAMING::REQUEST_MODEL(hash2);
				if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hash2))
				{
					int Object = VEHICLE::erstelle_fahr(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
					if (ENTITY::DOES_ENTITY_EXIST(Object))
					{
						int Vehicle = VEHICLE::erstelle_fahr(hash2, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
						if (ENTITY::DOES_ENTITY_EXIST(Vehicle))
						{
							VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Vehicle, 255, 0, 0);
							VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Vehicle, 255, 0, 0);
							VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Object, 255, 0, 0);
							VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Object, 255, 0, 0);
							PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);

							ENTITY::ATTACH_ENTITY_TO_ENTITY(Object, Vehicle, 0, a.x - 0.02f, a.y - 0.08f, a.z - 0.36f, b.x - 0.21f, b.y + 1.83f, b.z - 0.21f, 0, 1, 0, 0, 2, 1);

						}
					}
				}
			}
			if (Menu::Option("Speeder Prototype")) 
			{
				int Handle = PLAYER::PLAYER_PED_ID();
				Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
				Vector3 null; null.x = 0, null.y = 0; null.z = 0;
				Vector3 a; a.x = 0, a.y = 0, a.z = 0.03f;
				Vector3 b; b.x = 0, b.y = 0, b.z = 0;
				int hash = GAMEPLAY::GET_HASH_KEY("seashark");
				int hash1 = GAMEPLAY::GET_HASH_KEY("seashark");
				int hash2 = GAMEPLAY::GET_HASH_KEY("turismor");
				STREAMING::REQUEST_MODEL(hash);
				STREAMING::REQUEST_MODEL(hash1);
				STREAMING::REQUEST_MODEL(hash2);
				if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hash1) && STREAMING::HAS_MODEL_LOADED(hash2))
				{
					int Object = VEHICLE::erstelle_fahr(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
					int Object1 = VEHICLE::erstelle_fahr(hash1, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
					if (ENTITY::DOES_ENTITY_EXIST(Object))
					{
						int Vehicle = VEHICLE::erstelle_fahr(hash2, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
						if (ENTITY::DOES_ENTITY_EXIST(Vehicle))
						{
							VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Vehicle, 255, 0, 0);
							VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Vehicle, 255, 0, 0);
							VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Object, 255, 0, 0);
							VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Object, 255, 0, 0);
							VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Object1, 255, 0, 0);
							VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Object1, 255, 0, 0);
							PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
							ENTITY::ATTACH_ENTITY_TO_ENTITY(Object, Vehicle, 0, a.x, a.y + 1.37f, a.z + 0.59f, b.x - 14.33f, b.y + 541.20f, b.z - 1.42f, 0, 1, 0, 0, 2, 1);
							ENTITY::ATTACH_ENTITY_TO_ENTITY(Object1, Vehicle, 0, a.x, a.y - 0.79f, a.z + 0.83f, b.x + 9.72f, b.y + 539.03f, b.z - 0.16f, 0, 1, 0, 0, 2, 1);
						}
					}
				}
			}
			if (Menu::Option("6x6 War RC")) 
			{
				int Handle = PLAYER::PLAYER_PED_ID();
				Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
				Vector3 null; null.x = 0, null.y = 0; null.z = 0;
				Vector3 a; a.x = 0, a.y = 0, a.z = 0.03f;
				Vector3 b; b.x = 0, b.y = 0, b.z = 0;
				int hash = GAMEPLAY::GET_HASH_KEY("dune2");
				int hash2 = GAMEPLAY::GET_HASH_KEY("t20");
				int hash3 = GAMEPLAY::GET_HASH_KEY("dune2");
				int hash4 = GAMEPLAY::GET_HASH_KEY("dune2");
				int hash5 = GAMEPLAY::GET_HASH_KEY("monster");
				int hash6 = GAMEPLAY::GET_HASH_KEY("monster");


				STREAMING::REQUEST_MODEL(hash);
				STREAMING::REQUEST_MODEL(hash2);
				STREAMING::REQUEST_MODEL(hash3);
				STREAMING::REQUEST_MODEL(hash4);
				STREAMING::REQUEST_MODEL(hash5);
				STREAMING::REQUEST_MODEL(hash6);


				if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hash2) && STREAMING::HAS_MODEL_LOADED(hash3) && STREAMING::HAS_MODEL_LOADED(hash4) && STREAMING::HAS_MODEL_LOADED(hash5) && STREAMING::HAS_MODEL_LOADED(hash6))
				{
					int Object1 = VEHICLE::erstelle_fahr(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
					int Object2 = VEHICLE::erstelle_fahr(hash3, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
					int Object3 = VEHICLE::erstelle_fahr(hash4, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
					int Object4 = VEHICLE::erstelle_fahr(hash5, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
					int Object5 = VEHICLE::erstelle_fahr(hash6, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);



					if (ENTITY::DOES_ENTITY_EXIST(Object1) && ENTITY::DOES_ENTITY_EXIST(Object2) && ENTITY::DOES_ENTITY_EXIST(Object3) && ENTITY::DOES_ENTITY_EXIST(Object4) && ENTITY::DOES_ENTITY_EXIST(Object5))
					{
						int Vehicle = VEHICLE::erstelle_fahr(hash2, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
						if (ENTITY::DOES_ENTITY_EXIST(Vehicle))
						{
							PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);

							ENTITY::ATTACH_ENTITY_TO_ENTITY(Object1, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, 1, 0, 0, 2, 1);
							ENTITY::ATTACH_ENTITY_TO_ENTITY(Object2, Vehicle, 0, a.x - 0.1f, a.y, a.z, b.x, b.y + 41.1f, b.z, 0, 1, 0, 0, 2, 1);
							ENTITY::ATTACH_ENTITY_TO_ENTITY(Object3, Vehicle, 0, a.x + 0.1f, a.y, a.z, b.x, b.y - 41.4f, b.z, 0, 1, 0, 0, 2, 1);
							ENTITY::ATTACH_ENTITY_TO_ENTITY(Object4, Vehicle, 0, a.x + 1.41f, a.y, a.z - 0.2f, b.x - 179.99f, b.y, b.z, 0, 1, 0, 0, 2, 1);
							ENTITY::ATTACH_ENTITY_TO_ENTITY(Object5, Vehicle, 0, a.x - 1.41f, a.y, a.z - 0.2f, b.x - 179.99f, b.y, b.z, 0, 1, 0, 0, 2, 1);

							VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Vehicle, 255, 255, 255);
							VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Vehicle, 255, 255, 255);
							VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Object1, 255, 255, 255);
							VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Object1, 255, 255, 255);
							VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Object4, 255, 255, 255);
							VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Object4, 255, 255, 255);
							VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Object5, 255, 255, 255);
							VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Object5, 255, 255, 255);
						}

					}

				}
			}
			if (Menu::Option("Bumper Buggy")) 
			{
				uint Handle = PLAYER::PLAYER_PED_ID();
				Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
				Vector3 null; null.x = 0, null.y = 0; null.z = 0;
				Vector3 a; a.x = -0.34, a.y = 0.32, a.z = -0.25;
				Vector3 b; b.x = 0, b.y = 0, b.z = 180;
				Vector3 Tire; Tire.x = 0.0, Tire.y = 0.0; Tire.z = 0.0;//Right Front(inner tire)
				Vector3 TireA; TireA.x = 0.40, TireA.y = 1.0, TireA.z = -0.51;//X Coord - Y Coord - Z Coord
				Vector3 TireB; TireB.x = 0.0, TireB.y = 0.0, TireB.z = 88.0;//Pitch - Roll - Yaw
				Vector3 Tire01; Tire01.x = 0.0, Tire01.y = 0.0; Tire01.z = 0;//Right Front(outter tire)
				Vector3 TireC; TireC.x = 0.59, TireC.y = 1.0, TireC.z = -0.51;//X Coord - Y Coord - Z Coord
				Vector3 TireD; TireD.x = 0.0, TireD.y = 0.0, TireD.z = -90.0;//Pitch - Roll - Yaw
				Vector3 Tire02; Tire02.x = 0.0, Tire02.y = 0.0; Tire02.z = 0.0;//Left Front(inner tire)
				Vector3 TireE; TireE.x = -1.09, TireE.y = 1.0, TireE.z = -0.50;//X Coord - Y Coord - Z Coord
				Vector3 TireF; TireF.x = 0.0, TireF.y = 0.0, TireF.z = -88.0;//Pitch - Roll - Yaw
				Vector3 Tire03; Tire03.x = 0.0, Tire03.y = 0.0; Tire03.z = 0.0;//Left Front(outter tire)
				Vector3 TireG; TireG.x = -1.264, TireG.y = 1.0, TireG.z = -0.50;//X Coord - Y Coord - Z Coord
				Vector3 TireH; TireH.x = 0.0, TireH.y = 0.0, TireH.z = 92.0;//Pitch - Roll - Yaw
				Vector3 Engine1; Engine1.x = 0.0, Engine1.y = 0.0; Engine1.z = 0.0;//Engine
				Vector3 EngineA; EngineA.x = -0.39, EngineA.y = -1.60, EngineA.z = -0.70;//X Coord - Y Coord - Z Coord
				Vector3 EngineB; EngineB.x = 0.0, EngineB.y = 0.0, EngineB.z = 0.0;//Pitch - Roll - Yaw
				Vector3 Tire04; Tire04.x = 0.0, Tire04.y = 0.0; Tire04.z = 0.0;//Right Rear(inner tire)
				Vector3 TireI; TireI.x = 0.22, TireI.y = -1.40, TireI.z = -0.50;//X Coord - Y Coord - Z Coord
				Vector3 TireJ; TireJ.x = 0.0, TireJ.y = 0.0, TireJ.z = -88.0;//Pitch - Roll - Yaw
				Vector3 Tire05; Tire05.x = 0.0, Tire05.y = 0.0; Tire05.z = 0.0;//Right Rear(middle tire)
				Vector3 TireK; TireK.x = 0.42, TireK.y = -1.40, TireK.z = -0.50;//X Coord - Y Coord - Z Coord
				Vector3 TireL; TireL.x = 0.0, TireL.y = 0.0, TireL.z = 90.0;//Pitch - Roll - Yaw
				Vector3 Tire06; Tire06.x = 0.0, Tire06.y = 0.0; Tire06.z = 0.0;//Right Rear(outter tire)
				Vector3 TireM; TireM.x = 0.593, TireM.y = -1.40, TireM.z = -0.50;//X Coord - Y Coord - Z Coord
				Vector3 TireN; TireN.x = 0.0, TireN.y = 0.0, TireN.z = -89.0;//Pitch - Roll - Yaw
				Vector3 Tire07; Tire07.x = 0.0, Tire07.y = 0.0; Tire07.z = 0.0;//Left Rear(inner tire)
				Vector3 TireO; TireO.x = -0.81, TireO.y = -1.40, TireO.z = -0.50;//X Coord - Y Coord - Z Coord
				Vector3 TireP; TireP.x = 0.0, TireP.y = 0.0, TireP.z = 88.0;//Pitch - Roll - Yaw
				Vector3 Tire08; Tire08.x = 0.0, Tire08.y = 0.0; Tire08.z = 0.0;//Left Rear(middle tire)
				Vector3 TireQ; TireQ.x = -1.01, TireQ.y = -1.40, TireQ.z = -0.50;//X Coord - Y Coord - Z Coord
				Vector3 TireR; TireR.x = 0.0, TireR.y = 0.0, TireR.z = -91.0;//Pitch - Roll - Yaw
				Vector3 Tire09; Tire09.x = 0.0, Tire09.y = 0.0; Tire09.z = 0.0;//Left Rear(outter tire)
				Vector3 TireSs; TireSs.x = -1.184, TireSs.y = -1.40, TireSs.z = -0.50;//X Coord - Y Coord - Z Coord
				Vector3 TireT; TireT.x = 0.0, TireT.y = 0.0, TireT.z = 88.0;//Pitch - Roll - Yaw
				Vector3 Hood1; Hood1.x = 0, Hood1.y = 0; Hood1.z = 0;//Hood
				Vector3 HoodA; HoodA.x = -0.34, HoodA.y = 1.2, HoodA.z = -0.40;//X Coord - Y Coord - Z Coord
				Vector3 HoodB; HoodB.x = -24.0, HoodB.y = 0.0, HoodB.z = 0.0;//Pitch - Roll - Yaw
				Vector3 Battery1; Battery1.x = 0.0, Battery1.y = 0.0; Battery1.z = 0.0;//Battery
				Vector3 BatteryA; BatteryA.x = -0.34, BatteryA.y = 1.06, BatteryA.z = -0.06;//X Coord - Y Coord - Z Coord
				Vector3 BatteryB; BatteryB.x = -24.0, BatteryB.y = 0.0, BatteryB.z = 0.0;//Pitch - Roll - Yaw
				int hash = GAMEPLAY::GET_HASH_KEY("blista");
				int hash2 = GAMEPLAY::GET_HASH_KEY("prop_bumper_car_01");
				int Tires = GAMEPLAY::GET_HASH_KEY("prop_wheel_01");
				int Engine = GAMEPLAY::GET_HASH_KEY("prop_car_engine_01");
				int Hood = GAMEPLAY::GET_HASH_KEY("hei_prop_heist_emp");
				int Battery = GAMEPLAY::GET_HASH_KEY("prop_power_cell");
				STREAMING::REQUEST_MODEL(hash);
				STREAMING::REQUEST_MODEL(hash2);
				STREAMING::REQUEST_MODEL(Tires);
				STREAMING::REQUEST_MODEL(Engine);
				STREAMING::REQUEST_MODEL(Hood);
				STREAMING::REQUEST_MODEL(Battery);
				if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hash2) && STREAMING::HAS_MODEL_LOADED(Tires) && STREAMING::HAS_MODEL_LOADED(Engine) && STREAMING::HAS_MODEL_LOADED(Hood) && STREAMING::HAS_MODEL_LOADED(Battery))
				{
					int Object = OBJECT::CREATE_OBJECT(hash2, null.x, null.y, null.z, 1, 0, 1);
					int Tire1 = OBJECT::CREATE_OBJECT(Tires, Tire.x, Tire.y, Tire.z, 1, 0, 1);//Right Front(inner tire)
					int Tire2 = OBJECT::CREATE_OBJECT(Tires, Tire01.x, Tire01.y, Tire01.z, 1, 0, 1);//right Front(outter tire)
					int Tire3 = OBJECT::CREATE_OBJECT(Tires, Tire02.x, Tire02.y, Tire02.z, 1, 0, 1);//Left Front(inner tire)
					int Tire4 = OBJECT::CREATE_OBJECT(Tires, Tire03.x, Tire03.y, Tire03.z, 1, 0, 1);//Left Front(outter tire)
					int Engine01 = OBJECT::CREATE_OBJECT(Engine, Engine1.x, Engine1.y, Engine1.z, 1, 0, 1);//Engine
					int Tire5 = OBJECT::CREATE_OBJECT(Tires, Tire04.x, Tire04.y, Tire04.z, 1, 0, 1);//Right Rear(inner tire)
					int Tire6 = OBJECT::CREATE_OBJECT(Tires, Tire05.x, Tire05.y, Tire05.z, 1, 0, 1);//Right Rear(middle tire)
					int Tire7 = OBJECT::CREATE_OBJECT(Tires, Tire06.x, Tire06.y, Tire06.z, 1, 0, 1);//Right Rear(outter tire)
					int Tire8 = OBJECT::CREATE_OBJECT(Tires, Tire07.x, Tire07.y, Tire07.z, 1, 0, 1);//Left Rear(inner tire)
					int Tire9 = OBJECT::CREATE_OBJECT(Tires, Tire08.x, Tire08.y, Tire08.z, 1, 0, 1);//Left Rear(middle tire)
					int Tire10 = OBJECT::CREATE_OBJECT(Tires, Tire09.x, Tire09.y, Tire09.z, 1, 0, 1);//Left Rear(outter tire)
					int Hood01 = OBJECT::CREATE_OBJECT(Hood, Hood1.x, Hood1.y, Hood1.z, 1, 0, 1);//Hood
					int Battery01 = OBJECT::CREATE_OBJECT(Battery, Battery1.x, Battery1.y, Battery1.z, 1, 0, 1);//Battery
					if (ENTITY::DOES_ENTITY_EXIST(Object) && ENTITY::DOES_ENTITY_EXIST(Tire1) && ENTITY::DOES_ENTITY_EXIST(Tire2) && ENTITY::DOES_ENTITY_EXIST(Tire3) && ENTITY::DOES_ENTITY_EXIST(Tire4) && ENTITY::DOES_ENTITY_EXIST(Engine01) && ENTITY::DOES_ENTITY_EXIST(Tire5) && ENTITY::DOES_ENTITY_EXIST(Tire6) && ENTITY::DOES_ENTITY_EXIST(Tire7) && ENTITY::DOES_ENTITY_EXIST(Tire8) && ENTITY::DOES_ENTITY_EXIST(Tire9) && ENTITY::DOES_ENTITY_EXIST(Tire10) && ENTITY::DOES_ENTITY_EXIST(Hood01) && ENTITY::DOES_ENTITY_EXIST(Battery01))
					{
						int Vehicle = VEHICLE::erstelle_fahr(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
						if (ENTITY::DOES_ENTITY_EXIST(Vehicle))
						{
							PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
							STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
							ENTITY::SET_ENTITY_VISIBLE(Vehicle, false, true);
							ENTITY::ATTACH_ENTITY_TO_ENTITY(Object, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, 1, 0, 0, 2, 1);
							ENTITY::ATTACH_ENTITY_TO_ENTITY(Tire1, Vehicle, 0, TireA.x, TireA.y, TireA.z, TireB.x, TireB.y, TireB.z, 0, 1, 0, 0, 2, 1);//Right Front(inner tire)
							ENTITY::ATTACH_ENTITY_TO_ENTITY(Tire2, Vehicle, 0, TireC.x, TireC.y, TireC.z, TireD.x, TireD.y, TireD.z, 0, 1, 0, 0, 2, 1);//right Front(outter tire)
							ENTITY::ATTACH_ENTITY_TO_ENTITY(Tire3, Vehicle, 0, TireE.x, TireE.y, TireE.z, TireF.x, TireF.y, TireF.z, 0, 1, 0, 0, 2, 1);//Left Front(inner tire)
							ENTITY::ATTACH_ENTITY_TO_ENTITY(Tire4, Vehicle, 0, TireG.x, TireG.y, TireG.z, TireH.x, TireH.y, TireH.z, 0, 1, 0, 0, 2, 1);//Left Front(outter tire)
							ENTITY::ATTACH_ENTITY_TO_ENTITY(Engine01, Vehicle, 0, EngineA.x, EngineA.y, EngineA.z, EngineB.x, EngineB.y, EngineB.z, 0, 1, 0, 0, 2, 1);//Engine
							ENTITY::ATTACH_ENTITY_TO_ENTITY(Tire5, Vehicle, 0, TireI.x, TireI.y, TireI.z, TireJ.x, TireJ.y, TireJ.z, 0, 1, 0, 0, 2, 1);//Right Rear(inner tire)
							ENTITY::ATTACH_ENTITY_TO_ENTITY(Tire6, Vehicle, 0, TireK.x, TireK.y, TireK.z, TireL.x, TireL.y, TireL.z, 0, 1, 0, 0, 2, 1);//Right Rear(middle tire)
							ENTITY::ATTACH_ENTITY_TO_ENTITY(Tire7, Vehicle, 0, TireM.x, TireM.y, TireM.z, TireN.x, TireN.y, TireN.z, 0, 1, 0, 0, 2, 1);//Right Rear(outter tire)
							ENTITY::ATTACH_ENTITY_TO_ENTITY(Tire8, Vehicle, 0, TireO.x, TireO.y, TireO.z, TireP.x, TireP.y, TireP.z, 0, 1, 0, 0, 2, 1);//Left Rear(inner tire)
							ENTITY::ATTACH_ENTITY_TO_ENTITY(Tire9, Vehicle, 0, TireQ.x, TireQ.y, TireQ.z, TireR.x, TireR.y, TireR.z, 0, 1, 0, 0, 2, 1);//Left Rear(middle tire)
							ENTITY::ATTACH_ENTITY_TO_ENTITY(Tire10, Vehicle, 0, TireSs.x, TireSs.y, TireSs.z, TireT.x, TireT.y, TireT.z, 0, 1, 0, 0, 2, 1);//Left Rear(outter tire)
							ENTITY::ATTACH_ENTITY_TO_ENTITY(Hood01, Vehicle, 0, HoodA.x, HoodA.y, HoodA.z, HoodB.x, HoodB.y, HoodB.z, 0, 1, 0, 0, 2, 1);//Hood
							ENTITY::ATTACH_ENTITY_TO_ENTITY(Battery01, Vehicle, 0, BatteryA.x, BatteryA.y, BatteryA.z, BatteryB.x, BatteryB.y, BatteryB.z, 0, 1, 0, 0, 2, 1);//Battery
							ENTITY::SET_ENTITY_VISIBLE(Handle, true, true);

						}

					}

				}

			}
			if (Menu::Option("Roller Coaster Car")) 
			{
				uint Handle = PLAYER::PLAYER_PED_ID();
				Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
				//hash2_RollerCar
				Vector3 null; null.x = 0.0, null.y = 0.0; null.z = 0.0;
				Vector3 a; a.x = 0.0, a.y = 0.0, a.z = -0.5;//X Coord - Y Coord - Z Coord
				Vector3 b; b.x = 0.0, b.y = 0.0, b.z = 180.0;//Pitch - Roll - Yaw
															 //hash3_Seats
				Vector3 null1; null1.x = 0.0, null1.y = 0.0; null1.z = 0.0;
				Vector3 a1; a1.x = 0.0, a1.y = 0.0, a1.z = 0.0;
				Vector3 b1; b1.x = 0.0, b1.y = 0.0, b1.z = 0.0;
				//hash3_FLWheel1
				Vector3 null2; null2.x = 0.0, null2.y = 0.0; null2.z = 0.0;
				Vector3 a2; a2.x = -0.97, a2.y = 1.0, a2.z = -0.25;
				Vector3 b2; b2.x = 0.0, b2.y = 0.0, b2.z = -89.0;
				//hash3_RLWheel1
				Vector3 null3; null3.x = 0.0, null3.y = 0.0; null3.z = 0.0;
				Vector3 a3; a3.x = -1.00, a3.y = -1.10, a3.z = -0.24;
				Vector3 b3; b3.x = 0.0, b3.y = 0.0, b3.z = -89.0;
				//hash3_RFWheel1
				Vector3 null4; null4.x = 0.0, null4.y = 0.0; null4.z = 0.0;
				Vector3 a4; a4.x = 0.97, a4.y = 1.00, a4.z = -0.24;
				Vector3 b4; b4.x = 0.0, b4.y = 0.0, b4.z = 89.0;
				//hash3_RRWheel1
				Vector3 null5; null5.x = 0.0, null5.y = 0.0; null5.z = 0.0;
				Vector3 a5; a5.x = 1.00, a5.y = -1.10, a5.z = -0.24;
				Vector3 b5; b5.x = 0.0, b5.y = 0.0, b5.z = 89.0;
				int hash_T20 = GAMEPLAY::GET_HASH_KEY("t20");
				int hash2_RollerCar = GAMEPLAY::GET_HASH_KEY("ind_prop_dlc_roller_car");
				int hash3_Seats = GAMEPLAY::GET_HASH_KEY("prop_hd_seats_01");
				int hash4_Wheel = GAMEPLAY::GET_HASH_KEY("prop_wheel_01");
				STREAMING::REQUEST_MODEL(hash_T20);
				STREAMING::REQUEST_MODEL(hash2_RollerCar);
				STREAMING::REQUEST_MODEL(hash3_Seats);
				STREAMING::REQUEST_MODEL(hash4_Wheel);
				if (STREAMING::HAS_MODEL_LOADED(hash_T20) && STREAMING::HAS_MODEL_LOADED(hash2_RollerCar) && STREAMING::HAS_MODEL_LOADED(hash3_Seats) && STREAMING::HAS_MODEL_LOADED(hash4_Wheel))
				{
					int RollerCar = OBJECT::CREATE_OBJECT(hash2_RollerCar, null.x, null.y, null.z, 1, 0, 1);
					int Seats = OBJECT::CREATE_OBJECT(hash3_Seats, null1.x, null1.y, null1.z, 1, 0, 1);
					int FLWheel1 = OBJECT::CREATE_OBJECT(hash4_Wheel, null2.x, null2.y, null2.z, 1, 0, 1);
					int RLWheel1 = OBJECT::CREATE_OBJECT(hash4_Wheel, null3.x, null3.y, null3.z, 1, 0, 1);
					int RFWheel1 = OBJECT::CREATE_OBJECT(hash4_Wheel, null4.x, null4.y, null4.z, 1, 0, 1);
					int RRWheel1 = OBJECT::CREATE_OBJECT(hash4_Wheel, null5.x, null5.y, null5.z, 1, 0, 1);
					if (ENTITY::DOES_ENTITY_EXIST(RollerCar) && ENTITY::DOES_ENTITY_EXIST(Seats) && ENTITY::DOES_ENTITY_EXIST(FLWheel1) && ENTITY::DOES_ENTITY_EXIST(RLWheel1) && ENTITY::DOES_ENTITY_EXIST(RFWheel1) && ENTITY::DOES_ENTITY_EXIST(RRWheel1))
					{
						int Vehicle = VEHICLE::erstelle_fahr(hash_T20, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
						if (ENTITY::DOES_ENTITY_EXIST(Vehicle))
						{
							PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
							STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash_T20);
							ENTITY::SET_ENTITY_VISIBLE(Vehicle, false, true);
							ENTITY::ATTACH_ENTITY_TO_ENTITY(RollerCar, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, 1, 0, 0, 2, 1);
							ENTITY::ATTACH_ENTITY_TO_ENTITY(Seats, Vehicle, 0, a1.x, a1.y, a1.z, b1.x, b1.y, b1.z, 0, 1, 0, 0, 2, 1);
							ENTITY::ATTACH_ENTITY_TO_ENTITY(FLWheel1, Vehicle, 0, a2.x, a2.y, a2.z, b2.x, b2.y, b2.z, 0, 1, 0, 0, 2, 1);
							ENTITY::ATTACH_ENTITY_TO_ENTITY(RLWheel1, Vehicle, 0, a3.x, a3.y, a3.z, b3.x, b3.y, b3.z, 0, 1, 0, 0, 2, 1);
							ENTITY::ATTACH_ENTITY_TO_ENTITY(RFWheel1, Vehicle, 0, a4.x, a4.y, a4.z, b4.x, b4.y, b4.z, 0, 1, 0, 0, 2, 1);
							ENTITY::ATTACH_ENTITY_TO_ENTITY(RRWheel1, Vehicle, 0, a5.x, a5.y, a5.z, b5.x, b5.y, b5.z, 0, 1, 0, 0, 2, 1);
							ENTITY::SET_ENTITY_VISIBLE(Handle, true, true);

						}

					}

				}

			}
			if (Menu::Option("Boat And Trailer")) 
			{
				uint Me = PLAYER::PLAYER_PED_ID();
				Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
				Vector3 null; null.x = 0, null.y = 0; null.z = 0;
				Vector3 a; a.x = 0, a.y = -0.61, a.z = 0.28;
				Vector3 b; b.x = 0, b.y = 0, b.z = 0;
				int hash = GAMEPLAY::GET_HASH_KEY("boattrailer");
				int hash2 = GAMEPLAY::GET_HASH_KEY("suntrap");
				STREAMING::REQUEST_MODEL(hash);
				STREAMING::REQUEST_MODEL(hash2);
				if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hash2))
				{
					int Vehicle = VEHICLE::erstelle_fahr(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
					int Object = VEHICLE::erstelle_fahr(hash2, null.x, null.y, null.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
					if (ENTITY::DOES_ENTITY_EXIST(Vehicle) && ENTITY::DOES_ENTITY_EXIST(Object))
					{
						STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
						ENTITY::SET_ENTITY_VISIBLE(Vehicle, true, true);
						ENTITY::ATTACH_ENTITY_TO_ENTITY(Object, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, false, 0, 0, 2, true);
						ENTITY::SET_ENTITY_COLLISION(Object, 1, 0);

					}

				}

			}
			if (Menu::Option("FlatBed And T20")) 
			{
				uint Me = PLAYER::PLAYER_PED_ID();
				Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
				Vector3 null; null.x = 0, null.y = 0; null.z = 0;
				Vector3 a; a.x = 0, a.y = -2.0, a.z = 1.1;
				Vector3 b; b.x = 0, b.y = 0, b.z = 0;
				Vector3 null1; null1.x = 0, null1.y = 0; null1.z = 0;
				Vector3 a1; a1.x = -1.06, a1.y = -0.1, a1.z = 0.46;
				Vector3 b1; b1.x = 91.0, b1.y = 0, b1.z = 0;
				Vector3 null2; null2.x = 0, null2.y = 0; null2.z = 0;
				Vector3 a2; a2.x = -0.9, a2.y = 0.61, a2.z = 0.62;
				Vector3 b2; b2.x = 0.0, b2.y = 100.0, b2.z = 0;
				Vector3 null3; null3.x = 0, null3.y = 0; null3.z = 0;
				Vector3 a3; a3.x = 0.9, a3.y = 0.8, a3.z = 0.41;
				Vector3 b3; b3.x = -25.0, b3.y = 0, b3.z = 0;
				int hash = GAMEPLAY::GET_HASH_KEY("flatbed");
				int hash2 = GAMEPLAY::GET_HASH_KEY("t20");
				int hash3 = GAMEPLAY::GET_HASH_KEY("prop_tool_broom");
				int hash4 = GAMEPLAY::GET_HASH_KEY("prop_roadcone01a");
				int hash5 = GAMEPLAY::GET_HASH_KEY("prop_tool_box_02");
				STREAMING::REQUEST_MODEL(hash);
				STREAMING::REQUEST_MODEL(hash2);
				STREAMING::REQUEST_MODEL(hash3);
				STREAMING::REQUEST_MODEL(hash4);
				STREAMING::REQUEST_MODEL(hash5);
				if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hash2) && STREAMING::HAS_MODEL_LOADED(hash3) && STREAMING::HAS_MODEL_LOADED(hash4) && STREAMING::HAS_MODEL_LOADED(hash5))
				{
					int Vehicle = VEHICLE::erstelle_fahr(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
					int Object = VEHICLE::erstelle_fahr(hash2, null.x, null.y, null.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
					int Broom = OBJECT::CREATE_OBJECT(hash3, null1.x, null1.y, null1.z, 1, 0, 1);
					int Cone = OBJECT::CREATE_OBJECT(hash4, null2.x, null2.y, null2.z, 1, 0, 1);
					int Tool = OBJECT::CREATE_OBJECT(hash5, null3.x, null3.y, null3.z, 1, 0, 1);
					if (ENTITY::DOES_ENTITY_EXIST(Vehicle) && ENTITY::DOES_ENTITY_EXIST(Object) && ENTITY::DOES_ENTITY_EXIST(Broom) && ENTITY::DOES_ENTITY_EXIST(Cone) && ENTITY::DOES_ENTITY_EXIST(Tool))
					{
						PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
						VEHICLE::SET_VEHICLE_MOD_KIT(Object, 0);
						VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(Object, "Solitary");
						VEHICLE::SET_VEHICLE_WINDOW_TINT(Object, 5);
						STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
						ENTITY::SET_ENTITY_VISIBLE(Vehicle, true, true);
						ENTITY::ATTACH_ENTITY_TO_ENTITY(Object, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, false, 0, 0, 2, true);
						ENTITY::ATTACH_ENTITY_TO_ENTITY(Broom, Vehicle, 0, a1.x, a1.y, a1.z, b1.x, b1.y, b1.z, 0, false, 0, 0, 2, true);
						ENTITY::ATTACH_ENTITY_TO_ENTITY(Cone, Vehicle, 0, a2.x, a2.y, a2.z, b2.x, b2.y, b2.z, 0, false, 0, 0, 2, true);
						ENTITY::ATTACH_ENTITY_TO_ENTITY(Tool, Vehicle, 0, a3.x, a3.y, a3.z, b3.x, b3.y, b3.z, 0, false, 0, 0, 2, true);
						ENTITY::SET_ENTITY_COLLISION(Object, 1, 0);

					}

				}

			}
			if (Menu::Option("JetSki And Trailer")) 
			{
				uint Me = PLAYER::PLAYER_PED_ID();
				Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
				Vector3 null; null.x = 0, null.y = 0; null.z = 0.;
				Vector3 a; a.x = -0.625, a.y = -1.9, a.z = -0.09;
				Vector3 b; b.x = 0, b.y = 0, b.z = 0;
				Vector3 a1; a1.x = 0.625, a1.y = -1.9, a1.z = -0.09;
				Vector3 b1; b1.x = 0, b1.y = 0, b1.z = 0;

				Vector3 a2; a2.x = 0.0, a2.y = 0.9, a2.z = -0.45;
				Vector3 b2; b2.x = 0, b2.y = 0, b2.z = 180.0;

				int hash = GAMEPLAY::GET_HASH_KEY("boattrailer");
				int hash2 = GAMEPLAY::GET_HASH_KEY("seashark");
				int hash3 = GAMEPLAY::GET_HASH_KEY("prop_tool_box_05");
				STREAMING::REQUEST_MODEL(hash);
				STREAMING::REQUEST_MODEL(hash2);
				STREAMING::REQUEST_MODEL(hash3);

				if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hash2) && STREAMING::HAS_MODEL_LOADED(hash3))
				{
					int Vehicle = VEHICLE::erstelle_fahr(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
					int Object = VEHICLE::erstelle_fahr(hash2, null.x, null.y, null.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
					int Object1 = VEHICLE::erstelle_fahr(hash2, null.x, null.y, null.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
					int Object2 = OBJECT::CREATE_OBJECT(hash3, null.x, null.y, null.z, 1, 0, 1);
					if (ENTITY::DOES_ENTITY_EXIST(Vehicle) && ENTITY::DOES_ENTITY_EXIST(Object) && ENTITY::DOES_ENTITY_EXIST(Object1) && ENTITY::DOES_ENTITY_EXIST(Object2))
					{
						STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
						ENTITY::SET_ENTITY_VISIBLE(Vehicle, true, true);
						ENTITY::ATTACH_ENTITY_TO_ENTITY(Object, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, false, 0, 0, 2, true);
						ENTITY::ATTACH_ENTITY_TO_ENTITY(Object1, Vehicle, 0, a1.x, a1.y, a1.z, b1.x, b1.y, b1.z, 0, false, 0, 0, 2, true);
						ENTITY::ATTACH_ENTITY_TO_ENTITY(Object2, Vehicle, 0, a2.x, a2.y, a2.z, b2.x, b2.y, b2.z, 0, false, 0, 0, 2, true);
						ENTITY::SET_ENTITY_COLLISION(Object, 1, 0);
						ENTITY::SET_ENTITY_COLLISION(Object1, 1, 0);

					}

				}

			}
			if (Menu::Option("Ramp Truck")) 
			{
				uint Me = PLAYER::PLAYER_PED_ID();
				Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
				Vector3 null; null.x = 0, null.y = 0; null.z = 0;
				Vector3 a; a.x = 0, a.y = 10.0, a.z = -0.3;
				Vector3 b; b.x = 0, b.y = -147.0, b.z = 90.0;
				int hash = GAMEPLAY::GET_HASH_KEY("phantom");
				int hash2 = GAMEPLAY::GET_HASH_KEY("prop_lev_des_barge_01");
				STREAMING::REQUEST_MODEL(hash);
				STREAMING::REQUEST_MODEL(hash2);
				if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hash2))
				{
					int Vehicle = VEHICLE::erstelle_fahr(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
					int Object = OBJECT::CREATE_OBJECT(hash2, null.x, null.y, null.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
					if (ENTITY::DOES_ENTITY_EXIST(Vehicle) && ENTITY::DOES_ENTITY_EXIST(Object))
					{
						STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
						PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
						ENTITY::SET_ENTITY_VISIBLE(Vehicle, true, true);
						ENTITY::ATTACH_ENTITY_TO_ENTITY(Object, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, false, 0, 0, 2, true);
						ENTITY::SET_ENTITY_COLLISION(Object, 1, 0);

					}

				}

			}
			if (Menu::Option("Monster Swat")) 
			{
				uint Me = PLAYER::PLAYER_PED_ID();
				Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
				Vector3 null; null.x = 0, null.y = 0; null.z = 0;
				Vector3 a; a.x = 0, a.y = 0, a.z = 0;
				Vector3 b; b.x = 0, b.y = 0, b.z = 0;
				int hash = GAMEPLAY::GET_HASH_KEY("monster");
				int hash2 = GAMEPLAY::GET_HASH_KEY("riot");
				STREAMING::REQUEST_MODEL(hash);
				STREAMING::REQUEST_MODEL(hash2);
				if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hash2))
				{
					int Vehicle = VEHICLE::erstelle_fahr(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
					int Object = VEHICLE::erstelle_fahr(hash2, null.x, null.y, null.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
					if (ENTITY::DOES_ENTITY_EXIST(Vehicle) && ENTITY::DOES_ENTITY_EXIST(Object))
					{
						STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
						PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
						ENTITY::SET_ENTITY_VISIBLE(Vehicle, true, true);
						VEHICLE::SET_VEHICLE_MOD_KIT(Object, 0);
						VEHICLE::SET_VEHICLE_WINDOW_TINT(Object, 5);
						ENTITY::ATTACH_ENTITY_TO_ENTITY(Object, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, false, 0, 0, 2, true);

					}

				}

			}
			if (Menu::Option("Buffulo Police")) 
			{
				uint Me = PLAYER::PLAYER_PED_ID();
				Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
				Vector3 null; null.x = 0, null.y = 0; null.z = 0;
				Vector3 a; a.x = 0, a.y = 0, a.z = 0;
				Vector3 b; b.x = 0, b.y = 0, b.z = 0;
				int hash = GAMEPLAY::GET_HASH_KEY("police2");
				int hash2 = GAMEPLAY::GET_HASH_KEY("buffalo2");
				STREAMING::REQUEST_MODEL(hash);
				STREAMING::REQUEST_MODEL(hash2);
				if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hash2))
				{
					int Vehicle = VEHICLE::erstelle_fahr(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
					int Object = VEHICLE::erstelle_fahr(hash2, null.x, null.y, null.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
					if (ENTITY::DOES_ENTITY_EXIST(Vehicle) && ENTITY::DOES_ENTITY_EXIST(Object))
					{
						STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
						PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
						ENTITY::SET_ENTITY_VISIBLE(Vehicle, true, true);
						VEHICLE::SET_VEHICLE_MOD_KIT(Object, 0);
						VEHICLE::SET_VEHICLE_WINDOW_TINT(Object, 5);
						VEHICLE::SET_VEHICLE_WINDOW_TINT(Vehicle, 5);
						VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Object, 0, 0, 0);
						VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Object, 0, 0, 0);
						VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Vehicle, 0, 0, 0);
						VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Vehicle, 0, 0, 0);
						VEHICLE::SET_VEHICLE_EXTRA_COLOURS(Object, 0, 0);
						ENTITY::ATTACH_ENTITY_TO_ENTITY(Object, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, false, 0, 0, 2, true);

					}

				}

			}
			if (Menu::Option("Insurgent 3")) 
			{
				uint Me = PLAYER::PLAYER_PED_ID();
				Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
				Vector3 null; null.x = 0, null.y = 0; null.z = 0;
				Vector3 a; a.x = 0, a.y = 0, a.z = 0;
				Vector3 b; b.x = 0, b.y = 0, b.z = 0;
				int hash = GAMEPLAY::GET_HASH_KEY("insurgent");
				int hash2 = GAMEPLAY::GET_HASH_KEY("insurgent2");
				STREAMING::REQUEST_MODEL(hash);
				STREAMING::REQUEST_MODEL(hash2);
				if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hash2))
				{
					int Vehicle = VEHICLE::erstelle_fahr(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
					int Object = VEHICLE::erstelle_fahr(hash2, null.x, null.y, null.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
					if (ENTITY::DOES_ENTITY_EXIST(Vehicle) && ENTITY::DOES_ENTITY_EXIST(Object))
					{
						STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
						PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
						ENTITY::SET_ENTITY_VISIBLE(Vehicle, true, true);
						VEHICLE::SET_VEHICLE_MOD_KIT(Object, 0);
						VEHICLE::SET_VEHICLE_WINDOW_TINT(Object, 5);
						VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Object, 0, 0, 0);
						VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Object, 0, 0, 0);
						VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Vehicle, 0, 0, 0);
						VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Vehicle, 0, 0, 0);
						ENTITY::ATTACH_ENTITY_TO_ENTITY(Object, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, false, 0, 0, 2, true);

					}

				}

			}
			if (Menu::Option("Super 1")) 
			{
				uint Me = PLAYER::PLAYER_PED_ID();
				Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
				Vector3 null; null.x = 0, null.y = 0; null.z = 0;
				Vector3 a; a.x = 0, a.y = 0, a.z = -0.25;
				Vector3 b; b.x = 0, b.y = 0, b.z = 0;
				int hash = GAMEPLAY::GET_HASH_KEY("t20");
				int hash2 = GAMEPLAY::GET_HASH_KEY("cheetah");
				STREAMING::REQUEST_MODEL(hash);
				STREAMING::REQUEST_MODEL(hash2);
				if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hash2))
				{
					int Vehicle = VEHICLE::erstelle_fahr(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
					int Object = VEHICLE::erstelle_fahr(hash2, null.x, null.y, null.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
					if (ENTITY::DOES_ENTITY_EXIST(Vehicle) && ENTITY::DOES_ENTITY_EXIST(Object))
					{
						STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
						PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
						ENTITY::SET_ENTITY_VISIBLE(Vehicle, true, true);
						VEHICLE::SET_VEHICLE_MOD_KIT(Object, 0);
						VEHICLE::SET_VEHICLE_WINDOW_TINT(Object, 5);
						VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Object, 0, 0, 0);
						VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Object, 0, 0, 0);
						VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Vehicle, 0, 0, 0);
						VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Vehicle, 0, 0, 0);
						ENTITY::ATTACH_ENTITY_TO_ENTITY(Object, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, false, 0, 0, 2, true);

					}

				}

			}
			if (Menu::Option("Super 2")) 
			{
				uint Me = PLAYER::PLAYER_PED_ID();
				Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
				Vector3 null; null.x = 0, null.y = 0; null.z = 0;
				Vector3 a; a.x = 0, a.y = 0, a.z = 0;
				Vector3 b; b.x = 0, b.y = 0, b.z = 0;
				int hash = GAMEPLAY::GET_HASH_KEY("feltzer2");
				int hash2 = GAMEPLAY::GET_HASH_KEY("rapidgt");
				STREAMING::REQUEST_MODEL(hash);
				STREAMING::REQUEST_MODEL(hash2);
				if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hash2))
				{
					int Vehicle = VEHICLE::erstelle_fahr(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
					int Object = VEHICLE::erstelle_fahr(hash2, null.x, null.y, null.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
					if (ENTITY::DOES_ENTITY_EXIST(Vehicle) && ENTITY::DOES_ENTITY_EXIST(Object))
					{
						STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
						PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
						ENTITY::SET_ENTITY_VISIBLE(Vehicle, true, true);
						VEHICLE::SET_VEHICLE_MOD_KIT(Object, 0);
						VEHICLE::SET_VEHICLE_WINDOW_TINT(Object, 5);
						VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Object, 0, 0, 0);
						VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Object, 0, 0, 0);
						VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Vehicle, 0, 0, 0);
						VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Vehicle, 0, 0, 0);
						ENTITY::ATTACH_ENTITY_TO_ENTITY(Object, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, false, 0, 0, 2, true);

					}

				}

			}
			if (Menu::Option("Muscle 1")) 
			{
				uint Me = PLAYER::PLAYER_PED_ID();
				Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
				Vector3 null; null.x = 0, null.y = 0; null.z = 0;
				Vector3 a; a.x = 0, a.y = 0, a.z = -0.2;
				Vector3 b; b.x = 0, b.y = 0, b.z = 0;
				int hash = GAMEPLAY::GET_HASH_KEY("hotknife");
				int hash2 = GAMEPLAY::GET_HASH_KEY("jb700");
				STREAMING::REQUEST_MODEL(hash);
				STREAMING::REQUEST_MODEL(hash2);
				if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hash2))
				{
					int Vehicle = VEHICLE::erstelle_fahr(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
					int Object = VEHICLE::erstelle_fahr(hash2, null.x, null.y, null.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
					if (ENTITY::DOES_ENTITY_EXIST(Vehicle) && ENTITY::DOES_ENTITY_EXIST(Object))
					{
						STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
						PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
						ENTITY::SET_ENTITY_VISIBLE(Vehicle, true, true);
						VEHICLE::SET_VEHICLE_MOD_KIT(Object, 0);
						VEHICLE::SET_VEHICLE_WINDOW_TINT(Object, 5);
						VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Object, 0, 0, 0);
						VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Object, 0, 0, 0);
						VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Vehicle, 0, 0, 0);
						VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Vehicle, 0, 0, 0);
						ENTITY::ATTACH_ENTITY_TO_ENTITY(Object, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, false, 0, 0, 2, true);

					}

				}

			}
			if (Menu::Option("Muscle 2")) 
			{
				uint Me = PLAYER::PLAYER_PED_ID();
				Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
				Vector3 null; null.x = 0, null.y = 0; null.z = 0;
				Vector3 a; a.x = 0, a.y = 0, a.z = 2.0;
				Vector3 b; b.x = 0, b.y = 0, b.z = 0;
				int hash = GAMEPLAY::GET_HASH_KEY("coquette2");
				int hash2 = GAMEPLAY::GET_HASH_KEY("hotknife");
				STREAMING::REQUEST_MODEL(hash);
				STREAMING::REQUEST_MODEL(hash2);
				if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hash2))
				{
					int Vehicle = VEHICLE::erstelle_fahr(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
					int Object = VEHICLE::erstelle_fahr(hash2, null.x, null.y, null.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
					if (ENTITY::DOES_ENTITY_EXIST(Vehicle) && ENTITY::DOES_ENTITY_EXIST(Object))
					{
						STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
						PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
						ENTITY::SET_ENTITY_VISIBLE(Vehicle, true, true);
						VEHICLE::SET_VEHICLE_MOD_KIT(Object, 0);
						VEHICLE::SET_VEHICLE_WINDOW_TINT(Object, 5);
						VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Object, 0, 0, 0);
						VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Object, 0, 0, 0);
						VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Vehicle, 0, 0, 0);
						VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Vehicle, 0, 0, 0);
						ENTITY::ATTACH_ENTITY_TO_ENTITY(Object, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, false, 0, 0, 2, true);

					}

				}

			}
			if (Menu::Option("Special")) 
			{
				uint Me = PLAYER::PLAYER_PED_ID();
				Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
				Vector3 null; null.x = 0, null.y = 0; null.z = 0;
				Vector3 a; a.x = 0, a.y = 0, a.z = 0;
				Vector3 b; b.x = 0, b.y = 0, b.z = 0;
				int hash = GAMEPLAY::GET_HASH_KEY("zentorno");
				int hash2 = GAMEPLAY::GET_HASH_KEY("kuruma2");
				STREAMING::REQUEST_MODEL(hash);
				STREAMING::REQUEST_MODEL(hash2);
				if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hash2))
				{
					int Vehicle = VEHICLE::erstelle_fahr(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
					int Object = VEHICLE::erstelle_fahr(hash2, null.x, null.y, null.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
					if (ENTITY::DOES_ENTITY_EXIST(Vehicle) && ENTITY::DOES_ENTITY_EXIST(Object))
					{
						STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
						PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
						ENTITY::SET_ENTITY_VISIBLE(Vehicle, true, true);
						VEHICLE::SET_VEHICLE_MOD_KIT(Object, 0);
						VEHICLE::SET_VEHICLE_WINDOW_TINT(Object, 5);
						VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Object, 0, 0, 0);
						VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Object, 0, 0, 0);
						VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(Object, "Solitary");
						VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Vehicle, 0, 0, 0);
						VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Vehicle, 0, 0, 0);
						ENTITY::ATTACH_ENTITY_TO_ENTITY(Object, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, false, 0, 0, 2, true);

					}

				}

			}
			if (Menu::Option("Sub Copter")) 
			{
				uint Me = PLAYER::PLAYER_PED_ID();
				Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
				Vector3 null; null.x = 0, null.y = 0; null.z = 0;
				Vector3 a; a.x = 0, a.y = 1, a.z = 0.8;
				Vector3 b; b.x = 0, b.y = 0, b.z = 0;
				int hash = GAMEPLAY::GET_HASH_KEY("buzzard");
				int hash2 = GAMEPLAY::GET_HASH_KEY("submersible");
				STREAMING::REQUEST_MODEL(hash);
				STREAMING::REQUEST_MODEL(hash2);
				if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hash2))
				{
					int Vehicle = VEHICLE::erstelle_fahr(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
					int Object = VEHICLE::erstelle_fahr(hash2, null.x, null.y, null.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
					if (ENTITY::DOES_ENTITY_EXIST(Vehicle) && ENTITY::DOES_ENTITY_EXIST(Object))
					{
						STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
						PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
						ENTITY::SET_ENTITY_VISIBLE(Vehicle, true, true);
						VEHICLE::SET_VEHICLE_MOD_KIT(Object, 0);
						VEHICLE::SET_VEHICLE_WINDOW_TINT(Object, 5);
						VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Object, 0, 0, 0);
						VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Object, 0, 0, 0);
						VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Vehicle, 255, 149, 0);
						VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Vehicle, 0, 0, 0);
						ENTITY::ATTACH_ENTITY_TO_ENTITY(Object, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, false, 0, 0, 2, true);

					}

				}

			}
			if (Menu::Option("SlamVan")) 
			{
				uint Me = PLAYER::PLAYER_PED_ID();
				Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
				Vector3 null; null.x = 0, null.y = 0; null.z = 0;
				Vector3 a; a.x = 0, a.y = -2.0, a.z = 1.1;
				Vector3 b; b.x = 0, b.y = 0, b.z = 0;
				Vector3 null1; null1.x = 0, null1.y = 0; null1.z = 0;
				Vector3 a1; a1.x = -1.06, a1.y = -0.1, a1.z = 0.46;
				Vector3 b1; b1.x = 91.0, b1.y = 0, b1.z = 0;
				Vector3 null2; null2.x = 0, null2.y = 0; null2.z = 0;
				Vector3 a2; a2.x = -0.9, a2.y = 0.61, a2.z = 0.62;
				Vector3 b2; b2.x = 0.0, b2.y = 100.0, b2.z = 0;
				Vector3 null3; null3.x = 0, null3.y = 0; null3.z = 0;
				Vector3 a3; a3.x = 0.9, a3.y = 0.8, a3.z = 0.41;
				Vector3 b3; b3.x = -25.0, b3.y = 0, b3.z = 0;
				int hash = GAMEPLAY::GET_HASH_KEY("flatbed");
				int hash2 = GAMEPLAY::GET_HASH_KEY("slamvan2");
				int hash3 = GAMEPLAY::GET_HASH_KEY("prop_tool_broom");
				int hash4 = GAMEPLAY::GET_HASH_KEY("prop_roadcone01a");
				int hash5 = GAMEPLAY::GET_HASH_KEY("prop_tool_box_02");
				STREAMING::REQUEST_MODEL(hash);
				STREAMING::REQUEST_MODEL(hash2);
				STREAMING::REQUEST_MODEL(hash3);
				STREAMING::REQUEST_MODEL(hash4);
				STREAMING::REQUEST_MODEL(hash5);
				if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hash2) && STREAMING::HAS_MODEL_LOADED(hash3) && STREAMING::HAS_MODEL_LOADED(hash4) && STREAMING::HAS_MODEL_LOADED(hash5))
				{
					int Vehicle = VEHICLE::erstelle_fahr(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
					int Object = VEHICLE::erstelle_fahr(hash2, null.x, null.y, null.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
					int Broom = OBJECT::CREATE_OBJECT(hash3, null1.x, null1.y, null1.z, 1, 0, 1);
					int Cone = OBJECT::CREATE_OBJECT(hash4, null2.x, null2.y, null2.z, 1, 0, 1);
					int Tool = OBJECT::CREATE_OBJECT(hash5, null3.x, null3.y, null3.z, 1, 0, 1);
					if (ENTITY::DOES_ENTITY_EXIST(Vehicle) && ENTITY::DOES_ENTITY_EXIST(Object) && ENTITY::DOES_ENTITY_EXIST(Broom) && ENTITY::DOES_ENTITY_EXIST(Cone) && ENTITY::DOES_ENTITY_EXIST(Tool))
					{
						PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
						VEHICLE::SET_VEHICLE_MOD_KIT(Object, 0);
						VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Object, 8, 17, 30);
						VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Object, 0, 30, 1);
						VEHICLE::SET_VEHICLE_EXTRA_COLOURS(Object, 92, 0);
						VEHICLE::SET_VEHICLE_COLOURS(Object, 12, 53);
						VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(Object, " Solitary");
						VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT_INDEX(Object, 1);
						VEHICLE::TOGGLE_VEHICLE_MOD(Object, 18, 1);
						VEHICLE::TOGGLE_VEHICLE_MOD(Object, 22, 1);
						VEHICLE::SET_VEHICLE_MOD(Object, 11, 3, 0);
						VEHICLE::SET_VEHICLE_MOD(Object, 14, 14, 0);
						VEHICLE::SET_VEHICLE_MOD(Object, 15, 3, 0);
						VEHICLE::SET_VEHICLE_MOD(Object, 13, 2, 0);
						VEHICLE::SET_VEHICLE_WHEEL_TYPE(Object, 6);
						VEHICLE::SET_VEHICLE_WINDOW_TINT(Object, 5);
						VEHICLE::SET_VEHICLE_MOD(Object, 23, 18, 1);
						STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
						ENTITY::SET_ENTITY_VISIBLE(Vehicle, true, true);
						ENTITY::ATTACH_ENTITY_TO_ENTITY(Object, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, false, 0, 0, 2, true);
						ENTITY::ATTACH_ENTITY_TO_ENTITY(Broom, Vehicle, 0, a1.x, a1.y, a1.z, b1.x, b1.y, b1.z, 0, false, 0, 0, 2, true);
						ENTITY::ATTACH_ENTITY_TO_ENTITY(Cone, Vehicle, 0, a2.x, a2.y, a2.z, b2.x, b2.y, b2.z, 0, false, 0, 0, 2, true);
						ENTITY::ATTACH_ENTITY_TO_ENTITY(Tool, Vehicle, 0, a3.x, a3.y, a3.z, b3.x, b3.y, b3.z, 0, false, 0, 0, 2, true);

					}

				}

			}
			if (Menu::Option("Flying 5 Seater")) 
			{
				uint Me = PLAYER::PLAYER_PED_ID();
				Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
				Vector3 null; null.x = 0, null.y = 0; null.z = 0.;

				Vector3 a; a.x = 0.0, a.y = 0.0, a.z = 0.6;		// seashark 1 - 0.7 worked just hard to get on .. infront and behind wings only way to get on the sharks ...
				Vector3 b; b.x = 0, b.y = 0, b.z = 0;

				Vector3 a1; a1.x = 0.0, a1.y = -4.0, a1.z = 0.6;  // seashark 2
				Vector3 b1; b1.x = 0, b1.y = 0, b1.z = 0;


				Vector3 a2; a2.x = 0.0, a2.y = 0.9, a2.z = -0.45;
				Vector3 b2; b2.x = 0, b2.y = 0, b2.z = 180.0;

				int hash = GAMEPLAY::GET_HASH_KEY("hydra");
				int hash2 = GAMEPLAY::GET_HASH_KEY("seashark");
				int hash3 = GAMEPLAY::GET_HASH_KEY("prop_tool_box_05"); // turn this into something usefull maybe another sea shark ...
				STREAMING::REQUEST_MODEL(hash);
				STREAMING::REQUEST_MODEL(hash2);
				STREAMING::REQUEST_MODEL(hash3);

				if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hash2) && STREAMING::HAS_MODEL_LOADED(hash3))
				{
					int Vehicle = VEHICLE::erstelle_fahr(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
					int Object = VEHICLE::erstelle_fahr(hash2, null.x, null.y, null.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
					int Object1 = VEHICLE::erstelle_fahr(hash2, null.x, null.y, null.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
					int Object2 = OBJECT::CREATE_OBJECT(hash3, null.x, null.y, null.z, 1, 0, 1);
					if (ENTITY::DOES_ENTITY_EXIST(Vehicle) && ENTITY::DOES_ENTITY_EXIST(Object) && ENTITY::DOES_ENTITY_EXIST(Object1) && ENTITY::DOES_ENTITY_EXIST(Object2))
					{
						STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
						ENTITY::SET_ENTITY_VISIBLE(Vehicle, true, true);
						ENTITY::ATTACH_ENTITY_TO_ENTITY(Object, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, false, 0, 0, 2, true);
						ENTITY::ATTACH_ENTITY_TO_ENTITY(Object1, Vehicle, 0, a1.x, a1.y, a1.z, b1.x, b1.y, b1.z, 0, false, 0, 0, 2, true);
						ENTITY::ATTACH_ENTITY_TO_ENTITY(Object2, Vehicle, 0, a2.x, a2.y, a2.z, b2.x, b2.y, b2.z, 0, false, 0, 0, 2, true);
						ENTITY::SET_ENTITY_COLLISION(Object, 1, 0);
						ENTITY::SET_ENTITY_COLLISION(Object1, 1, 0);

					}

				}

			}
			if (Menu::Option("Panto/HotKnife")) 
			{
				uint Handle = PLAYER::PLAYER_PED_ID();
				Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
				//hash2_PANTO
				Vector3 null; null.x = 0.0, null.y = 0.0; null.z = 0.0;
				Vector3 a; a.x = 0.0, a.y = 0.0, a.z = -0.2;//X Coord - Y Coord - Z Coord
				Vector3 b; b.x = 0.0, b.y = 0.0, b.z = 0.0;//Pitch - Roll - Yaw
														   //hash3_MiniGun
				Vector3 null1; null1.x = 0.0, null1.y = 0.0; null1.z = 0.0;
				Vector3 a1; a1.x = -0.60, a1.y = 1.60, a1.z = 0.20;
				Vector3 b1; b1.x = 0.0, b1.y = 0.0, b1.z = 88.0;
				//hash3_MiniGun2
				Vector3 null0; null0.x = 0.0, null0.y = 0.0; null0.z = 0.0;
				Vector3 a0; a0.x = 0.60, a0.y = 1.60, a0.z = 0.20;
				Vector3 b0; b0.x = 0.0, b0.y = 0.0, b0.z = 88.0;
				//hash4_WindScreen _ VANISHED NEEDS FIXING
				Vector3 null2; null2.x = 0.0, null2.y = 0.0; null2.z = 0.0;
				Vector3 a2; a2.x = 0.3, a2.y = 0.41, a2.z = 0.50;
				Vector3 b2; b2.x = -45.3, b2.y = 0.0, b2.z = -179.0;//87
																	//hash4_RLWheel1
				Vector3 null3; null3.x = 0.0, null3.y = 0.0; null3.z = 0.0;
				Vector3 a3; a3.x = -0.90, a3.y = -1.2, a3.z = 0.0; // -0.23
				Vector3 b3; b3.x = 0.0, b3.y = 0.0, b3.z = 86.0;
				//hash4_RFWindScreen 
				Vector3 null4; null4.x = 0.0, null4.y = 0.0; null4.z = 0.0;
				Vector3 a4; a4.x = -0.3, a4.y = 0.41, a4.z = 0.5;
				Vector3 b4; b4.x = -45.3, b4.y = 0.0, b4.z = -179.0;
				//hash4_RRWheel1
				Vector3 null5; null5.x = 0.0, null5.y = 0.0; null5.z = 0.0;
				Vector3 a5; a5.x = 0.92, a5.y = -1.2, a5.z = 0.01;
				Vector3 b5; b5.x = 0.0, b5.y = 0.0, b5.z = -92.0;
				//PUNTO -- FUCK UP NEEDS FIXING 
				Vector3 null6; null6.x = 0, null6.y = 0; null6.z = 0;
				Vector3 a6; a6.x = 0.0, a6.y = 0.0, a6.z = -0.2;
				Vector3 b6; b6.x = 0.0, b6.y = 0.0, b6.z = 0.0;
				//SIDES LEFT
				Vector3 null7; null7.x = 0, null7.y = 0; null7.z = 0;
				Vector3 a7; a7.x = -0.75, a7.y = 0.7, a7.z = -0.3;
				Vector3 b7; b7.x = 90.0, b7.y = 0.0, b7.z = 0.0;
				//SIDES RIGHT
				Vector3 null8; null8.x = 0, null8.y = 0; null8.z = 0;
				Vector3 a8; a8.x = 0.75, a8.y = 0.7, a8.z = -0.3;
				Vector3 b8; b8.x = 90.0, b8.y = 0.0, b8.z = 0.0;

				int hash = GAMEPLAY::GET_HASH_KEY("hotknife");
				int hash2_EMP = GAMEPLAY::GET_HASH_KEY("hei_prop_heist_emp");
				int hash3_MiniGun = GAMEPLAY::GET_HASH_KEY("prop_minigun_01");
				int hash4_Wheel = GAMEPLAY::GET_HASH_KEY("prop_wheel_01");
				int hash2 = GAMEPLAY::GET_HASH_KEY("panto");
				int hashWindow = GAMEPLAY::GET_HASH_KEY("prop_ballistic_shield");
				int hashSides = GAMEPLAY::GET_HASH_KEY("prop_cons_plank");




				STREAMING::REQUEST_MODEL(hashWindow);// WINDOW
				STREAMING::REQUEST_MODEL(hash2_EMP); // PANTO
				STREAMING::REQUEST_MODEL(hash3_MiniGun); // GUNS
				STREAMING::REQUEST_MODEL(hash4_Wheel); // back wheels
				STREAMING::REQUEST_MODEL(hash);
				STREAMING::REQUEST_MODEL(hash2);
				STREAMING::REQUEST_MODEL(hashSides); // SIDE SKIRTS

				if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hashSides) && STREAMING::HAS_MODEL_LOADED(hashWindow) && STREAMING::HAS_MODEL_LOADED(hash2_EMP) && STREAMING::HAS_MODEL_LOADED(hash3_MiniGun) && STREAMING::HAS_MODEL_LOADED(hash2) && STREAMING::HAS_MODEL_LOADED(hash4_Wheel))
				{
					int EMP = OBJECT::CREATE_OBJECT(hash2_EMP, null.x, null.y, null.z, 1, 0, 1);
					int MiniGun = OBJECT::CREATE_OBJECT(hash3_MiniGun, null1.x, null1.y, null1.z, 1, 0, 1);
					int MiniGun2 = OBJECT::CREATE_OBJECT(hash3_MiniGun, null0.x, null0.y, null0.z, 1, 0, 1);
					int WINDOW_1 = OBJECT::CREATE_OBJECT(hashWindow, null2.x, null2.y, null2.z, 1, 0, 1);
					int RLWheel1 = OBJECT::CREATE_OBJECT(hash4_Wheel, null3.x, null3.y, null3.z, 1, 0, 1);
					int WINDOW_2 = OBJECT::CREATE_OBJECT(hashWindow, null4.x, null4.y, null4.z, 1, 0, 1);
					int RRWheel1 = OBJECT::CREATE_OBJECT(hash4_Wheel, null5.x, null5.y, null5.z, 1, 0, 1);
					int Object = VEHICLE::erstelle_fahr(hash2, null.x, null.y, null.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
					int LeftSide = OBJECT::CREATE_OBJECT(hashSides, null7.x, null7.y, null7.z, 1, 0, 1);
					int RightSide = OBJECT::CREATE_OBJECT(hashSides, null8.x, null8.y, null8.z, 1, 0, 1);


					if (ENTITY::DOES_ENTITY_EXIST(EMP) && ENTITY::DOES_ENTITY_EXIST(LeftSide) && ENTITY::DOES_ENTITY_EXIST(RightSide) && ENTITY::DOES_ENTITY_EXIST(MiniGun) && ENTITY::DOES_ENTITY_EXIST(MiniGun2) && ENTITY::DOES_ENTITY_EXIST(WINDOW_1) && ENTITY::DOES_ENTITY_EXIST(RLWheel1) && ENTITY::DOES_ENTITY_EXIST(WINDOW_2) && ENTITY::DOES_ENTITY_EXIST(RRWheel1))
					{
						int Vehicle = VEHICLE::erstelle_fahr(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);

						if (ENTITY::DOES_ENTITY_EXIST(Vehicle))
						{
							PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
							STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
							ENTITY::SET_ENTITY_VISIBLE(Vehicle, true, true);
							ENTITY::SET_ENTITY_VISIBLE(PLAYER::PLAYER_PED_ID(), true, true);
							STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
							PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
							ENTITY::SET_ENTITY_VISIBLE(Vehicle, true, true);
							VEHICLE::SET_VEHICLE_MOD_KIT(Object, 0);
							VEHICLE::SET_VEHICLE_WINDOW_TINT(Object, 5);
							VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Object, 0, 0, 0);
							VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Object, 0, 0, 0);
							VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Vehicle, 0, 0, 0);
							VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Vehicle, 0, 0, 0);
							VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(Vehicle, "sm");
							VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(Object, "sm");
							VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT_INDEX(Vehicle, 1);
							VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT_INDEX(Object, 1);

							ENTITY::ATTACH_ENTITY_TO_ENTITY(Object, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, false, 0, 0, 2, true);
							ENTITY::ATTACH_ENTITY_TO_ENTITY(EMP, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, 1, 0, 0, 2, 1);
							ENTITY::ATTACH_ENTITY_TO_ENTITY(MiniGun, Vehicle, 0, a1.x, a1.y, a1.z, b1.x, b1.y, b1.z, 0, 1, 0, 0, 2, 1);
							ENTITY::ATTACH_ENTITY_TO_ENTITY(MiniGun2, Vehicle, 0, a0.x, a0.y, a0.z, b0.x, b0.y, b0.z, 0, 1, 0, 0, 2, 1);
							ENTITY::ATTACH_ENTITY_TO_ENTITY(WINDOW_1, Vehicle, 0, a2.x, a2.y, a2.z, b2.x, b2.y, b2.z, 0, 1, 0, 0, 2, 1);
							ENTITY::ATTACH_ENTITY_TO_ENTITY(RLWheel1, Vehicle, 0, a3.x, a3.y, a3.z, b3.x, b3.y, b3.z, 0, 1, 0, 0, 2, 1);
							ENTITY::ATTACH_ENTITY_TO_ENTITY(WINDOW_2, Vehicle, 0, a4.x, a4.y, a4.z, b4.x, b4.y, b4.z, 0, 1, 0, 0, 2, 1);
							ENTITY::ATTACH_ENTITY_TO_ENTITY(RRWheel1, Vehicle, 0, a5.x, a5.y, a5.z, b5.x, b5.y, b5.z, 0, 1, 0, 0, 2, 1);
							ENTITY::ATTACH_ENTITY_TO_ENTITY(LeftSide, Vehicle, 0, a7.x, a7.y, a7.z, b7.x, b7.y, b7.z, 0, 1, 0, 0, 2, 1);
							ENTITY::ATTACH_ENTITY_TO_ENTITY(RightSide, Vehicle, 0, a8.x, a8.y, a8.z, b8.x, b8.y, b8.z, 0, 1, 0, 0, 2, 1);


						}

					}

				}

			}
			if (Menu::Option("Monster Digger")) 
			{
				uint Handle = PLAYER::PLAYER_PED_ID();
				Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
				//hash2_Dozer
				Vector3 null; null.x = 0.0, null.y = 0.0; null.z = 0.0;
				Vector3 a; a.x = 0.0, a.y = 0.0, a.z = -0.4;   //X Coord - Y Coord - Z Coord
				Vector3 b; b.x = 0.0, b.y = 0.0, b.z = 0.0;   //Pitch - Roll - Yaw
															  //hash3_MiniGun LEFT
				Vector3 null1; null1.x = 0.0, null1.y = 0.0; null1.z = 0.0;
				Vector3 a1; a1.x = -0.70, a1.y = 1.80, a1.z = 0.98;
				Vector3 b1; b1.x = 0.0, b1.y = 0.0, b1.z = 88.0;
				//hash3_MiniGun2 RIGHT
				Vector3 null0; null0.x = 0.0, null0.y = 0.0; null0.z = 0.0;
				Vector3 a0; a0.x = 0.70, a0.y = 1.80, a0.z = 0.98;
				Vector3 b0; b0.x = 0.0, b0.y = 0.0, b0.z = 88.0;
				//hash4_Left BLUE left
				Vector3 null2; null2.x = 0.0, null2.y = 0.0; null2.z = 0.0;
				Vector3 a2; a2.x = -0.31, a2.y = 2.51, a2.z = 0.55;
				Vector3 b2; b2.x = 0.0, b2.y = 0.0, b2.z = -175.0;//87 - 179
																  //hash4_NIONS LEFT/back
				Vector3 null3; null3.x = 0.0, null3.y = 0.0; null3.z = 0.0;
				Vector3 a3; a3.x = 0.5, a3.y = -3.0, a3.z = -0.36; // -0.23
				Vector3 b3; b3.x = 0.0, b3.y = 0.0, b3.z = 86.0;
				//hash4_Right BLUE LIGHT
				Vector3 null4; null4.x = 0.0, null4.y = 0.0; null4.z = 0.0;
				Vector3 a4; a4.x = 0.31, a4.y = 2.51, a4.z = 0.55;
				Vector3 b4; b4.x = 0.0, b4.y = 0.0, b4.z = -175.0;
				//hash4_NIONS RIGHT
				Vector3 null5; null5.x = 0.0, null5.y = 0.0; null5.z = 0.0;
				Vector3 a5; a5.x = 0.92, a5.y = -2.0, a5.z = 0.01;
				Vector3 b5; b5.x = 0.0, b5.y = 0.0, b5.z = 89.0;
				//ENGINE
				Vector3 null6; null6.x = 0, null6.y = 0; null6.z = 0;
				Vector3 a6; a6.x = 0.0, a6.y = 1.76, a6.z = 0.86;
				Vector3 b6; b6.x = -0.0, b6.y = 0.0, b6.z = 0.0;
				//SIDES LEFT EMP
				Vector3 null7; null7.x = 0, null7.y = 0; null7.z = 0;
				Vector3 a7; a7.x = -0.88, a7.y = -1.8, a7.z = 1.0;
				Vector3 b7; b7.x = 0.0, b7.y = -51.9, b7.z = 0.0;
				//SIDES RIGHT EMP
				Vector3 null8; null8.x = 0, null8.y = 0; null8.z = 0;
				Vector3 a8; a8.x = 0.88, a8.y = -1.8, a8.z = 1.0;
				Vector3 b8; b8.x = 0.0, b8.y = 51.9, b8.z = 0.0;
				//BEAR
				Vector3 null9; null9.x = 0, null9.y = 0; null9.z = 0;
				Vector3 a9; a9.x = -1.0, a9.y = 2.7, a9.z = -0.4;
				Vector3 b9; b9.x = 0.0, b9.y = 0.0, b9.z = 156.5;
				//SPIKES
				Vector3 null10; null10.x = 0, null10.y = 0; null10.z = 0;
				Vector3 a10; a10.x = -0.12, a10.y = 0.59, a10.z = 1.9;
				Vector3 b10; b10.x = 0.0, b10.y = 0.0, b10.z = 0.0;

				int hash = GAMEPLAY::GET_HASH_KEY("monster");				// Monster Truck
				int hash1 = GAMEPLAY::GET_HASH_KEY("prop_car_engine_01");	// Car Engine
				int hash2 = GAMEPLAY::GET_HASH_KEY("bulldozer");			// Dozer
				int hash3 = GAMEPLAY::GET_HASH_KEY("prop_minigun_01");		// Mini GUn 
				int hash4 = GAMEPLAY::GET_HASH_KEY("v_ilev_uvcheetah");		// Nion Lights <-- needs changing
				int hash5 = GAMEPLAY::GET_HASH_KEY("prop_air_lights_05a");	// Blue Lights	
				int hash6 = GAMEPLAY::GET_HASH_KEY("hei_prop_heist_emp");	// Emp Lights	
				int hash7 = GAMEPLAY::GET_HASH_KEY("prop_mem_teddy_02");	// Large Teddy	
				int hash8 = GAMEPLAY::GET_HASH_KEY("p_stinger_04");			// Stinger Spikes

				STREAMING::REQUEST_MODEL(hash); 	// MONSTER
				STREAMING::REQUEST_MODEL(hash1); 	// Car Engine
				STREAMING::REQUEST_MODEL(hash2); 	// DOZER
				STREAMING::REQUEST_MODEL(hash3); 	// GUNS
				STREAMING::REQUEST_MODEL(hash4); 	// Nion Lights
				STREAMING::REQUEST_MODEL(hash5);	// Blue Lights
				STREAMING::REQUEST_MODEL(hash6); 	// Emp Lights
				STREAMING::REQUEST_MODEL(hash7); 	// Large Teddy
				STREAMING::REQUEST_MODEL(hash8); 	// SPIKES

				if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hash1) && STREAMING::HAS_MODEL_LOADED(hash2) && STREAMING::HAS_MODEL_LOADED(hash3) && STREAMING::HAS_MODEL_LOADED(hash4) && STREAMING::HAS_MODEL_LOADED(hash5) && STREAMING::HAS_MODEL_LOADED(hash6) && STREAMING::HAS_MODEL_LOADED(hash7) && STREAMING::HAS_MODEL_LOADED(hash8))
				{
					int Object = VEHICLE::erstelle_fahr(hash2, null.x, null.y, null.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
					int Ebox = OBJECT::CREATE_OBJECT(hash1, null.x, null.y, null.z, 1, 0, 1);
					int GunL = OBJECT::CREATE_OBJECT(hash3, null1.x, null1.y, null1.z, 1, 0, 1);
					int GunR = OBJECT::CREATE_OBJECT(hash3, null0.x, null0.y, null0.z, 1, 0, 1);
					int LSign = OBJECT::CREATE_OBJECT(hash4, null3.x, null3.y, null3.z, 1, 0, 1);
					int RSign = OBJECT::CREATE_OBJECT(hash4, null5.x, null5.y, null5.z, 1, 0, 1);
					int LBlight = OBJECT::CREATE_OBJECT(hash5, null2.x, null2.y, null2.z, 1, 0, 1);
					int RBlight = OBJECT::CREATE_OBJECT(hash5, null4.x, null4.y, null4.z, 1, 0, 1);
					int LeftEmp = OBJECT::CREATE_OBJECT(hash6, null7.x, null7.y, null7.z, 1, 0, 1);
					int RightEmp = OBJECT::CREATE_OBJECT(hash6, null8.x, null8.y, null8.z, 1, 0, 1);
					int Teddy = OBJECT::CREATE_OBJECT(hash7, null9.x, null9.y, null9.z, 1, 0, 1);
					int Spikes = OBJECT::CREATE_OBJECT(hash8, null10.x, null10.y, null10.z, 1, 0, 1);

					if (ENTITY::DOES_ENTITY_EXIST(Ebox) && ENTITY::DOES_ENTITY_EXIST(GunL) && ENTITY::DOES_ENTITY_EXIST(GunR) && ENTITY::DOES_ENTITY_EXIST(LSign) && ENTITY::DOES_ENTITY_EXIST(RSign) && ENTITY::DOES_ENTITY_EXIST(LBlight) && ENTITY::DOES_ENTITY_EXIST(RBlight) && ENTITY::DOES_ENTITY_EXIST(LeftEmp) && ENTITY::DOES_ENTITY_EXIST(RightEmp) && ENTITY::DOES_ENTITY_EXIST(Teddy) && ENTITY::DOES_ENTITY_EXIST(Spikes))
					{
						int Vehicle = VEHICLE::erstelle_fahr(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);

						if (ENTITY::DOES_ENTITY_EXIST(Vehicle))
						{
							PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
							STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
							ENTITY::SET_ENTITY_VISIBLE(Vehicle, true, true);
							ENTITY::SET_ENTITY_VISIBLE(PLAYER::PLAYER_PED_ID(), true, true);
							VEHICLE::SET_VEHICLE_MOD_KIT(Vehicle, 5);
							VEHICLE::SET_VEHICLE_WINDOW_TINT(Vehicle, 5);
							VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Vehicle, 0, 0, 0);
							VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Vehicle, 0, 0, 0);
							VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Object, 0, 0, 0);
							VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Object, 0, 0, 0);

							ENTITY::ATTACH_ENTITY_TO_ENTITY(Object, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, false, 0, 0, 2, true);
							ENTITY::ATTACH_ENTITY_TO_ENTITY(Ebox, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, 1, 0, 0, 2, 1);
							ENTITY::ATTACH_ENTITY_TO_ENTITY(GunL, Vehicle, 0, a1.x, a1.y, a1.z, b1.x, b1.y, b1.z, 0, 1, 0, 0, 2, 1);
							ENTITY::ATTACH_ENTITY_TO_ENTITY(GunR, Vehicle, 0, a0.x, a0.y, a0.z, b0.x, b0.y, b0.z, 0, 1, 0, 0, 2, 1);
							ENTITY::ATTACH_ENTITY_TO_ENTITY(LBlight, Vehicle, 0, a2.x, a2.y, a2.z, b2.x, b2.y, b2.z, 0, 1, 0, 0, 2, 1);
							ENTITY::ATTACH_ENTITY_TO_ENTITY(RBlight, Vehicle, 0, a4.x, a4.y, a4.z, b4.x, b4.y, b4.z, 0, 1, 0, 0, 2, 1);
							ENTITY::ATTACH_ENTITY_TO_ENTITY(LSign, Vehicle, 0, a3.x, a3.y, a3.z, b3.x, b3.y, b3.z, 0, 1, 0, 0, 2, 1);
							ENTITY::ATTACH_ENTITY_TO_ENTITY(RSign, Vehicle, 0, a5.x, a5.y, a5.z, b5.x, b5.y, b5.z, 0, 1, 0, 0, 2, 1);
							ENTITY::ATTACH_ENTITY_TO_ENTITY(LeftEmp, Vehicle, 0, a7.x, a7.y, a7.z, b7.x, b7.y, b7.z, 0, 1, 0, 0, 2, 1);
							ENTITY::ATTACH_ENTITY_TO_ENTITY(RightEmp, Vehicle, 0, a8.x, a8.y, a8.z, b8.x, b8.y, b8.z, 0, 1, 0, 0, 2, 1);
							ENTITY::ATTACH_ENTITY_TO_ENTITY(Teddy, Vehicle, 0, a9.x, a9.y, a9.z, b9.x, b9.y, b9.z, 0, 1, 0, 0, 2, 1);
							ENTITY::ATTACH_ENTITY_TO_ENTITY(Spikes, Vehicle, 0, a10.x, a10.y, a10.z, b10.x, b10.y, b10.z, 0, 1, 0, 0, 2, 1);
						}

					}

				}

			}
			if (Menu::Option("Train")) 
			{
				uint Me = PLAYER::PLAYER_PED_ID();
				Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
				Vector3 null; null.x = 0, null.y = 0; null.z = 0;
				Vector3 a; a.x = 0, a.y = 0, a.z = 0;
				Vector3 b; b.x = 0, b.y = 0, b.z = 0;
				int hash = GAMEPLAY::GET_HASH_KEY("massacro2");
				int hash2 = GAMEPLAY::GET_HASH_KEY("freight");
				STREAMING::REQUEST_MODEL(hash);
				STREAMING::REQUEST_MODEL(hash2);
				if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hash2))
				{
					int Vehicle = VEHICLE::erstelle_fahr(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
					int Object = VEHICLE::erstelle_fahr(hash2, null.x, null.y, null.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
					if (ENTITY::DOES_ENTITY_EXIST(Vehicle) && ENTITY::DOES_ENTITY_EXIST(Object))
					{
						STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
						PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
						ENTITY::SET_ENTITY_VISIBLE(Object, true, true);
						VEHICLE::SET_VEHICLE_MOD_KIT(Object, 0);
						VEHICLE::SET_VEHICLE_WINDOW_TINT(Object, 5);
						VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Object, 0, 0, 0);
						VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Object, 0, 0, 0);
						VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(Object, "sm");
						VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Vehicle, 0, 0, 0);
						VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Vehicle, 0, 0, 0);
						ENTITY::ATTACH_ENTITY_TO_ENTITY(Object, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, false, 0, 0, 2, true);

					}

				}

			}
			if (Menu::Option("Classic Car Mix")) 
			{
				uint Me = PLAYER::PLAYER_PED_ID();
				Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
				Vector3 null; null.x = 0, null.y = 0; null.z = 0;
				Vector3 a; a.x = 0, a.y = 0, a.z = 0;
				Vector3 b; b.x = 0, b.y = 0, b.z = 0;
				int hash = GAMEPLAY::GET_HASH_KEY("ztype");
				int hash2 = GAMEPLAY::GET_HASH_KEY("btype");
				STREAMING::REQUEST_MODEL(hash);
				STREAMING::REQUEST_MODEL(hash2);
				if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hash2))
				{
					int Vehicle = VEHICLE::erstelle_fahr(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
					int Object = VEHICLE::erstelle_fahr(hash2, null.x, null.y, null.z, ENTITY::GET_ENTITY_HEADING(Me), 1, 0);
					if (ENTITY::DOES_ENTITY_EXIST(Vehicle) && ENTITY::DOES_ENTITY_EXIST(Object))
					{
						STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
						PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
						ENTITY::SET_ENTITY_VISIBLE(Vehicle, true, true);
						VEHICLE::SET_VEHICLE_MOD_KIT(Object, 0);
						VEHICLE::SET_VEHICLE_WINDOW_TINT(Object, 5);
						VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Object, 0, 0, 0);
						VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Object, 0, 0, 0);
						VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(Vehicle, "Solitary");
						VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(Object, "Solitary");
						VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Vehicle, 0, 0, 0);
						VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Vehicle, 0, 0, 0);
						ENTITY::ATTACH_ENTITY_TO_ENTITY(Object, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, false, 0, 0, 2, true);

					}

				}

			}


		}
		break;
#pragma endregion

#pragma region Riding Things
		case ride:
		{
			Menu::Title("Star");
			Menu::Break("Ride Animals");
			                             

			if (Menu::Option("Stop Ride")) {
				Ped playerPed = PLAYER::PLAYER_PED_ID();
				ENTITY::DETACH_ENTITY(playerPed, 1, 1);
				AI::CLEAR_PED_TASKS_IMMEDIATELY(playerPed);
			}
			Menu::Break("Ride");
			if (Menu::Option("Ride Deer")) {
				Player player = PLAYER::PLAYER_ID();
				Ped playerPed = PLAYER::PLAYER_PED_ID();
				if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
				Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
				Hash stripper = GAMEPLAY::GET_HASH_KEY("a_c_deer");
				STREAMING::REQUEST_MODEL(stripper);
				while (!STREAMING::HAS_MODEL_LOADED(stripper))
					WAIT(0);

				int createdPED = PED::CREATE_PED(26, stripper, pos.x, pos.y, pos.z, 1, 1, 0);
				ENTITY::SET_ENTITY_INVINCIBLE(createdPED, false);
				PED::SET_PED_COMBAT_ABILITY(createdPED, 100);
				PED::SET_PED_CAN_SWITCH_WEAPON(createdPED, true);
				//				SET_ENTITY_HEADING(createdPED, 180.0f);

				ENTITY::ATTACH_ENTITY_TO_ENTITY(playerPed, createdPED, -1, 0.0f, 0.35f, 0.72f, 0.0f, 0.0f, 0.0f, 1, 0, 0, 2, 1, 1);

				//deer animation
				char *anim = "creatures@deer@move";
				char *animID = "trot";

				STREAMING::REQUEST_ANIM_DICT(anim);
				while (!STREAMING::HAS_ANIM_DICT_LOADED(anim))
					WAIT(0);

				AI::TASK_PLAY_ANIM(createdPED, anim, animID, 8.0f, 0.0f, -1, 9, 0, 0, 0, 0);

				//charPose
				char *anim2 = "mp_safehouselost_table@";
				char *animID2 = "lost_table_negative_a";

				STREAMING::REQUEST_ANIM_DICT(anim2);
				while (!STREAMING::HAS_ANIM_DICT_LOADED(anim2))
					WAIT(0);

				AI::TASK_PLAY_ANIM(playerPed, anim2, animID2, 8.0f, 0.0f, -1, 9, 0, 0, 0, 0);

			}
			if (Menu::Option("Sit On Deer")) {
				Player player = PLAYER::PLAYER_ID();
				Ped playerPed = PLAYER::PLAYER_PED_ID();
				if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
				Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
				Hash stripper = GAMEPLAY::GET_HASH_KEY("a_c_deer");
				STREAMING::REQUEST_MODEL(stripper);
				while (!STREAMING::HAS_MODEL_LOADED(stripper))
					WAIT(0);

				int createdPED = PED::CREATE_PED(26, stripper, pos.x, pos.y, pos.z, 1, 1, 0);
				ENTITY::SET_ENTITY_INVINCIBLE(createdPED, false);
				PED::SET_PED_COMBAT_ABILITY(createdPED, 100);
				PED::SET_PED_CAN_SWITCH_WEAPON(createdPED, true);
				//				SET_ENTITY_HEADING(createdPED, 180.0f);

				ENTITY::ATTACH_ENTITY_TO_ENTITY(playerPed, createdPED, -1, 0.0f, 0.35f, 0.72f, 0.0f, 0.0f, 0.0f, 1, 0, 0, 2, 1, 1);

				//charPose
				char *anim2 = "mp_safehouselost_table@";
				char *animID2 = "lost_table_negative_a";

				STREAMING::REQUEST_ANIM_DICT(anim2);
				while (!STREAMING::HAS_ANIM_DICT_LOADED(anim2))
					WAIT(0);

				AI::TASK_PLAY_ANIM(playerPed, anim2, animID2, 8.0f, 0.0f, -1, 9, 0, 0, 0, 0);
			}
			if (Menu::Option("Ride Walking Deer")) {
				Player player = PLAYER::PLAYER_ID();
				Ped playerPed = PLAYER::PLAYER_PED_ID();
				if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
				Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
				Hash stripper = GAMEPLAY::GET_HASH_KEY("a_c_deer");
				STREAMING::REQUEST_MODEL(stripper);
				while (!STREAMING::HAS_MODEL_LOADED(stripper))
					WAIT(0);

				int createdPED = PED::CREATE_PED(26, stripper, pos.x, pos.y, pos.z, 1, 1, 0);
				ENTITY::SET_ENTITY_INVINCIBLE(createdPED, false);
				PED::SET_PED_COMBAT_ABILITY(createdPED, 100);
				PED::SET_PED_CAN_SWITCH_WEAPON(createdPED, true);
				//				SET_ENTITY_HEADING(createdPED, 180.0f);

				ENTITY::ATTACH_ENTITY_TO_ENTITY(playerPed, createdPED, -1, 0.0f, 0.35f, 0.72f, 0.0f, 0.0f, 0.0f, 1, 0, 0, 2, 1, 1);

				//deer animation
				char *anim = "creatures@deer@move";
				char *animID = "walk";

				STREAMING::REQUEST_ANIM_DICT(anim);
				while (!STREAMING::HAS_ANIM_DICT_LOADED(anim))
					WAIT(0);

				AI::TASK_PLAY_ANIM(createdPED, anim, animID, 8.0f, 0.0f, -1, 9, 0, 0, 0, 0);

				//charPose
				char *anim2 = "mp_safehouselost_table@";
				char *animID2 = "lost_table_negative_a";

				STREAMING::REQUEST_ANIM_DICT(anim2);
				while (!STREAMING::HAS_ANIM_DICT_LOADED(anim2))
					WAIT(0);

				AI::TASK_PLAY_ANIM(playerPed, anim2, animID2, 8.0f, 0.0f, -1, 9, 0, 0, 0, 0);
			}
			if (Menu::Option("Ride Cow")) {
				Player player = PLAYER::PLAYER_ID();
				Ped playerPed = PLAYER::PLAYER_PED_ID();
				if (!ENTITY::DOES_ENTITY_EXIST(playerPed)) return;
				Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
				Hash stripper = GAMEPLAY::GET_HASH_KEY("a_c_cow");
				STREAMING::REQUEST_MODEL(stripper);
				while (!STREAMING::HAS_MODEL_LOADED(stripper))
					WAIT(0);

				int createdPED = PED::CREATE_PED(26, stripper, pos.x, pos.y, pos.z, 1, 1, 0);
				ENTITY::SET_ENTITY_INVINCIBLE(createdPED, false);
				PED::SET_PED_COMBAT_ABILITY(createdPED, 100);
				PED::SET_PED_CAN_SWITCH_WEAPON(createdPED, true);
				//				SET_ENTITY_HEADING(createdPED, 180.0f);

				ENTITY::ATTACH_ENTITY_TO_ENTITY(playerPed, createdPED, -1, 0.0f, 0.35f, 0.72f, 0.0f, 0.0f, 0.0f, 1, 0, 0, 2, 1, 1);

				//charPose
				char *anim2 = "mp_safehouselost_table@";
				char *animID2 = "lost_table_negative_a";

				STREAMING::REQUEST_ANIM_DICT(anim2);
				while (!STREAMING::HAS_ANIM_DICT_LOADED(anim2))
					WAIT(0);

				AI::TASK_PLAY_ANIM(playerPed, anim2, animID2, 8.0f, 0.0f, -1, 9, 0, 0, 0, 0);
			}
		}
		break;



#pragma region Weather Options
		case weatheroptions:
		{
			Menu::Title("Star");
			Menu::Break("Weather Options");
			if (Menu::Option("Sunny")) { GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("Clear"); }
			if (Menu::Option("Rain")) { GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("Clearing"); }
			if (Menu::Option("Xmas")) { GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("Xmas"); }
			if (Menu::Option("Thunder")) { GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("Thunder"); }
			if (Menu::Option("Blizzard")) { GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("Blizzard"); }
			if (Menu::Option("Overcast")) { GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("Overcast"); }
			if (Menu::Option("Foggy")) { GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("Foggy"); }
			if (Menu::Option("Smog")) { GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("Smog"); }
			if (Menu::Option("Clouds")) { GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("Clouds"); }

		}
		break;
#pragma endregion

#pragma region Network
		case playerlist:
		{
			Menu::Title("Star");
			Menu::Break("Playerlist");
			for (int i = 0; i < 32; ++i)
			{
				if (ENTITY::DOES_ENTITY_EXIST(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i)))
					Menu::MenuOption(PLAYER::GET_PLAYER_NAME(i), playermenu) ? selectedPlayer = i : NULL;
			}	
		}
		    
		break;
#pragma endregion

#pragma region Recovery
		case recoverymenu:
		{
			Menu::Title("Star");
			Menu::Break("Recovery");
			Menu::MenuOption("Drop", dropss);
			Menu::MenuOption("Stats", stats);
		
		}

		break;
#pragma endregion

#pragma region Cash Dropp
		case dropss:
		{
			Menu::Title("Star");
			Menu::Break("Drop");
			Menu::Toggle("Money Drop", CashDropStar);
			Menu::Toggle("Drop Circle", CircleDropp);

		
					
		}
			break;
#pragma endregion

#pragma region Protection
		case protection:
		{
			Menu::Title("Star");
			Menu::Break("Protection");
			Menu::Toggle("Hide Name", RiskyOptins);
		}
		break;
#pragma endregion

#pragma region Stats
		case stats:
		{
			Menu::Title("Star");
			Menu::Break("Stats");
			if (Menu::Option("~w~Set Money earn in Jobs")) {
				int val = NumberKeyboard();
				STATS::STAT_SET_INT($("MPPLY_TOTAL_EVC"), val, 1);
			}

			if (Menu::Option("~w~Set total earned money")) {
				int temp1 = 0;
				temp1 = NumberKeyboard();
				STATS::STAT_SET_INT($("MPPLY_TOTAL_EVC"), temp1, 1);
			}

			if (Menu::Option("~w~Set Report Strength")) {
				int val = NumberKeyboard();
				STATS::STAT_SET_INT($("MPPLY_REPORT_STRENGTH"), val, 1);
			}

			if (Menu::Option("Custom Deaths")) {
				int val = NumberKeyboard();
				STATS::STAT_SET_INT($("MPPLY_DEATHS_PLAYER"), val, 1);
			}


			if (Menu::Option("~w~Set Commend Strength")) {
				int val = NumberKeyboard();
				STATS::STAT_SET_INT($("MPPLY_COMMEND_STRENGTH"), val, 1);
			}


			if (Menu::Option("~w~Set Friendly Stuff")) {
				int val = NumberKeyboard();
				STATS::STAT_SET_INT($("MPPLY_FRIENDLY"), val, 1);
			}


			if (Menu::Option("~w~Set Helpfull Stuff")) {
				int val = NumberKeyboard();
				STATS::STAT_SET_INT($("MPPLY_HELPFUL"), val, 1);
			}

			if (Menu::Option("~w~Set Griefing")) {
				int val = NumberKeyboard();
				STATS::STAT_SET_INT($("MPPLY_GRIEFING"), val, 1);
			}


			if (Menu::Option("~w~Set Offensive Language")) {
				int val = NumberKeyboard();
				STATS::STAT_SET_INT($("MPPLY_OFFENSIVE_LANGUAGE"), val, 1);
			}


			if (Menu::Option("~w~Set Offensive UGC")) {
				int val = NumberKeyboard();
				STATS::STAT_SET_INT($("MPPLY_OFFENSIVE_UGC"), val, 1);
			}


			if (Menu::Option("~w~Set VC Hate")) {
				int val = NumberKeyboard();
				STATS::STAT_SET_INT($("MPPLY_VC_HATE"), val, 1);
			}


			if (Menu::Option("~w~Set Gameplay Exploits")) {
				int val = NumberKeyboard();
				STATS::STAT_SET_INT($("MPPLY_GAME_EXPLOITS"), val, 1);
			}


			if (Menu::Option("~w~Set Inspunished")) {
				int val = NumberKeyboard();
				STATS::STAT_SET_INT($("MPPLY_ISPUNISHED"), val, 1);
			}


			if (Menu::Option("~w~Set Badsports")) {
				int val = NumberKeyboard();
				STATS::STAT_SET_INT($("BADSPORT_NUMDAYS_1ST_OFFENCE"), val, 1);
				STATS::STAT_SET_INT($("BADSPORT_NUMDAYS_2ND_OFFENCE"), val, 1);
				STATS::STAT_SET_INT($("BADSPORT_NUMDAYS_3RD_OFFENCE"), val, 1);
				STATS::STAT_SET_INT($("BADSPORT_NUMDAYS_4TH_OFFENCE"), val, 1);
				STATS::STAT_SET_INT($("BADSPORT_NUMDAYS_5TH_OFFENCE"), val, 1);
				STATS::STAT_SET_INT($("BADSPORT_NUMDAYS_6TH_OFFENCE"), val, 1);
				STATS::STAT_SET_INT($("BADSPORT_NUMDAYS_7TH_OFFENCE"), val, 1);
				STATS::STAT_SET_INT($("BADSPORT_NUMDAYS_8TH_OFFENCE"), val, 1);
				STATS::STAT_SET_INT($("BADSPORT_NUMDAYS_9TH_OFFENCE"), val, 1);
				STATS::STAT_SET_INT($("BADSPORT_NUMDAYS_10TH_OFFENCE"), val, 1);
				STATS::STAT_SET_INT($("BADSPORT_NUMDAYS_1ST_OFFENCE"), val, 1);
				STATS::STAT_SET_INT($("BADSPORT_NUMDAYS_2ND_OFFENCE"), val, 1);
				STATS::STAT_SET_INT($("BADSPORT_NUMDAYS_3RD_OFFENCE"), val, 1);
				STATS::STAT_SET_INT($("BADSPORT_NUMDAYS_4TH_OFFENCE"), val, 1);
				STATS::STAT_SET_INT($("BADSPORT_NUMDAYS_5TH_OFFENCE"), val, 1);
				STATS::STAT_SET_INT($("BADSPORT_NUMDAYS_6TH_OFFENCE"), val, 1);
				STATS::STAT_SET_INT($("BADSPORT_NUMDAYS_7TH_OFFENCE"), val, 1);
				STATS::STAT_SET_INT($("BADSPORT_NUMDAYS_8TH_OFFENCE"), val, 1);
				STATS::STAT_SET_INT($("BADSPORT_NUMDAYS_9TH_OFFENCE"), val, 1);
				STATS::STAT_SET_INT($("BADSPORT_NUMDAYS_11TH_OFFENCE"), val, 1);
				STATS::STAT_SET_INT($("BADSPORT_NUMDAYS_1ST_OFFENCE"), val, 1);
				STATS::STAT_SET_INT($("BADSPORT_NUMDAYS_2ND_OFFENCE"), val, 1);
				STATS::STAT_SET_INT($("BADSPORT_NUMDAYS_3RD_OFFENCE"), val, 1);
				STATS::STAT_SET_INT($("BADSPORT_NUMDAYS_4TH_OFFENCE"), val, 1);
				STATS::STAT_SET_INT($("BADSPORT_NUMDAYS_5TH_OFFENCE"), val, 1);
				STATS::STAT_SET_INT($("BADSPORT_NUMDAYS_6TH_OFFENCE"), val, 1);
				STATS::STAT_SET_INT($("BADSPORT_NUMDAYS_7TH_OFFENCE"), val, 1);
				STATS::STAT_SET_INT($("BADSPORT_NUMDAYS_8TH_OFFENCE"), val, 1);
				STATS::STAT_SET_INT($("BADSPORT_NUMDAYS_9TH_OFFENCE"), val, 1);
				STATS::STAT_SET_INT($("BADSPORT_NUMDAYS_11TH_OFFENCE"), val, 1);
				STATS::STAT_SET_INT($("BADSPORT_NUMDAYS_1ST_OFFENCE"), val, 1);
				STATS::STAT_SET_INT($("BADSPORT_NUMDAYS_2ND_OFFENCE"), val, 1);
				STATS::STAT_SET_INT($("BADSPORT_NUMDAYS_3RD_OFFENCE"), val, 1);
				STATS::STAT_SET_INT($("BADSPORT_NUMDAYS_4TH_OFFENCE"), val, 1);
				STATS::STAT_SET_INT($("BADSPORT_NUMDAYS_5TH_OFFENCE"), val, 1);
				STATS::STAT_SET_INT($("BADSPORT_NUMDAYS_6TH_OFFENCE"), val, 1);
				STATS::STAT_SET_INT($("BADSPORT_NUMDAYS_7TH_OFFENCE"), val, 1);
				STATS::STAT_SET_INT($("BADSPORT_NUMDAYS_8TH_OFFENCE"), val, 1);
				STATS::STAT_SET_INT($("BADSPORT_NUMDAYS_9TH_OFFENCE"), val, 1);
				STATS::STAT_SET_INT($("BADSPORT_NUMDAYS_11TH_OFFENCE"), val, 1);
				STATS::STAT_SET_FLOAT($("BADSPORT_RESET_MINUTES"), val, 1);
				STATS::STAT_SET_FLOAT($("BADSPORT_RESET_MINUTES"), val, 1);
				STATS::STAT_SET_FLOAT($("MPPLY_OVERALL_BADSPORT"), val, 1);
				STATS::STAT_SET_BOOL($("MPPLY_CHAR_IS_BADSPORT"), val, 1);
				STATS::STAT_SET_INT($("MPPLY_BECAME_BADSPORT_NUM"), val, 1);
				STATS::STAT_SET_INT($("BAD_SPORT_BITSET"), val, 1);
				STATS::STAT_SET_INT($("CHEAT_BITSET"), val, 1);



			}



			if (Menu::Option("Set Kills")) {
				int val = NumberKeyboard();
				STATS::STAT_SET_INT($("MPPLY_KILLS_PLAYERS"), val, 1);
			}

			if (Menu::Option("Set Won Races")) {
				int val = NumberKeyboard();
				STATS::STAT_SET_INT($("AWD_RACES_WON"), val, 1);
				STATS::STAT_SET_INT($("AWD_FM_GTA_RACES_WON"), val, 1);
			}
			if (Menu::Option("Set Armwrestling Wins")) {
				int val = NumberKeyboard();
				STATS::STAT_SET_INT($("AWD_NO_ARMWRESTLING_WINS"), val, 1);
			}
			if (Menu::Option("Set Deathmatch Wins")) {
				int val = NumberKeyboard();
				STATS::STAT_SET_INT($("AWD_FM_DM_WINS"), val, 1);
				STATS::STAT_SET_INT($("AWD_FM_DM_WINS"), val, 1);
				STATS::STAT_SET_INT($("AWD_FM_TDM_WINS"), val, 1);
			}
			if (Menu::Option("Set Deathmatch Losses")) {
				int val = NumberKeyboard();
				STATS::STAT_SET_INT($("MPPLY_TOTAL_DEATHMATCH_LOST"), val, 1);
			}
			if (Menu::Option("Set Death Match Kills")) {
				int val = NumberKeyboard();
				STATS::STAT_SET_INT($("AWD_FM_DM_TOTALKILLS"), val, 1);
			}


			if (Menu::Option("Set Death Match Deaths")) {
				int val = NumberKeyboard();
				STATS::STAT_SET_INT($("MPPLY_DM_TOTAL_DEATHS"), val, 1);
			}
			if (Menu::Option("Set Death Match Deaths")) {
				int val = NumberKeyboard();
				STATS::STAT_SET_INT($("MPPLY_DM_TOTAL_DEATHS"), val, 1);
			}
			if (Menu::Option("Set Golf Wins")) {
				int val = NumberKeyboard();
				STATS::STAT_SET_INT($("AWD_FM_GOLF_WON"), val, 1);
			}
			if (Menu::Option("Set Shooting Range Wins")) {
				int val = NumberKeyboard();
				STATS::STAT_SET_INT($("AWD_FM_SHOOTRANG_TG_WON"), val, 1);
				STATS::STAT_SET_INT($("AWD_FM_SHOOTRANG_RT_WON"), val, 1);
				STATS::STAT_SET_INT($("AWD_FM_SHOOTRANG_CT_WON"), val, 1);
				STATS::STAT_SET_INT($("AWD_FM_SHOOTRANG_GRAN_WON"), val, 1);
			}
			if (Menu::Option("Set Tennis Wins")) {
				int val = NumberKeyboard();
				STATS::STAT_SET_INT($("AWD_FM_TENNIS_WON"), val, 1);
				STATS::STAT_SET_INT($("MPPLY_TENNIS_MATCHES_WON"), val, 1);
			}
			if (Menu::Option("Weapons")) {
				int val = NumberKeyboard();

				STATS::STAT_SET_INT($("MOLOTOV_ENEMY_KILLS"), val, 1);
				STATS::STAT_SET_INT($("CMBTPISTOL_ENEMY_KILLS"), val, 1);
				STATS::STAT_SET_INT($("PISTOL50_ENEMY_KILLS"), val, 1);
				STATS::STAT_SET_INT($("APPISTOL_ENEMY_KILLS"), val, 1);
				STATS::STAT_SET_INT($("MICROSMG_ENEMY_KILLS"), val, 1);
				STATS::STAT_SET_INT($("SMG_ENEMY_KILLS"), val, 1);
				STATS::STAT_SET_INT($("ASLTSMG_ENEMY_KILLS"), val, 1);
				STATS::STAT_SET_INT($("ASLTRIFLE_ENEMY_KILLS"), val, 1);
				STATS::STAT_SET_INT($("CRBNRIFLE_ENEMY_KILLS"), val, 1);
				STATS::STAT_SET_INT($("ADVRIFLE_ENEMY_KILLS"), val, 1);
				STATS::STAT_SET_INT($("MG_ENEMY_KILLS"), val, 1);
				STATS::STAT_SET_INT($("CMBTMG_ENEMY_KILLS"), val, 1);
				STATS::STAT_SET_INT($("ASLTMG_ENEMY_KILLS"), val, 1);
				STATS::STAT_SET_INT($("PUMP_ENEMY_KILLS"), val, 1);
				STATS::STAT_SET_INT($("SAWNOFF_ENEMY_KILLS"), val, 1);
				STATS::STAT_SET_INT($("BULLPUP_ENEMY_KILLS"), val, 1);
				STATS::STAT_SET_INT($("ASLTSHTGN_ENEMY_KILLS"), val, 1);
				STATS::STAT_SET_INT($("SNIPERRFL_ENEMY_KILLS"), val, 1);
				STATS::STAT_SET_INT($("HVYSNIPER_ENEMY_KILLS"), val, 1);
				STATS::STAT_SET_INT($("GRNLAUNCH_ENEMY_KILLS"), val, 1);
				STATS::STAT_SET_INT($("RPG_ENEMY_KILLS"), val, 1);
				STATS::STAT_SET_INT($("MINIGUNS_ENEMY_KILLS"), val, 1);
				STATS::STAT_SET_INT($("GRENADE_ENEMY_KILLS"), val, 1);
				STATS::STAT_SET_INT($("SMKGRENADE_ENEMY_KILLS"), val, 1);
				STATS::STAT_SET_INT($("STKYBMB_ENEMY_KILLS"), val, 1);
				STATS::STAT_SET_INT($("MOLOTOV_ENEMY_KILLS"), val, 1);
			}
			
		}
		break;
#pragma endregion

#pragma region Player
		case playermenu:
		{
			Menu::Title("Star");
			Menu::Break(PLAYER::GET_PLAYER_NAME(selectedPlayer));

			Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer), false);
			GRAPHICS::DRAW_MARKER(29, coords.x, coords.y, coords.z + 1.3f, 0, 0, 0, 0, 180, 0, 1, 1, 1, 0, 255, 255, 200, 1, 1, 1, 0, 0, 0, 0);
		}
		if (Menu::Option("Teleport to Player"))
		{
			TeleportToClient(PLAYER::GET_PLAYER_PED(selectedPlayer));
			STREAMING::REQUEST_NAMED_PTFX_ASSET("scr_rcbarry2");
			GRAPHICS::_SET_PTFX_ASSET_NEXT_CALL("scr_rcbarry2");
			GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY("scr_clown_appears", PLAYER::PLAYER_PED_ID(), 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 1.0, false, false, false);
		}
		if (Menu::Option("Teleport in Vehicle"))
		{
			if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::GET_PLAYER_PED(selectedPlayer), true))
			{
				PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), PED::GET_VEHICLE_PED_IS_USING(PLAYER::GET_PLAYER_PED(selectedPlayer)), VEHICLE::IS_VEHICLE_SEAT_FREE(PED::GET_VEHICLE_PED_IS_USING(PLAYER::GET_PLAYER_PED(selectedPlayer)), -1));
			}
		}
		if (Menu::Option("Kick him out of Car")) 
		{
			Ped playerPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer);
			RequestControlOfEnt(playerPed);
			AI::CLEAR_PED_TASKS_IMMEDIATELY(playerPed);
			AI::CLEAR_PED_TASKS(playerPed);
			AI::CLEAR_PED_SECONDARY_TASK(playerPed);
		}
		if (Menu::Option("Explode him")) {
			Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer), false);
			FIRE::ADD_EXPLOSION(coords.x, coords.y, coords.z, 0, 1000.f, true, false, 1000.f);
		}
		if (Menu::Option("Airstrike Player")) {
			Ped selectedplayer = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer);
			Ped playerPed = PLAYER::PLAYER_PED_ID();
			Vector3 coords = ENTITY::GET_ENTITY_COORDS(selectedplayer, 1);
			Hash airStrike = GAMEPLAY::GET_HASH_KEY("WEAPON_AIRSTRIKE_ROCKET");
			WEAPON::REQUEST_WEAPON_ASSET(airStrike, 31, false);
			while (!WEAPON::HAS_WEAPON_ASSET_LOADED(airStrike))
				WAIT(0);
			GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords.x, coords.y, coords.z + 50.f, coords.x, coords.y, coords.z, 250, 1, airStrike, playerPed, 1, 0, -1.0);
		}
		if (Menu::Option("Spawn Bodyguard")) 
		{
			Ped selectedplayer = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer);
			if (!ENTITY::DOES_ENTITY_EXIST(selectedplayer)) return;
			Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_RAILGUN");
			Vector3 pos = ENTITY::GET_ENTITY_COORDS(selectedplayer, 1);
			Hash pedm = GAMEPLAY::GET_HASH_KEY("u_m_m_jesus_01");
			STREAMING::REQUEST_MODEL(pedm);
			while (!STREAMING::HAS_MODEL_LOADED(pedm))
				WAIT(0);
			int my_group = PLAYER::GET_PLAYER_GROUP(selectedplayer);
			clone[gcount] = PED::CREATE_PED(26, pedm, pos.x + rand() % 1, pos.y + rand() % 1, pos.z + 1, 0, 1, 1);
			PED::SET_PED_AS_GROUP_LEADER(selectedplayer, my_group);
			PED::SET_PED_AS_GROUP_MEMBER(clone[gcount], my_group);
			PED::SET_PED_NEVER_LEAVES_GROUP(clone[gcount], my_group);
			ENTITY::SET_ENTITY_INVINCIBLE(clone[gcount], false);
			PED::SET_PED_COMBAT_ABILITY(clone[gcount], 100);
			WEAPON::GIVE_WEAPON_TO_PED(clone[gcount], railgun, railgun, 9999, 9999);
			PED::SET_PED_CAN_SWITCH_WEAPON(clone[gcount], true);
			PED::SET_GROUP_FORMATION(my_group, 3);
			PED::SET_PED_MAX_HEALTH(clone[gcount], 5000);
			gcount++;
		}
		if (Menu::Option("Spawn Enemy")) 
		{
			Ped selectedplayer = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer);
			if (!ENTITY::DOES_ENTITY_EXIST(selectedplayer)) return;
			Hash railgun = GAMEPLAY::GET_HASH_KEY("WEAPON_RAILGUN");
			Vector3 pos = ENTITY::GET_ENTITY_COORDS(selectedplayer, 1);
			Hash pedm = GAMEPLAY::GET_HASH_KEY("u_m_m_jesus_01");
			STREAMING::REQUEST_MODEL(pedm);
			while (!STREAMING::HAS_MODEL_LOADED(pedm))
				WAIT(0);
			eclone[egcount] = PED::CREATE_PED(26, pedm, pos.x + rand() % 1, pos.y + rand() % 1, pos.z + 1, 0, 1, 1);
			ENTITY::SET_ENTITY_INVINCIBLE(eclone[egcount], false);
			PED::SET_PED_COMBAT_ABILITY(eclone[egcount], 100);
			WEAPON::GIVE_WEAPON_TO_PED(eclone[egcount], railgun, railgun, 9999, 9999);
			PED::SET_PED_CAN_SWITCH_WEAPON(eclone[egcount], true);
			AI::TASK_COMBAT_PED(eclone[egcount], selectedplayer, 1, 1);
			PED::SET_PED_ALERTNESS(eclone[egcount], 1000);
			PED::SET_PED_COMBAT_RANGE(eclone[egcount], 1000);
			egcount++;
		}
		if (Menu::Option("~r~Cage Player")) {
			trapcage(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer));
		}
		Menu::Break("Drop");
		Menu::Toggle("Give Him Moneygun", GiveMoneyGunn);
		Menu::Toggle("Fire Loop Him", GiveFireLoopp);
		Menu::Toggle("Money Bag", NewDropp5);
		Menu::Toggle("Alien Egg (2k)", NewDropp6);
		Menu::Toggle("Xmas Tree", NewDropp7);
		Menu::Toggle("Rain 2.5k", RainMoneyyy);

		if (Menu::Option("Drop Armor")) 
		{
			Ped selectedplayer = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer);
			if (!ENTITY::DOES_ENTITY_EXIST(selectedplayer)) return;
			Vector3 pos = ENTITY::GET_ENTITY_COORDS(selectedplayer, 1);
			OBJECT::pockup(1274757841, pos.x, pos.y, pos.z + 1.5, 0, 100000, 1, 0, 1);
		}
		if (Menu::Option("Drop Parachute")) 
		{
			Ped selectedplayer = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer);
			if (!ENTITY::DOES_ENTITY_EXIST(selectedplayer)) return;
			Vector3 pos = ENTITY::GET_ENTITY_COORDS(selectedplayer, 1);
			OBJECT::pockup(1735599485, pos.x, pos.y, pos.z + 1.5, 0, 100000, 1, 0, 1);
		}
		if (Menu::Option("Drop Snack")) 
		{
			Ped selectedplayer = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(selectedPlayer);
			if (!ENTITY::DOES_ENTITY_EXIST(selectedplayer)) return;
			Vector3 pos = ENTITY::GET_ENTITY_COORDS(selectedplayer, 1);
			OBJECT::pockup(483577702, pos.x, pos.y, pos.z + 1.5, 0, 100000, 1, 0, 1);
		}
		break;
#pragma endregion

#pragma region Online Options
		case onlineoptions:
		{
			Menu::Title("Star");
			Menu::Break("Online Options");
			if (Menu::Option("~w~Valkyrie Cannon All Player"))
			{

				for (int i = 0; i < 32; i++)
				{
					int excludeMe = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i);
					if (excludeMe > 0 && excludeMe != PLAYER::PLAYER_PED_ID())
					{

						Ped iPed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i);
						Ped playerPed = PLAYER::PLAYER_PED_ID();
						Vector3 playerPosition = ENTITY::GET_ENTITY_COORDS(iPed, FALSE);
						FIRE::ADD_EXPLOSION(playerPosition.x, playerPosition.y, playerPosition.z - 1, 38, 0.5f, true, false, 0.0f);
					}

				}
			}
			if (Menu::Option("~r~Cage All Player"))
			{
				for (int i = 1; i <= 32; i++)
				{
					if (PLAYER::PLAYER_ID() != i)
					{
						Vector3 remotePos = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i), 0);
						Object obj = OBJECT::CREATE_OBJECT($("prop_gold_cont_01"), remotePos.x, remotePos.y, remotePos.z - 1.f, true, false, false);
					}
				}
			}
			if (Menu::Option("Kick All From Car")) {
				for (int i = 0; i < 32; i++)
				{
					if (i != PLAYER::PLAYER_ID())
					{
						RequestControlOfEnt(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i));
						AI::CLEAR_PED_TASKS_IMMEDIATELY(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i));
						AI::CLEAR_PED_TASKS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i));
						AI::CLEAR_PED_SECONDARY_TASK(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i));
					}
				}
			}

			if (Menu::Option("Explode All"))
			{
				for (int i = 0; i < 32; i++)
				{
					int excludeMe = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i);
					if (excludeMe > 0 && excludeMe != PLAYER::PLAYER_PED_ID())
					{
						if (PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i) == PLAYER::PLAYER_PED_ID()) continue;
						{
							Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i), false);
							FIRE::ADD_EXPLOSION(coords.x, coords.y, coords.z, 0, 1000.f, true, false, 100.f); //patched
						}
					}
				}
			}
			if (Menu::Option("Clone All Player"))
			{
				for (int i = 0; i < 32; i++)
				{
					int excludeMe = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i);
					if (excludeMe > 0 && excludeMe != PLAYER::PLAYER_PED_ID())
					{

						PED::CLONE_PED(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i), 1, 1, 1);

					}
				}
			}
		}
		break;
#pragma endregion

#pragma region Vehicle Menu
		case vehicle:
		{
			Menu::Title("Star");
			Menu::Break("Vehicle");
			Menu::MenuOption("~r~Vehicle Options", vehicleoptions);
			Menu::Break("Spawner");
			if (Menu::Option("Spawn by name")) 
			{
				GAMEPLAY::DISPLAY_ONSCREEN_KEYBOARD(true, "", "", "", "", "", "", 100);
				while (GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD() == 0) WAIT(0);
				autovehi(GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT());
			}
			Menu::MenuOption("Supersport", super);
			Menu::MenuOption("Sport Classic", sportclassic);
			Menu::MenuOption("Sport", sport);
			Menu::MenuOption("Muscle", muscle);
			Menu::MenuOption("Motorcycles", motorcycles);
			Menu::MenuOption("Planes", planes);
			Menu::MenuOption("Helicopters", helicopters);
			Menu::MenuOption("Boats", boats);
			Menu::MenuOption("Military", military);
			Menu::MenuOption("Trolls", troll);
		}
		break;
#pragma endregion

#pragma region Vehicle Options
		case vehicleoptions:
		{
			Menu::Title("Star");
			Menu::Break("Vehicle Options");
			Menu::Toggle("Rainbow Car", Rainbowpaint);
			Menu::Toggle("Hornboost", hornboostt);
			Menu::Break("<==========>");
			Menu::MenuOption("Movement", carmovement);
			Menu::Break("Car");
			if (Menu::Option("Max Vehicle"))
			{
				int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				MaxUpgrades(VehID);
			}
			if (Menu::Option("Fix Vehicle"))
			{
				uint Vehicle = PED::GET_VEHICLE_PED_IS_USING(PLAYER::GET_PLAYER_PED(PLAYER::PLAYER_ID()));
				VEHICLE::SET_VEHICLE_FIXED(Vehicle);
				VEHICLE::SET_VEHICLE_DEFORMATION_FIXED(Vehicle);
				VEHICLE::SET_VEHICLE_DIRT_LEVEL(Vehicle, 0);
			}
			if (Menu::Option("~w~Custom Plate")) {
				Vehicle veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				RequestControlOfEnt(veh);
				VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(veh, CharKeyboard());
			}
			Menu::Break("Paint");
			if (Menu::Option("Chrome Paint")) {
				VEHICLE::SET_VEHICLE_COLOURS(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), 120, 120);
			}
			if (Menu::Option("Random Paint"))
			{
				int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(VehID, GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 255), GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 255), GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 255));
				VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(VehID, GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 255), GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 255), GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 255));
			}
		}
		break;
#pragma endregion

#pragma region Movement Car
		case carmovement:
		{
			Menu::Title("Star");
			Menu::Break("Movement");
			if (Menu::Option("Front Flip"))
			{
				int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
				ENTITY::APPLY_FORCE_TO_ENTITY(veh, true, 0, 0, 6.0f, 0, -2.0f, 0, true, true, true, true, false, true);
			}
			if (Menu::Option("Back Flip"))
			{
				int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
				ENTITY::APPLY_FORCE_TO_ENTITY(veh, true, 0, 0, 6.0f, 0, 2.0f, 0, true, true, true, true, false, true);
			}
			if (Menu::Option("Kick Flip"))
			{
				int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
				ENTITY::APPLY_FORCE_TO_ENTITY(veh, true, 0, 0, 5.0f, 2.0f, 0, 0, true, true, true, true, false, true);
			}
			if (Menu::Option("Heel Flip"))
			{
				int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
				ENTITY::APPLY_FORCE_TO_ENTITY(veh, true, 0, 0, 5.0f, -2.0f, 0, 0, true, true, true, true, false, true);
			}
			if (Menu::Option("Bunny Hop"))
			{
				int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
				ENTITY::APPLY_FORCE_TO_ENTITY(veh, true, 0, 0, 7.0f, 0, 0, 0, true, true, true, true, false, true);
			}
			if (Menu::Option("Launch Up"))
			{
				int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
				ENTITY::APPLY_FORCE_TO_ENTITY(veh, true, 0, 0, 40.0f, 0, 0, 0, true, true, true, true, false, true);
			}
			if (Menu::Option("Crush Vehicle"))
			{
				int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
				ENTITY::APPLY_FORCE_TO_ENTITY(veh, true, 0, 0, -40.0f, 0, 0, 0, true, true, true, true, false, true);
			}
			if (Menu::Option("Open Doors"))
			{
				VEHICLE::SET_VEHICLE_DOOR_OPEN(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), 0, true, false);
				VEHICLE::SET_VEHICLE_DOOR_OPEN(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), 1, true, false);
				VEHICLE::SET_VEHICLE_DOOR_OPEN(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), 2, true, false);
				VEHICLE::SET_VEHICLE_DOOR_OPEN(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), 3, true, false);
				VEHICLE::SET_VEHICLE_DOOR_OPEN(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), 4, true, false);
				VEHICLE::SET_VEHICLE_DOOR_OPEN(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), 5, true, false);
				VEHICLE::SET_VEHICLE_DOOR_OPEN(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), 6, true, false);
				VEHICLE::SET_VEHICLE_DOOR_OPEN(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), 7, true, false);
			}
			if (Menu::Option("Close Doors"))
			{
				VEHICLE::SET_VEHICLE_DOORS_SHUT(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), true);
			}
		}
		break;
#pragma endregion




#pragma region Supersport
		case super:
		{
			Menu::Title("Star");
			Menu::Break("Supersport");
			if (Menu::Option("Adder")) { SpawnVehicle(0xB779A091); }
			if (Menu::Option("Tempesta")) { SpawnVehicle(0x1044926F); }
			if (Menu::Option("Visione")) { SpawnVehicle(0xC4810400); }
			if (Menu::Option("Xa21")) { SpawnVehicle(0x36B4A8A9); }
			if (Menu::Option("Tezeract")) { SpawnVehicle(0x3D7C6410); }
			if (Menu::Option("Zentorno")) { SpawnVehicle(0xAC5DF515); }
			if (Menu::Option("Tyrant")) { SpawnVehicle(0xE99011C2); }
			if (Menu::Option("Sheava")) { SpawnVehicle(0x30D3F6D8); }
			if (Menu::Option("Reaper")) { SpawnVehicle(0xDF381E5); }


			
		}
		break;
#pragma endregion

#pragma region Sport Classic
		case sportclassic:
		{
			Menu::Title("Star");
			Menu::Break("Sport Classic");
			if (Menu::Option("Btype2")) { SpawnVehicle(0xCE6B35A4); }
			if (Menu::Option("Feltzer3")) { SpawnVehicle(0xA29D6D10); }
			if (Menu::Option("jb700")) { SpawnVehicle(0x3EAB5555); }
			if (Menu::Option("stinger")) { SpawnVehicle(0x5C23AF9B); }
			if (Menu::Option("ztype")) { SpawnVehicle(0x2D3BD401); }
			if (Menu::Option("ardent")) { SpawnVehicle(0x97E5533); }
			if (Menu::Option("fagaloa")) { SpawnVehicle(0x6068AD86); }
			if (Menu::Option("michelli")) { SpawnVehicle(0x3E5BD8D9); }
			if (Menu::Option("mamba")) { SpawnVehicle(0x9CFFFC56); }

			

		}
		break;
#pragma endregion

#pragma region Sport
		case sport:
		{
			Menu::Title("Star");
			Menu::Break("Sport");
			if (Menu::Option("Schlagen GT")) { SpawnVehicle(0xE1C03AB0); }
			if (Menu::Option("Seven70")) { SpawnVehicle(0x97398A4B); }
			if (Menu::Option("Zr3802")) { SpawnVehicle(0xBE11EFC6); }
			if (Menu::Option("vVrlierer 2")) { SpawnVehicle(0x41B77FA4); }
			if (Menu::Option("Specter 2")) { SpawnVehicle(0x400F5147); }
			if (Menu::Option("Ruston")) { SpawnVehicle(0x2AE524A8); }
			if (Menu::Option("Jester")) { SpawnVehicle(0xB2A716A3); }
			if (Menu::Option("Furoregt")) { SpawnVehicle(0xBF1691E0); }
			if (Menu::Option("Deveste")) { SpawnVehicle(0x5EE005DA); }



		}
		break;
#pragma endregion

#pragma region Muscle
		case muscle:
		{
			Menu::Title("Star");
			Menu::Break("Muscle");
			if (Menu::Option("Declasse Drift Yosemite"));

		}
		break;
#pragma endregion

#pragma region Motorcycles
		case motorcycles:
		{
			Menu::Title("Star");
			Menu::Break("Motorcycles");
			if (Menu::Option("Manchez")) { SpawnVehicle(-1523428744); }
			if (Menu::Option("Hexer")) { SpawnVehicle(301427732); }
			if (Menu::Option("Bati")) { SpawnVehicle(-114291515); }
			if (Menu::Option("BF400")) { SpawnVehicle(86520421); }
			if (Menu::Option("CarbonRS")) { SpawnVehicle(11251904); }
			if (Menu::Option("Cliffhanger")) { SpawnVehicle(390201602); }
			if (Menu::Option("Faggio2")) { SpawnVehicle(55628203); }
		}
		break;
#pragma endregion

#pragma region Planes
		case planes:
		{
			Menu::Title("Star");
			Menu::Break("Planes");
			if (Menu::Option("Luxor 2")) { SpawnVehicle(0xB79F589E); }
			if (Menu::Option("Lazer")) { SpawnVehicle(0xB39B0AE6); }
			if (Menu::Option("Jet")) { SpawnVehicle(0x3F119114); }
			if (Menu::Option("Volatol")) { SpawnVehicle(0x1AAD0DED); }
			if (Menu::Option("Titan")) { SpawnVehicle(0x761E2AD3); }
			if (Menu::Option("Cargoplane")) { SpawnVehicle(0x15F27762); }
			if (Menu::Option("Blimp3")) { SpawnVehicle(0xEDA4ED97); }
			if (Menu::Option("Besra")) { SpawnVehicle(0x6CBD1D6D); }
			if (Menu::Option("Hydra")) { SpawnVehicle(0x39D6E83F); }


		}
		break;
#pragma endregion

#pragma region Helicopters
		case helicopters:
		{
			Menu::Title("Star");
			Menu::Break("Helicopter");
			if (Menu::Option("Cargobob")) { SpawnVehicle(-50547061); }
			if (Menu::Option("Buzzard")) { SpawnVehicle(788747387); }
			if (Menu::Option("Skylift")) { SpawnVehicle(1044954915); }
			if (Menu::Option("Frogger")) { SpawnVehicle(744705981); }
			if (Menu::Option("Valkyrie")) { SpawnVehicle(-1600252419); }
			if (Menu::Option("Swift")) { SpawnVehicle(-339587598); }
			if (Menu::Option("Volatus")) { SpawnVehicle(-1845487887); }
		}
		break;
#pragma endregion

#pragma region Boats
		case boats:
		{
			Menu::Title("Star");
			Menu::Break("Boats");
			if (Menu::Option("Toro")) { SpawnVehicle(1070967343); }
			if (Menu::Option("Tug")) { SpawnVehicle(-2100640717); }
			if (Menu::Option("Seashark")) { SpawnVehicle(-1030275036); }
			if (Menu::Option("Marquis")) { SpawnVehicle(-1043459709); }
			if (Menu::Option("Speeder")) { SpawnVehicle(231083307); }
			if (Menu::Option("Tropic")) { SpawnVehicle(290013743); }
			if (Menu::Option("Submersible")) { SpawnVehicle(771711535); }

		}
		break;
#pragma endregion

#pragma region Military
		case military:
		{
			Menu::Title("Star");
			Menu::Break("Military");
			if (Menu::Option("Barracks")) { SpawnVehicle(-823509173); }
			if (Menu::Option("Barracks2")) { SpawnVehicle(1074326203); }
			if (Menu::Option("Barracks3")) { SpawnVehicle(630371791); }
			if (Menu::Option("Crusader")) { SpawnVehicle(321739290); }
			if (Menu::Option("Rhino")) { SpawnVehicle(782665360); }
		}
		break;
#pragma endregion

#pragma region Troll
		case troll:
		{
			Menu::Title("Star");
			Menu::Break("Troll");
			if (Menu::Option("PBus")) { SpawnVehicle(-2007026063); }
			if (Menu::Option("Tractor")) { SpawnVehicle(1641462412); }
			if (Menu::Option("Mower")) { SpawnVehicle(1783355638); }
			if (Menu::Option("FireTruck")) { SpawnVehicle(1938952078); }
			if (Menu::Option("Ambulance")) { SpawnVehicle(1171614426); }
			if (Menu::Option("Riot")) { SpawnVehicle(-1205689942); }
			if (Menu::Option("panto")) { SpawnVehicle(-431692672); }
			if (Menu::Option("police car")) { SpawnVehicle(-1627000575); }
			if (Menu::Option("Cutter")) { SpawnVehicle(-1006919392); }
			if (Menu::Option("Kalahari")) { SpawnVehicle(92612664); }
			if (Menu::Option("slamvan6")) { SpawnVehicle(0x67D52852); }
			if (Menu::Option("Dune4")) { SpawnVehicle(-827162039); }
			if (Menu::Option("Bulldozer")) { SpawnVehicle(1886712733); }

		}
		break;
#pragma endregion
			
		

#pragma region Settings Menu
		case settings:
		{
			Menu::Title("Star");
			Menu::Break("Settings");
			if (Menu::Int("Scroll Delay", Menu::Settings::keyPressDelay2, 1, 200))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
					Menu::Settings::keyPressDelay2 = NumberKeyboard();
				}
			}
			if (Menu::Int("Int Delay", Menu::Settings::keyPressDelay3, 1, 200))
			{
				if (IsKeyPressed(VK_NUMPAD5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept)) {
					Menu::Settings::keyPressDelay3 = NumberKeyboard();
				}
			}
			if (Menu::Option("MenuX plus")) {
				if (Menu::Settings::menuX < 0.81f) Menu::Settings::menuX += 0.01f;
			}
			if (Menu::Option("MenuX minus")) {
				if (Menu::Settings::menuX > 0.17f) Menu::Settings::menuX -= 0.01f;
			}
			Menu::MenuOption("~r~KILL GAME", exitgta);
		}
		break;
		case exitgta:
		{
			Menu::Title("Exit GTA V");
			if (Menu::Option("Yes")) exit(0);
		}
		break;
		
#pragma endregion
		}
		Menu::End();
		WAIT(0);
	}
}

void ScriptMain() {
	srand(GetTickCount());

	main();
}