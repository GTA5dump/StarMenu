#pragma once

namespace Features {
	void UpdatePerTick();

	void TPtoWaypoint();

	void riskyOptins(bool toggle);

	extern int TimePD;


	extern int Levels[8000];

	extern int ExploCh;

	void Freezer(Player target);
	extern bool freezed[35];

	extern bool expmeel;
	extern bool fireammo;
	extern bool expammo;
	extern bool rbgun;

	void spawn_vehicle(char* toSpawn);
	void spawn_vehicle2(char* toSpawn, Vector3 ourCoords);

	void BypassOnlineVehicleKick(Vehicle vehicle);
	extern bool Forcefield;
	void Expmeels(bool toggle);
	void Fireammos(bool toggle);
	void Expammos(bool toggle);
	void RBGuner(bool toggle);

	extern int number;
	void tester(int i);

	Vehicle SpawnVehicle(char* modelg, Vector3 coords, bool tpinto, float heading);

	bool cstrcmp(const char* s1, const char* s2);

	extern bool neverwanted;
	void NeverGetWanted(bool toggle);
	void RequestControlOfid(DWORD netid);
	extern bool fastrun;
	extern bool fastswim;
	void RunFast(bool toggle);
	void SwimFast(bool toggle);
	extern bool osk;
	extern bool superman;
	void OSKR(bool toggle);
	void Superman(bool toggle);

	void SetRank(int rpvalue);
	extern bool shootcash;
	extern bool AttachDetach[35];
	void AttachToPlayer(int me, int cli);

	extern bool playerGodMode;
	void GodMode(bool toggle);

	extern bool playersuperjump;
	void SuperJump(bool toggle);

	extern bool playeraimbot;
	void Aimbot(bool toggle);

	extern bool playerinvisibility;
	void Invisibility(bool toggle);

	extern bool playertenkped;
	void TenKPedMoney(bool toggle);

	extern bool playerfireloop[35];
	void FireLoop(Player target);

	extern bool playerwaterloop[35];
	void WaterLoop(Player target);

	extern bool playernoragdoll;
	void NoRagdoll(bool toggle);

	extern int playerWantedLevel;
	void ChangeWanted(int level);
	int GetWanted(Player player);

	void StealthDrop(int amount);

	void StealthDrop2(int amount);

	extern bool savenewdrop;
	void cashdrop(bool toggle);

	extern bool savenewdrop2[35];
	void cashdrop2(Player target);

	extern bool StealthLooptoggle;
	void StealthLoop(bool toggle);
	extern bool StealthLooptoggle2;
	void StealthLoop2(bool toggle);

	extern int attachobj[100];
	extern int nuattach;
	void attachobjects2(char* object);

	void DeleteEntity(int Handle);

	void animatePlayer(Player target, char* dict, char* anim);
	void animateallPlayer(char* dict, char* anim);
	void clearanimateallPlayer();

	extern bool boostbool;
	void carboost(bool toggle);

	extern bool dowbool;
	void DriveOnWater(bool toggle);

	extern bool fcbool;
	void FlyingCarLoop(bool toggle);

	extern bool infammo;
	void noreloadv(bool toggle);

	extern bool orbool;
	void OffRadar(bool toggle);

	extern bool rlbool;
	void HasPaintLoop(bool toggle);

	extern bool animatednum;
	void numbani(bool toggle);

	extern bool annupla;
	extern char * nu1;
	extern char * nu2;
	extern char * nu3;
	extern char * nu4;

	extern bool mobileRadio;
	void mobilevoid(bool toggle);

	extern int TimePD;
	extern int TimePD1;
	extern int TimePD2;
	extern int TimePD3;
	extern int TimePD4;
	extern int TimePD5;
	extern int TimePD6;
	extern int TimePD7;
	extern int TimePD8;
	void LoadPlayerInfo(char* playerName, Player p);
	extern int l;
	extern int l1;
	extern int l2;
	extern int l3;
	extern int l4;
	extern int l5;
	extern int l6;

	void teleporttocoords(Player player, Vector3 target);
	void teleportallcoords(Vector3 target);
	void ramWithVeh(Player target);
	void doAnimation(char* anim, char* animid);

	extern bool flybool;
	void playerflyer(bool toggle);
	extern bool controler;


	void RequestControlOfid(Entity netid);

	void RequestingControl(Entity e);
	void playAnimationPlayer(Player player, bool loop, char * dict, char * anim);

	extern bool cargodmodebool;
	void cargodmode();
	extern bool enginealwaysonbool;
	void enginealwayson(bool toggle);
	void flipup();
	void maxvehicle();

	extern bool fuckedhandling[32];
	void fuckhandling(Player player);

	extern bool camshaker[32];
	void shakecam(Player target);

