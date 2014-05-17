/*
 * Attribute bonus structures.
 */
struct str_app_type
{
    const int		todam;
    const int		carry;
    const int		wield;
    const int		uwalnianie;
};

struct int_app_type
{
    const int		learn;
    const int		mana;
};

struct wis_app_type
{
    const int		practice;
    const int		opc;
};

struct dex_app_type
{
    const int		defensive;
    const int		tohit;
};

struct con_app_type
{
    const int		hitp;
    const double	wyparowanie;
    const int		shock;
};

/*
 * Liquids.
 */
struct liq_type
{
    const char *	const	liq_name;
    const char *	const	liq_biernik;
    const char *	const	liq_narzednik;
    const char *	const	liq_color;
    const int			liq_affect[ 3 ];
};

/*
 * Czary/umiejetnosci. Spolszczone: Lam i Grzechu 10.9.98
 */
struct skill_type
{
	  char *	pl_name;
    const char *	short_name;
    const char *	old_name;			/* Name of skill               */
	  int		skill_level[ MAX_CLASS ];	/* Level needed by class       */
    const char *	needed;				/* Lam: wymagana umiejetnosc   */
	  int		multi_level[ MAX_CLASS ];	/* Lam: poziom dla multi-profesji */
	  SPELL_FUN *	spell_fun;			/* Spell pointer (for spells)  */
    const int		target;				/* Legal targets               */
    const int		minimum_position;		/* Position for caster / user  */
	  int *		pgsn;				/* Pointer to associated gsn   */
    const int		min_mana;			/* Minimum mana used           */
    const int		beats;				/* Waiting time after use      */
    const int		to_practice;			/* Lam: ile mozna to cwiczyc   */
    const int		to_use;				/* Lam: ile trzeba uzyc do nauki */
    const int		rodzaj;				/* Lam: do komunikatow przy walce */
    const char *	noun_damage;			/* Damage message              */
    const char *	msg_off;			/* Wear off message            */
    const char *	msg_off_others;			/* Lam 20.11.2000 na wzor EOS  */
    WEAR_OFF_FUN	*wear_off_fun;			/* Lam 1.4.2006		  */
    const int		flags;				/* Ulryk 24.09.2003            */
};

/* Lam 10.1.2003 */
struct holiday_type
{
    const int			month;	/* miesiac, 1-17 */
    const int			day;	/* dzien w miesiacu, 1-35 */
    const char *	const	name;	/* nazwa swieta */
    const char *	const	message;/* komunikat wysylany graczom o polnocy */
};

struct material_type
{
    const char *	const	name;
    const char *	const	dopelniacz;
    const int			minlevel;
    const int			maxlevel;
    const int			ac; /* ( ac / 8 ) * value[ 0 ] */
    const int			value; /* jw. * cost */
    const int			weight; /* jw. * weight */
    const bool			vampburn; /* czy pali wampiry */
/*  const int			forms; */ /* bity - jakich form nie moze miec */
};

/*
 * Struktura dla typy_przedmiotow (const.c)
 */
struct object_type
{
    const	char *	const	name;
    const	char *	const	name_pl;
    const	char *	const	value[ 6 ];
    const	bool		spell[ 6 ];
};

/*
 * Struktura dla kierunki (const.c)
 */
struct dir_type
{
    const	char *	const	name;
		char *	const	skrot;
    const	char *	const	skrotd;
    const	char *	const	krotki;
    const	char *	const	biernik;
    const	char *	const	z_dopelniacz;
    const	int		odwrotny;
    const	char *	const	na_krew;
};

/*
 * Race structures
 */
