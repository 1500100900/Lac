#include "globals.h"

/*
 * These are skill_lookup return values for common skills and spells.
 */
int	gsn_backstab;
int	gsn_berserk;		/* by Thelonius */
int	gsn_blokowanie_tarcza;	/* Lam */
int	gsn_breathe_water;	/* by Thelonius */
int	gsn_burning_hands;
int	gsn_cause_light;
int	gsn_change;		/* Lam */
int	gsn_circle;		/* by Thelonius */
int	gsn_cone_of_silence;
int	gsn_disarm;
int	gsn_dodge;
int	gsn_enhanced_whois;	/* Lam */
int	gsn_fast_flee;		/* Lam */
int	gsn_fast_healing;	/* Lam */
int	gsn_fetch;		/* Lam */
int	gsn_flamestrike;
int	gsn_fourth_attack;	/* Lam */
int	gsn_haggle;		/* Lam */
int	gsn_hide;
int	gsn_hunt;		/* z Wurma */
int	gsn_krwawe_lzy;		/* Lam */
int	gsn_kontrola_nad_woda;	/* Lam */
int	gsn_kumulacja_mocy;	/* Qwert */
int	gsn_longscan;		/* Lam */
int	gsn_meditation;		/* Lam */
int	gsn_no_trip;		/* Lam */
int	gsn_overhear;		/* Lam */
int	gsn_pajeczyna;
int	gsn_peek;
int	gsn_pick_lock;
int	gsn_plywanie;		/* Lam */
int	gsn_poison_weapon;	/* by Thelonius */
int	gsn_profesjonalizm;
int	gsn_scrolls;		/* by Binky / Thelonius */
int	gsn_snare;		/* by Binky / Thelonius */
int	gsn_sneak;
int	gsn_staves;		/* by Binky / Thelonius */
int	gsn_steal;
int	gsn_strong_wield;	/* Lam */
int	gsn_taranowanie;	/* Lam */
int	gsn_telepathy;		/* Lam */
int	gsn_untangle;		/* by Thelonius */
int	gsn_wands;		/* by Binky / Thelonius */

int	gsn_bash;
int	gsn_dual;		/* by Thelonius */
int	gsn_enhanced_damage;
int	gsn_kick;
int	gsn_parry;
int	gsn_rescue;
int	gsn_second_attack;
int	gsn_third_attack;
int	gsn_fury;		/* Qwert */

int	gsn_blindness;
int	gsn_dazzle;		/* Lam */
int	gsn_charm_person;
int	gsn_curse;
int	gsn_invis;
int	gsn_mass_invis;
int	gsn_mute;		/* by Thelonius */
int	gsn_podglad;		/* Lam */
int	gsn_poison;
int	gsn_sleep;
int	gsn_polymorph_other;
int	gsn_turn_undead;
int	gsn_rozpalanie_ognisk;	/* Ulryk */
int	gsn_blokada_mentalna;	/* Ulryk */

/*
 * Psionicist gsn's (by Thelonius).
 */
int	gsn_chameleon;
int	gsn_domination;
int	gsn_heighten;
int	gsn_shadow;

/*
 * Fuyara: skrytobojca
 */
int	gsn_anatomy;
int	gsn_appraise;
int	gsn_assasinate;
int	gsn_assemble;
int	gsn_awareness;
int	gsn_concentrate;
int	gsn_critical_hit;
int	gsn_cumulate_strength;
int	gsn_death_tech;
int	gsn_disguise;
int	gsn_dragon_tech;
int	gsn_enhanced_kick;
int	gsn_flash;
int	gsn_high_efficiency;
int	gsn_initiation;
int	gsn_jump;
int	gsn_mighty_hands;
int	gsn_power_tech;
int	gsn_pull;
int	gsn_reinforce_blade;
int	gsn_runes;
int	gsn_rune_flare;
int	gsn_rune_fire;
int	gsn_rune_ice;
int	gsn_rune_poison;
int	gsn_search;
int	gsn_speed_tech;
int	gsn_strike;
int	gsn_stun;
int	gsn_whirl;
int	gsn_wraith_morph;
int	gsn_walka_na_oslep;

int	gsn_stake;

/*
 * Race gsn's (by Kahn).
 */
int	gsn_vampiric_bite;
int	gsn_postac_nietoperza;

/*
 * Alandar: spadanie
 */
int	gsn_uderzenie_w;
int	gsn_uderzenie_o;
int	gsn_upadek;

/*
 * Qwert
 */
int	gsn_aura_pokoju;
int	gsn_duchowe_wsparcie;
int	gsn_bio_przyspieszenie;
int	gsn_przeniesienie_sily;
int	gsn_ostrze_ognia;
int	gsn_ostrze_chaosu;
int	gsn_ostrze_lodu;
int	gsn_przeniesienie_umyslu;
int	gsn_lodowa_tarcza;
int	gsn_lodowy_kolec;
int	gsn_dezorientacja;
int	gsn_przeklenstwo_natury;
int	gsn_przyspieszenie;
int	gsn_spowolnienie;
int	gsn_zakazenie;
int	gsn_kukla;
int	gsn_regeneracja;
int	gsn_degeneracja;
int	gsn_hipnoza;
int	gsn_rewers;
int	gsn_uwolnienie_umyslow;
int	gsn_znamie_smierci;

