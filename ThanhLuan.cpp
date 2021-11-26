#include <stdio.h>
//-----------------------------------------------
struct nut{
	int gtri;
	nut *tiep;
};

typedef nut Node;
Node *dau,*daumoi;

void khoitao(Node *&dau)
{dau=NULL;
}
//-----------------------------------------------
void nhapds(Node *&dau)
{ int tam;
  Node *p; // chua d/c cua nut moi
  Node *q; // chua d/c nut cuoi trong ds
  do{
  	printf("\n Nhap 1 so nguyen, 0:dung ");
  	scanf("%d",&tam);
  	if (tam!=0)
  	{ // Tao nut moi
  	   p=new Node;
  	   p->gtri=tam;
  	   p->tiep=NULL;
  	   // Moc nut moi vao ds
  	   if (dau==NULL) // nut moi tao la nut dau tien
  	    dau =p;
  	    else
	   q->tiep=p;
	      q=p;		 	  
	  }
  }
  while (tam!=0);
}
//---------------------------------------------------
void Duyetlap(Node *dau)
{Node *p;
   p=dau;
   printf("\n");
   while (p!=NULL)
   { printf("%3d",p->gtri);
     p=p->tiep;
	} 
}
//-----------------------------------------------------
void Duyetdq(Node *dau)
{ if (dau!=NULL)
   { printf("%3d",dau->gtri);
     Duyetdq(dau->tiep);
   }
}
//-----------------------------------------------------
int tonglap(Node *dau)
{ int s=0;
  Node *p;
    p=dau;
	  while (p!=NULL)
	  { s=s+p->gtri;
	  p=p->tiep;
	   } 
	return s;   
}
//----------------------------------------------------- 
int tongdq(Node *dau)
{ if (dau==NULL) return  0;
 else
 return dau->gtri + tongdq(dau->tiep);
  }
//-----------------------------------------------------
int tongle(Node *dau)
{ if (dau==NULL) return 0;
   else
   if (dau->gtri %2 !=0)
   return dau->gtri + tongle(dau->tiep);
   else
   return tongle(dau->tiep);
}
//-----------------------------------------------------
void chendau(Node *&dau,int X)
{ Node *p;
  p=new Node;
  p->gtri=X;
  p->tiep=dau;
  dau=p;}
//-----------------------------------------------------
void chencuoi(Node *&dau, int X)
{ Node *p,*q;
  // Tim nut cuoi
  if (dau==NULL)
    chendau(dau,X);
  else
    { q=dau;
      while (q->tiep!=NULL) 
      q=q->tiep;
      // tao nut moi
      p=new Node;
      p->gtri=X;
      p->tiep=NULL;
      // Moc sau nut cuoi
      q->tiep=p;
	  }  
}
//------------------------------------------------------
void chensau(Node *&dau, int X, int Y)
{ Node *p,*q;
  if (dau!=NULL)
    { // Tim nut Y
       q=dau;
       while ((q!=NULL)&&(q->gtri!=Y))
         q=q->tiep;
         if (q!=NULL)
         { // Tao nut moi
           p=new Node;
           p->gtri=X;
           // Moc sau nut Y
           p->tiep=q->tiep;
           q->tiep=p;
		 }
	}
}
//------------------------------------------------------
void chentruoc(Node *&dau,int X, int Y)
{ Node *t, *q, *p;
   t=NULL;
   q=dau;
   // Tim nut mang gia tri Y
     while ((q!=NULL)&&(q->gtri!=Y))
     { t=q;
       q=q->tiep;
	 }
	 if (q!=NULL) // q la nut Y
	  { if (q==dau)
	     chendau(dau,X);
	    else
		{ // tao nut moi
		   p=new Node;
		   p->gtri=X;
		   // Moc p vao ds
		   t->tiep=p;
		   p->tiep=q;
		 } 
	    }
}
//------------------------------------------------------
void xoadau(Node *&dau)
{ Node *p;
   if (dau!=NULL)
   { p=dau;
     dau=dau->tiep;
     delete p;
   }
}
//------------------------------------------------------
void xoacuoi(Node *&dau)
{Node *p,*q;
 if (dau!=NULL)
 { q=NULL;
   p=dau;
     // Tim nut cuoi
      while (p->tiep!= NULL)
      { q=p;
        p=p->tiep;
	  }
	  
	  if (p==dau)       
	    xoadau(dau);
	  else
	    { q->tiep=NULL;
	     delete p;
		 }  
 }
}
//------------------------------------------------------
void xoa(Node *&dau, int X)
{ Node *p,*q;
  q=NULL;
    if (dau!=NULL)
    {// Tim nut mang gia tri X
      p=dau;
       while ((p!=NULL)&&(p->gtri!=X))
        { q=p;
          p=p->tiep; 
		}
		if (p!=NULL) // co nut mang gia tri X
		{ if (p==dau)
		   xoadau(dau);
		  else
		  { q->tiep=p->tiep;
		    delete p;
		   } 
		}
	}
}
//------------------------------------------------------
void xoasau(Node *&dau,int X)
{
	 Node *p,*q;
	 q=NULL;
	 if(dau!=NULL)
	 {
	 	p=dau;
	 	while(p!=NULL && p->gtri!=X)
	 		p=p->tiep;
	 	if(p!=NULL)	
	    if(p->tiep!=NULL)
		{
			q=p->tiep;
			p->tiep=q->tiep;
			delete q;
				}		
		 
	 }
	
}

