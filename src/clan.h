/*
 * Malven: klany, na bazie klanow Lama
 */
#define MAX_CLAN_NAME	    40
#define MAX_CLAN_DOPELNIACZ 40
#define MAX_PLAYER_NAME     12  /* Malven: 12 za check_parse_name( ) w nanny.c */

#if defined( unix )
# define MAX_CLAN_DIR   MAX_CLAN_NAME
#else
# define MAX_CLAN_DIR   8
#endif

/*
 * Stany klanow - Malven:
 * uszkodzony - brak jakiegos pliku lub niezbednego klucza w pliku dane.cln
 * usuniety - czlonkowie zostaja usunieci z klanu
 * zawieszony - przez SPK lub bogow, czlonkowie pozostaja w klanie ale wszystkie
 *		polecenia zablokowane
 * nowy - zanim zostanie zatwierdzony przez SPK, polecenia zablokowane
 * aktywny - zatwierdzony przez SPK
 * pomoc_usuwany - status pomocniczy wykorzystywany przy usuwaniu klanu, taka
 *		wartosc nie moze istniec w pliku
 */
#define CLAN_STAT_USZKODZONY		0
#define CLAN_STAT_USUNIETY		1
#define CLAN_STAT_ZAWIESZONY		2
#define CLAN_STAT_NOWY			3
#define CLAN_STAT_AKTYWNY		4
#define CLAN_STAT_POMOC_USUWANY		-1

/*
 * Stale przynaleznosci do klanu (ch->pcdata->clan_level)
 */
#define CLAN_NONE	 -1  /* bez klanu */
#define CLAN_GUEST        0  /* kandydat do zapisania sie */
#define CLAN_MEMBER       1  /* normalny czlonek klanu */
#define CLAN_HERO         5  /* bohater klanu */
#define CLAN_MASTER       7  /* mistrz klanu */

/*
 * Flagi klanu (clan->flags)
 * clanroom nie ma flagi, tylko clan->room to pokazuje. Potem juz tymi bitami:
 */
#define CLAN_FLAG_BEDROOM	b00  /* pomieszczenie do leczenia */
#define CLAN_FLAG_HP		b01  /* pomieszczenie z zyciem */
#define CLAN_FLAG_MANA		b02  /* pomieszczenie z mana */
#define CLAN_FLAG_LIBRARY	b03  /* klan ma biblioteke */
#define CLAN_FLAG_PIT		b04  /* klan posiada wlasna urne */

/*
 * Malven: flagi polecen klanowych
 */
#define CLAN_CMD_SPKONLY	b00  /* tylko dla SPK i bogow */
#define CLAN_CMD_UKRYTE		b01  /* polecenie nie wyswietla sie na liscie polecen */
#define CLAN_CMD_OOC		b02  /* moze byc wykonywane poza postacia */
#define CLAN_CMD_NOIC		b03  /* nie moze byc wykonywane w postaci */
#define CLAN_CMD_SPK		b04  /* SPK i bogowie moga wykonywac na specjalnych warunkach */

/*
 * Flagi zapisu
 */
#define CLAN_WRITE_ALL          b00 | b01 | b02 | b03 /* zapisanie wszystkiego */
#define CLAN_WRITE_DANE		b00  /* podstawowe dane klanu */
#define CLAN_WRITE_LISTA	b01  /* lista klanowiczow */
#define CLAN_WRITE_STOSUNKI	b02  /* stosunki miedzyklanowe */
#define CLAN_WRITE_SKRZYNIA	b03  /* skrzynia klanowa */

/*
 * znaczenia zmiennej rel->pokoj
 */
#define CLAN_POKOJ_BRAK		0	/* nie bylo deklaracji pokoju */
#define CLAN_POKOJ_DEKLARACJA	1	/* zlozona deklaracja pokoju */
#define CLAN_POKOJ_ODRZUCONY	2	/* odrzucona deklaracja pokoju */
#define CLAN_POKOJ_MAX		2

/*
 * Malven: stosunki miedzyklanowe
 */
/*CLAN_REL_DATA * clan_rel_lookup( CLAN_DATA *clana, CLAN_DATA *clanb );*/

typedef struct clan_rel_data  CLAN_REL_DATA;
typedef void CLAN_FUN                   args( ( CHAR_DATA *ch, char *argument ) );

struct clan_rel_data
{
    CLAN_REL_DATA * next;	/* nastepny na liscie */
    CLAN_DATA     * clan;	/* drugi klan */
    bool war;
    int             stosunek;	/* stosunek do drugiego klanu */
    int             wpkill;	/* liczba zabojstw w trakcie tej wojny */
    int             wpdead;     /* liczba zgonow w trakcie tej wojny */
    int	            pkill;	/* liczba zabojstw w sumie */
    int	            pdead;	/* liczba zgonow w sumie */
};

