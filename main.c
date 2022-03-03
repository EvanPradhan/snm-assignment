#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<stdbool.h>
int NTLine=8,MaxLinks=3,arrivaltime,MeanInterArrivalTime,MeanLength;
int callinProgress[7]={NULL};
int LengthofCallinProgress[3]={NULL};
int ArrivalofCall[3]={NULL};
indexing[6];
int Blocked,Busy,Processed,Completed;
int OriginCall,DestinationCall,LengthCall,SumofCallLength,sumofArrivalTime,ClosestArrivalTime=0;
bool StateofBusyCall=false,increaselengthcall=false;
int LinkInUse=0;
int Simulationtimer=0,nexttimer;//clock timer = simulation timer
char clocktimerStop;
void main(){
    for(int i=1;i<=NTLine;i++){
        if(NTLine<(2*MaxLinks+2)){
            printf("Too Few Lines Specified. Simulation Abandoned.");
            exit (0);
        }else{
            ArrivalNow();
            printf("\n\nSimulation of Telephone System \n\n");
            printf("No. of Lines             %d\n",NTLine);
            printf("No. of Maximum Links     %d\n",MaxLinks);
            printf("No. of Links in Use      %d\n",LinkInUse);
            printf("Mean Inter Arrival Time  %d\n",MeanInterArrivalTime);
            printf("Mean Call Length         %d\n",MeanLength);
            printf("Simulation clock Time    %d\n\n\n",Simulationtimer);

            printf("\nCall Processed           %d\n",Processed);
            printf("Call Completed           %d \n",Completed);
            printf("Busy Calls               %d\n",Busy);
            printf("Blocked calls            %d\n",Blocked);

            ClosestArrivalTime= ArrivalofCall[0];
            for(int k=0;k<LinkInUse;k++){
                    if(ClosestArrivalTime<ArrivalofCall[k]){
                        ClosestArrivalTime = ArrivalofCall[k];
                    }
            }
            Simulationtimer = ClosestArrivalTime;
            if(increaselengthcall==true){
                LengthofCallinProgress[LinkInUse-1]= Simulationtimer + LengthCall;
                increaselengthcall=false;
            }
            printf("\nAfter Updated Simulation clock Time    %d\n\n\n",Simulationtimer);
            Checkcounters();
            printf("\nCall Processed           %d\n",Processed);
            printf("Call Completed           %d \n",Completed);
            printf("Busy Calls               %d\n",Busy);
            printf("Blocked calls            %d\n",Blocked);

            }

        }
    getch();
}
void ArrivalNow(){
    printf("\nEnter the new Origin, Destination,Length and Arrival Time of the call\n");
    scanf("%d %d %d %d",&OriginCall,&DestinationCall,&LengthCall,&arrivaltime);
    if(LinkInUse>=MaxLinks){
            Blocked++;
            Processed = Processed + 1;
            printf("\nAll links are in used. So blocked is increase now\n");
    }
    else{
        if((OriginCall>=0 && OriginCall <=7) && (DestinationCall>=0 && DestinationCall <=7)){
                if(callinProgress[OriginCall-1]!=1 && callinProgress[DestinationCall-1]!=1){
                    callinProgress[OriginCall-1]=1;
                    callinProgress[DestinationCall-1]=1;
                    }
                else{
                    StateofBusyCall=true;

                }
        }else{
            printf("\nOrigin or Destination call entered is out of bounds\n");
            }

    if(StateofBusyCall==true){
        Busy++;
        StateofBusyCall = false;
    }
    if(callinProgress[OriginCall-1]==1 && callinProgress[DestinationCall-1]==1){
                    LinkInUse++;
                    increaselengthcall = true;
                    LengthofCallinProgress[LinkInUse-1]= Simulationtimer + LengthCall;
                    ArrivalofCall[LinkInUse-1] = arrivaltime + Simulationtimer;
                    for(int j=0;j<LinkInUse;j++){
                        SumofCallLength = LengthofCallinProgress[j] + SumofCallLength;
                        sumofArrivalTime = ArrivalofCall[j] + sumofArrivalTime;
                    }
                    MeanLength = SumofCallLength/LinkInUse;
                    MeanInterArrivalTime = sumofArrivalTime/LinkInUse;
    }
}
}
Checkcounters(){
    Processed++;
    for(int c=0;c<LinkInUse;c++){
        if(Simulationtimer>=LengthofCallinProgress[c]){
            LinkInUse--;
            Completed++;
        }
    }
}
