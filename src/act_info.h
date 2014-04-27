DECLARE_DO_FUN(	do_affects	); /* Lam */
DECLARE_DO_FUN(	do_afk		);
DECLARE_DO_FUN(	do_channels	);
DECLARE_DO_FUN(	do_commands	);
DECLARE_DO_FUN(	do_compare	);
DECLARE_DO_FUN(	do_config	);
DECLARE_DO_FUN(	do_consider	);
DECLARE_DO_FUN(	do_credits	);
DECLARE_DO_FUN(	do_description	);
DECLARE_DO_FUN(	do_equipment	);
DECLARE_DO_FUN(	do_examine	);
DECLARE_DO_FUN(	do_exits	);
DECLARE_DO_FUN(	do_fprompt	); /* Lam */
DECLARE_DO_FUN(	do_frombank	); /* Lam */
DECLARE_DO_FUN(	do_hasl		); /* Lam */
DECLARE_DO_FUN(	do_haslo	); /* Lam */
DECLARE_DO_FUN(	do_help		);
DECLARE_DO_FUN(	do_inventory	);
DECLARE_DO_FUN(	do_kalendarz	); /* Lam */
DECLARE_DO_FUN(	do_look		);
DECLARE_DO_FUN(	do_nowosci	); /* Lam */
DECLARE_DO_FUN(	do_odmiana	);
DECLARE_DO_FUN(	do_ostatnie	); /* Tissarius */
DECLARE_DO_FUN(	do_pagelen	);
DECLARE_DO_FUN(	do_podgladaj	); /* Lam */
DECLARE_DO_FUN(	do_polskie	); /* Lam */
DECLARE_DO_FUN(	do_poziomy	); /* Lam */
DECLARE_DO_FUN(	do_practice	);
DECLARE_DO_FUN(	do_prompt	);
DECLARE_DO_FUN(	do_punktacja	); /* Lam */
DECLARE_DO_FUN(	do_report	);
DECLARE_DO_FUN(	do_scan		); /* Lam i Albi */
DECLARE_DO_FUN(	do_slist	);
DECLARE_DO_FUN(	do_spells	);
DECLARE_DO_FUN(	do_time		);
DECLARE_DO_FUN(	do_title	);
DECLARE_DO_FUN(	do_tobank	); /* Lam */
DECLARE_DO_FUN(	do_version	); /* Lam */
DECLARE_DO_FUN(	do_weather	);
DECLARE_DO_FUN(	do_where	);
DECLARE_DO_FUN(	do_who		);
DECLARE_DO_FUN(	do_whois	);
DECLARE_DO_FUN(	do_wimpy	);

DECLARE_DO_FUN(	odmiana_postaci	); /* Lam */


char	*asctime_pl		args( ( const struct tm *timeptr ) );
char	*asctime_pl_krotko_nonl	args( ( const struct tm *timeptr ) );
bool	check_blind		args( ( CHAR_DATA *ch ) );
void	odmiana_prompt		args( ( CHAR_DATA *ch ) );
void	pokaz_pomieszczenie	args( ( CHAR_DATA *ch, ROOM_INDEX_DATA *pom,
					bool skrot ) );
void	real_help		args( ( CHAR_DATA *ch, char *arg, char *skroty,
					WHO_DESCRIPTOR_DATA *d ) );
void	real_slist		args( ( CHAR_DATA *ch, char *arg,
					WHO_DESCRIPTOR_DATA *d ) );
void	real_who		args( ( CHAR_DATA *ch, char *argument,
					WHO_DESCRIPTOR_DATA *who_d ) );
void	set_title		args( ( CHAR_DATA *ch, char *title ) );
void	show_list_to_char	args( ( OBJ_DATA *list, CHAR_DATA *ch,
					bool fShort, bool fShowNothing,
					bool krocej, bool inwentarz,
					bool fDontCombine,
					int ilosc, char *argument ) );
void	sprawdz_hasla		args( ( char *arg, char *haslo,
					char *skroty, int poziom ) );

extern	const int		where_order[ ];
