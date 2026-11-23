/* Game_GetDataByIndex (0x48d110). */
extern "C" void *g_Text_0475_Kids;
extern "C" void *g_Text_0476_Teens;
extern "C" void *g_Text_0477_Students;
extern "C" void *g_Text_0478_Louts;
extern "C" void *g_Text_0479_Yuppies;
extern "C" void *g_Text_0480_Big_shots;
extern "C" void *g_Text_0481_Gothics;
extern "C" void *g_Text_0482_Tourist;
extern "C" void *g_Text_0485_Official;
extern "C" void *g_Text_0486_Fat_man;
extern "C" void *g_Text_1298_Errand_Boy;
extern "C" void *g_Text_1299_Service;
extern "C" void *g_Text_1300_Cook;
extern "C" void *g_Text_1301_Manager;
extern "C" void *g_Text_1302_Job_seeker;
extern "C" void *g_Text_1303_Guard;
extern "C" void *g_Text_1304_Punk;
extern "C" void *g_Text_1305_Courier;
extern "C" void *g_Text_1306_Thug;
extern "C" void *g_Text_1307_Gangster;
extern "C" void *g_Text_1308_Policeman;
extern "C" void *g_Text_1310_Mayor;
extern "C" void *g_Text_1311_Flyer_Boy;
extern "C" void *g_Text_1312_Supplier;
extern "C" void *g_Text_1313_Cleaning;
extern "C" void *g_Text_1314_Exterminator;
extern "C" void *g_Text_1315_Rat;
extern "C" void *g_Text_1316_Woodworm;
extern "C" void *g_Text_1317_Cockroach;
extern "C" void *g_Text_1296_Celebrity;
extern "C" char s__00568310[];

extern "C" void *__stdcall Game_GetDataByIndex(int index)
{
    switch (index) {
    case 0:
        return g_Text_0475_Kids;
    case 0x1:
        return g_Text_0476_Teens;
    case 0x2:
        return g_Text_0477_Students;
    case 0x3:
        return g_Text_0478_Louts;
    case 0x4:
        return g_Text_0479_Yuppies;
    case 0x5:
        return g_Text_0480_Big_shots;
    case 0x6:
        return g_Text_0481_Gothics;
    case 0x7:
        return g_Text_0482_Tourist;
    case 0xa:
        return g_Text_0485_Official;
    case 0xb:
        return g_Text_0486_Fat_man;
    case 0xc:
        return g_Text_1312_Supplier;
    case 0xd:
        return g_Text_1308_Policeman;
    case 0xe:
        return g_Text_1313_Cleaning;
    case 0x10:
        return g_Text_1302_Job_seeker;
    case 0x11:
        return g_Text_1300_Cook;
    case 0x12:
        return g_Text_1301_Manager;
    case 0x13:
        return g_Text_1299_Service;
    case 0x14:
        return g_Text_1298_Errand_Boy;
    case 0x16:
        return g_Text_1304_Punk;
    case 0x17:
        return g_Text_1303_Guard;
    case 0x18:
        return g_Text_1310_Mayor;
    case 0x1a:
        return g_Text_1315_Rat;
    case 0x1b:
        return g_Text_1317_Cockroach;
    case 0x1c:
        return g_Text_1316_Woodworm;
    case 0x1d:
        return g_Text_1307_Gangster;
    case 0x1e:
        return g_Text_1306_Thug;
    case 0x1f:
        return g_Text_1305_Courier;
    case 0x20:
        return g_Text_1314_Exterminator;
    case 0xf:
    case 0x21:
        return g_Text_1296_Celebrity;
    case 0x22:
        return g_Text_1311_Flyer_Boy;
    default:
        return s__00568310;
    }
}