struct race_type
{
    const	char *	const	who_name;
    const	char *	const	dopelniacz;
    const	char *	const	celownik;
    const	char *	const	biernik;
    const	char *	const	narzednik;
    const	char *	const	miejscownik;
    const	char *	const	wolacz;
    const	char *	const	name;/* polska bez polskich znakow */
    const	char *	const	ang; /* angielska nazwa - zeby wiedzial, jaka rasa */
    const	int		race_abilities;
    const	int		oddychanie;
    const	int		poruszanie;
    const	int		size;
    const	int		weight;
    const	int		str_mod;
    const	int		int_mod;
    const	int		wis_mod;
    const	int		dex_mod;
    const	int		con_mod;
    const	int		hp_gain;
    const	int		mana_gain;
    const	int		move_gain;
    const	int		thirst_mod;
    const	int		hunger_mod;
    const	char *	const	dmg_message;
    const	int		rodzaj;
    const	char *	const	hate;
    const	char *	const	kom_wejscia; /* Lam */
    const	char *	const	kom_wyjscia; /* Lam */
    const	int		wearlocs; /* Lam */
    const	int		food;	/* Alandar */
    const	int		parts; /* Lam */
		int *	const	zr; /* Lam: zapamietana rasa */
};

struct czesc_ciala
{
    int *wsk;
    int vnum;
    int masa; /* proporcja; <masa> razy ciezar rasy, podzielic przez 1024 */
    bool rasa_w_opisie;
    char *komunikat;
};

/*
 * Drunkeness communication structure.
 */
struct struckdrunk
{
    const int			min_drunk_level;
    const int			number_of_rep;
    const char	*	const	replacement[ 11 ];
};

/*
 * Per-class stuff.
 */
struct class_type
{
    const char	who_name[ MIL ];	/* Three-letter name for 'who'	*/
    const char	pl_name[ MIL ];		/* Wersja polska do "kto"	*/
    const char	long_name[ MIL ];	/* Wersja do "kimjest"		*/
    const char	ang[ MIL ];		/* Stara nazwa angielska	*/
    const int	attr_prime;		/* Prime attribute		*/
    const int	*weapon;		/* First weapon			*/
    const int	skill_adept;		/* Maximum skill level		*/
    const int	thac0_00;		/* Thac0 for level  0		*/
    const int	thac0_47;		/* Thac0 for level 47		*/
    const int	hp_min;			/* Min hp gained on leveling	*/
    const int	hp_max;			/* Max hp gained on leveling	*/
    const double bonus;			/* Doswiadczenie		*/
    const bool	fMana;			/* Class gains mana on level	*/
    const char	*races;			/* Rasy mogace nim byc		*/
};


extern	const	char *		const	clan_lev_name_md[ 10 ];
extern	const	char *		const	clan_lev_name_mm[ 10 ];
extern	const	char *		const	clan_lev_name_mn[ 10 ];
extern	const	char *		const	clan_lev_name_zd[ 10 ];
extern	const	char *		const	clan_lev_name_zm[ 10 ];
extern	const	char *		const	clan_lev_name_zn[ 10 ];
extern	const	char *		const	clan_stat_name[ 5 ];
extern	const	int			max_clan_level_members[ 10 ];

extern	const	struct class_type	class_table[ MAX_CLASS ];
extern		struct czesc_ciala	czesci_ciala[ ];
extern	const	struct struckdrunk	drunk[ ];
extern	const	struct holiday_type	holiday_table[ ];
extern	const	struct dir_type		kierunki[ MAX_DIR ];
extern	const	struct liq_type		liq_table_pl[ LIQ_MAX ];
extern	const	struct material_type	material_table[ MAX_MATERIAL ];
extern	const	struct race_type	race_table[ MAX_RACE ];
extern		struct skill_type	skill_table[ MAX_SKILL ];
extern	const	struct object_type	typy_przedmiotow[ ITEM_MAX ];

extern	const	char *		const	day_name[ ];
extern	const	char *		const	lac_nowosci;
extern	const	char *		const	month_name[ ];
extern	const	char *		const	polska_tablica[ 5 ][ 18 ];
extern	const	char *		const	tablica_kolorow[ 4 ][ MAX_COLOUR ];
extern	const	char *		const	title_table[ MAX_CLASS ][ 2 ];
extern	const	char *		const	typy_podloza[ ];

extern	const	int			dir_order[ MAX_DIR ];
extern	const	int			przelicznik_wydatkow[ 112 ];
extern	const	int			przelicznik_zysku[ 112 ];

