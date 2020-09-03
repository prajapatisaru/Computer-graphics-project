#include<conio.h>
#include<stdio.h>
#include<graphics.h>
#include<stdlib.h>
#include<dos.h>
//creating loading window
int window1; //this winodw1 help to create the loading screen

void loadingscreen(){
    window1 = initwindow(700,500); // creating loading screen
    setcolor(15);
    settextstyle(DEFAULT_FONT,HORIZ_DIR,2);  //it helps to change the fontsize  and font direction and size of text
    line(10,9,getmaxx(),9);  //getemaxx() is a funtion to get maximum size of screen
    outtextxy(10,20,"Made by Saru:");
    outtextxy(10,60,"Computer Graphics Project ---> ");
    line(10,90,getmaxx(),90);
    settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
    outtextxy(30,200," \"Walking in the Rain\"");
    setcolor(12);
    settextstyle(DEFAULT_FONT,HORIZ_DIR,5);
    outtextxy(50,300,"LOADING.....");
    line(50,350,getmaxx(),350);
    getch(); //press any key to continue to main project /
    closegraph(window1);  //here the loading screen will be close
}

void displayMan(int x,int y)
{
circle(x,y,20); //face
line(x,y+20,x,y+30); //neck
line(x,y+30,x+20,y+40); //right hand
line(x+20,y+40,x+30,y+30);
line(x,y+30,x,y+70); //body
line(x+30,y+30,x+30,y-90); //umbrella
pieslice(x+30,y-30,0,180,55);
}

void displayWoman(int a,int b)
{
circle(a,b,20); //face
line(a,b+20,a,b+30); //neck
line(a,b+30,a,b+70); //body

}


int main(){
    loadingscreen();
	int gd=DETECT,gm,i,d=0,x=50,y=340,c=0,a=110,b=340,Move=1;
	initgraph(&gd,&gm,"");
	int rx,ry;
	while(1)
{
	cleardevice();
	displayMan(x,340);
	displayWoman(a,340);
	line(0,430,700,430);
for(i=0;i<800;i++)

{
	rx=rand()%700;
	ry=rand()%430;
	if(rx>=(x-40)&&rx<=(x+110))
	 if(ry>=(y-50)&&ry<=470)

	continue;

	line(rx-3,ry+8,rx,ry);

}

//moving hands and legs For DisplayMan

if(Move)

{

	if(d<20)

	d+=4;

	else

	Move=0;
	line(x,y+70,x-d,y+90);
	line(x,y+30,x-d,y+40);

	line(x,y+70,x+d,y+90);
}
 else

{


	if(d>0)

	d-=4;

	else

	Move=1;

	line(x,y+70,x-d,y+90);
    line(x,y+30,x+d,y+50);
	line(x,y+70,x+d,y+90);
}
	x=(x+10)%700;


//moving legs and hands For DisplayWoman

if(Move)

{

	if(c<20)

	c+=4;

	else

	Move=0;
	line(a,b+70,a-c,b+90);
	line(a,b+30,a-c,b+50);
	line(a,b+70,a+c,b+90);
		line(a,b+30,a+c,b+50);


}

 else

{
	if(c>0)

	c-=4;

	else

	Move=1;

	line(a,b+70,a-c,b+90);
	line(a,b+30,a-c,b+50);
	line(a,b+70,a+c,b+90);
	line(a,b+30,a+c,b+50);
}
	delay(200);
	a=(a+10)%700;



}
getch();
}

