DECLARE_DO_FUN(	do_auction	);
DECLARE_DO_FUN(	do_brandish	);
DECLARE_DO_FUN(	do_buy		);
DECLARE_DO_FUN(	do_chrust	); /* Ulryk */
DECLARE_DO_FUN(	do_czytaj	); /* Lam */
DECLARE_DO_FUN(	do_donate	);
DECLARE_DO_FUN(	do_dostosuj	);
DECLARE_DO_FUN(	do_drink	);
DECLARE_DO_FUN(	do_drop		);
DECLARE_DO_FUN(	do_eat		);
DECLARE_DO_FUN(	do_fill		);
DECLARE_DO_FUN(	do_get		);
DECLARE_DO_FUN(	do_give		);
DECLARE_DO_FUN(	do_hold		); /* Lam */
DECLARE_DO_FUN(	do_list		);
DECLARE_DO_FUN(	do_nakarm	); /* Alandar */
DECLARE_DO_FUN(	do_napoj	); /* Alandar */
DECLARE_DO_FUN(	do_odbierz	); /* Lam */
DECLARE_DO_FUN(	do_ognisko	);
DECLARE_DO_FUN(	do_outfit	); /* Lam */
DECLARE_DO_FUN(	do_poison_weapon); /* by Thelonius */
DECLARE_DO_FUN(	do_przechowaj	); /* Lam */
DECLARE_DO_FUN(	do_put		);
DECLARE_DO_FUN(	do_recite	);
DECLARE_DO_FUN(	do_register	);
DECLARE_DO_FUN(	do_remove	);
DECLARE_DO_FUN(	do_sacrifice	);
DECLARE_DO_FUN(	do_sell		);
DECLARE_DO_FUN(	do_sklep	); /* Lam */
DECLARE_DO_FUN(	do_steal	);
DECLARE_DO_FUN(	do_uzyj		); /* Lam */
DECLARE_DO_FUN(	do_value	);
DECLARE_DO_FUN(	do_wear		);
DECLARE_DO_FUN(	do_wylej	); /* Lam */
DECLARE_DO_FUN(	do_zap		);

void	check_wield		args( ( CHAR_DATA *ch ) );
bool	remove_obj		args( ( CHAR_DATA *ch, int iWear, bool fReplace ) );
void	zmien_brzeczenie	args( ( CHAR_DATA *ch, bool fOn, bool fCiche ) );
void	zmien_poziom		args( ( OBJ_DATA *obj, CHAR_DATA *ch ) );
bool	pijane_przedmioty	args( ( CHAR_DATA *ch ) );

FUNKCJA_CZASOWA( przestan_karmic );
FUNKCJA_CZASOWA( przestan_poic );