extern	const	struct con_app_type	con_app[ 31 ];
extern	const	struct dex_app_type	dex_app[ 31 ];
extern	const	struct int_app_type	int_app[ 31 ];
extern	const	struct str_app_type	str_app[ 31 ];
extern	const	struct wis_app_type	wis_app[ 31 ];



/*
 * These are skill_lookup return values for common skills and spells.
 */
extern	int	gsn_backstab;
extern	int	gsn_berserk;		/* by Thelonius */
extern	int	gsn_blokowanie_tarcza;	/* Lam */
extern	int	gsn_breathe_water;	/* by Thelonius */
extern	int	gsn_burning_hands;
extern	int	gsn_cause_light;
extern	int	gsn_change;		/* Lam */
extern	int	gsn_circle;		/* by Thelonius */
extern	int	gsn_cone_of_silence;
extern	int	gsn_disarm;
extern	int	gsn_dodge;
extern	int	gsn_enhanced_whois;	/* Lam */
extern	int	gsn_fast_flee;		/* Lam */
extern	int	gsn_fast_healing;	/* Lam */
extern	int	gsn_fetch;		/* Lam */
extern	int	gsn_flamestrike;
extern	int	gsn_fourth_attack;	/* Lam */
extern	int	gsn_haggle;		/* Lam */
extern	int	gsn_hide;
extern	int	gsn_hunt;		/* z Wurma */
extern	int	gsn_krwawe_lzy;		/* Lam */
extern	int	gsn_kontrola_nad_woda;	/* Lam */
extern	int	gsn_kumulacja_mocy;	/* Qwert */
extern	int	gsn_longscan;		/* Lam */
extern	int	gsn_meditation;		/* Lam */
extern	int	gsn_no_trip;		/* Lam */
extern	int	gsn_overhear;		/* Lam */
extern	int	gsn_pajeczyna;
extern	int	gsn_peek;
extern	int	gsn_pick_lock;
extern	int	gsn_plywanie;		/* Lam */
extern	int	gsn_poison_weapon;	/* by Thelonius */
extern	int	gsn_profesjonalizm;
extern	int	gsn_scrolls;		/* by Binky / Thelonius */
extern	int	gsn_snare;		/* by Binky / Thelonius */
extern	int	gsn_sneak;
extern	int	gsn_staves;		/* by Binky / Thelonius */
extern	int	gsn_steal;
extern	int	gsn_strong_wield;	/* Lam */
extern	int	gsn_taranowanie;	/* Lam */
extern	int	gsn_telepathy;		/* Lam */
extern	int	gsn_untangle;		/* by Thelonius */
extern	int	gsn_wands;		/* by Binky / Thelonius */

extern	int	gsn_bash;
extern	int	gsn_dual;		/* by Thelonius */
extern	int	gsn_enhanced_damage;
extern	int	gsn_kick;
extern	int	gsn_parry;
extern	int	gsn_rescue;
extern	int	gsn_second_attack;
extern	int	gsn_third_attack;
extern	int	gsn_fury;		/* Qwert */

extern	int	gsn_blindness;
extern	int	gsn_dazzle;		/* Lam */
extern	int	gsn_charm_person;
extern	int	gsn_curse;
extern	int	gsn_invis;
extern	int	gsn_mass_invis;
extern	int	gsn_mute;		/* by Thelonius */
extern	int	gsn_podglad;		/* Lam */
extern	int	gsn_poison;
extern	int	gsn_sleep;
extern	int	gsn_polymorph_other;
extern	int	gsn_turn_undead;
extern	int	gsn_rozpalanie_ognisk;	/* Ulryk */
extern	int	gsn_blokada_mentalna;	/* Ulryk */

/*
 * Psionicist gsn's (by Thelonius).
 */
extern	int	gsn_chameleon;
extern	int	gsn_domination;
extern	int	gsn_heighten;
extern	int	gsn_shadow;

/*
 * Fuyara: skrytobojca
 */
