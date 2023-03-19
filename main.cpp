#include <iostream>
#include <conio.h>
#include <windows.h>
#include "mmsystem.h"
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>


using namespace std;
typedef enum {black,blue,green,cyan,red,magenta,yellow,white,gray,lightblue,lightgreen,lightcyan,lightred,lightmagenta,lightyellow,lightwhite};


class Profile;
void under(char);
void remove(char);
void poseclr(int, int);
void clrposeclr(int,int);
void layout();
void setColor(int, int);
void intro();
void lesson1(Profile);
void lesson2(Profile);
void lesson3(Profile);
void lesson4(Profile);
void lesson5(Profile);
void lesson6(Profile);
void openlessons(int, Profile);
void profiles();
void updateProfile(string, int, int);
void createNew();
void congrats(int);
void test();
void test1();
void test2();
void test3();
void high(int);
void gotoxy (int, int);
int CheckKeyPressed(int);
void layoutPlane();
void game();
void play();
void instructions();
void erase(int, int, int);
void view();


void gotoxy (int x, int y)
{
    COORD coord; // coordinates of screen
    coord.X = x; coord.Y = y; // set value of x and y coordinates
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); // take cursor to that position
}

void setColor(int textColor, int bgColor)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (textColor + (bgColor * 16)));
}


                            //   all classes

class Profile{
	private:
		string Name;
		int level;
		int location;
	public:
		Profile()
		{
			Name="";
			level=1;
			location=0;
		}
		Profile(string a, int b, int c)
		{
			Name=a;
			level=b;
			location=c;
		}
		void setName(string a) { Name=a;}
		void setlevel(int a) { level=a;}
		void setLocation(int a) { location=a;}
		int getLocation(){ return location;}
		string getName() { return Name;}
		int getLevel() { return level;}
};

class Plane{
    private:
        int x;
        int y;
        int flag;
    public:
        Plane(int a=0, int b=0, int c=0)
        {
            x=a;
            y=b;
            flag=c;
        }

        int getFlag() { return flag;}

        void drawPlane(int a)
        {
            if(flag==1)
            {
                gotoxy(x,y++);  cout << "     *\n";
                gotoxy(x,y++);  cout << "	**\n";
                gotoxy(x,y++);  cout << "*      ***\n";
                gotoxy(x,y++);  cout << " **     *****\n";
                gotoxy(x,y++);  cout << "****************\n";
                gotoxy(x,y++);  cout << " **     *****\n";
                gotoxy(x,y++);  cout << "*      ***\n";
                gotoxy(x,y++);  cout << "      **\n";
                gotoxy(x,y++);  cout << "     *\n";
            }
            y=a;
        }

        void destroyPlane()
        {
            flag=0;
            gotoxy(10,y++);  cout << "      \n";
            gotoxy(10,y++);  cout << "	     \n";
            gotoxy(10,y++);  cout << "          \n";
            gotoxy(10,y++);  cout << "             \n";
            gotoxy(10,y++);  cout << "                \n";
            gotoxy(10,y++);  cout << "             \n";
            gotoxy(10,y++);  cout << "          \n";
            gotoxy(10,y++);  cout << "        \n";
            gotoxy(10,y++);  cout << "      \n";
        }
        void fire(int a, int y)
        {
                int x=20;
            setColor(white,black);
            for(int i=0;i<a-5;i++){
                gotoxy(x++,y);
                cout << "---";
            }

            x=20;
            Sleep(10);
            for(int i=0;i<a-5;i++){
                gotoxy(x++,y);
                cout << "   ";
            }

            PlaySound(TEXT("fire.wav"),NULL,SND_SYNC);
            PlaySound(TEXT("exp.wav"),NULL,SND_SYNC);
        }
};

class Fingers{
	private:
		int leftX;
		int leftY;
		int rightX;
		int rightY;
	public:
		Fingers()
		{
			leftX=50;
			leftY=35;

			rightX=100;
			rightY=36;
		}

		void print(){

			setColor(white,black);
			gotoxy(leftX,leftY);
			cout << "^";
			gotoxy(leftX-1,leftY+1);
			cout << "(";
			gotoxy(leftX,leftY+1);
			cout << "O";
			gotoxy(leftX+1,leftY+1);
			cout << ")";
			gotoxy(leftX+4,leftY-1);
			cout << "^";
			gotoxy(leftX+3,leftY);
			cout << "(";
			gotoxy(leftX+4,leftY);
			cout << "O";
			gotoxy(leftX+5,leftY);
			cout << ")";
			gotoxy(leftX+8,leftY-2);
			cout << "^";
			gotoxy(leftX+7,leftY-1);
			cout << "(";
			gotoxy(leftX+8,leftY-1);
			cout << "O";
			gotoxy(leftX+9,leftY-1);
			cout << ")";
			gotoxy(leftX+12,leftY-1);
			cout << "^";
			gotoxy(leftX+11,leftY);
			cout << "(";
			gotoxy(leftX+12,leftY);
			cout << "O";
			gotoxy(leftX+13,leftY);
			cout << ")";
			gotoxy(leftX+16,leftY+1);
			cout << "^";
			gotoxy(leftX+15,leftY+2);
			cout << "(";
			gotoxy(leftX+16,leftY+2);
			cout << "O";
			gotoxy(leftX+17,leftY+2);
			cout << ")";


			gotoxy(rightX,rightY);
			cout << "^";
			gotoxy(rightX-1,rightY+1);
			cout << "(";
			gotoxy(rightX,rightY+1);
			cout << "O";
			gotoxy(rightX+1,rightY+1);
			cout << ")";
			gotoxy(rightX+4,rightY-2);
			cout << "^";
			gotoxy(rightX+3,rightY-1);
			cout << "(";
			gotoxy(rightX+4,rightY-1);
			cout << "O";
			gotoxy(rightX+5,rightY-1);
			cout << ")";
			gotoxy(rightX+8,rightY-3);
			cout << "^";
			gotoxy(rightX+7,rightY-2);
			cout << "(";
			gotoxy(rightX+8,rightY-2);
			cout << "O";
			gotoxy(rightX+9,rightY-2);
			cout << ")";
			gotoxy(rightX+12,rightY-2);
			cout << "^";
			gotoxy(rightX+11,rightY-1);
			cout << "(";
			gotoxy(rightX+12,rightY-1);
			cout << "O";
			gotoxy(rightX+13,rightY-1);
			cout << ")";
			gotoxy(rightX+16,rightY-1);
			cout << "^";
			gotoxy(rightX+15,rightY);
			cout << "(";
			gotoxy(rightX+16,rightY);
			cout << "O";
			gotoxy(rightX+17,rightY);
			cout << ")";
			gotoxy(28,50);
			cout << endl;
		}

