#include "main.h"


using namespace std;

void drawShip()
{
  


  GLfloat at[3] = {2.0, 0.25, 0.1}; //At
  GLfloat ab[3] = {2.0, 0.25, -0.1}; //Ab
  GLfloat bt[3] = {0.25, 0.75, 0.25}; //Bt
  GLfloat bb[3] = {0.25, 0.75, -0.25}; //Bb
  GLfloat ct[3] = {-0.25, 1.5, 0.4}; //Ct
  GLfloat cb[3] = {-0.25, 1.5, -0.4}; //Cb
  GLfloat dt[3] = {0.0, 3.0, 0.05}; //Dt
  GLfloat db[3] = {0.0, 3.0, -0.05}; //Db
  GLfloat et[3] = {-1.0, 3.0, 0.05}; //Et
  GLfloat eb[3] = {-1.0, 3.0, -0.05}; //Eb
  GLfloat ft[3] = {-2.0, 1.0, 0.5}; //Ft
  GLfloat fb[3] = {-2.0, 1.0, -0.5}; //Fb
  GLfloat gt[3] = {-2.0, -1.0, 0.5}; //Gt
  GLfloat gb[3] = {-2.0, -1.0, -0.5}; //Gb
  GLfloat ht[3] = {-1.0, -3.0, 0.05}; //Ht
  GLfloat hb[3] = {-1.0, -3.0, -0.05}; //Hb
  GLfloat it[3] = {0.0, -3.0, 0.05}; //It
  GLfloat ib[3] = {0.0, -3.0, -0.05}; //Ib
  GLfloat jt[3] = {-0.25, -1.5, 0.4}; //Jt
  GLfloat jb[3] = {-0.25, -1.5, -0.4}; //Jb
  GLfloat kt[3] = {0.25, -0.75, 0.25}; //Kt
  GLfloat kb[3] = {0.25, -0.75, -0.25}; //Kb
  GLfloat lt[3] = {2.0, -0.25, 0.1}; //Lt   
  GLfloat lb[3] = {2.0, -0.25, -0.1}; //Lb   

  GLfloat guna[3] = {0, 3, 0.05};
  GLfloat gunb[3] = {0, 3, -0.05};
  GLfloat gunc[3] = {1, 2.97, 0.01};
  GLfloat gund[3] = {1, 2.97, -0.01};
  GLfloat gune[3] = {-0.25, 2.8, 0.05};
  GLfloat gunf[3] = {-0.25, 2.8, -0.05};
  GLfloat gung[3] = {1, 2.95, 0.01};
  GLfloat gunh[3] = {1, 2.95, -0.01};

  GLfloat gun2a[3] = {0, -3, 0.05};
  GLfloat gun2b[3] = {0, -3, -0.05};
  GLfloat gun2c[3] = {1, -2.97, 0.01};
  GLfloat gun2d[3] = {1, -2.97, -0.01};
  GLfloat gun2e[3] = {-0.25, -2.8, 0.05};
  GLfloat gun2f[3] = {-0.25, -2.8, -0.05};
  GLfloat gun2g[3] = {1, -2.95, 0.01};
  GLfloat gun2h[3] = {1, -2.95, -0.01};

  glBegin(GL_QUADS);
  //1
  glTexCoord2f(0.0, 0.0);
  glNormal3fv(at);
  glVertex3fv(at);
  glTexCoord2f(1.0, 0.0);
  glNormal3fv(bt);
  glVertex3fv(bt);
  glTexCoord2f(1.0, 1.0);
  glNormal3fv(kt);
  glVertex3fv(kt);
  glTexCoord2f(0.0, 1.0);
  glNormal3fv(lt);
  glVertex3fv(lt);
  //2
  glTexCoord2f(0.0, 0.0);
  glNormal3fv(bt);
  glVertex3fv(bt);
  glTexCoord2f(1.0, 0.0);
  glNormal3fv(ct);
  glVertex3fv(ct);
  glTexCoord2f(1.0, 1.0);
  glNormal3fv(jt);
  glVertex3fv(jt);
  glTexCoord2f(0.0, 1.0);
  glNormal3fv(kt);
  glVertex3fv(kt);
  //3
  glTexCoord2f(0.0, 0.0);
  glNormal3fv(ct);
  glVertex3fv(ct);
  glTexCoord2f(1.0, 0.0);
  glNormal3fv(ft);
  glVertex3fv(ft);
  glTexCoord2f(1.0, 1.0);
  glNormal3fv(gt);
  glVertex3fv(gt);
  glTexCoord2f(0.0, 1.0);
  glNormal3fv(jt);
  glVertex3fv(jt);
  //4
  glTexCoord2f(0.0, 0.0);
  glNormal3fv(dt);
  glVertex3fv(dt);
  glTexCoord2f(1.0, 0.0);
  glNormal3fv(et);
  glVertex3fv(et);
  glTexCoord2f(1.0, 1.0);
  glNormal3fv(ft);
  glVertex3fv(ft);
  glTexCoord2f(0.0, 1.0);
  glNormal3fv(ct);
  glVertex3fv(ct);
  //5
  glTexCoord2f(0.0, 0.0);
  glNormal3fv(jt);
  glVertex3fv(jt);
  glTexCoord2f(1.0, 0.0);
  glNormal3fv(gt);
  glVertex3fv(gt);
  glTexCoord2f(1.0, 1.0);
  glNormal3fv(ht);
  glVertex3fv(ht);
  glTexCoord2f(0.0, 1.0);
  glNormal3fv(it);
  glVertex3fv(it);
  //6
  glTexCoord2f(0.0, 0.0);
  glNormal3fv(ab);
  glVertex3fv(ab);
  glTexCoord2f(1.0, 0.0);
  glNormal3fv(bb);
  glVertex3fv(bb);
  glTexCoord2f(1.0, 1.0);
  glNormal3fv(kb);
  glVertex3fv(kb);
  glTexCoord2f(0.0, 1.0);
  glNormal3fv(lb);
  glVertex3fv(lb);
  //7
  glTexCoord2f(0.0, 0.0);
  glNormal3fv(bb);
  glVertex3fv(bb);
  glTexCoord2f(1.0, 0.0);
  glNormal3fv(cb);
  glVertex3fv(cb);
  glTexCoord2f(1.0, 1.0);
  glNormal3fv(jb);
  glVertex3fv(jb);
  glTexCoord2f(0.0, 1.0);
  glNormal3fv(kb);
  glVertex3fv(kb);
  //8
  glTexCoord2f(0.0, 0.0);
  glNormal3fv(cb);
  glVertex3fv(cb);
  glTexCoord2f(1.0, 0.0);
  glNormal3fv(fb);
  glVertex3fv(fb);
  glTexCoord2f(1.0, 1.0);
  glNormal3fv(gb);
  glVertex3fv(gb);
  glTexCoord2f(0.0, 1.0);
  glNormal3fv(jb);
  glVertex3fv(jb);
  //9
  glTexCoord2f(0.0, 0.0);
  glNormal3fv(db);
  glVertex3fv(db);
  glTexCoord2f(1.0, 0.0);
  glNormal3fv(eb);
  glVertex3fv(eb);
  glTexCoord2f(1.0, 1.0);
  glNormal3fv(fb);
  glVertex3fv(fb);
  glTexCoord2f(0.0, 1.0);
  glNormal3fv(cb);
  glVertex3fv(cb);
  //10
  glTexCoord2f(0.0, 0.0);
  glNormal3fv(jb);
  glVertex3fv(jb);
  glTexCoord2f(1.0, 0.0);
  glNormal3fv(gb);
  glVertex3fv(gb);
  glTexCoord2f(1.0, 1.0);
  glNormal3fv(hb);
  glVertex3fv(hb);
  glTexCoord2f(0.0, 1.0);
  glNormal3fv(ib);
  glVertex3fv(ib);
  //11
  glTexCoord2f(0.0, 0.0);
  glNormal3fv(at);
  glVertex3fv(at);
  glTexCoord2f(1.0, 0.0);
  glNormal3fv(ab);
  glVertex3fv(ab);
  glTexCoord2f(1.0, 1.0);
  glNormal3fv(lb);
  glVertex3fv(lb);
  glTexCoord2f(0.0, 1.0);
  glNormal3fv(lt);
  glVertex3fv(lt);
  //12
  glTexCoord2f(0.0, 0.0);
  glNormal3fv(lt);
  glVertex3fv(lt);
  glTexCoord2f(1.0, 0.0);
  glNormal3fv(lb);
  glVertex3fv(lb);
  glTexCoord2f(1.0, 1.0);
  glNormal3fv(kb);
  glVertex3fv(kb);
  glTexCoord2f(0.0, 1.0);
  glNormal3fv(kt);
  glVertex3fv(kt);
  //13
  glTexCoord2f(0.0, 0.0);
  glNormal3fv(kt);
  glVertex3fv(kt);
  glTexCoord2f(1.0, 0.0);
  glNormal3fv(kb);
  glVertex3fv(kb);
  glTexCoord2f(1.0, 1.0);
  glNormal3fv(jb);
  glVertex3fv(jb);
  glTexCoord2f(0.0, 1.0);
  glNormal3fv(jt);
  glVertex3fv(jt);
  //14
  glTexCoord2f(0.0, 0.0);
  glNormal3fv(jt);
  glVertex3fv(jt);
  glTexCoord2f(1.0, 0.0);
  glNormal3fv(jb);
  glVertex3fv(jb);
  glTexCoord2f(1.0, 1.0);
  glNormal3fv(ib);
  glVertex3fv(ib);
  glTexCoord2f(0.0, 1.0);
  glNormal3fv(it);
  glVertex3fv(it);
  //15
  glTexCoord2f(0.0, 0.0);
  glNormal3fv(it);
  glVertex3fv(it);
  glTexCoord2f(1.0, 0.0);
  glNormal3fv(ib);
  glVertex3fv(ib);
  glTexCoord2f(1.0, 1.0);
  glNormal3fv(hb);
  glVertex3fv(hb);
  glTexCoord2f(0.0, 1.0);
  glNormal3fv(ht);
  glVertex3fv(ht);
  //16
  glTexCoord2f(0.0, 0.0);
  glNormal3fv(ht);
  glVertex3fv(ht);
  glTexCoord2f(1.0, 0.0);
  glNormal3fv(hb);
  glVertex3fv(hb);
  glTexCoord2f(1.0, 1.0);
  glNormal3fv(gb);
  glVertex3fv(gb);
  glTexCoord2f(0.0, 1.0);
  glNormal3fv(gt);
  glVertex3fv(gt);
  //17
  glTexCoord2f(0.0, 0.0);
  glNormal3fv(gt);
  glVertex3fv(gt);
  glTexCoord2f(1.0, 0.0);
  glNormal3fv(gb);
  glVertex3fv(gb);
  glTexCoord2f(1.0, 1.0);
  glNormal3fv(fb);
  glVertex3fv(fb);
  glTexCoord2f(0.0, 1.0);
  glNormal3fv(ft);
  glVertex3fv(ft);
  //18
  glTexCoord2f(0.0, 0.0);
  glNormal3fv(ft);
  glVertex3fv(ft);
  glTexCoord2f(1.0, 0.0);
  glNormal3fv(fb);
  glVertex3fv(fb);
  glTexCoord2f(1.0, 1.0);
  glNormal3fv(eb);
  glVertex3fv(eb);
  glTexCoord2f(0.0, 1.0);
  glNormal3fv(et);
  glVertex3fv(et);
  //19
  glTexCoord2f(0.0, 0.0);
  glNormal3fv(et);
  glVertex3fv(et);
  glTexCoord2f(1.0, 0.0);
  glNormal3fv(eb);
  glVertex3fv(eb);
  glTexCoord2f(1.0, 1.0);
  glNormal3fv(db);
  glVertex3fv(db);
  glTexCoord2f(0.0, 1.0);
  glNormal3fv(dt);
  glVertex3fv(dt);
  //20
  glTexCoord2f(0.0, 0.0);
  glNormal3fv(dt);
  glVertex3fv(dt);
  glTexCoord2f(1.0, 0.0);
  glNormal3fv(db);
  glVertex3fv(db);
  glTexCoord2f(1.0, 1.0);
  glNormal3fv(cb);
  glVertex3fv(cb);
  glTexCoord2f(0.0, 1.0);
  glNormal3fv(ct);
  glVertex3fv(ct);
  //21
  glTexCoord2f(0.0, 0.0);
  glNormal3fv(ct);
  glVertex3fv(ct);
  glTexCoord2f(1.0, 0.0);
  glNormal3fv(cb);
  glVertex3fv(cb);
  glTexCoord2f(1.0, 1.0);
  glNormal3fv(bb);
  glVertex3fv(bb);
  glTexCoord2f(0.0, 1.0);
  glNormal3fv(bt);
  glVertex3fv(bt);
  //22
  glTexCoord2f(0.0, 0.0);
  glNormal3fv(bt);
  glVertex3fv(bt);
  glTexCoord2f(1.0, 0.0);
  glNormal3fv(bb);
  glVertex3fv(bb);
  glTexCoord2f(1.0, 0.0);
  glNormal3fv(ab);
  glVertex3fv(ab);
  glTexCoord2f(0.0, 0.0);
  glNormal3fv(at);
  glVertex3fv(at);
  //guns
  glTexCoord2f(0.0, 0.0);
  glNormal3fv(guna);
  glVertex3fv(guna);
  glTexCoord2f(1.0, 0.0);
  glNormal3fv(gunb);
  glVertex3fv(gunb);
  glTexCoord2f(1.0, 1.0);
  glNormal3fv(gund);
  glVertex3fv(gund);
  glTexCoord2f(0.0, 1.0);
  glNormal3fv(gunc);
  glVertex3fv(gunc);

  glTexCoord2f(0.0, 0.0);
  glNormal3fv(guna);
  glVertex3fv(guna);
  glTexCoord2f(1.0, 0.0);
  glNormal3fv(gunc);
  glVertex3fv(gunc);
  glTexCoord2f(1.0, 1.0);
  glNormal3fv(gung);
  glVertex3fv(gung);
  glTexCoord2f(0.0, 1.0);
  glNormal3fv(gune);
  glVertex3fv(gune);

  glTexCoord2f(0.0, 0.0);
  glNormal3fv(gune);
  glVertex3fv(gune);
  glTexCoord2f(1.0, 0.0);
  glNormal3fv(gung);
  glVertex3fv(gung);
  glTexCoord2f(1.0, 1.0);
  glNormal3fv(gunh);
  glVertex3fv(gunh);
  glTexCoord2f(0.0, 1.0);
  glNormal3fv(gunf);
  glVertex3fv(gunf);

  glTexCoord2f(0.0, 0.0);
  glNormal3fv(gunb);
  glVertex3fv(gunb);
  glTexCoord2f(1.0, 0.0);
  glNormal3fv(gund);
  glVertex3fv(gund);
  glTexCoord2f(1.0, 1.0);
  glNormal3fv(gunh);
  glVertex3fv(gunh);
  glTexCoord2f(0.0, 1.0);
  glNormal3fv(gunf);
  glVertex3fv(gunf);

  glTexCoord2f(0.0, 0.0);
  glNormal3fv(gunc);
  glVertex3fv(gunc);
  glTexCoord2f(1.0, 0.0);
  glNormal3fv(gund);
  glVertex3fv(gund);
  glTexCoord2f(1.0, 1.0);
  glNormal3fv(gunh);
  glVertex3fv(gunh);
  glTexCoord2f(0.0, 1.0);
  glNormal3fv(gung);
  glVertex3fv(gung);

  glTexCoord2f(0.0, 0.0);
  glNormal3fv(gun2a);
  glVertex3fv(gun2a);
  glTexCoord2f(1.0, 0.0);
  glNormal3fv(gun2b);
  glVertex3fv(gun2b);
  glTexCoord2f(1.0, 1.0);
  glNormal3fv(gun2d);
  glVertex3fv(gun2d);
  glTexCoord2f(0.0, 1.0);
  glNormal3fv(gun2c);
  glVertex3fv(gun2c);

  glTexCoord2f(0.0, 0.0);
  glNormal3fv(gun2a);
  glVertex3fv(gun2a);
  glTexCoord2f(1.0, 0.0);
  glNormal3fv(gun2c);
  glVertex3fv(gun2c);
  glTexCoord2f(1.0, 1.0);
  glNormal3fv(gun2g);
  glVertex3fv(gun2g);
  glTexCoord2f(0.0, 1.0);
  glNormal3fv(gun2e);
  glVertex3fv(gun2e);

  glTexCoord2f(0.0, 0.0);
  glNormal3fv(gun2e);
  glVertex3fv(gun2e);
  glTexCoord2f(1.0, 0.0);
  glNormal3fv(gun2g);
  glVertex3fv(gun2g);
  glTexCoord2f(1.0, 1.0);
  glNormal3fv(gun2h);
  glVertex3fv(gun2h);
  glTexCoord2f(0.0, 1.0);
  glNormal3fv(gun2f);
  glVertex3fv(gun2f);

  glTexCoord2f(0.0, 0.0);
  glNormal3fv(gun2b);
  glVertex3fv(gun2b);
  glTexCoord2f(1.0, 0.0);
  glNormal3fv(gun2d);
  glVertex3fv(gun2d);
  glTexCoord2f(1.0, 1.0);
  glNormal3fv(gun2h);
  glVertex3fv(gun2h);
  glTexCoord2f(0.0, 1.0);
  glNormal3fv(gun2f);
  glVertex3fv(gun2f);

  glTexCoord2f(0.0, 0.0);
  glNormal3fv(gun2c);
  glVertex3fv(gun2c);
  glTexCoord2f(1.0, 0.0);
  glNormal3fv(gun2d);
  glVertex3fv(gun2d);
  glTexCoord2f(1.0, 1.0);
  glNormal3fv(gun2h);
  glVertex3fv(gun2h);
  glTexCoord2f(0.0, 1.0);
  glNormal3fv(gun2g);
  glVertex3fv(gun2g);

  glEnd();
}

