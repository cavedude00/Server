#ifndef EQEMU_LUA_CLIENT_H
#define EQEMU_LUA_CLIENT_H
#ifdef LUA_EQEMU

#include "lua_mob.h"

class Client;
class Lua_Group;
class Lua_Raid;
class Lua_Inventory;
class Lua_Packet;

namespace luabind {
	struct scope;
}

luabind::scope lua_register_client();
luabind::scope lua_register_inventory_where();

class Lua_Client : public Lua_Mob
{
	typedef Client NativeType;
public:
	Lua_Client() { SetLuaPtrData(nullptr); }
	Lua_Client(Client *d) { SetLuaPtrData(reinterpret_cast<Entity*>(d)); }
	virtual ~Lua_Client() { }

	operator Client*() {
		return reinterpret_cast<Client*>(GetLuaPtrData());
	}

	void SendSound();
	void Save();
	void Save(int commit_now);
	void SaveBackup();
	bool Connected();
	bool InZone();
	void Kick();
	void Disconnect();
	bool IsLD();
	void WorldKick();
	bool GetAnon();
	void Duck();
	void Stand();
	void SetGM(bool v);
	void SetPVP(bool v);
	bool GetPVP();
	bool GetGM();
	void SetBaseClass(int v);
	void SetBaseRace(int v);
	void SetBaseGender(int v);
	int GetBaseFace();
	int GetLanguageSkill(int skill_id);
	const char *GetLastName();
	int GetBaseSTR();
	int GetBaseSTA();
	int GetBaseCHA();
	int GetBaseDEX();
	int GetBaseINT();
	int GetBaseAGI();
	int GetBaseWIS();
	int GetWeight();
	uint32 GetEXP();
	uint32 GetAAExp();
	void SetDeity(int v);
	void AddEXP(uint32 add_exp);
	void AddEXP(uint32 add_exp, int conlevel);
	void AddEXP(uint32 add_exp, int conlevel, bool resexp);
	void SetEXP(uint32 set_exp, uint32 set_aaxp);
	void SetEXP(uint32 set_exp, uint32 set_aaxp, bool resexp);
	void SetBindPoint();
	void SetBindPoint(int to_zone);
	void SetBindPoint(int to_zone, float new_x);
	void SetBindPoint(int to_zone, float new_x, float new_y);
	void SetBindPoint(int to_zone, float new_x, float new_y, float new_z);
	float GetBindX();
	float GetBindX(int index);
	float GetBindY();
	float GetBindY(int index);
	float GetBindZ();
	float GetBindZ(int index);
	float GetBindHeading();
	float GetBindHeading(int index);
	uint32 GetBindZoneID();
	uint32 GetBindZoneID(int index);
	void MovePC(int zone, float x, float y, float z, float heading);
	void MovePCInstance(int zone, int instance, float x, float y, float z, float heading);
	void ChangeLastName(const char *in);
	int GetFactionLevel(uint32 char_id, uint32 npc_id, uint32 race, uint32 class_, uint32 deity, uint32 faction, Lua_NPC npc);
	void SetFactionLevel(uint32 char_id, uint32 npc_id, int char_class, int char_race, int char_deity);
	void SetFactionLevel2(uint32 char_id, int faction_id, int char_class, int char_race, int char_deity, int value, int temp);
	int GetRawItemAC();
	uint32 AccountID();
	const char *AccountName();
	int Admin();
	uint32 CharacterID();
	int GuildRank();
	uint32 GuildID();
	int GetFace();
	bool TakeMoneyFromPP(uint64 copper);
	bool TakeMoneyFromPP(uint64 copper, bool update_client);
	void AddMoneyToPP(uint32 copper, uint32 silver, uint32 gold, uint32 platinum, bool update_client);
	bool TGB();
	int GetSkillPoints();
	void SetSkillPoints(int skill);
	void IncreaseSkill(int skill_id);
	void IncreaseSkill(int skill_id, int value);
	void IncreaseLanguageSkill(int skill_id);
	void IncreaseLanguageSkill(int skill_id, int value);
	int GetRawSkill(int skill_id);
	bool HasSkill(int skill_id);
	bool CanHaveSkill(int skill_id);
	void SetSkill(int skill_id, int value);
	void AddSkill(int skill_id, int value);
	void CheckSpecializeIncrease(int spell_id);
	void CheckIncreaseSkill(int skill_id, Lua_Mob target);
	void CheckIncreaseSkill(int skill_id, Lua_Mob target, int chance_mod);
	void SetLanguageSkill(int language, int value);
	int MaxSkill(int skill_id);
	bool IsMedding();
	int GetDuelTarget();
	bool IsDueling();
	void SetDuelTarget(int c);
	void SetDueling(bool v);
	void ResetAA();
	void MemSpell(int spell_id, int slot);
	void MemSpell(int spell_id, int slot, bool update_client);
	void UnmemSpell(int slot);
	void UnmemSpell(int slot, bool update_client);
	void UnmemSpellAll();
	void UnmemSpellAll(bool update_client);
	void ScribeSpell(int spell_id, int slot);
	void ScribeSpell(int spell_id, int slot, bool update_client);
	void UnscribeSpell(int slot);
	void UnscribeSpell(int slot, bool update_client);
	void UnscribeSpellAll();
	void UnscribeSpellAll(bool update_client);
	void TrainDisc(int itemid);
	void UntrainDisc(int slot);
	void UntrainDisc(int slot, bool update_client);
	void UntrainDiscAll();
	void UntrainDiscAll(bool update_client);
	bool IsSitting();
	void SetFeigned(bool v);
	bool GetFeigned();
	bool AutoSplitEnabled();
	void SetHorseId(int id);
	int GetHorseId();
	void NukeItem(uint32 item_num);
	void NukeItem(uint32 item_num, int where_to_check);
	void SetTint(int slot_id, uint32 color);
	void SetMaterial(int slot_id, uint32 item_id);
	void Undye();
	int GetItemIDAt(int slot_id);
	void DeleteItemInInventory(int slot_id, int quantity);
	void DeleteItemInInventory(int slot_id, int quantity, bool update_client);
	void SummonItem(uint32 item_id);
	void SummonItem(uint32 item_id, int charges);
	void SummonItem(uint32 item_id, int charges, uint32 aug1);
	void SummonItem(uint32 item_id, int charges, uint32 aug1, uint32 aug2);
	void SummonItem(uint32 item_id, int charges, uint32 aug1, uint32 aug2, uint32 aug3);
	void SummonItem(uint32 item_id, int charges, uint32 aug1, uint32 aug2, uint32 aug3, uint32 aug4);
	void SummonItem(uint32 item_id, int charges, uint32 aug1, uint32 aug2, uint32 aug3, uint32 aug4, uint32 aug5);
	void SummonItem(uint32 item_id, int charges, uint32 aug1, uint32 aug2, uint32 aug3, uint32 aug4, uint32 aug5, 
		bool attuned);
	void SummonItem(uint32 item_id, int charges, uint32 aug1, uint32 aug2, uint32 aug3, uint32 aug4, uint32 aug5, 
		bool attuned, int to_slot);
	void SetStats(int type, int value);
	void IncStats(int type, int value);
	void DropItem(int slot_id);
	void BreakInvis();
	void LeaveGroup();
	bool IsGrouped();
	bool IsRaidGrouped();
	bool Hungry();
	bool Thirsty();
	int GetInstrumentMod(int spell_id);
	bool DecreaseByID(uint32 type, int amt);
	void Escape();
	void GoFish();
	void ForageItem();
	void ForageItem(bool guarantee);
	float CalcPriceMod(Lua_Mob other, bool reverse);
	void ResetTrade();
	bool UseDiscipline(int spell_id, int target_id);
	int GetCharacterFactionLevel(int faction_id);
	void SetZoneFlag(int zone_id);
	void ClearZoneFlag(int zone_id);
	bool HasZoneFlag(int zone_id);
	void SendZoneFlagInfo(Lua_Client to);
	void SetAATitle(const char *title);
	int GetClientVersion();
	uint32 GetClientVersionBit();
	void SetTitleSuffix(const char *text);
	void SetAAPoints(int points);
	int GetAAPoints();
	int GetSpentAA();
	void AddAAPoints(int points);
	void RefundAA();
	int GetModCharacterFactionLevel(int faction);
	int GetStartZone();
	void SetStartZone(int zone_id);
	void SetStartZone(int zone_id, float x);
	void SetStartZone(int zone_id, float x, float y);
	void SetStartZone(int zone_id, float x, float y, float z);
	void KeyRingAdd(uint32 item);
	bool KeyRingCheck(uint32 item);
	void QuestReadBook(const char *text, int type);
	uint32 GetGroupPoints();
	uint32 GetRaidPoints();
	void LearnRecipe(uint32 recipe);
	int GetEndurance();
	int GetMaxEndurance();
	int GetEndurancePercent();
	void SetEndurance(int endur);
	void SendOPTranslocateConfirm(Lua_Mob caster, int spell_id);
	uint32 GetIP();
	void AddLevelBasedExp(int exp_pct);
	void AddLevelBasedExp(int exp_pct, int max_level);
	void IncrementAA(int aa);
	int GetNextAvailableSpellBookSlot();
	int GetNextAvailableSpellBookSlot(int start);
	int FindSpellBookSlotBySpellID(int spell_id);
	int GetCorpseCount();
	int GetCorpseID(int corpse);
	int GetCorpseItemAt(int corpse, int slot);
	void AssignToInstance(int instance_id);
	void Freeze();
	void UnFreeze();
	int GetAggroCount();
	uint64 GetCarriedMoney();
	uint64 GetAllMoney();
	void Signal(uint32 id);
	bool HasSpellScribed(int spell_id);
	void SetAccountFlag(std::string flag, std::string val);
	std::string GetAccountFlag(std::string flag);
	Lua_Group GetGroup();
	Lua_Raid GetRaid();
	bool PutItemInInventory(int slot_id, Lua_ItemInst inst);
	bool PushItemOnCursor(Lua_ItemInst inst);
	Lua_Inventory GetInventory();
	void SendItemScale(Lua_ItemInst inst);
	void QueuePacket(Lua_Packet app);
	void QueuePacket(Lua_Packet app, bool ack_req);
	void QueuePacket(Lua_Packet app, bool ack_req, int client_connection_status);
	void QueuePacket(Lua_Packet app, bool ack_req, int client_connection_status, int filter);
	int GetHunger();
	int GetThirst();
	void SetHunger(int in_hunger);
	void SetThirst(int in_thirst);
	void SetConsumption(int in_hunger, int in_thirst);
	void SendMarqueeMessage(uint32 type, uint32 priority, uint32 fade_in, uint32 fade_out, uint32 duration, std::string msg);
	void PlayMP3(std::string file);
	int GetBoatID();
	void SetBoatID(uint32 in_boatid);
	char* GetBoatName();
	void SetBoatName(const char* in_boatname);
	void QuestReward(Lua_Mob target);
	void QuestReward(Lua_Mob target, uint32 copper);
	void QuestReward(Lua_Mob target, uint32 copper, uint32 silver);
	void QuestReward(Lua_Mob target, uint32 copper, uint32 silver, uint32 gold);
	void QuestReward(Lua_Mob target, uint32 copper, uint32 silver, uint32 gold, uint32 platinum);
	void QuestReward(Lua_Mob target, uint32 copper, uint32 silver, uint32 gold, uint32 platinum, uint32 itemid);
	void QuestReward(Lua_Mob target, uint32 copper, uint32 silver, uint32 gold, uint32 platinum, uint32 itemid, uint32 exp);
	void QuestReward(Lua_Mob target, uint32 copper, uint32 silver, uint32 gold, uint32 platinum, uint32 itemid, uint32 exp, bool faction);
};

#endif
#endif
