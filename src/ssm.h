void	boot_done		args( ( void ) );
char	*fread_string_eol	args( ( FILE *fp, int *status ) ) __attribute__( ( warn_unused_result ) );
void	init_string_space	args( ( void ) );
char	*real_fread_string	args( ( FILE *fp, int *status, const char *plik,
					int linia, const char *funkcja ) ) __attribute__( ( warn_unused_result ) );
void	real_free_string	args( ( char *pstr, const char *plik, int linia,
					const char *funkcja ) );
char	*real_str_dup		args( ( const char *str, const char *plik, int linia,
					const char *funkcja ) ) __attribute__( ( warn_unused_result ) );
int	ssm_max_free_entry	args( ( void ) );
int	ssm_num_free_entries	args( ( void ) );


/* dzieki temu widac, ktora funkcja wywoluje str_dup( )/free_string( ) */
#ifdef DOPALANY_BUG
# define str_dup( s ) real_str_dup( s, __FILE__, __LINE__, __FUNCTION__ )
# define fread_string( str, status ) real_fread_string( str, status, __FILE__, __LINE__, __FUNCTION__ )
# define free_string( s ) { real_free_string( s, __FILE__, __LINE__, __FUNCTION__ ); s = NULL; }
#else
# define str_dup( s ) real_str_dup( s, "?", 0, "?" )
# define fread_string( str, status ) real_fread_string( str, status, "?", 0, "?" )
# define free_string( s ) { real_free_string( s, "?", 0, "?" ); s = NULL; }
#endif
#if defined( DEBUG_SSM )
void	zrzut_kwasow_lancuchow	args( ( void ) );
void	oznacz_wszystko		args( ( void ) );
#endif


extern unsigned int	MAX_STRING;
extern bool		Full;
extern int		HEADER_SIZE;
extern long		nAllocString;
extern long		nOverFlowString;
extern long		sAllocString;
extern long		sOverFlowString;
extern char		str_empty[ 1 ];