void drawCockpit()
{
  GLfloat cpa[3] = {1.75, 0.1, 0.0};
  GLfloat cpb[3] = {1.25, 0.1, 0.3};
  GLfloat cpc[3] = {0.75, 0.1, 0.3};
  GLfloat cpd[3] = {0.5, 0.1, 0.0};
  GLfloat cpe[3] = {1.75, -0.1, 0.0};
  GLfloat cpf[3] = {1.25, -0.1, 0.3};
  GLfloat cpg[3] = {0.75, -0.1, 0.3};
  GLfloat cph[3] = {0.5, -0.1, 0.0};

  glBegin(GL_QUADS);
  //cockpit
  glTexCoord2f(0.0, 0.0);
  glNormal3fv(cpa);
  glVertex3fv(cpa);
  glTexCoord2f(1.0, 0.0);
  glNormal3fv(cpb);
  glVertex3fv(cpb);
  glTexCoord2f(1.0, 1.0);
  glNormal3fv(cpf);
  glVertex3fv(cpf);
  glTexCoord2f(0.0, 1.0);
  glNormal3fv(cpe);
  glVertex3fv(cpe);

  glTexCoord2f(0.0, 0.0);
  glNormal3fv(cpb);
  glVertex3fv(cpb);
  glTexCoord2f(1.0, 0.0);
  glNormal3fv(cpc);
  glVertex3fv(cpc);
  glTexCoord2f(1.0, 1.0);
  glNormal3fv(cpg);
  glVertex3fv(cpg);
  glTexCoord2f(0.0, 1.0);
  glNormal3fv(cpf);
  glVertex3fv(cpf);

  glTexCoord2f(0.0, 0.0);
  glNormal3fv(cpc);
  glVertex3fv(cpc);
  glTexCoord2f(1.0, 0.0);
  glNormal3fv(cpd);
  glVertex3fv(cpd);
  glTexCoord2f(1.0, 1.0);
  glNormal3fv(cph);
  glVertex3fv(cph);
  glTexCoord2f(0.0, 1.0);
  glNormal3fv(cpg);
  glVertex3fv(cpg);

  glTexCoord2f(0.0, 0.0);
  glNormal3fv(cpa);
  glVertex3fv(cpa);
  glTexCoord2f(1.0, 0.0);
  glNormal3fv(cpb);
  glVertex3fv(cpb);
  glTexCoord2f(1.0, 1.0);
  glNormal3fv(cpc);
  glVertex3fv(cpc);
  glTexCoord2f(0.0, 1.0);
  glNormal3fv(cpd);
  glVertex3fv(cpd);

  glTexCoord2f(0.0, 0.0);
  glNormal3fv(cpe);
  glVertex3fv(cpe);
  glTexCoord2f(1.0, 0.0);
  glNormal3fv(cpf);
  glVertex3fv(cpf);
  glTexCoord2f(1.0, 1.0);
  glNormal3fv(cpg);
  glVertex3fv(cpg);
  glTexCoord2f(0.0, 1.0);
  glNormal3fv(cph);
  glVertex3fv(cph);
  
  glEnd();
}

