//Jackson Chandler
//jccyb4
//Homework 1
//Due: 9/26/2014

#include<string.h>
#include<stdio.h>

#define STRING_LEN 20
#define PLAYLIST_LEN 20

typedef struct{
	char artist[STRING_LEN];
	char title[STRING_LEN];
	char album[STRING_LEN];
	int rating;
}Song;

int build_playlist(Song playlist[], char* inputFiles[], int numInputFiles);
int is_member(Song playlist[], int len, char* title);
void sort(Song playlist[], int len);
int do_swap(Song first, Song second);
void print(Song playlist[], int len);

//***************************
int main(int argc, char* argv[])
{
	if(argc<2){
	printf("Incorrect number of command line arguments\n");
	return -1;
	}

	Song playlist[PLAYLIST_LEN];
	
	int len = build_playlist(playlist, argv + 1, argc -1);
	//sort(playlist, len);
	print(playlist, len);
	if(len==-1){
	printf("Invalid input: multiple songs with the same title");
	return 0;
	}
}

//*****************************
int build_playlist(Song playlist[], char* inputFiles[], int numInputFiles)
{
	int i=0, len=0;
	for(i=0;i<numInputFiles;i++)
	{
		FILE*file=fopen(inputFiles[i],"r");

		if(file==NULL)
			return -1;
		
		while(len< PLAYLIST_LEN && fscanf(file, "%s %s %s %d", playlist[i].artist, playlist[i].title, playlist[i].album, &playlist[i].rating) != EOF)
		{
			//printf("%s %s %s %d\n", playlist[i].artist, playlist[i].title, playlist[i].album, playlist[i].rating);	
			len++;
			//int confirm = is_member(playlist,i,playlist[i].title);
			//printf("%s %s %s %d\n", playlist[i].artist, playlist[i].title, playlist[i].album, playlist[i].rating);
			//if(confirm==1)
			//return-1;
		}
	}
	return i;
}

//********************************
int is_member(Song playlist[], int len, char* title)
{
	int i;
	for(i=0;i<len;i++)
	{
		if(playlist[i].title ==  title) 
			return 1;
		else
		return 0;
	}
}

//**********************************
void sort(Song playlist[], int len)
{
	int i, check;
	Song hold;
	for(i=0;i++;i<len)
	{
		check = do_swap(playlist[i], playlist[i+1]);
		if(check==1)
		{
			hold=playlist[i+1];
			playlist[i+1] = playlist[i];
			playlist[i]=hold;
		}
	}
}

//**********************************
int do_swap(Song first, Song second)
{
	if(strcmp(first.artist,second.artist)>0)
		return 1;
 	else if(strcmp(first.artist,second.artist)==0&&strcmp(first.album,second.album)>0)
		return 1;
	else if(strcmp(first.artist,second.artist)==0&&strcmp(first.album,second.album)==0 && strcmp(first.title,second.title)>0)
		return 1;
	else if(strcmp(first.artist,second.artist)==0&&strcmp(first.album,second.album)==0 && strcmp(first.title,second.title)==0)
                return 0;
}

//**************************************
void print(Song playlist[], int len)
{
	int i;
	
	printf("%-10s %-12s %-10s %-4s\n", "Artist", "Album", "Title", "Rating");
	for(i=0;i<len;i++)
	{
		printf("%-10s %-12s %-10s %-4d\n", playlist[i].artist, playlist[i].album, playlist[i].title, playlist[i].rating);
	}
}