extern	int	gsn_anatomy;
extern	int	gsn_appraise;
extern	int	gsn_assasinate;
extern	int	gsn_assemble;
extern	int	gsn_awareness;
extern	int	gsn_concentrate;
extern	int	gsn_critical_hit;
extern	int	gsn_cumulate_strength;
extern	int	gsn_death_tech;
extern	int	gsn_disguise;
extern	int	gsn_dragon_tech;
extern	int	gsn_enhanced_kick;
extern	int	gsn_flash;
extern	int	gsn_high_efficiency;
extern	int	gsn_initiation;
extern	int	gsn_jump;
extern	int	gsn_mighty_hands;
extern	int	gsn_power_tech;
extern	int	gsn_pull;
extern	int	gsn_reinforce_blade;
extern	int	gsn_runes;
extern	int	gsn_rune_flare;
extern	int	gsn_rune_fire;
extern	int	gsn_rune_ice;
extern	int	gsn_rune_poison;
extern	int	gsn_search;
extern	int	gsn_speed_tech;
extern	int	gsn_strike;
extern	int	gsn_stun;
extern	int	gsn_whirl;
extern	int	gsn_wraith_morph;
extern	int	gsn_walka_na_oslep;

extern	int	gsn_stake;

/*
 * Race gsn's (by Kahn).
 */
extern	int	gsn_vampiric_bite;
extern	int	gsn_postac_nietoperza;

/*
 * Alandar: spadanie
 */
extern	int	gsn_uderzenie_w;
extern	int	gsn_uderzenie_o;
extern	int	gsn_upadek;

/*
 * Qwert
 */
extern	int	gsn_aura_pokoju;
extern	int	gsn_duchowe_wsparcie;
extern	int	gsn_bio_przyspieszenie;
extern	int	gsn_przeniesienie_sily;
extern	int	gsn_ostrze_ognia;
extern	int	gsn_ostrze_chaosu;
extern	int	gsn_ostrze_lodu;
extern	int	gsn_przeniesienie_umyslu;
extern	int	gsn_lodowa_tarcza;
extern	int	gsn_lodowy_kolec;
extern	int	gsn_dezorientacja;
extern	int	gsn_przeklenstwo_natury;
extern	int	gsn_przyspieszenie;
extern	int	gsn_spowolnienie;
extern	int	gsn_zakazenie;
extern	int	gsn_kukla;
extern	int	gsn_regeneracja;
extern	int	gsn_degeneracja;
extern	int	gsn_hipnoza;
extern	int	gsn_rewers;
extern	int	gsn_uwolnienie_umyslow;
extern	int	gsn_znamie_smierci;

/*
 * Paladyn od Gimzy
 */
extern	int	gsn_aniol_stroz;
extern	int	gsn_rozblysk;
extern	int	gsn_zaglada;
extern	int	gsn_swiety_msciciel;

/*
 * Ulryk: nekromanta
 */
extern	int	gsn_porazajacy_dotyk;
extern	int	gsn_balsamowanie;
extern	int	gsn_sprowadzenie_szkieletu;
extern	int	gsn_mroczny_plomien;
extern	int	gsn_kontrola_umyslu;
extern	int	gsn_wskrzeszenie;
extern	int	gsn_pocalunek_smierci;
extern	int	gsn_eksplozja;
extern	int	gsn_stworzenie_mumii;

/* Lam 5.11.2004: zapobiegam uzywaniu skill_lookup */
extern	int	gsn_acid_breath;
extern	int	gsn_armor;
extern	int	gsn_bless;
extern	int	gsn_combat_mind;
extern	int	gsn_cure_light;
extern	int	gsn_fire_breath;
extern	int	gsn_frost_breath;
extern	int	gsn_gas_breath;
extern	int	gsn_lightning_breath;
extern	int	gsn_mana_gift;
extern	int	gsn_refresh;
extern	int	gsn_shield;
extern	int	gsn_teleport;


/*
 * Lam 29.1.2004: zapamietane rasy
 */
extern	int	zr_bog;
extern	int	zr_byk;
extern	int	zr_harpia;
extern	int	zr_jednorozec;
extern	int	zr_jez;
extern	int	zr_martwiak;
extern	int	zr_minotaur;
extern	int	zr_niedzwiedz;
extern	int	zr_nietoperz;
extern	int	zr_pajeczak;
extern	int	zr_papuga;
extern	int	zr_przedmiot;
extern	int	zr_shambler;
extern	int	zr_smok;
extern	int	zr_troll;
extern	int	zr_wampir;
extern	int	zr_waz;


