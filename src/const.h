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
