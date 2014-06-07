#define LAC_VERSION "Lac 1.4.1"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *   ___           _______     ________      |                             *
 *  |###|         |#######|   |########| (R) |             Lac             *
 *  |###|        |###|^|###| |###|^^|###|    |                             *
 *  |###|        |###| |###| |###|   ^^^     |    ekipa programistyczna:   *
 *  |###|        |###|_|###| |###|           |   Lam, Qwert, Ulryk, Vigud  *
 *  |###|        |#########| |###|           |      Tissarius, Cadaver     *
 *  |###|        |###|^|###| |###|           |        Alandar, Gimza       *
 *  |###|        |###| |###| |###|   ___     |    trzy grosze dolozyli:    *
 *  |###|______  |###| |###| |###|__|###|    |      Varda, Nop, Fuyara     *
 *  |##########| |###| |###|  |########|     |     Albi, Malven, Muzgus    *
 *   ^^^^^^^^^^   ^^^   ^^^    ^^^^^^^^      |                             *
 * ----------------------------------------------------------------------- *
 *  LACMud improvements copyright (C) 1997 - 2012 by Leszek Matok et al.   *
 *  EnvyMud 2.2 improvements copyright (C) 1996, 1997 by Michael Quan.     *
 *  EnvyMud 2.0 improvements copyright (C) 1995 by Michael Quan and        *
 *   Mitchell Tse.                                                         *
 *  Envy Diku Mud improvements copyright (C) 1994 by Michael Quan, David   *
 *   Love, Guilherme 'Willie' Arnold, and Mitchell Tse.                    *
 *  Merc Diku Mud improvments copyright (C) 1992, 1993 by Michael          *
 *   Chastain, Michael Quan, and Mitchell Tse.                             *
 *  Original Diku Mud copyright (C) 1990, 1991 by Sebastian Hammer,        *
 *   Michael Seifert, Hans Henrik St{rfeldt, Tom Madsen, and Katja Nyboe.  *
 * ----------------------------------------------------------------------- *
 *  In order to use any part of this Lac Diku Mud, you must comply with    *
 *  the original Diku license in 'license.doc', the Merc license in        *
 *  'license.txt', the Envy license in 'license.nvy', as well as the Lac   *
 *  license in 'license.lac'. In particular, you may not remove either of  *
 *  these copyright notices.                                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/* Vigud: czy to nie jest zadanie dla configure? Tak czy owak, TCC w Gentoo nie
   ustawia unix, wiec musialem dopisac tutaj defined( linux ), zeby dzialalo. */
#if !defined( unix )
# if defined( __NetBSD__ ) || defined( __HAIKU__ )  || defined( __unix__ )  || \
     defined( __minix )    || defined( linux )      || defined( __unix )    || \
     defined( _AIX )       || defined( __linux__ )  || defined( __APPLE__ ) || \
     defined( __QNXNTO__ ) || defined( __TenDRA__ )
#  define unix
# endif
#endif

/*
 * OS-dependent declarations.
 * These are all very standard library functions,
 *   but some systems have incomplete or non-ansi header files.
 */
#if defined( amiga ) || defined( __AROS__ )
# define AmigaTCP
#endif

#if defined( _WIN32 ) || defined( __WIN32__ ) || defined( __WINDOWS__ ) || defined( __TOS_WIN__ )
# if !defined( WIN32 )
#  define WIN32
# endif
#endif

#if defined( WIN32 ) || defined( MSDOS ) || defined( AmigaTCP )
# if defined( unix )
#  undef unix
# endif
#endif

/* bez tych linijek nie kompilowalyby sie typy danych uzywane w roznych
   strukturach muda. Mozna je umieszczac w kazdym pliku .c, ale po co? */
#include <time.h>
#include <stdio.h>
/* te wystepowaly w wiekszosci plikow .c, tym sposobem wciagne je do .gch */
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <ctype.h>

#if defined( unix ) || defined( __MINGW32__ ) || defined( __DJGPP__ )
# include <unistd.h>
#endif

/* Vigud: tam, gdzie nie ma dostepu do configure, wylaczamy co sie da
   i zgadujemy rozmiar inta. */
#if !defined( SIZEOF_INT )
# define NO_PTHREADS
# define NO_WMEMSET
# define NO_STRERROR_R
# define NOCRYPT
# define getpid() 0
# define SIZEOF_INT 4
#endif

#if !defined( NO_PTHREADS )
# if defined( unix ) || defined( __MINGW32__ )
#  include <pthread.h>
# else
#  define NO_PTHREADS
# endif
#endif

#if defined( WIN32 ) && !defined( __MINGW32__ )
# include <windows.h>
# include <io.h>
# include <direct.h>
# if defined( ABSOLUTE )
#  undef ABSOLUTE
# endif
# if defined( _MSC_VER )
#   define unlink _unlink
#   define chdir _chdir
#   define rmdir _rmdir
#   define read _read
#   define open _open
#   define close _close
#   if (_MSC_VER < 1400)
#     define ftime _ftime
#     define stat _stat
#   endif
#   if (_MSC_VER >= 1400)
#     define timeb _timeb
#   endif
# endif
#endif

/*
 * The crypt(3) function is not available on some operating systems.
 * In particular, the U.S. Government prohibits its export from the
 *   United States to foreign countries.
 * Turn on NOCRYPT to keep passwords in plain text.
 */
#if defined( NOCRYPT )
# define crypt( s1, s2 ) ( s1 )
#endif


#ifdef __cplusplus
extern "C" {
#endif

/* plik konfiguracyjny */
#include "config.h"

/* zgodnosc z kompilatorami innymi niz GCC lub GCC starszym niz 3.4 */
#if !defined( __GNUC__ ) || __GNUC__ < 3 || ( __GNUC__ == 3 && __GNUC_MINOR__ < 4 )
# if defined( __attribute__ )
#  undef __attribute__
# endif
# define __attribute__( x )
#endif

/*
 * Lam: w pewnych przypadkach chce, aby kod przestal sie kompilowac w zaleznosci
 * od jakiejs sytuacji. Jesli zobaczysz kiedys:
 * error: zero width for bit-field 'jakis_dziwny_komunikat_bledu'
 * to znaczy, ze piszesz cos nie tak jak trzeba :)
 */
#if !defined( __TenDRA__ )
# define COMPILER_ASSERT( warunek, komunikat ) \
	{ struct x { unsigned int komunikat: ( warunek ); }; }
#else
# include <assert.h>
# define COMPILER_ASSERT( warunek, komunikat ) \
	assert( warunek );
#endif
/*
 * Accommodate old non-Ansi compilers.
 */
#if defined( TRADITIONAL )
# define const
# define args( list )			( )
# define DECLARE_DO_FUN( fun )		void fun( )
# define DECLARE_SPEC_FUN( fun )	bool fun( )
# define DECLARE_SPELL_FUN( fun )	bool fun( )
# define DECLARE_WEAR_OFF_FUN( fun )	void fun( )	/* Lam */
# define DECLARE_GAME_FUN( fun )	void fun( )
# define DECLARE_CLAN_FUN( fun )	void fun( )	/* Malven */
# define DECLARE_PROG_FUN( fun )	void fun( )	/* Lam */
# define DECLARE_HTML_FUN( fun )	void fun( )
#else
# define args( list )			list
# define DECLARE_DO_FUN( fun )		DO_FUN    fun
# define DECLARE_SPEC_FUN( fun )	SPEC_FUN  fun
/* W przypadku kompilacji Glacy, glaca.o zawiera puste funkcje, ktore latwiej
   zostawic zadeklarowane niz usuwac z tablic w const.c.
   Tak mozna wyciac magic.c i pokrewne, bo nie potrzeba tych funkcji Glacy. */
# if defined( KOMPILUJE_GLACA_C )
#  define DECLARE_SPELL_FUN( fun )	SPELL_FUN fun; CZAR( fun ) { return FALSE; }
#  define DECLARE_WEAR_OFF_FUN( fun )	WEAR_OFF_FUN fun; SPADANIE( fun ) { return; }
# else
#  define DECLARE_SPELL_FUN( fun )	SPELL_FUN fun
#  define DECLARE_WEAR_OFF_FUN( fun )	WEAR_OFF_FUN fun /* Lam */
# endif
# define DECLARE_GAME_FUN( fun )	GAME_FUN  fun
# define DECLARE_CLAN_FUN( fun )	CLAN_FUN  fun   /* Malven */
# define DECLARE_PROG_FUN( fun )	PROG_FUN  fun	/* Lam */
# define DECLARE_HTML_FUN( fun )	HTML_FUN  fun
#endif

/*
 * Short scalar types.
 * Diavolo reports AIX compiler has bugs with short types.
 */
#if     !defined( FALSE )
# define FALSE    0
#endif

#if     !defined( TRUE )
# define TRUE     1
#endif

#if	!defined( BERR )
# define BERR   255
#endif

#if defined( _AIX )
# if !defined( const )
# define const
# endif
typedef int	bool;
# define unix
#else
/* typedef unsigned char		bool; - nie kompilowalo sie */
/* #define bool unsigned char */
/* aktualnie taka wersja pozwala uniknac ostrzezenia gcc "passing arg * of *
   with different width due to prototype", ktore nie ma sensu moim zdaniem */
typedef int	bool;
#endif


#define sf_family sins.sin.sin_family
#define sf_port sins.sin.sin_port
#define sf_addr sins.sin.sin_addr
#if defined( IPV6 )
# define sf_addr6 sins.sin6.sin6_addr
#endif


/* --- ponizej juz definicje muda --- */

/*
 * Lam: tutaj definicje liczb odpowiadajacych poszczegolnym bitom.
 * fread_number( ) akceptuje liczby w takim formacie. Przydatne do ustawiania
 * flag roznym rzeczom w krainach, bez meczacego siedzenia nad numerkami
 * bxx = 2 do potegi xx, czyli 1 przes. w lewo o xx, czyli bit nr xx
 */
#define		b00	( 1 <<  0 )
#define		b01	( 1 <<  1 )
#define		b02	( 1 <<  2 )
#define		b03	( 1 <<  3 )
#define		b04	( 1 <<  4 )
#define		b05	( 1 <<  5 )
#define		b06	( 1 <<  6 )
#define		b07	( 1 <<  7 )
#define		b08	( 1 <<  8 )
#define		b09	( 1 <<  9 )
#define		b10	( 1 << 10 )
#define		b11	( 1 << 11 )
#define		b12	( 1 << 12 )
#define		b13	( 1 << 13 )
#define		b14	( 1 << 14 )
#define		b15	( 1 << 15 )
#define		b16	( 1 << 16 )
#define		b17	( 1 << 17 )
#define		b18	( 1 << 18 )
#define		b19	( 1 << 19 )
#define		b20	( 1 << 20 )
#define		b21	( 1 << 21 )
#define		b22	( 1 << 22 )
#define		b23	( 1 << 23 )
#define		b24	( 1 << 24 )
#define		b25	( 1 << 25 )
#define		b26	( 1 << 26 )
#define		b27	( 1 << 27 )
#define		b28	( 1 << 28 )
#define		b29	( 1 << 29 )
#define		b30	( 1 << 30 )
#define		b31	( (unsigned) 1 << 31 )


/* teraz jednak beda rzadzily wektory bitow, a to dla nich: */
/* #define BITS_PER_INT ( sizeof( int ) * 8 ) */
#define BITS_PER_INT ( SIZEOF_INT * 8 ) /* SIZEOF_INT znajdzie nam configure */
#if BITS_PER_INT == 16
# error Lac nie skompiluje sie takim gownianym kompilatorem.
#else
# if BITS_PER_INT == 32
#  define MOVE_BITS 5
#  define INT_MASK 31
# else
/* wszystkie 64-bitowe maszyny i tak maja "int" na 32 b */
#  if BITS_PER_INT == 64
#   define MOVE_BITS 6
#   define INT_MASK 63
#  else
#   error Lac nie zna takich mocarnych architektur!
#  endif
# endif
#endif


/* gcc rozumie \e i \E, ale inne kompilatory nie */
#define ESC '\033'
#define ESCS "\033"

/*
 * Ok here we define strdup so it can no longer be confused
 * with str_dup.  Suggested by erwin@pip.dknet.dk - Kahn.
 *
 * Lam: najpierw undef, zeby egcs nie robil afery
 */
#undef strdup
#define strdup STRDUP_ERROR__USE_STR_DUP!

#if !defined( NO_STRERROR_R )
# undef perror
# define perror PERROR_TO_CIENIZNA__TOCAJ_LAC_PERROR
#endif


/***************************************************************************
 *                                                                         *
 *                   VALUES OF INTEREST TO AREA BUILDERS                   *
 *                   (Start of section ... start here)                     *
 *                                                                         *
 ***************************************************************************/

/*
 * ACT bits for mobs.
 * Used in #MOBILES.
 */
#define ACT_IS_NPC		b00	/* Auto set for mobs    */
#define ACT_SENTINEL		b01	/* Stays in one room    */
#define ACT_SCAVENGER		b02	/* Picks up objects     */
#define ACT_NO_HUNT		b03	/* Nie do wytropienia	*/ /* Lam */
#define ACT_NO_TRACK		b04	/* Nie gania za graczami*/ /* Lam */
#define ACT_AGGRESSIVE		b05	/* Attacks PC's         */
#define ACT_STAY_AREA		b06	/* Won't leave area     */
#define ACT_WIMPY		b07	/* Flees when hurt      */
#define ACT_PET			b08	/* Auto set for pets    */
#define ACT_TRAIN		b09	/* Can train PC's       */
#define ACT_PRACTICE		b10	/* Can practice PC's    */
#define ACT_GAMBLE		b11	/* (Wycofane)		*/
#define ACT_PEACEFUL		b12	/* Nie do zaatakowania	*/ /* Lam */
#define ACT_NO_CHARM		b13	/* Nie do oczarowania	*/ /* Lam */
#define ACT_NO_GIFTS		b14	/* Nie bierze prezentow */ /* Ulryk */
#define ACT_DONT_COME_BACK	b15	/* b01 nie wraca	*/ /* Lam */
#define ACT_DOOM_PROOF		b16	/* Zagladoodporny       */ /* Lam */

#define ACT_MOVED		b17	/* Dont ever set!       */

#define ACT_NOT_RACIST		b18	/* Nie jest rasista	*/ /* Lam */
#define ACT_NIE_POMAGA		b19	/* Nie pomaga grupie	*/ /* Lam */

/*
 * Bits for 'affected_by'.
 * Used in #MOBILES.
 */
#define AFF_BLIND		0
#define AFF_INVISIBLE		1
#define AFF_DETECT_EVIL		2
#define AFF_DETECT_INVIS	3
#define AFF_DETECT_MAGIC	4
#define AFF_DETECT_HIDDEN	5
#define AFF_HOLD		6
#define AFF_SANCTUARY		7
#define AFF_FAERIE_FIRE		8
#define AFF_INFRARED		9
#define AFF_CURSE		10
#define AFF_CHANGE_SEX		11
#define AFF_POISON		12
#define AFF_PROTECT		13
#define AFF_POLYMORPH		14
#define AFF_SNEAK		15
#define AFF_HIDE		16
#define AFF_SLEEP		17
#define AFF_CHARM		18
#define AFF_FLYING		19
#define AFF_PASS_DOOR		20
#define AFF_WATERWALK		21 /* nieuzywane */
#define AFF_SUMMONED		22 /* nieuzywane */
#define AFF_MUTE		23
#define AFF_GILLS		24
#define AFF_VAMP_BITE		25
#define AFF_GHOUL		26
#define AFF_FLAMING		27
#define AFF_BLACK_AURA		28	/* Lam */
#define AFF_DISORIENTATED	29	/* Skrytobojca */
#define AFF_SPOKOJ		30	/* Qwert */
#define AFF_LODOWA_TARCZA	31	/* Qwert */
#define AFF_PRZYSPIESZENIE	32	/* Qwert */
#define AFF_SPOWOLNIENIE	33	/* Qwert */
#define AFF_REGENERACJA		34	/* Qwert */
#define AFF_DEGENERACJA		35	/* Qwert */
#define AFF_DEZORIENTACJA	36	/* Qwert */
#define AFF_SLUGA		37	/* Ulryk */
#define AFF_GROZA		38	/* Ulryk */
#define AFF_MROK		39	/* Ulryk */
#define AFF_TARCZA_UMARLYCH	40	/* Ulryk */
#define AFF_POSTAC_NIETOPERZA	41	/* Lam */
#define AFF_ANIOL_STROZ		42	/* Gimza */
#define AFF_SWIETA_AURA		43	/* Gimza */
#define AFF_WRZACA_KREW		44	/* Gimza */
#define AFF_DOLADOWANIE		45	/* Gimza */
#define AFF_ILUZJA		46	/* Ulryk */
#define AFF_BRZECZY		47	/* Ulryk */
#define AFF_SZAL_BOJOWY		48	/* Ulryk */
#define AFF_ZABURZENIE_ENERGII	49	/* Ulryk */
#define AFF_BLOKADA_MENTALNA	50	/* Ulryk */
#define AFF_KONTROLA_NAD_WODA	51	/* Lam */
#define AFF_PRZEMIESZCZENIE	52	/* Lam */
#define AFF_TARCZA_ZLA		53	/* Lam */
#define MAX_AFF_FLAG		53 /* zawsze uaktualnic! */
#define AFF_FLAGS_SIZE   ( MAX_AFF_FLAG / BITS_PER_INT + 1 )

/*
 * Alandar: jak kumulowane sa wplywy
 */
#define ADD_AFFECT	0	/* czas i modyfikator liniowo */
#define ENH_AFFECT	1	/* czas i modyfikator malejaco */
#define ENH_TIME	2	/* modyfikator liniowo, a czas malejaco */
#define ENH_MOD		3	/* czas malejaco, a modyfikator liniowo */
#define ENH_MAX		4	/* Lam: odswiezanie - dobijanie do maksimum */

/*
 * Sex.
 * Used in #MOBILES.
 */
#define SEX_NEUTRAL	0
#define SEX_MALE	1
#define SEX_FEMALE	2

/*
 * Item types.
 * Used in #OBJECTS.
 */
/* najpierw to, co mamy z Diku */
#define ITEM_LIGHT                    1
#define ITEM_SCROLL                   2
#define ITEM_WAND                     3
#define ITEM_STAFF                    4
#define ITEM_WEAPON                   5
/* wolne 6 - w Diku: FIRE_WEAPON */
/* wolne 7 - w Diku: MISSILE */
#define ITEM_TREASURE                 8
#define ITEM_ARMOR                    9
#define ITEM_POTION                  10
/* wolne 11 - w Diku: WORN */
#define ITEM_FURNITURE               12
#define ITEM_TRASH                   13
/* wolne 14 - w Diku: TRAP */
#define ITEM_CONTAINER               15
#define ITEM_SWISTEK		     16 /* Lam 23.1.2006 - w Diku: NOTE */
#define ITEM_DRINK_CON               17 /* w Diku: LIQUID_CONTAINER */
#define ITEM_KEY                     18
#define ITEM_FOOD                    19
#define ITEM_MONEY                   20
/* wolne 21 - w Diku: PEN */
#define ITEM_BOAT                    22
/* nowosci Merca */
#define ITEM_CORPSE_NPC              23
#define ITEM_CORPSE_PC               24
#define ITEM_FOUNTAIN                25
#define ITEM_PILL                    26
/* wolne 27-29 */
/* nowosci Laca - zostawilem miejsce na jakies nowosci nowych
wersji Envy (dla zgodnosci krain) */
#define ITEM_PORTAL                  30
#define ITEM_SPELLBOOK		     31 /* Lam 25.9.98 (Lac 1.4.-8) */
#define ITEM_BEACON		     32 /* Lam 8.1.99 (1.4.-5, szamani) */
#define ITEM_SHOVEL		     33 /* Lam 24.3.99 (lopata do kopania) */
#define ITEM_DEVICE		     34 /* Lam 23.1.2006 */
#define ITEM_BANDYTA		     35 /* jednoreki bandyta */
/* po dodaniu do tej listy KONIECZNIE dodaj do create_object( ) (db.c).
   Uzupelnij tez typy_przedmiotow (const.c) */
#define ITEM_MAX		     36

/*
 * Extra flags.
 * Used in #OBJECTS.
 */
#define ITEM_GLOW		0
#define ITEM_HUM		1
#define ITEM_POM		2 /* Tissarius: przedmiot nalezacy do pomieszczenia */
#define ITEM_PRIVATE		3 /* przedmiot osobisty */
#define ITEM_EVIL		4
#define ITEM_INVIS		5
#define ITEM_MAGIC		6
#define ITEM_NODROP		7
#define ITEM_QUEST		8 /* Ulryk: moj pierwszy natchniony kod */
#define ITEM_ANTI_GOOD		9
#define ITEM_ANTI_EVIL		10
#define ITEM_ANTI_NEUTRAL	11
#define ITEM_NOREMOVE		12
#define ITEM_INVENTORY		13
#define ITEM_POISONED		14 /* tylko bronie, zatrute ostrze */
#define ITEM_VAMPIRE_BANE	15
#define ITEM_HOLY		16 /* zadaje obrazenia wampirowi (podczas brania) */
/* lacowe nowosci */
#define ITEM_LOYAL		17 /* nie da sie krasc, rozbrojenie do inw. */
#define ITEM_NORANDVALUES	18 /* nie losuja sie value[ ] */
#define ITEM_NO_LOCATE		19 /* lokalizowanie nie dziala (zadania) */
#define ITEM_BURIED		20 /* zakopane, trzeba odkopac */
#define ITEM_ANTI_MALE		21 /* antymeskie */
#define ITEM_ANTI_FEMALE	22 /* antyzenskie */
#define ITEM_ANTI_NEUTER	23 /* antynijakie */
#define ITEM_INVERT_RACES	24
#define ITEM_INVERT_CLASSES	25
#define ITEM_VANISH		26 /* znika przy wychodzeniu, jak ITEM_KEY */
#define ITEM_REINFORCED		27 /* Fuyara */
#define ITEM_FLAME		28 /* Qwert */
#define ITEM_CHAOS		29 /* Qwert */
#define ITEM_ICY		30 /* Qwert */
#define ITEM_MANA_LEECH         31 /* Gimza: bron ssaca mane z przeciwnika */
#define ITEM_PLAYER_SHOP	32 /* Lam */
#define ITEM_MAX_EXTRA_FLAG	32 /* zawsze uaktualnic! */
#define ITEM_EXTRA_FLAGS_SIZE   ( ITEM_MAX_EXTRA_FLAG / BITS_PER_INT + 1 )

/*
 * Wear flags.
 * Used in #OBJECTS.
 */
#define ITEM_TAKE		b00
#define ITEM_WEAR_FINGER	b01
#define ITEM_WEAR_NECK		b02
#define ITEM_WEAR_BODY		b03
#define ITEM_WEAR_HEAD		b04
#define ITEM_WEAR_LEGS		b05
#define ITEM_WEAR_FEET		b06
#define ITEM_WEAR_HANDS		b07
#define ITEM_WEAR_ARMS		b08
#define ITEM_WEAR_SHIELD	b09
#define ITEM_WEAR_ABOUT		b10
#define ITEM_WEAR_WAIST		b11
#define ITEM_WEAR_WRIST		b12
#define ITEM_WIELD		b13
#define ITEM_HOLD		b14
#define ITEM_WEAR_FACE		b15

/*
 * Apply types (for affects).
 * Used in #OBJECTS.
 */
#define APPLY_NONE                    0
#define APPLY_STR                     1
#define APPLY_DEX                     2
#define APPLY_INT                     3
#define APPLY_WIS                     4
#define APPLY_CON                     5
#define APPLY_SEX                     6
#define APPLY_CLASS                   7
#define APPLY_LEVEL                   8
#define APPLY_AGE                     9
#define APPLY_HEIGHT                 10
#define APPLY_WEIGHT                 11
#define APPLY_MANA                   12
#define APPLY_HIT                    13
#define APPLY_MOVE                   14
#define APPLY_GOLD                   15
#define APPLY_EXP                    16
#define APPLY_AC                     17
#define APPLY_HITROLL                18
#define APPLY_DAMROLL                19
#define APPLY_SAVING_PARA            20
#define APPLY_SAVING_ROD             21
#define APPLY_SAVING_PETRI           22
#define APPLY_SAVING_BREATH          23
#define APPLY_SAVING_SPELL           24
#define APPLY_RACE                   25
#define APPLY_SIZE                   26

/*
 * Typy wartosci, uzywane w typy_przedmiotow[ ] do okreslenia jak traktowac dana
 * wartosc.
 */
#define VAL_NORMAL      0
#define VAL_SPELL       1
#define VAL_MATERIAL    2
#define VAL_STRING      3
#define VAL_LIQUID      4

/*
 * Values for containers (value[1]).
 * Used in #OBJECTS.
 */
#define CONT_CLOSEABLE		b00
#define CONT_PICKPROOF		b01
#define CONT_CLOSED		b02
#define CONT_LOCKED		b03

/*
 * Room flags.
 * Used in #ROOMS.
 */
#define ROOM_DARK		b00
#define ROOM_NO_HUNT		b01 /* Lam - wypelniam dziury */
#define ROOM_NO_MOB		b02
#define ROOM_INDOORS		b03
#define ROOM_UNDERGROUND 	b04
#define ROOM_INVERT_RACES	b05 /* Lam */
#define ROOM_INVERT_CLASSES	b06 /* Lam */
#define ROOM_NO_TELEPORT	b07 /* Lam */
#define ROOM_FOG		b08 /* Lam */
/* #define ROOM_PRIVATE		b09 - nie uzywac ponownie -Lam */
#define ROOM_SAFE		b10
/* #define ROOM_SOLITARY	b11 - nie uzywac ponownie -Lam */
#define ROOM_PET_SHOP		b12
#define ROOM_NO_RECALL		b13
#define ROOM_CONE_OF_SILENCE	b14
#define ROOM_CLAN_HP		b15 /* Lam - nie uzywac w krainach! */
#define ROOM_CLAN_MANA		b16 /* Lam - jw. */
#define ROOM_NOTE_READ		b17 /* Lam - do czytania notek - nie glodnieje
						sie, ale tez sie nie odradza */
#define ROOM_PURGATORY		b18 /* Lam - odradza sie, ale nie glodnieje */
#define ROOM_REFRESH		b19 /* Lam - nie dla krain! Do ogniska */
#define ROOM_NO_SUMMON		b20 /* Lam - bez czarow przywolujacych, ale
					dziala / (powrot) */

/*
 * Directions.
 * Used in #ROOMS.
 *
 * Lam 31.5.98: kierunki posrednie: ne, se, nw, sw
 */
#define DIR_NORTH		0
#define DIR_EAST		1
#define DIR_SOUTH		2
#define DIR_WEST		3
#define DIR_UP			4
#define DIR_DOWN		5
#define DIR_NORTHEAST		6
#define DIR_SOUTHEAST		7
#define DIR_NORTHWEST		8
#define DIR_SOUTHWEST		9
#define MAX_DIR			10

/*
 * Flagi wyjsc. Wyjscia sa zrobione zle, nalezy je poprawic. Ponizej numery
 * wewnetrzne Laca, w krainach maja inne odpowiedniki.
 */
#define EX_ISDOOR		b00	/* to drzwi */
#define EX_CLOSED		b01	/* zamkniete */
#define EX_LOCKED		b02	/* zamkniete na klucz */
#define EX_BASHED		b03	/* wywazone */
#define EX_BASHPROOF		b04	/* nie da sie wywazyc */
#define EX_PICKPROOF		b05	/* nie dzialaja wytrychy */
#define EX_PASSPROOF		b06	/* nie da sie przenikac */
#define EX_DIG			b07	/* da sie odkopac/zakopac */
#define EX_BURIED		b08	/* jest zakopane */
#define EX_DONTRESET		b09	/* nie ma miec resetu, prog/spec */
#define EX_BEZKLAMKI		b10	/* z tej strony nie da sie otworzyc */
#define EX_BEZZAMKA		b11	/* z tej strony nie da sie odkluczyc */

/*
 * Sector types.
 * Used in #ROOMS.
 */
#define SECT_INSIDE                   0	/* Gimza: w przypadku nowych SECT pamietac o dodaniu */
#define SECT_CITY                     1	/* tlumaczenia do typy_podloza! */
#define SECT_FIELD                    2
#define SECT_FOREST                   3
#define SECT_HILLS                    4
#define SECT_MOUNTAIN                 5
#define SECT_WATER_SHALLOW            6
#define SECT_WATER_DEEP               7
#define SECT_UNDERWATER               8
#define SECT_AIR                      9
#define SECT_DESERT                  10
#define SECT_MAX                     11

#define CZY_ZIEMIA( room )	 ( room->sector_type != SECT_WATER_SHALLOW \
				&& room->sector_type != SECT_WATER_DEEP \
				&& room->sector_type != SECT_UNDERWATER \
				&& room->sector_type != SECT_AIR )
#define CZY_WODA( room )	 ( room->sector_type > SECT_MOUNTAIN \
				&& room->sector_type < SECT_AIR )
