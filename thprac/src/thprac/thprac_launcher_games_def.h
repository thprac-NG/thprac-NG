﻿#pragma once
#include "thprac_gui_locale.h"
#include <cstdint>

namespace THPrac {
enum THGameCatagory {
    CAT_MAIN,
    CAT_SPINOFF_STG,
    CAT_SPINOFF_OTHERS,
    CAT_EMULATOR,
};
enum THGameType {
    TYPE_ERROR = 0,
    TYPE_ORIGINAL = 1,
    TYPE_MODDED = 2,
    TYPE_THCRAP = 3,
    TYPE_CHINESE = 4,
    TYPE_SCHINESE = 5,
    TYPE_TCHINESE = 6,
    TYPE_NYASAMA = 7,
    TYPE_STEAM = 8,
    TYPE_UNCERTAIN = 9,
    TYPE_MALICIOUS = 10,
    TYPE_UNKNOWN = 11,
};

struct ExeSig {
    uint32_t timeStamp;
    uint32_t textSize;
    uint32_t oepCode[10];
    uint32_t metroHash[4];
};

struct THGameSig {
    const char* idStr;
    const wchar_t* steamId;
    th_glossary_t refStr;
    THGameCatagory catagory;
    const wchar_t* vPatchStr;
    const wchar_t* appdataStr;
    void (*initFunc)();
    ExeSig exeSig;
};

struct THKnownGame {
    const char* idStr;
    THGameType type;
    uint32_t metroHash[4];
};

extern void TH06Init();
extern void TH07Init();
extern void TH08Init();
extern void TH09Init();
extern void TH095Init();
extern void TH10Init();
extern void AlcostgInit();
extern void TH11Init();
extern void TH12Init();
extern void TH125Init();
extern void TH128Init();
extern void TH13Init();
extern void TH14Init();
extern void TH143Init();
extern void TH15Init();
extern void TH16Init();
extern void TH165Init();
extern void TH17Init();
extern void TH18Init();
extern void TH185Init();
extern void TH19_v1_00a_Init();
extern void TH19_v1_10c_Init();

static THKnownGame gKnownGames[]{
    {"th06",  TYPE_CHINESE,  {0x6c2e0eb5, 0x6bb9bce8, 0x4ffcf20e, 0x65e9c0bf}},
    {"th06",  TYPE_ORIGINAL, {0xd179f6c8, 0x0af9170, 0xae99b942, 0x4c974b53} },
    {"th07",  TYPE_SCHINESE, {0x8995e319, 0x17c3ee1c, 0x6034a965, 0x70fefd77}},
    {"th07",  TYPE_SCHINESE, {0xdc5ae3c0, 0x959663c2, 0x5cebd278, 0x956424fe}},
    {"th075", TYPE_SCHINESE, {0xbdcd7982, 0x41103975, 0x75dc169d, 0x88298932}},
    {"th08",  TYPE_SCHINESE, {0x58db89b4, 0x5a9fe98a, 0x2dea944f, 0xaebe92d9}},
    {"th09",  TYPE_SCHINESE, {0x479728a5, 0xefc341e0, 0x260d5e91, 0xe6851479}},
    {"th095", TYPE_SCHINESE, {0xc0ba2aae, 0xd037ee77, 0xda79797d, 0x53a7ebc1}},
    {"th10",  TYPE_SCHINESE, {0x2680e8df, 0xe528eef4, 0x2a07c721, 0x6bc772df}},
    {"th10",  TYPE_TCHINESE, {0x03a4114f, 0xa6bfb0d7, 0xcbc29fec, 0x7028a7b1}},
    {"th105", TYPE_SCHINESE, {0x6a09d7da, 0xe25c8d1b, 0xdfa00b4f, 0x1fe8bb5f}},
    {"th11",  TYPE_SCHINESE, {0xca516350, 0x63057ef3, 0x815a096e, 0x50afd6b8}},
    {"th12",  TYPE_SCHINESE, {0xddf5470b, 0xe89d1019, 0x4fb6bf56, 0x738153ad}},
    {"th123", TYPE_SCHINESE, {0x2a7099d1, 0xf0244e40, 0x8fcab54c, 0xbdba4a5d}},
    {"th125", TYPE_SCHINESE, {0x66928829, 0x80da58eb, 0xd9dfd4da, 0x8333fcce}},
    {"th128", TYPE_SCHINESE, {0x126829c6, 0xd6eab530, 0xf9734a83, 0xee657af5}},
    {"th13",  TYPE_SCHINESE, {0xbfaa3ea8, 0x1242e9dd, 0x82953fb0, 0x40d24284}},
    {"th13",  TYPE_SCHINESE, {0x7c12239d, 0xf9e1b1a5, 0x2388ce13, 0x7e458f48}},
    {"th135", TYPE_SCHINESE, {0xf2246b98, 0x9d4a7bf0, 0x2c1d8f07, 0x84bc1a99}},
    {"th14",  TYPE_NYASAMA,  {0xdc9235f5, 0xe124c565, 0x6485e269, 0xf4686950}},
    {"th143", TYPE_NYASAMA,  {0x47cdb883, 0xbe3921ae, 0xf9c0c825, 0x2cefb060}},
    {"th145", TYPE_SCHINESE, {0x8c6911ea, 0xd4ab7879, 0x82297970, 0xbfd67515}},
    {"th15",  TYPE_NYASAMA,  {0xcfe2e487, 0xc7e04af4, 0x9160e8c1, 0x98291df2}},
    {"th16",  TYPE_NYASAMA,  {0xbf82bc22, 0xe19074c3, 0x4fb9a1d7, 0xfa429c31}},
    {"th165", TYPE_NYASAMA,  {0xfcdcbd55, 0x8b944a23, 0x32f3f96d, 0xefb7750e}},
    {"th17",  TYPE_NYASAMA,  {0x2f370234, 0xff6024b0, 0x80f25da9, 0xcf2e1bf4}},
    {"th18",  TYPE_ORIGINAL, {0xa3f0a451, 0x85ce8668, 0xfa4eda8a, 0xd808c596}},
    {"th18",  TYPE_NYASAMA,  {0x71115032, 0x3a4d05bd, 0x8dfc8ba4, 0xa476dc6f}},
};

static THGameSig gGameDefs[]{
    {"alcostg",
     nullptr,    ALCOSTG_TITLE,
     CAT_SPINOFF_STG,    L"vpatch_alcostg.dll",
     nullptr,                            AlcostgInit,
     {1198873702,
      397312,
      {0x212b, 0x322a, 0x0524, 0xac44, 0x5691, 0x4646, 0xd3f8, 0x4848, 0xc249, 0xa28d},
      {0x3d65fad0, 0xd4c4e831, 0x4fb58774, 0x957f0157}}},
    {"th06",
     nullptr,    TH06_TITLE,
     CAT_MAIN,           L"vpatch_th06.dll",
     nullptr,                            TH06Init,
     {1038721275,
      430080,
      {0x212b, 0xe22a, 0x05bc, 0xac44, 0x4867, 0x4646, 0xd3f8, 0x4848, 0xc249, 0xa28d},
      {0xbae18847, 0x78d78ce2, 0x4d19703a, 0x3f5cbe16}}},
    {"th07",
     nullptr,    TH07_TITLE,
     CAT_MAIN,           L"vpatch_th07.dll",
     nullptr,                            TH07Init,
     {1066942337,
      572928,
      {0x212b, 0xe22a, 0x0a45, 0xac44, 0x5ede, 0x4646, 0xd3f8, 0x4848, 0xc249, 0xa28d},
      {0xd69a5df6, 0x4a78f383, 0x956d7f9f, 0x02e3ad3b}}},
    {"th075",
     nullptr,    TH075_TITLE,
     CAT_SPINOFF_OTHERS, nullptr,
     nullptr,                            nullptr,
     {1120788294,
      2449408,
      {0x212b, 0x3a2a, 0x254c, 0xac44, 0x7599, 0x4646, 0xd3f8, 0x4848, 0xc249, 0xa28d},
      {0xececd7e6, 0xc7e6b23e, 0xd87c04f6, 0x98c496dc}}},
    {"th08",
     nullptr,    TH08_TITLE,
     CAT_MAIN,           L"vpatch_th08.dll",
     nullptr,                            TH08Init,
     {1095610188,
      728064,
      {0x212b, 0xf22a, 0x089b, 0xac44, 0x498b, 0x4646, 0xd3f8, 0x4848, 0xc249, 0xa28d},
      {0xc1f84aea, 0xfad04d3b, 0xf28642e5, 0x7fe28f3b}}},
    {"th09",
     nullptr,    TH09_TITLE,
     CAT_MAIN,           L"vpatch_th09.dll",
     nullptr,                            TH09Init,
     {1128708539,
      576512,
      {0x212b, 0xea2a, 0x0a16, 0xac44, 0x5900, 0x4646, 0xd3f8, 0x4848, 0xc249, 0xa28d},
      {0xdc63c169, 0x2c975430, 0xbc21df80, 0x26937f9e}}},
    {"th095",
     L"1420650", TH095_TITLE,
     CAT_SPINOFF_STG,    L"vpatch_th095.dll",
     nullptr,                            TH095Init,
     {1137085759,
      603136,
      {0x212b, 0x122a, 0x0af8, 0xac44, 0x5ce2, 0x4646, 0xd3f8, 0x4848, 0xc249, 0xa28d},
      {0x46eaf90e, 0x2a24f234, 0x74b70f03, 0xbd59c6e5}}},
    {"th10",
     L"1100140", TH10_TITLE,
     CAT_MAIN,           L"vpatch_th10.dll",
     nullptr,                            TH10Init,
     {1186086096,
      412672,
      {0x212b, 0x322a, 0x05e4, 0xac44, 0x5691, 0x4646, 0xd3f8, 0x4848, 0xc249, 0xa28d},
      {0x11c73117, 0x422a725f, 0xc0639015, 0x06050767}}},
    {"th105",
     nullptr,    TH105_TITLE,
     CAT_SPINOFF_OTHERS, nullptr,
     nullptr,                            nullptr,
     {1319458676,
      2879488,
      {0x8ba9, 0x42dd, 0xaa43, 0xba52, 0xbaba, 0x8a8a, 0x8b8b, 0x0ac5, 0x12b6, 0xc789},
      {0x31aaf075, 0x7fe79569, 0x5e0ad6ea, 0x8105772e}}},
    {"th11",
     L"1100150", TH11_TITLE,
     CAT_MAIN,           L"vpatch_th11.dll",
     nullptr,                            TH11Init,
     {1217734394,
      565248,
      {0x06a9, 0x4289, 0xaa43, 0xba3c, 0xbaba, 0xb9cd, 0xcc12, 0xc9a4, 0x61a5, 0x4a49},
      {0x4e4ad931, 0xa91dc711, 0x720e5db7, 0x57a14232}}},
    {"th12",
     L"1100160", TH12_TITLE,
     CAT_MAIN,           L"vpatch_th12.dll",
     nullptr,                            TH12Init,
     {1251344348,
      617472,
      {0x06a9, 0x4289, 0xaa43, 0xba3c, 0xbaba, 0xb9cd, 0xcc12, 0xc9a4, 0x61a5, 0x4a49},
      {0xd4d81259, 0xce424514, 0x6e7e6326, 0x8b4c0990}}},
    {"th123",
     nullptr,    TH123_TITLE,
     CAT_SPINOFF_OTHERS, nullptr,
     nullptr,                            nullptr,
     {1316148875,
      4546560,
      {0xa8a9, 0x42ec, 0xaa43, 0xba52, 0xbaba, 0x8a8a, 0x8b8b, 0x0ac5, 0x12b6, 0xc789},
      {0x7be66ad2, 0x4a21e375, 0xc7d08b4f, 0x7cc3c681}}},
    {"th125",
     L"1100170", TH125_TITLE,
     CAT_SPINOFF_STG,    L"vpatch_th125.dll",
     L"%APPDATA%\\ShanghaiAlice\\th125", TH125Init,
     {1267822137,
      611328,
      {0xf8a9, 0x42f9, 0xaa43, 0xba3c, 0xbaba, 0xb9cd, 0xcc12, 0xc9a4, 0x61a5, 0x4a49},
      {0x0e1b7b17, 0x473f857e, 0x3fe6360f, 0x40de70d3}}},
    {"th128",
     L"1100180", TH128_TITLE,
     CAT_SPINOFF_STG,    L"vpatch_th128.dll",
     L"%APPDATA%\\ShanghaiAlice\\th128", TH128Init,
     {1280811414,
      626176,
      {0x03a9, 0x42dd, 0xaa43, 0xbacd, 0xbaba, 0xb9cd, 0xcc12, 0xcba4, 0x69a5, 0x0fc1},
      {0x948a4e8a, 0x665d6cd0, 0x25fc26f7, 0xcba8f1e3}}},
    {"th13",
     L"1043230", TH13_TITLE,
     CAT_MAIN,           L"vpatch_th13.dll",
     L"%APPDATA%\\ShanghaiAlice\\th13",  TH13Init,
     {1313589413,
      656384,
      {0xb6a9, 0x42dc, 0xaa43, 0xbacd, 0xbaba, 0xb9cd, 0xcc12, 0xcba4, 0x69a5, 0x0fc1},
      {0x4619502d, 0xe94742fc, 0x13537c7d, 0x7212f384}}},
    {"th135",
     nullptr,    TH135_TITLE,
     CAT_SPINOFF_OTHERS, nullptr,
     nullptr,                            nullptr,
     {1381475275,
      3928064,
      {0xd7a9, 0x4340, 0xaa43, 0xbacd, 0xbaba, 0xb9cd, 0xcc12, 0xc3a4, 0x410c, 0x16e9},
      {0xb74eefbb, 0x7a38aa6f, 0xfa5258ff, 0x81b1c16c}}},
    {"th14",
     L"1043240", TH14_TITLE,
     CAT_MAIN,           L"vpatch_th14.dll",
     L"%APPDATA%\\ShanghaiAlice\\th14",  TH14Init,
     {1376634201,
      720896,
      {0xafa9, 0x42f5, 0xaa43, 0x4444, 0x4545, 0x522c, 0x1f2f, 0x0486, 0xa149, 0x511d},
      {0x08a6fde4, 0xb4344a4a, 0xa3636647, 0x387d4253}}},
    {"th143",
     L"937570",  TH143_TITLE,
     CAT_SPINOFF_STG,    nullptr,
     L"%APPDATA%\\ShanghaiAlice\\th143", TH143Init,
     {1398039605,
      748032,
      {0x6aa9, 0x428b, 0xaa43, 0x4444, 0x4545, 0x522c, 0xdf2f, 0x0511, 0xa149, 0x56f7},
      {0x2549f2c0, 0x1121c489, 0x9aaf6330, 0x75ade252}}},
    {"th145",
     nullptr,    TH145_TITLE,
     CAT_SPINOFF_OTHERS, nullptr,
     nullptr,                            nullptr,
     {1492674616,
      3516928,
      {0x83a9, 0x424d, 0xaa43, 0xbaca, 0xbaba, 0x562c, 0x772f, 0xcb28, 0xa149, 0x4500},
      {0x416e1a70, 0xcdae8d4f, 0xe62060d0, 0xc592d164}}},
    {"th15",
     L"937580",  TH15_TITLE,
     CAT_MAIN,           L"vpatch_th15.dll",
     L"%APPDATA%\\ShanghaiAlice\\th15",  TH15Init,
     {1444028071,
      772608,
      {0x1aa9, 0x428b, 0xaa43, 0x4444, 0x4545, 0x522c, 0x872f, 0x05f1, 0xa149, 0x56f7},
      {0xed3ac6ec, 0x21bc473c, 0x186edbb4, 0x9ebd98cf}}},
    {"th155",
     L"716710",  TH155_TITLE,
     CAT_SPINOFF_OTHERS, nullptr,
     nullptr,                            nullptr,
     {1524477382,
      3695616,
      {0x37a9, 0x424c, 0xaa43, 0xbaca, 0xbaba, 0x562c, 0xb72f, 0xc163, 0xa149, 0x47b4},
      {0xa42ea27d, 0xf14ae534, 0xde6c96e0, 0xb78ce61b}}},
    {"th16",
     L"745880",  TH16_TITLE,
     CAT_MAIN,           nullptr,
     L"%APPDATA%\\ShanghaiAlice\\th16",  TH16Init,
     {1501534029,
      564736,
      {0xeaa9, 0x4246, 0xaa43, 0xbaca, 0xbaba, 0xcd13, 0x11ab, 0x3db7, 0xc241, 0xa2bb},
      {0x4dae29e4, 0xa1af84f8, 0xc6d1d694, 0x8cb29894}}},
    {"th165",
     L"924650",  TH165_TITLE,
     CAT_SPINOFF_STG,    nullptr,
     L"%APPDATA%\\ShanghaiAlice\\th165", TH165Init,
     {1532998383,
      607232,
      {0xb9a9, 0x4246, 0xaa43, 0xbac0, 0xbaba, 0xcd13, 0x11ab, 0x3db7, 0xc241, 0xa2bb},
      {0x550d4b1c, 0x805408e3, 0x1ef2ca25, 0xa257adb3}}},
    {"th17",
     L"1079160", TH17_TITLE,
     CAT_MAIN,           nullptr,
     L"%APPDATA%\\ShanghaiAlice\\th17",  TH17Init,
     {1565429804,
      626688,
      {0xb2a9, 0x4246, 0xaa43, 0xba3e, 0xbaba, 0xcd13, 0x11ab, 0x3db7, 0xc241, 0xa2bb},
      {0x3b46eeb2, 0xcd3b5634, 0x3e1032a2, 0x22cac0c5}}},
    {"th175",
     L"1440500", TH175_TITLE,
     CAT_SPINOFF_OTHERS, nullptr,
     nullptr,                            nullptr,
     {1635319660,
      375296,
      {0x31a9, 0x4244, 0xaa43, 0xbaca, 0xbaba, 0xcd13, 0x11ab, 0x3db7, 0xc241, 0xa2bb},
      {0xac9cb8f9, 0x1972b2cc, 0xadab5748, 0x751593e1}}},
    {"th18",
     L"1566410", TH18_TITLE,
     CAT_MAIN,           nullptr,
     L"%APPDATA%\\ShanghaiAlice\\th18",  TH18Init,
     {1618619144,
      702464,
      {0x9ba9, 0x4246, 0xaa43, 0xba3e, 0xbaba, 0xcd13, 0xc4ab, 0x44a4, 0x04c4, 0xa2be},
      {0x06c9eac8, 0x6b941c66, 0x2ea3c134, 0xf44fc808}}},
    {"th185",
     L"2097720", TH185_TITLE,
     CAT_SPINOFF_STG,    nullptr,
     L"%APPDATA%\\ShanghaiAlice\\th185", TH185Init,
     {1659144319,
      711168,
      {0x84a9, 0x4246, 0xaa43, 0xba3e, 0xbaba, 0xcd13, 0xc4ab, 0x44a4, 0x04c4, 0xa2be},
      {0xeff8426f, 0xa6522a33, 0xdc04050e, 0xc99233fe}}},
    {"th19",
     L"2400340", TH19_TITLE,
     CAT_MAIN,           nullptr,
     L"%APPDATA%\\ShanghaiAlice\\th19",  TH19_v1_00a_Init,
     {1690598468,
      1433600,
      {0xdfa9, 0x4247, 0xaa43, 0xba3e, 0xbaba, 0x0e2e, 0x1d90, 0xb748, 0x8d5c, 0x1fbb},
      {0x1ef2d050, 0xbddd8da2, 0x56cedb87, 0xe674cd2c}}},
    {"th19",
     L"2400340", TH19_TITLE,
     CAT_MAIN,           nullptr,
     L"%APPDATA%\\ShanghaiAlice\\th19",  TH19_v1_10c_Init,
     {1720429610,
      1544704,
      {0xb3a9, 0x4245, 0xaa43, 0xba3e, 0xbaba, 0x0e2e, 0x1a4a, 0xb748, 0xad5c, 0x1dfb},
      {0x4951fa2e, 0x63b2d14d, 0x4b3ab26a, 0x3ee8b40d}}},
};

#pragma region Game Roll Def
enum GameRollType {
    ROLL_PC98 = 0,
    ROLL_MAIN = 1,
    ROLL_SPINOFF_STG = 2,
    ROLL_SPINOFF_OTHERS = 3
};

struct GameRoll {
    const char* name;
    GameRollType type;
    const char* playerSelect;
    int playerColumns;
    bool selected = false;
};

static GameRoll gGameRoll[] = {
    {
     "alcostg",                                                                  ROLL_SPINOFF_STG,
     nullptr,                                                       1,
     },
    {
     "th01",                                                                          ROLL_PC98,
     nullptr,                                                        1,
     },
    {
     "th02",                                                                    ROLL_PC98,
     nullptr,                                                             1,
     },
    {
     "th03",                                                                     ROLL_PC98,
     "Reimu\0Mima\0Marisa\0Ellen\0Kotohime\0Kana\0Rikako\0Chiyuri\0Yumemi\0\0",                                                       3,
     },
    {
     "th04",                                                                          ROLL_PC98,
     "Reimu\0Marisa\0\0",                                                        2,
     },
    {
     "th05",  ROLL_PC98,
     "Reimu\0Marisa\0Mima\0Yuuka\0\0",                                                             4,
     },
    {
     "th06",                                                                     ROLL_MAIN,
     "Reimu A\0Reimu B\0Marisa A\0Marisa B\0\0",                                           2,
     },
    {
     "th07",                                                                          ROLL_MAIN,
     "Reimu A\0Reimu B\0Marisa A\0Marisa B\0Sakuya A\0Sakuya B\0\0",                                                        2,
     },
    {
     "th075",                                           ROLL_SPINOFF_OTHERS,
     nullptr,                                                             1,
     },
    {
     "th08",                                                                     ROLL_MAIN,
     "Reimu&Yukari\0Marisa&Alice\0Sakuya&Remilia\0Youmu&"
     "Yuyuko\0Reimu\0Yukari\0Marisa\0Alice\0Sakuya\0Remilia\0Youmu\0Yuyuko\0\0",                    4,
     },
    {
     "th09",                                                                          ROLL_MAIN,
     "Reimu\0Marisa\0Sakuya\0Youmu\0Reisen\0Cirno\0Lyrica\0Merlin\0Lunasa\0Mystia\0Tewi\0Aya\0Me"
     "dicine\0Yuuka\0Komachi\0Eiki\0\0",                                                        4,
     },
    {
     "th095",             ROLL_SPINOFF_STG,
     nullptr,                                                             1,
     },
    {
     "th10",                                                                    ROLL_MAIN,
     "Reimu A\0Reimu B\0Reimu C\0Marisa A\0Marisa B\0Marisa C\0\0",                                                       3,
     },
    {
     "th105",                                                                          ROLL_SPINOFF_OTHERS,
     nullptr,                                                        1,
     },
    {
     "th11", ROLL_MAIN,
     "Reimu A\0Reimu B\0Reimu C\0Marisa A\0Marisa B\0Marisa C\0\0",                                                             3,
     },
    {
     "th12",                                                                     ROLL_MAIN,
     "Reimu A\0Reimu B\0Marisa A\0Marisa B\0Sanae A\0Sanae B\0\0",                            2,
     },
    {
     "th123",                                                                          ROLL_SPINOFF_OTHERS,
     nullptr,                                                       1,
     },
    {
     "th125",                                                                    ROLL_SPINOFF_STG,
     "Aya\0Hatate",                                                             2,
     },
    {
     "th128",                                                                     ROLL_SPINOFF_STG,
     nullptr, 1,
     },
    {
     "th13",                                                                          ROLL_MAIN,
     "Reimu\0Marisa\0Sanae\0Youmu\0\0",                                                       4,
     },
    {
     "th135",                                                                    ROLL_SPINOFF_OTHERS,
     nullptr,                                                             1,
     },
    {
     "th14",                                                                     ROLL_MAIN,
     "Reimu A\0Reimu B\0Marisa A\0Marisa B\0Sakuya A\0Sakuya B\0\0", 2,
     },
    {
     "th143",                                                                          ROLL_SPINOFF_STG,
     nullptr,                                                        1,
     },
    {
     "th145",               ROLL_SPINOFF_OTHERS,
     nullptr,                                                             1,
     },
    {
     "th15",                                                                    ROLL_MAIN,
     "Reimu\0Marisa\0Sanae\0Reisen\0\0",                                                       4,
     },
    {
     "th155",                                                                          ROLL_SPINOFF_OTHERS,
     nullptr,                                                       1,
     },
    {
     "th16",                                                              ROLL_MAIN,
     "Reimu Spring\0Reimu Summer\0Reimu Autumn\0Reimu Winter\0Marisa Spring\0Marisa "
     "Summer\0Marisa Autumn\0Marisa Winter\0Aya Spring\0Aya Summer\0Aya Autumn\0Aya "
     "Winter\0Cirno Spring\0Cirno Summer\0Cirno Autumn\0Cirno Winter\0\0",                                                             4,
     },
    {
     "th165",                                                                    ROLL_SPINOFF_STG,
     nullptr,                                                       1,
     },
    {
     "th17",                                                                          ROLL_MAIN,
     "Reimu Wolf\0Reimu Otter\0Reimu Eagle\0Marisa Wolf\0Marisa Otter\0Marisa Eagle\0Youmu "
     "Wolf\0Youmu Otter\0Youmu Eagle\0\0",                                                        3,
     },
    {
     "th175",                                          ROLL_SPINOFF_OTHERS,
     nullptr,                                                             1,
     },
    {
     "th18",                                                                    ROLL_MAIN,
     "Reimu\0Marisa\0Sanae\0Sakuya\0\0",                                                       4,
     },
    {
     "th185",                                                                          ROLL_SPINOFF_STG,
     nullptr,                                                        1,
     },
    {
     "th19",             ROLL_MAIN,
     "Reimu\0Marisa\0Sanae\0Ran\0Aunn\0Nazrin\0Seiran\0Orin\0Tsukasa\0Mamizou\0Yachie\0Saki\0Yuu"
     "ma\0Suika\0Biten\0Enoko\0Chiyari\0Hisami\0Zanmu\0\0",                                                             4,
     }
};
#pragma endregion
}