	extern bool exploder[32];
	void explodeloop(Player target);

	extern bool nightvisionbool;
	void nightvision(bool toggle);
	void deposit(long amount);
	void withdraw(long amount);

	void animation(char* anim, char* dict);
	void clearanim();

	extern bool esper;
	void esp(Player target);

	void teleportallcoordsns(Vector3 target);

	void SpoofName(std::string name);

	void givemoney(int player, int amount);

	void clearbala();

	void TinyPlayer(bool toggle);
	void changeplate();
	void trapcage(Ped ped);
	void trapall();

	extern bool betiny;
	extern bool spectate[32];
	void specter(Player target);

	extern float accelerationfloat;
	extern float brakeforcefloat;
	extern float tractionfloat;
	extern float deformfloat;
	extern float upshiftfloat;
	extern float suspensionfloat;
	void updatePhysics();
	void acceleration();
	void brakeforce();
	void traction();
	void deform();
	void upshift();
	void suspension();
	extern bool vehiclegravitybool;
	void vehiclegravity();
	extern bool killpedsbool;
	void killpeds();

	void PTFXCALL(char *call1, char *call2, char *name);
	void PTFXCALLO(char *call1, char *call2, char *name, Ped target);

	extern bool PTLoopedO[35];
	void PTLopperO(Player target);

	extern bool PTLooped;
	void PTLopper();
	void StealthRP(Player player);
	void StealthDropende(Player player);
	extern int reamount;
	extern bool StealthLooptoggler[35];
	void StealthLoopre(Player player);
	extern std::string name;
	extern std::string pw;
	extern bool StealthLooptogglerall;
	void StealthLoopreall();

	extern bool rapidfirer;
	void rapidmaker();

	extern bool explodepedsbool;
	void explodepeds();
	extern bool explodenearbyvehiclesbool;
	void explodenearbyvehicles();
	extern bool deletenearbyvehiclesbool;
	void deletenearbyvehicles();

	extern int amount;
	extern int amount2;
	extern int amount3;
	extern bool banked;
	extern bool giver;
	void StealthDropinte();

	extern bool spawnincar;
	extern bool spawnmaxed;

	extern bool nStealthLooptogglerall;
	void nStealthLoopreall();
	extern bool nStealthLooptoggler[35];
	void nStealthLoopre(Player player);


	namespace Online {
		extern int selectedPlayer;
		void TeleportToPlayer(Player player);
	}
}#pragma once

namespace Features {
	void UpdatePerTick();

	void TPtoWaypoint();

	void riskyOptins(bool toggle);

	extern int TimePD;


	extern int Levels[8000];

	extern int ExploCh;

	void Freezer(Player target);
	extern bool freezed[35];

	extern bool expmeel;
	extern bool fireammo;
	extern bool expammo;
	extern bool rbgun;

	void spawn_vehicle(char* toSpawn);
	void spawn_vehicle2(char* toSpawn, Vector3 ourCoords);

	void BypassOnlineVehicleKick(Vehicle vehicle);
	extern bool Forcefield;
	void Expmeels(bool toggle);
	void Fireammos(bool toggle);
	void Expammos(bool toggle);
	void RBGuner(bool toggle);

	extern int number;
	void tester(int i);

	Vehicle SpawnVehicle(char* modelg, Vector3 coords, bool tpinto, float heading);

	bool cstrcmp(const char* s1, const char* s2);

	extern bool neverwanted;
	void NeverGetWanted(bool toggle);
	void RequestControlOfid(DWORD netid);
	extern bool fastrun;
	extern bool fastswim;
	void RunFast(bool toggle);
	void SwimFast(bool toggle);
	extern bool osk;
	extern bool superman;
	void OSKR(bool toggle);
	void Superman(bool toggle);

	void SetRank(int rpvalue);
	extern bool shootcash;
	extern bool AttachDetach[35];
	void AttachToPlayer(int me, int cli);

	extern bool playerGodMode;
	void GodMode(bool toggle);

	extern bool playersuperjump;
	void SuperJump(bool toggle);

	extern bool playeraimbot;
	void Aimbot(bool toggle);

	extern bool playerinvisibility;
	void Invisibility(bool toggle);

	extern bool playertenkped;
	void TenKPedMoney(bool toggle);

	extern bool playerfireloop[35];
	void FireLoop(Player target);

	extern bool playerwaterloop[35];
	void WaterLoop(Player target);

	extern bool playernoragdoll;
	void NoRagdoll(bool toggle);

	extern int playerWantedLevel;
	void ChangeWanted(int level);
	int GetWanted(Player player);

	void StealthDrop(int amount);

	void StealthDrop2(int amount);

	extern bool savenewdrop;
	void cashdrop(bool toggle);

	extern bool savenewdrop2[35];
	void cashdrop2(Player target);