#define CZY_POD_WODA( room )	 ( room->sector_type == SECT_UNDERWATER )
#define CZY_DNO_POD_WODA( room ) ( room->sector_type == SECT_UNDERWATER \
				&& ( !room->exit[ DIR_DOWN ] \
				  || !room->exit[ DIR_DOWN ]->to_room ) )
#define CZY_POWIETRZE( room )	 ( room->sector_type == SECT_AIR )

/*
 * Equpiment wear locations.
 * Used in #RESETS.
 */
#define WEAR_NONE                    -1
#define WEAR_LIGHT                    0
#define WEAR_FINGER_L                 1
#define WEAR_FINGER_R                 2
#define WEAR_NECK_1                   3
#define WEAR_NECK_2                   4
#define WEAR_BODY                     5
#define WEAR_HEAD                     6
#define WEAR_LEGS                     7
#define WEAR_FEET                     8
#define WEAR_HANDS                    9
#define WEAR_ARMS                    10
#define WEAR_SHIELD                  11
#define WEAR_ABOUT                   12
#define WEAR_WAIST                   13
#define WEAR_WRIST_L                 14
#define WEAR_WRIST_R                 15
#define WEAR_WIELD                   16
#define WEAR_HOLD                    17
#define WEAR_WIELD_2                 18         /* Thelonius */
#define WEAR_FACE		     19		/* Lam */
#define MAX_WEAR                     20