		void poseclr(int x,int y)
		{
			gotoxy(x,y);
			setColor(green,black);
			cout << "O";
			gotoxy(10,10);
		}

		void clrposeclr(int x,int y)
		{
			gotoxy(x,y);
			setColor(white,black);
			cout << "O";
			gotoxy(10,10);
		}
		void under(char x)
		{

			if(x=='A'||x=='a'||x==9||x==14||x==15||x=='Q'||x=='q'||x=='Z'||x=='z'||x==49)
			poseclr(50,36);
			else if(x=='W'||x=='w'||x=='X'||x=='x'||x=='S'||x=='s'||x==50)
			poseclr(54,35);
			else if(x=='E'||x=='e'||x=='D'||x=='d'||x=='C'||x=='c'||x==51)
			poseclr(58,34);
			else if(x=='R'||x=='r'||x=='T'||x=='t'||x=='F'||x=='f'||x=='G'||x=='g'||x=='V'||x=='v'||x=='B'||x=='b'||x==52||x==53)
			poseclr(62,35);
			else if(x=='Y'||x=='y'||x=='U'||x=='u'||x=='H'||x=='h'||x=='J'||x=='j'||x=='N'||x=='n'||x=='M'||x=='m'||x==54||x==55)
			poseclr(104,35);
			else if(x=='I'||x=='i'||x=='K'||x=='k'||x==','||x==56)
			poseclr(108,34);
			else if(x=='O'||x=='o'||x=='L'||x=='l'||x==57)
			poseclr(112,35);
			else if(x=='P'||x=='p'||x==40||x==41||x==92||x==58||x==39||x==61||x==45||x==59||x==48||x==13)
			poseclr(116,36);
			else
			poseclr(66,37);
		}

		void remove(char x)
		{

			if(x=='A'||x=='a'||x==9||x==14||x==15||x=='Q'||x=='q'||x=='Z'||x=='z'||x==49)
			clrposeclr(50,36);
			else if(x=='W'||x=='w'||x=='X'||x=='x'||x=='S'||x=='s'||x==50)
			clrposeclr(54,35);
			else if(x=='E'||x=='e'||x=='D'||x=='d'||x=='C'||x=='c'||x==51)
			clrposeclr(58,34);
			else if(x=='R'||x=='r'||x=='T'||x=='t'||x=='F'||x=='f'||x=='G'||x=='g'||x=='V'||x=='v'||x=='B'||x=='b'||x==52||x==53)
			clrposeclr(62,35);
			else if(x=='Y'||x=='y'||x=='U'||x=='u'||x=='H'||x=='h'||x=='J'||x=='j'||x=='N'||x=='n'||x=='M'||x=='m'||x==54||x==55)
			clrposeclr(104,35);
			else if(x=='I'||x=='i'||x=='K'||x=='k'||x==','||x==56)
			clrposeclr(108,34);
			else if(x=='O'||x=='o'||x=='L'||x=='l'||x==57)
			clrposeclr(112,35);
			else if(x=='P'||x=='p'||x==40||x==41||x==92||x==58||x==39||x==61||x==45||x==59||x==48||x==13)
			clrposeclr(116,36);
			else
			clrposeclr(66,37);
		}

};



class Result{
	private:
		int i_diff;
		float diff;
		float time;
		float speed;
		float arc;
		int scr;
		int c;
	public:
		Result()
		{
			i_diff=0;
			diff=0;
			time=0;
			speed=0;
			arc=0;
			scr=0;
			c=0;
		}
		Result(int a, float b, float i, float d, float e, int f, int g)
		{
			i_diff=a;
			diff=b;
			time=i;
			speed=d;
			arc=e;
			scr=f;
			c=g;
		}
		void Print()
		{
			cout << fixed << showpoint << setprecision(2);

			gotoxy(70,11);
			setColor(yellow,black);
			cout << "Time taken= " << time << " min";
			cout << fixed << showpoint << setprecision(1);
			gotoxy(70,13);
			cout << "Correct Entries= " << c;
			gotoxy(70,15);
			cout << "Typing Speed= " << speed  <<" WPH";
			gotoxy(70,17);
			cout << "Accuracy= " << arc << "%";
			gotoxy(70,19);
			cout << "Total Score= " << scr << " points";

			high(scr);
		}
};

class Phrase{
	private:
		string A;
		int size;
	public:
		Phrase()
		{
			A = "";
			size=0;
		}

		Phrase(string a, char b)
		{
			A=a;
			A[0]=b;
			size=A.length();
		}

		void setPhrase(string a)
		{
			A =a;
			size = A.length();
		}

		int getSize() { return size;}

		void Print()
		{
			setColor(white,black);
			gotoxy(72, 18);
			for(int i=0;i<size;i++){
				if(A[i]=='0')
					gotoxy(72,19);
				else
					cout << A[i];
			}
		}

		void Print(int a)
		{
			int x=45, y=14;
			gotoxy(x, y);
			setColor(white,black);
			for(int i=0;i<size;i++){
				if(A[i]=='0')
				{
					x=45;
					y++;
					gotoxy(x,y);
				}

				else
					cout << A[i];
			}
		}

		int Input()
		{
			int a=44,b=24,m=0,c=3;
			char z;
			for(int i=0;i<size;){

					gotoxy(a,b);

					z=getch();
				  	if(z==27)
				    	intro();
				 	else{

						if(z==13)
						{
							a=44;
							b++;
						}

						if(z==13 && A[i]!=0)
						{
							m++;
						}

						else if(z!=A[i]&&A[i]!=0)
						{
							m++;
							a++;
						}
						else
						{
							c++;
							a++;
						}

					  	setColor(lightblue,black);
					  	putch(z);
					  	i++;
				  	}
				}

				return c;
		}


		char getPhraseCh(int a) { return A[a];}

};

class Text{
	private:
		Phrase* ptr;
	public:
		Text()
		{
			ptr= new Phrase[2];
			ptr[0];
			ptr[1];
		}

		Text(int size, string arr[])
		{
			ptr= new Phrase[size];
			for(int i=0;i<size;i++){
				ptr[i].setPhrase(arr[i]);
			}
		}

		char getchar(int a, int b)	{ return ptr[a].getPhraseCh(b);}

		int getPhraseSize(int a) { return ptr[a].getSize();}

		void Print(int a)
		{
			ptr[a].Print();
		}

		void Print(int a,int b)
		{
			ptr[a].Print(b);
		}