/*
 * Paladyn od Gimzy
 */
int	gsn_aniol_stroz;
int	gsn_rozblysk;
int	gsn_zaglada;
int	gsn_swiety_msciciel;

/*
 * Ulryk: nekromanta
 */
int	gsn_porazajacy_dotyk;
int	gsn_balsamowanie;
int	gsn_sprowadzenie_szkieletu;
int	gsn_mroczny_plomien;
int	gsn_kontrola_umyslu;
int	gsn_wskrzeszenie;
int	gsn_pocalunek_smierci;
int	gsn_eksplozja;
int	gsn_stworzenie_mumii;

/* Lam 5.11.2004: zapobiegam uzywaniu skill_lookup */
int	gsn_acid_breath;
int	gsn_armor;
int	gsn_bless;
int	gsn_combat_mind;
int	gsn_cure_light;
int	gsn_fire_breath;
int	gsn_frost_breath;
int	gsn_gas_breath;
int	gsn_lightning_breath;
int	gsn_mana_gift;
int	gsn_refresh;
int	gsn_shield;
int	gsn_teleport;


/*
 * Lam 29.1.2004: zapamietane rasy
 */
int	zr_bog;
int	zr_byk;
int	zr_harpia;
int	zr_jednorozec;
int	zr_jez;
int	zr_martwiak;
int	zr_minotaur;
int	zr_niedzwiedz;
int	zr_nietoperz;
int	zr_pajeczak;
int	zr_papuga;
int	zr_przedmiot;
int	zr_shambler;
int	zr_smok;
int	zr_troll;
int	zr_wampir;
int	zr_waz;


/*
 * Lam 23.3.99: zmienne czytane z pliku vnums.txt zamiast wielu #define w merc.h
 */
int	MOB_VNUM_MUMIA;		/* Ulryk */
int	MOB_VNUM_ZOMBIE;	/* Ulryk */
int	MOB_VNUM_SZKIELET;	/* Ulryk */
int	MOB_VNUM_KUKLA;		/* Qwert */
int	MOB_VNUM_CITYGUARD;
int	MOB_VNUM_VAMPIRE;
int	MOB_VNUM_ULT;
int	MOB_VNUM_SECRETARY;
int	MOB_VNUM_MIDGAARD_MAYOR;
int	MOB_VNUM_BANKIER;
int	MOB_VNUM_PRZECHOWALNIA;
int	MOB_VNUM_WARSZTAT;
int	MOB_VNUM_SUPERMOB;
int	OBJ_VNUM_MONEY_ONE;
int	OBJ_VNUM_MONEY_SOME;
int	OBJ_VNUM_CORPSE_NPC;
int	OBJ_VNUM_CORPSE_PC;
int	OBJ_VNUM_FLAKI;
int	OBJ_VNUM_GLOWA;
int	OBJ_VNUM_REKA;
int	OBJ_VNUM_NOGA;
int	OBJ_VNUM_SERCE;
int	OBJ_VNUM_OGON;
int	OBJ_VNUM_SKRZYDLO;
int	OBJ_VNUM_JEZYK;
int	OBJ_VNUM_UCHO;
int	OBJ_VNUM_LAPA;
int	OBJ_VNUM_LEB;
int	OBJ_VNUM_ZAB;
int	OBJ_VNUM_KIEL;
int	OBJ_VNUM_ROG;
int	OBJ_VNUM_SZPON;
int	OBJ_VNUM_PLETWA;
int	OBJ_VNUM_MUSHROOM;
int	OBJ_VNUM_LIGHT_BALL;
int	OBJ_VNUM_SPRING;
int	OBJ_VNUM_EGG;
int	OBJ_VNUM_PORTAL;
int	OBJ_VNUM_BRAMA;
int	OBJ_VNUM_DROGOWSKAZ;
int	OBJ_VNUM_CHRUST;
int	OBJ_VNUM_SCHOOL_MACE;
int	OBJ_VNUM_SCHOOL_DAGGER;
int	OBJ_VNUM_SCHOOL_SWORD;
int	OBJ_VNUM_SCHOOL_VEST;
int	OBJ_VNUM_SCHOOL_SHIELD;
int	OBJ_VNUM_SCHOOL_CLUB;
int	OBJ_VNUM_BLACK_POWDER;
int	OBJ_VNUM_STAKE;
int	OBJ_VNUM_KREW;
int	OBJ_VNUM_KALUZA_KRWI;
int	OBJ_VNUM_PALAD_MLOT;
int	OBJ_VNUM_PALAD_MIECZ;
int	OBJ_VNUM_SILVER_POWDER;
int	OBJ_VNUM_JEDZ_MIN;
int	OBJ_VNUM_JEDZ_MAX;
int	ROOM_VNUM_LIMBO;
int	ROOM_VNUM_CHAT;
int	ROOM_VNUM_TEMPLE;
int	ROOM_VNUM_ALTAR;
int	ROOM_VNUM_SCHOOL;
int	ROOM_VNUM_GRAVEYARD_A;
int	ROOM_VNUM_PURGATORY_A;
int	ROOM_VNUM_POZA_SWIATEM;
