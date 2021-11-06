#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define START_FILE   "[File_start]"
#define END_FILE     "[File_end]"
#define START_FOLDER "[Folder_start]"
#define END_FOLDER   "[Folder_end]"
#define START_OPT    "[Operation_start]"
#define END_OPT      "[Operation_end]"

#define INI_FILE     'f'
#define INI_FOLDER   'd'
#define EXECUTE      'o'
#define EXIT         'e'

#define NAME_MAX     10

typedef struct subNode{
  char name[NAME_MAX];    // File/Folder name
  char type;              // Folder is "d", File is "f"
  char access[3];         // rx, r- -x
  char owner[NAME_MAX];   // Who is the owner
  int  isUsed;             // 0 means this file/folder is free, 1 means it's used
}FILE_NODE;

typedef struct node{
  char name[NAME_MAX];    // File/Folder name
  char type;              // Folder is "d", File is "f"
  char access[3];         // rx, r- -x
  char owner[NAME_MAX];   // Who is the owner
  int  isUsed;             // 0 means this file/folder is free, 1 means it's used  
  FILE_NODE files[10];  // subfiles. 
}FOLDER_NODE;

static FOLDER_NODE folders[10];


void InitialData()
{
  int idxFolder = 0;
  int idxFile = 0;
  for( idxFolder = 0; idxFolder < 10; idxFolder++ )
  {
    folders[idxFolder].isUsed = 0;
    FOLDER_NODE *ptr = &folders[idxFolder];

    for( idxFile = 0; idxFile < 10; idxFile++ )
    {
      ptr->files[idxFile].isUsed = 0;
    }
  }

}

FOLDER_NODE *FindFolder( const char *folderName )
{
  int idx = 0;
  for( idx = 0 ; idx < 10; idx++ )
  {
    FOLDER_NODE *ptr = &folders[idx];
    if( ptr->isUsed )
    {
      if( !strcmp(ptr->name, folderName ) )
      {
        return ptr;
      }
    }
  }
  return NULL;
}

FILE_NODE *FindFileInFolder( FOLDER_NODE *folder, const char *name )
{
  int idx = 0;
  for( idx = 0 ; idx < 10; idx++ )
  {
    FILE_NODE  *ptr = &folder->files[idx];
    if( ptr->isUsed )
    {
      if( !strcmp(ptr->name, name ) )
      {
        return ptr;
      }
    }
  }
  return NULL;

}

void InitialFiles( const char *inBuf )
{
  char name[NAME_MAX];
  char access[3];
  char type;
  char owner[NAME_MAX];
  char folder[NAME_MAX];
  if( -1 != sscanf(inBuf, "%[^,],%[^,],%[^,],%[^,],%[^,]", name, &type, access, owner,folder))
  {
    FOLDER_NODE *ptr = FindFolder( folder );
    if( ptr )
    {
      int idx = 0;
      for( idx = 0; idx < 10; idx++ )
      {
        if(!ptr->files[idx].isUsed)
        {
          ptr->files[idx].isUsed = 1;
          strcpy( ptr->files[idx].name, name );
          ptr->files[idx].type = type;
          strcpy( ptr->files[idx].access, access );
          strcpy( ptr->files[idx].owner, owner );
          return;
        }
      }
    }
    else
    {
      printf("Could not found %s\n", folder);
    }
  }
  else{
    printf("Error read in InitialFile : %s\n", inBuf);
    exit(0);
  }

}

void InitialFolders( char *inBuf )
{
  static int idx = 0;
  FOLDER_NODE *ptr = &folders[idx];
  
  if( -1 != sscanf(inBuf, "%[^,],%[^,],%[^,],%[^,]", ptr->name, &ptr->type, ptr->access, ptr->owner))
  {
    ptr->isUsed = 1;
    idx++;
  }
  else
  {
    printf("Error read in InitialFolder : %s\n", inBuf);
    exit(0);
  }
}

void AddFile( const char *usr, const char *name, FOLDER_NODE *folder )
{
  int idx = 0;
  for( idx = 0; idx < 10; idx++ )
  {
    if(!folder->files[idx].isUsed)
    {
        folder->files[idx].isUsed = 1;
        strcpy( folder->files[idx].name, name );
        folder->files[idx].type = 'f';
        strcpy( folder->files[idx].access, "rw" );
        strcpy( folder->files[idx].owner, usr );
        return;
    }
  }
}