		void Input(int n, Fingers F, Profile A, int a=72, int b=22)
		{
			int length=getPhraseSize(n);
			for(int i=0;i<length;){

				F.under(getchar(n,i));

				gotoxy(5,1);
                cout << " ";

				gotoxy(a,b);

				int c=getch();

			    if(c==27)
                {
                    updateProfile(A.getName(),A.getLocation(),0);
                    intro();
                }
			    else{

					if(c==13 && getchar(n,i)=='0')
					{
						a=72;
						b++;
						F.remove(getchar(n,i));
						i++;
					}

					else if(c==getchar(n,i))
					{

						putch(c);//putch displays key pressed
						F.remove(getchar(n,i));
						i++;
						a++;
					}
					else
					{
						Beep(2000,300);
					}
			    }
			}
		}

		~Text()
		{
			delete ptr;
		}
};


                            //   layout functions

void layout()
{
		int x=10, y=4;
	setColor(gray,black);
	gotoxy(x,y);
	for(int i=1;i<=150;i++){
		cout << "-";
	}

	gotoxy(10,40);
	for(int i=1;i<=150;i++){
		cout << "-";
	}

}

void layoutPlane()
{
    	int x=7, y=6;
	setColor(gray,black);
	gotoxy(x,y);
	for(int i=1;i<=154;i++){
		cout << "-";
	}

	gotoxy(x,43);
	for(int i=1;i<=154;i++){
		cout << "-";
	}

	y=7;

	for(int i=1;i<=36;i++){
        gotoxy(130,y++);
		cout << "|";
	}

	gotoxy(136,15);
    cout << "Typed: ";

    gotoxy(136,20);
    cout << "Score: 0";

    gotoxy(136,25);
    cout << "Remaining planes:  ";

    gotoxy(136,30);
    setColor(red,black);
    cout << "Press ESC to exit";

}

void congrats(int a)
{
    system("cls");
    layout();
    for(int i=0;i<3;i++){
        if(i==0)
           setColor(yellow,black);
        else if(i==1)
            setColor(blue,black);
        else
            setColor(green,black);
        gotoxy(67,22);
		cout << "Lesson "<< a << " completed Sucessfully";
		gotoxy(73, 14);
		cout << "Congratulations!";
		gotoxy(73, 16);
		cout << "Congratulations!";
		gotoxy(73, 18);
		cout << "Congratulations!";
		gotoxy(73, 20);
		cout << "Congratulations!";
		Sleep(700);
    }
    PlaySound(TEXT("41.wav"),NULL,SND_SYNC);
}

void high(int y)
{
	int x;
	fstream f;

	f.open("file.txt",ios::in);
	if(f.is_open()){
		f>>x;
		f.close();
	}

	if(x<y){
        system("cls");
        layout();

		gotoxy(69,23);
		setColor(cyan,black);
		cout << "*****Congratulations*****";
		Sleep(900);
		gotoxy(69,25);
		setColor(yellow,black);
		cout << "*****Congratulations*****";
		Sleep(900);
		gotoxy(69,27);
		setColor(yellow,black);
		cout << "*****Congratulations*****";
		Sleep(900);
		setColor(red,black);
		gotoxy(74,30);
		cout <<"New high score!";
		PlaySound(TEXT("high.wav"),NULL,SND_SYNC);
		string n;
		gotoxy(69,34);
		setColor(white,black);
		cout << "Enter Name: ";
		cin >> n;

		updateProfile(n,0,y);
	}
}

void erase(int a, int b, int c)
{
    gotoxy(a,b);
    for(int q=0;q<c;q++){
        cout << " ";
    }
}


                                //   all lessons


void openlessons(int a, Profile A)
{
    switch(a){
		case 1: lesson1(A);
			break;
		case 2: lesson2(A);
			break;
        case 3: lesson3(A);
			break;
        case 4: lesson4(A);
			break;
        case 5: lesson5(A);
			break;
        case 6: lesson6(A);
			break;
		default: intro();
	}
}

void lesson1(Profile P)
{
		char c;

		string A[8]={"jasd jasd ksdf ksdf0fjkl fjkl dkl; dkl;","laks laks jd;f jd;f0sjal sjal akf; akf;","All academic acacias accelerated,0Alfred adduced.","Fluttered flyers flush as freakish0flirts fluster flyers.","Dedicated Dave did delusive deeds0daily.","Khaki karate Karl krafts kerchiefs0kraftly.","Lairds lammed laggards as laggards0lammed lairds.","Silly Sara screeches as she sells0scarlet scarves."};

		Text T(8,A);


	system("cls");
	layout();
	Fingers F;
	F.print();
	gotoxy(78, 10);
	setColor(red,black);
	cout << "LESSON 1";
	gotoxy(71, 12);
	setColor(lightred,black);
	cout << "Focus on Home Row";

	for(int i=0;i<8;i++){

		gotoxy(47, 14);
		setColor(magenta,black);
		cout << "Type Accordingly Looking at your Screen with the help of Fingers Simulator";

		T.Print(i);

		gotoxy(2,3);
		cout << " ";

		T.Input(i,F,P);

		system("cls");

		layout();
		F.print();

	}
			system("cls");
			layout();

			congrats(1);

			gotoxy(70,30);
			setColor(white,black);
			cout << "Press ENTER to continue";
			gotoxy(81,31);
			cout << "or";
			gotoxy(60,32);
			cout << "Or Press ESC to return to main menu ";
			int f=getch();
			while(!(f==13||f==27))
				f=getch();
			if(f==27)
            {
                updateProfile(P.getName(),P.getLocation(),0);
                intro();
            }
			else
				lesson2(P);
}

void lesson2(Profile P)
{
		char c;

		string A[13]={"ff gg jj hh rr vv uu0mm tt ff bb yy nn hh","frfv frfv ftfb ftfb0jujm jujm jyjn jyjn","frft frft jujy jujy0fvfb fvfb jmjn jmjn","Uplifted Ulysses ululates as Ursula0uses usual ukase.","Tall, tact, testy, tetchy, thrifty0Teddy is a teacher.","Yeah, yeah, the yearly Yuletide is0yes, yelled Yajar.","Raffish racing Russ raised red0radical radial radishes.","Uplifted Ulysses ululates as Ursula0uses usual ukase.","Great greyish gadflies gashed gauche0giddy gulls.","Hefty Hermes hugged healthy hasty0Harriet heartly.","Virgil values valueless vans,0Vera values varied vases.","Madagascar mackerel mash makes0a mermaid a meal.""Brigitte believes black beans beats0baked beans in Britian."};

		Text T(13,A);


	system("cls");
	layout();
	Fingers F;
	F.print();
	gotoxy(78, 10);
	setColor(red,black);
	cout << "LESSON 2";
	gotoxy(71, 12);
	setColor(lightred,black);
	cout << "Focus on Index Fingers Keys";

	for(int i=0;i<13;i++){

		gotoxy(47, 14);
		setColor(magenta,black);
		cout << "Type Accordingly Looking at your Screen with the help of Fingers Simulator";

		T.Print(i);

		gotoxy(2,3);
		cout << " ";

		T.Input(i,F,P);

		system("cls");

		layout();
		F.print();

	}
			system("cls");
			layout();

			congrats(2);

			gotoxy(70,30);
			setColor(white,black);
			cout << "Press ENTER to continue";
			gotoxy(81,31);
			cout << "or";
			gotoxy(60,32);
			cout << "Or Press ESC to return to main menu ";
			int f=getch();
			while(!(f==13||f==27))
				f=getch();
			if(f==27)
			{
                updateProfile(P.getName(),P.getLocation(),0);
				intro();
			}
			else
				lesson3(P);
}

