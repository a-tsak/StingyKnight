/* Ylopoihsame to bonus twn akrianwn epithesewn */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int Spawn(int M, int N, int **table, int diff, int ple, int plempo);
void play(int M, int N, int **table, int ple, int plempo, int lmoney, int *gmoney, char *dir);

int main(void)
{
  int i, j, a=0, M, N, d_true, diff, enemies, **table, pl, ple=0, plempo, M2, N2, face, lmoney=0, *gmoney;
  char b, d1, d2, *dir;
  gmoney=&a;
  dir=&b;   // Kateuthunsi pou koitaei o ippoths stin arxh kathe paixnidiou kai gurou
  srand(time(NULL));
  printf("\nEnter the number of dimensions. \n\nNote that: \nMinimum dimensions: 5x5\nMaximum dimensions: 15x15\n\n");
  do{
    scanf(" %d %d", &M, &N);
    d_true=0;
    if (M<5 && N<5){
      d_true=1;
      printf("\nBoth numbers are too small. Please try again! \n\n");
    }
    else if (M>15 && N>15){
      d_true=1;
      printf("\nBoth numbers are too large. Please try again! \n\n");
    }
    if (M<5 && d_true==0){
      printf("\nThe first number is too small. Please try again! \n\n");
    }
    else if (M>15 && d_true==0){
      printf("\nThe first number is too large. Please try again! \n\n");
    }
    if (N<5 && d_true==0){
      printf("\nThe second number is too small. Please try again! \n'n");
    }
    else if (N>15 && d_true==0){
      printf("\nThe second number is too large. Please try again! \n\n");
    }
  }while( M<5 || N<5 || M>15 || N>15 );
  M2=15;      // O megistos arithmos gia tis diastaseis einai 15
  N2=15;
  printf("\nSelect difficulty: Easy (1) | Medium (2) | Hard (3)\n\n");
  do{
    scanf("%d", &diff);
    if (diff!=1 && diff!=2 && diff!=2){
      printf("\nWrong number. Please try again!\n\n");
    }
  }while(diff!=1 && diff!=2 && diff!=3);
  if(diff == 1){
    ple=( (5*(M*N))/100);       // Pososto twn exthrwn ana diastaseis tou pinaka
    plempo=( (5*(M*N))/100);
  }
  if(diff == 2){
    ple=( (10*(M*N))/100);
    plempo=( (5*(M*N))/100);    // Pososto twn empodiwn ana diastaseis tou pinaka
  }
  if(diff == 3){
    ple=( (10*(M*N))/100);
    plempo=( (10*(M*N))/100);
  }
  // Ksekinaei to paixnidi
  while( (M<M2 || N<N2) || d_true==1 ){  // An mia diastasi ftasei to 15, tote sunexizetai to paixnidi me tin aukshsh tis allis diastasis, kai gia auto ||
    d_true=0;
    table = (int **) malloc(M*sizeof(int *));
    for (i=0; i<M; i++){
      table[i]=(int *) malloc(N*sizeof(int));
    }
    if (table==NULL){     // Stin periptwsi pou den uparxei xwros mnhmhs
      printf("There is no memory available.");
      exit(1);
    }
    for (i=0; i<M; i++){
      for (j=0; j<N; j++){
        table[i][j]=0;
      }
    }   // Arxikopoihsh tou pinaka se times 0
    do{
      pl=Spawn(M, N, table, diff, ple, plempo);   // Kalei tin sunartisi wspou kanenas exthros den vrisketai stin idia thesi me kapoion allon
    }while(pl != ple);
    face= 1 + rand () % 4;
    if (face==1){     // Kateuthunsi pou koitaei o ippoths
      *dir='U';
    }
    else if (face==2){
      *dir='R';
    }
    else if (face==3){
      *dir='D';
    }
    else if (face==4){
      *dir='L';
    }
    // Ektupwsi tou tamplo gia tin arxi tou paixnidiou kai kathe gurou
    printf("\n\n\n");
    for(i=0;i<M;i++){
      if (i==0){
        printf("    ");
        for (j=0; j<N; j++){
          if (j<9){
            printf("%d ", j+1);
          }
          else{
            printf("%d", j+1);   // Emfanize tous 10+ arithmous kollita metaksu tous
          }
        }
        printf("\n----");
        for (j=0; j<N; j++){
      	  printf("--");
        }
        printf("\n");
      }
      if (i<9){
        printf("%d | ", i+1);
      }
      else{
        printf("%d| ", i+1);    // Emfanize tous 10+ arithmous kollita me to |
      }
      for(j=0;j<N;j++){
        if (table[i][j]==1 || table[i][j]==2 || table[i][j]==3){
          printf("%d ", table[i][j]);
        }
        else if (table[i][j]==222){
          printf("# ");
        }
        else if (table[i][j]==333){
          printf("$ ");
        }
        else{
          printf(". ");
        }
      }
      printf("\n");
    }
    printf("\nThe knight is looking ");
    if (face==1){
      printf("up.");
    }
    if (face==2){
      printf("right.");
    }
    if (face==3){
      printf("down.");
    }
    if (face==4){
      printf("left.");
    }
    printf("\nLevel money spent: %d \nGame money spent: %d \nMake your move(s): ", lmoney, *gmoney);
    play(M,N,table,ple,plempo,lmoney,gmoney,dir);
    // free
    for (i=0; i<M; i++){
      free(table[i]);
    }
    free(table);
    if (M<M2){     // An mia diastasi ftasei sto megisto ths, stamata na auksanetai
      M=M+1;
      if (M==M2){
        d_true=1;
      }
    }
    if (N<N2){     // Ananewsi twn diastasewn tou pinaka
      N=N+1;
      if (N==N2){
        d_true=1;
      }
    }
    if(diff == 1){    // Ananewsi tou plithous exthrwn kai empodiwn
    ple=( (5*(M*N))/100);
    plempo=( (5*(M*N))/100);
    }
    if(diff == 2){
      ple=( (10*(M*N))/100);
      plempo=( (5*(M*N))/100);
    }
    if(diff == 3){
      ple=( (10*(M*N))/100);
      plempo=( (10*(M*N))/100);
    }  
  }     // Telos tou paixnidiou
  return 0;   // Telos tou programmatos
}

int Spawn(int M, int N, int **table, int diff, int ple, int plempo)  // Epistrefei plithos twn exthrwn
{
    int x[ple], obstacles, x2, x2_row, x2_col, move, i, j, pl=0, x_row[ple], x_col[ple], knight, knight_row, knight_col;
    x[0] = rand() % (M*N);  // Tuxaia topothetisi 1ou exthrou
    for (i=0; i<M; i++){
      for (j=0; j<N; j++){
        table[i][j]=0;
      }
    }
    for (i=1; i<ple; i++){    // Epilegetai tuxaia mia kateuthunsi (panw, deksia, katw, aristera) antistoixws me tous arithmous 1-4, kai me basi ton arithmo tha kataliksei o kathe epomenos exthros dipla apo ton proigoumeno stin kateuthunsi pou apofasistike
      if(x[i-1] == 0){    //1h epilogh (panw aristera)
        do{
            move = rand() % (4 + 1 - 1) + 1;
        }while((move == 1) || (move == 4));
      }
      else if(x[i-1] == (N-1)){     //2h epilogh (panw deksia)
        do{
            move = rand() % (4 + 1 - 1) + 1;
        }while((move == 1) || (move == 2));
      }
      else if ((x[i-1] % N == 0) && (x[i-1] != (M-1)*N)){   //3h epilogh (aristera)
        do{
            move = rand() % (4 + 1 - 1) + 1;
        }while(move == 4);
      }
      else if (x[i-1] == ((M-1)*N)){    // 4h epilogh (katw aristera)
        do{
            move = rand() % (4 + 1 - 1) + 1;
        }while(move == 3 || move == 4);
      }
      else if( (x[i-1] >= (((M-1)*N)+1)) && (x[i-1] <= (((M*N)-1)-1)) ){ // 5h epilogh (katw)
        do{
            move = rand() % (4 + 1 - 1) + 1;
        }while(move == 3);
      }
      else if(x[i-1] == ((M*N)-1)){   //6h epilogh (katw deksia)
        do{
            move = rand() % (4 + 1 - 1) + 1;
        }while((move == 3) || (move == 2));
      }
      else if(x[i-1] % N == (N-1)){    //7h epilogh (deksia)
      do{
            move = rand() % (4 + 1 - 1) + 1;
        }while(move ==2); 
      }
      else if((x[i-1] >= 1) && (x[i-1] < (N-1))){ // 8h epilogh (panw)
        do{
            move = rand() % (4 + 1 - 1) + 1;
        }while(move ==1);
      }
      else{                               //oxi se akriana simeia
        move = rand() % (4 + 1 - 1) + 1;
      }
      if(move == 1){
          x[i] = x[i-1] - N;
      }
      if(move == 2){
          x[i] = x[i-1] + 1;
      }
      if(move == 3){
        x[i] = x[i-1] + N;
      }
      if(move == 4){
        x[i] = x[i-1] - 1;
      } 
    }
    for (i=0; i<ple; i++){
      x_row[i]=x[i] / N;
      x_col[i]=x[i] % N;
      table[x_row[i]][x_col[i]]=rand() % (3 + 1 - 1) + 1;
    }
    for(i=0;i<M;i++){
      for(j=0;j<N;j++){
        if (table[i][j] !=0)
          pl++;                       // Metrisi tou plithous twn exthrwn pou vriskontai ston pinaka
      }
    }
    obstacles=0;
    while(obstacles<plempo){
      x2=rand() % (M*N);              // Tuxaia topothetisi empodiwn
      x2_row=x2/N;
      x2_col=x2%N;
      if (table[x2_row][x2_col]==0){
        table[x2_row][x2_col]=222;
        obstacles=obstacles+1;
      }
    }
    do{
      knight = rand() % (M*N);        // Tuxaia topothetisi ippoth
      knight_row = knight/N;
      knight_col = knight%N;
    }while (table[knight_row][knight_col]!=0);
    table[knight_row][knight_col]=333;
    return pl;
}

