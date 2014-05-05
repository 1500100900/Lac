/*
 * Structure for a command in the command lookup table.
 */
struct cmd_type
{
    char * const	name;
    char * const	old_name; /* Lam: Lac 1.4.-9 */
    DO_FUN *		do_fun;
    int			position;
    int			level;
    int			log;
    int			restr; /* Lam */
};


DECLARE_DO_FUN(	do_alias	); /* Lam */
DECLARE_DO_FUN(	do_answer	);
DECLARE_DO_FUN(	do_love		); /* Qwert */
DECLARE_DO_FUN(	do_realias	); /* Lam */
DECLARE_DO_FUN(	do_unalias	); /* Lam */


bool		interpret	args( ( CHAR_DATA *ch, char *argument, int zastos ) );
const CMD_TYPE	*znajdz_polecenie args( ( char *argument, int poziom ) );

extern	const	struct cmd_type		cmd_table[ ];
extern		bool			fLogAll;