void lesson3(Profile P)
{
		char c;

		string A[11]={"dedc dedc kik, kik,0cded cded ,kik ,kik","i,kI ik,I deki deki0dck, dck, kidc kidc","kedi kedi d,kc d,kc0iked iked cd,k cd,k","Edith esteems early Easter effaces0Easter Eire.","Idle idealist Ida idles idly as ideal0icicle idyll irks Ida.","Eight eager ecstatic eerie eagles0eat earth eclectically.","Irregular illumination irks irate0Irish idealistic idols.","Emaciated Esther estimed elegies,0Ellis elucidates.","Ivan irrited Issac as Ivan illustrated0illusive images.","Each Easter eccentric Elsa eagle eats0edam eagerly.","Ill fated itchy Iris imitated immature0Isaac."};

		Text T(11,A);


	system("cls");
	layout();
	Fingers F;
	F.print();
	gotoxy(78, 10);
	setColor(red,black);
	cout << "LESSON 3";
	gotoxy(71, 12);
	setColor(lightred,black);
	cout << "Focus on Middle Fingers Keys";

	for(int i=0;i<11;i++){

		gotoxy(47, 14);
		setColor(magenta,black);
		cout << "Type Accordingly Looking at your Screen with the help of Fingers Simulator";

		T.Print(i);

		gotoxy(2,3);
		cout << " ";

		T.Input(i,F,P);

		system("cls");

		layout();
		F.print();

	}
			system("cls");
			layout();

			congrats(3);

			gotoxy(70,30);
			setColor(white,black);
			cout << "Press ENTER to continue";
			gotoxy(81,31);
			cout << "or";
			gotoxy(60,32);
			cout << "Or Press ESC to return to main menu ";
			int f=getch();
			while(!(f==13||f==27))
				f=getch();
			if(f==27)
			{
                updateProfile(P.getName(),P.getLocation(),0);
				intro();
			}
			else
				lesson4(P);
}

void lesson4(Profile P)
{
		char c;

		string A[11]={"swsx swsx lol. lol.0xsws xsws wssx wssx","ol.o ol.o swlo swlo0sxl. sxl. losx losx","l.sw l.sw lwso lwso0s.lx s.lx ol.x ol.x","Walter wore Wellingtons on wearisome0wanderings.","Oddy, Olivia offerd others oats0and onions.","Willoughby and Wordsworth wished0Windsor well.","Ostentations, outer outrider outraged0Orangemen.","While Walt washed weft, Willma0whitewashed walls.","Xioping xeroxed a photo of a xenophobic0Xhossa.","X chromosomes exist exclusively0in human cells.","Xiphophylous, xenopteri, and xylosis0mean nothing."};

		Text T(11,A);


	system("cls");
	layout();
	Fingers F;
	F.print();
	gotoxy(78, 10);
	setColor(red,black);
	cout << "LESSON 4";
	gotoxy(71, 12);
	setColor(lightred,black);
	cout << "Focus on Ring Fingers Keys";

	for(int i=0;i<11;i++){

		gotoxy(47, 14);
		setColor(magenta,black);
		cout << "Type Accordingly Looking at your Screen with the help of Fingers Simulator";

		T.Print(i);

		gotoxy(2,3);
		cout << " ";

		T.Input(i,F,P);

		system("cls");

		layout();
		F.print();

	}
			system("cls");
			layout();

			congrats(4);

			gotoxy(70,30);
			setColor(white,black);
			cout << "Press ENTER to continue";
			gotoxy(81,31);
			cout << "or";
			gotoxy(60,32);
			cout << "Or Press ESC to return to main menu ";
			int f=getch();
			while(!(f==13||f==27))
				f=getch();
			if(f==27)
			{
                updateProfile(P.getName(),P.getLocation(),0);
				intro();
			}
			else
				lesson5(P);
}

void lesson5(Profile P)
{
		char c;

		string A[10]={"aqaz aqaz ;p;/ ;p;/0qaqz qaqz pap? pap?","aqp? aqp? p/aq p/aq0\az; \az; ;paz ;paz","/;aq /;aq z/;a z/;a0qap; qap; q/;z q/;z","Quiet quails quit quarlet quite0quickly.","Paul Phillips participated in0party politics.","Queen questioned and quashed0qualified qualms.","Pauline plays the piano and Patrick0paints paintings.","Zoological zone in Zurish has zero0zebras.","Zanies of Zaragoza have zest0for zips.","Zealous Zorro loves to eat zucchini0and zabaglione."};
		Text T(10,A);


	system("cls");
	layout();
	Fingers F;
	F.print();
	gotoxy(78, 10);
	setColor(red,black);
	cout << "LESSON 5";
	gotoxy(71, 12);
	setColor(lightred,black);
	cout << "Focus on Ring Fingers Keys";

	for(int i=0;i<10;i++){

		gotoxy(47, 14);
		setColor(magenta,black);
		cout << "Type Accordingly Looking at your Screen with the help of Fingers Simulator";

		T.Print(i);

		gotoxy(2,3);
		cout << " ";

		T.Input(i,F,P);

		system("cls");

		layout();
		F.print();

	}
			system("cls");
			layout();

			congrats(5);

			gotoxy(70,30);
			setColor(white,black);
			cout << "Press ENTER to continue";
			gotoxy(81,31);
			cout << "or";
			gotoxy(60,32);
			cout << "Or Press ESC to return to main menu ";
			int f=getch();
			while(!(f==13||f==27))
				f=getch();
			if(f==27)
			{
                updateProfile(P.getName(),P.getLocation(),0);
				intro();
			}
			else
				lesson6(P);
}

