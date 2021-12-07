#ifndef MONITOR_H
# define MONITOR_H
# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include <windows.h>
# include <stdio.h>
# include <unistd.h>
//# include <conio.h>
#define	BUFFERLENGTH 400

typedef struct	s_data {
	int			i;
	char		*str;
	int			data_1;
	int			port_1;
	int			data_2;
	int			port_2;
	int			data_3;
	int			port_3;
	int			data_4;
	int			port_4;
	int			*x;
	int			*y;
	int			*z;
	int			*k;
}	t_data;

int		get_new_line_of_data(t_data *data);
void	ft_putstr(char *s);
void	ft_data_analise_sensor1(t_data *data);

#endif
