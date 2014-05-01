DECLARE_DO_FUN(	do_imctl	); /* Lam */

bool	check_ban		args( ( char *host, char *ip, char *user, int type ) );
bool	check_playing		args( ( DESCRIPTOR_DATA *d, char *name,
					bool nowa ) );
bool	check_reconnect		args( ( DESCRIPTOR_DATA *d, bool fConn ) );
void	ch_printf		args( ( CHAR_DATA *ch, const char *fmt,
					... ) ) __attribute__( ( format( printf, 2, 3 ) ) );
void	close_socket		args( ( DESCRIPTOR_DATA *dclose, bool lost ) );
void	colourconv		args( ( char *buffer, const char *txt,
					CHAR_DATA *ch, unsigned int size ) );
int	comm_main		args( ( bool edytor, int argc, char **argv ) );
void	read_from_buffer	args( ( DESCRIPTOR_DATA *d, bool msg ) );
void	send_to_all_char	args( ( const char *text ) );
void	send_to_char		args( ( const char *txt, CHAR_DATA *ch ) );
void	send_to_char_bw		args( ( const char *txt, CHAR_DATA *ch ) );
void	super_act		args( ( unsigned int opcja, int zmysly,
					const char *format, CHAR_DATA *ch,
					const void *arg1, const void *arg2, int type,
					bool ooc ) );
void	write_to_buffer		args( ( DESCRIPTOR_DATA *d, const char *txt,
					int length ) );
int write_to_descriptor		args( ( int desc, const void *txt, int length ) );
#if defined( IMUD )
void	write_to_imud_buffer	args( ( const char *txt ) );
#endif
void	write_to_who_buffer	args( ( WHO_DESCRIPTOR_DATA *d, const char *txt,
					int length ) );

#if defined ( MSDOS ) && !defined( NO_SOUND )
void	damage_sound	args( ( void ) );
void	death_sound	args( ( void ) );
#endif

extern unsigned const char	echo_off_str[ ];
extern unsigned const char	echo_on_str[ ];
extern unsigned const char	keepalive_str[ ];
extern int			numlock;
extern time_t			current_time;
extern DESCRIPTOR_DATA		*descriptor_list;
extern FILE			*fpBugReserve;
extern FILE			*fpReserve;
extern struct stats_type	max_desc;
extern int			max_desc_all_time;
extern char			max_desc_all_time_time[ 200 ];
extern struct stats_type	max_play;
extern int			max_play_all_time;
extern char			max_play_all_time_time[ 200 ];
extern bool			merc_down;
extern char			str_boot_time[ ];
extern bool			TylkoKonwersja;
extern bool			wizlock;
