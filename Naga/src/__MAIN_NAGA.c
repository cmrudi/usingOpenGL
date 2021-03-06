#include <GL/glut.h>
#include <stdlib.h>

int counter = 0;

void display(){
  glClear(GL_COLOR_BUFFER_BIT);

  //Sayap Kanan Naga
  glColor3f(0,0.8,0);
  glBegin(GL_POLYGON);
    glVertex2f(146,208);
    glVertex2f(125,181);
    glVertex2f(232,91);
    glVertex2f(234,167);
    glVertex2f(213,222);
    glVertex2f(193,274);
    glVertex2f(95,290);
  glEnd();
  
  //sayap kiri naga
  //Claw
  glColor3f(1,1,1);
  glBegin(GL_POLYGON);
    glVertex2f(241,300);
    glVertex2f(240,293);
    glVertex2f(229,286);
    glVertex2f(223,299);
    glVertex2f(224,310);
    glVertex2f(232,306);
  glEnd();
  
  //LW-B-01
  glColor3f(0,1,0);
  glBegin(GL_POLYGON);
    glVertex2f(240,285);
    glVertex2f(226,191);
    glVertex2f(213,206);
    glVertex2f(229,286);
  glEnd();
  
  //LW-B-02
  glColor3f(0,1,0);
  glBegin(GL_POLYGON);
    glVertex2f(213,206);
    glVertex2f(226,191);
    glVertex2f(166,153);
    glVertex2f(155,162);
    glVertex2f(138,168);
    glVertex2f(152,185);
  glEnd();
  
  //LW-F
  glColor3f(0.8,0.8,0.8);
  glBegin(GL_POLYGON);
    glVertex2f(226,191);
    glVertex2f(240,285);
    glVertex2f(255,280);
    glVertex2f(282,262);
    glVertex2f(292,253);
    glVertex2f(304,238);
    glVertex2f(323,209);
    glVertex2f(340,163);
    glVertex2f(343,109);
    glVertex2f(338,95);
    glVertex2f(312,122);
    glVertex2f(299,121);
    glVertex2f(294,108);
    glVertex2f(270,124);
    glVertex2f(247,130);
    glVertex2f(236,131);
    glVertex2f(224,142);
    glVertex2f(204,148);
    glVertex2f(192,139);
    glVertex2f(166,153);
  glEnd();
  
  //LW-F-01
  glColor3f(0,0,0);
  glBegin(GL_LINE_STRIP);
    glVertex2f(240,285);
    glVertex2f(251,202);
    glVertex2f(236,131);
  glEnd();
  
  //LW-F-02
  glColor3f(0,0,0);
  glBegin(GL_LINE_STRIP);
    glVertex2f(254,281);
    glVertex2f(272,257);
    glVertex2f(290,218);
    glVertex2f(296,120);
  glEnd();
  
  //LW-O-01
  glColor3f(0,1,0);
  glBegin(GL_POLYGON);
    glVertex2f(240,293);
    glVertex2f(241,300);
    glVertex2f(270,285);
    glVertex2f(255,280);
    glVertex2f(240,285);
    glVertex2f(229,286);
  glEnd();
  
  //LW-O-02
  glColor3f(0,1,0);
  glBegin(GL_POLYGON);
    glVertex2f(270,285);
    glVertex2f(304,263);
    glVertex2f(292,253);
    glVertex2f(282,262);
    glVertex2f(255,280);
  glEnd();
  
  //LW-O-03
  glColor3f(0,1,0);
  glBegin(GL_POLYGON);
    glVertex2f(304,263);
    glVertex2f(339,205);
    glVertex2f(323,209);
    glVertex2f(304,238);
    glVertex2f(292,253);
  glEnd();
  
  //LW-O-04
  glColor3f(0,1,0);
  glBegin(GL_POLYGON);
    glVertex2f(339,205);
    glVertex2f(364,160);
    glVertex2f(340,163);
    glVertex2f(323,209);
  glEnd();
  
  //LW-O-05
  glColor3f(0,1,0);
  glBegin(GL_POLYGON);
    glVertex2f(364,160);
    glVertex2f(366,128);
    glVertex2f(353,97);
    glVertex2f(345,78);
    glVertex2f(331,64);
    glVertex2f(338,95);
    glVertex2f(343,109);
    glVertex2f(340,163);
  glEnd();
  
  //Badan
  glColor3f(0.1,0.9,0.1);
  glBegin(GL_POLYGON);
    // badan
    glVertex2f(172,124);
    glVertex2f(165,98);
    glVertex2f(172,123);
    glVertex2f(164,100);
    glVertex2f(164,57);
    glVertex2f(181,38);
    glVertex2f(210,33);
    glVertex2f(236,19);
    glVertex2f(243,57);
    glVertex2f(240,85);
    glVertex2f(220,122);
    glVertex2f(156,162);
    glVertex2f(130,178);
	glVertex2f(130,139);
  glEnd();
  
  //Leher
  glColor3f(0.1,0.9,0.1);
  glBegin(GL_POLYGON);
    glVertex2f(145,235);
    glVertex2f(94,220);
    glVertex2f(69,141);
    glVertex2f(97,85);
    glVertex2f(116,77);
    glVertex2f(109,107);
    glVertex2f(130,139);
	glVertex2f(130,178);
  glEnd();

  glColor3f(0.5,0.5,0);
  glBegin(GL_POLYGON);
    //ekor 
    glVertex2f(217,123);
    glVertex2f(275,82);
    glVertex2f(264,34);
    glVertex2f(246,58);
  glEnd();
  
  glBegin(GL_POLYGON);
    glVertex2f(275,82);
    glVertex2f(312,81);
    glVertex2f(319,56);
    glVertex2f(293,33);
    glVertex2f(264,34);
  glEnd();
  
  glBegin(GL_POLYGON);
    glVertex2f(312,81);
    glVertex2f(334,90);
    glVertex2f(319,56);
  glEnd();

  glColor3f(0.1,0.8,0.1);
  glBegin(GL_POLYGON);
    // kaki pertama
    glVertex2f(74,131);
    glVertex2f(57,104);
    glVertex2f(69,85);
    glVertex2f(110,75);
    glVertex2f(91,90);
  glEnd();

  glBegin(GL_POLYGON);
    glVertex2f(70,88);
    glVertex2f(48,38);
    glVertex2f(61,33);
    glVertex2f(86,34);
    glVertex2f(111,78);
  glEnd();

  glColor3f(0.1,0.8,0.1);
  glBegin(GL_POLYGON);
    // kaki kedua
    glVertex2f(129,142);
    glVertex2f(108,106);
    glVertex2f(121,77);
    glVertex2f(164,57);
    glVertex2f(165,98);
    glVertex2f(172,124);
  glEnd();
	
  glBegin(GL_POLYGON);
    glVertex2f(121,77);
    glVertex2f(90,30);
    glVertex2f(129,18);
    glVertex2f(164,57);
  glEnd();

  glColor3f(0.1,0.8,0.1);
  glBegin(GL_POLYGON);
    // kaki ketiga
    glVertex2f(236,19);
    glVertex2f(195,13);
    glVertex2f(180,3);
    glVertex2f(176,13);
    glVertex2f(165,4);
    glVertex2f(160,10);
    glVertex2f(152,6);
    glVertex2f(146,10);
    glVertex2f(146,22);
    glVertex2f(165,35);
    glVertex2f(182,37);
    glVertex2f(201,35);
	glVertex2f(210,33);
  glEnd();

  glColor3f(0,0,0);
  glBegin(GL_LINE_STRIP);
    //strip naga vertikal
    glVertex2f(123,219);
    glVertex2f(115,204);
    glVertex2f(106,180);
    glVertex2f(103,154);
    glVertex2f(111,126);
    glVertex2f(117,118);
  glEnd();

  glBegin(GL_LINES);
    glVertex2f(96,213);
    glVertex2f(119,215);
    glVertex2f(90,201);
    glVertex2f(114,204);
    glVertex2f(86,182);
    glVertex2f(104,181);
    glVertex2f(76,155);
    glVertex2f(103,157);
    glVertex2f(77,123);
    glVertex2f(89,118);
    glVertex2f(89,118);
    glVertex2f(109,126);
    glVertex2f(95,91);
  glEnd();
  
  //telinga kiri
  glColor3f(0,0,1);
  glBegin(GL_POLYGON);
    glVertex2f(32,315);
    glVertex2f(28,322);
    glVertex2f(22,327);
    glVertex2f(16,333);
    glVertex2f(9,335);
    glVertex2f(5,337);
    glVertex2f(8,330);
    glVertex2f(11,327);
    glVertex2f(13,323);
    glVertex2f(16,314);
    glVertex2f(18,300);
    glVertex2f(18,293);
    glVertex2f(17,282);
    glVertex2f(16,276);
    glVertex2f(20,272);
    glVertex2f(23,267);
    glVertex2f(24,261);
    glVertex2f(24,254);
    glVertex2f(26,248);
    glVertex2f(27,242);
    glVertex2f(29,236);
    glVertex2f(31,228);
    glVertex2f(31,225);
    glVertex2f(35,227);
    glVertex2f(38,234);
    glVertex2f(44,240);
  glEnd();

  //telinga kanan  
  glColor3f(0,0,1);
  glBegin(GL_POLYGON);
    glVertex2f(184,318);
    glVertex2f(191,320);
    glVertex2f(198,321);
    glVertex2f(206,323);
    glVertex2f(212,323);
    glVertex2f(220,322);
    glVertex2f(231,321);
    glVertex2f(238,320);
    glVertex2f(245,317);
    glVertex2f(249,314);
    glVertex2f(239,314);
    glVertex2f(234,309);
    glVertex2f(228,304);
    glVertex2f(221,297);
    glVertex2f(216,286);
    glVertex2f(214,278);
    glVertex2f(214,274);
    glVertex2f(214,264);
    glVertex2f(215,260);
    glVertex2f(208,259);
    glVertex2f(203,254);
    glVertex2f(197,249);
    glVertex2f(192,241);
    glVertex2f(188,235);
    glVertex2f(186,227);
    glVertex2f(185,221);
    glVertex2f(185,216);
    glVertex2f(184,212);
    glVertex2f(181,216);
    glVertex2f(178,221);
    glVertex2f(172,225);
    glVertex2f(167,229);
    glVertex2f(162,232);
    glVertex2f(157,235);
    glVertex2f(159,239);
    glVertex2f(157,242);
    glVertex2f(156,245);
    glVertex2f(160,252);
    glVertex2f(165,253);
    glVertex2f(169,257);
    glVertex2f(172,262);
    glVertex2f(174,267);
    glVertex2f(177,273);
  glEnd();  
	
  //kepala
  glColor3f(0,1,0);
  glBegin(GL_POLYGON);
  glVertex2f(177,324);
  glVertex2f(182,315);
  glVertex2f(184,303);
  glVertex2f(183,288);
  glVertex2f(178,276);
  glVertex2f(178,272);
  glVertex2f(172,263);
  glVertex2f(169,257);
  glVertex2f(165,255);
  glVertex2f(159,250);
  glVertex2f(154,245);
  glVertex2f(159,237);
  glVertex2f(153,234);
  glVertex2f(146,230);
  glVertex2f(140,230);
  glVertex2f(135,230);
  glVertex2f(129,227);
  glVertex2f(123,226);
  glVertex2f(113,224);
  glVertex2f(106,219);
  glVertex2f(99,217);
  glVertex2f(92,213);
  glVertex2f(88,209);
  glVertex2f(86,205);
  glVertex2f(78,204);
  glVertex2f(71,206);
  glVertex2f(65,208);
  glVertex2f(63,212);
  glVertex2f(63,215);
  glVertex2f(59,218);
  glVertex2f(55,219);
  glVertex2f(53,221);
  glVertex2f(48,222);
  glVertex2f(42,226);
  glVertex2f(39,229);
  glVertex2f(38,235);
  glVertex2f(33,241);
  glVertex2f(28,243);
  glVertex2f(25,246);
  glVertex2f(27,251);
  glVertex2f(28,257);
  glVertex2f(33,263);
  glVertex2f(32,267);
  glVertex2f(30,273);
  glVertex2f(30,278);
  glVertex2f(29,283);
  glVertex2f(28,288);
  glVertex2f(28,297);
  glVertex2f(29,302);
  glVertex2f(33,310);
  glVertex2f(36,314);
  glVertex2f(39,319);
  glVertex2f(41,324);
  glVertex2f(49,329);
  glVertex2f(53,335);
  glVertex2f(64,342);
  glVertex2f(73,347);
  glVertex2f(80,352);
  glVertex2f(87,357);
  glVertex2f(96,360);
  glVertex2f(104,361);
  glVertex2f(111,362);
  glVertex2f(117,362);
  glVertex2f(126,362);
  glVertex2f(138,359);
  glVertex2f(145,358);
  glVertex2f(151,354);
  glEnd();

  glColor3f(1,0,0);
  glBegin(GL_POLYGON);
  glVertex2f(137, 342);
  glVertex2f(161, 323);
  glVertex2f(177, 318);
  glVertex2f(181, 349);
  glVertex2f(219, 386);
  glVertex2f(168, 375);
  glEnd();


  glColor3f(1,0,0);
  glBegin(GL_POLYGON);
  glVertex2f(137,342);
  glVertex2f(161,323);
  glVertex2f(177,328);
  glVertex2f(181,349);
  glVertex2f(219,386);
  glVertex2f(168,375);
  glEnd();

  glColor3f(1,0,0);
  glBegin(GL_POLYGON);
  glVertex2f(73,375);
  glVertex2f(135,395);
  glVertex2f(104,361);
  glVertex2f(96,360);
  glVertex2f(87,357);
  glVertex2f(80,352);
  glVertex2f(73,347);
  glVertex2f(64,342);
  glVertex2f(59,338);
  glEnd();

  glColor3f(1,0,0);
  glBegin(GL_POLYGON);
  glVertex2f(83,307);
  glVertex2f(80,327);
  glVertex2f(92,346);
  glVertex2f(95,323);
  glEnd();

  glColor3f(1,0,0);
  glBegin(GL_POLYGON);
  glVertex2f(107,342);
  glVertex2f(111,366);
  glVertex2f(127,320);
  glVertex2f(127,360);
  glVertex2f(123,353);
  glEnd();

  glColor3f(1,0,0);
  glBegin(GL_POLYGON);
  glVertex2f(133,362);
  glVertex2f(150,375);
  glVertex2f(152,342);
  glEnd();

  glColor3f(1,1,1);
  glBegin(GL_POLYGON);
  glVertex2f(98,280);
  glVertex2f(109,263);
  glVertex2f(121,262);
  glVertex2f(130,267);
  glVertex2f(135,275);
  glVertex2f(136,284);
  glVertex2f(132,293);
  glEnd();

  glColor3f(1,0,0);
  glBegin(GL_POLYGON);
  glVertex2f(98,280);
  glVertex2f(92,264);
  glVertex2f(113,255);
  glVertex2f(136,267);
  glVertex2f(146,288);
  glVertex2f(135,293);
  glEnd();

  glColor3f(1,1,1);
  glBegin(GL_POLYGON);
  glVertex2f(62,268);
  glVertex2f(54,281);
  glVertex2f(35,288);
  glVertex2f(43,264);
  glVertex2f(52,259);
  glVertex2f(59,260);
  glEnd();
  
  glColor3f(1,1,1);
  glBegin(GL_POLYGON);
  glVertex2f(60,269);
  glVertex2f(56,264);
  glVertex2f(48,264);
  glVertex2f(39,279);
  glVertex2f(40,285);
  glVertex2f(54,281);
  glEnd();

  //mulut
  glColor3f(0,0,0);
  glBegin(GL_LINE_STRIP);
  glVertex2f(56,249);
  glVertex2f(49,247);
  glVertex2f(41,241);
  glVertex2f(37,233);
  glVertex2f(40,227);
  glVertex2f(46,222);
  glVertex2f(54,218);
  glVertex2f(65,216);
  glVertex2f(71,216);
  glVertex2f(78,219);
  glVertex2f(85,222);
  glVertex2f(91,228);
  glVertex2f(97,236);
  glVertex2f(108,234);
  glEnd ();

  //gigi
  glColor3f(0,0,0);
  glBegin(GL_LINE_STRIP);
  glVertex2f(84,224);
  glVertex2f(84,229);
  glVertex2f(85,234);
  glVertex2f(86,236);
  glVertex2f(88,234);
  glVertex2f(93,231);
  glVertex2f(99,226);
  glVertex2f(100,228);
  glVertex2f(102,234);
  glVertex2f(103,235);
  glEnd();

  //mata kiri
  glColor3f(0,0,0);
  glBegin(GL_POLYGON);
  glVertex2f(43,284);
  glVertex2f(40,281);
  glVertex2f(41,275);
  glVertex2f(43,270);
  glVertex2f(45,268);
  glVertex2f(47,265);
  glVertex2f(49,264);
  glVertex2f(53,262);
  glVertex2f(55,262);
  glVertex2f(58,264);
  glVertex2f(60,267);
  glVertex2f(59,270);
  glVertex2f(58,275);
  glVertex2f(56,279);
  glVertex2f(54,281);
  glEnd();

  glColor3f(1,1,1);
  glBegin(GL_POLYGON);
  glVertex2f(42,280);
  glVertex2f(44,282);
  glVertex2f(47,282);
  glVertex2f(50,280);
  glVertex2f(51,278);
  glVertex2f(52,276);
  glVertex2f(50,274);
  glVertex2f(48,273);
  glVertex2f(46,273);
  glVertex2f(44,275);
  glVertex2f(42,277);
  glEnd();

  glColor3f(1,1,1);
  glBegin(GL_POLYGON);
  glVertex2f(54,269);
  glVertex2f(56,268);
  glVertex2f(53,267);
  glVertex2f(52,269);
  glEnd();

  //mata kanan
  glColor3f(1,1,1);
  glBegin(GL_POLYGON);
  glVertex2f(94,264);
  glVertex2f(95,260);
  glVertex2f(98,258);
  glVertex2f(101,258);
  glVertex2f(105,256);
  glVertex2f(110,256);
  glVertex2f(116,256);
  glVertex2f(120,257);
  glVertex2f(126,259);
  glVertex2f(131,262);
  glVertex2f(134,266);
  glVertex2f(138,268);
  glVertex2f(141,272);
  glVertex2f(142,276);
  glVertex2f(145,282);
  glVertex2f(146,286);
  glVertex2f(147,289);
  glVertex2f(148,291);
  glVertex2f(150,289);
  glVertex2f(145,291);
  glVertex2f(142,291);
  glVertex2f(138,293);
  glVertex2f(131,293);
  glVertex2f(126,293);
  glVertex2f(122,292);
  glVertex2f(113,290);
  glVertex2f(99,284);
  glVertex2f(96,281);
  glVertex2f(95,274);
  glVertex2f(93,272);
  glVertex2f(93,269);
  glEnd();

  glColor3f(0,0,0);
  glBegin(GL_POLYGON);
  glVertex2f(101,277);
  glVertex2f(103,272);
  glVertex2f(105,269);
  glVertex2f(108,265);
  glVertex2f(111,263);
  glVertex2f(115,262);
  glVertex2f(120,262);
  glVertex2f(125,264);
  glVertex2f(129,265);
  glVertex2f(131,270);
  glVertex2f(134,274);
  glVertex2f(136,278);
  glVertex2f(135,283);
  glVertex2f(134,287);
  glVertex2f(131,291);
  glVertex2f(124,291);
  glVertex2f(116,289);
  glVertex2f(111,287);
  glVertex2f(106,286);
  glVertex2f(102,283);
  glVertex2f(100,281);
  glEnd();

  glColor3f(1,1,1);
  glBegin(GL_POLYGON);
  glVertex2f(103,279);
  glVertex2f(105,282);
  glVertex2f(110,285);
  glVertex2f(115,286);
  glVertex2f(119,286);
  glVertex2f(123,283);
  glVertex2f(123,281);
  glVertex2f(123,277);
  glVertex2f(120,275);
  glVertex2f(118,273);
  glVertex2f(115,273);
  glVertex2f(111,272);
  glVertex2f(108,273);
  glVertex2f(105,274);
  glEnd();

  glColor3f(1,1,1);
  glBegin(GL_POLYGON);
  glVertex2f(126,271);
  glVertex2f(128,271);
  glVertex2f(128,269);
  glVertex2f(126,267);
  glVertex2f(124,268);
  glVertex2f(124,270);
  glEnd();

  glFlush();
  glutSwapBuffers();
}

int main(int argc, char** argv){
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
  glutInitWindowSize(370, 397);
  glutCreateWindow("Naga euy");
  glutDisplayFunc(display);
  gluOrtho2D(0,370,0,397);
  glClearColor(1,0.7,0.5,0);
  glutMainLoop();
  return 0;
}