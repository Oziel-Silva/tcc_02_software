float cov_class_one [6][6];
int cov_class_two [6][6];

int z,w,n;
float cov;
float sum_cov[4];
float *map_f;


 map_f = mmap(0, MAP_RANGE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, MAP_BASE);
    if (map == MAP_FAILED)
    {
        close(fd);
        perror("Error mmapping the file");
        exit(EXIT_FAILURE);
    }




for( z = 0; z < 6 ; z++)
{
	for(w = 0; w < 6; w++)
	{	cov = 0;
		for(n = 0; n < 80; n++)
		{
			map_f[27] = class_one_data[n][z];
			map_f[28] = f_media[z];
			map_f[29] = class_one_data[n][w];
			map_f[30] = f_media[w];
			
			map_f[31] = class_one_data[n + 1][z];
			map_f[32] = f_media[z];
			map_f[33] = class_one_data[n + 1][w];
			map_f[34] = f_media[w];
		
			map_f[35] = class_one_data[n + 2][z];
			map_f[36] = f_media[z];
			map_f[37] = class_one_data[n + 2][w];
			map_f[38] = f_media[w];
			
			map_f[39] = class_one_data[n + 3][z];
			map_f[40] = f_media[z];
			map_f[41] = class_one_data[n + 3][w];
			map_f[42] = f_media[w];
			
			map[0] = 0x4;
			map[0] = 0x0;
			
			sum_cov[0] = map_f[59];
			sum_cov[1] = map_f[60];
			sum_cov[2] = map_f[61];
			sum_cov[3] = map_f[62];

		cov = cov + sum_cov[0] + sum_cov[1] + sum_cov[2] + sum_cov[3];
		n = n + 3;
		}
		
			
		cov_class_one[w][z] = cov;
		printf("a(%d,%d) = %f\n",w+1,z+1, cov_class_one[w][z]);

	}
}






}