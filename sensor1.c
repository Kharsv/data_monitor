# include "monitor.h"

void ft_data_analise_sensor1(t_data *data)
{
	int	digitemp[43];
	int i;
	int *start;

	i = 1;
	digitemp[0] =4063;
	digitemp[1] =4063;     // -55
	digitemp[2] =4051;
	digitemp[3] =4035;
	digitemp[4] =4015;
	digitemp[5] =3988;
	digitemp[6] =3955;
	digitemp[7] =3913;
	digitemp[8] =3861;
	digitemp[9] =3798;
	digitemp[10] =3722;
	digitemp[11] =3633;
	digitemp[12] =3530;
	digitemp[13] =3411;
	digitemp[14] =3279;
	digitemp[15] =3132;
	digitemp[16] =2973;
	digitemp[17] =2805;
	digitemp[18] =2629;
	digitemp[19] =2448;
	digitemp[20] =2266;
	digitemp[21] =2086;
	digitemp[22] =1910;
	digitemp[23] =1742;
	digitemp[24] =1581;
	digitemp[25] =1430;
	digitemp[26] =1290;
	digitemp[27] =1161;
	digitemp[28] =1043;
	digitemp[29] =936;
	digitemp[30] =839;
	digitemp[31] =753;
	digitemp[32] =675;
	digitemp[33] =606;
	digitemp[34] =544;
	digitemp[35] =489;
	digitemp[36] =439;
	digitemp[37] = 395;
	digitemp[38] = 356;
	digitemp[39] = 322;
	digitemp[40] = 291;
	digitemp[41] = 263;
	digitemp[42] = 238;
	digitemp[43] = 216;
	start = &digitemp[0];
	if (data->port_1 < 4010 && data->port_1 > 3990)
	{
		write(1,"Temperture on sensor is ON\n", 27);
		write(1,"Temperture on sensor 1 is ", 26);
	}
	// printf("-%d-\n", data->data_1);
	// printf("-%d-\n", digitemp[1]);
	while ( start[i] > data->data_1)
	{
		//printf("-%d-\n", digitemp[i]);
		i++;
	}
	float delta = 5 / (start[i-1] - data->data_1);
	float ourtemp = -55+(i-2)*5 + delta*(start[i-1]-data->data_1);
	printf("%.2f\n", ourtemp);	
}
