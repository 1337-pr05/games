#include<stdio.h>
#include<time.h> 
char grid[3][3]={' ',' ',' '
                ,' ',' ',' ',
                ' ',' ',' '};
void mesh(){
    int i,j;
printf("               THE BOARD LOOK LIKE THIS\n");
printf("                     %c | %c | %c\n",grid[0][0],grid[0][1],grid[0][2]);
printf("                    ___________\n");    
printf("                     %c | %c | %c\n",grid[1][0],grid[1][1],grid[1][2]);
printf("                    ___________\n");
printf("                     %c | %c | %c\n",grid[2][0],grid[2][1],grid[2][2]);
}
int input_player(void){
    int x,y;
    printf("\nINPUT THE COORINATE WHERE YOU WANT TO ENTER THE DESIRED CROSS\n");
    printf("YOUR INPUT (X,Y)");
    scanf("%d%d",&x,&y);
    if(checkgrid(x,y)){
        printf("wrong coordinate\n");
        input_player();
    }
    else{grid[x][y]='X';}
}
int input_computer(){
    int x,y;
    // int srand(0);
    x=rand() % 3;
    y=rand() % 3;
    if(checkgrid(x,y)){
        input_computer();
    }
    else{
        grid[x][y]='O';mesh(grid);}
}
int checkgrid(int x,int y){
    if(grid[x][y]==' '){
        return 0 ;
    }
    else{return 1;}
}
int check_empty(char grid[3][3]){
    int i;int j,r=0;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(grid[i][j]==' '){
                r+=1;
            }
            
        }
    }
    if(r>0)return 1;
    else return 0;
}
int match_player(char grid[3][3]){
    if((grid[0][0]=='X') && (grid[0][1]=='X')&& (grid[0][2]=='X')) return 'X';
    if((grid[1][0]=='X') && (grid[1][1]=='X')&& (grid[1][2]=='X')) return 'X';
    if((grid[2][0]=='X') && (grid[2][1]=='X')&& (grid[2][2]=='X')) return 'X';
    if((grid[0][0]=='X') && (grid[1][0]=='X')&& (grid[2][0]=='X')) return 'X';
    if((grid[0][1]=='X') && (grid[1][1]=='X')&& (grid[2][1]=='X')) return 'X';
    if((grid[0][2]=='X') && (grid[1][2]=='X')&& (grid[2][2]=='X')) return 'X'; 
    if((grid[0][0]=='X') && (grid[1][1]=='X')&& (grid[2][2]=='X')) return 'X';
    if((grid[0][2]=='X') && (grid[1][1]=='X')&& (grid[2][0]=='X')) return 'X';
    else{return 0;}
}
int match_computer(char grid[3][3]){
    if((grid[0][0]=='O') && (grid[0][1]=='O') && (grid[0][2]=='O')) return 'O';
    if((grid[1][0]=='O') && (grid[1][1]=='O') && (grid[1][2]=='O')) return 'O';
    if((grid[2][0]=='O') && (grid[2][1]=='O') && (grid[2][2]=='O')) return 'O';
    if((grid[0][0]=='O') && (grid[1][0]=='O') && (grid[2][0]=='O')) return 'O';
    if((grid[0][1]=='O') && (grid[1][1]=='O') && (grid[2][1]=='O')) return 'O';
    if((grid[0][2]=='O') && (grid[1][2]=='O') && (grid[2][2]=='O')) return 'O';
    if((grid[0][0]=='O') && (grid[1][1]=='O') && (grid[2][2]=='O')) return 'O';
    if((grid[0][2]=='O') && (grid[1][1]=='O') && (grid[2][0]=='O')) return 'O';
    else{return 1;}
}
void tie(char grid[3][3]){
    if(match_computer(grid)!='O'&&match_player(grid)!='X'){
        printf("ITS A TIE");
    }
}
int main(){
    int turn=0;
    int H_score=0,C_score=0;
    int i,j=0;
    printf("                        SCORE HUMAN-%d / COMPUTER-%d\n",H_score,C_score);
    printf("                    WELCOME TO THE GAME OF TIC-TAC-TOE\n");
    printf("                    THERE TO 255,168 POSSIBITIES TO PLAY THE GAME\n");
    int play=0;
    printf("ENTER 1 TO PLAY\nENTER 0 TO QUIT:-");
    scanf("%d",&play);
    mesh();
    while(play){
        if(!(check_empty(grid))) {goto win_player;} 
        input_player();
        if(match_player(grid)=='X'){mesh();
                printf("player won computer lost\n");
                H_score+=1;
                printf("DO YOU WANT TO PLAY AGAIN YOU KNOW THE DRILL\n");
                scanf("%d",&play);printf("NEW SCORE IS HUMAN-%d / COMPUTER-%d\n",H_score,C_score);
                
                if(play){
                    for(int i=0 ;i<3;i++){
                    for(int j=0;j<3;j++){
                        grid[i][j]=' ';
                    }
                   }
                   mesh();turn=0;
                }
                else{break;}
            }
        win_player:
            if(match_player(grid)=='X'){mesh();
                printf("player won computer lost\n");
                H_score+=1;
                printf("DO YOU WANT TO PLAY AGAIN YOU KNOW THE DRILL\n");
                scanf("%d",&play);printf("NEW SCORE IS HUMAN-%d / COMPUTER-%d\n",H_score,C_score);
                if(play){
                       for(int i=0 ;i<3;i++){
                    for(int j=0;j<3;j++){
                        grid[i][j]=' ';
                    }
                   }
                   mesh();turn=0;
                }
                else{break;}
            }
        if(!(check_empty(grid))) {goto win_computer;} 
        input_computer();
        if(match_computer(grid)=='O'){mesh();
                printf("player lost computer won\n");
                C_score+=1;
                printf("DO YOU WANT TO PLAY AGAIN YOU KNOW THE DRILL\n");
                scanf("%d",&play);printf("NEW SCORE IS HUMAN-%d / COMPUTER-%d\n",H_score,C_score);
                if(play){
                       for(int i=0 ;i<3;i++){
                    for(int j=0;j<3;j++){
                        grid[i][j]=' ';
                    }
                   }
                   mesh();turn=0;
                }
                else{break;}
            }
        win_computer:
            if(match_computer(grid)=='O'){
                mesh();
                printf("player lost computer won\n");
                C_score+=1;
                printf("DO YOU WANT TO PLAY AGAIN YOU KNOW THE DRILL\n");
                scanf("%d",&play);
                printf("NEW SCORE IS HUMAN-%d / COMPUTER-%d\n",H_score,C_score);
                if(play){
                   for(int i=0 ;i<3;i++){
                    for(int j=0;j<3;j++){
                        grid[i][j]=' ';
                    }
                   }
                   mesh();turn=0;
                }
                else{break;}
            }
            if(turn==8){
                printf("ITS A TIE\n");
                printf("DO YOU WANT TO PLAY AGAIN YOU KNOW THE DRILL\n");
                scanf("%d",&play);
                printf("NEW SCORE IS HUMAN-%d / COMPUTER-%d\n",H_score,C_score);
                getch();
                if(play){
                   for(int i=0 ;i<3;i++){
                    for(int j=0;j<3;j++){
                        grid[i][j]=' ';
                    }
                   }
                   mesh();
                   turn=0;
                   continue;
            }
           
            }
        turn++;

    }
   
    return 0;
}