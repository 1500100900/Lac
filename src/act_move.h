DECLARE_DO_FUN(	do_bash		);
DECLARE_DO_FUN(	do_chameleon	); /* by Thelonius */
DECLARE_DO_FUN(	do_close	);
DECLARE_DO_FUN(	do_dig		); /* Lam */
DECLARE_DO_FUN(	do_down		);
DECLARE_DO_FUN(	do_east		);
DECLARE_DO_FUN(	do_enter	); /* Lam */
DECLARE_DO_FUN(	do_heighten	); /* Thelonius */
DECLARE_DO_FUN(	do_hide		);
DECLARE_DO_FUN(	do_lock		);
DECLARE_DO_FUN(	do_north	);
DECLARE_DO_FUN(	do_northeast	); /* Lam */
DECLARE_DO_FUN(	do_northwest	); /* Lam */
DECLARE_DO_FUN(	do_open		);
DECLARE_DO_FUN(	do_pick		);
DECLARE_DO_FUN(	do_push		); /* Lam */
DECLARE_DO_FUN(	do_recall	); DECLARE_DO_FUN(	real_recall	);
DECLARE_DO_FUN(	do_rest		);
DECLARE_DO_FUN(	do_shadow	); /* by Thelonius */
DECLARE_DO_FUN(	do_sleep	);
DECLARE_DO_FUN(	do_snare	); /* by Binky / Thelonius */
DECLARE_DO_FUN(	do_sneak	);
DECLARE_DO_FUN(	do_south	);
DECLARE_DO_FUN(	do_southeast	); /* Lam */
DECLARE_DO_FUN(	do_southwest	); /* Lam */
DECLARE_DO_FUN(	do_stand	);
DECLARE_DO_FUN(	do_train	);
DECLARE_DO_FUN(	do_unlock	);
DECLARE_DO_FUN(	do_untangle	); /* by Thelonius */
DECLARE_DO_FUN(	do_up		);
DECLARE_DO_FUN(	do_visible	);
DECLARE_DO_FUN(	do_vomit	); /* Lam */
DECLARE_DO_FUN(	do_wake		);
DECLARE_DO_FUN(	do_west		);
DECLARE_DO_FUN(	do_wsiadz	); /* Lam */
DECLARE_DO_FUN(	do_wysiadz	); /* Lam */

extern const	int	movement_loss[ SECT_MAX ];
extern const	int	obr_z_upadku[ ];

bool	can_push_pull	args( ( CHAR_DATA *ch, CHAR_DATA *victim,
				ROOM_INDEX_DATA *from, ROOM_INDEX_DATA *to,
				int door ) );
int	find_door	args( ( CHAR_DATA *ch, char *arg, bool drzwi ) );
void	move_char	args( ( CHAR_DATA *ch, int door, bool wyciaganie ) );
void	po_wejsciu	args( ( CHAR_DATA *ch, bool ostroznosc ) );
void	wchodzenie_do_pomieszczenia args( ( CHAR_DATA *ch,
		ROOM_INDEX_DATA *in_room, ROOM_INDEX_DATA *to_room, int door,
		bool pokaz_kierunek ) );

FUNKCJA_CZASOWA( finish_digging );