void lesson6(Profile P)
{
		char c;

		string A[3]={"An Astronaut (from the Greek astron-meaning star, and nautes- meaning sailor) is a0person trained, equipped, and deployed by a human spaceflight program to serve as0a commander or crew member aboard a spacecraft. Although generally reserved for0professional space travelers, the terms are sometimes applied to anyone who travels0into space, including scientists, politicians, journalists and tourists.","A short story is a piece of prose fiction that typically can be read in one sitting0and focuses on a self-contained incident or series of linked incidents, with the0Internet of evoking a single effect or mood. The short story is one of the oldest types0of literature and has existed in the form of legends, mythic tales, folk tales, fairy0tales, fables and anecdotes in various ancient communities around the world.0The modern short story developed in the early 19th century.","Karate is a martial art developed in the Ryukyu Kingdom. It developed from the0indigenous Ryukyuan martial arts under the influence of Chinese martial arts,0particularly Fujian White Crane. Karate is now predominantly a striking art using0punching, kicking, knee strikes, elbow strikes and open-hand techniques such as0knife-hands, spear-hands and palm-heel strikes. Historically, and in some modern0styles, grappling, throws, joint locks, restraints and vital-point strikes are also0taught. A karate practitioner is called a karateka."};
		Text T(3,A);



	system("cls");
	layout();
	Fingers F;
	F.print();
	gotoxy(78, 7);
	setColor(red,black);
	cout << "LESSON 6";
	gotoxy(74, 9);
	setColor(lightred,black);
	cout << "Practice Paragraph";

	for(int i=0;i<3;i++){

		gotoxy(47, 11);
		setColor(magenta,black);
		cout << "Type Accordingly Looking at your Screen with the help of Fingers Simulator";

		T.Print(i,0);

		gotoxy(2,3);
		cout << " ";

		T.Input(i,F,P,45,22);

		system("cls");

		layout();
		F.print();

	}
			system("cls");
			layout();

			congrats(6);

			gotoxy(70,30);
			setColor(white,black);
			cout << "Press ENTER to continue";
			gotoxy(81,31);
			cout << "or";
			gotoxy(60,32);
			cout << "Or Press ESC to return to main menu ";
			int f=getch();
			while(!(f==13||f==27))
				f=getch();
			if(f==27)
			{
                updateProfile(P.getName(),P.getLocation(),0);
				intro();
			}
			else
				test();
}


                        //  file handling

void profiles()
{

    system("cls");
	layout();

	Profile P[5];
	string A;
	int a;

	ifstream file("file.txt");

	if(file.is_open())
        {
            for(int i=0; getline(file,A) && i<2; i++);
            P[0].setName(A);
            P[0].setLocation(2);
            for(int j=1;j<5;j++)
            {
                getline(file,A);
                P[j].setName(A);
                P[j].setLocation(2+j);
            }
            for(int j=0;j<5;j++)
            {
                file >> a;
				P[j].setlevel(a);
            }
        }

    file.close();
	a=0;

	gotoxy(73,12);
	setColor(green,black);
	cout << "LEARN TYPING";
	gotoxy(68,15);
	setColor(blue,black);
	cout << "Open Existing Profiles";

	setColor(magenta,black);
	for(int i=0;i<5;i++){
		gotoxy(70,17+i);
		cout << i+1 << ")" << P[i].getName();
	}

	gotoxy(68,23);
	setColor(blue,black);
	cout << "or";
	gotoxy(70,25);
	setColor(magenta,black);
	cout << "6) Create a new Profile";
	gotoxy(70,28);
	setColor(cyan,black);
	cout << "7) Back to Main Menu";

	gotoxy(2,41);
	cout << " ";

	gotoxy(68,30);
	setColor(white,black);
	cout << "Enter Choice: ";
	cin >> a;

		while(a<1 || a>7){
			Beep(2000,300);
			gotoxy(91,30);
			cout << "\b ";
			gotoxy(70,30);
			cout << "Enter valid Level:  ";
			cin >> a;
		}

	switch(a){
		case 1: openlessons(P[0].getLevel(),P[0]);
			break;
		case 2: openlessons(P[1].getLevel(),P[1]);
			break;
        case 3: openlessons(P[2].getLevel(),P[2]);
			break;
        case 4: openlessons(P[3].getLevel(),P[3]);
			break;
        case 5: openlessons(P[4].getLevel(),P[4]);
			break;
        case 6: createNew();
			break;
        case 7: intro();
			break;
		default: intro();
	}
}



void createNew()
{
    string n;

    setColor(green,black);
    gotoxy(100,18);
    cout << "------------------------------------------";
    gotoxy(100,19);
    cout << "|";
    gotoxy(100,20);
    cout << "|";
    gotoxy(100,21);
    cout << "|";
    gotoxy(100,22);
    cout << "------------------------------------------";
    gotoxy(141,19);
    	cout << "|";
   	gotoxy(141,20);
    	cout << "|";
    gotoxy(141,21);
    cout << "|";
    setColor(white,black);
    gotoxy(103,20);
    cout << "Enter Name: ";
    cin >> n;

    updateProfile(n,1,0);

    profiles();

}

void updateProfile(string a, int b, int c)
{
    stringstream ss;
    ss << b;

    string file[12];

    ifstream Get("file.txt");

        if(Get.is_open())
        {
            for(int i=0;i<12;i++){
                getline(Get,file[i]);
            }
        }
    Get.close();

    if(c==0)
    {
        file[b]=a;
        ss >> file[b+5];
    }
    else
    {
        stringstream cc;
        cc << c;
        cc >> file[0];
        file[1]=a;
    }

    ofstream Put("file.txt");

        if(Put.is_open())
        {
            for(int i=0;i<12;i++){
                Put << file[i] << endl;
            }
        }
    Put.close();
}
                                    //  all tests
void test()
{
	system("cls");
	layout();


		int a;
	gotoxy(73,15);
	setColor(red,black);
	cout << "TYPING TEST";
	gotoxy(70,18);
	setColor(green,black);
	cout << "1) Easy";
	gotoxy(70,19);
	cout << "2) Medium";
	gotoxy(70,20);
	cout << "3) Hard";

	gotoxy(2,41);
	cout << " ";

	gotoxy(70,22);
	setColor(white,black);
	cout << "Enter Level: ";
	cin >> a;
	while(a<1 || a>3){
		Beep(2000,300);
		gotoxy(91,22);
		cout << "\b ";
		gotoxy(70,22);
		cout << "Enter valid Level:  ";
		cin >> a;
	}

	switch(a){
		case 1: test1();
			break;
		case 2: test2();
			break;
		case 3: test3();
			break;
		default: test2();
	}

}