//------------------------------------------------------
void xoatruoc(Node *&dau,int X)
{
	 Node *p,*t,*q;
	 p=NULL;t=NULL;q=NULL;
	 if(dau!=NULL)
	 {//Tim nút mang gti x;
	 	p=dau;
	 	while(p!=NULL&&p->gtri!=X)
	 		{
	 		 q=t;
	 		 t=p;
			 p=p->tiep;
	 		}
	 	if(p!=NULL)	//co nut mang gtri x;
	    if(p!=dau)
		{
		    if(dau->tiep==p)
		    {
		     xoadau(dau);
		     }
		else
			{
			q->tiep=p;
			delete t;
			
			}
		}		
		 
	 }
	
}
//------------------------------------------------------
void sapxep(Node *&dau)
{
  Node *p;
  Node *q;
  p=dau;
  int tam;
    while(p!=NULL && p->tiep!=NULL)
    {
	 q=p->tiep;
	 while(q!=NULL)
	 {
	 if(q->gtri<p->gtri)
	 {
	 tam=q->gtri;
	 q->gtri=p->gtri;
	 p->gtri=tam;
	 }
	 q=q->tiep;
	 }
	
	p=p->tiep;
	}
}	
//------------------------------------------------------
void daonguoc(Node *&dau,Node *&daumoi)
{
 Node *q,*p;
 daumoi=NULL;
  p=dau;
    while(p!=NULL)
   {
       q=new Node;
       q->gtri=p->gtri;
       q->tiep=daumoi;
       daumoi=q;
    	p=p->tiep;
   }   
    

}
//------------------------------------------------
void daonguockotaodsmoi(Node *&dau)
{
  Node *p,*q;
  q=NULL;
  while(dau!=NULL)
  {p=dau;
  dau=dau->tiep;
  p->tiep=q;
  q=p;
  }
  dau=p;
}
//------------------------------------------------
//xoa cac nut trung nhau
//
//-----------------------------------------------
int main()
{khoitao(dau);
 nhapds(dau);
 Duyetlap(dau);
 //chendau(dau,111);
 //chencuoi(dau,999);
 //chensau(dau,77,5);
 //chentruoc(dau,44,8);
  //xoadau(dau);
 // xoacuoi(dau);
  // xoa(dau,5);
 //xoatruoc(dau,5);
 //sapxep(dau);
 //daonguoc(dau,daumoi);
 daonguockotaodsmoi(dau);
  Duyetlap(dau);
 //printf("\n Tong nut le %3d",tongle(dau));
 /*printf("\n Duyet De qui \n");
 Duyetdq(dau);
 printf("\n Tong cac nut %3d \n",tonglap(dau));
 printf("\n Tong cac nut %3d \n",tongdq(dau));*/
 return 0;
}