int DoCmd( const char *usr, const char *opt, FILE_NODE *file, FOLDER_NODE *folder, const char *filename )
{
  int ismyfile = 0; 
  int ismyfolder = strcmp( usr, folder->owner ) ? 0 : 1;
  
  if(file)
  {
    ismyfile = strcmp(usr, file->owner) ? 0 : 1;
  }

  if( !strcmp("read", opt) )
  {
    return ismyfile ? 1 : file->access[1] == 'r';
  }
  else if( !strcmp("write", opt) )
  {
    return ismyfile ? 1 : file->access[1] == 'w';
  }
  else if( !strcmp("add", opt) )
  {
    AddFile(usr, filename, folder);
    return 1;
  }
  else if( !strcmp("del", opt) )
  {
    if( ismyfolder )
    {
      file->isUsed = 0;
      return 1;
    }
    else
    {
      if( 'w' == folder->access[1] )
      {
        file->isUsed = 0;
        return 1;
      }
      return 0;
    }
  }
  
  printf("%s cmd is not found\n", opt);
  return 0;

}


int ExecuteCmd( const char *inBuf )
{
  char user[NAME_MAX];
  char opt[10];
  char file[NAME_MAX];
  char folder[NAME_MAX];
  if( -1 != sscanf(inBuf, "%[^,],%[^,],%[^,],%[^,]", user, opt, file, folder))
  {
    FOLDER_NODE *ptr = FindFolder(folder);
    if( ptr )
    {
      if( !strcmp("add", opt))
      {
        return DoCmd( user, opt, NULL, ptr, file );
      }
      else
      {
        FILE_NODE *ptrFile = FindFileInFolder(ptr, file);
        if( ptrFile )
        {
          return DoCmd( user, opt, ptrFile, ptr, NULL);
        }
        else
        {
          //printf("File is not found %s in %s\n", file, folder);
          return 0;
        }
      }
    }
    else
    {
      //printf("FOLDER is not found %s\n", folder);
      return 0;
    }
  }
  else
  {
    //printf("Error read in ExecuteCmd : %s\n", inBuf);
    exit(0);
  }

}

char ConfirmStatus( const char *inBuf, const char status, int *isData )
{
  
  *isData =  '[' == *inBuf ? 0 : 1;

  if( !strcmp( START_FILE, inBuf) )
  {
    return INI_FILE;
  }
  else if( !strcmp( START_FOLDER, inBuf) )
  {
    return INI_FOLDER;
  }
  else if(!strcmp( START_OPT, inBuf))
  {
    return EXECUTE;
  }
  else if(!strcmp( END_OPT, inBuf))
  {
    return EXIT;
  }
  else
  {
    return status; //status has no any changes.
  }
}

void OutputStruct()
{
  int idx = 0;
  for( idx = 0 ; idx < 10; idx++ )
  {
    if( folders[idx].isUsed )
    {
      printf( "%s:%s:%s\n", folders[idx].name, folders[idx].access, folders[idx].owner );
      int idxF = 0;
      for( idxF = 0 ; idxF < 10; idxF++ )
      {
        if( folders[idx].files[idxF].isUsed )
        {
          printf( "   %s:%s:%s\n",
             folders[idx].files[idxF].name,
             folders[idx].files[idxF].access,
             folders[idx].files[idxF].owner );
        }
      }
    }
  }
}


int main()
{
  char inBuf[256];
  char status = INI_FOLDER;
  int isData = 0;

  InitialData();

  while( (EXIT != status) && scanf("%s",inBuf) )
  {
    isData = 0;
    status = ConfirmStatus(inBuf, status, &isData );

    if( isData ){
      if( INI_FOLDER == status )
      {
        InitialFolders(inBuf);
      }
      else if( INI_FILE == status )
      {
        InitialFiles(inBuf);
      }
      else if( EXECUTE == status )
      {
        1 == ExecuteCmd(inBuf) ? printf("Success\n"): printf("Fail\n");
      }
    } 
  }
  //printf("\nEnd----\n");
  //OutputStruct();
  return 0;
}
