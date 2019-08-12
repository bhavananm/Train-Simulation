// #include<windows.h>
#include<stdio.h>
#include<math.h>
#include<GL/glut.h>
#define PI 3.14
float counter = 600.0;
GLfloat angle,xx=1.0;
GLint i,theta=0,x=0,y=0;
float x_pos = 50;
int state = 1;
GLint win_1=0, win_2=0, win_3=0;
void sky()
{
	
	glBegin(GL_QUADS);
	glPushMatrix();
	glColor3f(1, 1, 1);
	glVertex2f(-1300, 400);
	glVertex2f(1300, 400);
	glColor3f(0, 1, 1);
	glVertex2f(1300, 350);
	glVertex2f(-1300, 350);
	glVertex2f(-1300, 200);
    glVertex2f(1300, 200);
	glVertex2f(1300, 350);
	glVertex2f(-1300, 350);
	glColor3f(0.7, 0.9, 0);
	glVertex2f(-1300, 200);
	glVertex2f(1300, 200);
	glColor3f(0.6, 0.8, 0.196078);
	glVertex2f(1300, 150);
	glVertex2f(-1300, 150);
	glPopMatrix();
	glEnd();
	glFlush();

}
void sky1()
{
	//Sky
	glBegin(GL_QUADS);
	glPushMatrix();
	glColor3f(0.0, 0.0, 0.61);
	glVertex2f(-1000, 150);
	glVertex2f(1000, 150);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(-1000, 400);
	glVertex2f(1000, 400);
	glPopMatrix();
	glEnd();
	glFlush();
	//star();
	glBegin(GL_POINTS);
	glPointSize(1.0);
	glColor3f(1, 1, 1);
	for (int i = 0; i < 50; i++)
		glVertex2f(rand() % 700, rand() % 700);
	   for (int j = 0; j < 10; j++);
	
	glEnd();
	glFlush();
	glutPostRedisplay();
}
void road()
{
	glColor3f(0.7, 0.7, 0.7);
	glBegin(GL_QUADS);
	glPushMatrix();
	glVertex2f(-1000, 0);
	glVertex2f(1000, 0);
	glVertex2f(-1000, 150);
	glVertex2f(1000, 150);
	glPopMatrix();
	glEnd();
	glFlush();
}
void head()//engine head main bogie
{
	glColor3f(0.3, 0.2, 0.0);

	glLineWidth(5.0f);
	glBegin(GL_LINES);//engine head
	glPushMatrix();
	glVertex2f(x_pos+47, 250);//47
	glVertex2f(x_pos+102, 250);//102
	glPopMatrix();
	glEnd();
	glFlush();
}
void window1(int x)
{
	glColor3f(0.3, 0.1, 0.8);
	
	glBegin(GL_QUADS);
	glPushMatrix();
    glVertex2f(110+x, 190);
	glVertex2f(140+x, 190);
	glVertex2f(140+x, 230);
	glVertex2f(110+x, 230);
	glPopMatrix();
	glEnd();
	glFlush();
    glLineWidth(3);
	glColor3f(0, 0, 0);
    glBegin(GL_LINE_LOOP);
	glPushMatrix();
	glVertex2f(110+x, 190);
	glVertex2f(140+x, 190);
	glVertex2f(140+x, 230);
	glVertex2f(110+x, 230);
	glPopMatrix();
	glEnd();
	glFlush();
}
void line(int x)//track lines
{
	glLineWidth(7);
	glColor3f(0, 0, 0);
	glBegin(GL_LINES);
	glPushMatrix();
	glVertex2f(x+150,110);
	glVertex2f(x+160, 110);
	glPopMatrix();
	glEnd();
	glFlush();

}
void bogie(int x)
{
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glPushMatrix();
	//glTranslatef(-xx, 0, 0);//Added now
	glVertex2f(100+x, 100);
	glVertex2f(200+x, 100);
	glVertex2f(200+x, 250);
	glVertex2f(100+x, 250);
	glPopMatrix();
	glEnd();
    glFlush();
	glColor3f(0, 0, 0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(100 + x, 100);
	glVertex2f(200 + x, 100);
	glVertex2f(200 + x, 250);
	glVertex2f(100 + x, 250);
	glEnd();
	glFlush();
}
void circle(float x,float y,float r)
{
	glBegin(GL_TRIANGLE_FAN);
	glPushMatrix();
	for (angle = 0; angle <=180; angle += 0.1)
	{
		glVertex2f((x + r * cos(angle)), (y + r * sin(angle)));
	}
	glEnd();
	glFlush();
}
void track()
{
	glColor3f(0.3, 0.2, 0.0);
	glLineWidth(4);
	glBegin(GL_LINES);
	glPushMatrix();
	glVertex2f(0, 85);
	glVertex2f(1000, 85);
	glVertex2f(0, 113.5);
	glVertex2f(1000, 113.5);
	glPopMatrix();
	glEnd();
	glFlush();
}
void trackline(float x)
{
	glColor3f(0.3, 0.2, 0.0);
	glLineWidth(5);
	glBegin(GL_LINES);
	glPushMatrix();
	glVertex2f(5+x, 80);
	glVertex2f(15+x, 118.5);
	glPopMatrix();
	glEnd();
	glFlush();

}
void wire()
{
	glColor3f(0, 0, 0);
	glLineWidth(4);
	glBegin(GL_LINES);
	glPushMatrix();
	glVertex2f(0, 275);
	glVertex2f(1000, 275);
	glLineWidth(3);
	glVertex2f(x_pos+72, 250);
	glVertex2f(x_pos+82, 275);
	glPopMatrix();
	glEnd();
	glFlush();

}
void train(int x)
{
	sky();
	road();
	track();
	wire();
	for (i = -10; i <= 1300; i = i + 15)
	trackline(i);
	glPointSize(0.1);
	//glColor3f(0.9, 0.6, 1);
	glColor3f(0, 0, 1);
	glBegin(GL_QUADS);//engine left box
	glPushMatrix();
	glVertex2f(x_pos, 100);
	glVertex2f(x_pos+50, 100);
	glVertex2f(x_pos+50, 200);
	glVertex2f(x_pos, 200);
	glPopMatrix();
    glEnd();
	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	glPushMatrix();
	glVertex2f(x_pos, 100);
	glVertex2f(x_pos + 50, 100);
	glVertex2f(x_pos + 50, 200);
	glVertex2f(x_pos, 200);
	glPopMatrix();
	glEnd();
	glColor3f(0, 0, 0);
	glBegin(GL_LINES);
	glVertex2f(x_pos, 100);
	glVertex2f(x_pos,200);
	glVertex2f(x_pos + 100, 100);
	glVertex2f(x_pos + 100, 250);
	glEnd();
    //glColor3f(0.9, 0.6, 1);
	glColor3f(0, 0, 1);
	glBegin(GL_QUADS);//engine right box
	glPushMatrix();
	glVertex2f(x_pos+50, 100);
	glVertex2f(x_pos+100, 100);
	glVertex2f(x_pos+100, 250);
	glVertex2f(x_pos+50, 250);
	glPopMatrix();
    glEnd();
	glColor3f(0, 0, 0);
	glBegin(GL_LINES);//engine right box
	glPushMatrix();
	glVertex2f(x_pos + 50, 100);
	glVertex2f(x_pos + 100, 100);
	glVertex2f(x_pos + 100, 250);
	glVertex2f(x_pos + 50, 250);
	glPopMatrix();
	glEnd();
	glColor3f(0, 0, 0);
	glBegin(GL_LINES);
	glVertex2f(x_pos + 50, 200);
	glVertex2f(x_pos + 50, 250);
    head();
	window1(x_pos-50);//for engine
    bogie(x_pos+10);//bogie 1
	bogie(x_pos+120);//bogie 2
	window1(x_pos+12.5);//bogie 1 window 1
	window1(x_pos+57.5);//bogie 1 window 2
	window1(x_pos+122.5);//bogie 2 window 1
	window1(x_pos+167.5);//bogie 2 window 2
	line(x_pos-50);//connecting line 1
	line(x_pos+60);//connecting line 2
	circle(x_pos+25, 100, 15);//engine wheel 1
	circle(x_pos+75, 100, 15);//engine wheel 2
	circle(x_pos+125, 100, 15);//bogie 1 wheel 1
	circle(x_pos+160, 100, 15);//bogie 1 wheel 2
	circle(x_pos+195, 100, 15);//bogie 1 wheel 3
	circle(x_pos+235, 100, 15);//bogie 2 wheel 1 
	circle(x_pos+270, 100, 15);//bogie 2 wheel 2
    circle(x_pos+305, 100, 15);//bogie 2 wheel 3
}
void train1(int x)
{
	sky1();
	road();
	track();
	wire();
for (i = -10; i <= 1300; i = i + 15)
		trackline(i);
	glColor3f(0.9, 0.6, 1);
	glBegin(GL_QUADS);//engine left box
	glPushMatrix();
	glVertex2f(x_pos, 100);
	glVertex2f(x_pos + 50, 100);
	glVertex2f(x_pos + 50, 200);
	glVertex2f(x_pos, 200);
	glPopMatrix();
	glEnd();
    glColor3f(0.9, 0.6, 1);
	glBegin(GL_QUADS);//engine right box
	glPushMatrix();
	glVertex2f(x_pos + 50, 100);
	glVertex2f(x_pos + 100, 100);
	glVertex2f(x_pos + 100, 250);
	glVertex2f(x_pos + 50, 250);
	glPopMatrix();
	glEnd();
	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	glPushMatrix();
	glVertex2f(x_pos, 100);
	glVertex2f(x_pos + 50, 100);
	glVertex2f(x_pos + 50, 200);
	glVertex2f(x_pos, 200);
	glPopMatrix();
	glEnd();
	glColor3f(0, 0, 0);
	glBegin(GL_LINES);
	glVertex2f(x_pos, 100);
	glVertex2f(x_pos, 200);
	glVertex2f(x_pos + 100, 100);
	glVertex2f(x_pos + 100, 250);
	glEnd();
	glColor3f(0, 0, 0);
	glBegin(GL_LINES);
	glVertex2f(x_pos + 50, 200);
	glVertex2f(x_pos + 50, 250);
    head();
    window1(x_pos - 50);//for engine
    bogie(x_pos + 10);//bogie 1
    bogie(x_pos + 120);//bogie 2
    window1(x_pos + 12.5);//bogie 1 window 1
    window1(x_pos + 57.5);//bogie 1 window 2
    window1(x_pos + 122.5);//bogie 2 window 1
    window1(x_pos + 167.5);//bogie 2 window 2
	line(x_pos - 50);//connecting line 1
	line(x_pos + 60);//connecting line 2
    circle(x_pos + 25, 100, 15);//engine wheel 1
    circle(x_pos + 75, 100, 15);//engine wheel 2
	circle(x_pos + 125, 100, 15);//bogie 1 wheel 1
    circle(x_pos + 160, 100, 15);//bogie 1 wheel 2
	circle(x_pos + 195, 100, 15);//bogie 1 wheel 3
    circle(x_pos + 235, 100, 15);//bogie 2 wheel 1
    circle(x_pos + 270, 100, 15);//bogie 2 wheel 2
    circle(x_pos + 305, 100, 15);//bogie 2 wheel 3
}
void mouse(int btn, int state, int x, int y)
{
	if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(1.0, 1.0, 1.0, 1.0);
		glMatrixMode(GL_PROJECTION);
		glPushMatrix();
		glPointSize(3.0);
		train1(50);
		glMatrixMode(GL_MODELVIEW);
		glutSwapBuffers();
		glFlush();
		glutPostRedisplay();
	}
}
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glPointSize(3.0);
	train(50);
	glMatrixMode(GL_MODELVIEW);
	glutSwapBuffers();
}
void display2(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glPointSize(3.0);
	train1(50);
	glMatrixMode(GL_MODELVIEW);
	glutSwapBuffers();
}
void timer(int a)
{
	glutPostRedisplay();
	glutTimerFunc(1000 / 60, timer, 0);

		switch (state)
		{
		case 1:
			if (x_pos > 0)
			{
				x_pos -= 1.0;
			}
			else
				state = -1;
			break;
		case -1: if (x_pos <= 0)
		{  
			x_pos = 350;
 			x_pos -= 1.0;
		}
		   else
			state = 1;
			break;
		}
}
void timer1(int b)
{
	glutPostRedisplay();
	glutTimerFunc(1000 / 30, timer1, 0);

	switch (state)
	{
	case 1:
		if (x_pos > 0)
		{
			x_pos -= 0.5;
		}
		else
			state = -1;
		break;
	case -1: if (x_pos <= 0)
	{
		x_pos = 350;
		x_pos -= 0.5;
	}
			 else
		state = 1;
		break;
	}
}
void output(int x, int y, float r, float g, float b, char *string)
{
	glColor3f(r, g, b);
	glRasterPos2f(x, y);
	int len, i;
	len = (int)strlen(string);
	for (i = 0; i < len; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string[i]);
	}

}
void display1()
{
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	output(450, 1200, 1, 0, 1, "BNM INSTITUTE OF TECHNOLOGY");
	output(420, 1100, 0.2, 0, 1, "DEPARTMENT OF COMPUTER SCIENCE");
	output(540, 900, 0, 0.5, 0, "A MINI PROJECT ON");
	output(100, 700, 0, 0.5, 0, "TRAIN SIMULATION");
	output(100, 550, 0.1, 0.7, 0.5, "BY");
	output(100, 500, 0, 0.5, 0, "NAME:BHAVANA N M");
	output(100, 460, 0.1, 0.7, 0.5, "USN:1BG16CS026");
	output(1000, 600, 0, 0.5, 0, "GUIDE:");
	output(900, 530, 0.6, 0.5, 0.9, "DR.VIMUKTA SALIS MA'AM");
	output(520, 200, 1, 1, 1, "PRESS Enter TO START");
	glutSwapBuffers();

}
void key1(unsigned char key, int x, int y)
{
	if (key == 'd' || key == 'D')
	{
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glutHideWindow();
		glPushMatrix();
		glutSetWindow(win_2);
        glutTimerFunc(200, timer1, 0);
		glPopMatrix();
		glMatrixMode(GL_MODELVIEW);
		glutSwapBuffers();
		glutMainLoop();

	}
}
void mykey(unsigned char key, int x, int y)
{
	if (key == 'n' || key == 'N')
	{
		glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
		glutInitWindowPosition(0, 0);
		glutInitWindowSize(1300, 1300);
		win_3=glutCreateWindow("Night");
		glMatrixMode(GL_PROJECTION);
		glutTimerFunc(100, timer, 0);
		gluOrtho2D(0, 400, 0, 400);
		glutDisplayFunc(display2);
		glutKeyboardFunc(key1);
		glutTimerFunc(100, timer, 0);
		glutMainLoop();
	}
}
void kd(unsigned char key, int x, int y)
{
	if (key == 13)
	{
		glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
		glutInitWindowPosition(0, 0);
		glutInitWindowSize(1300, 1300);
		win_2 = glutCreateWindow("Train");
		glMatrixMode(GL_PROJECTION);
		glutTimerFunc(100, timer, 0);
		gluOrtho2D(0, 400, 0, 400);
		glutDisplayFunc(display);
		glutKeyboardFunc(mykey);
		glutTimerFunc(100, timer, 0);
	}
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(1300, 1300);
	win_1=glutCreateWindow("Front Sheet");
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 1300, 0, 1300);
	glutDisplayFunc(display1);
	glutKeyboardFunc(kd);
	glutMainLoop();
	return 0;
}