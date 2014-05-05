struct mob_trig_prog_data /* Lam */
{
    MTRIG_DATA	*next;
    CHAR_DATA	*ch;
    CHAR_DATA	*actor;
    CHAR_DATA	*vict;
    char	arg[ MIL ];
    int		time;
};

struct mob_prog_data
{
    MPROG_DATA *next;
    int		type;
    char *	arglist;
    char *	comlist;
    MPROG_DATA *parent; /* Lam 10.4.2002: do in_file_proga w kzapisz */
};

struct room_rand_prog_data /* Alandar 03.02.2004 */
{
    RRAND_DATA		*next;
    ROOM_INDEX_DATA	*room;
};


int interpretuj_zmysly		args( ( CHAR_DATA *ch, const char *argument ) );
void	mprog_process_cmnd	args( ( char* cmnd, CHAR_DATA* mob,
					CHAR_DATA* actor, OBJ_DATA* obj,
					CHAR_DATA* rndm, CHAR_DATA* vict,
					OBJ_DATA* v_obj ) );


extern MTRIG_DATA *mtrig_list;
extern RRAND_DATA *rrand_list;
