DECLARE_DO_FUN(	do_graj		); /* Lam */
DECLARE_DO_FUN(	do_postaw	); /* Thelonius, nowa: Lam */

GAME_FUN	*game_lookup	args( ( const char *name ) );
char		*game_name	args( ( GAME_FUN *fun ) );
