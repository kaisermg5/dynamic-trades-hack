
#include "headers/types.h"
#include "headers/pokemon.h"
#include "headers/script.h"

extern u16 gSpecialVar_0x8004;
extern u16 gScriptResult; // var 800D
extern struct Pokemon gEnemyParty[6];
extern struct ScriptContext sScriptContext1;

extern void SetMonData(struct Pokemon *mon, s32 field, const void *data);
extern void CalculateMonStats(struct Pokemon *mon);
extern void CreateMon(struct Pokemon *mon, u16 species, u8 level, u8 fixedIV, u8 hasFixedPersonality, u32 fixedPersonality, u8 otIdType, u32 fixedOtId);


void SetTrade()
{
	struct Pokemon *pokemon = &gEnemyParty[0];
	u8 met_location = 0xFE;
	CreateMon(pokemon, gScriptResult, gSpecialVar_0x8004, 32, 0, 0, 1, &sScriptContext1.data[0]);
	SetMonData(pokemon, MON_DATA_OT_NAME, sScriptContext1.data[1]);
	SetMonData(pokemon, MON_DATA_NICKNAME, sScriptContext1.data[2]);
	SetMonData(pokemon, MON_DATA_MET_LOCATION, &met_location);
	CalculateMonStats(pokemon);

	gSpecialVar_0x8004 = 0; // To prevent the texts from breaking...
}