/*
 * Struktura listy klanowiczow
 */
struct clan_member_data
{
    CLAN_MEMBER_DATA  * next;		/* nastepny klanowicz */
    CHAR_DATA	      * ch;		/* jesli gra, to nam na niego wskaze */
    char              * name;		/* imie */
    short               level;		/* poziom klanowy */
    int			zloto;		/* wplacone zloto */
    int			punkty;		/* wplacone punkty klanowe */
    time_t		seen;		/* kiedy ostatnio byl widziany */
#if 0
    int			skll;		/* umiejetnosci klanowe */
    int			pkill;		/* tyle razy zabil dla klanu */
    int			pdead;		/* tyle razy zginal za klan */
#endif
};

/*
 * Struktura klanu
 */
struct clan_data
{
    CLAN_DATA	      * next;         /* nastepny klan na liscie */
    int			status;       /* stan klanu */
    char	      * name;         /* pelna nazwa klanu */
    char	      * dop;          /* dopelniacz nazwy */
    char	      * dir;          /* katalog klanu */
    char	      * info;         /* informacja o klanie */
    char              * statut;       /* statut klanu */
    char	      *	skrot;        /* skrot nazwy klanu */
    char	      * data_zal;     /* data zalozenia klanu */
    CLAN_MEMBER_DATA  * member_list;  /* lista czlonkow wraz ze stopniami */
    CLAN_REL_DATA     * rel_list;     /* lista stosunkow z innymi klanami */
    char	      * lev_name_mm[ 10 ]; /* nazwy stopni - meski mianownik */
    char	      * lev_name_zm[ 10 ]; /* zenski mianownik */
    char	      * lev_name_md[ 10 ]; /* meski dopelniacz */
    char	      * lev_name_zd[ 10 ]; /* zenski dopelniacz */
    char	      * lev_name_mn[ 10 ]; /* meski narzednik */
    char	      * lev_name_zn[ 10 ]; /* zenski narzednik */
    int			gold;         /* konto bankowe klanu */
    int			punkty;       /* punkty klanowe */
#if 0
    char	      * area;	      /* kraina z twierdza klanowa */
    int			room;         /* pomieszczenie klanowe */
    int			flags;        /* flagi klanu i pomieszczenia */
#endif
    OBJ_DATA	      * urna;         /* urna klanowa */
};

/*
 * Struktura polecenia klanowego w tablicy
 */
struct clan_cmd_type
{
    char * const	name;        /* nazwa polecenia */
    CLAN_FUN *		clan_fun;    /* funkcja realizujaca polecenie */
    int			clan_level;  /* min. stopien konieczny do wykonania */
    int			clan_stat;   /* min. status klanu konieczny do wyk. */
    int			flags;       /* flagi polecenia klanowego */
};

DECLARE_DO_FUN(	do_clan	); /* Lam */

bool		can_see_clan	args( ( CHAR_DATA *ch, CLAN_DATA *clan ) );
void		check_clan_rel	args( ( void ) );
void		clan_log	args( ( CLAN_DATA *clan, char *str ) );
CLAN_DATA	*clan_lookup	args( ( char *arg ) );
CLAN_DATA	*clan_lookup2	args( ( char *arg ) );
CLAN_MEMBER_DATA *clan_member_new args( ( void ) ) __attribute__( ( warn_unused_result ) );
CLAN_DATA	*clan_new	args( ( void ) ) __attribute__( ( warn_unused_result ) );
CLAN_REL_DATA	*clan_rel_lookup args( ( CLAN_DATA *clana, CLAN_DATA *clanb ) );
CLAN_REL_DATA	*clan_rel_new	args( ( void ) ) __attribute__( ( warn_unused_result ) );
void		clan_remove	args( ( CLAN_DATA *clan ) );
bool		is_any_clan_member args( ( CHAR_DATA *ch ) );
bool		is_clan_member	args( ( CHAR_DATA *ch, CLAN_DATA *clan ) );
bool		is_same_clan	args( ( CHAR_DATA *ch, CHAR_DATA *victim ) );
bool		load_clan_statut args( ( CLAN_DATA *clan ) );
void		real_clan_info	args( ( CHAR_DATA *ch, CLAN_DATA *cl, WHO_DESCRIPTOR_DATA *d ) );
void		real_clan_lista	args( ( CHAR_DATA *ch, char *argument, WHO_DESCRIPTOR_DATA *d ) );
void		write_clan	args( ( CLAN_DATA *clan, int flagi ) );
void		write_clans( void );
void		zapisz_urny( void );

extern CLAN_DATA		*clan_free;
extern CLAN_DATA		*clan_list;
extern CLAN_MEMBER_DATA		*clan_member_free;
extern CLAN_REL_DATA		*clan_rel_free;