/*
 * Lam 23.3.99: zmienne czytane z pliku vnums.txt zamiast wielu #define w merc.h
 */
extern	int	MOB_VNUM_MUMIA;		/* Ulryk */
extern	int	MOB_VNUM_ZOMBIE;	/* Ulryk */
extern	int	MOB_VNUM_SZKIELET;	/* Ulryk */
extern	int	MOB_VNUM_KUKLA;		/* Qwert */
extern	int	MOB_VNUM_CITYGUARD;
extern	int	MOB_VNUM_VAMPIRE;
extern	int	MOB_VNUM_ULT;
extern	int	MOB_VNUM_SECRETARY;
extern	int	MOB_VNUM_MIDGAARD_MAYOR;
extern	int	MOB_VNUM_BANKIER;
extern	int	MOB_VNUM_PRZECHOWALNIA;
extern	int	MOB_VNUM_WARSZTAT;
extern	int	MOB_VNUM_SUPERMOB;
extern	int	OBJ_VNUM_MONEY_ONE;
extern	int	OBJ_VNUM_MONEY_SOME;
extern	int	OBJ_VNUM_CORPSE_NPC;
extern	int	OBJ_VNUM_CORPSE_PC;
extern	int	OBJ_VNUM_FLAKI;
extern	int	OBJ_VNUM_GLOWA;
extern	int	OBJ_VNUM_REKA;
extern	int	OBJ_VNUM_NOGA;
extern	int	OBJ_VNUM_SERCE;
extern	int	OBJ_VNUM_OGON;
extern	int	OBJ_VNUM_SKRZYDLO;
extern	int	OBJ_VNUM_JEZYK;
extern	int	OBJ_VNUM_UCHO;
extern	int	OBJ_VNUM_LAPA;
extern	int	OBJ_VNUM_LEB;
extern	int	OBJ_VNUM_ZAB;
extern	int	OBJ_VNUM_KIEL;
extern	int	OBJ_VNUM_ROG;
extern	int	OBJ_VNUM_SZPON;
extern	int	OBJ_VNUM_PLETWA;
extern	int	OBJ_VNUM_MUSHROOM;
extern	int	OBJ_VNUM_LIGHT_BALL;
extern	int	OBJ_VNUM_SPRING;
extern	int	OBJ_VNUM_EGG;
extern	int	OBJ_VNUM_PORTAL;
extern	int	OBJ_VNUM_BRAMA;
extern	int	OBJ_VNUM_DROGOWSKAZ;
extern	int	OBJ_VNUM_CHRUST;
extern	int	OBJ_VNUM_SCHOOL_MACE;
extern	int	OBJ_VNUM_SCHOOL_DAGGER;
extern	int	OBJ_VNUM_SCHOOL_SWORD;
extern	int	OBJ_VNUM_SCHOOL_VEST;
extern	int	OBJ_VNUM_SCHOOL_SHIELD;
extern	int	OBJ_VNUM_SCHOOL_CLUB;
extern	int	OBJ_VNUM_BLACK_POWDER;
extern	int	OBJ_VNUM_STAKE;
extern	int	OBJ_VNUM_KREW;
extern	int	OBJ_VNUM_KALUZA_KRWI;
extern	int	OBJ_VNUM_PALAD_MLOT;
extern	int	OBJ_VNUM_PALAD_MIECZ;
extern	int	OBJ_VNUM_SILVER_POWDER;
extern	int	OBJ_VNUM_JEDZ_MIN;
extern	int	OBJ_VNUM_JEDZ_MAX;
extern	int	ROOM_VNUM_LIMBO;
extern	int	ROOM_VNUM_CHAT;
extern	int	ROOM_VNUM_TEMPLE;
extern	int	ROOM_VNUM_ALTAR;
extern	int	ROOM_VNUM_SCHOOL;
extern	int	ROOM_VNUM_GRAVEYARD_A;
extern	int	ROOM_VNUM_PURGATORY_A;
extern	int	ROOM_VNUM_POZA_SWIATEM;