/***************************************************************************
 *                                                                         *
 *                   VALUES OF INTEREST TO AREA BUILDERS                   *
 *                   (End of this section ... stop here)                   *
 *                                                                         *
 ***************************************************************************/

/*
 * Conditions.
 */
#define COND_DRUNK                    0
#define COND_FULL                     1
#define COND_THIRST                   2

/*
 * Positions.
 */
#define POS_DEAD                      0
#define POS_MORTAL                    1
#define POS_INCAP                     2
#define POS_STUNNED                   3
#define POS_SLEEPING                  4
#define POS_RESTING                   5
#define POS_FIGHTING                  6
#define POS_STANDING                  7

/*
 * ACT bits for players.
 */
#define PLR_IS_NPC		b00	/* Don't EVER set. */
#define PLR_BOUGHT_PET		b01
#define PLR_SHOPKEEPER		b02	/* Lam */
#define PLR_SHOP_BREAK		b03	/* Lam */
#define PLR_UZYJ_WYJDZ		b04	/* Lam */
/* wolne 5-11 */
#define PLR_HOLYLIGHT		b12
#define PLR_WIZINVIS		b13
#define PLR_NO_COLOUR		b14
#define PLR_SILENCE		b15
#define PLR_NO_EMOTE		b16
#define PLR_MOVED		b17	/* 131072, musi byc rowne ACT_MOVED */
#define PLR_NO_TELL		b18
#define PLR_LOG			b19
#define PLR_DENY		b20
#define PLR_FREEZE		b21
#define PLR_THIEF		b22
#define PLR_KILLER		b23
#define PLR_LOVE		b24     /* Qwert */
#define PLR_AFK			b25
#define PLR_CHCE_BYC_MORDERCA   b26
#define PLR_ZABOJCA		b27     /* Qwert */
#define PLR_WAMPIR_OD_URODZENIA b28
#define PLR_BOSKA_KUKLA		b29	/* Vigud */

/*
 * Bity ch->info
 */
#define INF_BUDOWNICZY		b02
#define INF_QUESTMASTER		b03
#define INF_LAMER		b04 /* na wniosek RenTora */
#define INF_MORS		b05 /* :) */
#define INF_CLAN_GUARD		b06 /* Cadaver: straznicy porzadku klanowego */
#define INF_STOPIEN_SHOW	b07 /* pokazywanie stopnia niezaleznie od poziomu */
#define INF_KARTOGRAF		b08
#define INF_LACSAKRA		b09

#define CZY_OPCJA( ch, op )	( ch->pcdata && IS_SET( ch->pcdata->opcje, op ) )

/*
 * Bity ch->pcdata->opcje. Zastepstwo ch->act w przypadku opcji.
 */
#define OPC_AUTOEXIT		b00	/* czy ktos ma to wylaczone? */
#define OPC_AUTOGOLD		b01
#define OPC_AUTOLOOT		b02
#define OPC_AUTOSAC		b03
#define OPC_AUTOSPLIT		b04
#define OPC_BLANK		b05
#define OPC_BRIEF		b06
#define OPC_CHYBIANIE		b07
#define OPC_CUTCP		b08
#define OPC_HINT		b09	/* Lam */
#define OPC_MIW			b10	/* Lam */
#define OPC_NO_SEPARATOR	b11	/* Lam */
#define OPC_PROMPT		b12
#define OPC_GWIAZDKI		b13	/* Lam */
#define OPC_SHOWLEVEL		b14
#define OPC_SHOWTICK		b15
/* #define OPC_TELNET_GA	b16 - archaizm */
#define OPC_UNIKI		b17
#define OPC_WRAP		b18	/* Lam */
#define OPC_CISZA		b19	/* Lam */
#define OPC_WCHODZENIE          b20     /* Ulryk */
#define OPC_ANGIELSKIE		b21	/* Lam */
#if defined( MAM_AUTOKLATWE )
# define OPC_AUTOKLATWA		b22	/* Lam */
#endif
#define OPC_POJEMNIKI		b23	/* Lam */
#define OPC_AUTOWCIEL		b24	/* Lam */
#define OPC_RUCH		b25	/* Lam */
#define OPC_CZASPP		b26	/* Vigud */
/* ... */
#define OPC_ODWROC		b31	/* Lam dla act( ) */

/*
 * Bity ch->pcdata->temp_flags - temp_flags nie zapisuja sie w pliku
 */
#define TEMPFLAG_DELETE		b00 /* chce sie skasowac		*/
#define TEMPFLAG_RESTART	b01 /* zamierza restart			*/
#define TEMPFLAG_BACKUP		b02 /* zrobiona kopia przy zapisie	*/
#define TEMPFLAG_DARK		b03 /* ciemno mu			*/
#define TEMPFLAG_BLIND		b04 /* oczy mu sie przyzwyczajaja	*/
#define TEMPFLAG_WOLACZ		b05 /* musi podac wolacz wchodzac	*/
#define TEMPFLAG_VAMPIRE        b06 /* moze wybrac rase wampira		*/
#define TEMPFLAG_MORDERCA       b07 /* w tym pulsie zostal morderca	*/
#define TEMPFLAG_ZABOJCA        b08 /* w tym pulsie zostal zabojca	*/
#define TEMPFLAG_WYMUSZENIE	b09 /* wymuszenie zmiany imienia	*/
#define TEMPFLAG_KMNKT_BWWU	b10 /* komunikat dla BWWU tracacych um. */

/*
 * Channel bits.
 */
#define CHANNEL_AUCTION		b00
#define CHANNEL_CHAT		b01
#define CHANNEL_GOD		b02
#define CHANNEL_HERO		b03
#define CHANNEL_MUSIC		b04
/* #define CHANNEL_QUESTION	b05 */
#define CHANNEL_SHOUT		b06
#define CHANNEL_YELL		b07
/* #define CHANNEL_NCHAT	b08 */
#define CHANNEL_GRATS		b09
#define CHANNEL_FLAME		b10
#define CHANNEL_CLAN		b11
#define CHANNEL_IM		b12
#define CHANNEL_IMMORTAL	b13
#define CHANNEL_NOIC		b31

/*
 * Bity okreslaja, co w przedmiocie nie pasuje do postaci.
 */
#define NOTHING_WRONG		0
#define WRONG_RACE		b00
#define WRONG_CLASS		b01
#define WRONG_PERSON		b02

/*
 * Structure types.
 */
typedef struct	affect_data		AFFECT_DATA;
typedef struct	airobj_data		AIROBJ_DATA;
typedef struct	airchar_data		AIRCHAR_DATA;	/* Alandar 12.11.2003 */
typedef struct	alias_data		ALIAS_DATA;
typedef struct	area_data		AREA_DATA;
typedef struct	auction_data		AUCTION_DATA;
typedef struct	ban_data		BAN_DATA;
typedef struct	char_data		CHAR_DATA;
typedef struct	clan_data		CLAN_DATA;
typedef struct	clan_member_data	CLAN_MEMBER_DATA;
typedef struct	cmd_type		CMD_TYPE;
typedef struct	deathtrap_data		DEATHTRAP_DATA;
typedef struct	descriptor_data		DESCRIPTOR_DATA;
typedef struct	exit_data		EXIT_DATA;
typedef struct	extra_descr_data	EXTRA_DESCR_DATA;
typedef struct	fight_data		FIGHT_DATA;
typedef struct	healer_data		HEALER_DATA;
typedef struct	help_data		HELP_DATA;
typedef struct	imiona_data		IMIONA_DATA;
typedef struct	kill_data		KILL_DATA;
typedef struct	koles_data		KOLES_DATA;
typedef struct	mob_index_data		MOB_INDEX_DATA;
typedef struct	note_data		NOTE_DATA;
typedef struct	obj_data		OBJ_DATA;
typedef struct	obj_index_data		OBJ_INDEX_DATA;
typedef struct	pc_data			PC_DATA;
typedef struct	refuse_data		REFUSE_DATA;
typedef struct	reset_data		RESET_DATA;
typedef struct	restart_data		RESTART_DATA;
typedef struct	restrykcje_data		RESTRYKCJE_DATA;
typedef struct	room_index_data		ROOM_INDEX_DATA;
typedef struct	schemat_data		SCHEMAT_DATA;
typedef struct	shop_data		SHOP_DATA;
typedef struct	tell_data		TELL_DATA;
typedef struct	timer_data		TIMER_DATA;
typedef struct	time_info_data		TIME_INFO_DATA;
typedef struct	weather_data		WEATHER_DATA;
typedef struct	who_descriptor_data	WHO_DESCRIPTOR_DATA;
typedef struct	zone_data		ZONE_DATA;
typedef struct	zone_list		ZONE_LIST;
typedef struct	zwod_data		ZWOD_DATA;

