/*
** my.h for tekpaint in /home/mancie_m/rendu/rendu_J09/Piscine_C_J09/include
**
** Made by michel mancier
** Login   <mancie_m@epitech.net>
**
** Started on  Thu Oct  8 11:32:48 2015 michel mancier
** Last update Tue Jan 26 15:27:33 2016 Nicolas Zimmermann
*/

#ifndef MY_H_
# define MY_H_

int	my_char_isalphanum(char c);
int	my_char_isdigit(char c);
int	my_is_prime_finder(int nb);
int	my_getnbr(char *str);
int	my_isneg(int nb);
int	my_is_prime(int nombre);
int	my_power_rec(int nb, int power);
void	my_putchar(char c);
int	my_put_nbr(int nb);
int	my_putstr(char *str);
char	*my_revstr(char *str);
int	my_showmem(char *str, int size);
int	my_showstr(char *str);
void	my_sort_int_tab(int *tab, int size);
int	my_square_root(int nb);
char	*my_strcapitalize(char *str);
char	*my_strcat(char *dest, char *src);
int	my_strcmp(char *s1, char *s2);
char	*my_strcpy(char *dest, char *src);
int	my_str_isalpha(char *str);
int	my_str_islower(char *str);
int	my_str_isnum(char *str);
int	my_str_isprintable(char *str);
int	my_str_isupper(char *str);
int	my_strlen(char *str);
char	*my_strlowcase(char *str);
char	*my_strncat(char *dest, char *src, int nb);
int	my_strncmp(char *s1, char *s2, int n);
char	*my_strncpy(char *dest, char *src, int nb);
char	*my_strstr(char *str, char *to_find);
char	*my_strupcase(char *str);
int	my_swap(int *a, int *b);
int	my_putnbr_base(int nbr, char *base);
int	my_getnbr_base(char *str, char *base);
char	*my_strdup(char *src);
char	*sum_params(int argc, char **argv);
int	my_show_wordtab(char **tab);
char	**my_str_to_wordtab(char *str);
char	*convert_base(char *nbr, char *base_from, char *base_to);
char	*my_int_to_str(int nb);
int	my_intlen(int nb);
void	my_show_int_array(int *array, int len);

/*
** -------------------------------------------------
** Partie my_printf --------------------------------
** -------------------------------------------------
*/

# include <stdarg.h>
# include <errno.h>

# define FOREDARK "\033[30m"
# define FORERED "\033[31m"
# define FOREGREEN "\033[32m"
# define FOREYELLOW "\033[33m"
# define FOREBLUE "\033[34m"
# define FOREMAGENTA "\033[35m"
# define FORECYAN "\033[36m"
# define FOREWHITE "\033[37m"
# define FORERESET "\033[39m"
# define BACKDARK "\033[40m"
# define BACKRED "\033[41m"
# define BACKGREEN "\033[42m"
# define BACKYELLOW "\033[43m"
# define BACKBLUE "\033[44m"
# define BACKMAGENTA "\033[45m"
# define BACKCYAN "\033[46m"
# define BACKWHITE "\033[47m"
# define BACKRESET "\033[49m"
# define STYLEBOLD "\033[1m"
# define STYLEUNDERLINED "\033[4m"
# define STYLERESET "\033[0m"

int	my_printf(int mode, const char *format, ...);
int	printf_stdout(const char *format, int n, va_list *ap);
int	printf_stderr(const char *format, int n, va_list *ap);

void	errcreate(int (*fct[128])(va_list *, int));
void	create(int (*fct[128])(va_list *, int));

int	my_printchar(char c, int n);
int	my_printstr(char *str, int n);
int	my_printnbr(int nb, int mode, int n);
int	my_printnbr_base(long long nb, char *base, int n);
int	my_printstroct(char *str, int n);

int	print_percent(va_list *ap, int n);
int	error_noflag(va_list *ap, int n);
int	print_char(va_list *ap, int n);
int	print_str(va_list *ap, int n);
int	print_nbr(va_list *ap, int n);
int	print_bin(va_list *ap, int n);
int	print_oct(va_list *ap, int n);
int	print_hex_min(va_list *ap, int n);
int	print_hex_maj(va_list *ap, int n);
int	print_nbr_uns(va_list *ap, int n);
int	print_ptr(va_list *ap, int n);
int	print_stroct(va_list *ap, int n);
int	stock_n(va_list *ap, int n);
int	print_errno(va_list *ap, int n);

int	my_errchar(char c, int n);
int	my_errstr(char *str, int n);
int	my_errnbr(int nb, int mode, int n);
int	my_errnbr_base(long long nb, char *base, int n);
int	my_errstroct(char *str, int n);

int	err_percent(va_list *ap, int n);
int	eerror_noflag(va_list *ap, int n);
int	err_char(va_list *ap, int n);
int	err_str(va_list *ap, int n);
int	err_nbr(va_list *ap, int n);
int	err_bin(va_list *ap, int n);
int	err_oct(va_list *ap, int n);
int	err_hex_min(va_list *ap, int n);
int	err_hex_maj(va_list *ap, int n);
int	err_nbr_uns(va_list *ap, int n);
int	err_ptr(va_list *ap, int n);
int	err_stroct(va_list *ap, int n);
int	estock_n(va_list *ap, int n);
int	err_errno(va_list *ap, int n);

#endif /* !MY_H_ */
