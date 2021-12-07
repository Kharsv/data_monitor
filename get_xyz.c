#include "fdf.h"

void	ft_save_xyz(t_data *img, int n, int m)
{
	int	i;

	i = 0;
	while (i < m)
	{
		img->bufx[n][i] = (double)img->x[i];
		img->bufy[n][i] = (double)img->y[i];
		img->bufz[n][i] = (double)img->z[i];
		i++;
	}
	free(img->x);
	free(img->y);
	free(img->z);
}

void	get_color(t_data *img, int	i, int n)
{
	if (img->z[i] > -10 && img->z[i] < 10)
		img->colors[n][i] = img->color_zero;
	if (img->z[i] <= -10 || img->z[i] >= 10)
		img->colors[n][i] = img->color_up;
}

void	get_xyz(char *s, int n, t_data *img)
{
	char	**dot;
	int		i;

	i = 0;
	dot = ft_split(s, ' ');
	while (dot[i])
		i++;
	img->max_x = i;
	img->x = memory_allocete(i, 0);
	img->y = memory_allocete(i, 0);
	img->z = memory_allocete(i, 0);
	i = 0;
	while (dot[i])
	{
		img->x[i] = i;
		img->y[i] = n;
		img->z[i] = ft_atoi(dot[i]);
		get_color(img, i, n);
		free(dot[i]);
		i++;
	}
	ft_save_xyz(img, n, img->max_x);
	free(dot);
}