typedef struct	mob_prog_data		MPROG_DATA;
typedef struct	mob_trig_prog_data	MTRIG_DATA;
typedef struct	mpquest_data		MPQUEST_DATA;
typedef struct	room_rand_prog_data	RRAND_DATA;
/*
typedef struct	mob_prog_act_list	MPROG_ACT_LIST;
*/
typedef struct	typ_zmiennej		TYP_ZMIENNEJ;

/*
 * Function types.
 */
typedef void DO_FUN                     args( ( CHAR_DATA *ch,
					       char *argument ) );
typedef bool SPEC_FUN                   args( ( CHAR_DATA *ch ) );
/* Vigud: FIXME: powinno byc unsigned int level */
typedef bool SPELL_FUN                  args( ( int sn, int level,
					       CHAR_DATA *ch, void *vo,
					       int usage ) );
typedef void WEAR_OFF_FUN		args( ( CHAR_DATA *ch ) );
typedef void GAME_FUN                   args( ( CHAR_DATA *ch,
						CHAR_DATA *croupier,
						char *argument ) );
typedef void TIMER_FUN			args( ( TIMER_DATA *timer ) );
typedef void PROG_FUN		args( ( char* argument, CHAR_DATA* ch,
				       CHAR_DATA* actor, OBJ_DATA* obj,
				       CHAR_DATA* rndm, CHAR_DATA* vict,
				       OBJ_DATA* v_obj ) );


/* Lam */
#define KOMENDA( nazwa )	 void nazwa( CHAR_DATA *ch, char *argument )
#define CZAR( nazwa )		 bool nazwa( int sn, int level, \
						CHAR_DATA *ch, void *vo, \
						int usage )
#define SPADANIE( nazwa )	 void nazwa( CHAR_DATA *ch )
#define SPECJALNOSC( nazwa )	 bool nazwa( CHAR_DATA *ch )
#define GRA( nazwa )		 void nazwa( CHAR_DATA *ch, \
					CHAR_DATA *croupier, char *argument )
#define FUNKCJA_CZASOWA( nazwa ) void nazwa( TIMER_DATA *timer )
#define KOMENDA_KLANOWA( nazwa ) void nazwa( CHAR_DATA *ch, char *argument )
#define KOMENDA_PROGOWA( nazwa ) void nazwa( char* argument, CHAR_DATA* ch, \
				       CHAR_DATA* actor, OBJ_DATA* obj, \
				       CHAR_DATA* rndm, CHAR_DATA* vict, \
				       OBJ_DATA* v_obj )


struct bledomat_data
{
	bool wlaczony;
	char *adres;
	char *uzytkownik;
	char *haslo;
	char *baza;
	char *przedrostek;
	int bledy;
	int literowki;
	int pomysly;
};

/*
 * Time and weather stuff.
 */
#define SUN_DARK                    0
#define SUN_RISE                    1
#define SUN_LIGHT                   2
#define SUN_SET                     3

#define SKY_CLOUDLESS               0
#define SKY_CLOUDY                  1
#define SKY_RAINING                 2
#define SKY_LIGHTNING               3

struct time_info_data
{
    int         hour;
    int         day;
    int         month;
    int         year;
};

struct weather_data
{
    int         mmhg;
    int         change;
    int         sky;
    int         sunlight;
};

/*
 * Stale szpicla
 */
#define WIZ_ON		b00	/* wlaczenie/wylaczenie szpicla */
#define WIZ_DEATH	b01	/* smierc graczy */
#define WIZ_LEVEL	b02	/* robienie poziomow */
#define WIZ_LOGIN	b03	/* wchodzenie/wychodzenie */
#define WIZ_LINKS	b04	/* utrata polaczenia */
#define WIZ_MURDER	b05	/* nieregulaminowe ataki graczy, sciaganie */
#define WIZ_IDEA	b06	/* pomysl/literowka/blad */
#define WIZ_DEBUG	b07	/* rozne odpluskwiacze */
#define WIZ_IMMCMD	b08	/* oprocz logowania, zastapione WIZ_POL_* */
#define WIZ_PROGBUG	b09	/* progbug( ) */
#define	WIZ_POL_SMIE	b10	/* czy widac w ogole smiertelnikow */
#define WIZ_POL_SMWSZ	b11	/* czy widac wszystkie, a nie tylko logowane */
#define WIZ_POL_BOH	b12	/* czy widac bohaterskie/boskie */
#define WIZ_POL_BOHWSZ	b13	/* wszystkie, a nie tylko logowane */
#define WIZ_POL_PROG	b14	/* czy pokazywac polecenia podczas progow */
#define WIZ_ODM		b15	/* odmiana postaci przez przypadki */
#define WIZ_NOWI	b16	/* zakladanie nowych postaci */
#define WIZ_BUG		b17	/* zglaszanie bledow */

/*
 * Connected state for a channel.
 */
#define CON_PLAYING			 0
#define CON_GET_NAME			 1
#define CON_GET_OLD_PWD			 2
#define CON_CONFIRM_NEW_NAME		 3
#define CON_GET_NEW_PWD			 4
#define CON_CONFIRM_NEW_PWD		 5
#define CON_GET_NEW_RACE		 6
#define CON_CONFIRM_NEW_RACE		 7
#define CON_GET_NEW_SEX			 8
#define CON_GET_NEW_CLASS		 9
#define CON_CONFIRM_CLASS		10
#define CON_GET_MULTI			11  /* multi-profesje */
#define CON_CONFIRM_MULTI		12  /* jw. */
#define CON_GET_POLSKIE			13
#define CON_CONFIRM_POLSKIE		14
#define CON_READ_MOTD			15
#define CON_JUZ_GRAL_PWD_OK		16  /* juz gral, najpierw haslo */
#define CON_GET_OLD_PWD_GRAL		17  /* mowi, ze gral, ale czy to on? */

/* nie wstawiac niczego miedzy ponizsze 18-22, bo one sa obslugiwane inaczej
   przy utracie polaczenia (comm.c)! */
/* ustawiac ponizsze tylko po save_char_obj( d->character )! */
#define CON_GET_OLD_PWD_DELETE		18  /* chce sie skasowac, wiec haslo */
#define CON_GET_OLD_PWD_RESTART		19  /* restart (boski) - jw. */
#define CON_GET_OLD_PWD_PWD		20
#define CON_GET_NEW_PWD_PWD		21
#define CON_CONFIRM_NEW_PWD_PWD		22

/* Lam 29.11.98: nowe zakladanie postaci */
#define CON_GET_NEW_NAME		23
#define CON_GET_ODMIANA			24
#define CON_CONFIRM_ODMIANA		25
/* Lam 31.3.2002: strefy */
#define CON_GET_NEW_STREFA		26
#define CON_CONFIRM_STREFA		27
#define CON_READ_REGULAMIN		28
#define CON_UMOWA			29
#define CON_GET_WOLACZ			30
#define CON_CONFIRM_WOLACZ		31
/* adres email przy zakladaniu postaci */
#define CON_GET_EMAIL			32
#define CON_CONFIRM_EMAIL		33


/* czesci ciala przedstawiciela danej rasy */
#define P_NONE		  0 /* bezczesciowy */
#define P_FLAKI		b00
#define P_GLOWA		b01
#define P_RECE		b02
#define P_NOGI		b03
#define P_SERCE		b04
#define P_OGON		b05
#define P_SKRZYDLA	b06
#define P_USZY		b07
#define P_LAPA		b08
#define P_LEB		b09 /* niektorzy nie zasluguja na glowe :) */
#define P_ZAB		b10
#define P_KIEL		b11
#define P_ROG		b12
#define P_SZPON		b13
#define P_PLETWA	b14
#define P_JEZYK		  0 /* nie umiem wytlumaczyc jego odpadania od ciala */

#define P_HS		( P_FLAKI|P_GLOWA|P_RECE|P_NOGI|P_SERCE|P_JEZYK|P_USZY|P_ZAB )
/* wszystkie czesci czlekopodobne (Homo Sapiens) */

/* race_type->wearlocs, czyli gdzie dana rasa nie moze niczego zakladac */
#define WRL_HS		0
#define WRL_TRZYMANE	ITEM_HOLD
#define WRL_PALEC	ITEM_WEAR_FINGER
#define WRL_SZYJA	ITEM_WEAR_NECK
#define WRL_CIALO	ITEM_WEAR_BODY
#define WRL_GLOWA	ITEM_WEAR_HEAD
#define WRL_NOGI	ITEM_WEAR_LEGS
#define WRL_STOPY	ITEM_WEAR_FEET
#define WRL_DLONIE	ITEM_WEAR_HANDS
#define WRL_RAMIONA	ITEM_WEAR_ARMS
#define WRL_TARCZA	ITEM_WEAR_SHIELD
#define WRL_WOKOL	ITEM_WEAR_ABOUT
#define WRL_PAS		ITEM_WEAR_WAIST
#define WRL_NADGARSTEK	ITEM_WEAR_WRIST
#define WRL_BRON	ITEM_WIELD
#define WRL_TWARZ	ITEM_WEAR_FACE

/* Race ability bits */
#define RACE_NO_ABILITIES		  0
#define RACE_PC_AVAIL			b00
/* #define RACE_WATERBREATH		b01 - ODD_WODA */
/* #define RACE_FLY			b02 - POR_POWIETRZE */
/* #define RACE_SWIM			b03 - POR_WODA */
/* #define RACE_WATERWALK		b04 - POR_WODA | POR_POWIETRZE */
#define RACE_PASSDOOR			b05
#define RACE_INFRAVISION		b06
#define RACE_DETECT_EVIL		b07
#define RACE_DETECT_INVIS		b08
#define RACE_DETECT_HIDDEN		b09
#define RACE_PROTECTION			b10
#define RACE_SANCT			b11
#define RACE_WEAPON_WIELD		b12
#define RACE_MUTE			b13
#define RACE_NO_MOUTH			b14	/* Alandar: nie moze jesc */
#define RACE_POISONIMM			b15	/* Alandar: odporne na trucizne */
#define RACE_OPENS_DOORS		b16	/* Baarian */
#define RACE_NO_BLOOD			b17	/* Muzgus */
#define RACE_PROTECT_GOOD		b18	/* Lam */
#define RACE_NO_CORPSE			b19     /* Ulryk: nie zostawia zwlok */
#define RACE_NO_EYES			b20	/* Lam: nie da sie oslepic */
/* #define RACE_NIE_ODDYCHA		b21 - wystarczy ustawic oba ODD_ */
#define RACE_BEZ_SLUCHU			b22	/* Lam */
#define RACE_BEZ_WECHU			b23	/* Lam */
#define RACE_WOLI_LATAC			b24	/* Lam */
#define RACE_WOLI_PLYWAC		b25	/* Lam */

/* oddychanie */
#define ODD_POWIETRZEM			b01
#define ODD_WODA			b02

/* poruszanie */
#define POR_POD_WODA			b01 /* nurkowanie */
#define POR_PO_WODZIE			b02 /* plywanie po powierzchni */
#define POR_LAD				b03 /* poruszanie ladem */
#define POR_POWIETRZE			b04 /* latanie, implikuje lad i nad woda */
/* chociaz latanie implikuje lad i nad woda, warto ustawic LAD | POWIETRZE,
   dzieki temu bedziemy mogli zrobic, ze moby z samym POWIETRZE beda odfruwac
   nawet z pomieszczen ladowych, a LAD | POWIETRZE odchodzic */

/* zmiana koncepcji: bez LAD postac z samym POWIETRZE nie moglaby chodzic po
   dnie wody */

/*
 * Descriptor (channel) structure.
 *
 * Sporo zmian wprowadzonych przez Lama
 * Lam 6.11.2000: liczniki wejscia i wyjscia
 * Lam 24.11.2001: char * -> char[ ], zeby welcome( ) nie psulo sterty SSM-a
 */
struct descriptor_data
{
    DESCRIPTOR_DATA *   next;
    DESCRIPTOR_DATA *   snoop_by;
    DESCRIPTOR_DATA *	nast_na_poz;
    CHAR_DATA *         character;
    CHAR_DATA *         original;
    char		host		[ 256 ];
    int			port;
    char		login		[ 384 ];
    unsigned int        descriptor;
/*    unsigned int	addr; */
    int                 connected;
    int			idle;
    bool                fcommand;
    char                inbuf           [ BUF_LIMIT_INBUF ];
    char                incomm          [ MAX_INPUT_LENGTH ];
    char                inlast          [ MAX_INPUT_LENGTH ];
    char                predlast        [ MAX_INPUT_LENGTH ];
/*    int                 repeat; */
    int			polskie;
    char *		showstr_head;
    char *		showstr_point;
    char *		outbuf;
    int                 outsize;
    int                 outtop;
    char		user		[ CONN_USER_LEN ];
    char		term_type	[ CONN_TERM_LEN ];
    char		lsc_host	[ 256 ];
    char		lsc_user	[ 128 ];
    char		ipaddr		[ 32 ];
    int			szer;	/* pobrane z NAWS */
    int			wys;	/* jw. */
    int			wej_znaki;
    int			wej_linie;
    int			wyj_znaki;
    int			wyj_linie;
#if !defined( MSDOS )
    volatile int	welcome_state;
# if !defined( NO_PTHREADS )
    pthread_t		thread;
# endif
#endif
    int			telnet_state;
    bool		nowe_dane;
    bool		wait;
/*    bool		char_mode; */
    char		kolor;
};

