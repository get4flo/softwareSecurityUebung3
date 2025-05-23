void 01_main(void)

{
  int iVar1;
  long in_FS_OFFSET;
  char local_12 [2];
  undefined8 local_10;
  
  local_10 = *(undefined8 *)(in_FS_OFFSET + 0x28);
  02_setBuffers();
  local_12[0] = '\0';
  local_12[1] = '\0';
  DAT_00105130 = &DAT_00105140;
  puts("Hello and welcome to my new experimental Fotispy app !");
  puts("====================================== ===============");
  while( true ) {
    while( true ) {
      03_printOptions();
      04_readInput(local_12,2);
      iVar1 = atoi(local_12);
      if (((DAT_001050a0 != -1) || (iVar1 == 0)) || (iVar1 == 1)) break;
      puts("[-] No user has logged in yet.");
    }
    if (iVar1 == 8) break;
    if (iVar1 < 9) {
      if (iVar1 == 7) {
        14_writeFile();
      }
      else if (iVar1 < 8) {
        if (iVar1 == 6) {
          13_readFile();
        }
        else if (iVar1 < 7) {
          if (iVar1 == 5) {
            12_openSongFile();
          }
          else if (iVar1 < 6) {
            if (iVar1 == 4) {
              11_editFavSong();
            }
            else if (iVar1 < 5) {
              if (iVar1 == 3) {
                10_printFavSongs();
              }
              else if (iVar1 < 4) {
                if (iVar1 == 2) {
                  09_addFavSong();
                }
                else if (iVar1 < 3) {
                  if (iVar1 == 0) {
                    05_registerUser();
                  }
                  else if (iVar1 == 1) {
                    08_loginUser();
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  puts("Bye bye");
                    /* WARNING: Subroutine does not return */
  exit(0);
}


void 02_setBuffers(void)

{
  setvbuf(stdin,(char *)0x0,2,0);
  setvbuf(stdout,(char *)0x0,2,0);
  setvbuf(stderr,(char *)0x0,2,0);
  return;
}


void 03_printOptions(void)

{
  puts("");
  puts("[0] Register");
  puts("[1] Log in");
  puts("[2] Add a song to your favorites");
  puts("[3] Display info of a song");
  puts("[4] Edit favorite song");
  puts("[5] Open local song file");
  puts("[6] Read from file");
  puts("[6] Write to file");
  puts("[7] Exit");
  printf("Please enter your choice [7]: ");
  return;
}


int 04_readInput(long param_1,long param_2)

{
  int iVar1;
  undefined1 local_d;
  undefined4 local_c;
  
  local_c = 0;
  do {
    if (param_2 <= local_c) break;
    iVar1 = getc(stdin);
    local_d = (char)iVar1;
    iVar1 = local_c + 1;
    *(char *)(local_c + param_1) = local_d;
    local_c = iVar1;
  } while (local_d != '\n');
  while (local_d != '\n') {
    iVar1 = getc(stdin);
    local_d = (char)iVar1;
  }
  if (param_2 != local_c) {
    local_c = local_c + -1;
    *(undefined1 *)(param_1 + local_c) = 0;
  }
  return local_c;
}


void 05_registerUser(void)

{
  undefined8 *puVar1;
  char cVar2;
  void *pvVar3;
  void *pvVar4;
  undefined8 uVar5;
  
  cVar2 = 06_getUserBuffer();
  if (cVar2 != -1) {
    pvVar3 = calloc(1,0x20);
    pvVar4 = calloc(1,0x20);
    printf("[~] Please enter a username: ");
    04_readInput(pvVar3,0x20);
    printf("[~] Please enter a password: ");
    04_readInput(pvVar4,0x20);
    puVar1 = (undefined8 *)(DAT_00105130 + (long)cVar2 * 8);
    uVar5 = 07_printUserName(pvVar3,pvVar4);
    *puVar1 = uVar5;
    **(undefined8 **)(DAT_00105130 + (long)cVar2 * 8) = pv Var3;
    *(void **)(*(long *)(DAT_00105130 + (long)cVar2 * 8) + 8) = pvVar4;
  }
  return;
}


int 06_getUserBuffer(void)

{
  int local_c;
  
  local_c = 0;
  while( true ) {
    if (9 < local_c) {
      return -1;
    }
    if (*(long *)(DAT_00105130 + (long)local_c * 8) == 0) bre ak;
    local_c = local_c + 1;
  }
  return local_c;
}


void 07_printUserName(undefined8 param_1)

{
  printf("[+] Created user %s\n",param_1);
  calloc(1,0x3e0);
  return;
}


void 08_loginUser(void)

{
  int iVar1;
  char *__s1;
  char *__s1_00;
  int local_1c;
  
  __s1 = (char *)calloc(1,0x20);
  __s1_00 = (char *)calloc(1,0x20);
  printf("[~] Please enter a username: ");
  04_readInput(__s1,0x20);
  printf("[~] Please enter a password: ");
  04_readInput(__s1_00,0x20);
  local_1c = 0;
  while( true ) {
    if (9 < local_1c) {
      printf("[-] %s could not be logged in\n",__s1);
      return;
    }
    if (((*(long *)(DAT_00105130 + (long)local_1c * 8) != 0) &&
        (iVar1 = strncmp(__s1,(char *)**(undefined8 **)(DAT_0 0105130 + (long)local_1c * 8),0x20),
        iVar1 == 0)) &&
       (iVar1 = strncmp(__s1_00,*(char **)(*(long *)(DAT_001 05130 + (long)local_1c * 8) + 8),0x20),
       iVar1 == 0)) break;
    local_1c = local_1c + 1;
  }
  DAT_001050a0 = (undefined1)local_1c;
  printf("[+] %s has been logged in\n",__s1);
  return;
}


void 09_addFavSong(void)

{
  undefined8 *puVar1;
  char cVar2;
  undefined8 uVar3;
  long lVar4;
  long lVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined8 *puVar9;
  undefined8 *puVar10;
  undefined8 *puVar11;
  
  if (*(char *)(*(long *)(DAT_00105130 + (ulong)DAT_0010 50a0 * 8) + 0x10) == '\x10') {
    puts("[-] Favorites is full :(");
  }
  else {
    puVar9 = (undefined8 *)calloc(1,0x10);
    puVar10 = (undefined8 *)calloc(1,0x10);
    puVar11 = (undefined8 *)calloc(1,0x10);
    printf("[~] Please enter a song title: ");
    uVar6 = 04_readInput(puVar9,0x10);
    printf("[~] Please enter a who %s is from: ",puVar9);
    uVar7 = 04_readInput(puVar11,0x10);
    printf("[~] Please enter which album %s is on: ",puVar9);
    uVar8 = 04_readInput(puVar10,0x10);
    printf("[+] Song has been added in slot %d\n",
           (ulong)(uint)(int)*(char *)(*(long *)(DAT_00105130 +  (ulong)DAT_001050a0 * 8) + 0x10));
    puVar1 = (undefined8 *)
             (*(long *)(DAT_00105130 + (ulong)DAT_001050a0 * 8) +
             (long)(int)*(char *)(*(long *)(DAT_00105130 + (ulon g)DAT_001050a0 * 8) + 0x10) * 0x3c +
             0x40);
    uVar3 = puVar10[1];
    *puVar1 = *puVar10;
    puVar1[1] = uVar3;
    *(undefined4 *)
     ((long)(int)*(char *)(*(long *)(DAT_00105130 + (ulong)D AT_001050a0 * 8) + 0x10) * 0x3c +
      *(long *)(DAT_00105130 + (ulong)DAT_001050a0 * 8) + 0x58) = uVar8;
    puVar1 = (undefined8 *)
             (*(long *)(DAT_00105130 + (ulong)DAT_001050a0 * 8) +
             (long)(int)*(char *)(*(long *)(DAT_00105130 + (ulon g)DAT_001050a0 * 8) + 0x10) * 0x3c +
             0x20);
    uVar3 = puVar9[1];
    *puVar1 = *puVar9;
    puVar1[1] = uVar3;
    *(undefined4 *)
     ((long)(int)*(char *)(*(long *)(DAT_00105130 + (ulong)D AT_001050a0 * 8) + 0x10) * 0x3c +
      *(long *)(DAT_00105130 + (ulong)DAT_001050a0 * 8) + 0x54) = uVar6;
    puVar1 = (undefined8 *)
             (*(long *)(DAT_00105130 + (ulong)DAT_001050a0 * 8) +
             (long)(int)*(char *)(*(long *)(DAT_00105130 + (ulon g)DAT_001050a0 * 8) + 0x10) * 0x3c +
             0x30);
    uVar3 = puVar11[1];
    *puVar1 = *puVar11;
    puVar1[1] = uVar3;
    lVar4 = *(long *)(DAT_00105130 + (ulong)DAT_001050a 0 * 8);
    lVar5 = *(long *)(DAT_00105130 + (ulong)DAT_001050a 0 * 8);
    cVar2 = *(char *)(lVar5 + 0x10);
    *(char *)(lVar5 + 0x10) = cVar2 + '\x01';
    *(undefined4 *)((long)(int)cVar2 * 0x3c + lVar4 + 0x50) = uVar7;
  }
  return;
}


void 10_printFavSongs(void)

{
  int iVar1;
  char *__nptr;
  int local_20;
  int local_1c;
  int local_18;
  
  __nptr = (char *)calloc(1,10);
  printf("[~] Enter the slot of the song to edit: ");
  04_readInput(__nptr,10);
  iVar1 = atoi(__nptr);
  if (iVar1 < 0) {
    puts("[-] The slot has to be positive");
  }
  else {
    puts("[~] Song info:");
    printf("    - Song: ");
    for (local_20 = 0; local_20 < 0x10; local_20 = local_20 + 1) {
      putchar((int)*(char *)((long)local_20 +
                             (long)iVar1 * 0x3c + *(long *)(DAT_00105 130 + (ulong)DAT_001050a0 * 8)
                            + 0x20));
    }
    printf(" - ");
    for (local_1c = 0; local_1c < 0x10; local_1c = local_1c + 1) {
      putchar((int)*(char *)((long)local_1c +
                             (long)iVar1 * 0x3c + *(long *)(DAT_00105 130 + (ulong)DAT_001050a0 * 8)
                            + 0x40));
    }
    printf(" - ");
    for (local_18 = 0; local_18 < 0x10; local_18 = local_18 + 1) {
      putchar((int)*(char *)((long)local_18 +
                             (long)iVar1 * 0x3c + *(long *)(DAT_00105 130 + (ulong)DAT_001050a0 * 8)
                            + 0x30));
    }
    putchar(10);
  }
  free(__nptr);
  return;
}


void 11_editFavSong(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  char *__nptr;
  long lVar4;
  
  __nptr = (char *)calloc(1,10);
  printf("[~] Enter the slot of the song to edit: ");
  04_readInput(__nptr,10);
  iVar1 = atoi(__nptr);
  if (iVar1 < 0) {
    puts("[-] The slot has to be positive");
  }
  else {
    __nptr[0] = '\0';
    __nptr[1] = '\0';
    __nptr[2] = '\0';
    __nptr[3] = '\0';
    __nptr[4] = '\0';
    __nptr[5] = '\0';
    __nptr[6] = '\0';
    __nptr[7] = '\0';
    __nptr[8] = '\0';
    __nptr[9] = '\0';
    puts("[0] Title");
    puts("[1] Artist");
    puts("[2] Album");
    puts("[~] What do you want to change: ");
    04_readInput(__nptr,10);
    iVar2 = atoi(__nptr);
    if ((iVar2 < 0) || (2 < iVar2)) {
      puts("[-] Please enter a valid number");
    }
    else {
      lVar4 = *(long *)(DAT_00105130 + (ulong)DAT_001050 a0 * 8) + (long)iVar1 * 0x3c + 0x20;
      printf("[~] Please enter the new info: ");
      if (iVar2 == 2) {
        uVar3 = 04_readInput(lVar4 + 0x20,0x10);
        *(undefined4 *)(lVar4 + 0x38) = uVar3;
      }
      else if (iVar2 < 3) {
        if (iVar2 == 0) {
          uVar3 = 04_readInput(lVar4,0x10);
          *(undefined4 *)(lVar4 + 0x34) = uVar3;
        }
        else if (iVar2 == 1) {
          uVar3 = 04_readInput(lVar4 + 0x10,0x10);
          *(undefined4 *)(lVar4 + 0x30) = uVar3;
        }
      }
    }
  }
  free(__nptr);
  return;
}


void 12_openSongFile(void)

{
  long lVar1;
  int iVar2;
  char *pcVar3;
  char *__resolved;
  FILE *pFVar4;
  
  pcVar3 = (char *)calloc(1,0x1000);
  __resolved = (char *)calloc(1,0x1000);
  printf("[~] Please enter the file path: ");
  04_readInput(pcVar3,0x1000);
  realpath(pcVar3,__resolved);
  free(pcVar3);
  pcVar3 = strstr(__resolved,"homework");
  if (pcVar3 == (char *)0x0) {
    pcVar3 = strstr(__resolved,"flag");
    if (pcVar3 == (char *)0x0) {
      iVar2 = strncmp(__resolved,"/code",5);
      if (iVar2 == 0) {
        if (*(long *)(*(long *)(DAT_00105130 + (ulong)DAT_0 01050a0 * 8) + 0x18) != 0) {
          fclose(*(FILE **)(*(long *)(DAT_00105130 + (ulong) DAT_001050a0 * 8) + 0x18));
        }
        lVar1 = *(long *)(DAT_00105130 + (ulong)DAT_00105 0a0 * 8);
        pFVar4 = fopen(__resolved,"w+");
        *(FILE **)(lVar1 + 0x18) = pFVar4;
      }
      else {
        puts("[-] The file has to be in /code");
      }
    }
    else {
      puts("[-] It\'s not that easy");
    }
  }
  else {
    puts("[-] Please don\'t edit the homework binary");
  }
  free(__resolved);
  return;
}


void 13_readFile(void)

{
  int iVar1;
  char *__nptr;
  
  if (*(long *)(*(long *)(DAT_00105130 + (ulong)DAT_0010 50a0 * 8) + 0x18) == 0) {
    puts("[-] Please open a file first");
  }
  else {
    fseek(*(FILE **)(*(long *)(DAT_00105130 + (ulong)DAT _001050a0 * 8) + 0x18),0,0);
    __nptr = (char *)calloc(1,10);
    printf("[~] How many bytes to read: ");
    04_readInput(__nptr,10);
    iVar1 = atoi(__nptr);
    if (iVar1 < 1) {
      printf("[-] I can\'t get %s bytes\n",__nptr);
    }
    else {
      fread(&DAT_00105100,1,(long)iVar1,
            *(FILE **)(*(long *)(DAT_00105130 + (ulong)DAT_ 001050a0 * 8) + 0x18));
      printf("[+] Read %s\n",&DAT_00105100);
    }
    free(__nptr);
  }
  return;
}


void 14_writeFile(void)

{
  int iVar1;
  char *__nptr;
  void *__buf;
  
  if (*(long *)(*(long *)(DAT_00105130 + (ulong)DAT_0010 50a0 * 8) + 0x18) == 0) {
    puts("[-] Please open a file first");
  }
  else {
    __nptr = (char *)calloc(1,10);
    printf("[~] How many bytes to read: ");
    04_readInput(__nptr,10);
    iVar1 = atoi(__nptr);
    if (iVar1 < 1) {
      printf("[-] I can\'t get %s bytes\n",__nptr);
    }
    else {
      __buf = calloc(1,(long)iVar1);
      printf("[~] Enter the data: ");
      read(0,__buf,(long)iVar1);
      fwrite(__buf,1,(long)iVar1,
             *(FILE **)(*(long *)(DAT_00105130 + (ulong)DAT _001050a0 * 8) + 0x18));
      free(__buf);
    }
    free(__nptr);
  }
  return;
}