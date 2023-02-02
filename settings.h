// Includes needed by the core program,
// you may add some for use in the functions below,
// but do not remove any.
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Uncomment if walliable should be integrated.
#define WALLIABLE

// If walliable is in use, change this to the ABSOULUTE path of walliable binary. 
// e.g. "/bin/walliable" or
char *pathToWalliable = "";

// How often will the wallpaper change (in minutes, and no decimals)
int wallpaperChangeRate = 5;

// Called when the wallpaper changes
// This is ideal if you're not using walliable
void onWallpaperChange()
{

}

// Called when anything changes, can be used to time anything
void somethingChanged(int second, int minute, int hour, int day, int month, int year)
{

}