/*
 * Analogiczna struktura do polaczen z portem HTTP (pierwotnie tylko who)
 */
struct who_descriptor_data
{
    WHO_DESCRIPTOR_DATA *next;
    unsigned int	descriptor;
    char		host[ 256 ];
    char                odnosnik[ MIL ];
    char                zapytanie[ MIL ];
    char                klient[ MSL ];
    char                referer[ MSL ];
    int			idle;
    char		*outbuf;
    int			outsize;
    int			outtop;
    bool		cts; /* clear to send */
};

/*
 * TO types for act.
 */
#define TO_ROOM             0
#define TO_NOTVICT          1
#define TO_VICT             2
#define TO_CHAR             3
#define ACT_TELEP         b06

/*
 * Shop types.
 */
/* nie przenosze do config.h, bo by nikt nie zrozumial co to znaczy */
#define MAX_TRADE        5

struct shop_data
{
    int         keeper;                 /* Vnum of shop keeper mob      */
    int         buy_type [ MAX_TRADE ]; /* Item types shop will buy     */
    int         profit_buy;             /* Cost multiplier for buying   */
    int         profit_sell;            /* Cost multiplier for selling  */
    int         open_hour;              /* First opening hour           */
    int         close_hour;             /* First closing hour           */
    bool	quest_shop;		/* Lam 1.1.2004			*/
};

/*
 * Lam: Sprzedawcy czarow - sciagalem ze sklepow, ale tylko troche ;)
 */
struct healer_data
{
    int		keeper;			/* vnum of spell-selling mob	*/
    int		spells [ 5 ];		/* Spells to cast		*/
    int		cost   [ 5 ];		/* Costs of spell casting	*/
};


/* stale note_data->vote */
#define VOTE_NO		0	/* nie da sie glosowac   */
#define VOTE_OPEN	1	/* otwarte glosowanie    */
#define VOTE_CLOSED	2	/* zakonczone glosowanie */

/*
 * Gimza: odmow
 */
struct refuse_data
{
    REFUSE_DATA		*next;	     	      /* nastepne zablokowane polecenie */
    char		refused_cmd[ 30 ];    /* nazwa polecenia */
    char		who[ 40 ];   	      /* kto zabanowal */
    char		why[ 80 ];	      /* za co zabanowal */
    char		date[ 15 ];	      /* data akcji */
};

/*
 * Lam 3.6.2004: historia restartow
 */
struct restart_data
{
    RESTART_DATA	*nast;
    char		*wpis;
};

/*
 * Ulryk 18.03.2007: ustrukturalizowane restrykcje
 */
struct restrykcje_data
{
    char	* od;		/* od kiedy, od kogo itp... to, co dotychczas */
    time_t	  do_kiedy;	/* do kiedy */
};

/*
 * Prototype for a mob.
 * This is the in-memory version of #MOBILES.
 */
struct mob_index_data
{
    MOB_INDEX_DATA *    next;
    MOB_INDEX_DATA *	next_in_area;	/* Lam */
    AREA_DATA *		index_area;	/* Lam */
    SPEC_FUN *          spec_fun;
    GAME_FUN *		game_fun;	/* Lam */
    SHOP_DATA *         pShop;
    HEALER_DATA *	pHealer;
    MPROG_DATA *	mobprogs;
    char *              player_name;
    char *              short_descr;
    char *              long_descr;
    char *              dopelniacz;
    char *              celownik;
    char *              biernik;
    char *              narzednik;
    char *              miejscownik;
    char *              wolacz;
    char *              description;
    int                 vnum;
    int			progtypes;
    int			resetcount;	/* Lam */
    int                 count;
    int                 killed;
    unsigned int        sex;
    int                 level;
    int                 act;
    int                 affected_by[ AFF_FLAGS_SIZE ];
    int                 alignment;
    int                 race;
    int			zamoznosc;	/* Lam */
    int			grupa;		/* Lam */
    int			mod_size;	/* Lam */
};

/*
 * One character (PC or NPC).
 */
struct char_data
{
    CHAR_DATA *         next;
    CHAR_DATA *         next_in_room;
    CHAR_DATA *         master;
    ZWOD_DATA *		zwod_master;	/* Lam */
    CHAR_DATA *         leader;
    ZWOD_DATA *		zwod_leader;	/* Lam */
    CHAR_DATA *         reply;
    ZWOD_DATA *		zwod_reply;	/* Lam */
    CHAR_DATA *		retell;		/* Lam */
    ZWOD_DATA *		zwod_retell;	/* Lam */
    CHAR_DATA *         monitor;	/* Lam */
    ZWOD_DATA *		zwod_monitor;	/* Lam */
    CHAR_DATA *		hunting;	/* Lam */
    ZWOD_DATA *		zwod_hunting;	/* Lam */
    CHAR_DATA *		hating;		/* Lam */
    ZWOD_DATA *		zwod_hating;	/* Lam */
    CHAR_DATA *		fearing;	/* Lam */
    ZWOD_DATA *		zwod_fearing;	/* Lam */
    CHAR_DATA *		debugger;	/* Lam */
    ZWOD_DATA *		zwod_debugger;	/* Lam */
    FIGHT_DATA *        fighting;       /* Ulryk */
    SPEC_FUN *          spec_fun;
    MOB_INDEX_DATA *    pIndexData;
    AREA_DATA *		area;		/* Lam */
    DESCRIPTOR_DATA *   desc;
    AFFECT_DATA *       affected;
    ZWOD_DATA *		zwod_affected;	/* Lam */
    ALIAS_DATA *	alias;		/* Lam */
    TELL_DATA *		tell;		/* Lam */
    MPQUEST_DATA *	mpquest;	/* Lam */
    TYP_ZMIENNEJ *	zmienne;	/* Lam */
    ZWOD_DATA *		zwod_zmienne;	/* Lam */
    NOTE_DATA *         pnote;
    OBJ_DATA *          carrying;
    OBJ_DATA *          przechowalnia;	/* Lam */
    ROOM_INDEX_DATA *   in_room;
    ROOM_INDEX_DATA *	reset_room;	/* Lam */
    PC_DATA *           pcdata;
    OBJ_DATA *		pojazd;		/* Lam */
/*    MPROG_ACT_LIST *	mpact;
    int			mpactnum; */	/* Lam: act_proga nie ma */
    char *              name;
    char *              short_descr;
    char *              dopelniacz;	/* Lam */
    char *              celownik;	/* Lam */
    char *              biernik;	/* Lam */
    char *              narzednik;	/* Lam */
    char *              miejscownik;	/* Lam */
    char *              wolacz;		/* Lam */
    char *              long_descr;
    char *		long_descr_orig;/* Fuyara */
    char *		false_name;     /* disguise */
    char *              description;
    int                 race;
    int                 level;
    int                 trust;
    int                 played;
    time_t              logon;
    time_t              save_time;
    time_t              last_note;
    int                 timer;
    int                 wait;
    int                 hit;
    int                 max_hit;
    int			hit_remainder;	/* Lam */
    int                 mana;
    int                 max_mana;
    int			mana_remainder;	/* Lam */
    int                 move;
    int                 max_move;
    int			move_remainder;	/* Lam */
    int                 mod_str;	/* Lam 13.1.2004: mod_* z pc_data */
    int                 mod_int;
    int                 mod_wis;
    int                 mod_dex;
    int                 mod_con;
    int                 gold;
    int                 exp;
    int			qp;		/* Lam */
    int                 act;
    int                 affected_by[ AFF_FLAGS_SIZE ];
    int                 info;		/* Lam */
    int                 carry_weight;
    int                 carry_number;
    int                 saving_throw;
    int                 hitroll;
    int                 damroll;
    int                 armor;
    int                 marmor;		/* magiczna zbroja */
    int                 wimpy;
    int                 deaf;
    int			practice;
    int			alignment;
    unsigned int	sex;
    int			klasa;
    int			position;
    int			polskie;	/* Lam: standard polskich znakow */
    int			kolor;		/* Lam */
    int			podswietl;	/* Vigud */
    int			odmiana;	/* Lam */
    int			brzeczenie;
    char                separator;	/* Albi i Lam */
    char		reply_type;	/* Lam */
    char		retell_type;	/* Lam */
    bool                deleted;
};

/*
 * Data which only PC's have.
 */
struct pc_data
{
    PC_DATA	      * next;
    ZONE_DATA	      * strefa;		/* Lam */
    FILE	      * fLog;		/* Ulryk */
    ROOM_INDEX_DATA   * was_in_room;	/* przeniesione z char_data */
    ROOM_INDEX_DATA   * ic_in_room;	/* Lam */
    REFUSE_DATA	      * refuse;		/* Gimza */
    RESTART_DATA      * restart;	/* Lam */
    CLAN_DATA	      * clan;		/* Ulryk */
    CLAN_MEMBER_DATA  * clan_member;	/* Ulryk */
    struct
    {
	char   * pochodzenie;
	char   * strefa;
	int	 rasa;
	int	 ile;		/* liczba zwampirzen */
	int	 moc;		/* jak bardzo rozcienczona ma krew */
    }                   wampiryzm;
    char	      * pwd;
    char	      * bamfin;
    char	      * bamfout;
    char	      * immskll;
    char	      * title;
    char	      * prompt;
    char	      * fprompt;	/* Lam */
    char	      * stopien;	/* Lam */
    char	      * login;		/* Lam */
    char	      * last_login;	/* Lam */
    char	      * email;		/* Lam */
    RESTRYKCJE_DATA	love;		/* Qwert */
    RESTRYKCJE_DATA	silence;	/* Lam */
    RESTRYKCJE_DATA	noemote;	/* Lam */
    RESTRYKCJE_DATA	nocolour;	/* Lam */
    RESTRYKCJE_DATA	notell;		/* Lam */
    RESTRYKCJE_DATA	log;		/* Lam */
    RESTRYKCJE_DATA	freeze;		/* Lam */
    RESTRYKCJE_DATA	deny;
    char	      * thief_from;	/* Lam */
    char	      * killer_from;	/* Lam */
    char	      * zabojca_from;	/* Qwert */
    char	      * ignore;		/* Lam */
    char	      * pojedynek;	/* Lam */
    char	      * nienawisc;	/* Qwert */
    char	      * szpic_wybr;	/* Lam */
    char	      * szpic_wykl;	/* Lam */
    int			wiznet;		/* Lam */
    int                 killed;		/* Lam */
    int                 dead;		/* Lam */
    int			pkilled;	/* Lam */
    int			pdead;		/* Lam */
    int			samobojstwa;	/* Lam */
    int			wykrwawienia;	/* Lam */
    int                 perm_str;
    int                 perm_int;
    int                 perm_wis;
    int                 perm_dex;
    int                 perm_con;
    int                 condition       [ 3 ];
    int                 pagelen;
    int			bank;		/* Lam */
    int			hint;		/* Lam */
    int                 learned         [ MAX_SKILL ];
    int			used		[ MAX_SKILL ];	/* Lam */
    int			learned_level	[ MAX_SKILL ];	/* Lam */
    char		kolor		[ MIL ];	/* Lam */
    int			multi		[ 5 ];		/* Lam */
    int			temp_flags;	/* Lam */
    int			opcje;		/* Lam */
    int			wizinvis;	/* Lam */
    int                 niesmpoz;	/* Ulryk */
    int			ic_position;	/* Lam */
    int                 hp_angel;	/* Gimza */
    int			odwleczenie;	/* Lam */
    int			ost_end;	/* Tissarius */
    char	      * ostatnie[ MAX_OSTATNIE ];	/* Tissarius */
    bool                switched;
};


#define ERROR_PROG		 -1
#define IN_FILE_PROG		  0

/* #define M_ACT_PROG		b00 */
#define M_SPEECH_PROG		b01
#define M_RAND_PROG		b02
#define M_FIGHT_PROG		b03
#define M_DEATH_PROG		b04
#define M_HITPRCNT_PROG		b05
#define M_ENTRY_PROG		b06
#define M_GREET_PROG		b07
#define M_ALL_GREET_PROG	b08
#define M_GIVE_PROG		b09
#define M_BRIBE_PROG		b10
#define M_TRIG_PROG		b11
#define M_SOC_PROG		b12
#define M_TIME_PROG		b13
#define M_TELL_PROG		b14
#define M_SAY_PROG		b15
#define M_STEAL_PROG		b16
#define M_STEAL_FAIL_PROG	b17
#define M_ASLEEP_TIME_PROG	b18
#define M_DESCR_PROG		b19
#define M_FEED_PROG		b20 /* Alandar 21.12.2004: reaguje na karmienie */
#define M_WATER_PROG		b21 /* Alandar 21.12.2004: reaguje na pojenie */
#define M_SPELL_VICTIM_PROG	b22
#define M_LONG_DESCR_PROG	b23
#define M_AGGR_ATTACK_PROG	b24

