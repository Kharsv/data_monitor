# include "monitor.h"

int	*memory_allocete(int n)
{
	int	*new;

	new = (int *)malloc(sizeof(int *) * (n + 1));
	if (!new)
		return (NULL);
	return (new);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (NULL != s)
	{
		while (s[i] != '\0')
		{
			write(1, &s[i], 1);
			++i;
		}
		write(1, "\n", 1);
	}
}

void	ft_get_data_to_stract(t_data *data)
{
	char	**data8;
	
	data8 = ft_split(data->str, 's');
	data->data_1 = ft_atoi(data8[0]);
	data->port_1 = ft_atoi(data8[1]);
	data->data_2 = ft_atoi(data8[2]);
	data->port_2 = ft_atoi(data8[3]);
	data->data_3 = ft_atoi(data8[4]);
	data->port_3 = ft_atoi(data8[5]);
	data->data_4 = ft_atoi(data8[6]);
	data->port_4 = ft_atoi(data8[7]);
	free(data8);
}

int main()
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	int i = 0;
	while(1)
	{
		get_new_line_of_data(data);
		ft_putstr(data->str);
		ft_get_data_to_stract(data);
		ft_data_analise_sensor1(data);
		printf("%d\n", data->data_1);
		printf("%d\n", data->data_2);
		printf("%d\n", data->data_3);
		printf("%d\n", data->data_4);

		printf("%d\n", data->port_1);
		printf("%d\n", data->port_2);
		printf("%d\n", data->port_3);
		printf("%d\n", data->port_4);
		i++;
	}
	//ft_set_data(shell);
	
	//ft_check_file(argc, argv, shell);
	//show_menu();

	free(data);
	return (0);
}