void test1()
{
		 string t;
		 ifstream file("1.txt");

        if(file.is_open())
        	for(int i=0; getline(file,t) && i<1; i++);

		Phrase P(t,'T');

		file.close();

	system("cls");
	layout();


	gotoxy(75, 7);
	setColor(red,black);
	cout << "Speed Test";
	gotoxy(72, 10);
	setColor(magenta,black);
	cout << "Type Accordingly";

	P.Print(0);

	gotoxy(2,41);
	cout << " ";

	int start=time(0);
	int c=P.Input();
   	int end=time(0);

	float d=c;
	float diff=(end-start)-2;

	system("cls");
	layout();

	Result R((end-start)-2,diff,diff/60,(247/5)/(diff/60),(d/247)*100,((247/5)/(diff/60))+((d/247)*100),c);
	R.Print();

	setColor(white,black);
	gotoxy(65,30);
	cout << "Press Enter to Return to Main Menu";
	gotoxy(79,31);
	cout << "or";
	gotoxy(72,32);
	cout << "Press ESC to Exit  ";

	int o=getch();

	while(!(o==13 || o==27)){
		o=getch();
	}

	if(o==13)
	  intro();
	else
	  exit(0);

}

void test2()
{
		string t;
		ifstream file("1.txt");

        if(file.is_open())
        	getline(file,t);

        Phrase P;
        P.setPhrase(t);

		file.close();

	system("cls");
	layout();

	gotoxy(75, 7);
	setColor(red,black);
	cout << "Speed Test";
	gotoxy(72, 10);
	setColor(magenta,black);
	cout << "Type Accordingly";

	P.Print(0);

	gotoxy(2,41);
	cout << " ";

	int start=time(0);
	int c=P.Input();
   	int end=time(0);

	float d=c;
	float diff=(end-start)-2;

	system("cls");
	layout();

	Result R((end-start)-2,diff,diff/60,(247/5)/(diff/60),(d/247)*100,((247/5)/(diff/60))+((d/247)*100),c);
	R.Print();

	setColor(white,black);
	gotoxy(65,30);
	cout << "Press Enter to Return to Main Menu";
	gotoxy(79,31);
	cout << "or";
	gotoxy(72,32);
	cout << "Press ESC to Exit  ";

	int o=getch();

	while(!(o==13 || o==27)){
		o=getch();
	}

	if(o==13)
	  intro();
	else
	  exit(0);

}


void test3()
{
		string t;
		 ifstream file("1.txt");

        if(file.is_open())
        	for(int i=0; getline(file,t) && i<2; i++);

		Phrase P(t,'L');

		file.close();


	system("cls");
	layout();

	gotoxy(75, 7);
	setColor(red,black);
	cout << "Speed Test";
	gotoxy(72, 10);
	setColor(magenta,black);
	cout << "Type Accordingly";

	P.Print(0);

	gotoxy(2,41);
	cout << " ";

	Sleep(5000);
	int start=time(0);
	int c=P.Input();
   	int end=time(0);

	float d=c;
	float diff=(end-start)-2;

	system("cls");
	layout();

	Result R((end-start)-2,diff,diff/60,(247/5)/(diff/60),(d/247)*100,((247/5)/(diff/60))+((d/247)*100),c);
	R.Print();

	setColor(white,black);
	gotoxy(65,30);
	cout << "Press Enter to Return to Main Menu";
	gotoxy(79,31);
	cout << "or";
	gotoxy(72,32);
	cout << "Press ESC to Exit  ";

	int o=getch();

	while(!(o==13 || o==27)){
		o=getch();
	}

	if(o==13)
	  intro();
	else
	  exit(0);

}

                                //  Game functions
void game()
{
    system("cls");
    gotoxy(0,46);
    int x=7, y=6;
	setColor(gray,black);
	gotoxy(x,y);
	for(int i=1;i<=154;i++){
		cout << "-";
	}

	gotoxy(x,43);
	for(int i=1;i<=154;i++){
		cout << "-";
	}

	char choice;

    setColor(red,black);
    gotoxy(74,18);
	cout << " AeroType Game\n";
	gotoxy(70,22);
	setColor(lightblue,black);
	cout << "P) Play Game\n";
	gotoxy(70,24);
	cout << "I) Instructions\n";
	gotoxy(70,26);
	cout << "E) Main Menu\n";
	setColor(white,black);
	gotoxy(70,30);
	cout << "Enter choice : ";
	cin >> choice;
	while(!(choice=='P' || choice=='I' || choice=='p' || choice=='i' || choice=='e' || choice=='E')){
        Beep(4000,100);
        gotoxy(85,30);
        cout << " ";
        gotoxy(85,30);
        cin >> choice;
	}

    switch(choice){

        case 'p': play();
            break;
        case 'P': play();
            break;
        case 'i': instructions();
            break;
        case 'I': instructions();
            break;
        case 'e': intro();
            break;
        case 'E':
            break;

        default: cout << "Run the Program again\n";
    }
}

int CheckKeyPressed(int waitTime)
{
	HANDLE h= GetStdHandle(STD_INPUT_HANDLE);
	INPUT_RECORD r;
	DWORD w = 1;
	DWORD eventss;
	DWORD waitResult=0;
	int keypressed = false;
	int toReturn = 0;

	waitResult = WaitForSingleObject(h,waitTime);

	if (waitResult == WAIT_OBJECT_0)
	{
		//FlushConsoleInputBuffer(h);..commented out as this takes to asynchronous mode on some systems
		keypressed = ReadConsoleInput(h,&r,1,&eventss);

		if (keypressed && r.EventType==KEY_EVENT && r.Event.KeyEvent.bKeyDown)
			toReturn = r.Event.KeyEvent.wVirtualKeyCode;
		//this should make sure that checkKeyPressed is not called twice for arrow keys
		if (toReturn == 224)
			toReturn = CheckKeyPressed(waitTime);


		FlushConsoleInputBuffer(h);
	}

//	if(toReturn>64 && toReturn<91)
 //       return toReturn;
 //   else
	return toReturn+32;
}

void instructions()
{
    system("cls");
    gotoxy(7,6);
	for(int i=1;i<=154;i++){
		cout << "-";
	}

	gotoxy(7,43);
	for(int i=1;i<=154;i++){
		cout << "-";
	}

	setColor(red,black);
    gotoxy(80,12);
    cout << "AEROTYPE GAME";
    gotoxy(48,18);
    setColor(lightblue,black);
    cout << "This is a typing game made to learn typing and enhance typing speed while having fun";
    gotoxy(67,21);
    cout << "User has 3 Planes with unlimited missiles";
    gotoxy(50,22);
    cout << "User need to destroy the enemy aircrafts through firing missiles by typing correctly";
    gotoxy(56,23);
    cout << "the word on it before it hits the planes. If user types any wrong letter";
    gotoxy(70,24);
    cout << "User have to type all the word again";
    gotoxy(5,46);
    cout << " ";
    gotoxy(70,30);
    setColor(white,black);
    cout << "Press ESC to go back to Game Menu: ";
    int a=getch();
    while(a!=27){
        a=getch();
    }
    system("cls");
    game();
}