#define R_SPEECH_PROG		b00
#define R_GREET_PROG		b01
#define R_LOOK_PROG		b02
#define R_DO_PROG		b03
#define R_DESCR_PROG		b04
#define R_DROP_PROG		b05
#define R_TIME_PROG		b06
#define R_RAND_PROG		b07
#define R_UNDUG_PROG		b08

#define E_PASS_PROG		b00
#define E_OPEN_PROG		b01
#define E_CLOSE_PROG		b02
#define E_LOCK_PROG		b03
#define E_UNLOCK_PROG		b04
#define E_PICK_PROG		b05
#define E_BASH_PROG		b06
#define E_DIG_PROG		b07
#define E_BOUNCE_PROG		b08

#define O_TAKE_PROG		b00
#define O_DROP_PROG		b01
#define O_WEAR_PROG		b02
#define O_REMOVE_PROG		b03
#define O_BUY_PROG		b04
#define O_SELL_PROG		b05
#define O_USE_PROG		b06
#define O_GIVE_PROG		b07
#define O_PUT_PROG		b08
#define O_DIG_PROG		b09
#define O_PUTIN_PROG		b10
#define O_SACR_PROG		b11
#define O_DONATE_PROG		b12
#define O_STEAL_PROG		b13
#define O_STEAL_FAIL_PROG	b14
#define O_PUTIN_GOLD_PROG	b15 /* Tissarius 22.10.2001 */
#define O_OPEN_PROG		b16 /* Alandar 21.12.2004: do pojemnikow */
#define O_CLOSE_PROG		b17 /* jw. */
#define O_DESCR_PROG		b18 /* Lam, #2169 */
#define O_LONG_DESCR_PROG	b19 /* jw. */

/* typ zmiennej */
struct typ_zmiennej
{
    TYP_ZMIENNEJ *nast;
    char nazwa[ 31 ];   /* max. 30 znakow */
    int typ;            /* 0 - int, 1 - char * */
    union
    {
	int i;        /* dla lancuchow wskaznik, dla liczb wartosc */
	void *p;
    } wartosc;
};

/*
 * Struktura informacji o drogach prowadzacych do roznych krain.
 */
struct koles_data
{
    KOLES_DATA		*nast;
    int			 vnum;
    int			 droga;
    struct koles_type
    {
	char	*nazwa;
	char	*droga;
    } drogi[ MAX_TRACK ];
};

/*
 * Extra description data for a room or object.
 */
struct extra_descr_data
{
    EXTRA_DESCR_DATA *next;        /* Next in list                     */
    char             *keyword;     /* Keyword in look/examine          */
    char             *description; /* What to see                      */
    bool              deleted;
};

/*
 * Prototype for an object.
 */
struct obj_index_data
{
    OBJ_INDEX_DATA *    next;
    OBJ_INDEX_DATA *	next_in_area;	/* Lam */
    AREA_DATA *		area;		/* Lam */
    AFFECT_DATA *       affected;
    MPROG_DATA *	mobprogs;
    int			progtypes;
    char *              name;
    char *              short_descr;
    char *              dopelniacz;
    char *              celownik;
    char *              biernik;
    char *              narzednik;
    char *              miejscownik;
    char *              description;
    char *		look_descr;	/* Lam: zamiast extra_descr */
    char *              action;
    char *		anti_class;	/* Lac 1.4.-7 */
    char *		anti_race;	/* Lac 1.4.-7 */
    int                 vnum;
    int                 item_type;
    int                 extra_flags[ ITEM_EXTRA_FLAGS_SIZE ];
    int                 wear_flags;
    int                 count;
    int                 weight;
    int                 cena;			/* Lam: to dla sklepow */
    int                 poziom;			/* to tez */
    int			qp;			/* Lam 9.4.2000 */
    int                 rodzaj; /* 1 meski, 2 zenski, 3 niemeskoosobowy */
    /* Lam 7.11.2004: Lac musi sie kompilowac na systemach 64-bitowych, ale
       nie chce zmieniac int na int albo long long (z #ifami), zeby nie
       zmieniac wszystkich printfow w kodzie w zaleznosci od architektury. */
    union
    {
	int		v;
	void *		p;
    } value[ 6 ];				/* 4 --> 6, Lac 1.4.-7 */
    int			min_reset_level;	/* Lam 16.5.2000 */
    int			wielkosc;		/* Lam 22.11.2000 */
    bool		w_sklepie;		/* Lam 13.5.2005 */
};

/*
 * Przedmiot.
 */
struct obj_data
{
    OBJ_DATA *          next;
    OBJ_DATA *          next_content;
    OBJ_DATA *          contains;
    OBJ_DATA *          in_obj;
    CHAR_DATA *         carried_by;
    CHAR_DATA *         owned_by;	/* przechowalnia */
    AFFECT_DATA *       affected;
    OBJ_INDEX_DATA *    pIndexData;
    ROOM_INDEX_DATA *   in_room;
    char *              name;
    char *              short_descr;
    char *              dopelniacz;
    char *              celownik;
    char *              biernik;
    char *              narzednik;
    char *              miejscownik;
    char *              description;
    char *		look_descr;	/* Lam */
    char *              action;
    char *		anti_class;	/* Lam 3.5.2003: kopiowanie do przedmiotu */
    char *		anti_race;	/* jw. */
    char *              owner;          /* Ulryk 04.01.2005: przedmioty osobiste */
    int			item_type;
    int                 extra_flags[ ITEM_EXTRA_FLAGS_SIZE ];
    int                 wear_flags;
    int			wear_loc;
    int                 weight;
    int                 cost;
    int			plr_shop_cost;
    int                 level;
    int                 timer;
    int			rodzaj; /* 1 meski, 2 zenski, 3 niemeskoosobowy */
    union
    {
	int		v;
	void *		p;
    } value[ 6 ];
/*    int                 value   [ 6 ]; */
    bool                deleted;
};

/*
 * Exit data.
 */
struct exit_data
{
    EXIT_DATA *		next;		/* tylko do listy wolnych wyjsc */
    ROOM_INDEX_DATA *   to_room;
    int                 vnum;
    int                 exit_info;
    int                 key;
    int                 rodzaj; /* 0 nijaki, 1 meski, 2 zenski, 3 niemos. */
    char *              keyword;
    char *              short_descr;	/* ... jest zamkniety/a, sa zamkniete */
    char *              biernik;	/* otwierasz ... */
    char *              description;
    MPROG_DATA *	mobprogs;	/* eprogs Lam */
    int			progtypes;
};

/*
 * Reset commands:
 *   '*': comment
 *   'M': read a mobile
 *   'O': read an object
 *   'P': put object in object
 *   'G': give object to mobile
 *   'E': equip object to mobile
 *   'D': set state of door
 *   'R': randomize room exits
 *   'S': stop (end of list)
 */

/*
 * Area-reset definition.
 */
struct reset_data
{
    RESET_DATA *        next;
    char                command;
    int                 arg1;
    int                 arg2;
    int                 arg3;
    char *		string;
};

/*
 * Lam 27.11.2000: wreszcie dlugo wyczekiwane strefy
 */
struct zone_data
{
    ZONE_DATA *next;
    char *nazwa;
    char *dopelniacz;
    char *celownik;
    char *biernik;
    char *narzednik;
    char *miejscownik;
    char *stolica;
    char *stol_dop;
    char *stol_cel;
    char *stol_bie;
    char *stol_narz;
    char *stol_mie;
    char *wladca;
    char *namiestnik;
    char *rasy;
    int przywolanie;
    int swiatynia;
    int szkola;
    int ile_krain;
    int ile_mobow;
    int ile_przedmiotow;
    int ile_pomieszczen;
};


struct zone_list
{
    ZONE_DATA *zone;
    ZONE_LIST *next;
};

/*
 * Area definition.
 */
struct area_data
{
    AREA_DATA *         next;
    RESET_DATA *        reset_first;
    RESET_DATA *        reset_last;
    TYP_ZMIENNEJ *	zmienne;	/* Lam */
    ZONE_LIST *		strefy;		/* Lam */
    ROOM_INDEX_DATA *	first_room;	/* Lam */
    ROOM_INDEX_DATA *	last_room;	/* Lam */
    MOB_INDEX_DATA *	first_mob;	/* Lam */
    MOB_INDEX_DATA *	last_mob;	/* Lam */
    OBJ_INDEX_DATA *	first_obj;	/* Lam */
    OBJ_INDEX_DATA *	last_obj;	/* Lam */
    char *              name;
    char *		full_name;	/* Lam */
    char *		file_name;	/* Lam */
    char *		reset_msg;	/* Lam */
    char *		opis;		/* Lam */
    char *		revision;	/* Lam */
    int			version;	/* Lam */
    int                 recall;
    int                 age;
    int                 nplayer;
    int			numofrooms;	/* Lam */
    int			numofmobs;	/* Lam */
    int			numofobjs;	/* Lam */
    int                 lowroomvnum;    /* Lam */
    int                 highroomvnum;   /* Lam */
    int                 lowmobvnum;     /* Lam */
    int                 highmobvnum;    /* Lam */
    int                 lowobjvnum;     /* Lam */
    int                 highobjvnum;    /* Lam */
    int			lowmoblevel;	/* Lam */
    int			highmoblevel;	/* Lam */
    int			lowgroupvnum;	/* Lam */
    int			highgroupvnum;	/* Lam */
    int			flags;		/* Lam */
    TIME_INFO_DATA	time_info;	/* Lam */
    WEATHER_DATA	weather_info;	/* Lam */
    bool		odnowiona;	/* Lam */
};

/*
 * Room type.
 */
struct room_index_data
{
    ROOM_INDEX_DATA *   next;
    ROOM_INDEX_DATA *	next_in_area;	/* Lam */
    ROOM_INDEX_DATA *   next_track;
    ROOM_INDEX_DATA *   track_came_from;
    CHAR_DATA *         people;
    OBJ_DATA *          contents;
    EXTRA_DESCR_DATA *  extra_descr;
    AREA_DATA *		area;
    DEATHTRAP_DATA *	trap;		/* Lam */
    EXIT_DATA *         exit[ 10 ];	/* Lam (bylo 6) */
    MPROG_DATA *	mobprogs;	/* Lam */
    AFFECT_DATA *       affected;
    int			progtypes;	/* Lam */
    char *              name;
    char *		miejscownik;	/* Lam */
    char *              description;
    char *		anti_race;	/* Lam */
    char *		anti_class;	/* Lam */
    int                 vnum; /* Vigud: FIXME: to powinno byc unsigned */
    int                 room_flags;
    /* ponizsze do zapisywania w pliku krainy bez wplywow np. strefa ciszy */
    int                 original_room_flags; /* Lam */
    /* pojemnosc zamiast obecnych w Envy flag SOLITARY i PRIVATE */
    int			pojemnosc;	/* Lam */
    int			strata_ruchu;	/* Lam */
    int                 light;
    int                 sector_type;
};

/*
 * Types of attacks.
 * Must be non-overlapping with spell/skill types,
 * but may be arbitrary beyond that.
 */
#define TYPE_UNDEFINED		  -1
#define TYPE_UNDEF_ZZ		  -2 /* jak UNDEFINED, ale liczy zwykly zgon */
#define TYPE_HIT		1000

/* argument typ_zgonu dla raw_kill */
#define ZGON_ZWYKLY		   0
#define ZGON_GRACZ		   1
#define ZGON_SAMOBOJSTWO	   2
#define ZGON_WYKRWAWIENIE	   3

/*
 * Ulryk: flagi umiejetnosci i czarow
 */
#define SKILL_NORMAL		   0
#define SKILL_NO_DISPEL		 b00
#define SKILL_FRIENDLY_DISPEL	 b01
#define SKILL_INVISIBLE		 b02
#define SKILL_KUPOWALNE		 b03
#define SKILL_NPC		 b04 /* Lam */
#define SKILL_PSI_SELF		 b05 /* Lam */
#define SKILL_DEF_VICT		 b06 /* Lam */
#define SKILL_NO_COST		 b07 /* Lam */

/*
 *  Target types.
 */
#define TAR_IGNORE                  0
#define TAR_CHAR_OFFENSIVE          1
#define TAR_CHAR_DEFENSIVE          2
#define TAR_CHAR_SELF               3
#define TAR_OBJ_INV                 4

/*
 * Usage types.
 */
#define USAGE_CAST		 0 /* do_cast, zwykle czarowanie */
#define USAGE_HEALER		 1 /* do_buy, kupowanie czarow */
#define USAGE_WAND		 2 /* do_zap, wyzwalanie rozdzek */
#define USAGE_STAFF		 3 /* do_brandish, wyzwalanie bulaw i podobnych */
#define USAGE_PILL		 4 /* do_eat, jedzenie pigulek */
#define USAGE_POTION		 5 /* do_drink (stare do_quaff), picie mikstur */
#define USAGE_SCROLL		 6 /* do_recite, recytacja pergaminow */
#define USAGE_SHIELD		 7 /* damage, odpowiadanie tarcz na ataki */
#define USAGE_WEAPON		 8 /* damage, magiczne bronie */
#define USAGE_BREATH		 9 /* pc_breathe, specjalnosci graczy */
#define USAGE_SPECIAL		10 /* spec_*, specjalnosci mobow */
#define USAGE_RECUR		11 /* rekurencja, czar jako dodatek drugiego */
#define USAGE_GAME		12 /* wygrana w kole fortuny */


