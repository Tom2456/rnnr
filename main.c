#include "settings.h"
#include "UnixTimeToDate.h"

void update(time_t *t,int* year, int* month, int* day, int* hours, int* minutes, int* seconds)
{
	
	*t = time(NULL);
	/*
	*year = *t / 31556952 + 1970; 
	*month = (*t / 2629746 - (*year - 1970) * 12) + 1;
	*day = *t / 86400 - ((*year - 1970) * 12) +1) * 30;
	*hours = (*t / 3600 - (*t / 86400 + 1 / 24) * 24) + 1;
	*minutes = *t / 60 - (*t / 3600) * 60;
	*/
	convertUnixTimeToDate(*t, seconds, minutes, hours, day, month, year);	
	*hours = *hours + 1;
}

int main(int argc, char *argv[])
{
	int wallpaperCooldown = wallpaperChangeRate; // (in minutes hopefully)

	// bool
	int run = 1;

	time_t t;
	t = time(NULL); // (UTC)

	int y; 
	int M; 
	int d; 
	int h; 
	int m; 
	int s;

	update(&t, &y, &M, &d, &h, &m, &s);

	int lastHour = h;
	int lastMinute = m;
	int lastMonth = M;
	int lastDay = d;
	int lastYear = y;
	int lastSecond = s;

	while(run)
	{
		update(&t, &y, &M, &d, &h, &m, &s);

		if(lastMinute != m)
		{
			somethingChanged(s, m, h, d, M, y);

			wallpaperCooldown--;
			if(wallpaperCooldown == 0)
			{
				printf("%s", "WALLPAPER\n");
				#ifdef WALLIABLE
				system(pathToWalliable);
				#endif
				wallpaperCooldown = 5;
				onWallpaperChange();
			}

			lastMinute = m;
		}
		
		if(lastHour != h || lastDay != d || lastMinute != m || lastMonth != M || lastYear != y || lastSecond != s)
		{
			somethingChanged(s, m, h, d, M, y);

			printf("%d:%d, %d:%d, wpcooldown: %d\n", h, m, lastHour, lastMinute, wallpaperCooldown);

			lastHour = h;
			lastMonth = M;
			lastDay = d;
			lastYear = y;
			lastSecond = s;

			continue;
		}
		printf("y:%d, M:%d, d:%d, h:%d, m:%d, s:%d\n", y, M, d, h, m, s);
		system("clear");
	}
	return 0;
}