void play()
{
    system("cls");
    srand(time(0));

        int count=3;
        int index=0;
        int score=0;
        int t=143;

        char str;
        int status[3]={1,1,1};
        string a[35]={"pakistan","ukraine","uganda","balaruse","koraisia","islamabad","peshawar","munna","barbie","cuttings","oven","cord","gloom","lineage","crime","sodium","village","costume","platform","reputation","brilliance","diplomat","tempt","infrastructure","flourish","deprivation","patience","merchant","attractive","kinship","inappropriate","allocation","contradiction","deficiency","owl"};


    layoutPlane();

    Plane P1(10,11,1);
    Plane P2(10,21,1);
    Plane P3(10,31,1);

	while(1){

        int x=118, y=rand()%30+10, z=rand()%34+0, w=rand()%85+10;
        int v=a[z].size();

    setColor(white,black);
    P1.drawPlane(11);
    P2.drawPlane(21);
    P3.drawPlane(31);

    gotoxy(2,46);
    cout << " ";

		for(int i=0;i<113;i++){

            setColor(green,black);
            gotoxy(154,25);
            cout << count;

            if(count==0)
            {
                system("cls");
                game();
            }

			gotoxy(x+v-i,y);
			cout << " ";
			gotoxy(x-i,y);
			setColor(magenta,black);
			cout << a[z];
			Sleep(w);
			gotoxy(x+v-i,y);
			cout << " ";

			if(i==112)
			{
				gotoxy(6,y);
                for(int q=0;q<v+2;q++){
                    cout << " ";
                }
			}

			if((y==11||y==21||y==31) && i==103 && status[y/10-1]==1)
			{
                if(y==11)
                {
                    erase(13,y,v+2);
                    P1.destroyPlane();
                    status[0]=0;
                    PlaySound(TEXT("exp.wav"),NULL,SND_SYNC);
                    count--;
                }
                else if(y==21)
                {
                    erase(13,y,v+2);
                    P2.destroyPlane();
                    status[1]=0;
                    PlaySound(TEXT("exp.wav"),NULL,SND_SYNC);
                    count--;
                }
                else if(y==31)
                {
                    erase(13,y,v+2);
                    P3.destroyPlane();
                    status[2]=0;
                    PlaySound(TEXT("exp.wav"),NULL,SND_SYNC);
                    count--;
                }

				break;
            }
            else if((y==19||y==29||y==39) && i==103 && status[y/10-1]==1)
            {
				 if(y==19)
                 {
                     erase(13,y,v+2);
                     P1.destroyPlane();
                     status[0]=0;
                     PlaySound(TEXT("exp.wav"),NULL,SND_SYNC);
                    count--;
                 }
                 else if(y==29)
                 {
                     erase(13,y,v+2);
                     P2.destroyPlane();
                     status[1]=0;
                     PlaySound(TEXT("exp.wav"),NULL,SND_SYNC);
                    count--;
                 }
                 else if(y==39)
                 {
                     erase(13,y,v+2);
                     P3.destroyPlane();
                     status[2]=0;
                     PlaySound(TEXT("exp.wav"),NULL,SND_SYNC);
                     count--;
                 }

                    break;

			  }
              else if((y==12||y==22||y==32) && i==101 && status[y/10-1]==1)
			  {
				  if(y==12)
                  {
                      erase(15,y,v+2);
                      P1.destroyPlane();
                      status[0]=0;
                      PlaySound(TEXT("exp.wav"),NULL,SND_SYNC);
                      count--;
                  }
                  else if(y==22)
                  {
                      erase(15,y,v+2);
                      P2.destroyPlane();
                      status[1]=0;
                      PlaySound(TEXT("exp.wav"),NULL,SND_SYNC);
                      count--;
                  }
                  else if(y==32)
                  {
                        erase(15,y,v+2);
                        P3.destroyPlane();
                        status[2]=0;
                        PlaySound(TEXT("exp.wav"),NULL,SND_SYNC);
                        count--;
                  }

				    break;
			   }
			   else if((y==18||y==28||y==38) && i==101 && status[y/10-1]==1)
			   {
                    if(y==18)
                    {
                            erase(15,y,v+2);
                            P1.destroyPlane();
                            status[0]=0;
                            PlaySound(TEXT("exp.wav"),NULL,SND_SYNC);
                            count--;
                    }
                    else if(y==28)
                    {
                            erase(15,y,v+2);
                            P2.destroyPlane();
                            status[1]=0;
                            PlaySound(TEXT("exp.wav"),NULL,SND_SYNC);
                            count--;
                    }
                    else if(y==38)
                    {
                            erase(15,y,v+2);
                            P3.destroyPlane();
                            status[2]=0;
                            PlaySound(TEXT("exp.wav"),NULL,SND_SYNC);
                            count--;
                    }

                      break;
			    }
			    else if((y==13||y==23||y==33) && i==99 && status[y/10-1]==1)
			    {
                     if(y==13)
                     {
                         erase(17,y,v+2);
                         P1.destroyPlane();
                         status[0]=0;
                         PlaySound(TEXT("exp.wav"),NULL,SND_SYNC);
                         count--;
                     }
                     else if(y==23)
                     {
                            erase(17,y,v+2);
                            P2.destroyPlane();
                            status[1]=0;
                            PlaySound(TEXT("exp.wav"),NULL,SND_SYNC);
                            count--;
                     }
                     else if(y==33)
                     {
                            erase(17,y,v+2);
                            P3.destroyPlane();
                            status[2]=0;
                            PlaySound(TEXT("exp.wav"),NULL,SND_SYNC);
                            count--;
                     }

                        break;
                 }
                else if((y==17||y==27||y==37) && i==99 && status[y/10-1]==1)
                {
                     if(y==17)
                     {
                            erase(17,y,v+2);
                            P1.destroyPlane();
                            status[0]=0;
                            PlaySound(TEXT("exp.wav"),NULL,SND_SYNC);
                            count--;
                     }
                     else if(y==27)
                     {
                            erase(17,y,v+2);
                            P2.destroyPlane();
                            status[1]=0;
                            PlaySound(TEXT("exp.wav"),NULL,SND_SYNC);
                            count--;
                     }
                     else if(y==37)
                     {
                            erase(17,y,v+2);
                            P3.destroyPlane();
                            status[2]=0;
                            PlaySound(TEXT("exp.wav"),NULL,SND_SYNC);
                            count--;
                     }

                        break;
                }
                else if((y==14||y==24||y==34) && i==96 && status[y/10-1]==1)
                {
                      if(y==14)
                      {
                            P1.destroyPlane();
                            status[0]=0;
                            PlaySound(TEXT("exp.wav"),NULL,SND_SYNC);
                            count--;
                      }
                      else if(y==24)
                      {
                            erase(20,y,v+2);
                            P2.destroyPlane();
                            status[1]=0;
                            PlaySound(TEXT("exp.wav"),NULL,SND_SYNC);
                            count--;
                      }
                      else if(y==34)
                      {
                            erase(20,y,v+2);
                            P3.destroyPlane();
                            status[2]=0;
                            PlaySound(TEXT("exp.wav"),NULL,SND_SYNC);
                            count--;
                      }

                       break;
                }
                else if((y==16||y==26||y==36) && i==96 && status[y/10-1]==1)
                {
                      if(y==16)
                      {
                            erase(20,y,v+2);
                            P1.destroyPlane();
                            status[0]=0;
                            PlaySound(TEXT("exp.wav"),NULL,SND_SYNC);
                            count--;
                      }
                      else if(y==26)
                      {
                            erase(20,y,v+2);
                            P2.destroyPlane();
                            status[1]=0;
                            PlaySound(TEXT("exp.wav"),NULL,SND_SYNC);
                            count--;
                      }
                      else if(y==36)
                      {
                            erase(20,y,v+2);
                            P3.destroyPlane();
                            status[2]=0;
                            PlaySound(TEXT("exp.wav"),NULL,SND_SYNC);
                            count--;
                      }

                        break;
                 }
                else if((y==15||y==25||y==35) && i==92 && status[y/10-1]==1)
                {
                    if(y==15)
                    {
                        erase(25,y,v+2);
                        P1.destroyPlane();
                        status[0]=0;
                        PlaySound(TEXT("exp.wav"),NULL,SND_SYNC);
                        count--;
                    }
                    else if(y==25)
                    {
                        erase(20,y,v+2);
                        P2.destroyPlane();
                        status[1]=0;
                        PlaySound(TEXT("exp.wav"),NULL,SND_SYNC);
                        count--;
                    }
                    else if(y==35)
                    {
                        erase(20,y,v+2);
                        P3.destroyPlane();
                        status[2]=0;
                        PlaySound(TEXT("exp.wav"),NULL,SND_SYNC);
                        count--;
                    }

                  break;

                }

            str=CheckKeyPressed(10);

            if(str-32==27)
            {
                system("cls");
                game();
            }

            if(str==a[z][index])
            {
                gotoxy(t++,15);
                setColor(green,black);
                cout << str;
                index++;
            }
            else if(str>='a' && str<='z' && str!=a[z][index])
            {
                t=143;
                gotoxy(t,15);
                for(int q=0;q<v+2;q++){
                    cout << " ";
                }
                Beep(4000,100);
                index=0;
            }
            if(index==v)
            {

                gotoxy(x-i,y);
                for(int q=0;q<v+2;q++){
                    cout << " ";
                }

                if((y>10 && y<20) && status[y/10-1]==1){
                    gotoxy(x-i,y);
                    score++;
                    P1.fire(x-i-v,y);
                }

                else if((y>20 && y<30) && status[y/10-1]==1){
                    gotoxy(x-i,y);
                    score++;
                    P2.fire(x-i-v,y);
                }
                else if((y>30 && y<40) && status[y/10-1]==1){
                    gotoxy(x-i,y);
                    score++;
                    P3.fire(x-i-v,y);
                }
                else
                {
                    gotoxy(x-i,y);
                    for(int q=0;q<v+2;q++){
                        cout << " ";
                    }
                    PlaySound(TEXT("1.wav"),NULL,SND_SYNC);
                }
              break;
            }
   		}

   		index=0;
   		gotoxy(143,20);
        cout << score;
        gotoxy(142,15);
        for(int q=0;q<15;q++){
            cout << " ";
        }
        t=143;
    }

return;
}