void play(int M,int N, int **table, int ple, int plempo, int lmoney, int *gmoney, char *dir)
{
    int i, j, k=0, l, l2, pl, knight, att_abc, att_true, att_true2, face, exit_abc;
    int knight_row, knight_col, steps, money, move_true, move_true2, move_abc;
    char move, att, c1, c2;

    for (i=0; i<M; i++){
      for (j=0; j<N; j++){
        if (table[i][j]==333){
          knight=k;
        }
        k=k+1;
      }
    }
    knight_row=knight/N;
    knight_col=knight%N;
    lmoney=0;
    l=0;      // Plithos entolwn kinisewn pou exei dwsei o xrhsths (xreiazetai gia to check twn kateuthunsewn (dir) stis epitheseis)
    l2=0;     // Plithos entolwn pou exei dwsei o xrhsths (xreiazetai gia to minima knight looks __ se kathe arxi tou girou)
    while (ple>0){    // Oso uparxoun exthroi, sunexizei o guros
      do{
        move_abc=0;
        att_abc=0;
        exit_abc=0;
        scanf(" %c%c", &c1, &c2);     // to c2 xreiazetai mono gia to move
        if (c1=='F' || c1=='f' || c1=='A' || c1=='a' || c1=='S' || c1=='s' || c1=='B' || c1=='b'){
          att_abc=1;
          if (c2==' ' || c2=='\n' || c2=='\t'){
            att_abc=2;
            l2=l2+1;
          }
          else{
            printf("You cannot enter multiple characters for an attack. Please try again! ");
          }
        }
        else if (c1=='U' || c1=='u' || c1=='D' || c1=='d' || c1=='R' || c1=='r' || c1=='L' || c1=='l'){
          move_abc=1;
          if (c2>='0' && c2<='9'){
            move_abc=2;
            l=l+1;  // metritis twn entolwn kinisewn, me ton 2o elegxo pio meta tha einai o metritis twn epituximenwn entolwn kinisewn
            l2=l2+1;
          }
          else if (c2==' ' || c2=='\n' || c2=='\t'){
            printf("You should specify how many steps you wish to make. Please try again! "); 
          }
        }
        else if (c1=='X' || c1=='x'){
          exit_abc=1;
          if (c2==' ' || c2=='\n' || c2=='\t'){
            exit_abc=2;
          }
          else{
            printf("You cannot enter multiple characters to exit. Please try again! ");
          }
        }
        else{
          printf("Wrong character. Please try again. ");
        }
      } while(move_abc!=2 && att_abc!=2 && exit_abc!=2);
      if (move_abc==2){
        move=c1;
        steps=c2-48;    // To steps pairnei tin akeraia timi tou xaraktira c2 stin ASCII kai me to -48 ginetai o idios arithmos pou eprepe na einai
      }
      else if (att_abc==2){
        att=c1;
      }
      // An entoli = kinisi
      if (move_abc==2){
        do{
          move_true=0;     // move_true=0 => H kinisi einai ektos oriwn, move_true=1 => H kinisi einai entos oriwn tou pinaka 
          move_true2=0;    // H kinisi egine epituxws, den uparxoun exthroi h empodia prin h kata tin thesi pou thelei na metakinisei o xrhsths ton ippoth
          move_abc=0;
          if (move=='D' || move=='d'){
            if ( (knight_row+steps)< M){    // An o ippoths den vgainei ektos oriwn apo tin thesi pou idi vrisketai
              move_true=1;
              pl=0;
              for (i=knight_row+1; i<=knight_row+steps; i++){
                if (table[i][knight_col]==0)    // An einai keni thesi, den uparxoun empodia h exthroi
                  pl=pl+1;
              }
              if (pl==steps){
                move_true2=1;
                table[knight_row+steps][knight_col]=333;
                knight=(knight_row*N)+(steps*N)+knight_col;
              }
            }
            else{
              pl=0;
              for (i=knight_row+1; i<M; i++){
                if (table[i][knight_col]==0){
                  pl=pl+1;
                }
              }
              for (i=0; i<=(steps-(M-1-knight_row)-1); i++){
                if (table[i][knight_col]==0){
                  pl=pl+1;
                }
              }
              if (pl==steps){
                move_true2=1;
                table[steps-(M-1-knight_row)-1][knight_col]=333;
                knight=(steps-(M-1-knight_row)-1)*N+knight_col;
                // Pio meta mhdenizetai h proigoumeni thesi tou ippoth kai to knight_row, knight_col ananewnontai me div kai mod.
              }
            }
          }
          else if(move=='U' || move=='u'){
            if ((knight_row-steps)>=0){
              move_true=1;
              pl=0;
              for (i=knight_row-steps; i<=knight_row-1; i++){
                if (table[i][knight_col]==0){
                  pl=pl+1;
                }
              }
              if (pl==steps){
                move_true2=1;
                table[knight_row-steps][knight_col]=333;
                knight=(knight_row*N)-(steps*N)+knight_col;
              }
            }
            else{
              // To move_true den allazei, paramenei 0
              pl=0;
              for (i=0; i<=knight_row-1; i++){
                if (table[i][knight_col]==0){
                  pl=pl+1;
                }
              }
              for (i=(M-(steps-knight_row)); i<M; i++){
                if (table[i][knight_col]==0){
                  pl=pl+1;
                }
              }
              if (pl==steps){
                move_true2=1;
                table[M-(steps-(knight_row))][knight_col]=333;
                knight=(M-(steps-(knight_row)))*N+knight_col;
              }
            }
          }
          else if(move=='R' || move=='r'){
            if ( (knight_col+steps) < N ){  //An o ippoths den vgainei ektos oriwn (<= (N-1)) apo tin thesi pou hdh vrisketai
              move_true=1;
              pl=0;
              for (i=knight_col+1; i<=knight_col+steps; i++){
                if (table[knight_row][i]==0){
                  pl=pl+1;
                }
              }
              if (pl==steps){
                move_true2=1;
                table[knight_row][knight_col+steps]=333;
                knight=(knight_row*N)+(knight_col)+(steps);
              }
            }
            else{ // An o ippoths vgainei ektos oriwn, kanei kinhsh apo thn mia akri stin allh
              pl=0;
              for (i=knight_col+1; i<N; i++){
                if (table[knight_row][i]==0){
                  pl=pl+1;
                }
              }
              for (i=0; i<=(steps-(N-1-knight_col)-1); i++){
                if (table[knight_row][i]==0){
                  pl=pl+1;
                }
              }
              if (pl==steps){
                move_true2=1;
                table[knight_row][steps-(N - 1 - knight_col)-1]=333;
                knight=knight_row*N+steps-(N - 1 - knight_col)-1;
                }
              }
            }
            else if(move=='L' || move=='l'){
              if ( (knight_col-steps)>=0){
                move_true=1;
                pl=0;
                for (i=knight_col-steps; i<=knight_col-1; i++){
                  if (table[knight_row][i]==0){
                    pl=pl+1;
                  }
                }
                if (pl==steps){
                  move_true2=1;
                  table[knight_row][knight_col-steps]=333;
                  knight=(knight_row*N)+(knight_col)-(steps);
                }
              }
              else{
                pl=0;
                for (i=0; i<=knight_col-1; i++){
                  if (table[knight_row][i]==0){
                    pl=pl+1;
                  }
                }
                for(i=(N-(steps-(knight_col))); i<N; i++){
                  if(table[knight_row][i]==0){
                    pl=pl+1;
                  }
                }
                if (pl==steps){
                  move_true2=1;
                  table[knight_row][N-(steps-(knight_col))]=333;
                  knight=(knight_row*N)+N-steps+knight_col;
                }
              }
            }
            if (steps!=0 && move_true2==1)
              table[knight_row][knight_col]=0;    // H proigoumeni thesi tou ippoti svinetai apo ton pinaka
            knight_row=knight/N;
            knight_col=knight%N;
            if (move_true2==0){ // An h kinisi den petuxe
              printf("\nYou cannot step over an enemy or an obstacle. Please try again!\n\n");
              l=l-1;    // o metritis twn entolwn kinisewn pou exei eisagei o xrhsths meiwnetai kata 1 giati den htan epituximeni auth h entolh logw exthrou h empodiou (epeidi prin ton auksisame ston allo elegxo)
              break;
            }
        }while(move_true2!=1);       // otan to move_true=1 stamataei
        if (move_true2!=0){ // An h kinisi petuxe (den patise panw se exthro h empodio)
          lmoney=lmoney+(5*steps);
          *gmoney=*gmoney+(5*steps);
        }
        // Ektupwsh pinaka meta tin epituximeni metakinisi tou ippoth
        if (move_true2!=0){ // An h kinisi petuxe (den patise panw se exthro h empodio)
        printf("\n\n");
        for (i=0; i<M; i++){
          if (i==0){
            printf("    ");
            for (j=0; j<N; j++){
              if (j<9){
                printf("%d ", j+1);
              }
              else{
                printf("%d", j+1);      // Emfanize kollita ta 10+
              }
            }
            printf("\n----");
            for (j=0; j<N; j++){
              printf("--");
            }
            printf("\n");
          }
          if (i<9){
            printf("%d | ", i+1);
          }
          else{
            printf("%d| ", i+1);      // Emfanize kollita ta 10+ me |
          }
          for(j=0;j<N;j++){
            if (table[i][j]==1 || table[i][j]==2 || table[i][j]==3){
              printf("%d ", table[i][j]);
            }
            else if (table[i][j]==222){
              printf("# ");
            }
            else if (table[i][j]==333){
              printf("$ ");
            }
            else{
              printf(". ");
            }
          }
          printf("\n");
        }
        printf("\nLevel money spent: %d \nGame money spent: %d \nMake your move(s): ", lmoney, *gmoney);
      }
  }
  // An entoli=epithesi
  else if (att_abc==2)
  {
    j=0;
    do
    {
      att_abc=0;
      att_true=0;
      if (att=='F' || att=='f'){
        att_abc=1;
        if (move=='D' || move=='d' || (l==0 && *dir=='D')){
          if ( (knight_row+1) < (M-1) ){    // An o ippoths kanei attack stin proteleutaia thesi tou pinaka (vrisketai stin paraproteleutaia grammi tou pinaka)
            att_true=1;
            if ( (table[knight_row+1][knight_col]==1 || table[knight_row+1][knight_col]==2 || table[knight_row+1][knight_col]==3)){
              att_true=2;
              table[knight_row+1][knight_col]= table[knight_row+1][knight_col]-1;
              if (table[knight_row+1+1][knight_col]==0){
                table[knight_row+1+1][knight_col]=table[knight_row+1][knight_col];
                table[knight_row+1][knight_col]=0;
              }
            }
          }
          else if ( (knight_row+1)==(M-1) ){   // An o ippoths kanei attack stin teleutaia thesi tou pinaka, diladi vrisketai stin proteleutaia thesi tou pinaka
            att_true=1;       
            if ( (table[knight_row+1][knight_col]==1 || table[knight_row+1][knight_col]==2 || table[knight_row+1][knight_col]==3) ){
              att_true=2;
              if (table[knight_row+1][knight_col]>0){
                table[knight_row+1][knight_col]= table[knight_row+1][knight_col]-1;
              }   // Mono meiwsi -1, oxi opisthoxorisi
            }
          }
          if ( (knight_row) == (M-1)){ // An o ippoths vrisketai stin teleutaia thesi tou pinaka, diladi kanei attack apo tin alli meria tou pinaka
            att_true=1;
            if ( table[0][knight_col]==1 || table[0][knight_col]==2 || table[0][knight_col]==3 ){
              att_true=2;
              table[0][knight_col]=table[0][knight_col]-1;
              if (table[1][knight_col]==0){   // Opisthoxorisi
                table[1][knight_col]=table[0][knight_col];
                table[0][knight_col]=0;
              }
            }
          }
        }
        else if (move=='U' || move=='u' || (l==0 && *dir=='U') ){
          if ( (knight_row-1)>0){     // An o ippoths einai apo tin teleutaia mexri tin 3h grammi tou pinaka
            att_true=1;
            if (table[knight_row-1][knight_col]==1 || table[knight_row-1][knight_col]==2 || table[knight_row-1][knight_col]==3){
              att_true=2;
                table[knight_row-1][knight_col]= table[knight_row-1][knight_col]-1;
                if (table[knight_row-2][knight_col]==0){
                  table[knight_row-2][knight_col]=table[knight_row-1][knight_col];
                  table[knight_row-1][knight_col]= 0;    // Opisthoxorisi
                }
            }
          }
          else if ( (knight_row-1) == 0 )   // An o ippoths einai stin 2h grammi tou pinaka
          {
            att_true=1;
            if ( (table[knight_row-1][knight_col]==1 || table[knight_row-1][knight_col]==2 || table[knight_row-1][knight_col]==3) ){
              att_true=2;
                table[knight_row-1][knight_col]= table[knight_row-1][knight_col]-1;
                // Mono meiwsi -1, oxi opisthoxorisi
            }
          }
          if (knight_row==0){
            att_true=1;
            if (table[M-1][knight_col]==1 || table[M-1][knight_col]==2 || table[M-1][knight_col]==3){
              att_true=2;
              table[M-1][knight_col]=table[M-1][knight_col]-1;
              if (table[M-2][knight_col]==0){     // Opisthoxorisi
                table[M-2][knight_col]=table[M-1][knight_col];
                table[M-1][knight_col]=0;
              }
            }
          }
        }
        else if (move=='L' || move=='l' || (l==0 && *dir=='L') ){
          if ((knight_col-1)>0){      // An o ippoths einai apo tin teleutaia mexri tin 3h sthlh tou pinaka
            att_true=1;
            if (table[knight_row][knight_col-1]==1 || table[knight_row][knight_col-1]==2 || table[knight_row][knight_col-1]==3){
              att_true=2;
                table[knight_row][knight_col-1]= table[knight_row][knight_col-1]-1;
                if (table[knight_row][knight_col-2]==0){
                  table[knight_row][knight_col-2]=table[knight_row][knight_col-1];
                  table[knight_row][knight_col-1]= 0;    // Opisthoxorisi
                }
            }
          }
          else if ((knight_col-1)==0){    // An o ippoths einai stin 2h sthlh tou pinaka
            att_true=1;
            if ( (table[knight_row][knight_col-1]==1 || table[knight_row][knight_col-1]==2 || table[knight_row][knight_col-1]==3) ){
              att_true=2;
                table[knight_row][knight_col-1]= table[knight_row][knight_col-1]-1;
                // Mono meiwsi -1, oxi opisthoxorisi
            }
          }
          if (knight_col==0){       // An o ippoths einai stin 1h sthlh tou pinaka
            att_true=1;
            if (table[knight_row][N-1]==1 || table[knight_row][N-1]==2 || table[knight_row][N-1]==3){
              att_true=2;
              table[knight_row][N-1]=table[knight_row][N-1]-1;
              if (table[knight_row][N-2]==0){
                table[knight_row][N-2]=table[knight_row][N-1];
                table[knight_row][N-1]=0;
              }
            }
          }
        }
        else if (move=='R' || move=='r' || (l==0 && *dir=='R') ){
          if ( (knight_col+1) < (N-1) ){    // An o ippoths kanei attack ws tin proteleutaia thesi tou pinaka (<=(N-2))
            att_true=1;
            if (table[knight_row][knight_col+1]==1 || table[knight_row][knight_col+1]==2 || table[knight_row][knight_col+1]==3){
              att_true=2;
                table[knight_row][knight_col+1]= table[knight_row][knight_col+1]-1;
                if (table[knight_row][knight_col+2]==0){
                  table[knight_row][knight_col+2]=table[knight_row][knight_col+1];
                  table[knight_row][knight_col+1]= 0;
                }
            }
          }
          else if ( (knight_col+1) == (N-1) ){
            att_true=1;
            if ( (table[knight_row][knight_col+1]==1 || table[knight_row][knight_col+1]==2 || table[knight_row][knight_col+1]==3) ){
              att_true=2;
              if (table[knight_row][knight_col+1]>0){
                table[knight_row][knight_col+1]= table[knight_row][knight_col+1]-1;
              }   // Mono meiwsi -1, oxi opisthoxorisi
            }
          }
          if (knight_col==(N-1)){
            att_true=1;
            if (table[knight_row][0]==1 || table[knight_row][0]==2 || table[knight_row][0]==3){
              att_true=2;
              table[knight_row][0]=table[knight_row][0]-1;
              if (table[knight_row][1]==0){
                table[knight_row][1]=table[knight_row][0];
                table[knight_row][0]=0;
              }
            }
          }
        }
      }
      else if(att=='A' || att=='a'){
        att_abc=1;
        if (move=='D' || move=='d' || (l==0 && *dir=='D') ){
          if (knight_row<=(M-3)){     // An o ippoths einai ews tin paraproteleutaia thesi tou pinaka
            att_true=1;
            if ( (table[knight_row+1][knight_col]==1 || table[knight_row+1][knight_col]==2 || table[knight_row+1][knight_col]==3) && (table[knight_row+2][knight_col]==1 || table[knight_row+2][knight_col]==2 || table[knight_row+2][knight_col]==3) ){
              // An uparxei 1os kai 2os exthros
              att_true=2;
              table[knight_row+1][knight_col]=table[knight_row+1][knight_col]-1;
              table[knight_row+2][knight_col]=table[knight_row+2][knight_col]-1;
              if ( (knight_row+3) <= (M-1) ){   // An h pisw thesi apo tous exthrous einai entos oriwn
                if ( table[knight_row+3][knight_col]==0 ){
                  table[knight_row+3][knight_col]=table[knight_row+2][knight_col];
                  table[knight_row+2][knight_col]=table[knight_row+1][knight_col];
                  table[knight_row+1][knight_col]=0;
                }
                else {      // An h pisw thesi apo tous exthrous exei empodio h exthro, tote mono an o 2os den uparxei pia o 1os opisthoxwrei
                  if (table[knight_row+2][knight_col]==0){
                    table[knight_row+2][knight_col]=table[knight_row+1][knight_col];
                    table[knight_row+1][knight_col]=0;
                  }
                }
              }
              else{   // An h pisw thesi apo tous exthrous einai ektos oriwn
                if ( table[knight_row+2][knight_col]==0){ // An o 2os exthros molis stamatise na uparxei
                  table[knight_row+2][knight_col]=table[knight_row+1][knight_col];  // Tote opisthoxwrisi tou 1ou exthrou
                  table[knight_row+1][knight_col]=0;
                }
              }
            }
            if ( (table[knight_row+1][knight_col]==1 || table[knight_row+1][knight_col]==2 || table[knight_row+1][knight_col]==3) && (att_true!=2)){       // An uparxei 1os exthros
              att_true=2;
              table[knight_row+1][knight_col]=table[knight_row+1][knight_col]-1;
              if ( (knight_row+2) <= (M-1) ){
                if ( table[knight_row+2][knight_col]==0 ){
                  table[knight_row+2][knight_col]=table[knight_row+1][knight_col];
                  table[knight_row+1][knight_col]=0;
                }
              }
            }
            if ( (table[knight_row+2][knight_col]==1 || table[knight_row+2][knight_col]==2 || table[knight_row+2][knight_col]==3) && (att_true!=2) ){    // An uparxei 2os exthros
              att_true=2;
              table[knight_row+2][knight_col]=table[knight_row+2][knight_col]-1;
              if ( (knight_row+3) <= (M-1) ){
                if ( table[knight_row+3][knight_col]==0 ){
                  table[knight_row+3][knight_col]=table[knight_row+2][knight_col];
                  table[knight_row+2][knight_col]=0;
                }
              }
            }
          }
          else if (knight_row==(M-2)){    // An o ippoths einai stin proteleutaia grammi tou pinaka
            att_true=1;
            if ( (table[knight_row+1][knight_col]==1 || table[knight_row+1][knight_col]==2 || table[knight_row+1][knight_col]==3) ){
              att_true=2;
                table[knight_row+1][knight_col]= table[knight_row+1][knight_col]-1; // Meiwsi zwhs, oxi opisthoxwrisi (giati einai akri)
            }
            if ( (table[0][knight_col]==1 || table[0][knight_col]==2 || table[0][knight_col]==3) ){
              att_true=2;
              table[0][knight_col]= table[0][knight_col]-1; // meiwsi zwhs, oxi opisthoxwrisi (giati einai akri akri)
              if (table[1][knight_col]==0){
                table[1][knight_col]=table[0][knight_col];
                table[0][knight_col]=0;
              }
            }
          }
          else if (knight_row==(M-1)){    // An o ippoths einai stin teleutaia grammi tou pinaka
            att_true=1;
            if ( (table[0][knight_col]==1 || table[0][knight_col]==2 || table[0][knight_col]==3) && (table[1][knight_col]==1 || table[1][knight_col]==2 || table[1][knight_col]==3) ){
              // An uparxei 1os kai 2os exthros
              att_true=2;
              table[0][knight_col]=table[0][knight_col]-1;
              table[1][knight_col]=table[1][knight_col]-1;
              if (table[2][knight_col]==0){
                table[2][knight_col]=table[1][knight_col];
                table[1][knight_col]=table[0][knight_col];
                table[0][knight_col]=0;
              }
              else{   // An o pisw paiktis molis stamatise na uparxei
                if (table[knight_row][2]==0){
                  table[knight_row][2]=table[knight_row][1];
                  table[knight_row][1]=0;
                }
              }
            }
            if ( (table[0][knight_col]==1 || table[0][knight_col]==2 || table[0][knight_col]==3) && (att_true!=2) ){
              att_true=2;
              table[0][knight_col]=table[0][knight_col]-1;
              if (table[1][knight_col]==0){
                table[1][knight_col]=table[0][knight_col];
                table[0][knight_col]=0;
              }
            }
            if ( (table[1][knight_col]==1 || table[1][knight_col]==2 || table[1][knight_col]==3) && (att_true!=2) ){
              att_true=2;
              table[1][knight_col]=table[1][knight_col]-1;
              if (table[2][knight_col]==0){
                table[2][knight_col]=table[1][knight_col];
                table[1][knight_col]=0;
              }
            }
          }
        }
        else if (move=='U' || move=='u' || (l==0 && *dir=='U') ){
          if (knight_row>=2){     // An o ippoths einai apo tin teleutaia grammh ews tin 3h
            att_true=1;
            if ( (table[knight_row-1][knight_col]>0 && table[knight_row-1][knight_col]!=222) && (table[knight_row-2][knight_col]>0 && table[knight_row-2][knight_col]!=222) ){
              // An uparxei 1os kai 2os exthros
              att_true=2;
              table[knight_row-1][knight_col]=table[knight_row-1][knight_col]-1;
              table[knight_row-2][knight_col]=table[knight_row-2][knight_col]-1;
              if ( (knight_row-3) >= 0 ){   // An h pisw thesi tous einai kenh
                if ( table[knight_row-3][knight_col]==0 ){
                  table[knight_row-3][knight_col]=table[knight_row-2][knight_col];
                  table[knight_row-2][knight_col]=table[knight_row-1][knight_col];
                  table[knight_row-1][knight_col]=0;
                }
                else { 
                  if (table[knight_row-2][knight_col]==0){
                    table[knight_row-2][knight_col]=table[knight_row-1][knight_col];
                    table[knight_row-1][knight_col]=0;
                  }
                }
              }
              else{   //  An pisw apo tous 2 exthrous den uparxei alli thesi, diladi einai o 2os stin akri tou tamplo kai me tin meiwsi zwis den uparxei pia (0 zwi), tote opisthoxwrei o 1os exthros kata 1 tetragwno
                if ( table[knight_row-2][knight_col]==0){
                  table[knight_row-2][knight_col]=table[knight_row-1][knight_col];
                  table[knight_row-1][knight_col]=0;
                }
              }
            }
            if ( (table[knight_row-1][knight_col]==1 || table[knight_row-1][knight_col]==2 || table[knight_row-1][knight_col]==3) && (att_true!=2)){
              // An uparxei 1os exthros
              att_true=2;
              table[knight_row-1][knight_col]=table[knight_row-1][knight_col]-1;
              if ( (knight_row-2) >= 0 ){
                if ( table[knight_row-2][knight_col]==0 ){
                  table[knight_row-2][knight_col]=table[knight_row-1][knight_col];
                  table[knight_row-1][knight_col]=0;
                }
              }
            }
            if ( (table[knight_row-2][knight_col]==1 || table[knight_row-2][knight_col]==2 || table[knight_row-2][knight_col]==3) && (att_true!=2) ){
              // An uparxei 2os exthros
              att_true=2;
              table[knight_row-2][knight_col]=table[knight_row-2][knight_col]-1;
              if ( (knight_row-3) >= 0 ){
                if ( table[knight_row-3][knight_col]==0 ){
                  table[knight_row-3][knight_col]=table[knight_row-2][knight_col];
                  table[knight_row-2][knight_col]=0;
                }
              }
            }
          }
          else if (knight_row==1){    // An o ippoths einai sthn 2h thesi
            att_true=1;
            if ( (table[knight_row-1][knight_col]==1 || table[knight_row-1][knight_col]==2 || table[knight_row-1][knight_col]==3) ){
              att_true=2;
              if (table[knight_row-1][knight_col]>0 && table[knight_row-1][knight_col]!=222){
                table[knight_row-1][knight_col]= table[knight_row-1][knight_col]-1; // Meiwsi zwhs, oxi opisthoxwrisi (giati einai akri)
              }
            }
            if ( (table[M-1][knight_col]==1 || table[M-1][knight_col]==2 || table[M-1][knight_col]==3) ){ 
              att_true=2;
              table[M-1][knight_col]= table[M-1][knight_col]-1;
              if (table[M-2][knight_col]==0){
                table[M-2][knight_col]=table[M-1][knight_col];
                table[M-1][knight_col]=0;
              }
            }
          }
          else if (knight_row==0){
            att_true=1;
            if ( (table[M-1][knight_col]==1 || table[M-1][knight_col]==2 || table[M-1][knight_col]==3) && (table[M-2][knight_col]==1 || table[M-2][knight_col]==2 || table[M-2][knight_col]==3) ){
              // An uparxei 1os kai 2os exthros
              att_true=2;
              table[M-1][knight_col]=table[M-1][knight_col]-1;
              table[M-2][knight_col]=table[M-2][knight_col]-1;
              if (table[M-3][knight_col]==0){
                table[M-3][knight_col]=table[M-2][knight_col];
                table[M-2][knight_col]=table[M-1][knight_col];
                table[M-1][knight_col]=0;
              }
              else{   // An o pisw paiktis molis stamatise na uparxei
                if (table[M-2][knight_col]==0){
                  table[M-2][knight_col]=table[M-1][knight_col];
                  table[M-1][knight_col]=0;
                }
              }
            }
            if ( (table[M-1][knight_col]==1 || table[M-1][knight_col]==2 || table[M-1][knight_col]==3) && (att_true!=2) ){
              att_true=2;
              table[M-1][knight_col]=table[M-1][knight_col]-1;
              if (table[M-2][knight_col]==0){
                table[M-2][knight_col]=table[M-1][knight_col];
                table[M-1][knight_col]=0;
              }
            }
            if ( (table[M-2][knight_col]==1 || table[M-2][knight_col]==2 || table[M-2][knight_col]==3) && (att_true!=2) ){
              att_true=2;
              table[M-2][knight_col]=table[M-2][knight_col]-1;
              if (table[M-3][knight_col]==0){
                table[M-3][knight_col]=table[M-2][knight_col];
                table[M-2][knight_col]=0;
              }
            }
          }
        }
        else if (move=='L' || move=='l' || (l==0 && *dir=='L') ){
          if ( (knight_col-1) >0 ){   // An o ippoths vrisketai apo thn 3h sthlh kai meta
            att_true=1;
            if ( (table[knight_row][knight_col-1]>0 || table[knight_row][knight_col-1]==2 || table[knight_row][knight_col-1]==3) && (table[knight_row][knight_col-2]==1 || table[knight_row][knight_col-2]==2 || table[knight_row][knight_col-2]==3)){
              // An uparxei 1os kai 2os exthros
              att_true=2;
              table[knight_row][knight_col-1]=table[knight_row][knight_col-1]-1;
              table[knight_row][knight_col-2]=table[knight_row][knight_col-2]-1;
              if ( (knight_col-3)>=0){      // An h thesi pisw apo tous exthrous den vgainei ektos oriwn
                if ( table[knight_row][knight_col-3]==0){
                  table[knight_row][knight_col-3]=table[knight_row][knight_col-2];
                  table[knight_row][knight_col-2]=table[knight_row][knight_col-1];
                  table[knight_row][knight_col-1]=0;
                }
                else {    // An pisw apo tous 2 exthrous uparxei empodio h allos exthros, tote opisthoxwrei o 1os exthros an o 2os exthros den uparxei pia me tin meiwsi zwis
                  if (table[knight_row][knight_col-2]==0){
                    table[knight_row][knight_col-2]=table[knight_row][knight_col-1];
                    table[knight_row][knight_col-1]=0;
                  }
                }
              }
              else{   // An pisw apo tous 2 exthrous uparxei empodio h allos exthros, tote opisthoxwrei o 1os exthros an o 2os exthros den uparxei pia me tin meiwsi zwis
                if ( table[knight_row][knight_col-2]==0){
                  table[knight_row][knight_col-2]=table[knight_row][knight_col-1];
                  table[knight_row][knight_col-1]=0;
                }
              }
            }
            if ((table[knight_row][knight_col-1]==1 || table[knight_row][knight_col-1]==2 || table[knight_row][knight_col-1]==3) && (att_true!=2)){
              // An uparxei 1os exthros
              att_true=2;
              table[knight_row][knight_col-1]=table[knight_row][knight_col-1]-1;
              if ( (knight_col-2)>=0){
                if ( table[knight_row][knight_col-2]==0 ){
                  table[knight_row][knight_col-2]=table[knight_row][knight_col-1];
                  table[knight_row][knight_col-1]=0;
                }
              }
            }
            if ((table[knight_row][knight_col-2]==1 || table[knight_row][knight_col-2]==2 || table[knight_row][knight_col-2]==3) && (att_true!=2) ){
              // An uparxei 2os exthros mono
              att_true=2;
              table[knight_row][knight_col-2]=table[knight_row][knight_col-2]-1;
              if ( (knight_col-3)>=0){
                if ( table[knight_row][knight_col-3]==0 ){
                  table[knight_row][knight_col-3]=table[knight_row][knight_col-2];
                  table[knight_row][knight_col-2]=0;
                }
              }
            }
          }
          else if ( (knight_col-1) == 0){ // An o ippoths vrisketai stin 2h sthlh
            att_true=1;
            if ((table[knight_row][knight_col-1]==1 || table[knight_row][knight_col-1]==2 || table[knight_row][knight_col-1]==3)){
              att_true=2;
              table[knight_row][knight_col-1]= table[knight_row][knight_col-1]-1;
            }
            // An uparxei exthros stin alli akri tou ippoth (N-1), borei na opisthoxwrisei
            if ((table[knight_row][N-1]==1 || table[knight_row][N-1]==2 || table[knight_row][N-1]==3)){
              att_true=2;
              table[knight_row][N-1]= table[knight_row][N-1]-1;
              if (table[knight_row][N-2]==0){
                table[knight_row][N-2]=table[knight_row][N-1];
                table[knight_row][N-1]=0;
              }
            }
          }
          if (knight_col==0){
            att_true=1;
            if ( (table[knight_row][N-1]==1 || table[knight_row][N-1]==2 || table[knight_row][N-1]==3) && (table[knight_row][N-2]==1 || table[knight_row][N-2]==2 || table[knight_row][N-2]==3) ){
              // An uparxei 1os kai 2os exthros
              att_true=2;
              table[knight_row][N-1]=table[knight_row][N-1]-1;
              table[knight_row][N-2]=table[knight_row][N-2]-1;
              if (table[knight_row][N-3]==0){
                table[knight_row][N-3]=table[knight_row][N-2];
                table[knight_row][N-2]=table[knight_row][N-1];
                table[knight_row][N-1]=0;
              }
              else{   // An o pisw paiktis molis stamatise na uparxei
                if (table[knight_row][2]==0){
                  table[knight_row][2]=table[knight_row][1];
                  table[knight_row][1]=0;
                }
              }
            }
            if ( (table[knight_row][N-1]==1 || table[knight_row][N-1]==2 || table[knight_row][N-1]==3) && (att_true!=2) ){
              att_true=2;
              table[knight_row][N-1]=table[knight_row][N-1]-1;
              if (table[knight_row][N-2]==0){
                table[knight_row][N-2]=table[knight_row][N-1];
                table[knight_row][N-1]=0;
              }
            }
            if ( (table[knight_row][N-2]==1 || table[knight_row][N-2]==2 || table[knight_row][N-2]==3) && (att_true!=2) ){
              att_true=2;
              table[knight_row][N-2]=table[knight_row][N-2]-1;
              if (table[knight_row][N-3]==0){
                table[knight_row][N-3]=table[knight_row][N-2];
                table[knight_row][N-2]=0;
              }
            }
          }
        }
        else if (move=='R' || move=='r' || (l==0 && *dir=='R') ){
          if ( (knight_col+1) < (N-1) ){    // An o ippoths einai stin paraproteleutaia sthlh
            att_true=1;
            if ( (table[knight_row][knight_col+1]>0 && table[knight_row][knight_col+1]!=222) && (table[knight_row][knight_col+2]>0 && table[knight_row][knight_col+2]!=222) ){
              // An uparxei 1os kai 2os exthros
              att_true=2;
              table[knight_row][knight_col+1]=table[knight_row][knight_col+1]-1;
              table[knight_row][knight_col+2]=table[knight_row][knight_col+2]-1;
              if ( (knight_col+3) <= (N-1)){
                if ( table[knight_row][knight_col+3]==0){
                  table[knight_row][knight_col+3]=table[knight_row][knight_col+2];
                  table[knight_row][knight_col+2]=table[knight_row][knight_col+1];
                  table[knight_row][knight_col+1]=0;
                }
                else {  
                  if (table[knight_row][knight_col+2]==0){
                    table[knight_row][knight_col+2]=table[knight_row][knight_col+1];
                    table[knight_row][knight_col+1]=0;
                  }
                }
              }
              else{   // An pisw apo tous 2 exthrous den uparxei alli thesi, diladi einai o 2os stin akri tou tamplo kai me tin meiwsi zwis den uparxei pia (0 zwi), tote opisthoxwrei o 1os exthros kata 1 tetragwno
                if ( table[knight_row][knight_col+2]==0){
                  table[knight_row][knight_col+2]=table[knight_row][knight_col+1];
                  table[knight_row][knight_col+1]=0;
                }
              }
            }
            if ((table[knight_row][knight_col+1]>0 && table[knight_row][knight_col+1]!=222) && (att_true!=2)){
              // An uparxei 1os exthros
              att_true=2;
              table[knight_row][knight_col+1]=table[knight_row][knight_col+1]-1;
              if ( (knight_col+2) <= (N-1)){
                if ( table[knight_row][knight_col+2]==0){
                  table[knight_row][knight_col+2]=table[knight_row][knight_col+1];
                  table[knight_row][knight_col+1]=0;
                }
              }
            }
            if ( (table[knight_row][knight_col+2]>0 && table[knight_row][knight_col+2]!=222) && (att_true!=2)){
              // An uparxei 2os exthros
              att_true=2;
              table[knight_row][knight_col+2]=table[knight_row][knight_col+2]-1;
              if ((knight_col+3) <= (N-1)){
                if ( table[knight_row][knight_col+3]==0){
                  table[knight_row][knight_col+3]=table[knight_row][knight_col+2];
                  table[knight_row][knight_col+2]=0;
                }
              }
            }
          }
          else if ( (knight_col+1) == (N-1) ){    // An o ippoths einai stin proteleutaia sthlh tou pinaka
            att_true=1;
            if ((table[knight_row][knight_col+1]==1 || table[knight_row][knight_col+1]==2 || table[knight_row][knight_col+1]==3)){
              att_true=2;
                table[knight_row][knight_col+1]= table[knight_row][knight_col+1]-1;
            }
            // An uparxei exthros stin alli akri tou ippoth (N-1), borei na opisthoxwrisei
            if ((table[knight_row][0]==1 || table[knight_row][0]==2 || table[knight_row][0]==3)){
              att_true=2;
              table[knight_row][0]= table[knight_row][0]-1;
              if (table[knight_row][1]==0){
                table[knight_row][1]=table[knight_row][0];
                table[knight_row][0]=0;
              }
            }
          }
          if (knight_col==(N-1)){
            att_true=1;
            if ( (table[knight_row][0]==1 || table[knight_row][0]==2 || table[knight_row][0]==3) && (table[knight_row][1]==1 || table[knight_row][1]==2 || table[knight_row][1]==3) ){
              // An uparxei 1os kai 2os exthros
              att_true=2;
              table[knight_row][0]=table[knight_row][0]-1;
              table[knight_row][1]=table[knight_row][1]-1;
              if (table[knight_row][2]==0){
                table[knight_row][2]=table[knight_row][1];
                table[knight_row][1]=table[knight_row][0];
                table[knight_row][0]=0;
              }
              else{   // ** rare periptwsi ** an o pisw paiktis molis stamatise na uparx
                if (table[knight_row][1]==0){
                  table[knight_row][1]=table[knight_row][0];
                  table[knight_row][0]=0;
                }
              }
            }
            if ( (table[knight_row][0]==1 || table[knight_row][0]==2 || table[knight_row][0]==3) && (att_true!=2) ){
              att_true=2;
              table[knight_row][0]=table[knight_row][0]-1;
              if (table[knight_row][1]==0){
                table[knight_row][1]=table[knight_row][0];
                table[knight_row][0]=0;
              }
            }
            if ( (table[knight_row][1]==1 || table[knight_row][1]==2 || table[knight_row][1]==3) && (att_true!=2) ){
              att_true=2;
              table[knight_row][1]=table[knight_row][1]-1;
              if (table[knight_row][2]==0){
                table[knight_row][2]=table[knight_row][1];
                table[knight_row][1]=0;
              }
            }
          }
        }
      }
      else if(att=='S' || att=='s'){
        att_abc=1;
        if (move=='D' || move=='d' || (l==0 && *dir=='D') ){
          if ( knight_row <= (M-2)){
            if (knight_col!=0 && knight_col!=(N-1)){    // An o ippoths den einai stis akres (ksexoristi periptosi)
              att_true=1;       // Gia tin idia sthlh (exthro)
              if (table[knight_row+1][knight_col]==1 || table[knight_row+1][knight_col]==2 || table[knight_row+1][knight_col]==3){
                att_true=2;
                table[knight_row+1][knight_col]=table[knight_row+1][knight_col]-1;
                if ( (knight_row+2) <= (M-1)){  // An h epithesi den vgainei ektos oriwn
                  if ( table[knight_row+2][knight_col]==0){
                    table[knight_row+2][knight_col]=table[knight_row+1][knight_col];
                    table[knight_row+1][knight_col]=0;
                  }
                }
              }       // Gia tin proigoumeni sthlh (exthro)
              if (table[knight_row+1][knight_col-1]==1 || table[knight_row+1][knight_col-1]==2 || table[knight_row+1][knight_col-1]==3){
                att_true=2;
                table[knight_row+1][knight_col-1]=table[knight_row+1][knight_col-1]-1;
                if ( (knight_row+2) <= (M-1)){  //////
                  if ( table[knight_row+2][knight_col-1]==0){
                    table[knight_row+2][knight_col-1]=table[knight_row+1][knight_col-1];
                    table[knight_row+1][knight_col-1]=0;
                  }
                }
              }         // Gia tin epomeni sthlh (exthro)
              if (table[knight_row+1][knight_col+1]==1 || table[knight_row+1][knight_col+1]==2 || table[knight_row+1][knight_col+1]==3){
                att_true=2;
                table[knight_row+1][knight_col+1]=table[knight_row+1][knight_col+1]-1;
                if ( (knight_row+2) <= (M-1)){
                  if ( table[knight_row+2][knight_col+1]==0){
                    table[knight_row+2][knight_col+1]=table[knight_row+1][knight_col+1];
                    table[knight_row+1][knight_col+1]=0;
                  }
                }
              }
            }
            else if (knight_col==0 && att_true==0){
              att_true=1;
              if (table[knight_row+1][knight_col]==1 || table[knight_row+1][knight_col]==2 || table[knight_row+1][knight_col]==3){
                att_true=2;
                table[knight_row+1][knight_col]=table[knight_row+1][knight_col]-1;
                if ((knight_row+2)<=(M-1)){   // An h epithesi den vgainei ektos oriwn
                  if (table[knight_row+2][knight_col]==0){
                    table[knight_row+2][knight_col]=table[knight_row+1][knight_col];
                    table[knight_row+1][knight_col]=0;
                  }
                }
              }         // Gia tin proigoumeni sthlh (exthro)
              if (table[M-1][N-1]==1 || table[M-1][N-1]==2 || table[M-1][N-1]==3){
                att_true=2;
                table[M-1][N-1]=table[M-1][N-1]-1;
                if ((knight_row+2)<=(M-1)){
                  if (table[M-2][N-1]==0){
                    table[M-2][N-1]=table[M-1][N-1];
                    table[M-1][N-1]=0;
                  }
                }
              }         // Gia tin epomeni sthlh (exthro)
              if (table[knight_row+1][knight_col+1]==1 || table[knight_row+1][knight_col+1]==2 || table[knight_row+1][knight_col+1]==3){
                att_true=2;
                table[knight_row+1][knight_col+1]=table[knight_row+1][knight_col+1]-1;
                if ((knight_row+2)<=(M-1)){ ////////////////////////////////
                  if (table[knight_row+2][knight_col+1]==0){
                    table[knight_row+2][knight_col+1]=table[knight_row+1][knight_col+1];
                    table[knight_row+1][knight_col+1]=0;
                  }
                }
              }
            }
            else if (knight_col==(N-1) && att_true==0){
              // Gia tin idia sthlh
              if (table[knight_row+1][knight_col]==1 || table[knight_row+1][knight_col]==2 || table[knight_row+1][knight_col]==3){
                att_true=2;
                table[knight_row+1][knight_col]=table[knight_row+1][knight_col]-1;
                if ((knight_row+2)<=(M-1)){
                  if (table[knight_row+2][knight_col]==0){
                    table[knight_row+2][knight_col]=table[knight_row+1][knight_col];
                    table[knight_row+1][knight_col]=0;
                  }
                }
              }
              // Gia tin proigoumeni sthlh
              if (table[knight_row+1][knight_col-1]==1 || table[knight_row+1][knight_col-1]==2 || table[knight_row+1][knight_col-1]==3){
                att_true=2;
                table[knight_row+1][knight_col-1]=table[knight_row+1][knight_col-1]-1;
                if ((knight_row+2)<=(M-1)){
                  if (table[knight_row+2][knight_col-1]==0){
                    table[knight_row+2][knight_col-1]=table[knight_row+1][knight_col-1];
                    table[knight_row+1][knight_col-1]=0;
                  }
                }
              }       // Gia tin epomeni sthlh
              if (table[knight_row+1][0]==1 || table[knight_row+1][0]==2 || table[knight_row+1][0]==3){
                att_true=2;
                table[knight_row+1][0]=table[knight_row+1][0]-1;
                if ((knight_row+2)<=(M-1)){
                  if (table[knight_row+2][0]==0){
                    table[knight_row+2][0]=table[knight_row+1][0];
                    table[knight_row+1][0]=0;
                  }
                }
              }
            }
          }
          else if (knight_row==(M-1)){    // An o ippoths vrisketai stin teleutaia sthlh tou pinaka (kai teleutaia grammi apo tin ekswteriki If)
            att_true=1;
            if (knight_col!=0 && knight_col!=(N-1)){
              if (table[0][knight_col]==1 || table[0][knight_col]==2 || table[0][knight_col]==3){
                // Gia tin idia sthlh
                att_true=2;
                table[0][knight_col]=table[0][knight_col]-1;
                if (table[1][knight_col]==0){
                  table[1][knight_col]=table[0][knight_col];
                  table[0][knight_col]=0;
                }
              }
              if (knight_row>=1){
                if (table[0][knight_col-1]==1 || table[0][knight_col-1]==2 || table[0][knight_col-1]==3){
                  // Gia tin idia sthlh
                  att_true=2;
                  table[0][knight_col-1]=table[0][knight_col-1]-1;
                  if (table[1][knight_col-1]==0){
                    table[1][knight_col-1]=table[0][knight_col-1];
                    table[0][knight_col-1]=0;
                  }
                }
              }
              if (knight_row<=(M-2)){ ///////////
                if (table[0][knight_col+1]==1 || table[0][knight_col+1]==2 || table[0][knight_col+1]==3){
                  // Gia tin idia sthlh
                  att_true=2;
                  table[0][knight_col+1]=table[0][knight_col+1]-1;
                  if (table[1][knight_col+1]==0){
                    table[1][knight_col+1]=table[0][knight_col+1];
                    table[0][knight_col+1]=0;
                  }
                }
              }
            }
            else if (knight_col==0){
              att_true=1;
              // Gia tin idia sthlh
              if (table[0][knight_col]==1 || table[0][knight_col]==2 || table[0][knight_col]==3){
                att_true=2;
                table[0][knight_col]=table[0][knight_col]-1;
                if (table[1][knight_col]==0){  
                  table[1][knight_col]=table[0][knight_col];
                  table[0][knight_col]=0;
                }
              }
              // Gia tin proigoumeni sthlh
              if (table[0][N-1]==1 || table[0][N-1]==2 || table[0][N-1]==3){
                att_true=2;
                table[0][N-1]=table[0][N-1]-1;
                if (table[1][N-1]==0){  
                  table[1][N-1]=table[0][N-1];
                  table[0][N-1]=0;
                }
              }
              // Gia tin epomeni sthlh
              if (table[0][knight_col+1]==1 || table[0][knight_col+1]==2 || table[0][knight_col+1]==3){
                att_true=2;
                table[0][knight_col+1]=table[0][knight_col+1]-1;
                if (table[1][knight_col+1]==0){  
                  table[1][knight_col+1]=table[0][knight_col+1];
                  table[0][knight_col+1]=0;
                }
              }
            }
            else if (knight_col==(N-1)){    // row = M-1 , col = N-1
              att_true=1;
              // Gia tin idia sthlh
              if (table[0][N-1]==1 || table[0][N-1]==2 || table[0][N-1]==3){
                att_true=2;
                table[0][N-1]=table[0][N-1]-1;
                if (table[1][N-1]==0){  
                  table[1][N-1]=table[0][N-1];
                  table[0][N-1]=0;
                }
              }
              // Gia tin proigoumeni sthlh
              if (table[0][N-2]==1 || table[0][N-2]==2 || table[0][N-2]==3){
                att_true=2;
                table[0][N-2]=table[0][N-2]-1;
                if (table[1][N-2]==0){  
                  table[1][N-2]=table[0][N-2];
                  table[0][N-2]=0;
                }
              }
              // Gia tin epomeni sthlh
              if (table[0][knight_col]==1 || table[0][knight_col]==2 || table[0][knight_col]==3){
                att_true=2;
                table[0][knight_col]=table[0][knight_col]-1;
                if (table[1][knight_col]==0){  
                  table[1][knight_col]=table[0][knight_col];
                  table[0][knight_col]=0;
                }
              }
            }
          }
        }
        else if (move=='U' || move=='u' || (l==0 && *dir=='U') ){
          if ( knight_row >= 1){
            if (knight_col!=0 && knight_col!=(N-1)){
              att_true=1;       // gia tin idia sthlh
              if (table[knight_row-1][knight_col]==1 || table[knight_row-1][knight_col]==2 || table[knight_row-1][knight_col]==3){
                att_true=2;
                table[knight_row-1][knight_col]=table[knight_row-1][knight_col]-1;
                if ( (knight_row-2) >= 0){  ///
                  if ( table[knight_row-2][knight_col]==0){
                    table[knight_row-2][knight_col]=table[knight_row-1][knight_col];
                    table[knight_row-1][knight_col]=0;
                  }
                }
              }       // gia tin proigoumeni sthlh
              if (table[knight_row-1][knight_col-1]==1 || table[knight_row-1][knight_col-1]==2 || table[knight_row-1][knight_col-1]==3){
                att_true=2;
                table[knight_row-1][knight_col-1]=table[knight_row-1][knight_col-1]-1;
                if ( (knight_row-2) >= 0){  ///
                  if ( table[knight_row-2][knight_col-1]==0){
                    table[knight_row-2][knight_col-1]=table[knight_row-1][knight_col-1];
                    table[knight_row-1][knight_col-1]=0;
                  }
                }
              }         // gia tin epomeni sthlh
              if (table[knight_row-1][knight_col+1]==1 || table[knight_row-1][knight_col+1]==2 || table[knight_row-1][knight_col+1]==3){
                att_true=2;
                table[knight_row-1][knight_col+1]=table[knight_row-1][knight_col+1]-1;
                if ( (knight_row-2) >= 0){  ///
                  if ( table[knight_row-2][knight_col+1]==0){
                    table[knight_row-2][knight_col+1]=table[knight_row-1][knight_col+1];
                    table[knight_row-1][knight_col+1]=0;
                  }
                }
              }
            }
            else if (knight_col==0 && att_true==0){  // row <M-1, col=0
              att_true=1;
              if (table[knight_row-1][knight_col]==1 || table[knight_row-1][knight_col]==2 || table[knight_row-1][knight_col]==3){
                // gia tin idia sthlh
                att_true=2;
                table[knight_row-1][knight_col]=table[knight_row-1][knight_col]-1;
                if ((knight_row-2)>=0){
                  if (table[knight_row-2][knight_col]==0){
                    table[knight_row-2][knight_col]=table[knight_row-1][knight_col];
                    table[knight_row-1][knight_col]=0;
                  }
                }
              }         // gia tin proigoumeni sthlh
              if (table[M-1][N-1]==1 || table[M-1][N-1]==2 || table[M-1][N-1]==3){
                att_true=2;
                table[M-1][N-1]=table[M-1][N-1]-1;
                if ((knight_row+2)<=(M-1)){
                  if (table[M-2][N-1]==0){
                    table[M-2][N-1]=table[M-1][N-1];
                    table[M-1][N-1]=0;
                  }
                }
              }       // gia tin epomeni sthlh
              if (table[knight_row-1][knight_col+1]==1 || table[knight_row-1][knight_col+1]==2 || table[knight_row-1][knight_col+1]==3){
                att_true=2;
                table[knight_row-1][knight_col+1]=table[knight_row-1][knight_col+1]-1;
                if ((knight_row-2)>=0){
                  if (table[knight_row-2][knight_col+1]==0){
                    table[knight_row-2][knight_col+1]=table[knight_row-1][knight_col+1];
                    table[knight_row-1][knight_col+1]=0;
                  }
                }
              }
            }
            else if (knight_col==(N-1) && att_true==0){
              //gia tin idia sthlh
              if (table[knight_row-1][knight_col]==1 || table[knight_row-1][knight_col]==2 || table[knight_row-1][knight_col]==3){
                att_true=2;
                table[knight_row-1][knight_col]=table[knight_row-1][knight_col]-1;
                if ((knight_row-2)>=0){
                  if (table[knight_row-2][knight_col]==0){
                    table[knight_row-2][knight_col]=table[knight_row-1][knight_col];
                    table[knight_row-1][knight_col]=0;
                  }
                }
              }       // gia tin proigoumeni sthlh
              if (table[knight_row-1][knight_col-1]==1 || table[knight_row-1][knight_col-1]==2 || table[knight_row-1][knight_col-1]==3){
                att_true=2;
                table[knight_row-1][knight_col-1]=table[knight_row-1][knight_col-1]-1;
                if ((knight_row-2)>=0){
                  if (table[knight_row-2][knight_col-1]==0){
                    table[knight_row-2][knight_col-1]=table[knight_row-1][knight_col-1];
                    table[knight_row-1][knight_col-1]=0;
                  }
                }
              }       // gia tin epomeni sthlh
              if (table[knight_row-1][0]==1 || table[knight_row-1][0]==2 || table[knight_row-1][0]==3){
                att_true=2;
                table[knight_row-1][0]=table[knight_row-1][0]-1;
                if ((knight_row-2)>=0){
                  if (table[knight_row-2][0]==0){
                    table[knight_row-2][0]=table[knight_row-1][0];
                    table[knight_row-1][0]=0;
                  }
                }
              }
            }
          }
          else if (knight_row==0){    // An o ippoths einai stin prwti grammi
            att_true=1;
            if ((knight_col!=0) && (knight_col!=(N-1))){    // An o ippoths den einai stis akrianes sthles
              if (table[M-1][knight_col]==1 || table[M-1][knight_col]==2 || table[M-1][knight_col]==3){ // Gia tin idia sthlh
                att_true=2;
                table[M-1][knight_col]=table[M-1][knight_col]-1;
                if (table[M-2][knight_col]==0){
                  table[M-2][knight_col]=table[M-1][knight_col];
                  table[M-1][knight_col]=0;
                }
              }
              if (knight_col-1>=0){ // Gia tin proigoumeni sthlh
                if (table[M-1][knight_col-1]==1 || table[M-1][knight_col-1]==2 || table[M-1][knight_col-1]==3){
                  att_true=2;
                  table[M-1][knight_col-1]=table[M-1][knight_col-1]-1;
                  if (table[M-2][knight_col-1]==0){
                    table[M-2][knight_col-1]=table[M-1][knight_col-1];
                    table[M-1][knight_col-1]=0;
                  }
                }
              }
              if ((knight_col+1)<=(M-2)){
                if (table[M-1][knight_col+1]==1 || table[M-1][knight_col+1]==2 || table[M-1][knight_col+1]==3){ // Gia tin epomeni sthlh
                  att_true=2;
                  table[M-1][knight_col+1]=table[M-1][knight_col+1]-1;
                  if (table[M-2][knight_col+1]==0){
                    table[M-2][knight_col+1]=table[M-1][knight_col+1];
                    table[M-1][knight_col+1]=0;
                  }
                }
              }
            }
            else if (knight_col==0){    // An o ippoths einai stin prwth sthlh
              att_true=1;
              // gia tin idia grammi
              if (table[M-1][0]==1 || table[M-1][0]==2 || table[M-1][0]==3){
                att_true=2;
                table[M-1][0]=table[M-1][0]-1;
                if (table[M-2][0]==0){  
                  table[M-2][knight_col]=table[M-1][0];
                  table[M-1][0]=0;
                }
              }
              // gia tin proigoumeni grammi
              if (table[M-1][N-1]==1 || table[M-1][N-1]==2 || table[M-1][N-1]==3){
                att_true=2;
                table[M-1][N-1]=table[M-1][N-1]-1;
                if (table[M-2][N-1]==0){  
                  table[M-2][N-1]=table[M-1][N-1];
                  table[M-1][N-1]=0;
                }
              }
              //gia tin epomeni grammi
              if (table[M-1][1]==1 || table[M-1][1]==2 || table[M-1][1]==3){
                att_true=2;
                table[M-1][1]=table[M-1][1]-1;
                if (table[M-2][1]==0){  
                  table[M-2][1]=table[M-1][1];
                  table[M-1][1]=0;
                }
              }
            }
            else if (knight_col==(N-1)){    // An o ippoths einai sthn teleutaia sthlh
              att_true=1;
              // gia tin idia grammi
              if (table[M-1][N-1]==1 || table[M-1][N-1]==2 || table[M-1][N-1]==3){
                att_true=2;
                table[M-1][N-1]=table[M-1][N-1]-1;
                if (table[M-2][N-1]==0){  
                  table[M-2][N-1]=table[M-1][N-1];
                  table[M-1][N-1]=0;
                }
              }
              // gia tin proigoumeni grammi
              if (table[M-1][N-2]==1 || table[M-1][N-2]==2 || table[M-1][N-2]==3){
                att_true=2;
                table[M-1][N-2]=table[M-1][N-2]-1;
                if (table[M-2][N-2]==0){  
                  table[M-2][N-2]=table[M-1][N-2];
                  table[M-1][N-2]=0;
                }
              }
              // gia tin epomeni grammi
              if (table[M-1][0]==1 || table[M-1][0]==2 || table[M-1][0]==3){
                att_true=2;
                table[M-1][0]=table[M-1][0]-1;
                if (table[M-2][0]==0){  
                  table[M-2][0]=table[M-1][0];
                  table[M-1][0]=0;
                }
              }
            }
          }
        }
        else if (move=='L' || move=='l' || (l==0 && *dir=='L') ){
          if ( knight_col >= 1){
            if (knight_row!=0 && knight_row!=(M-1)){
              att_true=1;       // gia tin idia grammi
              if (table[knight_row][knight_col-1]==1 || table[knight_row][knight_col-1]==2 || table[knight_row][knight_col-1]==3){
                att_true=2;
                table[knight_row][knight_col-1]=table[knight_row][knight_col-1]-1;
                if ( (knight_col-2) >= 0){
                  if ( table[knight_row][knight_col-2]==0){
                    table[knight_row][knight_col-2]=table[knight_row][knight_col-1];
                    table[knight_row][knight_col-1]=0;
                  }
                }
              }       // gia tin proigoumeni grammi
              if (table[knight_row-1][knight_col-1]==1 || table[knight_row-1][knight_col-1]==2 || table[knight_row-1][knight_col-1]==3){
                att_true=2;
                table[knight_row-1][knight_col-1]=table[knight_row-1][knight_col-1]-1;
                if ( (knight_col-2) >= 0){
                  if ( table[knight_row-1][knight_col-2]==0 ){
                    table[knight_row-1][knight_col-2]=table[knight_row-1][knight_col-1];
                    table[knight_row-1][knight_col-1]=0;
                  }
                }
              }         // gia tin epomeni grammi
              if (table[knight_row+1][knight_col-1]==1 || table[knight_row+1][knight_col-1]==2 || table[knight_row+1][knight_col-1]==3){
                att_true=2;
                if (table[knight_row+1][knight_col-1]>0 && table[knight_row+1][knight_col-1]!=222){
                  table[knight_row+1][knight_col-1]=table[knight_row+1][knight_col-1]-1;
                  if ( (knight_col-2) >= 0){
                    if ( table[knight_row+1][knight_col-2]==0 ){
                      table[knight_row+1][knight_col-2]=table[knight_row+1][knight_col-1];
                      table[knight_row+1][knight_col-1]=0;
                    }
                  }
                }
              }
            }
            else if (knight_row==0 && att_true==0){  // row = 0, col>1
              att_true=1;   // Gia tin idia grammi
              if (table[0][knight_col-1]==1 || table[0][knight_col-1]==2 || table[0][knight_col-1]==3){
                att_true=2;
                table[0][knight_col-1]=table[0][knight_col-1]-1;
                if (knight_col-2>=0){
                  if (table[0][knight_col-2]==0){
                    table[0][knight_col-2]=table[0][knight_col-1];
                    table[0][knight_col-1]=0;
                  }
                }
              }         // gia tin proigoumeni grammi
              if (table[M-1][knight_col-1]==1 || table[M-1][knight_col-1]==2 || table[M-1][knight_col-1]==3){
                att_true=2;
                table[M-1][knight_col-1]=table[M-1][knight_col-1]-1;
                if (knight_col-2>=0){
                  if (table[M-1][knight_col-2]==0){
                    table[M-1][knight_col-2]=table[M-1][knight_col-1];
                    table[M-1][knight_col-1]=0;
                  }
                }
              }         // gia tin epomeni grammi
              if (table[1][knight_col-1]==1 || table[1][knight_col-1]==2 || table[1][knight_col-1]==3){
                att_true=2;
                table[1][knight_col-1]=table[1][knight_col-1]-1;
                if (knight_col-2>=0){
                  if (table[1][knight_col-2]==0){
                    table[1][knight_col-2]=table[0][knight_col-1];
                    table[0][knight_col-1]=0;
                  }
                }
              }
            }
            else if (knight_row==(M-1) && att_true==0){ 
              //gia tin idia grammi
              if (table[M-1][knight_col-1]==1 || table[M-1][knight_col-1]==2 || table[M-1][knight_col-1]==3){
                att_true=2;
                table[M-1][knight_col-1]=table[M-1][knight_col-1]-1;
                if (knight_col-2>=0){
                  if (table[M-1][knight_col-2]==0){
                    table[M-1][knight_col-2]=table[M-1][knight_col-1];
                    table[M-1][knight_col-1]=0;
                  }
                }
              }       // gia tin proigoumeni grammi
              if (table[M-2][knight_col-1]==1 || table[M-2][knight_col-1]==2 || table[M-2][knight_col-1]==3){
                att_true=2;
                table[M-2][knight_col-1]=table[M-2][knight_col-1]-1;
                if (knight_col-2>=0){
                  if (table[M-2][knight_col-2]==0){
                    table[M-2][knight_col-2]=table[M-2][knight_col-1];
                    table[M-2][knight_col-1]=0;
                  }
                }
              }       // gia tin epomeni grammi
              if (table[0][knight_col-1]==1 || table[0][knight_col-1]==2 || table[0][knight_col-1]==3){
                att_true=2;
                table[0][knight_col-1]=table[0][knight_col-1]-1;
                if (knight_col-2>=0){
                  if (table[0][knight_col-2]==0){
                    table[0][knight_col-2]=table[0][knight_col-1];
                    table[0][knight_col-1]=0;
                  }
                }
              }
            }
          }
          else if (knight_col==0){
            att_true=1;
            if (knight_row!=0 && knight_row!=(M-1)){
              if (table[knight_row][N-1]==1 || table[knight_row][N-1]==2 || table[knight_row][N-1]==3){ // Gia tin idia grammi
                att_true=2;
                table[knight_row][N-1]=table[knight_row][N-1]-1;
                if (table[knight_row][N-2]==0){
                  table[knight_row][N-2]=table[knight_row][N-1];
                  table[knight_row][N-1]=0;
                }
              }
              if (knight_row>=1){     // Gia tin panw grammi
                if (table[knight_row-1][N-1]==1 || table[knight_row-1][N-1]==2 || table[knight_row-1][N-1]==3){
                  att_true=2;
                  table[knight_row-1][N-1]=table[knight_row-1][N-1]-1;
                    if (table[knight_row-1][N-2]==0){
                      table[knight_row-1][N-2]=table[knight_row-1][N-1];
                      table[knight_row-1][N-1]=0;
                    }
                }
              }
              if (knight_row<=(M-2)){     // Gia tin katw grammi
                if (table[knight_row+1][N-1]==1 || table[knight_row+1][N-1]==2 || table[knight_row+1][N-1]==3){
                  att_true=2;
                  table[knight_row+1][N-1]=table[knight_row+1][N-1]-1;
                    if (table[knight_row+1][N-2]==0){
                      table[knight_row+1][N-2]=table[knight_row+1][N-1];
                      table[knight_row+1][N-1]=0;
                    }
                }
              }
            }
            else if (knight_row==0){
              att_true=1;
              // gia tin idia grammi
              if (table[0][N-1]==1 || table[0][N-1]==2 || table[0][N-1]==3){
                att_true=2;
                table[0][N-1]=table[0][N-1]-1;
                if (table[0][N-2]==0){  
                  table[0][N-2]=table[0][N-1];
                  table[0][N-1]=0;
                }
              }
              // gia tin proigoumeni grammi
              if (table[M-1][N-1]==1 || table[M-1][N-1]==2 || table[M-1][N-1]==3){
                att_true=2;
                table[M-1][N-1]=table[M-1][N-1]-1;
                if (table[M-1][N-2]==0){  
                  table[M-1][N-2]=table[M-1][N-1];
                  table[M-1][N-1]=0;
                }
              }
              //gia tin epomeni grammi
              if (table[1][N-1]==1 || table[1][N-1]==2 || table[1][N-1]==3){
                att_true=2;
                table[1][N-1]=table[1][N-1]-1;
                if (table[1][N-2]==0){  
                  table[1][N-2]=table[1][N-1];
                  table[1][N-1]=0;
                }
              }
            }
            else if (knight_row==(M-1)){
              att_true=1;
              // gia tin idia grammi
              if (table[M-1][N-1]==1 || table[M-1][N-1]==2 || table[M-1][N-1]==3){
                att_true=2;
                table[M-1][N-1]=table[M-1][N-1]-1;
                if (table[M-1][N-2]==0){
                  table[M-1][N-2]=table[M-1][N-1];
                  table[M-1][N-1]=0;
                }
              }
              // gia tin proigoumeni grammi
              if (table[M-2][N-1]==1 || table[M-2][N-1]==2 || table[M-2][N-1]==3){
                att_true=2;
                table[M-2][N-1]=table[M-2][N-1]-1;
                if (table[M-2][N-2]==0){
                  table[M-2][N-2]=table[M-2][N-1];
                  table[M-2][N-1]=0;
                }
              }
              // gia tin epomeni grammi
              if (table[0][N-1]==1 || table[0][N-1]==2 || table[0][N-1]==3){
                att_true=2;
                table[0][N-1]=table[0][N-1]-1;
                if (table[0][N-2]==0){
                  table[0][N-2]=table[0][N-1];
                  table[0][N-1]=0;
                }
              }
            }
          }
        }
        else if (move=='R' || move=='r' || (l==0 && *dir=='R') ){
          if ( knight_col <= (N-2)){
            if (knight_row!=0 && knight_row!=(M-1)){
              att_true=1;       // gia tin idia grammi
              if (table[knight_row][knight_col+1]==1 || table[knight_row][knight_col+1]==2 || table[knight_row][knight_col+1]==3){
                att_true=2;
                table[knight_row][knight_col+1]=table[knight_row][knight_col+1]-1;
                if ( (knight_col+2) <= (N-1)){
                  if ( table[knight_row][knight_col+2]==0){
                    table[knight_row][knight_col+2]=table[knight_row][knight_col+1];
                    table[knight_row][knight_col+1]=0;
                  }
                }
              }       // gia tin proigoumeni grammi
              if (table[knight_row-1][knight_col+1]==1 || table[knight_row-1][knight_col+1]==2 || table[knight_row-1][knight_col+1]==3){
                att_true=2;
                table[knight_row-1][knight_col+1]=table[knight_row-1][knight_col+1]-1;
                if ( (knight_col+2) <= (N-1)){
                  if ( table[knight_row-1][knight_col+2]==0 ){
                    table[knight_row-1][knight_col+2]=table[knight_row-1][knight_col+1];
                    table[knight_row-1][knight_col+1]=0;
                  }
                }
              }         // gia tin epomeni grammi
              if (table[knight_row+1][knight_col+1]==1 || table[knight_row+1][knight_col+1]==2 || table[knight_row+1][knight_col+1]==3){
                att_true=2;
                  table[knight_row+1][knight_col+1]=table[knight_row+1][knight_col+1]-1;
                  if ( (knight_col+2) <= (N-1)){
                    if ( table[knight_row+1][knight_col+2]==0 ){
                      table[knight_row+1][knight_col+2]=table[knight_row+1][knight_col+1];
                      table[knight_row+1][knight_col+1]=0;
                    }
                  }
              }
            }
            else if (knight_row==0 && att_true==0){
              att_true=1;           // gia tin idia grammi
              if (table[0][knight_col+1]==1 || table[0][knight_col+1]==2 || table[0][knight_col+1]==3){
                att_true=2;
                table[0][knight_col+1]=table[0][knight_col+1]-1;
                if ( (knight_col+2)<=(N-1)){
                  if (table[0][knight_col+2]==0){
                    table[0][knight_col+2]=table[0][knight_col+1];
                    table[0][knight_col+1]=0;
                  }
                }
              }         // gia tin proigoumeni grammi
              if (table[M-1][knight_col+1]==1 || table[M-1][knight_col+1]==2 || table[M-1][knight_col+1]==3){
                att_true=2;
                table[M-1][knight_col+1]=table[M-1][knight_col+1]-1;
                if ( (knight_col+2)<=(N-1)){
                  if (table[M-1][knight_col+2]==0){
                    table[M-1][knight_col+2]=table[M-1][knight_col+1];
                    table[M-1][knight_col+1]=0;
                  }
                }
              }         // gia tin epomeni grammi
              if (table[1][knight_col+1]==1 || table[1][knight_col+1]==2 || table[1][knight_col+1]==3){
                att_true=2;
                table[1][knight_col+1]=table[1][knight_col+1]-1;
                if ( (knight_col+2)<=(N-1)){
                  if (table[1][knight_col+2]==0){
                    table[1][knight_col+2]=table[0][knight_col+1];
                    table[0][knight_col+1]=0;
                  }
                }
              }
            }
            else if (knight_row==(M-1) && att_true==0){
              //gia tin idia grammi
              if (table[M-1][knight_col+1]==1 || table[M-1][knight_col+1]==2 || table[M-1][knight_col+1]==3){
                att_true=2;
                table[M-1][knight_col+1]=table[M-1][knight_col+1]-1;
                if ( (knight_col+2)<=(N-1)){
                  if (table[M-1][knight_col+2]==0){
                    table[M-1][knight_col+2]=table[M-1][knight_col+1];
                    table[M-1][knight_col+1]=0;
                  }
                }
              }       // gia tin proigoumeni grammi
              if (table[M-2][knight_col+1]==1 || table[M-2][knight_col+1]==2 || table[M-2][knight_col+1]==3){
                att_true=2;
                table[M-2][knight_col+1]=table[M-2][knight_col+1]-1;
                if ( (knight_col+2)<=(N-1)){
                  if (table[M-2][knight_col+2]==0){
                    table[M-2][knight_col+2]=table[M-2][knight_col+1];
                    table[M-2][knight_col+1]=0;
                  }
                }
              }       // gia tin epomeni grammi
              if (table[0][knight_col+1]==1 || table[0][knight_col+1]==2 || table[0][knight_col+1]==3){
                att_true=2;
                table[0][knight_col+1]=table[0][knight_col+1]-1;
                if ( (knight_col+2)<= (N-1)){
                  if (table[0][knight_col+2]==0){
                    table[0][knight_col+2]=table[0][knight_col+1];
                    table[0][knight_col+1]=0;
                  }
                }
              }
            }
          }
          else if (knight_col==(N-1)){
            att_true=1;
            if (knight_row!=0 && knight_row!=(M-1)){
              if (table[knight_row][0]==1 || table[knight_row][0]==2 || table[knight_row][0]==3){ // Gia tin idia grammi
                att_true=2;
                table[knight_row][0]=table[knight_row][0]-1;
                if (table[knight_row][1]==0){
                  table[knight_row][1]=table[knight_row][0];
                  table[knight_row][0]=0;
                }
              }
              if (knight_row>=1){     // Gia tin panw grammi
                if (table[knight_row-1][0]==1 || table[knight_row-1][0]==2 || table[knight_row-1][0]==3){
                  att_true=2;
                  table[knight_row-1][0]=table[knight_row-1][0]-1;
                  if (table[knight_row-1][1]==0){
                    table[knight_row-1][1]=table[knight_row-1][0];
                    table[knight_row-1][0]=0;
                  }
                }
              }
              if (knight_row<=(M-2)){     // Gia tin katw grammi
                if (table[knight_row+1][0]==1 || table[knight_row+1][0]==2 || table[knight_row+1][0]==3){
                  att_true=2;
                  table[knight_row+1][0]=table[knight_row+1][0]-1;
                    if (table[knight_row+1][1]==0){
                      table[knight_row+1][1]=table[knight_row+1][0];
                      table[knight_row+1][0]=0;
                    }
                }
              }
            }
            else if (knight_row==0){
              att_true=1;
              // gia tin idia grammi
              if (table[0][0]==1 || table[0][0]==2 || table[0][0]==3){
                att_true=2;
                table[0][0]=table[0][0]-1;
                if (table[0][1]==0){  
                  table[0][1]=table[0][0];
                  table[0][0]=0;
                }
              }
              // gia tin proigoumeni grammi
              if (table[M-1][0]==1 || table[M-1][0]==2 || table[M-1][0]==3){
                att_true=2;
                table[M-1][0]=table[M-1][0]-1;
                if (table[M-1][1]==0){  
                  table[M-1][1]=table[M-1][0];
                  table[M-1][0]=0;
                }
              }
              //gia tin epomeni grammi
              if (table[1][0]==1 || table[1][0]==2 || table[1][0]==3){
                att_true=2;
                table[1][0]=table[1][0]-1;
                if (table[1][0]==0){  
                  table[1][0]=table[1][0];
                  table[1][0]=0;
                }
              }
            }
            else if (knight_row==(M-1)){
              att_true=1;
              // gia tin idia grammi
              if (table[M-1][0]==1 || table[M-1][0]==2 || table[M-1][0]==3){
                att_true=2;
                table[M-1][0]=table[M-1][0]-1;
                if (table[M-1][1]==0){
                  table[M-1][1]=table[M-1][0];
                  table[M-1][0]=0;
                }
              }
              // gia tin proigoumeni grammi
              if (table[M-2][0]==1 || table[M-2][0]==2 || table[M-2][0]==3){
                att_true=2;
                table[M-2][0]=table[M-2][0]-1;
                if (table[M-2][1]==0){
                  table[M-2][1]=table[M-2][0];
                  table[M-2][0]=0;
                }
              }
              // gia tin epomeni grammi
              if (table[0][0]==1 || table[0][0]==2 || table[0][0]==3){
                att_true=2;
                table[0][0]=table[0][0]-1;
                if (table[0][1]==0){
                  table[0][1]=table[0][0];
                  table[0][0]=0;
                }
              }
            }
          }
        }
      }
      else if(att=='B' || att=='b'){
        att_abc=1;
        if (move=='D' || move=='d' || (l==0 && *dir=='D') ){
          if ( (knight_row+2) < (M-1) ){
            att_true=1;
            if (table[knight_row+2][knight_col]==1 || table[knight_row+2][knight_col]==2 || table[knight_row+2][knight_col]==3){
              att_true=2;
              if (table[knight_row+2][knight_col]>0 && table[knight_row+2][knight_col]!=222){
                table[knight_row+2][knight_col]=table[knight_row+2][knight_col]-1;
                if (table[knight_row+3][knight_col]==0){
                  table[knight_row+3][knight_col]=table[knight_row+2][knight_col];
                  table[knight_row+2][knight_col]=0;
                }
              }
            }
          }
          else if ( (knight_row+2) == (M-1) ){
            att_true=1;
            if (table[knight_row+2][knight_col]==1 || table[knight_row+2][knight_col]==2 || table[knight_row+2][knight_col]==3){
              att_true=2;
              if (table[knight_row+2][knight_col]>0 && table[knight_row+2][knight_col]!=222){
                table[knight_row+2][knight_col]=table[knight_row+2][knight_col]-1;
              }
            }
          }
          if (knight_row==(M-1)){
            att_true=1;
            if (table[1][knight_col]==1 || table[1][knight_col]==2 || table[1][knight_col]==3){
              att_true=2;
              table[1][knight_col]=table[1][knight_col]-1;
              if (table[2][knight_col]==0){
                table[2][knight_col]=table[1][knight_col];
                table[1][knight_col]=0;
              }
            }
          }
          else if (knight_row==(M-2)){
            att_true=1;
            if (table[0][knight_col]==1 || table[0][knight_col]==2 || table[0][knight_col]==3){
              att_true=2;
              table[0][knight_col]=table[0][knight_col]-1;
              if (table[1][knight_col]==0){
                table[1][knight_col]=table[0][knight_col];
                table[0][knight_col]=0;
              }
            }
          }
        }
        else if (move=='U' || move=='u' || (l==0 && *dir=='U') ){
          if ( (knight_row-2) > 0 ){
            att_true=1;
            if (table[knight_row-2][knight_col]==1 || table[knight_row-2][knight_col]==2 || table[knight_row-2][knight_col]==3){
              att_true=2;
              if (table[knight_row-2][knight_col]>0 && table[knight_row-2][knight_col]!=222){
                table[knight_row-2][knight_col]=table[knight_row-2][knight_col]-1;
                if (table[knight_row-3][knight_col]==0){
                  table[knight_row-3][knight_col]=table[knight_row-2][knight_col];
                  table[knight_row-2][knight_col]=0;
                }
              }
            }
          }
          else if ( (knight_row-2) == 0 ){
            att_true=1;
            if (table[knight_row-2][knight_col]==1 || table[knight_row-2][knight_col]==2 || table[knight_row-2][knight_col]==3){
              att_true=2;
              if (table[knight_row-2][knight_col]>0 && table[knight_row-2][knight_col]!=222){
                table[knight_row-2][knight_col]=table[knight_row-2][knight_col]-1;
              }
            }
          }
        }
        else if (move=='R' || move=='r' || (l==0 && *dir=='R') ){
          if ( (knight_col+2) < (N-1) ){
            att_true=1;
            if (table[knight_row][knight_col+2]==1 || table[knight_row][knight_col+2]==2 || table[knight_row][knight_col+2]==3){
              att_true=2;
              if (table[knight_row][knight_col+2]>0 && table[knight_row][knight_col+2]!=222){
                table[knight_row][knight_col+2]=table[knight_row][knight_col+2]-1;
                if (table[knight_row][knight_col+3]==0){
                  table[knight_row][knight_col+3]=table[knight_row][knight_col+2];
                  table[knight_row][knight_col+2]=0;
                }
              }
            }
          }
          else if ( (knight_col+2) == (N-1) ){
            att_true=1;
            if (table[knight_row][knight_col+2]==1 || table[knight_row][knight_col+2]==2 || table[knight_row][knight_col+2]==3){
              att_true=2;
              if (table[knight_row][knight_col+2]>0 && table[knight_row][knight_col+2]!=222){
                table[knight_row][knight_col+2]=table[knight_row][knight_col+2]-1;
              }
            }
          }
        }
        else if (move=='L' || move=='l' || (l==0 && *dir=='L') ){
          if ( (knight_col-2) > 0 ){
            att_true=1;
            if (table[knight_row][knight_col-2]==1 || table[knight_row][knight_col-2]==2 || table[knight_row][knight_col-2]==3){
              att_true=2;
              if (table[knight_row][knight_col-2]>0 && table[knight_row][knight_col-2]!=222){
                table[knight_row][knight_col-2]=table[knight_row][knight_col-2]-1;
                if (table[knight_row][knight_col-3]==0){
                  table[knight_row][knight_col-3]=table[knight_row][knight_col-2];
                  table[knight_row][knight_col-2]=0;
                }
              }
            }
          }
          else if ( (knight_col-2) == 0 ){
            att_true=1;
            if (table[knight_row][knight_col-2]==1 || table[knight_row][knight_col-2]==2 || table[knight_row][knight_col-2]==3){
              att_true=2;
              if (table[knight_row][knight_col-2]>0 && table[knight_row][knight_col-2]!=222){
                table[knight_row][knight_col-2]=table[knight_row][knight_col-2]-1;
              }
            }
          }
        }
      }
      else{
        if (j!=0)
          printf("\nWrong key. Please try again!\n\n");
      }
      if (att_true==0){
        att_true=1;     // Panta ginontai oi epitheseis akoma ki an kapoies fores den petuxainoun exthro, to =1 sumvolize prin oti htan entos oriwn kai htan boithitiko gia tin pragmatopoihsh kapoiwn if, alla twra ginetai 1  gia na ginei h airball epithesi kai na emfanistei to katallilo minima
      }
      if (att_true==1){
        printf("\nAirball. You didn't attack a nearby enemy. \n");
      }
    }while( (att_true!=2 && att_true!=1) || att_abc!=1);
    if (att_true==2){
      if (att=='F' || att=='f'){
        lmoney=lmoney+50;
        *gmoney=*gmoney+50;
      }
      else if (att=='A' || att=='a'){
        lmoney=lmoney+70;
        *gmoney=*gmoney+70;
      }
      else if (att=='S' || att=='s'){
        lmoney=lmoney+80;
        *gmoney=*gmoney+80;
      }
      else if (att=='B' || att=='b'){
        lmoney=lmoney+60;
        *gmoney=*gmoney+60;
      }
    }

    //Ektupwsi tou pinaka meta tin epithesi tou ippoth
    printf("\n\n");
    for (i=0; i<M; i++){
      if (i==0){
        printf("    ");
        for (j=0; j<N; j++){
          if (j<9){
            printf("%d ", j+1);
          }
          else{
            printf("%d", j+1);      // Emfanize kollita ta 10+
          }
        }
        printf("\n----");
        for (j=0; j<N; j++){
        	printf("--");
        }
        printf("\n");
      }
      if (i<9){
        printf("%d | ", i+1);
      }
      else{
        printf("%d| ", i+1);      // Stis sthles na einai kollitos to 10+ me to |
      }
      for(j=0;j<N;j++){
        if (table[i][j]==1 || table[i][j]==2 || table[i][j]==3){
          printf("%d ", table[i][j]);
        }
        else if (table[i][j]==222){
          printf("# ");
        }
        else if (table[i][j]==333){
          printf("$ ");
        }
        else{
          printf(". ");
        }
      }
      printf("\n");
    }
    printf("\nLevel money spent: %d \nGame money spent: %d \nMake your move(s): ", lmoney, *gmoney);
    }
    else if (c1=='X' || c1=='x'){
      exit(1);
    }
    pl=0;
    for (i=0; i<M; i++){
      for (j=0; j<N; j++){
        if (table[i][j]==1 || table[i][j]==2 || table[i][j]==3){
          pl=pl+1;
        }
      }
    }
    if (pl==0){
      ple=0;
    }
  
  }     // Telos tou kathe gurou
  // Telos sunarthshs
}