/*
 * Utility macros.
 */
#define UMIN( a, b )            ( ( a ) < ( b ) ? ( a ) : ( b ) )
#define UMAX( a, b )            ( ( a ) > ( b ) ? ( a ) : ( b ) )
#define URANGE( a, b, c )       ( ( b ) < ( a ) ? ( a )                       \
						: ( ( b ) > ( c ) ? ( c )     \
								  : ( b ) ) )
#define ABSOLUTE( a )		( ( a ) > 0 ? ( a ) : 0 - ( a ) )
#define LOWER( c )              ( ( c ) >= 'A' && ( c ) <= 'Z'                \
						? ( c ) + 'a' - 'A' : ( c ) )
#define UPPER( c )              ( ( c ) >= 'a' && ( c ) <= 'z'                \
						? ( c ) + 'A' - 'a' : ( c ) )
#define IS_SET( flag, bit )     ( ( flag ) &   ( bit ) )
#define SET_BIT( var, bit )     ( ( var )  |=  ( bit ) )
#define REMOVE_BIT( var, bit )  ( ( var )  &= ~( bit ) )

/*
 * Wektory bitow, wersja Lama, powstala w wyniku burzy mozgow z Ulrykiem
 * trwajacej pol nocy.
 *
 * Nasza implementacja tym sie rozni od innych, ktore widzielismy, ze umozliwia
 * rozna wielkosc kazdego z wektorow - jeden wektor moze miec wielkosc 1 dopoki
 * nie ma potrzeby jego rozszerzenia, inny 2, a inny 3. Porownaj to ze
 * Smaugiem, gdzie kazdy wektor zajmuje 16 bajtow, a kiedy chocby w jednym
 * skonczy sie miejsce, trzeba powiekszac wszystkie.
 */
#define IS_SET_V( flag, bit ) \
	( ( flag[ ( bit ) >> MOVE_BITS ] >> ( ( bit ) & INT_MASK ) ) & 1 )
/* chcialbym COMPILER_ASSERT( ( bit ) <= sizeof( flag ) * BITS_PER_INT, za_duza_wartosc_flagi_dla_SET_BIT_V );
   ale wtedy bit nie moze byc zmienna, a musi stala (typu AFF_BLABLA)
   gcc z -Wunreachable-code bezblednie wykrywa te linie, gdzie nie ma potrzeby
   sprawdzania, ale czy mozna wykryc te, gdzie wlasnie jest? ;) */
#define SET_BIT_V( flag, bit ) \
	do {  if ( ( bit ) <= sizeof( flag ) * BITS_PER_INT ) \
	    flag[ ( bit ) >> MOVE_BITS ] |= ( (unsigned) 1 << ( ( bit ) & INT_MASK ) ); \
	    else bug( "SET_BIT_V: ogromny bit", 0 ); \
	} while ( 0 )
#define REMOVE_BIT_V( flag, bit ) \
	do {  if ( ( bit ) <= sizeof( flag ) * BITS_PER_INT ) \
	    flag[ ( bit ) >> MOVE_BITS ] &= ~( 1 << ( ( bit ) & INT_MASK ) ); \
	    else bug( "SET_BIT_V: ogromny bit", 0 ); \
	} while ( 0 )
#define CLEAR_BITS( flag ) \
	do {	unsigned int ibvc; \
		for ( ibvc = 0; ibvc < ( sizeof( flag ) / SIZEOF_INT ); ibvc++ ) \
			flag[ ibvc ] = 0; } while ( 0 )
#define COPY_BITS( to, from ) \
	do {	unsigned int ibvc; \
		COMPILER_ASSERT( sizeof( from ) == sizeof( to ), niezgodna_wielkosc_flag_w_COPY_BITS ); \
		for ( ibvc = 0; ibvc < ( sizeof( from ) / SIZEOF_INT ); ibvc++ ) \
			to[ ibvc ] = from[ ibvc ]; } while ( 0 )
#define OR_BITS( to, from ) \
	do {	unsigned int ibvc; \
		COMPILER_ASSERT( sizeof( from ) == sizeof( to ), niezgodna_wielkosc_flag_w_OR_BITS ); \
		for ( ibvc = 0; ibvc < ( sizeof( from ) / SIZEOF_INT ); ibvc++ ) \
			to[ ibvc ] |= from[ ibvc ]; } while ( 0 )
#define AND_BITS( to, from ) \
	do {	unsigned int ibvc; \
		COMPILER_ASSERT( sizeof( from ) == sizeof( to ), niezgodna_wielkosc_flag_w_AND_BITS ); \
		for ( ibvc = 0; ibvc < ( sizeof( from ) / SIZEOF_INT ); ibvc++ ) \
			to[ ibvc ] &= from[ ibvc ]; } while ( 0 )
#define AND_NOT_BITS( to, from ) \
	do {	unsigned int ibvc; \
		COMPILER_ASSERT( sizeof( from ) == sizeof( to ), niezgodna_wielkosc_flag_w_AND_NOT_BITS ); \
		for ( ibvc = 0; ibvc < ( sizeof( from ) / SIZEOF_INT ); ibvc++ ) \
			to[ ibvc ] &= ~from[ ibvc ]; } while ( 0 )
/* nie sprawdza, czy nie ma roznicy wielkosci :( FIXME: zrobic funkcje */
#define SAME_BITS( a, b ) ( !memcmp( a, b, sizeof( a ) ) )
#define fread_vector( flag, file, stat ) \
	do { CLEAR_BITS( flag ); \
	real_fread_vector( flag, sizeof( flag ) / SIZEOF_INT, file, stat ); \
	} while ( 0 )
#define rozpisz_flagi_v( flag, czy ) \
	rozpisz_flagi_v_fun( flag, sizeof( flag ) * 8, czy )

/*
 * Teoretycznie jest mozliwe, ze miedzy fclose a fopen wstrzeli sie np.
 * connect( ) z welcome( ) w innym watku, co jest mozliwe przy jakims porzadnym
 * "pakietowaniu", a kolejne fopen( ) nie otworzy fpReserve/fpBugReserve.
 * Zabezpieczam sie przed tym do pewnego stopnia - i tak jesli plik nie zostal
 * poprzednio pomyslnie otwarty i nie wyjdzie fclose, funkcje korzystajace
 * z tego moga miec problem z wlasnym fopen( ). No ale bez tego byla mozliwosc
 * wywalenia Laca doprowadzajac do dwukrotnego fclose( fpReserve ).
 */
#define zamknij_reserve( fp ) \
	do {	if ( fp ) \
		{ \
			fclose( fp ); \
			fp = NULL; \
		} } while ( 0 )

/*
 * Makra dla splaszczenia systemu monetarnego.
 */
#define ZYSK( poziom, mnoznik )		\
			( ( przelicznik_zysku[ URANGE( 0, poziom, 111 ) ] \
						* mnoznik ) >> 10 )
#define WYDATEK( poziom, mnoznik )	\
			( ( przelicznik_wydatkow[ URANGE( 0, poziom, 111 ) ] \
						* mnoznik ) >> 10 )

/*
 * Character macros.
 */
#define NIEUDANE( kto ) STC( "Nie uda`lo ci si`e.\n\r", kto )
#define NIEUDANE_BC( kto ) do { if IS_AFFECTED( kto, AFF_DETECT_MAGIC ) \
			STC( "To niczego nie da.\n\r", kto ); \
		   else STC( "Nie uda`lo ci si`e.\n\r", kto ); } while ( 0 )
#define WZMOCNIONY( kto, sn, warunek ) do { if ( warunek ) \
		{ ch_printf( ch, "Zwi`ekszasz moc czaru \"%s\".\n\r", \
				skill_table[ sn ].pl_name ); \
		return TRUE; } } while ( 0 )
#define DAMAGEBEZWALKI( ch, victim, usage ) \
				 ( ch == victim \
				&& ( usage == USAGE_PILL \
				  || usage == USAGE_POTION ) )

#define IS_NPC( ch )            ( IS_SET( ( ch )->act, ACT_IS_NPC ) )
#define IS_IMMORTAL( ch )       ( !IS_NPC( ch ) && ch->level >= LEVEL_IMMORTAL )
#define IS_HERO( ch )           ( get_trust( ch ) >= LEVEL_HERO )
#define IS_AFFECTED( ch, bit )	( IS_SET_V( ( ch )->affected_by, ( bit ) ) )

#define IS_GOOD( ch )           ( ch->alignment >=  350 )
#define IS_EVIL( ch )           ( ch->alignment <= -350 )
#define IS_NEUTRAL( ch )        ( !IS_GOOD( ch ) && !IS_EVIL( ch ) )

#define IS_AWAKE( ch )          ( ch->position > POS_SLEEPING )
#define ZDOLNY_DO_WALKI( ch )	( ( ch )->position > POS_STUNNED )
#define GET_AC( ch )            ( UMAX( 0, ch->armor ) )
#define GET_MAC( ch )		( UMAX( 0, ch->marmor ) )
#define GET_ST( ch )		( UMAX( 0, ch->saving_throw ) )
/* Ulryk */
#define LICZ_BU( ch, wield )	( zetnij( interpolate( ch->level, 40, 55 ),  \
					interpolate( ch->level, 75, 100 ),   \
					get_hitroll( ch, wield ) ) )
#define LICZ_BO( ch, wield )	( zetnij( interpolate( ch->level, 20, 200 ), \
					interpolate( ch->level, 10, 100 ),   \
					get_damroll( ch, wield ) ) )
#define LICZ_OPC( ch )		( ( zetnij( 50, 33, GET_ST( ch ) )           \
				+ ( IS_NPC( ch )                             \
				 || class_table[ ch->klasa ].fMana ) )       \
				? wis_app[ get_curr_wis( ch ) ].opc : 0 )
#define LICZ_MINUS_TT( ch )	( ( zetnij( 34, 100, GET_AC( ch ) )          \
				  + zetnij( 34,                              \
				    str_app[ get_curr_str( ch ) ].carry / 10,\
				    ch->carry_weight ) ) / 2 )
#define LICZ_WYPAROWANIE_KP( ch, dam )                                       \
				( dam - zetnij( 2 * dam / 3, 500,            \
				GET_MAC( ch ) + 2 * GET_AC( ch ) ) )
#define LICZ_WYPAROWANIE_OPC( ch, dam )                                      \
				( dam - zetnij( 3 * dam / 4, 50,             \
				  LICZ_OPC( ch ) ) )

#define IS_OUTSIDE( ch )        ( !IS_SET(                                   \
				    ( ch )->in_room->room_flags,             \
				    ROOM_INDOORS ) )
#define IS_HASTE( ch, czas )	( IS_AFFECTED( ch, AFF_PRZYSPIESZENIE )    \
				  ? ( ( czas ) / 2 ) : 0 )
#define IS_SLOW( ch, czas )	( IS_AFFECTED( ch, AFF_SPOWOLNIENIE )      \
				  ? ( ( czas ) / 2 ) : 0 )

/* Lam: do { } while ( 0 ) bez srednika, zeby mozna bylo uzywac jak funkcji */
#define WAIT_STATE( ch, pulse ) do { ( ch )->wait = UMAX( ( ch )->wait,      \
						      ( pulse -		     \
						IS_HASTE( ch, pulse ) +      \
						IS_SLOW( ch, pulse ) ) );    \
				PRZERWIJ_KOPANIE( ch, TRUE ); } while ( 0 )
#define PRZERWIJ_KOPANIE( ch, czy_widac )				     \
	{ if ( find_timer( ch, finish_digging ) )      			     \
	  { if ( czy_widac )						     \
	      send_to_char( "{RPrzerywasz przekopywanie pod`lo`za.{x\n\r", ch ); \
	    del_timer( find_timer( ch, finish_digging ) ); } }
#define PRZERWIJ_KARMPOJ( xch, czy_widac )	{ TIMER_DATA *timer;	\
	for ( timer = timer_list; timer; timer = timer->next )		\
	    if ( ( timer->fun == przestan_karmic 			\
		|| timer->fun == przestan_poic )			\
	      && ( ( CHAR_DATA * ) timer->arg[ 0 ].p == xch		\
		|| timer->ch == xch ) )					\
	    {	del_timer( timer );					\
		if ( timer->ch == xch && czy_widac )			\
		    timer->fun( timer ); } }


/* Lam: moby maja 0 dla kazdego czaru */
#define MANA_COST( ch, sn )     ( IS_NPC( ch ) ? 0 \
				: UMAX ( skill_table[ sn ].min_mana, \
				    100 / ( 2 + UMAX ( 0, ch->level - \
				    ch->pcdata->learned_level[ sn ] ) ) ) \
				  * ( IS_AFFECTED( ch, AFF_ZABURZENIE_ENERGII ) \
				      ? 2 : 1 ) \
				  / ( ch->pcdata->learned[ gsn_profesjonalizm ] \
				      ? 2 : 1 ) )