void view()
{
    system("cls");
    layout();
    string H;
    char c;

    ifstream V("file.txt");

        if(V.is_open())
        {
            getline(V,H);
            gotoxy(68,16);
            setColor(green,black);
            cout << "Highest Score is " << H << " made by ";
            getline(V,H);
            cout << H;
        }
    V.close();

        gotoxy(72,27);
        setColor(white,black);
        cout << "Press ESC to go to Main Menu";
        c=getch();
        while(c!=27){
            c=getch();
        }
        intro();
}

void intro()
{
	  char c;
	system("cls");
	layout();
	setColor(magenta,black);
    gotoxy(75, 10);
	cout << "Welcome to";
	setColor(red,black);
	gotoxy(71, 12);
	cout << "FAST Typing Tutor!";
	setColor(magenta,black);
	gotoxy(36, 17);
	cout << "Speed up your learning progress with FAST Typing Tutor and develop valuable keyboarding skills\n";
    setColor(lightblue,black);

	gotoxy(68,25);
	cout << "L) Learn Typing";
	gotoxy(68,26);
	cout << "T) Test Typing Speed";
	gotoxy(68,27);
	cout << "H) View High Score";
	gotoxy(68,28);
	cout << "G) Typing Games";
	gotoxy(68,29);
	cout << "E) Exit";
	gotoxy(2,41);
	cout << " ";
	gotoxy(68,31);
	cout << "Choose any option to Get Started :";
	cin >> c;


	while(!((c=='T'||c=='t')||(c=='L'||c=='l')||(c=='H'||c=='h')||(c=='E'||c=='e')||(c=='G'||c=='g'))){
		gotoxy(68, 33);
		Beep(2000,300);
		cout << "Enter valid Choice";
		gotoxy(68, 34);
		cout << "Enter Again :  \b";
		cin >> c;
	}

	switch(c){
		case 'L': profiles();
		break;
		case 'l': profiles();
		break;
		case 'T': test();
		break;
		case 't': test();
		break;
		case 'H': view();
		break;
		case 'h': view();
		break;
		case 'G': game();
		break;
		case 'g': game();
		break;
		case 'E': exit(0);
		break;
		case 'e': exit(0);
	  default : cout << "Run the program Again";Sleep(2000);exit(0);

	}


}

int main()
{
    Sleep(2000);
	intro();
	return 0;
}