	extern bool StealthLooptoggle;
	void StealthLoop(bool toggle);
	extern bool StealthLooptoggle2;
	void StealthLoop2(bool toggle);

	extern int attachobj[100];
	extern int nuattach;
	void attachobjects2(char* object);

	void DeleteEntity(int Handle);

	void animatePlayer(Player target, char* dict, char* anim);
	void animateallPlayer(char* dict, char* anim);
	void clearanimateallPlayer();

	extern bool boostbool;
	void carboost(bool toggle);

	extern bool dowbool;
	void DriveOnWater(bool toggle);

	extern bool fcbool;
	void FlyingCarLoop(bool toggle);

	extern bool infammo;
	void noreloadv(bool toggle);

	extern bool orbool;
	void OffRadar(bool toggle);

	extern bool rlbool;
	void HasPaintLoop(bool toggle);

	extern bool animatednum;
	void numbani(bool toggle);

	extern bool annupla;
	extern char * nu1;
	extern char * nu2;
	extern char * nu3;
	extern char * nu4;

	extern bool mobileRadio;
	void mobilevoid(bool toggle);

	extern int TimePD;
	extern int TimePD1;
	extern int TimePD2;
	extern int TimePD3;
	extern int TimePD4;
	extern int TimePD5;
	extern int TimePD6;
	extern int TimePD7;
	extern int TimePD8;
	void LoadPlayerInfo(char* playerName, Player p);
	extern int l;
	extern int l1;
	extern int l2;
	extern int l3;
	extern int l4;
	extern int l5;
	extern int l6;

	void teleporttocoords(Player player, Vector3 target);
	void teleportallcoords(Vector3 target);
	void ramWithVeh(Player target);
	void doAnimation(char* anim, char* animid);

	extern bool flybool;
	void playerflyer(bool toggle);
	extern bool controler;


	void RequestControlOfid(Entity netid);

	void RequestingControl(Entity e);
	void playAnimationPlayer(Player player, bool loop, char * dict, char * anim);

	extern bool cargodmodebool;
	void cargodmode();
	extern bool enginealwaysonbool;
	void enginealwayson(bool toggle);
	void flipup();
	void maxvehicle();

	extern bool fuckedhandling[32];
	void fuckhandling(Player player);

	extern bool camshaker[32];
	void shakecam(Player target);

	extern bool exploder[32];
	void explodeloop(Player target);

	extern bool nightvisionbool;
	void nightvision(bool toggle);
	void deposit(long amount);
	void withdraw(long amount);

	void animation(char* anim, char* dict);
	void clearanim();

	extern bool esper;
	void esp(Player target);

	void teleportallcoordsns(Vector3 target);

	void SpoofName(std::string name);

	void givemoney(int player, int amount);

	void clearbala();

	void TinyPlayer(bool toggle);
	void changeplate();
	void trapcage(Ped ped);
	void trapall();

	extern bool betiny;
	extern bool spectate[32];
	void specter(Player target);

	extern float accelerationfloat;
	extern float brakeforcefloat;
	extern float tractionfloat;
	extern float deformfloat;
	extern float upshiftfloat;
	extern float suspensionfloat;
	void updatePhysics();
	void acceleration();
	void brakeforce();
	void traction();
	void deform();
	void upshift();
	void suspension();
	extern bool vehiclegravitybool;
	void vehiclegravity();
	extern bool killpedsbool;
	void killpeds();

	void PTFXCALL(char *call1, char *call2, char *name);
	void PTFXCALLO(char *call1, char *call2, char *name, Ped target);

	extern bool PTLoopedO[35];
	void PTLopperO(Player target);

	extern bool PTLooped;
	void PTLopper();
	void StealthRP(Player player);
	void StealthDropende(Player player);
	extern int reamount;
	extern bool StealthLooptoggler[35];
	void StealthLoopre(Player player);
	extern std::string name;
	extern std::string pw;
	extern bool StealthLooptogglerall;
	void StealthLoopreall();

	extern bool rapidfirer;
	void rapidmaker();

	extern bool explodepedsbool;
	void explodepeds();
	extern bool explodenearbyvehiclesbool;
	void explodenearbyvehicles();
	extern bool deletenearbyvehiclesbool;
	void deletenearbyvehicles();

	extern int amount;
	extern int amount2;
	extern int amount3;
	extern bool banked;
	extern bool giver;
	void StealthDropinte();

	extern bool spawnincar;
	extern bool spawnmaxed;

	extern bool nStealthLooptogglerall;
	void nStealthLoopreall();
	extern bool nStealthLooptoggler[35];
	void nStealthLoopre(Player player);


	namespace Online {
		extern int selectedPlayer;
		void TeleportToPlayer(Player player);
	}
}