/*
 * Lam, zeby nie powtarzac, dla czarow SKILL_NO_COST.
 *
 * Uwaga! Czary SKILL_NO_COST MUSZA uzywac RZUCENIE_CZARU( ) ZANIM nastapia
 * jakiekolwiek ich efekty! Oprocz tego, ze najpierw musi sie wywolac
 * say_spell( ) z tego makra, to opoznienie_czaru( ) zawiera nauke
 * profesjonalizmu.
 */
#define RZUCENIE_CZARU( ch, sn, usage ) do { \
    if ( usage == USAGE_CAST ) \
    {	ch->mana -= MANA_COST( ch, sn ); \
	opoznienie_czaru( ch, sn ); \
	say_spell( ch, sn ); \
    } } while ( 0 )

#define SPELL_LEVEL( ch, level )( ( ch ) && !IS_NPC( ch ) && ( level ) >= L_DIR \
					? ( level ) \
					: URANGE( 1, ( level ), LEVEL_HERO ) )

#define IS_SWITCHED( ch )	( ch->pcdata->switched )

#define CZY_UTF_8( ch )		( ch->polskie == POLSKIE_UTF_8 )

#define STREFA( ch )		( IS_NPC( ch ) \
				? ch->area->strefy \
				  ? ch->area->strefy->zone \
				  : NULL \
				: ch->pcdata->strefa )
#define POCHODZENIE( ch )	( IS_NPC( ch ) \
				? ( ch->area->strefy \
				  ? ch->area->strefy->zone->dopelniacz \
				  : "(brak strefy krainy!)" ) \
				: ( ch->pcdata->strefa \
				  ? ch->pcdata->strefa->dopelniacz \
				  : "(brak strefy gracza)" ) )
/* do progow, wszedzie indziej uzywany dopelniacz */
#define POCHODZENIE_M( ch )	( IS_NPC( ch ) \
				? ( ch->area->strefy \
				  ? ch->area->strefy->zone->nazwa \
				  : "(brak)" ) \
				: ( ch->pcdata->strefa \
				  ? ch->pcdata->strefa->nazwa \
				  : "(brak)" ) )
#define PRZYWOLANIE( ch )	( ch->in_room->area->recall \
				? ch->in_room->area->recall \
				: ( IS_NPC( ch ) \
				  ? ( ch->area->strefy \
				    ? ch->area->strefy->zone->przywolanie \
				    : ROOM_VNUM_TEMPLE ) \
				  : ( ch->pcdata->strefa \
				    ? ch->pcdata->strefa->przywolanie \
				    : ROOM_VNUM_TEMPLE ) ) )
/* do progowego recall( ), bez uwzgledniania krainy */
#define PRZYWOLANIE_P( ch )	( IS_NPC( ch ) \
				  ? ( ch->area->strefy \
				    ? ch->area->strefy->zone->przywolanie \
				    : ROOM_VNUM_TEMPLE ) \
				  : ( ch->pcdata->strefa \
				    ? ch->pcdata->strefa->przywolanie \
				    : ROOM_VNUM_TEMPLE ) )
/* do progowego temple( ) */
#define SWIATYNIA( ch )		( IS_NPC( ch ) \
				  ? ( ch->area->strefy \
				    ? ch->area->strefy->zone->swiatynia \
				    : ROOM_VNUM_TEMPLE ) \
				  : ( ch->pcdata->strefa \
				    ? ch->pcdata->strefa->swiatynia \
				    : ROOM_VNUM_TEMPLE ) )

/* czy jest w postaci? */
#define WP( ch )		 ( ch->in_room \
				&& ch->in_room->vnum != ROOM_VNUM_POZA_SWIATEM )
/* czy jest poza postacia? */
#define PP( ch )		( !WP( ch ) )

#define CZY_WAMPIR( ch )	 ( ch->race == zr_wampir \
				|| IS_AFFECTED( ch, AFF_POSTAC_NIETOPERZA ) )

/* Tyche, via Vigud: Digital Mars was unable to expand the PERS macros when the
   FIGHTING macro was passed to it. */
#if defined( __DMC__ ) || defined( PLAN9 )
# define FIGHTING( ch )		fighting_func( ch )
#else
# define FIGHTING( ch )		( ch->fighting ? ch->fighting->vch : NULL )
#endif
/* brak tlenu jesli:
  - jest pod woda i nie ma oddychania woda
  - nie jest ani pod woda, ani w wodzie, a nie ma oddychania powietrzem
    (bo wszedzie poza woda jest u nas powietrze)
  kazdy inny przypadek - umie pobierac tlen (na wodzie ma wybor nosnika) */
#define CZY_BRAK_TLENU_W_POM( ch, room ) \
	       ( !IS_IMMORTAL( ch ) \
	      && ( ( room->sector_type == SECT_UNDERWATER \
		  && !IS_AFFECTED( ch, AFF_GILLS ) \
		  && !IS_SET( race_table[ ch->race ].oddychanie, ODD_WODA ) ) \
		|| ( !IS_SET( race_table[ ch->race ].oddychanie, ODD_POWIETRZEM ) \
		  && !CZY_WODA( room ) ) ) )
#define CZY_BRAK_TLENU( ch ) CZY_BRAK_TLENU_W_POM( ch, ch->in_room )
/* przy zmianach w CZY_PALACE_SLONCE zaktualizowac wykrywacz w reset_area! */
#define CZY_PALACE_SLONCE_W_POM( ch, room ) \
	       ( CZY_WAMPIR( ch ) \
	      && ( room->area->weather_info.sunlight == SUN_RISE \
		|| room->area->weather_info.sunlight == SUN_LIGHT ) \
	      && !IS_SET( room->room_flags, ROOM_UNDERGROUND ) \
	      && room->sector_type != SECT_UNDERWATER \
	      && !IS_IMMORTAL( ch ) )
#define CZY_PALACE_SLONCE( ch ) CZY_PALACE_SLONCE_W_POM( ch, ch->in_room )
#define IS_MUTE( ch ) \
		 ( WP( ch ) \
		&& ( IS_AFFECTED( ch, AFF_MUTE ) \
		  || IS_SET( race_table[ ch->race ].race_abilities, RACE_MUTE ) \
		  || CZY_BRAK_TLENU( ch ) ) )
#define CAN_TALK( ch ) \
		 ( !IS_MUTE( ch ) \
		&& ( !ch->in_room \
		  || !IS_SET( ch->in_room->room_flags, ROOM_CONE_OF_SILENCE ) ) )
#define CAN_HEAR_ROOM( ch, room ) \
		 ( IS_AWAKE( ch ) \
		&& !IS_SET( room->room_flags, ROOM_CONE_OF_SILENCE ) \
		&& !IS_SET( race_table[ ch->race ].race_abilities, RACE_BEZ_SLUCHU ) )
#define CAN_HEAR( ch )	CAN_HEAR_ROOM( ch, ch->in_room )
#define CAN_SMELL( ch ) \
		 ( IS_AWAKE( ch ) && !CZY_BRAK_TLENU( ch ) \
		&& !IS_SET( race_table[ ch->race ].race_abilities, RACE_BEZ_WECHU ) )
#define HAS_INFRAVISION( ch ) \
		 ( IS_AFFECTED( ch, AFF_INFRARED ) \
		|| IS_SET( race_table[ ch->race ].race_abilities, RACE_INFRAVISION ) )
/* zakladamy, ze rasy ze skrzydlami lataja dzieki nim, czyli jesli postac nie
   ma wplywu "latanie", nie moze spac (chwilowo moze odpoczywac), bo spadnie */
#define IS_FLYING( ch ) \
		 ( IS_AFFECTED( ch, AFF_FLYING ) \
		|| ( IS_SET( race_table[ ch->race ].poruszanie, POR_POWIETRZE ) \
		  && ( !IS_SET( race_table[ ch->race ].parts, P_SKRZYDLA ) \
		    || IS_AWAKE( ch ) ) ) )
#define HAS_DETECT_HIDDEN( ch ) \
		 ( IS_AFFECTED( ch, AFF_DETECT_HIDDEN ) \
		|| IS_SET( race_table[ ch->race ].race_abilities, RACE_DETECT_HIDDEN ) )
#define HAS_DETECT_INVIS( ch ) \
		 ( IS_AFFECTED( ch, AFF_DETECT_INVIS ) \
		|| IS_SET( race_table[ ch->race ].race_abilities, RACE_DETECT_INVIS ) )
#define HAS_DETECT_EVIL( ch ) \
		 ( IS_AFFECTED( ch, AFF_DETECT_EVIL ) \
		|| ( IS_SET( race_table[ ch->race ].race_abilities, RACE_DETECT_EVIL ) \
		  && IS_GOOD( ch ) ) \
		|| ( ch->klasa == CLASS_PALADYN ) )
#define IS_PASSING( ch ) \
		 ( IS_AFFECTED( ch, AFF_PASS_DOOR ) \
		|| IS_SET( race_table[ ch->race ].race_abilities, RACE_PASSDOOR ) )
#define HAS_PROTECTION( ch ) \
		 ( IS_AFFECTED( ch, AFF_PROTECT ) \
		|| IS_SET( race_table[ ch->race ].race_abilities, RACE_PROTECTION ) )
#define HAS_PROTECT_GOOD( ch ) \
		 ( IS_AFFECTED( ch, AFF_TARCZA_ZLA ) \
		|| IS_SET( race_table[ ch->race ].race_abilities, RACE_PROTECT_GOOD ) )
#define HAS_SANCTUARY( ch ) \
		 ( IS_AFFECTED( ch, AFF_SANCTUARY ) \
		|| IS_SET( race_table[ ch->race ].race_abilities, RACE_SANCT ) )
#define ROZMIAR( ch ) \
		 ( ( !IS_NPC( ch ) && ch->race == zr_wampir \
		  && ch->pcdata->wampiryzm.rasa != -1 ) \
		   ? race_table[ ch->pcdata->wampiryzm.rasa ].size \
		   : ( !IS_NPC( ch ) \
		     ? race_table[ ch->race ].size \
		     : race_table[ ch->race ].size + ch->pIndexData->mod_size ) )

#define CZY_MA_TWARZ( ch ) \
		( !IS_SET( race_table[ ch->race ].wearlocs, WRL_TWARZ ) )

/*
 * Object macros.
 */
#define CAN_WEAR( obj, part )   ( IS_SET( ( obj )->wear_flags, ( part ) ) )
#define IS_OBJ_STAT( obj, stat )( IS_SET_V( ( obj )->extra_flags, ( stat ) ) )

/*
 * Description macros.
 */
/*
#define PERS( ch, looker )      ( can_see( looker, ( ch ) ) ?                \
				( IS_NPC( ch ) ? ( ch )->short_descr         \
					       : ( ch )->name ) : "someone" )
*/
#define PERS( ch, looker, tel )  ( ( ( tel ) \
					? can_see_who( ( looker ), ( ch ) ) \
					: can_see( ( looker ), ( ch ) ) ) ? \
				   ( ch )->short_descr  : "kto`s" )
#define PERSD( ch, looker, tel ) ( ( ( tel ) \
					? can_see_who( ( looker ), ( ch ) ) \
					: can_see( ( looker ), ( ch ) ) ) ? \
				   ( ch )->dopelniacz   : "kogo`s" )
#define PERSC( ch, looker, tel ) ( ( ( tel ) \
					? can_see_who( ( looker ), ( ch ) ) \
					: can_see( ( looker ), ( ch ) ) ) ? \
				   ( ch )->celownik     : "komu`s" )
#define PERSB( ch, looker, tel ) ( ( ( tel ) \
					? can_see_who( ( looker ), ( ch ) ) \
					: can_see( ( looker ), ( ch ) ) ) ? \
				   ( ch )->biernik      : "kogo`s" )
#define PERSN( ch, looker, tel ) ( ( ( tel ) \
					? can_see_who( ( looker ), ( ch ) ) \
					: can_see( ( looker ), ( ch ) ) ) ? \
				   ( ch )->narzednik    : "kim`s" )
#define PERSM( ch, looker, tel ) ( ( ( tel ) \
					? can_see_who( ( looker ), ( ch ) ) \
					: can_see( ( looker ), ( ch ) ) ) ? \
				   ( ch )->miejscownik  : "kim`s" )
#define PERSW( ch, looker, tel ) ( ( ( tel ) \
					? can_see_who( ( looker ), ( ch ) ) \
					: can_see( ( looker ), ( ch ) ) ) ? \
				   ( ch )->wolacz       : "ktosiu" )


/* trzeci parametr interpret( ) */
#define INTERP_NORMAL	  0
#define INTERP_FORCE	  1
#define INTERP_AT	  2
#define INTERP_MANY	  3
#define INTERP_ORDER	  4
#define INTERP_MPROG	100
#define INTERP_MPFORCE	101
#define INTERP_MPAT	102
#define CMD_NOTLISTED	b05

/* MobC: mob_c.c, mob_var.c */
/* typy zmiennych */
#define TZ_CALK		0 /* calkowita */
#define TZ_ZNAK		1 /* znakowa (lancuch) */
#define TZ_POST		2 /* postac */
#define TZ_PRZE		3 /* przedmiot */


#ifdef __cplusplus
}
#endif
